using System;
using EF.Common;
using EF.Debugger;
using EF.Feature;

namespace GameLogic
{
    /// <summary>
    /// 生命值特性，管理实体的生命值与死亡状态。
    /// </summary>
    public class HealthFeature : FeatureBase<HealthFeatureData>
    {
        private float _currentHealth;
        private float _maxHealth;
        private bool _isDead;

        /// <summary>
        /// 当前生命值。
        /// </summary>
        public float CurrentHealth => _currentHealth;

        /// <summary>
        /// 最大生命值。
        /// </summary>
        public float MaxHealth => _maxHealth;

        /// <summary>
        /// 是否已死亡。
        /// </summary>
        public bool IsDead => _isDead;

        /// <summary>
        /// 死亡时触发的回调。
        /// </summary>
        public event Action OnDeath;

        protected override void OnSetup(HealthFeatureData data)
        {
            _maxHealth = data.MaxHealth;
            _currentHealth = _maxHealth;
            _isDead = false;
            OnDeath = null;
        }

        /// <summary>
        /// 清理死亡回调。
        /// </summary>
        public override void OnDestroy()
        {
            base.OnDestroy();
            OnDeath = null;
        }

        /// <summary>
        /// 接受伤害，生命值降为 0 时触发死亡并回调。
        /// </summary>
        /// <param name="damage">伤害值。</param>
        public void TakeDamage(float damage)
        {
            if (_isDead)
            {
                return;
            }

            _currentHealth -= damage;
            Log.Info($"[HealthFeature] 实体 {Entity.Id} 受到伤害 {damage}，当前生命值: {_currentHealth}/{_maxHealth}");

            if (_currentHealth <= 0)
            {
                _isDead = true;
                _currentHealth = 0;
                Log.Info($"[HealthFeature] 实体 {Entity.Id} 已死亡");
                OnDeath?.Invoke();
            }
        }
    }
}
