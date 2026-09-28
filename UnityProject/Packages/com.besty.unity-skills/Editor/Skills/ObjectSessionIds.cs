using System;
using System.Collections.Generic;
using System.Linq;
using UnityEditor;
using UnityEngine;
using Object = UnityEngine.Object;

namespace UnitySkills
{
    /// <summary>
    /// 将编辑器会话中的 Unity 对象映射为工具协议使用的整数句柄。
    /// </summary>
    public static class ObjectSessionIds
    {
#if UNITY_6000_6_OR_NEWER
        private static readonly Dictionary<EntityId, int> IdsByEntity = new Dictionary<EntityId, int>();
        private static readonly Dictionary<int, EntityId> EntitiesById = new Dictionary<int, EntityId>();
        private static int _nextId;
#endif

        /// <summary>
        /// 获取当前编辑器会话内稳定的非零句柄，不截断原生 EntityId。
        /// </summary>
        public static int GetSessionId(this Object obj)
        {
            if (obj == null)
                return 0;

#if UNITY_6000_6_OR_NEWER
            EntityId entityId = obj.GetEntityId();
            if (IdsByEntity.TryGetValue(entityId, out int sessionId))
                return sessionId;

            if (_nextId == int.MaxValue)
                throw new InvalidOperationException("编辑器会话中的对象句柄已耗尽。");

            sessionId = ++_nextId;
            IdsByEntity.Add(entityId, sessionId);
            EntitiesById.Add(sessionId, entityId);
            return sessionId;
#else
            return obj.GetInstanceID();
#endif
        }

        /// <summary>
        /// 将本会话返回的整数句柄解析为 Unity 对象。
        /// </summary>
        public static Object Resolve(int sessionId)
        {
            if (sessionId == 0)
                return null;

#if UNITY_6000_6_OR_NEWER
            return EntitiesById.TryGetValue(sessionId, out EntityId entityId)
                ? EditorUtility.EntityIdToObject(entityId)
                : null;
#else
            return EditorUtility.InstanceIDToObject(sessionId);
#endif
        }

        /// <summary>
        /// 将当前选中对象转换为可供书签保存的会话句柄。
        /// </summary>
        public static int[] GetSelectedIds()
        {
            return Selection.objects.Select(GetSessionId).ToArray();
        }

        /// <summary>
        /// 根据会话句柄恢复仍然存在的选中对象。
        /// </summary>
        public static void SetSelectedIds(IEnumerable<int> sessionIds)
        {
            Selection.objects = sessionIds.Select(Resolve).Where(obj => obj != null).ToArray();
        }

        /// <summary>
        /// 判断对象引用字段是否保留了未解析的原生对象标识。
        /// </summary>
        public static bool HasUnresolvedReference(SerializedProperty property)
        {
#if UNITY_6000_6_OR_NEWER
            return EntityId.ToULong(property.objectReferenceEntityIdValue) != 0;
#else
            return property.objectReferenceInstanceIDValue != 0;
#endif
        }
    }
}
