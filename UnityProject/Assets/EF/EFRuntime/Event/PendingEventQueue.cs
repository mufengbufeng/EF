using System;
using System.Collections.Generic;

namespace EF.Event
{
    /// <summary>
    /// 管理待分发事件的线程安全队列。
    /// </summary>
    internal sealed class PendingEventQueue
    {
        private readonly Queue<PendingEvent> _pendingEvents = new();
        private readonly object _queueLock = new();

        /// <summary>
        /// 将事件加入待分发队列。
        /// </summary>
        /// <param name="pendingEvent">待分发事件。</param>
        public void Enqueue(PendingEvent pendingEvent)
        {
            lock (_queueLock)
            {
                _pendingEvents.Enqueue(pendingEvent);
            }
        }

        /// <summary>
        /// 将当前所有待分发事件输出到目标缓冲区，并清空队列。
        /// </summary>
        /// <param name="buffer">用于承接事件的缓冲区。</param>
        public void DrainTo(List<PendingEvent> buffer)
        {
            if (buffer == null)
            {
                throw new ArgumentNullException(nameof(buffer), "缓冲区不能为空");
            }

            lock (_queueLock)
            {
                while (_pendingEvents.Count > 0)
                {
                    buffer.Add(_pendingEvents.Dequeue());
                }
            }
        }

        /// <summary>
        /// 清空所有待分发事件。
        /// </summary>
        public void Clear()
        {
            lock (_queueLock)
            {
                _pendingEvents.Clear();
            }
        }
    }
}
