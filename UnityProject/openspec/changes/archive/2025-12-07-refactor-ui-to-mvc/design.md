# Design: UI 框架 MVC 重构

## Context
当前 EasyFramework 的 UI 模块使用 MVVM 模式，包含 `UIView` 和 `UIViewModel` 两个核心基类。用户希望改用 MVC 模式，并且 UI 层的 Model 数据层需要与现有的 `ModelManager` 框架集成，而不是独立定义。

### 约束条件
- 需要保持与现有 `UIManager` 生命周期管理的兼容性
- **Model 层必须使用 ModelManager 框架管理**
- 需要支持 UniTask 异步操作
- 需要支持 Unity MonoBehaviour 生命周期
- 层级访问控制必须在编译时强制执行

## Goals / Non-Goals

### Goals
- 实现 MVC 分层架构
- **UI Model 数据复用 ModelManager 框架**
- View 层通过 ModelManager 获取只读数据视图
- Controller 层通过 ModelManager 获取完整 Model
- 保持数据绑定能力

### Non-Goals
- 不改变资源加载机制
- 不改变 UI 层级管理
- 不引入新的依赖库
- 不为 UI 层单独定义 Model 基类

## Decisions

### Decision 1: 复用 ModelManager 框架

**选择**: UI 层的 Model 数据通过 ModelManager 管理，不在 UI 框架中创建独立的 UIModel

**原因**:
- 避免数据层重复
- 保持架构一致性
- ModelManager 已提供完善的 Model-View 分离机制

**实现**:
- UIRuntimeContext 持有 ModelManager 引用
- Controller 通过 `Context.ModelManager.GetModel<T>()` 获取完整 Model
- View 通过 `Context.ModelManager.Get<TView>()` 获取只读视图

### Decision 2: MVC 类型结构

```
ModelManager (已有框架)
    └── ModelBase<TView> (数据层)
            └── TView (只读视图接口)

UIView (抽象类，通过 ModelManager 获取只读视图)

UIController (抽象类，通过 ModelManager 获取 Model，持有 View)
```

### Decision 3: 依赖注入方向

```
UIManager (持有 ModelManager)
    │
    ├── 创建 View (注入 Context，可访问 ModelManager 只读视图)
    │
    └── 创建 Controller (注入 Context + View，可访问 ModelManager 完整 Model)
```

### Decision 4: 生命周期映射

| 旧 (MVVM) | 新 (MVC) |
|-----------|----------|
| UIViewModel.OnInitialize | Controller.OnInitialize |
| UIViewModel.OnEnter | Controller.OnEnter |
| UIViewModel.OnRefresh | Controller.OnRefresh |
| UIViewModel.OnExit | Controller.OnExit |
| UIViewModel.OnUpdate | Controller.OnUpdate |
| UIView.OnOpen | UIView.OnOpen |
| UIView.OnClose | UIView.OnClose |

## 核心类设计

### UIRuntimeContext (修改后)
```csharp
public sealed class UIRuntimeContext
{
    public IUIManager Manager { get; }
    public ModelManager ModelManager { get; }  // 新增
    public UIWindowDescriptor Descriptor { get; }
    public Transform LayerRoot { get; }
}
```

### UIView (修改后)
```csharp
public abstract class UIView : MonoBehaviour
{
    protected UIRuntimeContext Context { get; }
    
    // 通过 ModelManager 获取只读视图
    protected TView GetModelView<TView>() where TView : class
    {
        return Context.ModelManager.Get<TView>();
    }
}
```

### UIController (修改后)
```csharp
public abstract class UIController
{
    protected UIView View { get; }
    protected UIRuntimeContext Context { get; }
    
    // 通过 ModelManager 获取完整 Model
    protected TModel GetModel<TModel>() where TModel : ModelBase
    {
        return Context.ModelManager.GetModel<TModel>();
    }
}
```

### UIWindowDescriptor (简化)
```csharp
public sealed class UIWindowDescriptor
{
    // 只需要 View 和 Controller 工厂，Model 由 ModelManager 管理
    public Type ViewType { get; }
    public Func<UIController> ControllerFactory { get; }
}
```

## 层级访问控制

| 层级 | 可访问 | 实现方式 |
|------|--------|----------|
| Model (ModelBase) | 无 UI 层引用 | ModelManager 框架隔离 |
| View | ModelManager 只读视图 | `ModelManager.Get<TView>()` |
| Controller | ModelManager 完整 Model + View | `ModelManager.GetModel<T>()` |

## Risks / Trade-offs

### Risk 1: 破坏性变更
- **风险**: 所有现有 UI 实现需要迁移
- **缓解**: 提供迁移指南和示例代码

### Trade-off: 集成 vs 独立
- 选择与 ModelManager 集成意味着 UI 数据必须在 ModelManager 中注册
- 但保证了数据层的统一性和一致性

## Migration Plan

1. **阶段 1**: 实现新的 MVC 基类（已完成）
2. **阶段 2**: 迁移现有 UI 实现
3. **阶段 3**: 移除旧的 UIViewModel 代码（已完成）
