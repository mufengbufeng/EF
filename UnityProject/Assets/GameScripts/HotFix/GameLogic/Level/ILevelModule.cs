using System;
using EF.Common;

namespace GameLogic
{
    public interface ILevelModule : IEFManager
    {
        int CurrentLevelId { get; }
        int KillCount { get; }
        int RequiredKills { get; }
        void RecordKill();
        bool CheckLevelComplete();
        void AdvanceToNextLevel();
        void ResetProgress();
        void LoadProgress();
        void SaveProgress();
    }
}
