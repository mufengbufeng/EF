# Entity Module Design

## Context

游戏开发中需要大量动态创建和销毁的游戏对象，如角色、敌人、道具、特效等。这些对象具有以下特点：
- 生命周期管理：创建、显示、隐藏、回收
- 资源加载：需要从 AssetBundle 异步加载 Prefab
- 对象池复用：频繁创建销毁的对象应该使用对象池
- 层级关系：实体之间可能存在父子关系（如角色装备的武器）

EF 框架目前已有 ObjectPool 和 ResourceManager 模块，但缺少统一的实体管理层来协调这些功能。

## Goals / Non-Goals

### Goals
- 提供统一的实体生命周期管理 API
- 自动集成对象池，减少手动管理成本
- 支持异步资源加载，与 YooAsset 无缝集成
- 支持实体分组管理，不同类型实体使用独立对象池
- 支持实体父子层级关系
- 与 EF 框架现有设计风格一致

### Non-Goals
- 实现具体的游戏逻辑（由游戏层继承 EntityBase 实现）
- 实体持久化保存（由 Save 模块负责）
- 网络同步（由游戏层自行实现）

## Decisions

### 1. 命名空间设计

使用 `EF.Entity` 命名空间，与 EF 框架其他模块保持一致。

### 2. 接口层次结构

```
IEntity                    - 实体接口
  └── EntityBase           - 抽象基类（可选继承）

IEntityGroup               - 实体组接口（管理同类型实体的对象池）
  └── EntityGroup          - 实现类

IEntityManager             - 实体管理器接口
  └── EntityManager        - 实现类

IEntityHelper              - 实例化辅助接口（需游戏层实现）
```

### 3. 与现有模块的集成

- **ObjectPool**: 每个实体组内部维护一个对象池，使用 `IObjectPoolManager` 创建
- **Resource**: 使用 `IResourceManager.LoadAssetAsync<GameObject>()` 加载实体 Prefab

### 4. 简化设计 vs Game Framework

相比参考的 Game Framework，我们做以下简化：
- 使用 UniTask 替代事件回调模式
- 移除依赖资源加载事件（简化设计，按需添加）
- 使用更简洁的 API 设计

### 5. 实体 ID 生成

使用 `InternalId` 模式生成唯一实体 ID：
```
EntityId = (SerialId << 16) | (GroupIndex & 0xFFFF)
```
其中 SerialId 每次创建实体递增，GroupIndex 为实体组索引。

## Architecture

```
┌─────────────────────────────────────────────────────────┐
│                     EntityManager                       │
│  - ShowEntity(entityId, assetName, groupName, ...)      │
│  - HideEntity(entityId)                                 │
│  - AttachEntity/DetachEntity                            │
└──────────────┬──────────────────────────────────────────┘
               │
               ├──► EntityGroup (Name: "Enemy")
               │    └── ObjectPool<EnemyEntity>
               │
               └──► EntityGroup (Name: "Player")
                    └── ObjectPool<PlayerEntity>
```

## Class Structure

### IEntity
```csharp
public interface IEntity
{
    int Id { get; }
    string EntityAssetName { get; }
    GameObject Handle { get; }
    IEntityGroup EntityGroup { get; }

    void OnInit(int entityId, string entityAssetName, IEntityGroup entityGroup, bool isNewInstance, object userData);
    void OnRecycle();
    void OnShow(object userData);
    void OnHide(bool isShutdown, object userData);
    void OnAttached(IEntity childEntity, object userData);
    void OnDetached(IEntity childEntity, object userData);
    void OnAttachTo(IEntity parentEntity, object userData);
    void OnDetachFrom(IEntity parentEntity, object userData);
    void OnUpdate(float elapseSeconds, float realElapseSeconds);
}
```

### IEntityGroup
```csharp
public interface IEntityGroup
{
    string Name { get; }
    int EntityCount { get; }
    IObjectPool<IEntity> EntityPool { get; }

    IEntity SpawnEntity();
    void RecycleEntity(IEntity entity);
    void Release();
}
```

### IEntityManager
```csharp
public interface IEntityManager : IEFManager
{
    int EntityCount { get; }
    int EntityGroupCount { get; }

    void SetObjectPoolManager(IObjectPoolManager objectPoolManager);
    void SetResourceManager(IResourceManager resourceManager);
    void SetEntityHelper(IEntityHelper entityHelper);

    bool HasEntityGroup(string name);
    IEntityGroup GetEntityGroup(string name);
    bool AddEntityGroup(string name, EntityGroupOptions options);
    void RemoveEntityGroup(string name);

    bool HasEntity(int entityId);
    IEntity GetEntity(int entityId);
    IEntity[] GetAllLoadedEntities();

    UniTask<IEntity> ShowEntityAsync(int entityId, string entityAssetName, string groupName, object userData = null);
    void HideEntity(int entityId);
    void HideAllLoadedEntities();

    void AttachEntity(int childEntityId, int parentEntityId, object userData = null);
    void DetachEntity(int childEntityId, object userData = null);
}
```

## Risks / Trade-offs

| Risk | Mitigation |
|------|-----------|
| 实体创建时加载资源可能导致延迟 | 提供预热接口，允许在适当时机预加载 |
| 大量实体同时创建可能卡顿 | 提供优先级参数和进度回调 |
| 实体层级循环引用 | AttachEntity 时检测循环引用并抛出异常 |

## Migration Plan

- 这是一个纯新增模块，无需迁移现有代码
- 游戏代码可以逐步从直接 GameObject.Instantiate 迁移到 EntityManager

## Open Questions

1. 是否需要支持实体显示/隐藏的事件通知？
   - **决策**: 初始版本不包含事件，按需添加
2. 是否需要支持实体模板（Variant）？
   - **决策**: 不支持，使用不同的 entityAssetName 区分
3. 实体 Update 是否可选？
   - **决策**: IEntity 包含 OnUpdate，但默认实现为空
