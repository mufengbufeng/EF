using System;
using Cysharp.Threading.Tasks;
using EF.Common;
using EF.Debugger;
using EF.Entity;
using UnityEngine;

namespace GameLogic
{
    /// <summary>
    /// 玩家飞机模块。
    /// 负责玩家实体组创建、玩家实体生成与回收。
    /// </summary>
    public sealed class PlayerAvatarModule : AEFManager, IPlayerAvatarModule
    {
        private readonly IEntityManager _entityManager;

        private string _avatarPrefabName;
        private string _avatarGroupName;
        private float _attackInterval;
        private float _bulletSpeed;
        private float _dragBoundaryPadding;

        private Transform _spawnAnchor;
        private int _avatarEntityId;
        private bool _isInitialized;

        /// <summary>
        /// 初始化玩家模块。
        /// </summary>
        /// <param name="entityManager">实体管理器。</param>
        public PlayerAvatarModule(IEntityManager entityManager)
        {
            _entityManager = entityManager ?? throw new ArgumentNullException(nameof(entityManager));
            _avatarEntityId = 0;
        }

        /// <summary>
        /// 配置玩家参数。
        /// </summary>
        public void Configure(
            string avatarPrefabName,
            string avatarGroupName,
            float attackInterval,
            float bulletSpeed,
            float dragBoundaryPadding)
        {
            _avatarPrefabName = avatarPrefabName;
            _avatarGroupName = avatarGroupName;
            _attackInterval = attackInterval;
            _bulletSpeed = bulletSpeed;
            _dragBoundaryPadding = Mathf.Max(0f, dragBoundaryPadding);

            Log.Info(
                $"[PlayerAvatarModule] 已配置 - 预制体:{_avatarPrefabName}, 实体组:{_avatarGroupName}, 攻击间隔:{_attackInterval}, 子弹速度:{_bulletSpeed}");
        }

        /// <summary>
        /// 设置玩家出生锚点。
        /// </summary>
        public void SetSpawnAnchor(Transform spawnAnchor)
        {
            _spawnAnchor = spawnAnchor;
        }

        /// <summary>
        /// 初始化模块并生成玩家实体。
        /// </summary>
        public async UniTask InitializeAsync()
        {
            if (_isInitialized && _avatarEntityId > 0 && _entityManager.HasEntity(_avatarEntityId))
            {
                return;
            }

            if (string.IsNullOrWhiteSpace(_avatarPrefabName))
            {
                Log.Error("[PlayerAvatarModule] 玩家预制体名称为空，无法初始化");
                return;
            }

            if (string.IsNullOrWhiteSpace(_avatarGroupName))
            {
                Log.Error("[PlayerAvatarModule] 玩家实体组名称为空，无法初始化");
                return;
            }

            EnsureAvatarEntityGroup();

            Vector3 spawnPosition = ResolveSpawnPosition();
            var behaviorData = new PlayerAvatarBehaviorData
            {
                SpawnPosition = spawnPosition,
                AttackInterval = _attackInterval,
                BulletSpeed = _bulletSpeed,
                DragBoundaryPadding = _dragBoundaryPadding
            };

            try
            {
                if (_avatarEntityId <= 0)
                {
                    _avatarEntityId = _entityManager.GenerateEntityId();
                }

                await _entityManager.ShowEntityAsync(_avatarEntityId, _avatarPrefabName, _avatarGroupName, behaviorData);
                _isInitialized = true;
                Log.Info($"[PlayerAvatarModule] 玩家实体初始化完成，EntityId:{_avatarEntityId}, Spawn:{spawnPosition}");
            }
            catch (Exception e)
            {
                _isInitialized = false;
                _avatarEntityId = 0;
                Log.Error($"[PlayerAvatarModule] 初始化玩家实体失败: {e.Message}");
            }
        }

        /// <summary>
        /// 关闭模块并回收玩家实体。
        /// </summary>
        public override void Shutdown()
        {
            if (_avatarEntityId > 0 && _entityManager.HasEntity(_avatarEntityId))
            {
                _entityManager.HideEntity(_avatarEntityId);
                Log.Info($"[PlayerAvatarModule] 已回收玩家实体，EntityId:{_avatarEntityId}");
            }

            _avatarEntityId = 0;
            _isInitialized = false;
            _spawnAnchor = null;
        }

        private void EnsureAvatarEntityGroup()
        {
            if (_entityManager.HasEntityGroup(_avatarGroupName))
            {
                return;
            }

            var options = new EntityGroupOptions
            {
                Priority = 0,
                AutoRelease = true,
                Capacity = 2,
                ExpireTime = 120f,
                AutoReleaseInterval = 60f,
                EntityFactory = () => new PlayerAvatarEntity()
            };

            bool created = _entityManager.AddEntityGroup(_avatarGroupName, options);
            if (created)
            {
                Log.Info($"[PlayerAvatarModule] 已创建玩家实体组: {_avatarGroupName}");
            }
        }

        private Vector3 ResolveSpawnPosition()
        {
            if (_spawnAnchor != null)
            {
                return _spawnAnchor.position;
            }

            Camera mainCamera = Camera.main;
            if (mainCamera == null)
            {
                Log.Warning("[PlayerAvatarModule] 未找到 PlayerPoint 且主摄像机为空，使用默认出生点");
                return new Vector3(0f, -3f, 0f);
            }

            float spawnY = -mainCamera.orthographicSize * 0.6f;
            return new Vector3(mainCamera.transform.position.x, spawnY, 0f);
        }
    }
}
