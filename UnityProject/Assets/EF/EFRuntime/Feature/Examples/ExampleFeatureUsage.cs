using UnityEngine;
using EF.Entity;

namespace EF.Feature.Examples
{
    /// <summary>
    /// 特性系统使用示例。
    /// 展示如何使用特性系统进行实体-特性开发。
    /// </summary>
    public class ExampleFeatureUsage
    {
        /// <summary>
        /// 示例：创建一个带有特性的实体。
        /// </summary>
        public void CreateEntityWithFeatures(IEntity entity)
        {
            // 添加位置特性
            PositionFeature position = entity.Features.AddFeature<PositionFeature>();
            position.SetPosition(10, 0, 5);

            // 添加血量特性
            HealthFeature health = entity.Features.AddFeature<HealthFeature>();
            health.MaxHealth = 200f;
            health.TakeDamage(50f); // 当前生命值: 150/200

            // 添加渲染特性（依赖位置特性，必须先有位置特性）
            RenderFeature render = entity.Features.AddFeature<RenderFeature>();
            render.Color = Color.red;

            // 添加多个攻击特性（允许多实例）
            AttackFeature meleeAttack = entity.Features.AddFeature<AttackFeature>();
            meleeAttack.AttackType = "Melee";
            meleeAttack.Damage = 25f;
            meleeAttack.Cooldown = 0.5f;

            AttackFeature rangedAttack = entity.Features.AddFeature<AttackFeature>();
            rangedAttack.AttackType = "Ranged";
            rangedAttack.Damage = 15f;
            rangedAttack.Cooldown = 1.0f;

            Debug.Log($"Entity '{entity.EntityAssetName}' has {entity.Features.FeatureCount} features.");
        }

        /// <summary>
        /// 示例：查询和操作特性。
        /// </summary>
        public void QueryAndManipulateFeatures(IEntity entity)
        {
            // 检查是否有特性
            if (entity.Features.HasFeature<PositionFeature>())
            {
                PositionFeature position = entity.Features.GetFeature<PositionFeature>();
                Debug.Log($"Position: {position.Value}");

                // 修改位置
                position.SetPosition(20, 10, 0);
            }

            // 获取所有攻击特性
            AttackFeature[] attacks = entity.Features.GetFeatures<AttackFeature>();
            Debug.Log($"Entity has {attacks.Length} attack types:");
            foreach (AttackFeature attack in attacks)
            {
                Debug.Log($"  - {attack.AttackType}: {attack.Damage} damage, {attack.Cooldown}s cooldown");
            }

            // 获取所有特性
            var allFeatures = entity.Features.GetAllFeatures();
            Debug.Log($"Total features: {allFeatures.Count}");
        }

        /// <summary>
        /// 示例：移除特性。
        /// </summary>
        public void RemoveFeatures(IEntity entity)
        {
            // 移除指定类型的特性
            if (entity.Features.RemoveFeature<RenderFeature>())
            {
                Debug.Log("RenderFeature removed successfully.");
            }

            // 通过实例移除特性
            PositionFeature position = entity.Features.GetFeature<PositionFeature>();
            if (position != null)
            {
                entity.Features.RemoveFeature(position);
                Debug.Log("PositionFeature removed successfully.");
            }
        }

        /// <summary>
        /// 示例：启用/禁用特性。
        /// </summary>
        public void EnableDisableFeatures(IEntity entity)
        {
            // 禁用特性（禁用后不会调用 OnUpdate）
            entity.Features.SetFeatureEnabled<AttackFeature>(false);
            Debug.Log("AttackFeature disabled.");

            // 重新启用特性
            entity.Features.SetFeatureEnabled<AttackFeature>(true);
            Debug.Log("AttackFeature enabled.");
        }

        /// <summary>
        /// 示例：特性间交互。
        /// </summary>
        public void FeatureInteraction(IEntity attacker, IEntity target)
        {
            // 获取攻击者的攻击特性
            AttackFeature attack = attacker.Features.GetFeature<AttackFeature>();
            // 获取目标的血量特性
            HealthFeature health = target.Features.GetFeature<HealthFeature>();

            // 执行攻击
            if (attack != null && health != null)
            {
                bool success = attack.Attack(health);
                if (success)
                {
                    Debug.Log($"Attack successful! Target health: {health.HealthPercent * 100}%");
                }
            }
        }

        /// <summary>
        /// 示例：创建自定义特性。
        /// </summary>
        public void CustomFeatureExample()
        {
            /*
            // 自定义特性只需继承 FeatureBase
            public class MyCustomFeature : FeatureBase
            {
                private float _timer;

                public override void OnInit()
                {
                    base.OnInit();
                    _timer = 0f;
                    Debug.Log("MyCustomFeature initialized!");
                }

                public override void OnUpdate(float elapseSeconds, float realElapseSeconds)
                {
                    base.OnUpdate(elapseSeconds, realElapseSeconds);
                    _timer += elapseSeconds;
                    if (_timer >= 1f)
                    {
                        Debug.Log($"One second passed! Entity: {Entity.EntityAssetName}");
                        _timer = 0f;
                    }
                }
            }

            // 使用自定义特性
            IEntity entity = ...;
            entity.Features.AddFeature<MyCustomFeature>();
            */
        }
    }
}
