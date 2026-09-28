using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using NUnit.Framework;
using UnityEditor;
using UnityEngine;
using UnitySkills;

namespace UnitySkills.Tests.Core
{
    [TestFixture]
    public class WorkflowBookmarkTests
    {
        [Test]
        public void SessionId_ResolvesDistinctObjects()
        {
            var first = new GameObject("SessionIdFirst");
            var second = new GameObject("SessionIdSecond");
            try
            {
                int firstId = first.GetSessionId();
                int secondId = second.GetSessionId();

                Assert.That(firstId, Is.Not.EqualTo(0));
                Assert.That(firstId, Is.Not.EqualTo(secondId));
                Assert.That(first.GetSessionId(), Is.EqualTo(firstId));
                Assert.That(ObjectSessionIds.Resolve(firstId), Is.SameAs(first));
                Assert.That(ObjectSessionIds.Resolve(secondId), Is.SameAs(second));
            }
            finally
            {
                Object.DestroyImmediate(first);
                Object.DestroyImmediate(second);
            }
        }

        [Test]
        public void BookmarkGoto_RestoresSelectionBySessionId()
        {
            var selected = new GameObject("BookmarkSelected");
            var other = new GameObject("BookmarkOther");
            try
            {
                Selection.activeObject = selected;
                WorkflowSkills.BookmarkSet("SessionIdBookmark");
                Selection.activeObject = other;

                WorkflowSkills.BookmarkGoto("SessionIdBookmark");

                Assert.That(Selection.activeObject, Is.SameAs(selected));
            }
            finally
            {
                WorkflowSkills.BookmarkDelete("SessionIdBookmark");
                Selection.activeObject = null;
                Object.DestroyImmediate(selected);
                Object.DestroyImmediate(other);
            }
        }

        [Test]
        public void BookmarkSet_ThenBookmarkList_ReturnsCreatedBookmark()
        {
            var setJson = ToJObject(WorkflowSkills.BookmarkSet("BookmarkTest", "bookmark note"));
            Assert.That(setJson["success"]?.Value<bool>(), Is.True);

            var listJson = ToJObject(WorkflowSkills.BookmarkList());
            Assert.That(listJson["success"]?.Value<bool>(), Is.True);
            Assert.That(listJson["count"]?.Value<int>(), Is.GreaterThanOrEqualTo(1));
            Assert.That(listJson["bookmarks"]?.ToString(), Does.Contain("BookmarkTest"));

            var deleteJson = ToJObject(WorkflowSkills.BookmarkDelete("BookmarkTest"));
            Assert.That(deleteJson["success"]?.Value<bool>(), Is.True);
        }

        private static JObject ToJObject(object result)
        {
            return JObject.Parse(JsonConvert.SerializeObject(result));
        }
    }
}
