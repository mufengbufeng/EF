using EF.Event;

namespace GameLogic
{
    /// <summary>
    /// 体力变化事件参数。
    /// </summary>
    [EventArgs]
    public readonly struct EnergyChangedEvent
    {
        /// <summary>
        /// 当前体力值。
        /// </summary>
        public readonly int Current;

        /// <summary>
        /// 体力上限。
        /// </summary>
        public readonly int Max;

        public EnergyChangedEvent(int current, int max)
        {
            Current = current;
            Max = max;
        }
    }
}
