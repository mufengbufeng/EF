using System;
using System.Collections.Generic;
using System.Reflection;

namespace EF.Event
{
    /// <summary>
    /// 负责校验事件类型并解析事件标识，内部带有缓存以减少反射成本。
    /// </summary>
    internal sealed class EventTypeResolver
    {
        private readonly Dictionary<Type, int> _eventIdCache = new();
        private readonly object _cacheLock = new();

        /// <summary>
        /// 根据事件类型获取事件标识，若尚未缓存则自动解析并写入缓存。
        /// </summary>
        /// <param name="eventType">事件参数类型，必须继承 <see cref="BaseEventArgs"/>。</param>
        /// <returns>事件标识。</returns>
        public int GetEventId(Type eventType)
        {
            if (eventType == null)
            {
                throw new ArgumentNullException(nameof(eventType), "事件类型不能为空");
            }

            EnsureEventArgsType(eventType);

            lock (_cacheLock)
            {
                if (_eventIdCache.TryGetValue(eventType, out int cachedId))
                {
                    return cachedId;
                }
            }

            int eventId = ExtractEventId(eventType);

            lock (_cacheLock)
            {
                if (_eventIdCache.TryGetValue(eventType, out int cachedId))
                {
                    return cachedId;
                }

                _eventIdCache.Add(eventType, eventId);
                return eventId;
            }
        }

        /// <summary>
        /// 将泛型事件数据转换为 <see cref="BaseEventArgs"/>，并确保不为空。
        /// </summary>
        /// <typeparam name="T">事件数据的泛型类型。</typeparam>
        /// <param name="eventData">事件数据实例。</param>
        /// <returns>事件参数对象。</returns>
        public BaseEventArgs ConvertToEventArgs<T>(T eventData)
        {
            if (eventData == null)
            {
                throw new ArgumentNullException(nameof(eventData), "事件数据不能为空");
            }

            if (eventData is not BaseEventArgs eventArgs)
            {
                throw new ArgumentException("事件数据必须继承 BaseEventArgs", nameof(eventData));
            }

            return eventArgs;
        }

        private static void EnsureEventArgsType(Type eventType)
        {
            if (!typeof(BaseEventArgs).IsAssignableFrom(eventType))
            {
                throw new ArgumentException($"事件类型 {eventType.FullName} 必须继承 BaseEventArgs", nameof(eventType));
            }
        }

        private static int ExtractEventId(Type eventType)
        {
            const BindingFlags flags = BindingFlags.Public | BindingFlags.Static | BindingFlags.FlattenHierarchy;

            PropertyInfo propertyInfo = eventType.GetProperty("EventId", flags);
            if (propertyInfo != null && propertyInfo.PropertyType == typeof(int))
            {
                return (int)propertyInfo.GetValue(null);
            }

            FieldInfo fieldInfo = eventType.GetField("EventId", flags);
            if (fieldInfo != null && fieldInfo.FieldType == typeof(int))
            {
                return (int)fieldInfo.GetValue(null);
            }

            try
            {
                if (Activator.CreateInstance(eventType) is not BaseEventArgs instance)
                {
                    throw new ArgumentException($"事件类型 {eventType.FullName} 必须继承 BaseEventArgs", nameof(eventType));
                }

                return instance.EventId;
            }
            catch (Exception ex)
            {
                throw new ArgumentException($"无法为事件类型 {eventType.FullName} 自动解析 EventId，请提供静态字段/属性或无参构造函数", nameof(eventType), ex);
            }
        }
    }
}
