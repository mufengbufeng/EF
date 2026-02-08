## Context
`add-enemy-spawner-system` 变更的 Review 发现了多个架构和实现层面的问题。本文档记录修复这些问题的关键技术决策。

## Goals / Non-Goals
- Goals:
  - 修复 EntityManager 的 GameObject 和 AssetHandle 泄漏
  - 消除所有 async void 使用
  - 确保子弹模块初始化完成后才开始生成敌人
  - 优化热路径（每帧/每次攻击）的 ModuleSystem 查询
- Non-Goals:
  - 重构 EntityManager 的整体架构（如实体-组件系统）
  - 添加子弹碰撞检测逻辑
  - 性能基准测试

## Decisions

### D1: EntityManager Handle 复用策略
- **决策**: ShowEntityAsync 中，如果对象池返回的实体已有 Handle（GameObject），则复用而非重新实例化
- **理由**: 对象池的核心目的就是复用对象。回收时保留 Handle，再次 Spawn 时直接使用，避免重复 Instantiate/Destroy
- **替代方案**: 在 OnRecycle 中销毁 Handle，每次 Show 时重新创建 —— 这会增加 GC 压力和加载时间，不推荐

### D2: AssetHandle 缓存粒度
- **决策**: 在 EntityManager 中按资源名缓存 AssetHandle（`Dictionary<string, AssetHandle>`），同名资源只加载一次
- **理由**: 同类敌人共用同一预制体，不需要每次都加载。YooAsset 虽有内部缓存但仍会创建新 Handle 对象
- **替代方案**: 完全依赖 YooAsset 缓存，不在 EntityManager 层做缓存 —— 会导致无法精确控制资源释放时机

### D3: BulletModule.Initialize 返回 UniTask
- **决策**: 将 `Initialize()` 改为 `async UniTask InitializeAsync()`
- **理由**: 调用方需要等待加载完成后再启动敌人生成。fire-and-forget 模式导致子弹在前几秒静默丢失
- **接口变更**: IBulletModule 的签名变更，但目前只有 GamePlayProcedure 一处调用，影响可控

### D4: GamePlayProcedure.OnEnter 保持 void 签名
- **决策**: OnEnter 保持 `override void` 签名（因为基类要求），内部调用 `OnEnterAsync().Forget()` 将异步逻辑封装到 `async UniTaskVoid` 辅助方法
- **理由**: ProcedureBase.OnEnter 是 void 签名，无法改为 async。使用 UniTaskVoid + try/catch 确保异常不会丢失

### D5: GenerateEntityId 公开化
- **决策**: 将 EntityManager.GenerateEntityId 改为公共方法，通过 IEntityManager 接口暴露
- **理由**: EnemySpawnerModule 当前使用自增 `_nextEnemyId`（从 10000 开始），可能与 EntityManager 内部的 GenerateEntityId 产生 ID 冲突。统一使用同一 ID 生成器

## Risks / Trade-offs
- Handle 复用要求回收时不销毁 GameObject —— 已有实现符合（OnDestroyEntity 只在对象池销毁时调用）
- IBulletModule.Initialize 签名变更是 **BREAKING** —— 但该接口仅在 GameLogic 热更层使用，无外部消费者
- GenerateEntityId 公开后，外部可能误用 —— 风险低，因为只有 Spawner 类需要调用

## Open Questions
- 无
