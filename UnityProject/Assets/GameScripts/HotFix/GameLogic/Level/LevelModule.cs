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
            Log.Info("[LevelModule] Shutdown");
        }
        
        [Serializable]
        private class LevelSaveData
        {
            public int currentLevelId;
        }
    }
}
