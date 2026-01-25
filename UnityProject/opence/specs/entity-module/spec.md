# entity-module Specification

## Purpose
TBD - created by archiving change add-entity-module. Update Purpose after archive.
## Requirements
### Requirement: Entity Interface

系统 SHALL 提供 `IEntity` 接口，定义实体的生命周期和层级关系回调。

#### Scenario: Entity initialization
- **WHEN** 实体被创建或从对象池取出时
- **THEN** 调用 `OnInit(entityId, entityAssetName, entityGroup, isNewInstance, userData)`
- **AND** `isNewInstance` 为 true 表示新创建，false 表示从对象池复用

#### Scenario: Entity show
- **WHEN** 实体需要显示给玩家时
- **THEN** 调用 `OnShow(userData)` 进行业务初始化
- **AND** 实体的 GameObject 被激活

#### Scenario: Entity hide
- **WHEN** 实体需要隐藏时
- **THEN** 调用 `OnHide(isShutdown, userData)`
- **AND** 实体的 GameObject 被停用
- **AND** 如果不是关闭管理器触发，实体回收到对象池

#### Scenario: Entity recycle
- **WHEN** 实体回收到对象池时
- **THEN** 调用 `OnRecycle()` 清理状态

#### Scenario: Entity update
- **WHEN** 每帧 Unity Update 时
- **THEN** 调用所有已显示实体的 `OnUpdate(elapseSeconds, realElapseSeconds)`

#### Scenario: Child entity attached
- **WHEN** 子实体附加到当前实体时
- **THEN** 调用父实体的 `OnAttached(childEntity, userData)`
- **AND** 调用子实体的 `OnAttachTo(parentEntity, userData)`

#### Scenario: Child entity detached
- **WHEN** 子实体从当前实体解除时
- **THEN** 调用父实体的 `OnDetached(childEntity, userData)`
- **AND** 调用子实体的 `OnDetachFrom(parentEntity, userData)`

---

### Requirement: Entity Group

系统 SHALL 提供 `IEntityGroup` 接口，管理同类型实体的对象池。

#### Scenario: Create entity group
- **WHEN** 调用 `AddEntityGroup(name, options)` 时
- **THEN** 创建一个新的实体组
- **AND** 使用 `IObjectPoolManager` 创建内部对象池
- **AND** 对象池使用 `options` 中的配置参数

#### Scenario: Spawn entity from group
- **WHEN** 调用实体组的 `SpawnEntity()` 时
- **THEN** 从内部对象池取出或创建新实体
- **AND** 返回 `IEntity` 实例

#### Scenario: Recycle entity to group
- **WHEN** 调用实体组的 `RecycleEntity(entity)` 时
- **THEN** 将实体回收到内部对象池
- **AND** 调用实体的 `OnRecycle()`

#### Scenario: Get entity group
- **WHEN** 调用 `GetEntityGroup(name)` 时
- **THEN** 返回指定名称的实体组
- **AND** 如果不存在则抛出异常

#### Scenario: Check entity group exists
- **WHEN** 调用 `HasEntityGroup(name)` 时
- **THEN** 返回该名称的实体组是否存在

---

### Requirement: Entity Manager

系统 SHALL 提供 `IEntityManager` 接口，管理所有实体的创建、显示、隐藏和层级关系。

#### Scenario: Show entity asynchronously
- **WHEN** 调用 `ShowEntityAsync(entityId, entityAssetName, groupName, userData)` 时
- **THEN** 使用 `IResourceManager` 异步加载实体资源
- **AND** 加载完成后从指定实体组获取实体实例
- **AND** 调用实体的 `OnInit()` 和 `OnShow()`
- **AND** 返回 `UniTask<IEntity>`

#### Scenario: Show entity with priority
- **WHEN** 调用 `ShowEntityAsync` 并指定 priority 参数时
- **THEN** 使用指定优先级加载资源
- **AND** 高优先级的实体优先加载

#### Scenario: Hide entity
- **WHEN** 调用 `HideEntity(entityId)` 时
- **THEN** 调用实体的 `OnHide(false, null)`
- **AND** 将实体回收到所属实体组

#### Scenario: Hide all loaded entities
- **WHEN** 调用 `HideAllLoadedEntities()` 时
- **THEN** 隐藏所有已加载的实体
- **AND** 将它们回收到各自的实体组

#### Scenario: Get entity by id
- **WHEN** 调用 `GetEntity(entityId)` 时
- **THEN** 返回对应的实体实例
- **AND** 如果实体不存在则返回 null

#### Scenario: Check entity exists
- **WHEN** 调用 `HasEntity(entityId)` 时
- **THEN** 返回该 ID 的实体是否已加载

#### Scenario: Get all loaded entities
- **WHEN** 调用 `GetAllLoadedEntities()` 时
- **THEN** 返回所有已加载实体的数组

---

### Requirement: Entity Hierarchy

系统 SHALL 支持实体之间的父子层级关系。

#### Scenario: Attach child entity
- **WHEN** 调用 `AttachEntity(childEntityId, parentEntityId, userData)` 时
- **THEN** 将子实体附加到父实体
- **AND** 调用父实体的 `OnAttached(childEntity, userData)`
- **AND** 调用子实体的 `OnAttachTo(parentEntity, userData)`
- **AND** 子实体的 Transform 成为父实体 Transform 的子对象

#### Scenario: Detect circular reference
- **WHEN** Attach 操作会导致循环引用时
- **THEN** 抛出 `InvalidOperationException`
- **AND** 不执行附加操作

#### Scenario: Detach child entity
- **WHEN** 调用 `DetachEntity(childEntityId, userData)` 时
- **THEN** 将子实体从父实体解除
- **AND** 调用父实体的 `OnDetached(childEntity, userData)`
- **AND** 调用子实体的 `OnDetachFrom(parentEntity, userData)`
- **AND** 子实体的 Transform 移到场景根节点

#### Scenario: Get parent entity
- **WHEN** 调用 `GetParentEntity(childEntityId)` 时
- **THEN** 返回子实体的父实体
- **AND** 如果没有父实体则返回 null

#### Scenario: Get child entities
- **WHEN** 调用 `GetChildEntities(parentEntityId)` 时
- **THEN** 返回父实体的所有直接子实体数组

---

### Requirement: Entity Helper

系统 SHALL 提供 `IEntityHelper` 接口，用于实例化实体 GameObject。

#### Scenario: Instantiate entity
- **WHEN** 资源加载完成后需要实例化实体时
- **THEN** 调用 `IEntityHelper.InstantiateEntity(asset)`
- **AND** 返回实例化的 GameObject
- **AND** 游戏层可以通过自定义 Helper 控制实例化逻辑

#### Scenario: Set entity helper
- **WHEN** 调用 `SetEntityHelper(helper)` 时
- **THEN** 设置管理器使用的实体辅助器
- **AND** 后续创建实体时使用新的辅助器

---

### Requirement: Entity Lifecycle Integration

系统 SHALL 与 EF 框架的生命周期系统集成。

#### Scenario: Manager update
- **WHEN** Unity 每帧 Update 时
- **THEN** 调用 `EntityManager.Update(elapseSeconds, realElapseSeconds)`
- **AND** 管理器更新所有已显示的实体

#### Scenario: Manager shutdown
- **WHEN** 游戏关闭或管理器被销毁时
- **THEN** 调用 `EntityManager.Shutdown()`
- **AND** 隐藏所有已加载的实体（isShutdown = true）
- **AND** 释放所有实体组
- **AND** 清空内部缓存

#### Scenario: Set dependency managers
- **WHEN** 调用 `SetObjectPoolManager(manager)` 时
- **THEN** 设置对象池管理器依赖
- **WHEN** 调用 `SetResourceManager(manager)` 时
- **THEN** 设置资源管理器依赖

---

### Requirement: Entity Base Class

系统 SHALL 提供 `EntityBase` 抽象类，简化实体实现。

#### Scenario: Default implementation
- **WHEN** 游戏代码继承 `EntityBase` 时
- **THEN** 自动实现 `IEntity` 的基本属性（Id, EntityAssetName, Handle, EntityGroup）
- **AND** 提供空的回调方法供子类选择性重写

#### Scenario: Lifecycle hooks
- **WHEN** 子类继承 `EntityBase` 时
- **THEN** 可以重写 `OnInit`, `OnShow`, `OnHide`, `OnRecycle` 等方法
- **AND** 可以重写 `OnUpdate` 实现每帧逻辑

