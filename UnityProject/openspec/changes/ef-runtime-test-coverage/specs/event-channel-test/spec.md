## ADDED Requirements

### Requirement: Subscribe 注册处理器
EventChannel SHALL 允许通过 Subscribe 注册 Action<T> 回调，注册后 HandlerCount 递增。

#### Scenario: 注册单个 handler
- **WHEN** 调用 Subscribe(handler)
- **THEN** HandlerCount 等于 1，handler 存在于 GetHandlerNames() 返回列表中

#### Scenario: 注册 null handler 抛出异常
- **WHEN** 调用 Subscribe(null)
- **THEN** 抛出 ArgumentNullException

#### Scenario: 注册重复 handler 忽略
- **WHEN** 同一个 handler 被注册两次
- **THEN** HandlerCount 仍然为 1，不会重复触发

### Requirement: Unsubscribe 反注册处理器
EventChannel SHALL 支持通过 Unsubscribe 移除已注册的 handler，使用 swap-with-last 策略保证 O(1)。

#### Scenario: 反注册已存在的 handler
- **WHEN** 调用 Unsubscribe(registeredHandler)
- **THEN** HandlerCount 减少 1，后续 Publish 不再触发该 handler

#### Scenario: 反注册不存在的 handler 静默忽略
- **WHEN** 调用 Unsubscribe(unknownHandler)
- **THEN** HandlerCount 不变，无异常

#### Scenario: 反注册 null handler 抛出异常
- **WHEN** 调用 Unsubscribe(null)
- **THEN** 抛出 ArgumentNullException

### Requirement: Publish 同步派发
EventChannel SHALL 通过 Publish 同步调用所有已注册 handler，按注册顺序触发。

#### Scenario: 单 handler 派发
- **WHEN** 调用 Publish(args) 且有 1 个 handler
- **THEN** handler 被调用一次，参数为 args

#### Scenario: 多 handler 按序派发
- **WHEN** 注册 handler A、B、C 后调用 Publish(args)
- **THEN** 按注册顺序 A → B → C 依次调用

#### Scenario: 派发中注册新 handler 不影响本轮
- **WHEN** handler A 在回调中调用 Subscribe(handlerD)
- **THEN** 本轮 Publish 不触发 handlerD，下一轮 Publish 才触发

#### Scenario: 派发中反注册 handler 安全处理
- **WHEN** handler A 在回调中调用 Unsubscribe(handlerB)
- **THEN** handlerB 仍可能在本轮被调用（取决于调用顺序），不会崩溃

### Requirement: Enqueue 异步队列
EventChannel SHALL 通过 Enqueue 将事件放入环形缓冲区，不立即派发。

#### Scenario: Enqueue 增加 PendingCount
- **WHEN** 调用 Enqueue(args)
- **THEN** PendingCount 增加 1，handler 未被调用

#### Scenario: 环形缓冲区自动扩容
- **WHEN** 连续 Enqueue 超过初始容量 16
- **THEN** 缓冲区自动扩容，所有已入队事件不丢失

### Requirement: Flush 派发异步队列
EventChannel SHALL 通过 Flush 将环形缓冲区中的所有事件依次 Publish 给 handler。

#### Scenario: Flush 清空队列
- **WHEN** Enqueue 3 个事件后调用 Flush()
- **THEN** 每个 handler 被调用 3 次，PendingCount 归零

#### Scenario: 空队列 Flush 无操作
- **WHEN** 没有入队事件时调用 Flush()
- **THEN** 无任何 handler 被调用

### Requirement: Clear 清空
EventChannel SHALL 通过 Clear 同时清空所有 handler 和异步队列。

#### Scenario: Clear 后 Publish 和 Flush 均无效果
- **WHEN** 注册 handler 并 Enqueue 事件后调用 Clear()
- **THEN** HandlerCount 为 0，PendingCount 为 0
