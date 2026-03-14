using System;
using EF.Common;
using EF.Debugger;
using EF.Save;

namespace GameLogic
{
    public sealed class LevelModule : AEFManager, ILevelModule
    {
        private const string SaveKey = "level_progress";
        private const int DefaultRequiredKills = 10;
        
        private readonly ISaveManager _saveManager;
        private int _currentLevelId = 1;
        private int _killCount = 0;
        private int _requiredKills = DefaultRequiredKills;
        
        public int CurrentLevelId => _currentLevelId;
        public int KillCount => _killCount;
        public int RequiredKills => _requiredKills;
        
        public event Action<int, int, int> OnProgressChanged;
        public event Action OnLevelComplete;
        
        public LevelModule(ISaveManager saveManager = null)
        {
            _saveManager = saveManager;
            LoadProgress();
            Log.Info($"[LevelModule] Initialized. Level: {_currentLevelId}");
        }
        
        public void RecordKill()
        {
            _killCount++;
            Log.Info($"[LevelModule] Kill recorded: {_killCount}/{_requiredKills}");
            
            // 触发进度变化事件
            OnProgressChanged?.Invoke(_currentLevelId, _killCount, _requiredKills);
            
            // 检测通关
            if (CheckLevelComplete())
            {
                Log.Info($"[LevelModule] Level {_currentLevelId} complete!");
                OnLevelComplete?.Invoke();
            }
        }
        
        public bool CheckLevelComplete()
        {
            return _killCount >= _requiredKills;
        }
        
        public void AdvanceToNextLevel()
        {
            _currentLevelId++;
            _killCount = 0;
            SaveProgress();
            Log.Info($"[LevelModule] Advanced to level {_currentLevelId}");
        }
        
        public void ResetProgress()
        {
            _killCount = 0;
        }
        
        public void LoadProgress()
        {
            if (_saveManager == null) return;
            var data = _saveManager.Load<LevelSaveData>(SaveKey);
            if (data != null)
            {
                _currentLevelId = data.currentLevelId;
            }
        }
        
        public void SaveProgress()
        {
            if (_saveManager == null) return;
            _saveManager.Save(SaveKey, new LevelSaveData { currentLevelId = _currentLevelId });
        }
        
        public override void Shutdown()
        {
            SaveProgress();
            OnProgressChanged = null;
            OnLevelComplete = null;
            Log.Info("[LevelModule] Shutdown");
        }
        
        [Serializable]
        private class LevelSaveData
        {
            public int currentLevelId;
        }
    }
}
