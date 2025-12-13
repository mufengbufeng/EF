using System;
using EF.Common;

namespace EF.Event
{
    /// <summary>
    /// 定义事件管理器需要实现的核心能力接口。
    /// </summary>
    public interface IEventManager : IEFManager
    {
        /// <summary>
        /// 当前注册的事件种类数量。
        /// </summary>
        int EventCount { get; }

        /// <summary>
        /// 已注册的事件处理器总数。
        /// </summary>
        int EventHandlerCount { get; }

        /// <summary>
        /// 获取指定事件标识下的处理器数量。
        /// </summary>
        int Count(int id);

        /// <summary>
        /// 检查指定事件是否包含目标处理器。
        /// </summary>
        bool Check(int id, EventHandler<object> listener);

        /// <summary>
        /// 注册事件监听器。
        /// </summary>
        void Subscribe<T>(EventHandler<T> listener);

        /// <summary>
        /// 反注册事件监听器。
        /// </summary>
        void Unsubscribe<T>(EventHandler<T> listener);

        /// <summary>
        /// 异步派发事件，事件将进入下一帧的分发队列。
        /// </summary>
        void Publish<T>(T eventData);

        /// <summary>
        /// 同步立即派发事件，立刻执行所有监听器。
        /// </summary>
        void PublishNow<T>(T eventData);
    }
}
