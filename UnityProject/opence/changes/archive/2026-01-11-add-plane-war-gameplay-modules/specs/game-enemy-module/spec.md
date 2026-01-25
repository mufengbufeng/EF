## ADDED Requirements

### Requirement: GameEnemyModule 负责敌机生成与回收

系统 SHALL 提供 `GameEnemyModule`（及其服务接口 `IGameEnemyModule`），用于在玩法运行期间生成敌机并在退出玩法时清理。  
在最小实现阶段，`GameEnemyModule` SHOULD 支持按固定时间间隔生成敌机，并维护其生成记录以便统一回收。

#### Scenario: 场景就绪后开始刷怪

**Given** `GamePlayProcedure` 已进入且玩法场景就绪  
**And** 调用方已通过模块接口提供敌机的 `entityAssetName` 与 `groupName`  
**When** `GamePlayProcedure` 启动 `GameEnemyModule` 的刷怪流程  
**Then** `GameEnemyModule` 在后续更新中按规则生成敌机  
**And** 每个生成的敌机被记录用于后续回收

### Requirement: GameEnemyModule 使用 EntityManager（推荐默认方案）

系统 SHALL 默认采用 `EF.Entity.IEntityManager` 作为敌机生成与回收的实现基础。  
当项目启用 `EF.Entity.IEntityManager` 时，`GameEnemyModule` MUST 使用 `IEntityManager.ShowEntityAsync(...)` 生成敌机，并在退出玩法时通过 `HideEntity(...)` 或 `HideAllLoadedEntities()` 回收敌机。  
`GameEnemyModule` MUST NOT 在模块内部硬编码敌机的 `entityAssetName` 与 `groupName`；这些参数 MUST 由调用方通过模块接口参数传入，或由外部注入/配置提供。

#### Scenario: 通过 IEntityManager 生成并回收敌机

**Given** `IEntityManager` 已在 `ModuleSystem` 中注册且可被获取  
**When** `GameEnemyModule` 需要生成敌机  
**Then** `GameEnemyModule` 调用 `IEntityManager.ShowEntityAsync(entityId, entityAssetName, groupName, userData)`  
**And** 在 `Shutdown()` 时回收本模块生成的敌机并清空内部记录

### Requirement: GameEnemyModule 受 ModuleSystem scope 管理

`GameEnemyModule` MUST 以“玩法作用域（GamePlay scope）”注册到 `EF.Common.ModuleSystem`，并在调用 `ModuleSystem.ShutdownScope(GamePlayScope)` 时被注销并执行 `Shutdown()`。  
`Shutdown()` MUST 停止刷怪、回收敌机并保持幂等。

#### Scenario: 退出玩法时清理敌机模块

**Given** `GameEnemyModule` 已以 `scope = GamePlayScope` 注册到 `ModuleSystem` 且已生成若干敌机  
**When** `GamePlayProcedure` 退出并调用 `ModuleSystem.ShutdownScope(GamePlayScope)`  
**Then** `GameEnemyModule.Shutdown()` 被调用  
**And** 本模块生成的敌机被回收且不会残留在场景中
