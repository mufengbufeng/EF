using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using UnityEditor;
using UnityEngine;

namespace EF.Editor
{
    /// <summary>
    /// 为 consumer 程序集添加完整 EF 运行时引用的菜单入口。
    /// </summary>
    internal static class EFAssemblyReferenceMenu
    {
        private const string MenuPath = "EF/Assembly/添加全部运行时模块引用";
        private const string AssetsMenuPath = "Assets/EF/Assembly/添加全部运行时模块引用";

        /// <summary>
        /// 将完整 EF 引用写入当前选中的 consumer asmdef。
        /// </summary>
        [MenuItem(MenuPath, false, 100)]
        [MenuItem(AssetsMenuPath, false, 2000)]
        private static void AddAllRuntimeModuleReferences()
        {
            if (!TryGetSelectedAssemblyDefinition(out string assetPath, out string fullPath))
            {
                Debug.LogError("请选择一个 consumer asmdef 后再添加 EF 运行时模块引用。");
                return;
            }

            try
            {
                bool changed = EFAssemblyReferenceUtility.AddAllReferencesToFile(fullPath);
                if (!changed)
                {
                    Debug.Log($"程序集定义 {assetPath} 已包含完整 EF 运行时引用。");
                    return;
                }

                AssetDatabase.ImportAsset(assetPath, ImportAssetOptions.ForceUpdate);
                Debug.Log($"已向程序集定义 {assetPath} 添加完整 EF 运行时引用。");
            }
            catch (Exception exception)
            {
                Debug.LogError($"更新程序集定义 {assetPath} 失败：{exception.Message}");
            }
        }

        /// <summary>
        /// 仅在选中可安全修改的 consumer asmdef 时启用菜单。
        /// </summary>
        [MenuItem(MenuPath, true)]
        [MenuItem(AssetsMenuPath, true)]
        private static bool CanAddAllRuntimeModuleReferences()
        {
            if (!TryGetSelectedAssemblyDefinition(out _, out string fullPath))
            {
                return false;
            }

            try
            {
                return EFAssemblyReferenceUtility.CanAddAllReferences(File.ReadAllText(fullPath));
            }
            catch (Exception)
            {
                return false;
            }
        }

        /// <summary>
        /// 获取当前选中的 asmdef 资源路径和磁盘绝对路径。
        /// </summary>
        private static bool TryGetSelectedAssemblyDefinition(out string assetPath, out string fullPath)
        {
            assetPath = AssetDatabase.GetAssetPath(Selection.activeObject);
            fullPath = string.Empty;
            if (string.IsNullOrEmpty(assetPath)
                || !assetPath.EndsWith(".asmdef", StringComparison.OrdinalIgnoreCase))
            {
                return false;
            }

            string projectRoot = Directory.GetParent(Application.dataPath).FullName;
            fullPath = Path.GetFullPath(Path.Combine(projectRoot, assetPath));
            return File.Exists(fullPath);
        }
    }

    /// <summary>
    /// 在不重写其它 JSON 字段的前提下更新 asmdef references 数组。
    /// </summary>
    internal static class EFAssemblyReferenceUtility
    {
        internal const string AggregateAssemblyName = "EF";

        private static readonly string[] RequiredReferences =
        {
            AggregateAssemblyName,
            "EF.Base",
            "EF.Bootstrap",
            "EF.Commercial",
            "EF.DataDriven",
            "EF.Debugger",
            "EF.Entity",
            "EF.Event",
            "EF.Fsm",
            "EF.Model",
            "EF.ObjectPool",
            "EF.Procedure",
            "EF.Resource",
            "EF.Save",
            "EF.Scene",
            "EF.Sound",
            "EF.Timer",
            "EF.UI"
        };

        private static readonly HashSet<string> RequiredReferenceSet =
            new HashSet<string>(RequiredReferences, StringComparer.Ordinal);

        /// <summary>
        /// 获取一键接入时写入的完整程序集引用顺序。
        /// </summary>
        internal static IReadOnlyList<string> RuntimeReferences => RequiredReferences;

        /// <summary>
        /// 判断 asmdef 是否是允许接入完整 EF 引用的 consumer 程序集。
        /// </summary>
        internal static bool CanAddAllReferences(string json)
        {
            if (!TryParseAssemblyDefinition(json, out AssemblyDefinitionReferences definition))
            {
                return false;
            }

            return !RequiredReferenceSet.Contains(definition.name);
        }

        /// <summary>
        /// 幂等地向 asmdef JSON 添加完整 EF 引用，并保留 references 之外的原始文本。
        /// </summary>
        internal static string AddAllReferences(string json, out bool changed)
        {
            if (!TryParseAssemblyDefinition(json, out AssemblyDefinitionReferences definition))
            {
                throw new InvalidDataException("程序集定义 JSON 无效或缺少 name 字段。");
            }

            if (RequiredReferenceSet.Contains(definition.name))
            {
                throw new InvalidOperationException($"不能向 EF 运行时程序集 {definition.name} 添加聚合引用，否则会产生循环依赖。");
            }

            string[] existingReferences = definition.references ?? Array.Empty<string>();
            var mergedReferences = new List<string>(existingReferences.Length + RequiredReferences.Length);
            var seenReferences = new HashSet<string>(StringComparer.Ordinal);

            foreach (string reference in existingReferences)
            {
                if (string.IsNullOrEmpty(reference)
                    || RequiredReferenceSet.Contains(reference)
                    || !seenReferences.Add(reference))
                {
                    continue;
                }

                mergedReferences.Add(reference);
            }

            foreach (string reference in RequiredReferences)
            {
                seenReferences.Add(reference);
                mergedReferences.Add(reference);
            }

            if (existingReferences.SequenceEqual(mergedReferences, StringComparer.Ordinal))
            {
                changed = false;
                return json;
            }

            FindReferencesArray(json, out int arrayStart, out int arrayEnd);
            string replacement = SerializeReferencesArray(mergedReferences);
            changed = true;
            return json.Substring(0, arrayStart)
                   + replacement
                   + json.Substring(arrayEnd + 1);
        }

        /// <summary>
        /// 更新磁盘上的 asmdef；内容未变化时不写文件。
        /// </summary>
        internal static bool AddAllReferencesToFile(string fullPath)
        {
            if (string.IsNullOrWhiteSpace(fullPath))
            {
                throw new ArgumentException("程序集定义路径不能为空。", nameof(fullPath));
            }

            string original = File.ReadAllText(fullPath);
            string updated = AddAllReferences(original, out bool changed);
            if (!changed)
            {
                return false;
            }

            File.WriteAllText(fullPath, updated, new UTF8Encoding(false));
            return true;
        }

        /// <summary>
        /// 解析 asmdef 的名称和引用字段。
        /// </summary>
        private static bool TryParseAssemblyDefinition(
            string json,
            out AssemblyDefinitionReferences definition)
        {
            definition = null;
            if (string.IsNullOrWhiteSpace(json))
            {
                return false;
            }

            try
            {
                definition = JsonUtility.FromJson<AssemblyDefinitionReferences>(json);
                return definition != null && !string.IsNullOrWhiteSpace(definition.name);
            }
            catch (ArgumentException)
            {
                definition = null;
                return false;
            }
        }

        /// <summary>
        /// 定位原 JSON 中 references 数组的首尾字符位置。
        /// </summary>
        private static void FindReferencesArray(string json, out int arrayStart, out int arrayEnd)
        {
            int propertyIndex = json.IndexOf("\"references\"", StringComparison.Ordinal);
            if (propertyIndex < 0)
            {
                throw new InvalidDataException("程序集定义缺少 references 数组。");
            }

            int colonIndex = json.IndexOf(':', propertyIndex + "\"references\"".Length);
            arrayStart = colonIndex >= 0 ? json.IndexOf('[', colonIndex + 1) : -1;
            if (arrayStart < 0)
            {
                throw new InvalidDataException("程序集定义的 references 字段不是数组。");
            }

            bool inString = false;
            bool escaped = false;
            int depth = 0;
            for (int index = arrayStart; index < json.Length; index++)
            {
                char character = json[index];
                if (inString)
                {
                    if (escaped)
                    {
                        escaped = false;
                    }
                    else if (character == '\\')
                    {
                        escaped = true;
                    }
                    else if (character == '"')
                    {
                        inString = false;
                    }

                    continue;
                }

                if (character == '"')
                {
                    inString = true;
                }
                else if (character == '[')
                {
                    depth++;
                }
                else if (character == ']')
                {
                    depth--;
                    if (depth == 0)
                    {
                        arrayEnd = index;
                        return;
                    }
                }
            }

            throw new InvalidDataException("程序集定义的 references 数组未闭合。");
        }

        /// <summary>
        /// 使用 Unity JSON 转义规则序列化 references 数组。
        /// </summary>
        private static string SerializeReferencesArray(IReadOnlyCollection<string> references)
        {
            var wrapper = new AssemblyDefinitionReferences
            {
                name = "Temporary",
                references = references.ToArray()
            };
            string wrapperJson = JsonUtility.ToJson(wrapper, true);
            FindReferencesArray(wrapperJson, out int arrayStart, out int arrayEnd);
            return wrapperJson.Substring(arrayStart, arrayEnd - arrayStart + 1);
        }

        [Serializable]
        private sealed class AssemblyDefinitionReferences
        {
            public string name;
            public string[] references;
        }
    }
}
