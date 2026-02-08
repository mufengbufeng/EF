# Change: 修复敌人/子弹系统 Review 阶段发现的问题

## Why
`add-enemy-spawner-system` 变更的 Review 阶段发现了 7 个 HIGH 和 9 个 MEDIUM 优先级问题，涉及内存泄漏、async void 崩溃风险、子弹初始化时序、性能热点和防御性编程缺陷。这些问题如果不修复，将导致长时间运行时内存持续增长、异常静默丢失、以及偶发的运行时崩溃。

## What Changes
- **EntityManager 资源管理**：修复 `ShowEntityAsync` 每次创建新 GameObject 不复用的问题；修复 `LoadEntityAssetAsync` 丢弃 `AssetHandle` 导致的资源引用泄漏
- **async void → async UniTaskVoid**：将 `EnemySpawnerModule.SpawnEnemy()` 和 `GamePlayProcedure.OnEnter()` 从 `async void` 改为安全的异步模式
- **子弹初始化时序**：`BulletModule.Initialize()` 改为返回 `UniTask` 的可等待方法，`GamePlayProcedure` 在子弹模块就绪后才启动敌人生成器
- **EnemyEntity 性能优化**：在 `OnShow()` 中缓存 `IBulletModule` 和 `IEntityManager` 引用，避免每次攻击/边界检测时通过 `ModuleSystem.Get<T>()` 加锁查字典
- **EnemySpawnerModule 优化**：用手动反向循环替换 `RemoveAll(lambda)` 避免闭包分配；使用 `IEntityManager.GenerateEntityId()` 替代自增 ID 避免冲突
- **防御性编程**：`_attackInterval <= 0` 保护、统一模块 Initialize/Register 顺序

## Impact
- Affected specs: `entity-lifecycle-guarantee`, `game-enemy-module`
- Affected code:
  - `Assets/EF/EFRuntime/Entity/EntityManager.cs` — ShowEntityAsync 复用 + AssetHandle 缓存
  - `Assets/EF/EFRuntime/Entity/IEntityManager.cs` — 新增 `GenerateEntityId()` 方法
  - `Assets/GameScripts/HotFix/GameLogic/GamePlay/Enemy/EnemyEntity.cs` — 缓存模块引用 + 攻击间隔保护
  - `Assets/GameScripts/HotFix/GameLogic/GamePlay/Enemy/EnemySpawnerModule.cs` — async void 修复 + RemoveAll 优化 + ID 生成
  - `Assets/GameScripts/HotFix/GameLogic/GamePlay/Bullet/BulletModule.cs` — Initialize 返回 UniTask
  - `Assets/GameScripts/HotFix/GameLogic/GamePlay/Bullet/IBulletModule.cs` — Initialize 签名变更
  - `Assets/GameScripts/HotFix/GameLogic/Procedure/GamePlay/GamePlayProcedure.cs` — async void 修复 + 初始化顺序调整
