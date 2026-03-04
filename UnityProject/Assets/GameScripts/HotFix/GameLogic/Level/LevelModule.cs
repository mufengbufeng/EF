using System;
using GameConfig.level;
using EF.Common;
using EF.Debugger;
using UnityEngine;

namespace GameLogic
{
    /// <summary>
    /// 关卡模块实现。
    /// </summary>
    public sealed class LevelModule : AEFManager, ILevelModule
    {
        private const string CurrentLevelIdKey = "CurrentLevelId";
        private const int DefaultLevelId = 1;

        private int _currentLevelId;
        private int _currentKillCount;

        public LevelModule()
        {
            _currentLevelId = LoadCurrentLevelId();
            _currentKillCount = 0;
            Log.Info($"[LevelModule] 初始化完成，当前关卡：{_currentLevelId}");
        }

        public int GetCurrentLevelId()
        {
            return _currentLevelId;
        }

        public Level GetLevelConfig(int levelId)
        {
            var tables = GameLogicEntry.Config?.Tables;
            if (tables?.TbLevel == null)
            {
                Log.Error("[LevelModule] 配置表 TbLevel 不可用");
                return null;
            }

            if (tables.TbLevel.DataMap.TryGetValue(levelId, out Level levelConfig))
            {
                return levelConfig;
            }

            int fallbackId = GetFallbackLevelId();
            if (tables.TbLevel.DataMap.TryGetValue(fallbackId, out Level fallbackConfig))
            {
                Log.Warning($"[LevelModule] 关卡 {levelId} 不存在，回退到关卡 {fallbackId}");
                return fallbackConfig;
            }

            Log.Error("[LevelModule] TbLevel 为空，无法提供关卡配置");
            return null;
        }

        public void RecordKill()
        {
            _currentKillCount++;
        }

        public bool CheckLevelComplete()
        {
            Level currentLevel = GetLevelConfig(_currentLevelId);
            if (currentLevel == null)
            {
                return false;
            }

            return _currentKillCount >= currentLevel.KillTarget;
        }

        public void AdvanceToNextLevel()
        {
            int nextLevelId = GetNextLevelId(_currentLevelId);
            if (nextLevelId != _currentLevelId)
            {
                Log.Info($"[LevelModule] 关卡推进：{_currentLevelId} -> {nextLevelId}");
            }
            else
            {
                Log.Info($"[LevelModule] 当前已是最后一关，保持关卡：{_currentLevelId}");
            }

            _currentLevelId = nextLevelId;
            SaveCurrentLevelId(_currentLevelId);
            _currentKillCount = 0;
        }

        public void ResetCurrentLevel()
        {
            _currentKillCount = 0;
        }

        public int GetCurrentKillCount()
        {
            return _currentKillCount;
        }

        public override void Shutdown()
        {
            SaveCurrentLevelId(_currentLevelId);
        }

        private int LoadCurrentLevelId()
        {
            int savedLevelId = PlayerPrefs.GetInt(CurrentLevelIdKey, DefaultLevelId);
            int normalizedLevelId = NormalizeLevelId(savedLevelId);
            if (normalizedLevelId != savedLevelId)
            {
                SaveCurrentLevelId(normalizedLevelId);
            }

            return normalizedLevelId;
        }

        private void SaveCurrentLevelId(int levelId)
        {
            PlayerPrefs.SetInt(CurrentLevelIdKey, levelId);
            PlayerPrefs.Save();
        }

        private int NormalizeLevelId(int levelId)
        {
            Level levelConfig = GetLevelConfig(levelId);
            if (levelConfig != null)
            {
                return levelConfig.Id;
            }

            return GetFallbackLevelId();
        }

        private int GetFallbackLevelId()
        {
            var tbLevel = GameLogicEntry.Config?.Tables?.TbLevel;
            if (tbLevel == null || tbLevel.DataList == null || tbLevel.DataList.Count == 0)
            {
                return DefaultLevelId;
            }

            int minLevelId = int.MaxValue;
            foreach (Level level in tbLevel.DataList)
            {
                if (level.Id < minLevelId)
                {
                    minLevelId = level.Id;
                }
            }

            return minLevelId == int.MaxValue ? DefaultLevelId : minLevelId;
        }

        private int GetNextLevelId(int currentLevelId)
        {
            var tbLevel = GameLogicEntry.Config?.Tables?.TbLevel;
            if (tbLevel == null || tbLevel.DataList == null || tbLevel.DataList.Count == 0)
            {
                return currentLevelId;
            }

            int candidate = int.MaxValue;
            int maxLevelId = int.MinValue;

            foreach (Level level in tbLevel.DataList)
            {
                if (level.Id > currentLevelId && level.Id < candidate)
                {
                    candidate = level.Id;
                }

                if (level.Id > maxLevelId)
                {
                    maxLevelId = level.Id;
                }
            }

            if (candidate != int.MaxValue)
            {
                return candidate;
            }

            return maxLevelId == int.MinValue ? currentLevelId : maxLevelId;
        }
    }
}
