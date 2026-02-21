using System;
using Cysharp.Threading.Tasks;
using EF.Common;
using EF.Debugger;
using EF.Entity;
using UnityEngine;

namespace GameLogic
{
    /// <summary>
    /// 子弹模块实现。
    /// 使用 EntityManager 管理子弹实体的生成和回收。
    /// 子弹通用于玩家和敌人双方。
    /// </summary>
    public sealed class BulletModule : AEFManager, IBulletModule
    {
        private const string BulletGroupName = "Bullet";

        private readonly IEntityManager _entityManager;

        private string _bulletPrefabName;
        private bool _isReady;

        // 子弹 ID 生成器,从 1000000 开始
        private int _nextBulletId = 1000000;

        public BulletModule(IEntityManager entityManager)
        {
            _entityManager = entityManager ?? throw new ArgumentNullException(nameof(entityManager));
        }

        /// <summary>
        /// 配置子弹预制体资源名称。
        /// </summary>
        public void Configure(string bulletPrefabName)
        {
            if (!string.IsNullOrWhiteSpace(bulletPrefabName))
            {
                _bulletPrefabName = bulletPrefabName;
            }

            // Log.Info($"[BulletModule] 已配置 - 预制体: {_bulletPrefabName}");
        }

        /// <summary>
        /// 异步初始化模块,创建 Bullet EntityGroup。
        /// </summary>
        public async UniTask InitializeAsync()
        {
            // Log.Info("[BulletModule] InitializeAsync");

            if (_isReady)
            {
                return;
            }

            if (string.IsNullOrWhiteSpace(_bulletPrefabName))
            {
                Log.Error("[BulletModule] 子弹预制体名称未配置,无法初始化");
                return;
            }

            if (_entityManager == null)
            {
                Log.Error("[BulletModule] EntityManager 未初始化,无法创建实体组");
                return;
            }

            // 创建 Bullet EntityGroup
            if (!_entityManager.HasEntityGroup(BulletGroupName))
            {
                var options = new EntityGroupOptions
                {
                    Priority = 0,
                    AutoRelease = true,
                    Capacity = 50,
                    ExpireTime = 60f,
                    AutoReleaseInterval = 30f,
                    EntityFactory = () => new BulletEntity()
                };

                bool created = _entityManager.AddEntityGroup(BulletGroupName, options);
                if (created)
                {
                    // Log.Info($"[BulletModule] 已创建子弹实体组: {BulletGroupName}");
                }
                else
                {
                    Log.Error($"[BulletModule] 创建子弹实体组失败: {BulletGroupName}");
                    return;
                }
            }

            _isReady = true;
            // Log.Info($"[BulletModule] 初始化完成");

            // 避免编译器警告,实际上不需要异步操作
            await UniTask.CompletedTask;
        }

        /// <summary>
        /// 发射一颗子弹。
        /// </summary>
        public async void Fire(BulletData data)
        {
            if (!_isReady)
            {
                Log.Warning("[BulletModule] 模块未就绪,无法发射子弹");
                return;
            }

            if (data == null)
            {
                Log.Warning("[BulletModule] BulletData 为空,无法发射子弹");
                return;
            }

            int bulletId = GenerateUniqueId();

            try
            {
                await _entityManager.ShowEntityAsync(bulletId, _bulletPrefabName, BulletGroupName, data);
                // Log.Info($"[BulletModule] 子弹发射成功 - ID: {bulletId}, 归属: {data.OwnerType}");
            }
            catch (Exception e)
            {
                Log.Error($"[BulletModule] 子弹发射失败: {e.Message}");
            }
        }

        /// <summary>
        /// 按发射者实体 ID 清理在场子弹。
        /// </summary>
        public void ClearBulletsBySource(int sourceEntityId)
        {
            if (!_isReady || sourceEntityId <= 0)
            {
                return;
            }

            IEntity[] loadedEntities = _entityManager.GetAllLoadedEntities();
            int clearedCount = 0;
            for (int i = 0; i < loadedEntities.Length; i++)
            {
                if (loadedEntities[i] is not BulletEntity bulletEntity)
                {
                    continue;
                }

                if (bulletEntity.SourceEntityId != sourceEntityId)
                {
                    continue;
                }

                _entityManager.HideEntity(bulletEntity.Id);
                clearedCount++;
            }

            if (clearedCount > 0)
            {
                Log.Info($"[BulletModule] 已清理发射者 {sourceEntityId} 的在场子弹数量: {clearedCount}");
            }
        }

        /// <summary>
        /// 关闭模块,销毁 EntityGroup。
        /// </summary>
        public override void Shutdown()
        {
            // Log.Info("[BulletModule] Shutdown");

            _isReady = false;

            // 销毁 EntityGroup
            if (_entityManager != null && _entityManager.HasEntityGroup(BulletGroupName))
            {
                _entityManager.RemoveEntityGroup(BulletGroupName);
                // Log.Info($"[BulletModule] 已销毁子弹实体组: {BulletGroupName}");
            }
        }

        /// <summary>
        /// 生成唯一的子弹 ID。
        /// </summary>
        private int GenerateUniqueId()
        {
            return _nextBulletId++;
        }
    }
}
