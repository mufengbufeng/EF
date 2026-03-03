using System;
using System.Collections.Generic;
using EF.Common;
using EF.Debugger;
using EF.Event;

namespace GameLogic
{
    /// <summary>
    /// 关卡模块实现。
    /// 负责进入/完成关卡、解锁下一关与星级记录。
    /// </summary>
    public sealed class LevelModule : AEFManager, ILevelModule
    {
        private const int DefaultMaxLevel = 100;
        private const int MaxStars = 3;

        private int _maxLevel = DefaultMaxLevel;
        private int _currentLevelId;
        private int _currentLevelProgress;
        private int _maxUnlockedLevelId = 1;
        private readonly Dictionary<int, int> _levelStars = new();

        public int CurrentLevelId => _currentLevelId;
        public int CurrentLevelProgress => _currentLevelProgress;
        public int MaxUnlockedLevelId => _maxUnlockedLevelId;

        public void Configure(int maxLevel)
        {
            _maxLevel = Math.Max(1, maxLevel);
            _maxUnlockedLevelId = Math.Clamp(_maxUnlockedLevelId, 1, _maxLevel);
            Log.Info($"[LevelModule] Configured: maxLevel={_maxLevel}");
        }

        public void Initialize()
        {
            Log.Info("[LevelModule] Initialized");
        }

        public override void Update(float elapseSeconds, float realElapseSeconds)
        {
            // 当前无逐帧逻辑
        }

        public void Cleanup()
        {
            Log.Info("[LevelModule] Cleanup");
        }

        public override void Shutdown()
        {
            Cleanup();
            Log.Info("[LevelModule] Shutdown");
        }

        public bool EnterLevel(int levelId)
        {
            if (levelId < 1 || levelId > _maxLevel)
            {
                Log.Warning($"[LevelModule] Invalid levelId: {levelId}");
                return false;
            }

            if (levelId > _maxUnlockedLevelId)
            {
                Log.Info($"[LevelModule] Level locked: {levelId}, maxUnlocked={_maxUnlockedLevelId}");
                return false;
            }

            // EnergyModule is optional - skip energy check if not registered
            if (ModuleSystem.TryGet<IEnergyModule>(out IEnergyModule energy))
            {
                if (!energy.Consume(energy.CostPerLevel))
                {
                    Log.Info("[LevelModule] Not enough energy to enter level");
                    return false;
                }
            }
            else
            {
                Log.Warning("[LevelModule] EnergyModule not found, skipping energy check");
            }

            _currentLevelId = levelId;
            _currentLevelProgress = 0;

            GameLogicEntry.Event?.Publish(new LevelEnterEvent(levelId));
            GameLogicEntry.Event?.Publish(new LevelStartEvent(levelId));
            return true;
        }

        public void CompleteLevel(int stars)
        {
            if (_currentLevelId <= 0)
            {
                Log.Warning("[LevelModule] No active level to complete");
                return;
            }

            int clampedStars = Math.Clamp(stars, 1, MaxStars);
            int oldStars = GetLevelStars(_currentLevelId);
            bool isNewRecord = clampedStars > oldStars;

            _levelStars[_currentLevelId] = Math.Max(oldStars, clampedStars);
            UnlockNextLevel(_currentLevelId + 1);

            GameLogicEntry.Event?.Publish(new LevelCompleteEvent(_currentLevelId, clampedStars, isNewRecord));

            _currentLevelId = 0;
            _currentLevelProgress = 0;
        }

        public void UnlockNextLevel(int levelId)
        {
            if (levelId < 1 || levelId > _maxLevel)
            {
                return;
            }

            if (levelId > _maxUnlockedLevelId)
            {
                _maxUnlockedLevelId = levelId;
                GameLogicEntry.Event?.Publish(new LevelUnlockedEvent(levelId));
            }
        }

        public int GetLevelStars(int levelId)
        {
            return _levelStars.TryGetValue(levelId, out int stars) ? Math.Clamp(stars, 0, MaxStars) : 0;
        }

        public void SetProgress(int progress)
        {
            _currentLevelProgress = Math.Max(0, progress);
        }

        public void AddProgress(int delta)
        {
            if (delta > 0)
            {
                _currentLevelProgress += delta;
            }
        }

        public IReadOnlyDictionary<int, int> GetAllLevelStars()
        {
            return _levelStars;
        }

        public int GetTotalStars()
        {
            int total = 0;
            foreach (int stars in _levelStars.Values)
            {
                total += stars;
            }
            return total;
        }
    }
}
