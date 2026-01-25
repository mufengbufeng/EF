using System;
using System.Collections.Generic;
using EF.Common;
using EF.Debugger;

namespace EF.Event
{
    /// <summary>
    /// 事件管理器，负责事件监听的注册、派发与生命周期管理，可根据池化策略进行运行时调整。
    /// </summary>
    public sealed class EventManager : AEFManager, IEventManager
    {
        private readonly EventHandlerRegistry _handlerRegistry = new();
        private readonly EventTypeResolver _eventTypeResolver = new();
        private readonly PendingEventQueue _pendingEventQueue = new();
        private readonly List<PendingEvent> _dispatchBuffer = new();

        /// <summary>
        /// 初始化事件管理器。
        /// </summary>
        public EventManager()
        {
            PoolModel = EventPoolModel.Default;
        }

        /// <summary>
        /// 事件池策略控制枚举，可在运行时调整事件注册约束。
        /// </summary>
        public EventPoolModel PoolModel { get; set; }

        /// <inheritdoc />
        public int EventCount => _handlerRegistry.EventCount;

        /// <inheritdoc />
        public int EventHandlerCount => _handlerRegistry.HandlerCount;

        /// <inheritdoc />
        public int Count(int id) => _handlerRegistry.Count(id);

        /// <inheritdoc />
        public bool Check(int id, EventHandler<object> listener) => _handlerRegistry.Contains(id, listener);

        /// <inheritdoc />
        public void Subscribe<T>(EventHandler<T> listener) where T : BaseEventArgs
        {
            if (listener == null)
            {
                throw new ArgumentNullException(nameof(listener), "事件监听器不能为空");
            }

            int eventId = _eventTypeResolver.GetEventId(typeof(T));
            _handlerRegistry.Subscribe(eventId, PoolModel, listener);
        }

        /// <inheritdoc />
        public void Unsubscribe<T>(EventHandler<T> listener) where T : BaseEventArgs
        {
            if (listener == null)
            {
                throw new ArgumentNullException(nameof(listener), "事件监听器不能为空");
            }

            int eventId = _eventTypeResolver.GetEventId(typeof(T));
            _handlerRegistry.Unsubscribe(eventId, listener);
        }

        /// <inheritdoc />
        public void Publish<T>(T eventData) where T : BaseEventArgs
        {
            BaseEventArgs eventArgs = _eventTypeResolver.ConvertToEventArgs(eventData);
            _pendingEventQueue.Enqueue(new PendingEvent(this, eventArgs));
        }

        /// <inheritdoc />
        public void PublishNow<T>(T eventData) where T : BaseEventArgs
        {
            BaseEventArgs eventArgs = _eventTypeResolver.ConvertToEventArgs(eventData);
            Dispatch(new PendingEvent(this, eventArgs));
        }

        /// <summary>
        /// 处理排队事件，一般在 Unity Update 生命周期内调用。
        /// </summary>
        public override void Update(float elapseSeconds, float realElapseSeconds)
        {
            _dispatchBuffer.Clear();
            _pendingEventQueue.DrainTo(_dispatchBuffer);

            foreach (PendingEvent pendingEvent in _dispatchBuffer)
            {
                Dispatch(pendingEvent);
            }

            _dispatchBuffer.Clear();
        }

        /// <summary>
        /// 停止事件管理器并释放内部资源。
        /// </summary>
        public override void Shutdown()
        {
            _handlerRegistry.Clear();
            _pendingEventQueue.Clear();
            _dispatchBuffer.Clear();
        }

        private void Dispatch(PendingEvent pendingEvent)
        {
            List<EventHandler<object>> handlerSnapshot = _handlerRegistry.CreateSnapshot(pendingEvent.EventArgs.EventId);
            if (handlerSnapshot.Count == 0)
            {
                if ((PoolModel & EventPoolModel.AllowNoHandler) == 0)
                {
                    Log.Warning($"[EventManager] 事件 {pendingEvent.EventArgs.EventId} 没有注册任何监听器");
                }

                return;
            }

            foreach (EventHandler<object> handler in handlerSnapshot)
            {
                handler(pendingEvent.Sender, pendingEvent.EventArgs);
            }
        }
    }
}
