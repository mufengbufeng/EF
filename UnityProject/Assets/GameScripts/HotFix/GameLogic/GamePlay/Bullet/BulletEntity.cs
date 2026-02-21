using EF.Debugger;
using EF.Entity;
using EF.Common;
using UnityEngine;

namespace GameLogic
{
    /// <summary>
    /// 子弹实体。
    /// 负责子弹的移动、边界检测和碰撞检测逻辑。
    /// </summary>
    public class BulletEntity : EntityBase, ICollisionHandler
    {
        private GameObject _handleField;

        // 运行时数据
        private Vector3 _direction;
        private float _speed;
        private BulletOwnerType _ownerType;
        private float _damage;
        private int _sourceEntityId;

        // 边界参数（基于摄像机可视区域 + 缓冲）
        private const float BoundaryBuffer = 1f;

        // 缓存的模块引用
        private IEntityManager _entityManager;

        /// <summary>
        /// 实体关联的 GameObject。
        /// 使用显式实现绕过 HybridCLR 的 internal set 限制。
        /// </summary>
        public override GameObject Handle
        {
            get => _handleField;
            set => _handleField = value;
        }

        /// <summary>
        /// 发射该子弹的实体 ID。
        /// </summary>
        public int SourceEntityId => _sourceEntityId;

        /// <summary>
        /// 初始化实体。
        /// </summary>
        public override void OnInit(int entityId, string entityAssetName, IEntityGroup entityGroup, bool isNewInstance,
            object userData)
        {
            base.OnInit(entityId, entityAssetName, entityGroup, isNewInstance, userData);

            // 缓存模块引用
            if (_entityManager == null)
            {
                _entityManager = ModuleSystem.Get<IEntityManager>();
            }

            // 重置状态
            _direction = Vector3.zero;
            _speed = 0f;
            _ownerType = BulletOwnerType.Player;
            _damage = 10f;
            _sourceEntityId = 0;
        }

        /// <summary>
        /// 实体显示时调用，配置子弹数据。
        /// </summary>
        public override void OnShow(object userData)
        {
            base.OnShow(userData);

            if (Handle != null)
            {
                Handle.SetActive(true);
            }

            if (userData is BulletData data)
            {
                // 设置子弹位置
                if (Handle != null)
                {
                    Handle.transform.position = data.SpawnPosition;

                    // 根据飞行方向设置旋转（默认 Sprite 朝上）
                    float angle = Mathf.Atan2(data.Direction.y, data.Direction.x) * Mathf.Rad2Deg - 90f;
                    Handle.transform.rotation = Quaternion.Euler(0f, 0f, angle);
                }

                // 配置运行时数据
                _direction = data.Direction.normalized;
                _speed = data.Speed;
                _ownerType = data.OwnerType;
                _damage = data.Damage;
                _sourceEntityId = data.SourceEntityId;
            }
            else
            {
                Log.Warning($"[BulletEntity] OnShow 收到的 userData 不是 BulletData 类型");
            }
        }

        /// <summary>
        /// 实体更新，移动子弹和边界检测。
        /// </summary>
        public override void OnUpdate(float elapseSeconds, float realElapseSeconds)
        {
            base.OnUpdate(elapseSeconds, realElapseSeconds);

            if (Handle == null)
            {
                return;
            }

            // 移动子弹
            Handle.transform.position += _direction * _speed * elapseSeconds;

            // 边界检测
            if (IsOutOfBounds())
            {
                HideSelf();
            }
        }

        /// <summary>
        /// 实体隐藏时调用。
        /// </summary>
        public override void OnHide(bool isShutdown, object userData)
        {
            base.OnHide(isShutdown, userData);

            if (Handle != null)
            {
                Handle.SetActive(false);
            }

            _direction = Vector3.zero;
            _speed = 0f;
            _ownerType = BulletOwnerType.Player;
            _damage = 10f;
            _sourceEntityId = 0;
        }

        /// <summary>
        /// 实体回收时调用，重置数据。
        /// </summary>
        public override void OnRecycle()
        {
            base.OnRecycle();

            _direction = Vector3.zero;
            _speed = 0f;
            _ownerType = BulletOwnerType.Player;
            _damage = 10f;
            _sourceEntityId = 0;
        }

        /// <summary>
        /// 碰撞检测。
        /// </summary>
        public void HandleTriggerEnter2D(Collider2D other)
        {
            if (!other)
            {
                return;
            }

            var entityView = other.GetComponent<EntityView>();
            if (entityView == null || entityView.Entity == null)
            {
                return;
            }

            EntityBase targetEntity = entityView.Entity;
            if (!ShouldDamageTarget(targetEntity))
            {
                return;
            }

            IHealth health = targetEntity as IHealth;
            if (health != null && !health.IsDead)
            {
                health.TakeDamage(_damage);
            }

            HideSelf();
        }

        /// <summary>
        /// 判断是否应该对目标造成伤害（友军判断）。
        /// </summary>
        private bool ShouldDamageTarget(EntityBase targetEntity)
        {
            // 玩家子弹只能击中敌人
            if (_ownerType == BulletOwnerType.Player)
            {
                return targetEntity is EnemyEntity;
            }

            // 敌人子弹只能击中玩家
            if (_ownerType == BulletOwnerType.Enemy)
            {
                return targetEntity is PlayerAvatarEntity;
            }

            return false;
        }

        /// <summary>
        /// 判断子弹是否超出边界。
        /// </summary>
        private bool IsOutOfBounds()
        {
            if (Handle == null)
            {
                return true;
            }

            Vector3 pos = Handle.transform.position;

            // 获取屏幕边界
            Camera cam = Camera.main;
            float topY = 7f;
            float bottomY = -7f;
            float leftX = -6f;
            float rightX = 6f;

            if (cam != null)
            {
                topY = cam.orthographicSize + BoundaryBuffer;
                bottomY = -cam.orthographicSize - BoundaryBuffer;
                float halfWidth = cam.orthographicSize * cam.aspect;
                leftX = -halfWidth - BoundaryBuffer;
                rightX = halfWidth + BoundaryBuffer;
            }

            return pos.y > topY || pos.y < bottomY || pos.x < leftX || pos.x > rightX;
        }

        /// <summary>
        /// 隐藏自己。
        /// </summary>
        private void HideSelf()
        {
            if (_entityManager != null)
            {
                _entityManager.HideEntity(Id);
            }
            else
            {
                Log.Error($"[BulletEntity] 无法隐藏子弹，EntityManager 为空 - ID: {Id}");
            }
        }
    }
}
