using System;
using EF.Common;
using EF.Debugger;
using EF.Event;

namespace GameLogic
{
    /// <summary>
    /// 体力模块实现。
    /// 支持体力消耗、自动恢复与事件通知。
    /// </summary>
    public sealed class EnergyModule : AEFManager, IEnergyModule
    {
        private const int DefaultMaxEnergy = 100;
        private const int DefaultRecoverRateSeconds = 300;
        private const int DefaultCostPerLevel = 10;

        private int _maxEnergy = DefaultMaxEnergy;
        private int _currentEnergy = DefaultMaxEnergy;
        private int _recoverRateSeconds = DefaultRecoverRateSeconds;
        private int _costPerLevel = DefaultCostPerLevel;
        private float _accumulatedTime;
        private bool _isRecovering = true;

        public int CurrentEnergy => _currentEnergy;
        public int MaxEnergy => _maxEnergy;
        public int RecoverRateSeconds => _recoverRateSeconds;
        public int CostPerLevel => _costPerLevel;

        public void Configure(int maxEnergy, int recoverRateSeconds, int costPerLevel)
        {
            _maxEnergy = maxEnergy > 0 ? maxEnergy : DefaultMaxEnergy;
            _recoverRateSeconds = recoverRateSeconds > 0 ? recoverRateSeconds : DefaultRecoverRateSeconds;
            _costPerLevel = costPerLevel > 0 ? costPerLevel : DefaultCostPerLevel;

            _currentEnergy = Math.Clamp(_currentEnergy, 0, _maxEnergy);

            Log.Info($"[EnergyModule] Configured: max={_maxEnergy}, recover={_recoverRateSeconds}s, costPerLevel={_costPerLevel}");
        }

        public void Initialize()
        {
            _isRecovering = true;
            _accumulatedTime = 0f;
            Log.Info("[EnergyModule] Initialized");
        }

        public override void Update(float elapseSeconds, float realElapseSeconds)
        {
            if (!_isRecovering || _currentEnergy >= _maxEnergy || _recoverRateSeconds <= 0)
            {
                return;
            }

            _accumulatedTime += Math.Max(0f, elapseSeconds);
            while (_accumulatedTime >= _recoverRateSeconds)
            {
                _accumulatedTime -= _recoverRateSeconds;
                RecoverEnergy(1);
            }
        }

        public void Cleanup()
        {
            _isRecovering = false;
            _accumulatedTime = 0f;
            Log.Info("[EnergyModule] Cleanup");
        }

        public override void Shutdown()
        {
            Cleanup();
            Log.Info("[EnergyModule] Shutdown");
        }

        public bool CanConsume(int cost)
        {
            return cost > 0 && _currentEnergy >= cost;
        }

        public bool Consume(int cost)
        {
            if (cost <= 0)
            {
                Log.Warning($"[EnergyModule] Invalid consume cost: {cost}");
                return false;
            }

            if (_currentEnergy < cost)
            {
                GameLogicEntry.Event?.Publish(new EnergyNotEnoughEvent(_currentEnergy, cost));
                return false;
            }

            _currentEnergy -= cost;
            GameLogicEntry.Event?.Publish(new EnergyChangedEvent(_currentEnergy, _maxEnergy, -cost));
            return true;
        }

        public void SetEnergy(int energy)
        {
            int old = _currentEnergy;
            _currentEnergy = Math.Clamp(energy, 0, _maxEnergy);
            if (old != _currentEnergy)
            {
                GameLogicEntry.Event?.Publish(new EnergyChangedEvent(_currentEnergy, _maxEnergy, _currentEnergy - old));
            }
        }

        public void RestoreFullEnergy()
        {
            SetEnergy(_maxEnergy);
        }

        public void PauseRecover()
        {
            _isRecovering = false;
        }

        public void ResumeRecover()
        {
            _isRecovering = true;
        }

        private void RecoverEnergy(int amount)
        {
            if (amount <= 0 || _currentEnergy >= _maxEnergy)
            {
                return;
            }

            int old = _currentEnergy;
            _currentEnergy = Math.Min(_currentEnergy + amount, _maxEnergy);
            int delta = _currentEnergy - old;
            if (delta > 0)
            {
                GameLogicEntry.Event?.Publish(new EnergyChangedEvent(_currentEnergy, _maxEnergy, delta));
            }
        }
    }
}
