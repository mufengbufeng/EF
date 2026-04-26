## 1. 运行时生命周期基础

- [x] 1.1 梳理 `EventChannel<T>` 与 `EventHub` 之间的最小协作接口，明确活跃登记、空闲移除和调试状态所需字段
- [x] 1.2 修改 `Assets/EF/EFRuntime/Event/EventChannel.cs`，支持首次异步入队激活、队列清空后失活以及生命周期状态暴露
- [x] 1.3 更新事件基础接口或调试信息接口，使“未创建 / 已创建但空闲 / 已创建且活跃”状态可被上层读取

## 2. EventHub 代码生成与调度

- [x] 2.1 修改 `Assets/EF/EFEditor/Editor/EventCodeGen/EventCodeGenGenerator.cs`，生成 backing field + 延迟创建属性访问器，而不是构造时全量 `new`
- [x] 2.2 修改生成逻辑，产生活跃异步 Channel 集合及其 `Update()` / `Shutdown()` 调度代码，移除对全量 `_allChannels` 刷新的依赖
- [x] 2.3 重新生成 `Assets/GameScripts/HotFix/GameLogic/Event/Generated/EventHub.Generated.cs`，并确认现有业务调用点保持原有访问方式

## 3. 调试与可视化适配

- [x] 3.1 更新事件监视面板的数据获取方式，使其能够读取声明槽位和实例状态，而不会因为查看面板触发 Channel 实例化
- [x] 3.2 在面板中展示至少三种生命周期状态：未创建、已创建但空闲、已创建且活跃

## 4. 验证与回归覆盖

- [x] 4.1 为延迟创建行为补充测试，验证 `EventHub` 初始化后未访问事件不会创建 Channel，首次访问时才创建实例
- [x] 4.2 为活跃调度补充测试，验证仅有待处理异步事件的 Channel 会在 `Update()` 中被刷新，空闲 Channel 不会被扫描
- [x] 4.3 为同步路径补充测试，验证仅使用 `Subscribe` / `Publish` 的 Channel 不会进入异步活跃集合
- [x] 4.4 为关闭流程补充测试，验证 `Shutdown()` 会清空已创建 Channel 并重置活跃状态，同时不会为未创建事件补建实例
