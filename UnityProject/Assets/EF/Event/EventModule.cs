using System;
using System.Collections.Generic;

namespace EF
{
    public class EventModule : BehaviourSingleton<EventModule>
    {
        private Dictionary<int, Action<object[]>> _eventDictionay; // 事件字典

        protected override void Awake()
        {
            base.Awake();
            _eventDictionay = new Dictionary<int, Action<object[]>>();
        }

        /// <summary>
        ///  添加事件监听
        /// </summary>
        /// <param name="eventId">事件名</param>
        /// <param name="listener">事件监听函数</param>
        public void Add(int eventId, Action<object[]> listener)
        {
            if (_eventDictionay.TryGetValue(eventId, out var thisEvent))
            {
                thisEvent += listener;
                _eventDictionay[eventId] = thisEvent;
            }
            else
            {
                thisEvent += listener;
                _eventDictionay.Add(eventId, thisEvent);
            }
        }

        /// <summary>
        /// 移除事件监听
        /// </summary>
        /// <param name="eventId">事件名</param>
        /// <param name="listener">监听函数</param>
        public void Remove(int eventId, Action<object[]> listener)
        {
            if (_eventDictionay.TryGetValue(eventId, out var thisEvent))
            {
                thisEvent -= listener;
                _eventDictionay[eventId] = thisEvent;
            }
        }

        /// <summary>
        ///  移除所有事件监听
        /// </summary>
        /// <param name="eventId">事件名</param>
        public void RemoveAll(int eventId)
        {
            if (_eventDictionay.ContainsKey(eventId))
            {
                _eventDictionay.Remove(eventId);
            }
        }

        /// <summary>
        /// 触发事件
        /// </summary>
        /// <param name="eventId">事件名</param>
        /// <param name="message">携带参数</param>
        public void Trigger(int eventId, params object[] message)
        {
            if (_eventDictionay.TryGetValue(eventId, out var thisEvent))
            {
                thisEvent.Invoke(message);
            }
        }

        protected override void OnDestroy()
        {
            _eventDictionay.Clear();
        }
    }
}