# 实施任务清单

## 1. EntityManager 资源管理修复 (H1+H2)

- [x] 1.1 在 EntityManager 中添加 `Dictionary<string, AssetHandle> _assetHandleCache` 缓存已加载的实体资源句柄
- [x] 1.2 修改 `LoadEntityAssetAsync` 返回 `AssetHandle` 而不仅是 `GameObject`，调用方保存引用
- [x] 1.3 修改 `ShowEntityAsync`：复用对象池返回的实体已有 Handle（如果有），仅在 Handle 为 null 时才加载和实例化新 GameObject
- [x] 1.4 在 `Shutdown()` 中释放所有缓存的 AssetHandle
- [x] 1.5 在 `IEntityManager` 中暴露 `int GenerateEntityId()` 公共方法

## 2. async void 修复 (H6+H7)

- [x] 2.1 将 `EnemySpawnerModule.SpawnEnemy()` 从 `async void` 改为 `async UniTaskVoid`，使用 `.Forget()` 调用
- [x] 2.2 将 `GamePlayProcedure.OnEnter()` 改为调用 `async UniTaskVoid` 辅助方法，保留 `override void OnEnter` 签名

## 3. 子弹初始化时序修复 (H4+H5)

- [x] 3.1 将 `IBulletModule.Initialize()` 签名改为 `UniTask InitializeAsync()`
- [x] 3.2 将 `BulletModule.Initialize()` 改为 `async UniTask InitializeAsync()`，内联原 `LoadBulletPrefabAsync` 逻辑
- [x] 3.3 在 `GamePlayProcedure` 中 `await _bulletModule.InitializeAsync()` 确保子弹就绪后再启动敌人生成

## 4. EnemyEntity 性能优化 (M1+M2)

- [x] 4.1 添加 `_bulletModule` 和 `_entityManager` 私有字段
- [x] 4.2 在 `OnShow()` 中通过 `ModuleSystem.Get<T>()` 缓存两个引用
- [x] 4.3 `TriggerAttack()` 和 `CheckBoundary()` 使用缓存字段替代每次查询
- [x] 4.4 在 `OnHide()` 中清空缓存引用

## 5. EnemySpawnerModule 优化 (M3+M4)

- [x] 5.1 用手动反向 for 循环替换 `_aliveEnemies.RemoveAll(lambda)` 避免闭包分配
- [x] 5.2 移除 `_nextEnemyId` 字段，改用 `IEntityManager.GenerateEntityId()` 生成 ID

## 6. 防御性编程修复 (M9+M7)

- [x] 6.1 在 `EnemyEntity.UpdateAttack()` 中添加 `_attackInterval <= 0` 保护
- [x] 6.2 统一 `GamePlayProcedure` 中所有模块的 Initialize/Register 顺序为：创建 → Configure → Register → Initialize

## 依赖关系
- 任务 1.5 需在任务 5.2 之前完成（暴露 GenerateEntityId 后才能使用）
- 任务 3 需在任务 6.2 之前完成（Initialize 签名变更后才能调整调用顺序）
- 任务 4 可与其他任务并行
