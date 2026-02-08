# entity-lifecycle-guarantee Specification

## Purpose
Ensure that entity Handle property is properly initialized before any lifecycle callbacks are invoked, preventing null reference errors during entity initialization. This specification guarantees that entities can safely access their GameObject through the Handle property in OnInit and OnShow methods.
## Requirements
### Requirement: Entity Manager

系统 SHALL 提供 `IEntityManager` 接口，管理所有实体的创建、显示、隐藏和层级关系。

#### Scenario: Show entity asynchronously with Handle guarantee
- **WHEN** 调用 `ShowEntityAsync(entityId, entityAssetName, groupName, userData)` 时
- **THEN** 从对象池获取实体实例
- **AND** 若实体已有 Handle（GameObject），直接复用，不重新加载和实例化
- **AND** 若实体无 Handle，使用 `IResourceManager` 异步加载实体资源（按资源名缓存 AssetHandle，同名资源只加载一次）
- **AND** 加载完成后实例化 GameObject
- **AND** **立即设置实体的 Handle 属性指向实例化的 GameObject**
- **AND** 调用实体的 `OnInit()` 时 Handle 已经可用
- **AND** 调用实体的 `OnShow()` 时 Handle 已经可用
- **AND** 返回 `UniTask<IEntity>`

#### Scenario: AssetHandle lifecycle management
- **WHEN** EntityManager 首次加载某实体资源时
- **THEN** 缓存该资源的 `AssetHandle`，避免重复加载
- **AND** 在 `Shutdown()` 时释放所有缓存的 `AssetHandle`

#### Scenario: Generate unique entity ID
- **WHEN** 外部模块需要创建实体时
- **THEN** 可通过 `IEntityManager.GenerateEntityId()` 获取全局唯一的实体 ID
- **AND** 不与内部 ID 生成逻辑冲突

### Requirement: Entity Base Class

系统 SHALL 提供 `EntityBase` 抽象类，简化实体实现。

#### Scenario: Handle availability during lifecycle
- **WHEN** 实体的 `OnInit` 或 `OnShow` 方法被调用时
- **THEN** `Handle` 属性必须已经被设置为非 null 值
- **AND** 实体可以安全地访问 `Handle.transform`、`Handle.GetComponent<T>()` 等方法
- **AND** 不需要进行 null 检查

#### Scenario: Handle property access in OnShow
- **GIVEN** 实体继承自 `EntityBase`
- **WHEN** `OnShow(userData)` 被调用时
- **THEN** 实体可以直接使用 `Handle.SetActive(true)`
- **AND** 实体可以直接使用 `Handle.GetComponent<T>()`
- **AND** 实体可以直接使用 `Handle.transform.position = value`
- **AND** 所有 Handle 相关操作不会抛出 `NullReferenceException`

---

