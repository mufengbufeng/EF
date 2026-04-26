## ADDED Requirements

### Requirement: CreateFsm 创建状态机
FsmManager SHALL 支持通过 CreateFsm<TOwner>(owner, states) 创建状态机并自动进入初始状态。

#### Scenario: 创建后进入第一个状态
- **WHEN** 调用 CreateFsm(owner, new[]{ stateA, stateB })
- **THEN** stateA 的 OnEnter 被调用，CurrentState 为 stateA

#### Scenario: 创建后 HasFsm 返回 true
- **WHEN** 调用 CreateFsm<TOwner>(owner, states)
- **THEN** HasFsm<TOwner>() 返回 true

### Requirement: DestroyFsm 销毁状态机
FsmManager SHALL 支持通过 DestroyFsm<TOwner>() 销毁状态机。

#### Scenario: 销毁后不可获取
- **WHEN** 调用 DestroyFsm<TOwner>()
- **THEN** HasFsm<TOwner>() 返回 false，GetFsm 抛出异常

#### Scenario: 销毁时调用当前状态的 OnLeave
- **WHEN** 在 stateA 时调用 DestroyFsm
- **THEN** stateA 的 OnLeave 被调用

### Requirement: 状态转换生命周期
Fsm<TOwner> SHALL 在状态转换时依次调用 OnLeave(旧) → OnEnter(新)。

#### Scenario: 切换状态触发完整生命周期
- **WHEN** 从 stateA 切换到 stateB
- **THEN** 依次调用 stateA.OnLeave → stateB.OnEnter，CurrentState 变为 stateB

### Requirement: Update 驱动
FsmManager SHALL 通过 Update 驱动所有状态机的 OnUpdate。

#### Scenario: Update 传递到当前状态
- **WHEN** 调用 fsmManager.Update(0.5f, 0.5f)
- **THEN** 当前状态的 OnUpdate 被调用，参数为 (0.5f, 0.5f)

### Requirement: FsmDataCollection 数据存取
Fsm<TOwner> SHALL 支持通过 SetData/GetData 存取自定义数据。

#### Scenario: 设置和获取数据
- **WHEN** 调用 fsm.SetData("key", value) 后调用 fsm.GetData<T>("key")
- **THEN** 返回 value

#### Scenario: 获取不存在的数据返回 default
- **WHEN** 调用 fsm.GetData<int>("nonexistent")
- **THEN** 返回 0 (default(int))

### Requirement: Shutdown 清理
FsmManager SHALL 通过 Shutdown 销毁所有已创建的状态机。

#### Scenario: Shutdown 后 Count 归零
- **WHEN** 创建多个 FSM 后调用 Shutdown()
- **THEN** Count 归零，所有状态机的 OnLeave 被调用
