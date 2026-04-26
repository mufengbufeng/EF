## ADDED Requirements

### Requirement: EventChannel 泛型类支持类型安全的订阅与派发

系统 SHALL 提供 `EventChannel<T>` 泛型类（`where T : struct`），支持 `Subscribe(Action<T>)`、`Unsubscribe(Action<T>)`、`Publish(in T)`、`Enqueue(in T)` 四个核心操作。所有 handler 以 `Action<T>` 强类型存储，禁止任何 `object` 类型转换或装箱。

#### Scenario: 订阅并同步派发事件
- **WHEN** 调用 `channel.Subscribe(handler)` 注册一个 `Action<MyEvent>` handler，然后调用 `channel.Publish(new MyEvent())`
- **THEN** handler 被精确调用一次，参数类型为 `MyEvent`，无 GC 分配

#### Scenario: 取消订阅后不再收到事件
- **WHEN** 调用 `channel.Subscribe(handler)`，然后 `channel.Unsubscribe(handler)`，然后 `channel.Publish(new MyEvent())`
- **THEN** handler 不被调用

### Requirement: Publish 热路径零 GC

`Publish(in T)` 方法 SHALL 在执行过程中不产生任何托管堆分配。Handler 存储使用预分配数组，迭代使用版本号保护而非创建快照 List。

#### Scenario: 高频 Publish 无 GC
- **WHEN** 在一个已注册 handler 的 channel 上连续调用 `Publish` 1000 次
- **THEN** 零次 GC.Alloc 产生（可通过 Profiler 或 GC.GetTotalMemory 验证）

#### Scenario: Publish 期间 handler 列表被修改
- **WHEN** handler A 在被调用时调用 `Unsubscribe(handler B)`
- **THEN** 不抛出异常，handler B 在当前帧若已过迭代位置则不执行，版本号检测生效

### Requirement: 环形缓冲区异步派发

`Enqueue(in T)` SHALL 将事件写入 channel 内置的环形缓冲区，由 `Flush()` 在 Update 时统一消费并调用 `Publish`。环形缓冲区使用预分配的 `T[]` 数组，Enqueue 操作零 GC。

#### Scenario: Enqueue 后在 Flush 时派发
- **WHEN** 调用 `channel.Enqueue(new MyEvent())`，然后调用 `channel.Flush()`
- **THEN** 所有已注册 handler 被调用，事件参数与 Enqueue 时一致

#### Scenario: 环形缓冲区满时自动扩容
- **WHEN** Enqueue 时环形缓冲区已满（tail 追上 head）
- **THEN** 缓冲区自动翻倍扩容，已排队事件不丢失

### Requirement: EventArgs Attribute 标记

系统 SHALL 提供 `[EventArgs]` Attribute，用于标记 struct 事件参数类型。被标记的类型 MUST 是 `readonly struct`。

#### Scenario: 标记正确类型
- **WHEN** 用 `[EventArgs]` 标记一个 `readonly struct`
- **THEN** Code Gen 工具识别并将其纳入 EventHub 生成

#### Scenario: 标记非 struct 类型
- **WHEN** 用 `[EventArgs]` 标记一个 class
- **THEN** Code Gen 工具输出警告并跳过该类型

### Requirement: IEventChannel 接口

系统 SHALL 提供 `IEventChannel` 接口（包含 `Flush()` 和 `Clear()` 方法），用于 EventHub 统一迭代所有 channel。

#### Scenario: EventHub 遍历所有 channel
- **WHEN** EventHub.Update() 被调用
- **THEN** 遍历内部 `IEventChannel[]` 数组，对每个 channel 调用 `Flush()`

### Requirement: IEventChannelInfo 调试接口

`EventChannel<T>` SHALL 实现 `IEventChannelInfo` 接口，提供 `EventName`、`HandlerCount`、`PendingCount`、`GetHandlerNames()` 属性/方法供 Editor 面板使用。

#### Scenario: Editor 读取 channel 信息
- **WHEN** Editor 面板调用 `channel.EventName` 和 `channel.HandlerCount`
- **THEN** 返回正确的事件类型名称和当前注册 handler 数量
