using UnityEngine;
using EF.Entity;

namespace EF.Feature.Examples
{
    /// <summary>
    /// 位置特性示例，存储实体的位置信息。
    /// </summary>
    public class PositionFeature : FeatureBase
    {
        /// <summary>
        /// 获取或设置位置。
        /// </summary>
        public Vector3 Value { get; set; }

        /// <summary>
        /// 初始化位置特性。
        /// </summary>
        public override void OnInit()
        {
            base.OnInit();
            Value = Vector3.zero;
            Debug.Log($"[PositionFeature] Initialized for entity '{Entity.EntityAssetName}' (Id: {Entity.Id})");
        }

        /// <summary>
        /// 设置位置。
        /// </summary>
        public void SetPosition(float x, float y, float z)
        {
            Value = new Vector3(x, y, z);
        }

        /// <summary>
        /// 更新位置（示例：自动移动）。
        /// </summary>
        public override void OnUpdate(float elapseSeconds, float realElapseSeconds)
        {
            base.OnUpdate(elapseSeconds, realElapseSeconds);
            // 示例：每帧向 X 轴正方向移动
            // Value += Vector3.right * elapseSeconds;
        }
    }

    /// <summary>
    /// 渲染特性示例，依赖位置特性。
    /// </summary>
    [RequireFeature(typeof(PositionFeature))]
    public class RenderFeature : FeatureBase
    {
        private PositionFeature _positionFeature;

        /// <summary>
        /// 获取或设置渲染颜色。
        /// </summary>
        public Color Color { get; set; }

        public override void OnInit()
        {
            base.OnInit();
            Color = Color.white;
            _positionFeature = Entity.Features.GetFeature<PositionFeature>();
            Debug.Log($"[RenderFeature] Initialized for entity '{Entity.EntityAssetName}' (Id: {Entity.Id})");
        }

        public override void OnUpdate(float elapseSeconds, float realElapseSeconds)
        {
            base.OnUpdate(elapseSeconds, realElapseSeconds);
            // 示例：使用位置特性的信息进行渲染
            if (_positionFeature != null)
            {
                Vector3 position = _positionFeature.Value;
                // 这里可以进行实际的渲染操作
            }
        }
    }

    /// <summary>
    /// 血量特性示例。
    /// </summary>
    public class HealthFeature : FeatureBase
    {
        private float _maxHealth = 100f;
        private float _currentHealth = 100f;

        /// <summary>
        /// 获取或设置最大生命值。
        /// </summary>
        public float MaxHealth
        {
            get => _maxHealth;
            set => _maxHealth = Mathf.Max(0, value);
        }

        /// <summary>
        /// 获取当前生命值。
        /// </summary>
        public float CurrentHealth => _currentHealth;

        /// <summary>
        /// 获取生命值百分比。
        /// </summary>
        public float HealthPercent => _maxHealth > 0 ? _currentHealth / _maxHealth : 0f;

        /// <summary>
        /// 获取是否死亡。
        /// </summary>
        public bool IsDead => _currentHealth <= 0f;

        public override void OnInit()
        {
            base.OnInit();
            Debug.Log($"[HealthFeature] Initialized with {_currentHealth}/{_maxHealth} HP");
        }

        /// <summary>
        /// 造成伤害。
        /// </summary>
        public void TakeDamage(float damage)
        {
            if (IsDead) return;

            _currentHealth = Mathf.Max(0, _currentHealth - damage);
            Debug.Log($"[HealthFeature] Took {damage} damage, remaining: {_currentHealth}/{_maxHealth}");

            if (IsDead)
            {
                OnDeath();
            }
        }

        /// <summary>
        /// 恢复生命值。
        /// </summary>
        public void Heal(float amount)
        {
            if (IsDead) return;

            _currentHealth = Mathf.Min(_maxHealth, _currentHealth + amount);
            Debug.Log($"[HealthFeature] Healed {amount}, current: {_currentHealth}/{_maxHealth}");
        }

        /// <summary>
        /// 死亡时调用。
        /// </summary>
        private void OnDeath()
        {
            Debug.Log($"[HealthFeature] Entity '{Entity.EntityAssetName}' (Id: {Entity.Id}) has died!");
            // 这里可以触发死亡事件
        }
    }

    /// <summary>
    /// 攻击特性示例，允许多实例（可以添加多种攻击方式）。
    /// </summary>
    [AllowMultiple]
    public class AttackFeature : FeatureBase
    {
        /// <summary>
        /// 获取或设置攻击类型名称。
        /// </summary>
        public string AttackType { get; set; }

        /// <summary>
        /// 获取或设置攻击伤害。
        /// </summary>
        public float Damage { get; set; }

        /// <summary>
        /// 获取或设置攻击冷却时间（秒）。
        /// </summary>
        public float Cooldown { get; set; }

        private float _cooldownTimer;

        public override void OnInit()
        {
            base.OnInit();
            AttackType = "Default";
            Damage = 10f;
            Cooldown = 1f;
            Debug.Log($"[AttackFeature] Initialized with type '{AttackType}', damage: {Damage}");
        }

        public override void OnUpdate(float elapseSeconds, float realElapseSeconds)
        {
            base.OnUpdate(elapseSeconds, realElapseSeconds);

            if (_cooldownTimer > 0)
            {
                _cooldownTimer -= elapseSeconds;
            }
        }

        /// <summary>
        /// 执行攻击。
        /// </summary>
        public bool Attack(HealthFeature target)
        {
            if (_cooldownTimer > 0)
            {
                Debug.Log($"[AttackFeature] Attack '{AttackType}' is on cooldown!");
                return false;
            }

            if (target != null)
            {
                target.TakeDamage(Damage);
                _cooldownTimer = Cooldown;
                Debug.Log($"[AttackFeature] Attacked with '{AttackType}' for {Damage} damage!");
                return true;
            }

            return false;
        }
    }
}
