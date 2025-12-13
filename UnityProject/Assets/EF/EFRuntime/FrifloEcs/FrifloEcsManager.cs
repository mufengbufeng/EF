using System;
using System.Collections.Generic;
using EF.Common;
using Friflo.Engine.ECS;
using Friflo.Engine.ECS.Systems;

namespace EF.FrifloEcs
{
    /// <summary>
    /// Friflo ECS 管理器：封装多个 EntityStore 与 SystemRoot 的统一管理与调度。
    /// </summary>
    public sealed class FrifloEcsManager : AEFManager, IFrifloEcsManager
    {
        private readonly Dictionary<string, EntityStore> _stores = new(StringComparer.Ordinal);
        private readonly SystemRoot _root;
        private string _defaultStoreName;
        private float _accumulatedTime;

        /// <summary>
        /// 创建一个带默认世界的 ECS 管理器。
        /// </summary>
        /// <param name="defaultStoreName">默认世界名称。</param>
        public FrifloEcsManager(string defaultStoreName = "Default")
        {
            if (string.IsNullOrWhiteSpace(defaultStoreName))
            {
                throw new ArgumentException("Default store name cannot be null or empty.", nameof(defaultStoreName));
            }

            EntityStore defaultStore = new();
            _stores[defaultStoreName] = defaultStore;
            _defaultStoreName = defaultStoreName;

            _root = new SystemRoot(defaultStore, "EF.SystemRoot");
        }

        /// <summary>
        /// 获取当前被标记为默认的实体世界，供大多数游戏系统直接使用。
        /// </summary>
        public EntityStore DefaultStore => _stores[_defaultStoreName];

        /// <summary>
        /// 获取内部维护的 SystemRoot，可用于添加复杂的系统层级或启用性能监控。
        /// </summary>
        public SystemRoot Root => _root;

        /// <summary>
        /// 获取所有由管理器维护的实体世界集合，键为唯一名称。
        /// </summary>
        public IReadOnlyDictionary<string, EntityStore> Stores => _stores;

        /// <summary>
        /// 创建一个新的实体世界并自动加入系统根节点进行调度。
        /// </summary>
        /// <param name="name">世界名称，需在当前管理器内唯一。</param>
        /// <returns>新创建的 <see cref="EntityStore"/> 实例。</returns>
        public EntityStore CreateStore(string name)
        {
            if (string.IsNullOrWhiteSpace(name))
            {
                throw new ArgumentException("Store name cannot be null or empty.", nameof(name));
            }

            if (_stores.ContainsKey(name))
            {
                throw new InvalidOperationException($"Store '{name}' already exists.");
            }

            EntityStore store = new();
            _stores.Add(name, store);
            _root.AddStore(store);
            return store;
        }

        /// <summary>
        /// 将外部创建的实体世界纳入管理，可选设置为默认世界。
        /// </summary>
        /// <param name="name">唯一的世界名称。</param>
        /// <param name="store">需要托管的 <see cref="EntityStore"/> 实例。</param>
        /// <param name="setAsDefault">是否将该世界标记为默认世界。</param>
        public void AddStore(string name, EntityStore store, bool setAsDefault = false)
        {
            if (string.IsNullOrWhiteSpace(name))
            {
                throw new ArgumentException("Store name cannot be null or empty.", nameof(name));
            }

            if (store == null)
            {
                throw new ArgumentNullException(nameof(store));
            }

            if (_stores.ContainsKey(name))
            {
                throw new InvalidOperationException($"Store '{name}' already exists.");
            }

            _stores.Add(name, store);
            _root.AddStore(store);

            if (setAsDefault)
            {
                _defaultStoreName = name;
            }
        }

        /// <summary>
        /// 根据名称尝试获取实体世界，找不到时返回 <c>false</c>。
        /// </summary>
        /// <param name="name">要查询的世界名称。</param>
        /// <param name="store">若存在则返回对应实例，缺失则为 <c>null</c>。</param>
        public bool TryGetStore(string name, out EntityStore store)
        {
            if (string.IsNullOrEmpty(name))
            {
                store = null;
                return false;
            }

            return _stores.TryGetValue(name, out store);
        }

        /// <summary>
        /// 判断当前管理器是否包含指定名称的实体世界。
        /// </summary>
        public bool ContainsStore(string name)
        {
            return !string.IsNullOrEmpty(name) && _stores.ContainsKey(name);
        }

        /// <summary>
        /// 移除指定名称的实体世界并从系统根节点解绑，默认世界不允许移除。
        /// </summary>
        /// <param name="name">需要移除的世界名称。</param>
        /// <returns>成功移除返回 <c>true</c>，否则为 <c>false</c>。</returns>
        public bool RemoveStore(string name)
        {
            if (string.IsNullOrEmpty(name))
            {
                return false;
            }

            if (!_stores.TryGetValue(name, out EntityStore store))
            {
                return false;
            }

            if (ReferenceEquals(store, DefaultStore))
            {
                throw new InvalidOperationException("Cannot remove default EntityStore.");
            }

            _root.RemoveStore(store);
            return _stores.Remove(name);
        }

        /// <summary>
        /// 向 SystemRoot 追加一个系统，按追加顺序参与帧更新。
        /// </summary>
        /// <param name="system">需要调度的系统实例。</param>
        public void AddSystem(BaseSystem system)
        {
            if (system == null)
            {
                throw new ArgumentNullException(nameof(system));
            }

            _root.Add(system);
        }

        /// <summary>
        /// 在指定索引位置插入一个系统，可用于精确控制执行顺序。
        /// </summary>
        /// <param name="index">插入索引，-1 表示追加到末尾。</param>
        /// <param name="system">系统实例。</param>
        public void InsertSystem(int index, BaseSystem system)
        {
            if (system == null)
            {
                throw new ArgumentNullException(nameof(system));
            }

            _root.Insert(index, system);
        }

        /// <summary>
        /// 从 SystemRoot 中移除一个系统，若系统为空则忽略。
        /// </summary>
        /// <param name="system">需要移除的系统实例。</param>
        public void RemoveSystem(BaseSystem system)
        {
            if (system == null)
            {
                return;
            }

            _root.Remove(system);
        }

        /// <summary>
        /// 开启或关闭 Friflo 内置的系统性能监控，便于调试和性能分析。
        /// </summary>
        /// <param name="enabled">为 <c>true</c> 时启用性能统计。</param>
        public void SetPerformanceMonitoring(bool enabled)
        {
            _root.SetMonitorPerf(enabled);
        }

        /// <summary>
        /// Unity 生命周期每帧回调，驱动 SystemRoot 执行所有系统。
        /// </summary>
        public override void Update(float elapseSeconds, float realElapseSeconds)
        {
            _accumulatedTime += elapseSeconds;
            var tick = new UpdateTick(elapseSeconds, _accumulatedTime);
            _root.Update(tick);
        }

        /// <summary>
        /// 关闭 ECS 管理器并清理内部状态。
        /// </summary>
        public override void Shutdown()
        {
            var stores = _root.Stores;
            for (int i = stores.Count - 1; i >= 0; i--)
            {
                _root.RemoveStore(stores[i]);
            }

            _stores.Clear();
            _accumulatedTime = 0f;
        }
    }
}
