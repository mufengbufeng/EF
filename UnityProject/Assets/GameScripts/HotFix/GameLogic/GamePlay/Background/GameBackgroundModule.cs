using System;
using System.Collections.Generic;
using System.Linq;
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
    /// 飞机大战：背景模块。
    /// - 使用资源系统加载背景预制体
    /// - 在 ModuleSystem.Update 中驱动滚动
    /// </summary>
    public sealed class GameBackgroundModule : AEFManager, IGameBackgroundModule
    {
        private const string DefaultPrefabName = "BackgroundPrefab";
        private const string BackgroundRootName = "BackgroundRoot";
        private const string SegmentPoolNamePrefix = "BackgroundSegmentPool";

        private readonly IResourceManager _resourceManager;
        private readonly IObjectPoolManager _objectPoolManager;
        private readonly List<SpriteRenderer> _segments = new();
        private readonly HashSet<GameObject> _registeredSegments = new();

        private string _prefabName = DefaultPrefabName;
        private float _speed = 1f;
        private bool _autoCloneIfSingle = true;
        private Camera _targetCamera;

        private GameObject _instance;
        private AssetHandle _handle;
        private bool _isReady;
        private bool _isLoading;
        private bool _spawnedClone;
        private float _segmentHeight;
        private float _totalHeight;
        private string _segmentPoolName;
        private IObjectPool<GameObject> _segmentPool;
        private GameObject _segmentTemplate;

        public GameBackgroundModule(IResourceManager resourceManager, IObjectPoolManager objectPoolManager)
        {
            _resourceManager = resourceManager ?? throw new ArgumentNullException(nameof(resourceManager));
            _objectPoolManager = objectPoolManager ?? throw new ArgumentNullException(nameof(objectPoolManager));
        }

        public void Configure(string prefabName, float speed = 1f, bool autoCloneIfSingle = true)
        {
            if (!string.IsNullOrWhiteSpace(prefabName))
            {
                _prefabName = prefabName;
            }

            _speed = speed;
            _autoCloneIfSingle = autoCloneIfSingle;
        }

        public void SetSpeed(float speed)
        {
            _speed = speed;
        }

        public void SetSprite(Sprite sprite)
        {
            if (sprite == null)
            {
                Log.Warning("[GameBackgroundModule] 传入的 Sprite 为空，忽略切换。");
                return;
            }

            if (_instance == null)
            {
                return;
            }

            CollectSegments();
            foreach (SpriteRenderer renderer in _segments)
            {
                if (renderer != null)
                {
                    renderer.sprite = sprite;
                }
            }

            if (_segmentTemplate != null)
            {
                SpriteRenderer templateRenderer = _segmentTemplate.GetComponent<SpriteRenderer>();
                if (templateRenderer != null)
                {
                    templateRenderer.sprite = sprite;
                }
            }

            RebuildLayout();
        }

        public void SetTargetCamera(Camera camera)
        {
            _targetCamera = camera;
        }

        public async UniTask LoadAsync()
        {
            if (_isLoading || _instance != null)
            {
                return;
            }

            if (!_resourceManager.IsInitialized)
            {
                Log.Warning("[GameBackgroundModule] 资源管理器未初始化，无法加载背景。");
                return;
            }

            _isLoading = true;
            try
            {
                AssetHandle handle = await _resourceManager.LoadAssetAsync<GameObject>(_prefabName);
                GameObject prefab = handle.AssetObject as GameObject;
                if (prefab == null)
                {
                    Log.Error($"[GameBackgroundModule] 背景预制体加载失败：{_prefabName}");
                    _resourceManager.Release(handle);
                    return;
                }

                GameObject instance = UnityEngine.Object.Instantiate(prefab);
                instance.name = "Background";

                GameObject root = GameObject.Find(BackgroundRootName);
                if (root != null)
                {
                    instance.transform.SetParent(root.transform, false);
                }
                else
                {
                    Log.Warning($"[GameBackgroundModule] 未找到 {BackgroundRootName}，背景将挂在场景根节点。");
                }

                _handle = handle;
                _instance = instance;

                RebuildLayout();
            }
            finally
            {
                _isLoading = false;
            }
        }

        public override void Update(float elapseSeconds, float realElapseSeconds)
        {
            if (!_isReady || _segments.Count == 0)
            {
                return;
            }

            if (Mathf.Approximately(_speed, 0f))
            {
                return;
            }

            float delta = _speed * elapseSeconds;
            Vector3 move = Vector3.down * delta;
            for (int i = 0; i < _segments.Count; i++)
            {
                SpriteRenderer renderer = _segments[i];
                if (renderer == null)
                {
                    continue;
                }

                renderer.transform.position += move;
            }

            Camera camera = ResolveCamera();
            if (camera == null)
            {
                return;
            }

            float depth = GetCameraDepth(camera);

            if (_speed > 0f)
            {
                float bottomY = GetCameraBottomY(camera, depth);
                for (int i = 0; i < _segments.Count; i++)
                {
                    SpriteRenderer renderer = _segments[i];
                    if (renderer == null)
                    {
                        continue;
                    }

                    if (renderer.bounds.max.y < bottomY)
                    {
                        RepositionSegment(i, _totalHeight);
                    }
                }
            }
            else
            {
                float topY = GetCameraTopY(camera, depth);
                for (int i = 0; i < _segments.Count; i++)
                {
                    SpriteRenderer renderer = _segments[i];
                    if (renderer == null)
                    {
                        continue;
                    }

                    if (renderer.bounds.min.y > topY)
                    {
                        RepositionSegment(i, -_totalHeight);
                    }
                }
            }
        }

        public override void Shutdown()
        {
            _isReady = false;
            _segments.Clear();
            _spawnedClone = false;
            _segmentHeight = 0f;
            _totalHeight = 0f;
            _segmentTemplate = null;
            _registeredSegments.Clear();

            if (!string.IsNullOrWhiteSpace(_segmentPoolName))
            {
                _objectPoolManager.DestroyPool<GameObject>(_segmentPoolName);
                _segmentPoolName = null;
                _segmentPool = null;
            }

            if (_instance != null)
            {
                UnityEngine.Object.Destroy(_instance);
                _instance = null;
            }

            if (_handle != null)
            {
                _resourceManager.Release(_handle);
                _handle = null;
            }
        }

        private void RebuildLayout()
        {
            _isReady = false;
            CollectSegments();

            if (_segments.Count == 0)
            {
                Log.Warning("[GameBackgroundModule] 未找到 SpriteRenderer，无法初始化。");
                return;
            }

            SpriteRenderer reference = _segments.FirstOrDefault(renderer => renderer != null && renderer.sprite != null);
            if (reference == null)
            {
                Log.Warning("[GameBackgroundModule] 未找到有效的 SpriteRenderer，无法计算高度。");
                return;
            }

            _segmentHeight = reference.bounds.size.y;
            if (_segmentHeight <= 0f)
            {
                Log.Warning("[GameBackgroundModule] SpriteRenderer 高度为 0，无法初始化。");
                return;
            }

            EnsureSegmentCoverage(reference);

            List<SpriteRenderer> ordered = _segments
                .Where(renderer => renderer != null)
                .OrderBy(renderer => renderer.transform.position.y)
                .ToList();
            if (ordered.Count == 0)
            {
                Log.Warning("[GameBackgroundModule] 未找到有效的 SpriteRenderer，无法初始化。");
                return;
            }

            Vector3 basePosition = ordered[0].transform.position;
            for (int i = 0; i < ordered.Count; i++)
            {
                SpriteRenderer renderer = ordered[i];
                Vector3 position = renderer.transform.position;
                position.x = basePosition.x;
                position.z = basePosition.z;
                position.y = basePosition.y + _segmentHeight * i;
                renderer.transform.position = position;
            }

            _segments.Clear();
            _segments.AddRange(ordered);
            _totalHeight = _segmentHeight * _segments.Count;
            _isReady = true;
        }

        private void EnsureSegmentCoverage(SpriteRenderer reference)
        {
            Camera camera = ResolveCamera();
            int requiredCount = CalculateRequiredSegmentCount(camera);
            if (requiredCount <= _segments.Count || reference == null)
            {
                return;
            }

            EnsureSegmentPool(reference);
            Transform parent = reference.transform.parent;
            for (int i = _segments.Count; i < requiredCount; i++)
            {
                GameObject instance = _segmentPool != null
                    ? _segmentPool.Spawn()
                    : UnityEngine.Object.Instantiate(reference.gameObject, parent, false);

                instance.transform.SetParent(parent, false);
                instance.name = $"{reference.gameObject.name}_Clone_{i}";

                SpriteRenderer renderer = instance.GetComponent<SpriteRenderer>();
                if (renderer == null)
                {
                    continue;
                }

                if (reference.sprite != null && renderer.sprite != reference.sprite)
                {
                    renderer.sprite = reference.sprite;
                }

                _segments.Add(renderer);
                RegisterSegment(renderer);
            }
        }

        private int CalculateRequiredSegmentCount(Camera camera)
        {
            if (_segmentHeight <= 0f || camera == null)
            {
                return _segments.Count;
            }

            float depth = GetCameraDepth(camera);
            float viewHeight = Mathf.Abs(GetCameraTopY(camera, depth) - GetCameraBottomY(camera, depth));
            if (viewHeight <= 0f)
            {
                return _segments.Count;
            }

            int required = Mathf.CeilToInt(viewHeight / _segmentHeight) + 1;
            return Mathf.Max(required, 2);
        }

        private void CollectSegments()
        {
            _segments.Clear();
            if (_instance == null)
            {
                return;
            }

            SpriteRenderer[] renderers = _instance.GetComponentsInChildren<SpriteRenderer>(true);
            foreach (SpriteRenderer renderer in renderers)
            {
                if (renderer != null && renderer.gameObject.activeInHierarchy)
                {
                    _segments.Add(renderer);
                }
            }

            if (_segments.Count > 0)
            {
                EnsureSegmentPool(_segments[0]);
                RegisterSegments();
            }

            if (_segments.Count == 1 && _autoCloneIfSingle)
            {
                TryCloneSegment(_segments[0]);
                _segments.Clear();
                renderers = _instance.GetComponentsInChildren<SpriteRenderer>(true);
                foreach (SpriteRenderer renderer in renderers)
                {
                    if (renderer != null && renderer.gameObject.activeInHierarchy)
                    {
                        _segments.Add(renderer);
                    }
                }

                RegisterSegments();
            }
        }

        private void TryCloneSegment(SpriteRenderer source)
        {
            if (source == null || _spawnedClone)
            {
                return;
            }

            EnsureSegmentPool(source);
            RegisterSegment(source);

            if (_segmentPool == null)
            {
                GameObject clone = UnityEngine.Object.Instantiate(source.gameObject, source.transform.parent);
                clone.name = $"{source.gameObject.name}_Clone";
                _spawnedClone = true;
                return;
            }

            GameObject cloneInstance = _segmentPool.Spawn();
            cloneInstance.transform.SetParent(source.transform.parent, false);
            cloneInstance.name = $"{source.gameObject.name}_Clone";
            _registeredSegments.Add(cloneInstance);
            _spawnedClone = true;
        }

        private void EnsureSegmentPool(SpriteRenderer templateRenderer)
        {
            if (_segmentPool != null)
            {
                return;
            }

            if (templateRenderer == null || _objectPoolManager == null)
            {
                return;
            }

            _segmentTemplate = templateRenderer.gameObject;
            if (string.IsNullOrWhiteSpace(_segmentPoolName))
            {
                _segmentPoolName = $"{SegmentPoolNamePrefix}_{_prefabName}_{GetHashCode()}";
            }

            if (_objectPoolManager.TryGetPool<GameObject>(_segmentPoolName, out IObjectPool<GameObject> existingPool))
            {
                _segmentPool = existingPool;
                return;
            }

            var options = new ObjectPoolOptions
            {
                AllowMultiSpawn = false,
                AutoRelease = false
            };

            _segmentPool = _objectPoolManager.CreatePool(
                _segmentPoolName,
                CreateSegmentInstance,
                options,
                OnSegmentSpawn,
                OnSegmentRecycle,
                OnSegmentDestroy);
        }

        private GameObject CreateSegmentInstance()
        {
            if (_segmentTemplate == null)
            {
                throw new InvalidOperationException("背景片段模板为空，无法创建实例");
            }

            GameObject clone = UnityEngine.Object.Instantiate(_segmentTemplate, _segmentTemplate.transform.parent, false);
            clone.name = $"{_segmentTemplate.name}_Pooled";
            clone.SetActive(false);
            return clone;
        }

        private void RegisterSegments()
        {
            foreach (SpriteRenderer renderer in _segments)
            {
                RegisterSegment(renderer);
            }
        }

        private void RegisterSegment(SpriteRenderer renderer)
        {
            if (_segmentPool == null || renderer == null)
            {
                return;
            }

            GameObject target = renderer.gameObject;
            if (target == null || _registeredSegments.Contains(target))
            {
                return;
            }

            if (_segmentPool.Contains(target))
            {
                _registeredSegments.Add(target);
                return;
            }

            _segmentPool.Register(target, spawned: true);
            _registeredSegments.Add(target);
        }

        private void OnSegmentSpawn(GameObject instance)
        {
            if (instance != null)
            {
                instance.SetActive(true);
            }
        }

        private void OnSegmentRecycle(GameObject instance)
        {
            if (instance != null)
            {
                instance.SetActive(false);
            }
        }

        private void OnSegmentDestroy(GameObject instance)
        {
            if (instance != null)
            {
                UnityEngine.Object.Destroy(instance);
            }
        }

        private void RepositionSegment(int index, float offsetY)
        {
            SpriteRenderer renderer = _segments[index];
            if (renderer == null)
            {
                return;
            }

            Vector3 targetPosition = renderer.transform.position;
            targetPosition.y += offsetY;

            if (_segmentPool == null)
            {
                renderer.transform.position = targetPosition;
                return;
            }

            GameObject source = renderer.gameObject;
            if (source == null || !_registeredSegments.Contains(source))
            {
                renderer.transform.position = targetPosition;
                return;
            }

            _segmentPool.Recycle(source);
            GameObject spawned = _segmentPool.Spawn();
            if (spawned == null)
            {
                renderer.transform.position = targetPosition;
                return;
            }

            spawned.transform.SetParent(source.transform.parent, false);
            spawned.transform.position = targetPosition;

            SpriteRenderer spawnedRenderer = spawned.GetComponent<SpriteRenderer>();
            if (spawnedRenderer == null)
            {
                renderer.transform.position = targetPosition;
                return;
            }

            if (renderer.sprite != null && spawnedRenderer.sprite != renderer.sprite)
            {
                spawnedRenderer.sprite = renderer.sprite;
            }

            _segments[index] = spawnedRenderer;
            _registeredSegments.Add(spawned);
        }

        private Camera ResolveCamera()
        {
            if (_targetCamera != null)
            {
                return _targetCamera;
            }

            return Camera.main;
        }

        private float GetCameraDepth(Camera camera)
        {
            if (camera == null)
            {
                return 0f;
            }

            Vector3 referencePosition = _instance != null ? _instance.transform.position : Vector3.zero;
            if (_segments.Count > 0 && _segments[0] != null)
            {
                referencePosition = _segments[0].transform.position;
            }

            float depth = Vector3.Dot(referencePosition - camera.transform.position, camera.transform.forward);
            if (depth < camera.nearClipPlane)
            {
                depth = camera.nearClipPlane;
            }

            return depth;
        }

        private static float GetCameraBottomY(Camera camera, float depth)
        {
            Vector3 bottom = camera.ViewportToWorldPoint(new Vector3(0f, 0f, depth));
            return bottom.y;
        }

        private static float GetCameraTopY(Camera camera, float depth)
        {
            Vector3 top = camera.ViewportToWorldPoint(new Vector3(0f, 1f, depth));
            return top.y;
        }
    }
}
