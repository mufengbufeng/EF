## 1. 实现（Implementation）

- [x] 1.1 确认“玩法作用域”常量（例如 `GamePlayScope = 1001`），并约定所有玩法模块必须使用该 scope 注册到 `ModuleSystem`
- [x] 1.2 新增 `IGameEnemyModule` / `GameEnemyModule`（HotFix）：最小刷怪实现（固定间隔生成敌机），并在 `Shutdown()` 中回收敌机（敌机全部使用 `IEntityManager` 创建为 Entity）
- [x] 1.3 调整 `GamePlayProcedure`：
  - [x] 1.3.1 `OnEnter`：先 `ModuleSystem.ShutdownScope(GamePlayScope)`（幂等清理），再注册敌机模块；然后调用 `GameLogicEntry.GameScene.EnterGamePlaySceneAsync()` 并等待完成，最后启动刷怪
  - [x] 1.3.2 `OnLeave`：调用 `ModuleSystem.ShutdownScope(GamePlayScope)` 统一清理玩法模块
  - [x] 1.3.3 `OnUpdate`：根据项目实际情况选择“显式驱动敌机模块更新”或“依赖全局 `ModuleSystem.Update`”

## 2. 验证（Validation）

- [ ] 2.1 Unity PlayMode：从主菜单进入玩法流程，日志显示进入 `GamePlayProcedure` 且完成玩法场景加载
- [ ] 2.2 Unity PlayMode：若已调用 `IGameEnemyModule.Configure(...)` 提供有效 `entityAssetName/groupName`，则场景就绪后敌机按间隔生成（至少出现 3 次生成日志/实体）；未配置时应输出警告且不刷怪
- [ ] 2.3 Unity PlayMode：退出玩法流程后调用 `ShutdownScope(GamePlayScope)`，敌机被回收且不会残留

## 3. 兼容性与风险处理（Risk）

- [x] 3.1 确认项目是否存在统一的 `ModuleSystem.Update(...)` 驱动入口：若不存在，补齐驱动（例如在合适的 MonoBehaviour `Update()` 中调用），否则新模块与现有 EF 管理器的 Update 都可能无法运行
