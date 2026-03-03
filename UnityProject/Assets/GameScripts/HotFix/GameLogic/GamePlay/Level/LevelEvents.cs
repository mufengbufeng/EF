using EF.Event;

namespace GameLogic
{
    /// <summary>
    /// 关卡进入事件。
    /// </summary>
    public sealed class LevelEnterEvent : BaseEventArgs
    {
        public LevelEnterEvent(int levelId)
        {
            LevelId = levelId;
        }

        public override int EventId => (int)EGameEvent.LevelEnterEvent;

        public int LevelId { get; }
    }

    /// <summary>
    /// 关卡完成事件。
    /// </summary>
    public sealed class LevelCompleteEvent : BaseEventArgs
    {
        public LevelCompleteEvent(int levelId, int stars, bool isNewRecord)
        {
            LevelId = levelId;
            Stars = stars;
            IsNewRecord = isNewRecord;
        }

        public override int EventId => (int)EGameEvent.LevelCompleteEvent;

        public int LevelId { get; }
        public int Stars { get; }
        public bool IsNewRecord { get; }
    }

    /// <summary>
    /// 关卡失败事件。
    /// </summary>
    public sealed class LevelFailedEvent : BaseEventArgs
    {
        public LevelFailedEvent(int levelId)
        {
            LevelId = levelId;
        }

        public override int EventId => (int)EGameEvent.LevelFailedEvent;

        public int LevelId { get; }
    }

    /// <summary>
    /// 关卡解锁事件。
    /// </summary>
    public sealed class LevelUnlockedEvent : BaseEventArgs
    {
        public LevelUnlockedEvent(int levelId)
        {
            LevelId = levelId;
        }

        public override int EventId => (int)EGameEvent.LevelUnlockedEvent;

        public int LevelId { get; }
    }

    /// <summary>
    /// 关卡开始事件。
    /// </summary>
    public sealed class LevelStartEvent : BaseEventArgs
    {
        public LevelStartEvent(int levelId)
        {
            LevelId = levelId;
        }

        public override int EventId => (int)EGameEvent.LevelStartEvent;

        public int LevelId { get; }
    }
}
