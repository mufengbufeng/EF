using System;
using EF.Common;
using EF.Debugger;
using EF.Entity;
using UnityEngine;

namespace GameLogic
{
    /// <summary>
    /// 玩家飞机实体。
    /// 作为编排者管理 Feature 生命周期，对外通过 IHealth 回调转发暴露接口。
    /// </summary>
    public sealed class PlayerAvatarEntity : EntityBase, IHealth
    {
        private const string MoveAnimationState = "Move";
        private const string BoomAnimationState = "Boom";

        private GameObject _handleField;
        private IBulletModule _bulletModule;
        private IEntityManager _entityManager;
        private Animator _animator;
        private Collider2D _collider2D;

        private int _lifecycleToken;
        private Action _onDead;
        private bool _deathNotified;

        // IHealth 回调字段 —— Feature 注册
        private Action<float> _takeDamageCallback;
        private Func<float> _currentHealthCallback;
        private Func<float> _maxHealthCallback;
        private Func<bool> _isDeadCallback;

        /// <summary>
        /// 当前生命值。
        /// </summary>
        public float CurrentHealth => _currentHealthCallback?.Invoke() ?? 0f;

        /// <summary>
        /// 最大生命值。
        /// </summary>
        public float MaxHealth => _maxHealthCallback?.Invoke() ?? 0f;

        /// <summary>
        /// 是否已死亡。
        /// </summary>
        public bool IsDead => _isDeadCallback?.Invoke() ?? false;

        /// <summary>
        /// 实体关联的 GameObject。
        /// </summary>
        public override GameObject Handle
        {
            get => _handleField;
            set => _handleField = value;
        }

        /// <summary>
        /// 设置自定义攻击执行器。
        /// </summary>
        /// <param name="attackExecutor">自定义攻击逻辑。</param>
        public void SetCustomAttackExecutor(Func<Vector3, bool> attackExecutor)
        {
            var attackFeature = Features.GetFeature<AttackFeature>();
            if (attackFeature != null)
            {
                attackFeature.SetCustomAttackExecutor(attackExecutor);
            }
        }

        /// <summary>
        /// 播放爆炸动画。
        /// </summary>
        public void PlayBoomAnimation()
        {
            if (_animator != null)
            {
                _animator.Play(BoomAnimationState);
            }
        }

        /// <summary>
        /// 接受伤害。
        /// </summary>
        /// <param name="damage">伤害值。</param>
        public void TakeDamage(float damage)
        {
            _takeDamageCallback?.Invoke(damage);
        }

        /// <summary>
        /// 实体初始化。
        /// </summary>
        public override void OnInit(int entityId, string entityAssetName, IEntityGroup entityGroup, bool isNewInstance, object userData)
        {
            base.OnInit(entityId, entityAssetName, entityGroup, isNewInstance, userData);
            ResetRuntimeState();
        }

        /// <summary>
        /// 实体显示。
        /// </summary>
        public override void OnShow(object userData)
        {
            base.OnShow(userData);

            if (Handle == null)
            {
                Log.Warning($"[PlayerAvatarEntity] 实体 {Id} Handle 为空，无法显示");
                return;
            }

            if (!ModuleSystem.TryGet<IBulletModule>(out _bulletModule))
            {
                _bulletModule = null;
            }

            if (!ModuleSystem.TryGet<IEntityManager>(out _entityManager))
            {
                _entityManager = null;
            }

            Handle.SetActive(true);

            _animator = Handle.GetComponent<Animator>();
            _collider2D = Handle.GetComponent<Collider2D>();

            if (_collider2D == null)
            {
                _collider2D = Handle.AddComponent<BoxCollider2D>();
                Log.Warning("[PlayerAvatarEntity] Avatar 缺少 Collider2D，已自动补充 BoxCollider2D");
            }

            _collider2D.enabled = true;

            Vector3 spawnPosition;
            float fixedZ;
            float attackInterval;
            float bulletSpeed;
            float dragBoundaryPadding;

            if (userData is PlayerAvatarBehaviorData behaviorData)
            {
                spawnPosition = behaviorData.SpawnPosition;
                attackInterval = behaviorData.AttackInterval;
                bulletSpeed = behaviorData.BulletSpeed;
                dragBoundaryPadding = behaviorData.DragBoundaryPadding;
                _onDead = behaviorData.OnDead;
            }
            else
            {
                spawnPosition = Handle.transform.position;
                attackInterval = 0.2f;
                bulletSpeed = 8f;
                dragBoundaryPadding = 0.25f;
                _onDead = null;
                Log.Warning($"[PlayerAvatarEntity] 实体 {Id} 未接收到行为数据，使用默认参数");
            }

            Handle.transform.position = spawnPosition;
            fixedZ = spawnPosition.z;

            // 添加 Feature 并注册回调
            var healthFeature = Features.AddFeature<HealthFeature>(new HealthFeatureData { MaxHealth = 100f });
            healthFeature.OnDeath += HandleHealthDeath;
            _takeDamageCallback = healthFeature.TakeDamage;
            _currentHealthCallback = () => healthFeature.CurrentHealth;
            _maxHealthCallback = () => healthFeature.MaxHealth;
            _isDeadCallback = () => healthFeature.IsDead;

            Features.AddFeature<PositionClampFeature>(new PositionClampData
            {
                BoundaryPadding = dragBoundaryPadding,
                FixedZ = fixedZ
            });

            Features.AddFeature<DragInputFeature>(new DragInputData
            {
                FixedZ = fixedZ
            });

            Features.AddFeature<AttackFeature>(new AttackData
            {
                AttackInterval = attackInterval,
                BulletSpeed = bulletSpeed,
                SourceEntityId = Id
            });

            _deathNotified = false;
            PlayMoveAnimation();
        }

        /// <summary>
        /// 每帧更新。调用 base.OnUpdate 分发到 Feature，然后检查状态编排 Feature 启停。
        /// </summary>
        public override void OnUpdate(float elapseSeconds, float realElapseSeconds)
        {
            base.OnUpdate(elapseSeconds, realElapseSeconds);

            if (Handle == null)
            {
                return;
            }

            // 编排：死亡时禁用其他 Feature
            if (IsDead)
            {
                Features.SetFeatureEnabled<DragInputFeature>(false);
                Features.SetFeatureEnabled<AttackFeature>(false);
            }
        }

        /// <summary>
        /// 实体隐藏。
        /// </summary>
        public override void OnHide(bool isShutdown, object userData)
        {
            base.OnHide(isShutdown, userData);

            if (Handle != null)
            {
                Handle.SetActive(false);
            }

            ResetRuntimeState();
        }

        /// <summary>
        /// 实体回收。
        /// </summary>
        public override void OnRecycle()
        {
            base.OnRecycle();
            ResetRuntimeState();
        }

        /// <summary>
        /// HealthFeature 死亡回调，执行碰撞器禁用、子弹清理和爆炸动画。
        /// </summary>
        private void HandleHealthDeath()
        {
            if (_collider2D != null)
            {
                _collider2D.enabled = false;
            }

            ClearOwnedBullets();
            PlayBoomAnimation();
            DelayedHide(1.0f, _lifecycleToken, Id);
        }

        /// <summary>
        /// 延迟隐藏实体，等待爆炸动画播放完毕。
        /// </summary>
        /// <param name="delay">延迟时间（秒）。</param>
        /// <param name="expectedToken">期望的生命周期令牌，用于取消过期操作。</param>
        /// <param name="expectedEntityId">期望的实体 ID。</param>
        private async void DelayedHide(float delay, int expectedToken, int expectedEntityId)
        {
            await Cysharp.Threading.Tasks.UniTask.Delay(System.TimeSpan.FromSeconds(delay));

            if (expectedToken != _lifecycleToken || !IsDead || Id != expectedEntityId)
            {
                return;
            }

            NotifyDeathOnce();

            if (Handle != null && _entityManager != null)
            {
                _entityManager.HideEntity(expectedEntityId);
                Log.Info($"[PlayerAvatarEntity] 实体 {expectedEntityId} 已隐藏");
            }
        }

        /// <summary>
        /// 清理该实体发射的所有子弹。
        /// </summary>
        private void ClearOwnedBullets()
        {
            if (_bulletModule == null && !ModuleSystem.TryGet<IBulletModule>(out _bulletModule))
            {
                return;
            }

            _bulletModule.ClearBulletsBySource(Id);
        }

        /// <summary>
        /// 通知外部死亡事件，保证只触发一次。
        /// </summary>
        private void NotifyDeathOnce()
        {
            if (_deathNotified)
            {
                return;
            }

            _deathNotified = true;
            if (_onDead == null)
            {
                return;
            }

            try
            {
                _onDead.Invoke();
            }
            catch (Exception e)
            {
                Log.Error($"[PlayerAvatarEntity] 死亡回调执行异常: {e.Message}");
            }
        }

        /// <summary>
        /// 播放移动动画。
        /// </summary>
        private void PlayMoveAnimation()
        {
            if (_animator != null)
            {
                _animator.Play(MoveAnimationState);
            }
        }

        /// <summary>
        /// 重置所有运行时状态，清空回调并移除所有 Feature。
        /// </summary>
        private void ResetRuntimeState()
        {
            // 清理回调
            _takeDamageCallback = null;
            _currentHealthCallback = null;
            _maxHealthCallback = null;
            _isDeadCallback = null;

            // 移除所有 Feature
            var allFeatures = Features.GetAllFeatures();
            for (int i = allFeatures.Count - 1; i >= 0; i--)
            {
                Features.RemoveFeature(allFeatures[i]);
            }

            _animator = null;
            _collider2D = null;
            _bulletModule = null;
            _entityManager = null;
            _onDead = null;
            _deathNotified = false;
            _lifecycleToken++;
        }
    }
}
