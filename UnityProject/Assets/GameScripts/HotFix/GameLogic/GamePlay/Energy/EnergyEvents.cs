using EF.Event;

namespace GameLogic
{
    /// <summary>
    /// 体力值变化事件。
    /// </summary>
    public sealed class EnergyChangedEvent : BaseEventArgs
    {
        public EnergyChangedEvent(int currentEnergy, int maxEnergy, int delta)
        {
            CurrentEnergy = currentEnergy;
            MaxEnergy = maxEnergy;
            Delta = delta;
        }

        public override int EventId => (int)EGameEvent.EnergyChangedEvent;

        public int CurrentEnergy { get; }
        public int MaxEnergy { get; }
        public int Delta { get; }
    }

    /// <summary>
    /// 体力不足事件。
    /// </summary>
    public sealed class EnergyNotEnoughEvent : BaseEventArgs
    {
        public EnergyNotEnoughEvent(int currentEnergy, int requiredEnergy)
        {
            CurrentEnergy = currentEnergy;
            RequiredEnergy = requiredEnergy;
        }

        public override int EventId => (int)EGameEvent.EnergyNotEnoughEvent;

        public int CurrentEnergy { get; }
        public int RequiredEnergy { get; }
    }
}
