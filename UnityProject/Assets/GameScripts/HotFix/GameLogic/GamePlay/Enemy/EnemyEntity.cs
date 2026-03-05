using EF.Debugger;
using EF.Entity;
using EF.Common;
using UnityEngine;

namespace GameLogic
{
    /// <summary>
    /// 敌人实体。
    /// 负责敌人的移动、停留和攻击行为逻辑，以及动画状态控制。
    /// </summary>
    public class EnemyEntity : EntityBase, IHealth
    {
        /// <summary>
        /// 敌人行为状态。
        /// </summary>
        private enum EnemyState
        {
            Moving, // 移动中
            Staying, // 停留中
            Dead // 死亡
        }

        private GameObject _handleField;
        private EnemyState _currentState;

        // 移动参数
        private float _moveSpeed;
        private Vector3 _moveDirection;

        // 停留参数
        private Vector3 _stayPosition;
        private float _stayDuration;
        private float _stayTimer;
        private bool _hasStayed; // 是否已经完成过停留

        // 攻击参数
        private float _attackInterval;
        private float _attackTimer;

        // 动画控制
        private Animator _animator;
        private Collider2D _collider2D;
        private static readonly int IsDeadParam = Animator.StringToHash("IsDead");
        private const string EnemyIdelState = "EnemyIdel";
        private const string EnemyDeadState = "EnemyDead";
        private const int KillScore = 1;

        // 边界检测
        private const float BottomBoundary = -6f;

        // 缓存的模块引用，避免每帧查询 ModuleSystem
        private IBulletModule _bulletModule;
        private IEntityManager _entityManager;
        private GamePlayModel _gamePlayModel;
        private int _lifecycleToken;

        // 生命值系统
        private float _currentHealth;
        private float _maxHealth;
        private bool _isDead;
        private bool _hasAwardedKillScore;

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
        /// 实体关联的 GameObject。
        /// 使用显式实现绕过 HybridCLR 的 internal set 限制。
        /// </summary>
        public override GameObject Handle
        {
            get { return _handleField; }
            set { _handleField = value; }
        }

        /// <summary>
        /// 初始化实体。
        /// </summary>
        public override void OnInit(int entityId, string entityAssetName, IEntityGroup entityGroup, bool isNewInstance,
            object userData)
        {
            base.OnInit(entityId, entityAssetName, entityGroup, isNewInstance, userData);

            // 重置状态
            _currentState = EnemyState.Moving;
            _stayTimer = 0f;
            _attackTimer = 0f;
            _hasStayed = false;
            _animator = null;
            _collider2D = null;
            _currentHealth = 0f;
            _maxHealth = 0f;
            _isDead = false;
            _hasAwardedKillScore = false;
            _gamePlayModel = null;
        }

        /// <summary>
        /// 实体显示时初始化位置和行为参数。
        /// </summary>
        public override void OnShow(object userData)
        {
            base.OnShow(userData);

            _lifecycleToken++;

            // 缓存模块引用，避免每帧查询
            _bulletModule = ModuleSystem.Get<IBulletModule>();
            _entityManager = ModuleSystem.Get<IEntityManager>();
            ResolveGamePlayModel();
            _hasAwardedKillScore = false;

            // 激活 GameObject
            if (Handle != null)
            {
                Handle.SetActive(true);

                // 获取 Animator 组件
                _animator = Handle.GetComponent<Animator>();
                _collider2D = Handle.GetComponent<Collider2D>();
                if (_animator != null)
                {
                    // 播放待机动画
                    _animator.Play(EnemyIdelState);
                    _animator.SetBool(IsDeadParam, false);
                }

                if (_collider2D != null)
                {
                    _collider2D.enabled = true;
                }
            }

            // 解析行为配置数据
            if (userData is EnemyBehaviorData behaviorData)
            {
                // 设置初始位置
                if (Handle != null)
                {
                    Handle.transform.position = behaviorData.SpawnPosition;
                }

                // 初始化移动参数
                _moveSpeed = behaviorData.MoveSpeed;
                _moveDirection = behaviorData.MoveDirection.normalized;

                // 初始化停留参数
                _stayPosition = behaviorData.StayPosition;
                _stayDuration = behaviorData.StayDuration;

                // 初始化攻击参数
                _attackInterval = behaviorData.AttackInterval;

                // 初始化生命值
                _maxHealth = 50f;
                _currentHealth = _maxHealth;
                _isDead = false;

                // 设置初始状态为移动
                _currentState = EnemyState.Moving;
                _stayTimer = 0f;
                _attackTimer = 0f;
                _hasStayed = false;

                // Log.Info($"[EnemyEntity] ID {Id} 已显示，位置: {behaviorData.SpawnPosition}, 停留目标: {_stayPosition}");
            }
            else
            {
                Log.Warning($"[EnemyEntity] ID {Id} 未接收到有效的行为配置数据");
            }
        }

        /// <summary>
        /// 实体更新，执行移动、停留和攻击逻辑。
        /// </summary>
        public override void OnUpdate(float elapseSeconds, float realElapseSeconds)
        {
            base.OnUpdate(elapseSeconds, realElapseSeconds);

            if (Handle == null)
            {
                return;
            }

            if (_isDead || _currentState == EnemyState.Dead)
            {
                return;
            }

            switch (_currentState)
            {
                case EnemyState.Moving:
                    UpdateMoving(elapseSeconds);
                    break;

                case EnemyState.Staying:
                    UpdateStaying(elapseSeconds);
                    break;

                case EnemyState.Dead:
                    return;
            }

            // 更新攻击逻辑（移动和停留状态都可以攻击）
            UpdateAttack(elapseSeconds);

            // 边界检测
            CheckBoundary();
        }

        /// <summary>
        /// 更新移动逻辑。
        /// </summary>
        private void UpdateMoving(float elapseSeconds)
        {
            // 移动敌人
            Handle.transform.position += _moveDirection * _moveSpeed * elapseSeconds;

            // 尚未停留过时，检查是否到达停留位置
            if (!_hasStayed)
            {
                float distanceToStayPosition = Vector3.Distance(Handle.transform.position, _stayPosition);
                if (distanceToStayPosition < 0.1f)
                {
                    // 切换到停留状态
                    _currentState = EnemyState.Staying;
                    _stayTimer = 0f;
                    Handle.transform.position = _stayPosition; // 精确定位到停留位置
                    Log.Info($"[EnemyEntity] ID {Id} 到达停留位置: {_stayPosition}");
                }
            }
        }

        /// <summary>
        /// 更新停留逻辑。
        /// </summary>
        private void UpdateStaying(float elapseSeconds)
        {
            _stayTimer += elapseSeconds;

            // 检查停留时间是否到期
            if (_stayTimer >= _stayDuration)
            {
                // 标记已完成停留，切换回移动状态继续向下
                _hasStayed = true;
                _currentState = EnemyState.Moving;
                // Log.Info($"[EnemyEntity] ID {Id} 停留结束，继续向下移动");
            }
        }

        /// <summary>
        /// 更新攻击逻辑。
        /// </summary>
        private void UpdateAttack(float elapseSeconds)
        {
            // 防御性检查：攻击间隔无效时跳过攻击，避免无限射击
            if (_attackInterval <= 0f)
            {
                return;
            }

            _attackTimer += elapseSeconds;

            // 检查攻击间隔
            if (_attackTimer >= _attackInterval)
            {
                TriggerAttack();
                _attackTimer = 0f;
            }
        }

        /// <summary>
        /// 触发攻击行为，向下发射一颗子弹。
        /// </summary>
        private void TriggerAttack()
        {
            if (_bulletModule == null)
            {
                Log.Warning($"[EnemyEntity] ID {Id} 无法获取 IBulletModule，跳过攻击");
                return;
            }

            var bulletData = new BulletData
            {
                SpawnPosition = Handle.transform.position,
                Direction = Vector3.down,
                Speed = 5f,
                OwnerType = BulletOwnerType.Enemy,
                Damage = 20f,
                SourceEntityId = Id
            };

            _bulletModule.Fire(bulletData);
            // Log.Info($"[EnemyEntity] ID {Id} 发射子弹，位置: {Handle.transform.position}");
        }

        /// <summary>
        /// 边界检测，敌人超出屏幕底部时自动销毁。
        /// </summary>
        private void CheckBoundary()
        {
            if (Handle.transform.position.y < BottomBoundary)
            {
                // Log.Info($"[EnemyEntity] ID {Id} 超出边界，自动销毁");

                // 使用缓存的 EntityManager 销毁自己
                if (_entityManager != null)
                {
                    _entityManager.HideEntity(Id);
                }
            }
        }

        /// <summary>
        /// 播放死亡动画。
        /// </summary>
        public void PlayDeadAnimation()
        {
            if (_animator != null)
            {
                _animator.SetBool(IsDeadParam, true);
                _animator.Play(EnemyDeadState);
                // Log.Info($"[EnemyEntity] ID {Id} 播放死亡动画");
            }
        }

        /// <summary>
        /// 接受伤害。
        /// </summary>
        /// <param name="damage">伤害值。</param>
        public void TakeDamage(float damage)
        {
            if (_isDead)
            {
                return;
            }

            _currentHealth -= damage;
            // Log.Info($"[EnemyEntity] ID {Id} 受到伤害 {damage}，当前生命值: {_currentHealth}/{_maxHealth}");

            if (_currentHealth <= 0)
            {
                _isDead = true;
                _currentHealth = 0;
                _currentState = EnemyState.Dead;
                // Log.Info($"[EnemyEntity] ID {Id} 已死亡");

                TryAwardKillScore();

                if (_collider2D != null)
                {
                    _collider2D.enabled = false;
                }

                ClearOwnedBullets();

                // 播放死亡动画
                PlayDeadAnimation();

                // 延迟隐藏实体(等待动画播放)
                DelayedHide(1.0f, _lifecycleToken, Id);
            }
        }

        /// <summary>
        /// 延迟隐藏实体。
        /// </summary>
        private async void DelayedHide(float delay, int expectedToken, int expectedEntityId)
        {
            await Cysharp.Threading.Tasks.UniTask.Delay(System.TimeSpan.FromSeconds(delay));

            if (expectedToken != _lifecycleToken || !_isDead || Id != expectedEntityId)
            {
                return;
            }

            // 兜底重试：避免异常时序导致本次击败未结算积分。
            TryAwardKillScore();

            if (Handle != null && _entityManager != null)
            {
                _entityManager.HideEntity(expectedEntityId);
                // Log.Info($"[EnemyEntity] ID {expectedEntityId} 已隐藏");
            }
        }

        private void ClearOwnedBullets()
        {
            if (_bulletModule == null)
            {
                _bulletModule = ModuleSystem.Get<IBulletModule>();
            }

            _bulletModule?.ClearBulletsBySource(Id);
        }

        private void TryAwardKillScore()
        {
            if (_hasAwardedKillScore)
            {
                return;
            }

            // 每次重新解析，避免使用已释放的缓存引用
            var model = ResolveGamePlayModel();

            if (model == null)
            {
                Log.Warning($"[EnemyEntity] ID {Id} 结算击败积分失败，GamePlayModel 不可用");
                return;
            }

            model.AddScore(KillScore);
            _hasAwardedKillScore = true;

            // 记录关卡击杀
            if (ModuleSystem.TryGet<ILevelModule>(out var levelModule))
            {
                levelModule.RecordKill();
            }
        }

        /// <summary>
        /// 解析并缓存玩法模型。
        /// 使用非泛型 TryGetModel(Type) 规避热更新环境下的泛型校验问题。
        /// </summary>
        private GamePlayModel ResolveGamePlayModel()
        {
            var modelManager = GameLogicEntry.Model;
            if (modelManager == null)
            {
                _gamePlayModel = null;
                return null;
            }

            _gamePlayModel = modelManager.TryGetModel(typeof(GamePlayModel)) as GamePlayModel;
            return _gamePlayModel;
        }

        /// <summary>
        /// 实体隐藏时清理状态。
        /// </summary>
        public override void OnHide(bool isShutdown, object userData)
        {
            base.OnHide(isShutdown, userData);

            _lifecycleToken++;

            // 停用 GameObject
            if (Handle != null)
            {
                Handle.SetActive(false);
            }

            // 清理状态
            _currentState = EnemyState.Moving;
            _stayTimer = 0f;
            _attackTimer = 0f;
            _hasStayed = false;
            _animator = null;
            _collider2D = null;
            _currentHealth = 0f;
            _maxHealth = 0f;
            _isDead = false;
            _hasAwardedKillScore = false;

            // 清理缓存的模块引用
            _bulletModule = null;
            _entityManager = null;
            _gamePlayModel = null;

            // Log.Info($"[EnemyEntity] ID {Id} 已隐藏");
        }

        /// <summary>
        /// 实体回收时重置数据。
        /// </summary>
        public override void OnRecycle()
        {
            base.OnRecycle();

            _lifecycleToken++;

            // 重置所有数据
            _moveSpeed = 0f;
            _moveDirection = Vector3.zero;
            _stayPosition = Vector3.zero;
            _stayDuration = 0f;
            _attackInterval = 0f;
            _stayTimer = 0f;
            _attackTimer = 0f;
            _hasStayed = false;
            _currentState = EnemyState.Moving;
            _animator = null;
            _collider2D = null;
            _currentHealth = 0f;
            _maxHealth = 0f;
            _isDead = false;
            _hasAwardedKillScore = false;
            _gamePlayModel = null;
        }
    }
}
