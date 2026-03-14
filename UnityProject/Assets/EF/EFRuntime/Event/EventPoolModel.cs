namespace EF.Event
{
    /// <summary>
    /// 控制事件池行为的策略枚举，可按位组合使用。
    /// </summary>
    public enum EventPoolModel
    {
        /// <summary>
        /// 默认策略：禁止同一事件注册多个监听器，也不允许重复注册相同监听器。
        /// </summary>
        Default = 0,

        /// <summary>
        /// 允许事件在没有监听器的情况下被触发，默认会抛出异常。
        /// </summary>
        AllowNoHandler = 1,

        /// <summary>
        /// 允许同一事件注册多个监听器。
        /// </summary>
        AllowMultiHandler = 1 << 1,

        /// <summary>
        /// 允许同一监听器重复注册到同一事件。
        /// </summary>
        AllowDuplicateHandler = 1 << 2
    }
}
