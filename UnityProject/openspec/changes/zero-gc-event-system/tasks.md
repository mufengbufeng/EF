## 1. 基础设施（EF.Runtime）

- [x] 1.1 创建 `EventArgsAttribute` — 放在 `Assets/EF/EFRuntime/Event/EventArgsAttribute.cs`，标记事件 struct 类型
- [x] 1.2 创建 `IEventChannel` 接口 — 放在 `Assets/EF/EFRuntime/Event/IEventChannel.cs`，定义 `Flush()` 和 `Clear()` 方法
- [x] 1.3 创建 `IEventChannelInfo` 接口 — 放在 `Assets/EF/EFRuntime/Event/IEventChannelInfo.cs`，定义 Editor 调试信息属性（EventName、HandlerCount、PendingCount、GetHandlerNames）
- [x] 1.4 实现 `EventChannel<T>` 核心类 — 放在 `Assets/EF/EFRuntime/Event/EventChannel.cs`，实现 handler 预分配数组、swap-remove、版本号保护、环形缓冲区、Publish/Enqueue/Flush/Clear

## 2. Code Gen 工具（Editor）

- [x] 2.1 创建 `EventCodeGenScanner` — 扫描所有程序集中 `[EventArgs]` 标记的 readonly struct，返回类型列表
- [x] 2.2 创建 `EventCodeGenGenerator` — 根据扫描结果生成 EventHub partial 类代码（channel 属性 + IEventChannel[] 数组 + Update/Shutdown）
- [x] 2.3 创建 `EventCodeGenRunner` — 编排扫描→生成→写入流程，提供 `[MenuItem("EF/Generate Event System")]` 手动触发入口
- [x] 2.4 创建 `EventCodeGenAssetProcessor` — 继承 AssetPostprocessor，监听 .cs 文件变化自动触发 Code Gen

## 3. 事件系统迁移

- [x] 3.1 迁移 `SceneEnterEvent` — 改为 `[EventArgs] readonly struct SceneEnterEvent`
- [x] 3.2 迁移 `BeforeSceneEnterEvent` — 改为 `[EventArgs] readonly struct BeforeSceneEnterEvent`
- [x] 3.3 删除 `EGameEvent` 枚举 — 类型本身即为标识，不再需要
- [x] 3.4 运行 Code Gen 生成 `EventHub` — 手动创建 `Assets/GameScripts/HotFix/GameLogic/Event/Generated/EventHub.Generated.cs`（编辑器中可通过菜单 EF/Generate Event System 重新生成）
- [x] 3.5 迁移 `GameSceneManager` — 将 `_eventManager.Publish(new XxxEvent(...))` 改为 `EventHub.XxxEvent.Enqueue(new XxxEvent(...))`
- [x] 3.6 迁移 `GameLogicEntry` — 将 `IEventManager` 替换为 `EventHub`，更新静态属性暴露

## 4. 旧代码清理

- [x] 4.1 删除旧 `EventManager.cs`、`EventHandlerRegistry.cs`、`EventTypeResolver.cs`、`PendingEvent.cs`、`PendingEventQueue.cs`
- [x] 4.2 删除旧 `BaseEventArgs.cs`、`GameEventArgs.cs`、`EventPoolModel.cs`
- [x] 4.3 更新 `IEventManager.cs` — 移除旧接口或替换为新接口定义
- [x] 4.4 更新 `ModuleSystem` 注册 — 将 `IEventManager` 替换为 `EventHub`，在 GameLogicEntry 中创建和注册

## 5. Editor 可视化面板

- [x] 5.1 创建 `EFEventMonitorWindow` — EditorWindow，菜单 `Window/EF/Event Monitor`，展示 channel 列表表格
- [x] 5.2 实现表格渲染 — 每行显示事件名称、handler 数量、pending 数量、活跃状态
- [x] 5.3 实现 handler 详情展开 — 点击行展开显示 `ClassName.MethodName` 列表
- [x] 5.4 实现运行时刷新 — 通过 EditorApplication.update 定时刷新 pending 数据
- [x] 5.5 实现空状态提示 — 非 Play Mode 显示提示文本

## 6. 验证

- [ ] 6.1 验证 Publish 路径零 GC — 使用 Profiler 或 GC.GetTotalMemory 验证连续 Publish 无分配
- [ ] 6.2 验证 Subscribe/Unsubscribe 正确性 — 注册多个 handler 后逐个取消，确认调用正确
- [ ] 6.3 验证 Enqueue/Flush 异步派发 — 确认下一帧 Update 时正确派发
- [ ] 6.4 验证 Editor 面板数据显示正确 — Play Mode 下面板实时反映 handler 和 pending 状态
- [ ] 6.5 验证 Code Gen 自动触发 — 新增 `[EventArgs]` struct 文件后自动更新 EventHub
