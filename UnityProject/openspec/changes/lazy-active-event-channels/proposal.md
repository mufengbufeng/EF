## Why

当前生成的 `EventHub` 会在构造时一次性创建全部 `EventChannel`，并在每帧 `Update` 中无条件遍历所有 Channel 执行 `Flush()`。随着事件类型数量增长，这会把启动期分配成本和空转帧开销线性放大，即使某些事件从未被订阅、从未入队，也要持续为其付出初始化和遍历成本。

`zero-gc-event-system` 已经解决了事件分发热路径的 GC 问题，但 Channel 生命周期与调度策略仍然偏粗粒度。现在补上这一层优化，可以让类型化事件系统在事件规模扩张时仍保持低启动成本和低空闲帧成本。

## What Changes

- 生成的 `EventHub` 改为按需创建 `EventChannel`，不再在构造函数中一次性初始化所有 Channel 实例。
- 为异步事件队列增加“活跃 Channel”调度机制，只刷新真正存在待处理事件的 Channel，而不是每帧全量遍历。
- 区分同步派发路径与异步刷新路径，避免仅使用同步 `Publish` 的 Channel 被纳入常驻刷新成本。
- 扩展事件运行时与代码生成约定，使延迟创建、活跃登记、空闲移除和调试可视化能够协同工作。
- 保持业务侧类型化事件 API 尽量稳定，使现有 `EventHub.XxxEvent.Publish/Enqueue/Subscribe` 使用方式无需大规模改写。

## Capabilities

### New Capabilities
- `event-channel-lifecycle`: 定义类型化事件 Channel 的延迟创建、异步活跃登记、按需刷新和调试可见性要求。

### Modified Capabilities

## Impact

- 受影响运行时代码：`Assets/EF/EFRuntime/Event/EventChannel.cs` 及相关事件基础接口。
- 受影响生成代码：`Assets/GameScripts/HotFix/GameLogic/Event/Generated/EventHub.Generated.cs` 的属性与调度结构。
- 受影响编辑器工具：`Assets/EF/EFEditor/Editor/EventCodeGen/EventCodeGenGenerator.cs` 以及事件监视面板读取逻辑。
- 对业务调用点的目标影响：保留现有类型化调用风格，尽量不要求 `GameLogic` 中现有事件调用方改签名。
- 与现有变更关系：这是对 `zero-gc-event-system` 的生命周期与调度层补强，不改变其“类型化零 GC 事件通道”的总体方向。
