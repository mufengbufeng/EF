using System;
using System.Collections.Generic;
using Cysharp.Threading.Tasks;
using EF.Common;
using EF.Debugger;
using EF.Entity;

namespace GameLogic
{
    /// <summary>
    /// 飞机大战：敌机模块。
    /// - 使用 IEntityManager 创建/回收敌机实体
    /// - 支持按固定间隔刷怪（最小实现）
    /// - 退出玩法时通过 Shutdown() 回收所有本模块创建的敌机
    /// </summary>
    public sealed class GameEnemyModule : AEFManager, IGameEnemyModule
    {
        private readonly IEntityManager _entityManager;

        private string _enemyEntityAssetName;
        private string _enemyEntityGroupName;
        private float _spawnIntervalSeconds = 1f;

        private bool _isSpawning;
        private bool _isShutdown;
        private float _spawnTimer;
        private bool _spawnInProgress;

        private int _nextEntityId = 10000;
        private readonly List<int> _spawnedEntityIds = new();

        public GameEnemyModule(IEntityManager entityManager)
        {
            _entityManager = entityManager ?? throw new ArgumentNullException(nameof(entityManager));
        }

        public void Configure(string enemyEntityAssetName, string enemyEntityGroupName, float spawnIntervalSeconds = 1f)
        {
            _enemyEntityAssetName = enemyEntityAssetName;
            _enemyEntityGroupName = enemyEntityGroupName;
            _spawnIntervalSeconds = spawnIntervalSeconds > 0f ? spawnIntervalSeconds : 1f;

            Log.Info($"[GameEnemyModule] 已配置敌机模块参数：实体资源={_enemyEntityAssetName}，实体组={_enemyEntityGroupName}，间隔={_spawnIntervalSeconds:0.###}s");
        }

        public void StartSpawning()
        {
            if (_isShutdown)
            {
                Log.Warning("[GameEnemyModule] 模块已关闭，无法开始刷怪。");
                return;
            }

            if (string.IsNullOrEmpty(_enemyEntityAssetName) || string.IsNullOrEmpty(_enemyEntityGroupName))
            {
                Log.Warning("[GameEnemyModule] 未配置敌机资源名或实体组名，跳过刷怪启动。");
                return;
            }

            _isSpawning = true;
            _spawnTimer = 0f;
            Log.Info("[GameEnemyModule] 已开始刷怪。");
        }

        public void StopSpawning()
        {
            if (!_isSpawning)
            {
                return;
            }

            _isSpawning = false;
            Log.Info("[GameEnemyModule] 已停止刷怪。");
        }

        public override void Update(float elapseSeconds, float realElapseSeconds)
        {
            if (_isShutdown || !_isSpawning)
            {
                return;
            }

            _spawnTimer += elapseSeconds;
            if (_spawnTimer < _spawnIntervalSeconds)
            {
                return;
            }

            _spawnTimer = 0f;
            TrySpawnEnemy().Forget();
        }

        public override void Shutdown()
        {
            if (_isShutdown)
            {
                return;
            }

            _isShutdown = true;
            StopSpawning();

            for (int i = 0; i < _spawnedEntityIds.Count; i++)
            {
                int entityId = _spawnedEntityIds[i];
                try
                {
                    _entityManager.HideEntity(entityId);
                }
                catch (Exception ex)
                {
                    Log.Warning($"[GameEnemyModule] 回收敌机失败：entityId={entityId}，原因：{ex.Message}");
                }
            }

            _spawnedEntityIds.Clear();
            Log.Info("[GameEnemyModule] 模块已关闭并完成清理。");
        }

        private async UniTask TrySpawnEnemy()
        {
            if (_isShutdown || !_isSpawning)
            {
                return;
            }

            if (_spawnInProgress)
            {
                return;
            }

            if (string.IsNullOrEmpty(_enemyEntityAssetName) || string.IsNullOrEmpty(_enemyEntityGroupName))
            {
                return;
            }

            _spawnInProgress = true;
            try
            {
                if (!EnsureEnemyGroupExists())
                {
                    return;
                }

                int entityId = _nextEntityId++;
                IEntity entity = await _entityManager.ShowEntityAsync(entityId, _enemyEntityAssetName, _enemyEntityGroupName);
                if (entity == null)
                {
                    Log.Warning($"[GameEnemyModule] 生成敌机失败：entity 为 null，entityId={entityId}");
                    return;
                }

                if (_isShutdown)
                {
                    _entityManager.HideEntity(entityId);
                    return;
                }

                _spawnedEntityIds.Add(entityId);
                Log.Info($"[GameEnemyModule] 已生成敌机实体：entityId={entityId}");
            }
            catch (Exception ex)
            {
                Log.Error($"[GameEnemyModule] 生成敌机异常：{ex.Message}");
            }
            finally
            {
                _spawnInProgress = false;
            }
        }

        private bool EnsureEnemyGroupExists()
        {
            if (_entityManager.HasEntityGroup(_enemyEntityGroupName))
            {
                return true;
            }

            bool created = _entityManager.AddEntityGroup(_enemyEntityGroupName, new EntityGroupOptions());
            if (!created)
            {
                Log.Warning($"[GameEnemyModule] 创建敌机实体组失败：{_enemyEntityGroupName}");
                return false;
            }

            return true;
        }
    }
}
