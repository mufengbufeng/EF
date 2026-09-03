using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using EF.Editor;
using NUnit.Framework;
using UnityEngine;

namespace GameLogic.Tests.EditMode.Framework
{
    /// <summary>
    /// 验证完整 EF 引用写入、字段保留和循环依赖保护。
    /// </summary>
    [TestFixture]
    public sealed class EFAssemblyReferenceUtilityTests
    {
        private const string ConsumerAssemblyJson =
            "{\n" +
            "    \"name\": \"Consumer.Game\",\n" +
            "    \"rootNamespace\": \"Consumer\",\n" +
            "    \"references\": [\n" +
            "        \"EF.Base\",\n" +
            "        \"External.Assembly\",\n" +
            "        \"EF.Base\",\n" +
            "        \"EF.UI\"\n" +
            "    ],\n" +
            "    \"customField\": {\"keep\": true},\n" +
            "    \"autoReferenced\": false\n" +
            "}\n";

        /// <summary>
        /// 确保工具保留外部引用和未知字段，并按固定顺序添加全部 EF 引用。
        /// </summary>
        [Test]
        public void AddAllReferences_保留其它字段并规范化EF引用()
        {
            string updated = EFAssemblyReferenceUtility.AddAllReferences(
                ConsumerAssemblyJson,
                out bool changed);

            Assert.That(changed, Is.True);
            StringAssert.Contains("\"customField\": {\"keep\": true}", updated);
            StringAssert.Contains("\"rootNamespace\": \"Consumer\"", updated);

            AssemblyDefinitionReferences definition =
                JsonUtility.FromJson<AssemblyDefinitionReferences>(updated);
            var expected = new List<string> { "External.Assembly" };
            expected.AddRange(EFAssemblyReferenceUtility.RuntimeReferences);
            CollectionAssert.AreEqual(expected, definition.references);
        }

        /// <summary>
        /// 确保重复执行不会再次改写程序集定义。
        /// </summary>
        [Test]
        public void AddAllReferences_重复执行保持幂等()
        {
            string first = EFAssemblyReferenceUtility.AddAllReferences(
                ConsumerAssemblyJson,
                out bool firstChanged);
            string second = EFAssemblyReferenceUtility.AddAllReferences(first, out bool secondChanged);

            Assert.That(firstChanged, Is.True);
            Assert.That(secondChanged, Is.False);
            Assert.That(second, Is.EqualTo(first));
        }

        /// <summary>
        /// 确保磁盘写入仅修改一次，并保留 UTF-8 无 BOM 文本。
        /// </summary>
        [Test]
        public void AddAllReferencesToFile_写入目标Asmdef且第二次不写入()
        {
            string path = Path.Combine(
                Application.temporaryCachePath,
                $"ef-assembly-reference-{Guid.NewGuid():N}.asmdef");

            try
            {
                File.WriteAllText(path, ConsumerAssemblyJson, new UTF8Encoding(false));

                bool firstChanged = EFAssemblyReferenceUtility.AddAllReferencesToFile(path);
                string first = File.ReadAllText(path);
                bool secondChanged = EFAssemblyReferenceUtility.AddAllReferencesToFile(path);
                string second = File.ReadAllText(path);

                Assert.That(firstChanged, Is.True);
                Assert.That(secondChanged, Is.False);
                Assert.That(second, Is.EqualTo(first));
                Assert.That(File.ReadAllBytes(path).Take(3), Is.Not.EqualTo(new byte[] { 0xEF, 0xBB, 0xBF }));
            }
            finally
            {
                if (File.Exists(path))
                {
                    File.Delete(path);
                }
            }
        }

        /// <summary>
        /// 确保 EF 聚合及其模块不能反向引用 EF，避免程序集循环。
        /// </summary>
        [TestCase("EF")]
        [TestCase("EF.Base")]
        [TestCase("EF.Resource")]
        [TestCase("EF.UI")]
        public void AddAllReferences_拒绝EF运行时程序集(string assemblyName)
        {
            string json = CreateAssemblyDefinitionJson(assemblyName);

            Assert.That(EFAssemblyReferenceUtility.CanAddAllReferences(json), Is.False);
            Assert.Throws<InvalidOperationException>(
                () => EFAssemblyReferenceUtility.AddAllReferences(json, out _));
        }

        /// <summary>
        /// 创建具有空引用数组的最小程序集定义 JSON。
        /// </summary>
        private static string CreateAssemblyDefinitionJson(string assemblyName)
        {
            return "{\n"
                   + $"    \"name\": \"{assemblyName}\",\n"
                   + "    \"references\": []\n"
                   + "}\n";
        }

        [Serializable]
        private sealed class AssemblyDefinitionReferences
        {
            public string[] references;
        }
    }
}
