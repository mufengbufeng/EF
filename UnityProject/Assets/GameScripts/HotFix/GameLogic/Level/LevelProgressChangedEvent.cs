using EF.Event;

namespace GameLogic
{
    /// <summary>
    /// 关卡进度变化事件参数。
    /// </summary>
    [EventArgs]
    public readonly struct LevelProgressChangedEvent
    {
        /// <summary>
        /// 当前关卡 ID。
        /// </summary>
        public readonly int LevelId;

        /// <summary>
        /// 当前击杀数。
        /// </summary>
        public readonly int KillCount;

        /// <summary>
        /// 目标击杀数。
        /// </summary>
        public readonly int RequiredKills;

        public LevelProgressChangedEvent(int levelId, int killCount, int requiredKills)
        {
            LevelId = levelId;
            KillCount = killCount;
            RequiredKills = requiredKills;
        }
    }
}
