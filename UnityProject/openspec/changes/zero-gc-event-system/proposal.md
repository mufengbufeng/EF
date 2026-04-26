## Why

现有 Event 系统（`EF.Event`）在热路径（Publish/Dispatch）上存在持续的 GC 分配：每次派发都 `new List<EventHandler<object>>()` 创建快照，Subscribe 时通过闭包包装产生 `EventHandler<object>` 委托分配，首次事件类型解析使用反射。高频事件场景下这些分配导致频繁 GC 触发，影响帧率稳定性。

## What Changes

- **BREAKING** 用 `readonly struct` 事件参数替代 `class BaseEventArgs` 继承体系，消除 EventId 枚举和反射解析
- **BREAKING** 新 API：`EventHub.SceneEnter.Publish(args)` 替代 `IEventManager.Publish<T>(args)`，通过类型化 Channel 直接派发
- 新增 `EventChannel<T>` 泛型类，内置预分配 handler 数组和环形缓冲区，Publish 路径零 GC
- 新增 `[EventArgs]` Attribute 标记事件类型，供 Code Gen 扫描
- 新增 Code Gen 工具，自动扫描 `[EventArgs]` struct 并生成 `EventHub` 聚合类
- 新增 Editor 可视化面板，展示事件订阅状态、待分发队列、handler 列表
- Code Gen 支持菜单手动触发和文件变化自动触发
- 移除旧 `EventManager`、`EventHandlerRegistry`、`EventTypeResolver`、`PendingEventQueue` 等

## Capabilities

### New Capabilities

- `typed-event-channel`: 类型化事件 Channel，预分配 handler 数组 + 环形缓冲区，Publish 路径零 GC 零反射
- `event-codegen`: Code Gen 工具，扫描 `[EventArgs]` struct 生成 EventHub 聚合类，支持手动和自动触发
- `event-editor-panel`: Editor 可视化面板，实时展示事件系统状态

### Modified Capabilities

（无现有 capability 需要修改）

## Impact

- **BREAKING API**: 所有 `IEventManager.Subscribe<T>/Publish<T>/PublishNow<T>` 调用点需迁移到 `EventHub.Channel.Subscribe/Publish/Enqueue`
- **BREAKING 类型**: 所有 `class XxxEvent : BaseEventArgs` 需改为 `[EventArgs] readonly struct`
- **BREAKING 枚举**: `EGameEvent` 枚举不再需要，类型本身即为标识
- **程序集**: EF.Runtime 新增 `EventChannel<T>`、`EventArgsAttribute`、`IEventChannel`；GameLogic 新增生成的 `EventHub`
- **注册方式**: `ModuleSystem.Register<IEventManager>` 替换为 `ModuleSystem.Register<EventHub>`（或通过 `GameLogicEntry.Event` 暴露）
- **影响范围**: 当前已知调用点 `GameSceneManager`、`GameSceneEvents`、`GameLogicEntry`
