namespace EF.Event
{
    /// <summary>
    /// 所有事件参数的基类，要求子类提供唯一的事件标识。
    /// </summary>
    public abstract class BaseEventArgs
    {
        /// <summary>
        /// 获取事件的唯一标识，建议使用常量或静态缓存以避免重复计算。
        /// </summary>
        public abstract int EventId { get; }
    }
}
