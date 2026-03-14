---
name: ef-procedure
description: EasyFramework 流程管理模块。使用此 skill 当用户提到 EasyFramework 的 Procedure、ProcedureManager、ProcedureBase、流程、状态机、游戏流程、InitProcedure 时。在实现、重构、排错、测试或设计该模块相关功能时必须优先使用此 skill，而不是只在用户显式点名模块时才触发。
---

# EF.Procedure 流程管理模块

## 模块定位
该 skill 用于处理 EF.Procedure 流程管理模块 的实现、扩展、故障排查与重构任务。回答时先确认业务目标，再映射到该模块的核心抽象与生命周期。

## 何时必须触发
- 用户直接提到：EasyFramework 的 Procedure、ProcedureManager、ProcedureBase、流程、状态机、游戏流程、InitProcedure。
- 虽未点名模块，但需求本质落在 EF.Procedure 流程管理模块 的职责范围（例如注册、生命周期、依赖关系、性能或稳定性问题）。
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
流程管理器，管理游戏流程状态切换，基于状态机模式实现。

## 核心类型

| 类型 | 说明 |
|------|------|
| `IProcedureManager` | 流程管理器接口 |
| `ProcedureManager` | 流程管理器实现 |
| `ProcedureBase` | 流程基类 |

## 使用示例

### 定义流程

```csharp
public class InitProcedure : ProcedureBase
{
    protected override void OnEnter(ProcedureOwner owner)
    {
        base.OnEnter(owner);
        // 初始化流程逻辑
    }
    
    protected override void OnUpdate(ProcedureOwner owner, float elapseSeconds)
    {
        base.OnUpdate(owner, elapseSeconds);
        // 检查切换条件
        if (IsInitialized())
        {
            owner.ChangeState<MainMenuProcedure>();
        }
    }
}

public class MainMenuProcedure : ProcedureBase
{
    protected override void OnEnter(ProcedureOwner owner)
    {
        base.OnEnter(owner);
        // 打开主菜单
    }
}
```

### 流程切换

```csharp
// 在流程内部切换
owner.ChangeState<GameProcedure>();

// 从外部切换
procedureManager.ChangeState<GameProcedure>();
```

## 流程生命周期

```
ChangeState<TProcedure>()
    ↓
OnExit() [当前流程]
    ↓
OnEnter() [新流程]
    ↓
[每帧 OnUpdate()]
    ↓
ChangeState() → 循环
```

## 常见流程

| 流程 | 说明 |
|------|------|
| `InitProcedure` | 初始化流程 |
| `MainMenuProcedure` | 主菜单流程 |
| `GameProcedure` | 游戏流程 |
| `PauseProcedure` | 暂停流程 |
