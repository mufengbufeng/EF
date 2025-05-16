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
        /// <param name="eventName">事件名</param>
        /// <param name="listener">事件监听函数</param>
        public void Add(int eventName, Action<object[]> listener)
        {
            if (_eventDictionay.TryGetValue(eventName, out var thisEvent))
            {
                thisEvent += listener;
                _eventDictionay[eventName] = thisEvent;
            }
            else
            {
                thisEvent += listener;
                _eventDictionay.Add(eventName, thisEvent);
            }
        }

        /// <summary>
        /// 移除事件监听
        /// </summary>
        /// <param name="eventName">事件名</param>
        /// <param name="listener">监听函数</param>
        public void Remove(int eventName, Action<object[]> listener)
        {
            if (_eventDictionay.TryGetValue(eventName, out var thisEvent))
            {
                thisEvent -= listener;
                _eventDictionay[eventName] = thisEvent;
            }
        }

        /// <summary>
        ///  移除所有事件监听
        /// </summary>
        /// <param name="eventName">事件名</param>
        public void RemoveAll(int eventName)
        {
            if (_eventDictionay.ContainsKey(eventName))
            {
                _eventDictionay.Remove(eventName);
            }
        }

        /// <summary>
        /// 触发事件
        /// </summary>
        /// <param name="eventName">事件名</param>
        /// <param name="message">携带参数</param>
        public void Trigger(int eventName, params object[] message)
        {
            if (_eventDictionay.TryGetValue(eventName, out var thisEvent))
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