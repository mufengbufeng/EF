## MODIFIED Requirements
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
