using System;
using EF.Common;
using EF.Debugger;
using EF.Save;
using UnityEngine;

namespace GameLogic
{
    /// <summary>
    /// 体力模块实现，提供体力消耗、恢复与基础持久化。
    /// </summary>
    public sealed class EnergyModule : AEFManager, IEnergyModule
    {
        private const string SaveKey = "game_logic_energy_state";
        private const int DefaultMaxEnergy = 10;

        private readonly ISaveManager _saveManager;

        private int _currentEnergy;
        private int _maxEnergy;

        public int CurrentEnergy => _currentEnergy;

        public int MaxEnergy => _maxEnergy;

        public event Action<int, int> OnEnergyChanged;

        public EnergyModule(ISaveManager saveManager)
        {
            _saveManager = saveManager ?? throw new ArgumentNullException(nameof(saveManager));
            LoadOrCreateState();
        }

        public bool CanConsume(int amount)
        {
            if (amount <= 0)
            {
                return true;
            }

            return _currentEnergy >= amount;
        }

        public bool TryConsume(int amount)
        {
            if (amount <= 0)
            {
                return true;
            }

            if (!CanConsume(amount))
            {
                return false;
            }

            _currentEnergy -= amount;
            SaveState();
            RaiseEnergyChanged();
            return true;
        }

        public void Recover(int amount)
        {
            if (amount <= 0)
            {
                return;
            }

            int newEnergy = Mathf.Clamp(_currentEnergy + amount, 0, _maxEnergy);
            if (newEnergy == _currentEnergy)
            {
                return;
            }

            _currentEnergy = newEnergy;
            SaveState();
            RaiseEnergyChanged();
        }

        public override void Shutdown()
        {
            SaveState();
            OnEnergyChanged = null;
        }

        private void LoadOrCreateState()
        {
            _maxEnergy = DefaultMaxEnergy;
            _currentEnergy = DefaultMaxEnergy;

            if (_saveManager.HasKey(SaveKey))
            {
                EnergySaveData saveData = _saveManager.Load<EnergySaveData>(SaveKey, null);
                if (saveData != null)
                {
                    _maxEnergy = saveData.maxEnergy > 0 ? saveData.maxEnergy : DefaultMaxEnergy;
                    _currentEnergy = Mathf.Clamp(saveData.currentEnergy, 0, _maxEnergy);
                }
                else
                {
                    Log.Warning("[EnergyModule] 体力存档读取为空，使用默认值。");
                }
            }
            else
            {
                SaveState();
            }

            RaiseEnergyChanged();
            Log.Info($"[EnergyModule] 初始化完成，体力：{_currentEnergy}/{_maxEnergy}");
        }

        private void SaveState()
        {
            var saveData = new EnergySaveData
            {
                currentEnergy = _currentEnergy,
                maxEnergy = _maxEnergy
            };

            bool success = _saveManager.Save(SaveKey, saveData);
            if (!success)
            {
                Log.Warning("[EnergyModule] 体力存档保存失败。");
            }
        }

        private void RaiseEnergyChanged()
        {
            OnEnergyChanged?.Invoke(_currentEnergy, _maxEnergy);
        }

        [Serializable]
        private class EnergySaveData
        {
            public int currentEnergy;
            public int maxEnergy;
        }
    }
}
