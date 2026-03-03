using System.Collections.Generic;
using EF.Common;

namespace GameLogic
{
    /// <summary>
    /// 关卡模块接口。
    /// </summary>
    public interface ILevelModule : IEFManager
    {
        int CurrentLevelId { get; }
        int CurrentLevelProgress { get; }
        int MaxUnlockedLevelId { get; }

        bool EnterLevel(int levelId);
        void CompleteLevel(int stars);
        void UnlockNextLevel(int levelId);
        int GetLevelStars(int levelId);

        void SetProgress(int progress);
        void AddProgress(int delta);

        IReadOnlyDictionary<int, int> GetAllLevelStars();
        int GetTotalStars();
    }
}
