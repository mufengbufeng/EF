using System;
using System.Collections.Generic;

namespace EF.Event
{
    /// <summary>
    /// 管理事件处理器的注册、反注册与快照生成，确保线程安全和配额约束。
    /// </summary>
    internal sealed class EventHandlerRegistry
    {
        private readonly Dictionary<int, List<EventHandler<object>>> _eventHandlers = new();
        private readonly Dictionary<Delegate, List<HandlerRegistration>> _handlerRegistrations = new();
        private readonly object _syncRoot = new();

        /// <summary>
        /// 当前注册的事件种类数量。
        /// </summary>
        public int EventCount
        {
            get
            {
                lock (_syncRoot)
                {
                    return _eventHandlers.Count;
                }
            }
        }

        /// <summary>
        /// 当前所有事件处理器总数。
        /// </summary>
        public int HandlerCount
        {
            get
            {
                lock (_syncRoot)
                {
                    int count = 0;
                    foreach (List<EventHandler<object>> handlers in _eventHandlers.Values)
                    {
                        count += handlers.Count;
                    }

                    return count;
                }
            }
        }

        /// <summary>
        /// 获取指定事件下的处理器数量。
        /// </summary>
        public int Count(int eventId)
        {
            lock (_syncRoot)
            {
                return _eventHandlers.TryGetValue(eventId, out List<EventHandler<object>> handlers) ? handlers.Count : 0;
            }
        }

        /// <summary>
        /// 检查某个事件是否包含指定的包装处理器。
        /// </summary>
        public bool Contains(int eventId, EventHandler<object> handler)
        {
            if (handler == null)
            {
                throw new ArgumentNullException(nameof(handler), "处理器不能为空");
            }

            lock (_syncRoot)
            {
                return _eventHandlers.TryGetValue(eventId, out List<EventHandler<object>> handlers) && handlers.Contains(handler);
            }
        }

        /// <summary>
        /// 注册新的事件处理器。
        /// </summary>
        public void Subscribe<T>(int eventId, EventPoolModel poolModel, EventHandler<T> listener)
        {
            if (listener == null)
            {
                throw new ArgumentNullException(nameof(listener), "事件监听器不能为空");
            }

            lock (_syncRoot)
            {
                if (!_handlerRegistrations.TryGetValue(listener, out List<HandlerRegistration> registrations))
                {
                    registrations = new List<HandlerRegistration>();
                    _handlerRegistrations.Add(listener, registrations);
                }
                else if ((poolModel & EventPoolModel.AllowDuplicateHandler) == 0)
                {
                    foreach (HandlerRegistration registration in registrations)
                    {
                        if (registration.EventId == eventId)
                        {
                            throw new InvalidOperationException($"事件 {eventId} 已经注册了相同的监听器");
                        }
                    }
                }

                if (!_eventHandlers.TryGetValue(eventId, out List<EventHandler<object>> handlers))
                {
                    handlers = new List<EventHandler<object>>();
                    _eventHandlers.Add(eventId, handlers);
                }
                else if ((poolModel & EventPoolModel.AllowMultiHandler) == 0 && handlers.Count > 0)
                {
                    throw new InvalidOperationException($"事件 {eventId} 不允许注册多个监听器");
                }

                EventHandler<object> wrapper = CreateWrapper(listener);
                handlers.Add(wrapper);
                registrations.Add(new HandlerRegistration(eventId, wrapper));
            }
        }

        /// <summary>
        /// 反注册事件处理器，若未注册则忽略。
        /// </summary>
        public void Unsubscribe<T>(int eventId, EventHandler<T> listener)
        {
            if (listener == null)
            {
                throw new ArgumentNullException(nameof(listener), "事件监听器不能为空");
            }

            lock (_syncRoot)
            {
                if (!_handlerRegistrations.TryGetValue(listener, out List<HandlerRegistration> registrations))
                {
                    return;
                }

                int registrationIndex = -1;
                HandlerRegistration registration = default;

                for (int i = 0; i < registrations.Count; i++)
                {
                    if (registrations[i].EventId == eventId)
                    {
                        registrationIndex = i;
                        registration = registrations[i];
                        break;
                    }
                }

                if (registrationIndex < 0)
                {
                    return;
                }

                registrations.RemoveAt(registrationIndex);
                if (registrations.Count == 0)
                {
                    _handlerRegistrations.Remove(listener);
                }

                if (_eventHandlers.TryGetValue(eventId, out List<EventHandler<object>> handlers))
                {
                    handlers.Remove(registration.Wrapper);
                    if (handlers.Count == 0)
                    {
                        _eventHandlers.Remove(eventId);
                    }
                }
            }
        }

        /// <summary>
        /// 生成指定事件的处理器快照，避免锁内调用外部逻辑。
        /// </summary>
        public List<EventHandler<object>> CreateSnapshot(int eventId)
        {
            lock (_syncRoot)
            {
                if (!_eventHandlers.TryGetValue(eventId, out List<EventHandler<object>> handlers) || handlers.Count == 0)
                {
                    return new List<EventHandler<object>>();
                }

                return new List<EventHandler<object>>(handlers);
            }
        }

        /// <summary>
        /// 清空所有事件注册信息。
        /// </summary>
        public void Clear()
        {
            lock (_syncRoot)
            {
                _eventHandlers.Clear();
                _handlerRegistrations.Clear();
            }
        }

        private static EventHandler<object> CreateWrapper<T>(EventHandler<T> listener)
        {
            return (sender, payload) =>
            {
                if (payload is not T typedPayload)
                {
                    throw new InvalidCastException($"事件载荷类型不匹配，期望 {typeof(T).FullName}，实际 {payload?.GetType().FullName ?? "null"}");
                }

                listener(sender, typedPayload);
            };
        }

        private readonly struct HandlerRegistration
        {
            public HandlerRegistration(int eventId, EventHandler<object> wrapper)
            {
                EventId = eventId;
                Wrapper = wrapper;
            }

            public int EventId { get; }

            public EventHandler<object> Wrapper { get; }
        }
    }
}
