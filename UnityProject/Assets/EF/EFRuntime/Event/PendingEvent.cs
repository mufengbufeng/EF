namespace EF.Event
{
    /// <summary>
    /// 表示一个待分发的事件实例，记录发送者与事件参数。
    /// </summary>
    internal readonly struct PendingEvent
    {
        public PendingEvent(object sender, BaseEventArgs eventArgs)
        {
            Sender = sender;
            EventArgs = eventArgs;
        }

        /// <summary>
        /// 触发事件的对象。
        /// </summary>
        public object Sender { get; }

        /// <summary>
        /// 事件参数。
        /// </summary>
        public BaseEventArgs EventArgs { get; }
    }
}
