using System.Collections.Generic;
using Cysharp.Threading.Tasks;
using EF.Common;
using EF.Debugger;
using EF.Entity;
using UnityEngine;

namespace GameLogic
{
    /// <summary>
    /// 敌人生成器模块实现。
    /// 负责按间隔生成敌人，管理存活敌人数量。
    /// </summary>
    public class EnemySpawnerModule : AEFManager, IEnemySpawnerModule
    {
        private readonly IEntityManager _entityManager;

        private string _enemyPrefabName;
        private float _spawnInterval;
        private int _maxEnemyCount;
        private float _spawnTimer;

        // 生成区域参数
        private Transform _spawnAreaCenter;
        private float _spawnAreaHalfWidth;

        // 存活敌人列表
        private readonly List<int> _aliveEnemies = new List<int>();

        // 实体组名称
        private const string EnemyGroupName = "Enemy";

        /// <summary>
        /// 初始化敌人生成器模块。
        /// </summary>
        /// <param name="entityManager">实体管理器。</param>
        public EnemySpawnerModule(IEntityManager entityManager)
        {
            _entityManager = entityManager;
        }

        /// <summary>
        /// 配置敌人生成参数。
        /// </summary>
        public void Configure(string enemyPrefabName, float spawnInterval, int maxEnemyCount)
        {
            _enemyPrefabName = enemyPrefabName;
            _spawnInterval = spawnInterval;
            _maxEnemyCount = maxEnemyCount;
            _spawnTimer = 0f;

            // Log.Info($"[EnemySpawnerModule] 已配置 - 预制体: {enemyPrefabName}, 间隔: {spawnInterval}s, 最大数量: {maxEnemyCount}");
        }

        /// <summary>
        /// 设置生成区域的锚点 Transform。
        /// 敌人将在该锚点的 X 范围内随机生成，Y 坐标使用锚点的 Y 值。
        /// </summary>
        /// <param name="spawnAreaCenter">生成区域中心锚点。</param>
        /// <param name="spawnAreaHalfWidth">生成区域半宽度。</param>
        public void SetSpawnArea(Transform spawnAreaCenter, float spawnAreaHalfWidth)
        {
            _spawnAreaCenter = spawnAreaCenter;
            _spawnAreaHalfWidth = spawnAreaHalfWidth;

            if (spawnAreaCenter != null)
            {
                // Log.Info($"[EnemySpawnerModule] 已设置生成区域 - 中心: {spawnAreaCenter.position}, 半宽度: {spawnAreaHalfWidth}");
            }
            else
            {
                Log.Warning("[EnemySpawnerModule] 生成区域锚点为空，将使用摄像机计算的后备位置");
            }
        }

        /// <summary>
        /// 设置生成间隔。
        /// </summary>
        public void SetSpawnInterval(float interval)
        {
            _spawnInterval = interval;
            // Log.Info($"[EnemySpawnerModule] 生成间隔已更新为: {interval}s");
        }

        /// <summary>
        /// 设置同屏最大敌人数量。
        /// </summary>
        public void SetMaxEnemyCount(int maxCount)
        {
            _maxEnemyCount = maxCount;
            // Log.Info($"[EnemySpawnerModule] 最大敌人数量已更新为: {maxCount}");
        }

        /// <summary>
        /// 模块更新，处理生成逻辑。
        /// </summary>
        public override void Update(float elapseSeconds, float realElapseSeconds)
        {
            // 清理已销毁的敌人引用（反向遍历避免闭包分配）
            for (int i = _aliveEnemies.Count - 1; i >= 0; i--)
            {
                if (!_entityManager.HasEntity(_aliveEnemies[i]))
                {
                    _aliveEnemies.RemoveAt(i);
                }
            }

            // 累加生成计时器
            _spawnTimer += elapseSeconds;

            // 检查是否达到生成条件
            if (_spawnTimer >= _spawnInterval && _aliveEnemies.Count < _maxEnemyCount)
            {
                SpawnEnemy().Forget();
                _spawnTimer = 0f;
            }
        }

        /// <summary>
        /// 生成一个敌人。
        /// </summary>
        private async UniTaskVoid SpawnEnemy()
        {
            if (string.IsNullOrEmpty(_enemyPrefabName))
            {
                Log.Warning("[EnemySpawnerModule] 敌人预制体名称未配置");
                return;
            }

            // 计算生成位置（基于生成区域锚点的随机位置）
            Vector3 spawnPosition = GetRandomSpawnPosition();

            // 创建敌人行为数据
            var behaviorData = new EnemyBehaviorData
            {
                SpawnPosition = spawnPosition,
                MoveSpeed = 2f,
                MoveDirection = Vector3.down,
                StayPosition = new Vector3(spawnPosition.x, spawnPosition.y - 3f, 0),
                StayDuration = 2f,
                AttackInterval = 1.5f
            };

            try
            {
                int enemyId = _entityManager.GenerateEntityId();
                var entity =
                    await _entityManager.ShowEntityAsync(enemyId, _enemyPrefabName, EnemyGroupName, behaviorData);

                _aliveEnemies.Add(enemyId);
                // Log.Info($"[EnemySpawnerModule] 生成敌人 ID: {enemyId}, 位置: {spawnPosition}, 当前存活数量: {_aliveEnemies.Count}");
            }
            catch (System.Exception e)
            {
                Log.Error($"[EnemySpawnerModule] 生成敌人失败: {e.Message}");
            }
        }

        /// <summary>
        /// 获取随机生成位置。
        /// 优先使用场景中配置的生成区域锚点，否则回退到摄像机计算。
        /// </summary>
        private Vector3 GetRandomSpawnPosition()
        {
            // 优先使用场景中配置的生成区域
            if (_spawnAreaCenter != null)
            {
                Vector3 centerPos = _spawnAreaCenter.position;
                float randomX = Random.Range(centerPos.x - _spawnAreaHalfWidth, centerPos.x + _spawnAreaHalfWidth);
                return new Vector3(randomX, centerPos.y, centerPos.z);
            }

            // 后备方案：基于摄像机计算
            Camera mainCamera = Camera.main;
            if (mainCamera == null)
            {
                Log.Warning("[EnemySpawnerModule] 主摄像机未找到且无生成区域锚点，使用默认生成位置");
                return new Vector3(0, 6f, 0);
            }

            float viewportWidth = mainCamera.orthographicSize * mainCamera.aspect * 2f;
            float fallbackX = Random.Range(-viewportWidth * 0.4f, viewportWidth * 0.4f);
            float spawnY = mainCamera.orthographicSize + 1f;

            return new Vector3(fallbackX, spawnY, 0);
        }

        /// <summary>
        /// 模块初始化。
        /// </summary>
        public void Initialize()
        {
            // Log.Info("[EnemySpawnerModule] Initialize");

            // 确保实体组存在
            if (!_entityManager.HasEntityGroup(EnemyGroupName))
            {
                var options = new EntityGroupOptions
                {
                    Priority = 0,
                    AutoRelease = true,
                    Capacity = 10,
                    ExpireTime = 120f,
                    AutoReleaseInterval = 60f,
                    // 使用 EnemyEntity 作为实体类型，确保移动/攻击逻辑生效
                    EntityFactory = () => new EnemyEntity()
                };
                _entityManager.AddEntityGroup(EnemyGroupName, options);
                // Log.Info($"[EnemySpawnerModule] 已创建实体组: {EnemyGroupName}（使用 EnemyEntity 工厂）");
            }
        }

        /// <summary>
        /// 模块关闭，清理所有敌人。
        /// </summary>
        public override void Shutdown()
        {
            // Log.Info($"[EnemySpawnerModule] OnShutdown - 清理 {_aliveEnemies.Count} 个存活敌人");

            // 隐藏所有存活的敌人
            foreach (int enemyId in _aliveEnemies)
            {
                if (_entityManager.HasEntity(enemyId))
                {
                    _entityManager.HideEntity(enemyId);
                }
            }

            _aliveEnemies.Clear();
            _spawnTimer = 0f;
            _spawnAreaCenter = null;
        }
    }
}