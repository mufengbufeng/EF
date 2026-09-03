using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using NUnit.Framework;
using UnityEngine;

namespace GameLogic.Tests.EditMode.Framework
{
    /// <summary>
    /// 验证 EF.Base、聚合程序集与 EFRuntime 可选模块的程序集边界。
    /// </summary>
    [TestFixture]
    public sealed class RuntimeAssemblyBoundaryTests
    {
        private const string BaseAssemblyName = "EF.Base";
        private const string AggregateAssemblyName = "EF";
        private static readonly string EfRootPath = Path.Combine(Application.dataPath, "EF");
        private static readonly string BasePath = Path.Combine(EfRootPath, "Base");

        private static readonly IReadOnlyDictionary<string, string[]> ExpectedEfReferences =
            new Dictionary<string, string[]>
            {
                [BaseAssemblyName] = Array.Empty<string>(),
                ["EF.Bootstrap"] = Array.Empty<string>(),
                ["EF.Commercial"] = new[] { BaseAssemblyName },
                ["EF.DataDriven"] = Array.Empty<string>(),
                ["EF.Debugger"] = Array.Empty<string>(),
                ["EF.Entity"] = new[] { BaseAssemblyName, "EF.ObjectPool", "EF.Resource" },
                ["EF.Event"] = new[] { BaseAssemblyName },
                ["EF.Fsm"] = new[] { BaseAssemblyName },
                ["EF.Model"] = new[] { BaseAssemblyName },
                ["EF.ObjectPool"] = new[] { BaseAssemblyName },
                ["EF.Procedure"] = new[] { BaseAssemblyName, "EF.Fsm" },
                ["EF.Resource"] = new[] { BaseAssemblyName, "EF.Debugger" },
                ["EF.Save"] = new[] { BaseAssemblyName, "EF.Debugger" },
                ["EF.Scene"] = new[] { BaseAssemblyName, "EF.Debugger", "EF.Resource" },
                ["EF.Sound"] = new[] { BaseAssemblyName, "EF.Resource" },
                ["EF.Timer"] = new[] { BaseAssemblyName },
                ["EF.UI"] = new[] { BaseAssemblyName, "EF.Resource" }
            };

        /// <summary>
        /// 确保只自动集成无 Unity 引擎依赖的 EF.Base。
        /// </summary>
        [Test]
        public void EFRuntime程序集_仅Base自动引用()
        {
            IReadOnlyDictionary<string, AssemblyDefinitionData> definitions = LoadRuntimeAssemblyDefinitions();

            CollectionAssert.AreEquivalent(
                ExpectedEfReferences.Keys.Append(AggregateAssemblyName),
                definitions.Keys);
            CollectionAssert.AreEquivalent(
                new[] { BaseAssemblyName },
                definitions.Values.Where(definition => definition.autoReferenced)
                    .Select(definition => definition.name));

            AssemblyDefinitionData baseDefinition = definitions[BaseAssemblyName];
            Assert.That(baseDefinition.references, Is.Empty);
            Assert.That(baseDefinition.noEngineReferences, Is.True);
        }

        /// <summary>
        /// 确保 EF.Base 及根级源码均迁入独立 Base 目录。
        /// </summary>
        [Test]
        public void EFBase程序集_位于独立Base目录()
        {
            Assert.That(File.Exists(Path.Combine(BasePath, "EF.Base.asmdef")), Is.True);
            Assert.That(File.Exists(Path.Combine(EfRootPath, "EF.Base.asmdef")), Is.False);
        }

        /// <summary>
        /// 确保完整聚合程序集定义位于 EF 根目录。
        /// </summary>
        [Test]
        public void EF聚合程序集_位于EF根目录()
        {
            Assert.That(File.Exists(Path.Combine(EfRootPath, "EF.asmdef")), Is.True);
            Assert.That(File.Exists(Path.Combine(EfRootPath, "EF.asmref")), Is.False);
            Assert.That(File.Exists(Path.Combine(EfRootPath, "AggregateAssemblyMarker.cs")), Is.True);
            Assert.That(Directory.Exists(Path.Combine(EfRootPath, "EFRuntime")), Is.False);
        }

        /// <summary>
        /// 确保可选模块只声明其真实 EF 下游，不重新依赖聚合程序集。
        /// </summary>
        [Test]
        public void EFRuntime程序集_可选模块依赖保持最小化()
        {
            IReadOnlyDictionary<string, AssemblyDefinitionData> definitions = LoadRuntimeAssemblyDefinitions();

            foreach (KeyValuePair<string, string[]> expected in ExpectedEfReferences)
            {
                string[] actualReferences = definitions[expected.Key].references
                    .Where(reference => reference.StartsWith("EF.", StringComparison.Ordinal))
                    .ToArray();

                CollectionAssert.AreEquivalent(
                    expected.Value,
                    actualReferences,
                    $"程序集 {expected.Key} 的 EF 依赖与模块边界不一致。");
            }

            string[] aggregateReferences = definitions[AggregateAssemblyName].references
                .Where(reference => reference.StartsWith("EF.", StringComparison.Ordinal))
                .ToArray();
            CollectionAssert.AreEquivalent(
                ExpectedEfReferences.Keys,
                aggregateReferences,
                "EF 聚合程序集必须引用全部 EFRuntime 模块。");
        }

        /// <summary>
        /// 按程序集名读取独立 EF.Base、聚合程序集与全部运行时模块定义。
        /// </summary>
        private static IReadOnlyDictionary<string, AssemblyDefinitionData> LoadRuntimeAssemblyDefinitions()
        {
            IEnumerable<string> assemblyNames =
                ExpectedEfReferences.Keys.Append(AggregateAssemblyName);
            var definitions = new Dictionary<string, AssemblyDefinitionData>(StringComparer.Ordinal);

            foreach (string assemblyName in assemblyNames)
            {
                string[] paths = Directory.GetFiles(
                    EfRootPath,
                    assemblyName + ".asmdef",
                    SearchOption.AllDirectories);
                Assert.That(paths, Has.Length.EqualTo(1), $"程序集 {assemblyName} 必须存在且名称唯一。");

                string path = paths[0];
                AssemblyDefinitionData definition = JsonUtility.FromJson<AssemblyDefinitionData>(File.ReadAllText(path));
                Assert.That(definition, Is.Not.Null, $"无法解析程序集定义：{path}");
                Assert.That(definition.name, Is.EqualTo(assemblyName), $"程序集定义名称与文件名不一致：{path}");
                definition.references ??= Array.Empty<string>();
                definitions.Add(definition.name, definition);
            }

            return definitions;
        }

        [Serializable]
        private sealed class AssemblyDefinitionData
        {
            public string name;
            public string[] references;
            public bool autoReferenced;
            public bool noEngineReferences;
        }
    }
}
