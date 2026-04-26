## ADDED Requirements

### Requirement: EventChannel 订阅绑定
ControllerEventBinder SHALL 提供 `BindEvent<T>(EventChannel<T> channel, Action<T> handler)` 方法，用于订阅 EventChannel 事件。

#### Scenario: 绑定 EventChannel 事件
- **WHEN** Controller 在 OnEnter 中调用 `EventBinder.BindEvent(channel, handler)`
- **THEN** handler 被注册到 channel（等效于 channel.Subscribe(handler)）

#### Scenario: 参数为空时抛出异常
- **WHEN** 调用 `BindEvent<T>(null, handler)` 或 `BindEvent<T>(channel, null)`
- **THEN** 抛出 ArgumentNullException

### Requirement: EventChannel 订阅自动清理
ControllerEventBinder SHALL 在 ClearAllBindings 时自动 Unsubscribe 所有通过 BindEvent(EventChannel, handler) 注册的订阅。

#### Scenario: OnExit 自动取消订阅
- **WHEN** Controller 调用 OnExit → InternalExit → ClearAllBindings
- **THEN** 所有通过 BindEvent 绑定的 EventChannel 订阅被 Unsubscribe，handler 不再收到事件

#### Scenario: Dispose 后禁止绑定
- **WHEN** ControllerEventBinder 已 Dispose，再调用 BindEvent
- **THEN** 抛出 ObjectDisposedException
