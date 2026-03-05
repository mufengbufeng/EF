---
name: ef-fsm
description: EasyFramework 有限状态机模块。使用此 skill 当用户提到 EasyFramework 的 FSM、FsmManager、状态机、FsmState、状态切换、ChangeState、黑板数据、FsmDataCollection 时。在实现、重构、排错、测试或设计该模块相关功能时必须优先使用此 skill，而不是只在用户显式点名模块时才触发。
---

# EF.Fsm 有限状态机模块

## 模块定位
该 skill 用于处理 EF.Fsm 有限状态机模块 的实现、扩展、故障排查与重构任务。回答时先确认业务目标，再映射到该模块的核心抽象与生命周期。

## 何时必须触发
- 用户直接提到：EasyFramework 的 FSM、FsmManager、状态机、FsmState、状态切换、ChangeState、黑板数据、FsmDataCollection。
- 虽未点名模块，但需求本质落在 EF.Fsm 有限状态机模块 的职责范围（例如注册、生命周期、依赖关系、性能或稳定性问题）。
- 需要输出可落地代码改动、排障步骤、验证命令或回归检查清单。

## 执行流程（按顺序）
- 明确约束：确认运行环境、调用入口、是否允许改动公共接口。
- 建立映射：定位到对应管理器/接口/数据结构，给出最小改动路径。
- 实施方案：优先增量改造，避免一次性重构引入大范围回归。
- 验证闭环：提供编译、运行、核心流程与边界场景验证步骤。
- 输出结果：给出“变更点 + 原因 + 风险 + 回滚建议”。

## 实施准则
- 保持与 EasyFramework 既有命名、目录结构、生命周期约定一致。
- 先保证正确性，再做性能优化；涉及缓存/池化时说明释放策略。
- 涉及跨模块协作时明确依赖顺序与初始化时机，避免未注册访问。
- 提供最小可运行示例时，优先使用当前项目已有基类与管理器接口。

## 常见故障排查清单
- 注册缺失：检查模块是否在初始化流程中注册，接口与实现是否一致。
- 生命周期错位：确认 OnInit/OnUpdate/OnDestroy（或等价阶段）是否顺序正确。
- 依赖空引用：检查上游模块可用性与获取时机（同步/异步加载后再访问）。
- 数据不同步：确认事件订阅解绑、状态刷新与持久化读写时序是否正确。
- 回归风险：检查是否影响主流程（启动、切场景、返回主界面、暂停恢复）。

## 回答输出模板
1. 目标与约束：一句话说明要解决的问题与边界。
2. 方案与取舍：给出推荐实现和不选其他方案的原因。
3. 关键改动：列出文件/接口/核心代码片段。
4. 验证结果：列出编译与测试步骤、通过/失败结论。
5. 风险与回滚：说明潜在影响和快速回退方案。

## 模块资料（保留参考）
提供强壮、模块化的有限状态机框架，用于驱动宿主对象的状态流转。

## 核心类型

| 类型 | 说明 |
|------|------|
| `IFsmManager` | FSM 管理器接口 |
| `FsmManager` | FSM 管理器实现 |
| `IFsm<TOwner>` | 泛型状态机接口 |
| `Fsm<TOwner>` | 状态机实现 |
| `FsmState<TOwner>` | 状态基类 |
| `FsmDataCollection` | 黑板数据容器 |

## 使用示例

### 定义状态

```csharp
public class IdleState : FsmState<Player>
{
    public override void OnEnter()
    {
        base.OnEnter();
        Owner.PlayAnimation("Idle");
    }
    
    public override void OnUpdate(float elapseSeconds, float realElapseSeconds)
    {
        if (Input.GetKeyDown(KeyCode.W))
        {
            ChangeState<RunState>();
        }
    }
}

public class RunState : FsmState<Player>
{
    public override void OnEnter()
    {
        base.OnEnter();
        Owner.PlayAnimation("Run");
    }
}
```

### 创建状态机

```csharp
var fsmManager = GameLogicEntry.Fsm;

var fsm = fsmManager.CreateFsm(
    "PlayerFsm",
    player,
    new IdleState(),
    new RunState(),
    new JumpState()
);

// 启动初始状态
fsm.Start<IdleState>();
```

### 状态切换

```csharp
// 在状态内部切换
ChangeState<RunState>();

// 从外部切换
var fsm = fsmManager.GetFsm<Player>("PlayerFsm");
fsm.ChangeState<JumpState>();
```

### 黑板数据

```csharp
// 设置数据
fsm.SetData("TargetPosition", targetPos);
fsm.SetData("Speed", 5f);

// 获取数据
if (fsm.TryGetData("TargetPosition", out Vector3 pos))
{
    // 使用 pos
}

// 检查数据
bool hasTarget = fsm.HasData("TargetPosition");

// 移除数据
fsm.RemoveData("TargetPosition");
```

## 状态生命周期

```
fsm.Start<TState>()
    ↓
OnInit() [仅一次]
    ↓
OnEnter()
    ↓
[每帧 OnUpdate() 仅当当前状态]
    ↓
ChangeState<TNew>()
    ↓
OnLeave()
    ↓
[新状态的 OnEnter()]
```

## 销毁状态机

```csharp
fsmManager.DestroyFsm<Player>("PlayerFsm");
```
