## ADDED Requirements

### Requirement: ScheduleOnce 一次性定时
TimerManager SHALL 支持 ScheduleOnce 注册在指定延迟后触发一次的回调。

#### Scenario: 到时触发回调
- **WHEN** 调用 ScheduleOnce(5f, callback) 后 Update 累计 5 秒
- **THEN** callback 被调用一次

#### Scenario: 未到时不触发
- **WHEN** 调用 ScheduleOnce(5f, callback) 后 Update 累计 3 秒
- **THEN** callback 未被调用

#### Scenario: 返回有效 TimerId
- **WHEN** 调用 ScheduleOnce(1f, callback)
- **THEN** 返回的 TimerId 大于 0，且 Exists(id) 返回 true

### Requirement: ScheduleLoop 循环定时
TimerManager SHALL 支持 ScheduleLoop 注册按间隔循环触发的回调。

#### Scenario: 每隔 interval 触发一次
- **WHEN** 调用 ScheduleLoop(2f, callback) 后 Update 累计 6 秒
- **THEN** callback 被调用 3 次

### Requirement: Cancel 取消定时器
TimerManager SHALL 支持通过 Cancel 取消已注册的定时器。

#### Scenario: 取消后不再触发
- **WHEN** 调用 ScheduleOnce(5f, callback) 后 Cancel(id) 后 Update 5 秒
- **THEN** callback 未被调用，Exists(id) 返回 false

### Requirement: TimerId 不重复
TimerManager SHALL 保证每次生成的 TimerId 全局唯一。

#### Scenario: 连续创建 ID 递增且不重复
- **WHEN** 连续调用 100 次 ScheduleOnce
- **THEN** 100 个 TimerId 互不相同

### Requirement: TimerTask 状态机
TimerTask SHALL 管理 IsCancelled 和 NextTriggerTime 状态。

#### Scenario: Cancel 后 IsCancelled 为 true
- **WHEN** 调用 task.Cancel()
- **THEN** task.IsCancelled 为 true

#### Scenario: 循环任务 TrySetNextTrigger 更新下次触发时间
- **WHEN** 循环任务的 IsLoop 为 true，调用 TrySetNextTrigger
- **THEN** NextTriggerTime 增加 IntervalSeconds

### Requirement: TimerTaskCollection 收集到期任务
TimerTaskCollection SHALL 通过 CollectDue 返回所有到期的 TimerTask。

#### Scenario: CollectDue 只返回到期任务
- **WHEN** 注册 3 个任务（1 个到期、2 个未到期）后调用 CollectDue(currentTime)
- **THEN** 只返回 1 个到期任务

#### Scenario: ShiftAll 偏移所有任务时间
- **WHEN** 调用 ShiftAll(10f)
- **THEN** 所有任务的 NextTriggerTime 增加 10f

### Requirement: Clear 清空所有定时器
TimerManager SHALL 通过 Clear 移除所有已注册的定时器。

#### Scenario: Clear 后 TimerCount 为 0
- **WHEN** 注册多个定时器后调用 Clear()
- **THEN** TimerCount 归零，所有回调不再触发
