using System.Collections.Generic;
using EF.Common;
using Friflo.Engine.ECS;
using Friflo.Engine.ECS.Systems;

namespace EF.FrifloEcs
{
    /// <summary>
    /// 提供对 Friflo ECS 的统一管理入口，负责 EntityStore 与 SystemRoot 的生命周期和更新调度。
    /// </summary>
    public interface IFrifloEcsManager : IEFManager
    {
        /// <summary>
        /// 默认实体世界，用于大多数游戏逻辑。
        /// </summary>
        EntityStore DefaultStore { get; }

        /// <summary>
        /// 系统根节点，内部维护完整的系统层级结构。
        /// </summary>
        SystemRoot Root { get; }

        /// <summary>
        /// 当前已注册的所有实体世界。
        /// </summary>
        IReadOnlyDictionary<string, EntityStore> Stores { get; }

        /// <summary>
        /// 创建并注册一个新的实体世界。
        /// </summary>
        /// <param name="name">世界名称，需在管理器内唯一。</param>
        /// <returns>新创建的实体世界。</returns>
        EntityStore CreateStore(string name);

        /// <summary>
        /// 将外部创建的实体世界纳入管理。
        /// </summary>
        /// <param name="name">世界名称，需在管理器内唯一。</param>
        /// <param name="store">待注册的实体世界实例。</param>
        /// <param name="setAsDefault">是否将该世界设置为默认世界。</param>
        void AddStore(string name, EntityStore store, bool setAsDefault = false);

        /// <summary>
        /// 尝试获取指定名称的实体世界。
        /// </summary>
        bool TryGetStore(string name, out EntityStore store);

        /// <summary>
        /// 检查是否包含指定名称的实体世界。
        /// </summary>
        bool ContainsStore(string name);

        /// <summary>
        /// 移除并注销指定名称的实体世界（默认世界不允许移除）。
        /// </summary>
        bool RemoveStore(string name);

        /// <summary>
        /// 向系统根节点追加一个系统，按追加顺序参与更新。
        /// </summary>
        void AddSystem(BaseSystem system);

        /// <summary>
        /// 在指定索引位置插入一个系统，控制更新顺序。
        /// </summary>
        void InsertSystem(int index, BaseSystem system);

        /// <summary>
        /// 从系统根节点移除一个系统。
        /// </summary>
        void RemoveSystem(BaseSystem system);

        /// <summary>
        /// 控制是否开启系统性能监控。
        /// </summary>
        void SetPerformanceMonitoring(bool enabled);
    }
}