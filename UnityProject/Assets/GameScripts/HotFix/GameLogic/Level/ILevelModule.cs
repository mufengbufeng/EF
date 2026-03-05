using System;
using EF.Common;

namespace GameLogic
{
    public interface ILevelModule : IEFManager
    {
        int CurrentLevelId { get; }
        int KillCount { get; }
        int RequiredKills { get; }
        
        /// <summary>
        /// 关卡进度变化事件（参数：关卡ID, 当前击杀数, 目标击杀数）
        /// </summary>
        event Action<int, int, int> OnProgressChanged;
        
        /// <summary>
        /// 关卡通关事件
        /// </summary>
        event Action OnLevelComplete;
        
        void RecordKill();
        bool CheckLevelComplete();
        void AdvanceToNextLevel();
        void ResetProgress();
    }
}
