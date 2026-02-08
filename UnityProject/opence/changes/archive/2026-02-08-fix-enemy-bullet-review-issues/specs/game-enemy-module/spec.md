## MODIFIED Requirements
### Requirement: GameEnemyModule 负责敌机生成与回收

系统 SHALL 提供 `GameEnemyModule`（及其服务接口 `IGameEnemyModule`），用于在玩法运行期间生成敌机并在退出玩法时清理。  
在最小实现阶段，`GameEnemyModule` SHOULD 支持按固定时间间隔生成敌机，并维护其生成记录以便统一回收。

#### Scenario: 场景就绪后开始刷怪
**Given** `GamePlayProcedure` 已进入且玩法场景就绪  
**And** 调用方已通过模块接口提供敌机的 `entityAssetName` 与 `groupName`  
**And** 子弹模块已完成异步初始化（`InitializeAsync` 返回的 UniTask 已完成）  
**When** `GamePlayProcedure` 启动 `GameEnemyModule` 的刷怪流程  
**Then** `GameEnemyModule` 在后续更新中按规则生成敌机  
**And** 每个生成的敌机被记录用于后续回收

#### Scenario: 异步生成使用 UniTaskVoid 而非 async void
**Given** `EnemySpawnerModule.SpawnEnemy()` 需要异步调用 `ShowEntityAsync`  
**When** 生成器触发生成逻辑  
**Then** 使用 `async UniTaskVoid` 签名而非 `async void`  
**And** 内部异常通过 try/catch 捕获并记录日志，不会导致应用崩溃

#### Scenario: 使用 EntityManager 统一 ID 生成
**Given** `IEntityManager` 提供 `GenerateEntityId()` 方法  
**When** `EnemySpawnerModule` 需要为新敌机分配 ID  
**Then** 调用 `_entityManager.GenerateEntityId()` 获取 ID  
**And** 不使用模块内部自增 ID，避免与 EntityManager 内部 ID 冲突

#### Scenario: 存活敌人清理不产生 GC 分配
**Given** `EnemySpawnerModule.Update()` 每帧需要清理已销毁的敌人引用  
**When** 执行清理逻辑  
**Then** 使用手动反向 for 循环遍历 `_aliveEnemies`  
**And** 不使用 `RemoveAll(lambda)` 以避免闭包分配

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

`GameEnemyModule` MUST 以"玩法作用域（GamePlay scope）"注册到 `EF.Common.ModuleSystem`，并在调用 `ModuleSystem.ShutdownScope(GamePlayScope)` 时被注销并执行 `Shutdown()`。  
`Shutdown()` MUST 停止刷怪、回收敌机并保持幂等。

#### Scenario: 退出玩法时清理敌机模块
**Given** `GameEnemyModule` 已以 `scope = GamePlayScope` 注册到 `ModuleSystem` 且已生成若干敌机  
**When** `GamePlayProcedure` 退出并调用 `ModuleSystem.ShutdownScope(GamePlayScope)`  
**Then** `GameEnemyModule.Shutdown()` 被调用  
**And** 本模块生成的敌机被回收且不会残留在场景中

## ADDED Requirements
### Requirement: EnemyEntity 缓存模块引用以优化性能

敌人实体 SHALL 在 `OnShow()` 时缓存 `IBulletModule` 和 `IEntityManager` 的引用，避免在热路径（每帧更新、每次攻击）中重复通过 `ModuleSystem.Get<T>()` 查询。

#### Scenario: OnShow 时缓存引用
- **WHEN** `EnemyEntity.OnShow()` 被调用时
- **THEN** 通过 `ModuleSystem.Get<IBulletModule>()` 缓存子弹模块引用
- **AND** 通过 `ModuleSystem.Get<IEntityManager>()` 缓存实体管理器引用
- **AND** `TriggerAttack()` 和 `CheckBoundary()` 使用缓存字段

#### Scenario: 攻击间隔防御
- **WHEN** `_attackInterval` 小于等于 0 时
- **THEN** 跳过攻击逻辑，不执行每帧子弹发射
