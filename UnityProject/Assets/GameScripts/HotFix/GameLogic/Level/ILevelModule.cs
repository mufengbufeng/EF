using GameConfig.level;
using EF.Common;

namespace GameLogic
{
    /// <summary>
    /// 关卡模块接口。
    /// 负责当前关卡读取、击杀计数与通关推进。
    /// </summary>
    public interface ILevelModule : IEFManager
    {
        /// <summary>
        /// 获取当前关卡 ID。
        /// </summary>
        int GetCurrentLevelId();

        /// <summary>
        /// 根据关卡 ID 获取关卡配置。
        /// </summary>
        Level GetLevelConfig(int levelId);

        /// <summary>
        /// 记录一次击杀。
        /// </summary>
        void RecordKill();

        /// <summary>
        /// 检查当前关卡是否已完成。
        /// </summary>
        bool CheckLevelComplete();

        /// <summary>
        /// 推进到下一关并持久化。
        /// </summary>
        void AdvanceToNextLevel();

        /// <summary>
        /// 重置当前关卡的击杀计数。
        /// </summary>
        void ResetCurrentLevel();

        /// <summary>
        /// 获取当前局内击杀计数。
        /// </summary>
        int GetCurrentKillCount();
    }
}
