## ADDED Requirements

### Requirement: EventHub SHALL lazily create declared event channels
生成的 `EventHub` MUST 为每个已声明事件保留稳定的类型化访问入口，但对应 `EventChannel` 实例 SHALL 在首次实际访问前保持未创建状态。

#### Scenario: Unused channel remains uninitialized after hub startup
- **WHEN** `EventHub` 被构造且某个已声明事件从未被访问、订阅、发布或入队
- **THEN** 该事件对应的 `EventChannel` 实例 MUST 仍处于未创建状态

#### Scenario: First access initializes a typed channel
- **WHEN** 业务代码首次访问某个已声明的 `EventHub.XxxEvent`
- **THEN** 系统 MUST 创建并返回该事件唯一的类型化 `EventChannel` 实例

### Requirement: EventHub SHALL refresh only active asynchronous channels
`EventHub` 的帧刷新逻辑 MUST 仅处理当前存在待分发异步事件的 Channel，而不是遍历全部已声明或全部已创建 Channel。

#### Scenario: Idle update skips channels without pending events
- **WHEN** 当前帧没有任何 Channel 持有待分发异步事件
- **THEN** `EventHub.Update()` MUST 不对空闲 Channel 执行异步刷新工作

#### Scenario: Pending queue activates channel for refresh
- **WHEN** 某个 Channel 从“无待分发异步事件”变为“存在至少一个待分发异步事件”
- **THEN** 该 Channel MUST 在下一次 `EventHub.Update()` 中被刷新

#### Scenario: Drained queue stops participating in refresh
- **WHEN** 某个活跃 Channel 的待分发异步事件已在刷新中被完全消费
- **THEN** 该 Channel MUST 在后续空闲帧中停止参与异步刷新

### Requirement: Synchronous event usage SHALL not incur asynchronous scheduling cost
仅通过 `Subscribe` 和同步 `Publish` 使用的 Channel MUST 不因为被访问或已有订阅者而自动加入异步刷新集合。

#### Scenario: Synchronous publish does not activate async refresh
- **WHEN** 某个 Channel 被创建并发生同步 `Publish`，但从未调用 `Enqueue`
- **THEN** 该 Channel MUST 不被视为异步活跃 Channel

#### Scenario: Subscribed but idle channel is not refreshed
- **WHEN** 某个 Channel 已注册一个或多个 handler，但待分发异步队列为空
- **THEN** `EventHub.Update()` MUST 不为该 Channel 执行异步刷新

### Requirement: Event lifecycle state SHALL remain observable for debugging
事件监视和调试接口 MUST 能区分每个已声明事件的生命周期状态，至少包括“未创建”“已创建但空闲”“已创建且活跃”三种状态。

#### Scenario: Debugging view shows uninitialized channel
- **WHEN** 调试工具读取一个已声明但尚未首次访问的事件 Channel
- **THEN** 系统 MUST 将其呈现为“未创建”状态，而不是隐式创建实例

#### Scenario: Debugging view shows active channel
- **WHEN** 某个 Channel 持有待分发异步事件并等待下一次刷新
- **THEN** 调试工具 MUST 能将其呈现为“已创建且活跃”状态

#### Scenario: Debugging view shows idle created channel
- **WHEN** 某个 Channel 已被创建且没有待分发异步事件
- **THEN** 调试工具 MUST 能将其呈现为“已创建但空闲”状态

### Requirement: Shutdown SHALL clear created channels and reset lifecycle state
事件系统关闭时 MUST 清理所有已创建 Channel 的订阅与待分发状态，并重置异步活跃调度状态。

#### Scenario: Shutdown clears active queues
- **WHEN** `EventHub.Shutdown()` 在存在已创建且活跃的 Channel 时被调用
- **THEN** 所有已创建 Channel 的待分发异步事件 MUST 被清空，且后续空闲帧不得继续刷新这些 Channel

#### Scenario: Shutdown preserves lazy model for never-created channels
- **WHEN** `EventHub.Shutdown()` 被调用且某些已声明事件从未创建实例
- **THEN** 系统 MUST 不为这些事件补建 Channel 实例仅用于执行清理
