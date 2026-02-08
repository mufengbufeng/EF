using System;
using System.Collections.Generic;
using Cysharp.Threading.Tasks;
using EF.Common;
using EF.Debugger;
using EF.ObjectPool;
using EF.Resource;
using UnityEngine;
using YooAsset;

namespace GameLogic
{
    /// <summary>
    /// 子弹模块实现。
    /// 使用对象池管理子弹 GameObject 的生成和回收。
    /// 子弹通用于玩家和敌人双方。
    /// </summary>
    public sealed class BulletModule : AEFManager, IBulletModule
    {
        private const string BulletPoolNamePrefix = "BulletPool";

        private readonly IResourceManager _resourceManager;
        private readonly IObjectPoolManager _objectPoolManager;

        private string _bulletPrefabName;
        private string _bulletPoolName;
        private IObjectPool<GameObject> _bulletPool;
        private GameObject _bulletTemplate;
        private AssetHandle _assetHandle;
        private bool _isReady;
        private bool _isLoading;

        /// <summary>
        /// 活跃子弹列表。
        /// 每个元素记录了子弹的 GameObject 和运行时数据。
        /// </summary>
        private readonly List<ActiveBullet> _activeBullets = new();

        /// <summary>
        /// 待回收子弹的索引列表，避免在遍历中修改集合。
        /// </summary>
        private readonly List<int> _recycleIndices = new();

        // 边界参数（基于摄像机可视区域 + 缓冲）
        private const float BoundaryBuffer = 1f;

        /// <summary>
        /// 活跃子弹的运行时数据。
        /// </summary>
        private struct ActiveBullet
        {
            public GameObject Go;
            public Vector3 Direction;
            public float Speed;
            public string OwnerTag;
        }

        public BulletModule(IResourceManager resourceManager, IObjectPoolManager objectPoolManager)
        {
            _resourceManager = resourceManager ?? throw new ArgumentNullException(nameof(resourceManager));
            _objectPoolManager = objectPoolManager ?? throw new ArgumentNullException(nameof(objectPoolManager));
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

            Log.Info($"[BulletModule] 已配置 - 预制体: {_bulletPrefabName}");
        }

        /// <summary>
        /// 异步初始化模块，加载预制体并创建对象池。
        /// </summary>
        public async UniTask InitializeAsync()
        {
            Log.Info("[BulletModule] InitializeAsync");

            if (_isLoading || _isReady)
            {
                return;
            }

            if (string.IsNullOrWhiteSpace(_bulletPrefabName))
            {
                Log.Error("[BulletModule] 子弹预制体名称未配置，无法初始化");
                return;
            }

            if (!_resourceManager.IsInitialized)
            {
                Log.Warning("[BulletModule] 资源管理器未初始化，无法加载子弹预制体");
                return;
            }

            _isLoading = true;
            try
            {
                AssetHandle handle = await _resourceManager.LoadAssetAsync<GameObject>(_bulletPrefabName);
                GameObject prefab = handle.AssetObject as GameObject;
                if (prefab == null)
                {
                    Log.Error($"[BulletModule] 子弹预制体加载失败: {_bulletPrefabName}");
                    _resourceManager.Release(handle);
                    return;
                }

                _assetHandle = handle;
                _bulletTemplate = prefab;

                // 创建对象池
                _bulletPoolName = $"{BulletPoolNamePrefix}_{_bulletPrefabName}";
                if (_objectPoolManager.HasPool<GameObject>(_bulletPoolName))
                {
                    _bulletPool = _objectPoolManager.GetPool<GameObject>(_bulletPoolName);
                }
                else
                {
                    var options = new ObjectPoolOptions
                    {
                        AllowMultiSpawn = false,
                        AutoRelease = false
                    };

                    _bulletPool = _objectPoolManager.CreatePool(
                        _bulletPoolName,
                        CreateBulletInstance,
                        options,
                        OnBulletSpawn,
                        OnBulletRecycle,
                        OnBulletDestroy);
                }

                _isReady = true;
                Log.Info($"[BulletModule] 初始化完成，对象池已创建: {_bulletPoolName}");
            }
            catch (Exception e)
            {
                Log.Error($"[BulletModule] 初始化失败: {e.Message}");
            }
            finally
            {
                _isLoading = false;
            }
        }

        /// <summary>
        /// 发射一颗子弹。
        /// </summary>
        public void Fire(BulletData data)
        {
            if (!_isReady || _bulletPool == null)
            {
                Log.Warning("[BulletModule] 模块未就绪，无法发射子弹");
                return;
            }

            if (data == null)
            {
                Log.Warning("[BulletModule] BulletData 为空，无法发射子弹");
                return;
            }

            GameObject bulletGo = _bulletPool.Spawn();
            if (bulletGo == null)
            {
                Log.Error("[BulletModule] 从对象池中获取子弹失败");
                return;
            }

            // 设置子弹位置和方向
            bulletGo.transform.position = data.SpawnPosition;

            // 根据飞行方向设置旋转（默认 Sprite 朝上）
            float angle = Mathf.Atan2(data.Direction.y, data.Direction.x) * Mathf.Rad2Deg - 90f;
            bulletGo.transform.rotation = Quaternion.Euler(0f, 0f, angle);

            // 记录活跃子弹
            _activeBullets.Add(new ActiveBullet
            {
                Go = bulletGo,
                Direction = data.Direction.normalized,
                Speed = data.Speed,
                OwnerTag = data.OwnerTag
            });
        }

        /// <summary>
        /// 每帧更新：移动所有活跃子弹并回收超出边界的子弹。
        /// </summary>
        public override void Update(float elapseSeconds, float realElapseSeconds)
        {
            if (!_isReady || _activeBullets.Count == 0)
            {
                return;
            }

            _recycleIndices.Clear();

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

            // 移动子弹并检测边界
            for (int i = 0; i < _activeBullets.Count; i++)
            {
                ActiveBullet bullet = _activeBullets[i];

                if (bullet.Go == null)
                {
                    _recycleIndices.Add(i);
                    continue;
                }

                // 移动
                bullet.Go.transform.position += bullet.Direction * bullet.Speed * elapseSeconds;

                // 边界检测
                Vector3 pos = bullet.Go.transform.position;
                if (pos.y > topY || pos.y < bottomY || pos.x < leftX || pos.x > rightX)
                {
                    _recycleIndices.Add(i);
                }
            }

            // 从后往前回收，避免索引偏移
            for (int i = _recycleIndices.Count - 1; i >= 0; i--)
            {
                int index = _recycleIndices[i];
                ActiveBullet bullet = _activeBullets[index];

                if (bullet.Go != null && _bulletPool != null)
                {
                    _bulletPool.Recycle(bullet.Go);
                }

                _activeBullets.RemoveAt(index);
            }
        }

        /// <summary>
        /// 关闭模块，回收所有子弹并销毁对象池。
        /// </summary>
        public override void Shutdown()
        {
            Log.Info($"[BulletModule] Shutdown - 清理 {_activeBullets.Count} 颗活跃子弹");

            // 回收所有活跃子弹
            foreach (ActiveBullet bullet in _activeBullets)
            {
                if (bullet.Go != null && _bulletPool != null)
                {
                    _bulletPool.TryRecycle(bullet.Go);
                }
            }

            _activeBullets.Clear();
            _recycleIndices.Clear();
            _isReady = false;
            _bulletTemplate = null;

            // 销毁对象池
            if (!string.IsNullOrWhiteSpace(_bulletPoolName))
            {
                _objectPoolManager.DestroyPool<GameObject>(_bulletPoolName);
                _bulletPoolName = null;
                _bulletPool = null;
            }

            // 释放资源句柄
            if (_assetHandle != null)
            {
                _resourceManager.Release(_assetHandle);
                _assetHandle = null;
            }
        }

        #region 对象池回调

        private GameObject CreateBulletInstance()
        {
            if (_bulletTemplate == null)
            {
                throw new InvalidOperationException("子弹模板为空，无法创建实例");
            }

            GameObject instance = UnityEngine.Object.Instantiate(_bulletTemplate);
            instance.name = $"{_bulletTemplate.name}_Pooled";
            instance.SetActive(false);
            return instance;
        }

        private void OnBulletSpawn(GameObject instance)
        {
            if (instance != null)
            {
                instance.SetActive(true);
            }
        }

        private void OnBulletRecycle(GameObject instance)
        {
            if (instance != null)
            {
                instance.SetActive(false);
            }
        }

        private void OnBulletDestroy(GameObject instance)
        {
            if (instance != null)
            {
                UnityEngine.Object.Destroy(instance);
            }
        }

        #endregion
    }
}
