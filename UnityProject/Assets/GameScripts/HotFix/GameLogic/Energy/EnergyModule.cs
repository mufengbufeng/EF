using System;
using EF.Common;
using EF.Debugger;
using EF.Save;
using UnityEngine;

namespace GameLogic
{
    /// <summary>
    /// 体力模块实现，基于时间戳计算自动恢复，无定时器依赖。
    /// </summary>
    public sealed class EnergyModule : AEFManager, IEnergyModule
    {
        private const string SaveKey = "game_logic_energy_state";
        private const int DefaultMaxEnergy = 10;
        private const int DefaultRecoveryIntervalSeconds = 360; // 6 分钟

        private readonly ISaveManager _saveManager;

        private int _baseEnergy;          // 上次操作时的体力快照
        private int _maxEnergy;
        private long _baseTimestamp;      // 上次操作时的 Unix 秒时间戳

        public int CurrentEnergy => ComputeCurrentEnergy();

        public int MaxEnergy => _maxEnergy;

        public int RecoveryIntervalSeconds => DefaultRecoveryIntervalSeconds;

        public float TimeToNextRecovery
        {
            get
            {
                if (_baseEnergy >= _maxEnergy)
                {
                    return 0f;
                }

                long elapsed = DateTimeOffset.UtcNow.ToUnixTimeSeconds() - _baseTimestamp;
                int alreadyRecovered = (int)(elapsed / DefaultRecoveryIntervalSeconds);
                int canRecover = Mathf.Min(alreadyRecovered, _maxEnergy - _baseEnergy);

                if (_baseEnergy + canRecover >= _maxEnergy)
                {
                    return 0f;
                }

                float progressInCurrentInterval = elapsed % DefaultRecoveryIntervalSeconds;
                return DefaultRecoveryIntervalSeconds - progressInCurrentInterval;
            }
        }

        public bool IsRecovering => ComputeCurrentEnergy() < _maxEnergy;

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

            return ComputeCurrentEnergy() >= amount;
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

            // 先刷新快照到当前真实值，再扣除
            SyncBaseToNow();
            _baseEnergy -= amount;

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

            int current = ComputeCurrentEnergy();
            int newEnergy = Mathf.Clamp(current + amount, 0, _maxEnergy);
            if (newEnergy == current)
            {
                return;
            }

            _baseEnergy = newEnergy;
            _baseTimestamp = DateTimeOffset.UtcNow.ToUnixTimeSeconds();

            SaveState();
            RaiseEnergyChanged();
        }

        public override void Shutdown()
        {
            // 关闭时将当前真实体力写回快照再存盘
            SyncBaseToNow();
            SaveState();
            OnEnergyChanged = null;
        }

        /// <summary>
        /// 基于 _baseEnergy + 经过时间计算当前真实体力。
        /// </summary>
        private int ComputeCurrentEnergy()
        {
            if (_baseEnergy >= _maxEnergy)
            {
                return _maxEnergy;
            }

            long elapsed = DateTimeOffset.UtcNow.ToUnixTimeSeconds() - _baseTimestamp;
            if (elapsed <= 0)
            {
                return _baseEnergy;
            }

            int recovered = (int)(elapsed / DefaultRecoveryIntervalSeconds);
            return Mathf.Min(_baseEnergy + recovered, _maxEnergy);
        }

        /// <summary>
        /// 将快照刷新为当前真实体力，重置时间戳。
        /// </summary>
        private void SyncBaseToNow()
        {
            _baseEnergy = ComputeCurrentEnergy();
            _baseTimestamp = DateTimeOffset.UtcNow.ToUnixTimeSeconds();
        }

        private void LoadOrCreateState()
        {
            _maxEnergy = DefaultMaxEnergy;
            _baseEnergy = DefaultMaxEnergy;

            long now = DateTimeOffset.UtcNow.ToUnixTimeSeconds();
            _baseTimestamp = now;

            if (_saveManager.HasKey(SaveKey))
            {
                EnergySaveData saveData = _saveManager.Load<EnergySaveData>(SaveKey, null);
                if (saveData != null)
                {
                    _maxEnergy = saveData.maxEnergy > 0 ? saveData.maxEnergy : DefaultMaxEnergy;
                    _baseEnergy = Mathf.Clamp(saveData.baseEnergy, 0, _maxEnergy);

                    // 旧存档兼容：缺少时间戳时使用当前时间，不做离线补偿
                    _baseTimestamp = saveData.baseTimestamp > 0
                        ? saveData.baseTimestamp
                        : now;
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

            // 启动时计算离线补偿并打印日志
            int offlineRecovered = ComputeCurrentEnergy() - _baseEnergy;
            if (offlineRecovered > 0)
            {
                Log.Info($"[EnergyModule] 离线补偿恢复 {offlineRecovered} 点体力");
            }

            RaiseEnergyChanged();
            Log.Info($"[EnergyModule] 初始化完成，体力：{ComputeCurrentEnergy()}/{_maxEnergy}");
        }

        private void SaveState()
        {
            var saveData = new EnergySaveData
            {
                baseEnergy = _baseEnergy,
                maxEnergy = _maxEnergy,
                baseTimestamp = _baseTimestamp
            };

            bool success = _saveManager.Save(SaveKey, saveData);
            if (!success)
            {
                Log.Warning("[EnergyModule] 体力存档保存失败。");
            }
        }

        private void RaiseEnergyChanged()
        {
            OnEnergyChanged?.Invoke(ComputeCurrentEnergy(), _maxEnergy);
        }

        [Serializable]
        private class EnergySaveData
        {
            public int baseEnergy;
            public int maxEnergy;
            public long baseTimestamp;
        }
    }
}
