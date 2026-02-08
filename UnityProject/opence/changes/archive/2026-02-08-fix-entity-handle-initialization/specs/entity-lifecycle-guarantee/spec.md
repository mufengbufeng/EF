# entity-lifecycle-guarantee Specification

## Purpose
Ensure that entity Handle property is properly initialized before any lifecycle callbacks are invoked, preventing null reference errors during entity initialization.

## ADDED Requirements

### Requirement: Entity Manager

系统 SHALL 提供 `IEntityManager` 接口，管理所有实体的创建、显示、隐藏和层级关系。

#### Scenario: Show entity asynchronously with Handle guarantee
- **WHEN** 调用 `ShowEntityAsync(entityId, entityAssetName, groupName, userData)` 时
- **THEN** 使用 `IResourceManager` 异步加载实体资源
- **AND** 加载完成后实例化 GameObject
- **AND** **立即设置实体的 Handle 属性指向实例化的 GameObject**
- **AND** 从指定实体组获取实体实例
- **AND** 调用实体的 `OnInit()` 时 Handle 已经可用
- **AND** 调用实体的 `OnShow()` 时 Handle 已经可用
- **AND** 返回 `UniTask<IEntity>`

---

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

## Notes

### Related Specifications

- **entity-module**: Core entity lifecycle specification
- **game-enemy-module**: Enemy entity implementation that depends on Handle availability

### Implementation Notes

The fix involves reordering operations in `EntityManager.ShowEntityAsync`:
1. Load entity asset
2. Instantiate GameObject
3. **Set Handle property** (moved before OnInit)
4. Call OnInit
5. Register entity
6. Call OnShow

This ensures Handle is available throughout the entire entity lifecycle.
