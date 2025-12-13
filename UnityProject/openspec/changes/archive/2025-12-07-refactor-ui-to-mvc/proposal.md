# Change: 将 UI 框架从 MVVM 重构为 MVC 模式

## Why
当前 UI 框架采用 MVVM 模式（UIView + UIViewModel），但用户希望改用 MVC 模式，并且需要在框架层面强制控制各层之间的访问权限，确保架构分层的严格性。

## What Changes
- **BREAKING**: 移除现有的 `UIViewModel` 基类，替换为 `UIModel` 和 `UIController`
- **BREAKING**: 修改 `UIView` 基类，移除对 ViewModel 的直接引用
- 新增 `UIModel` 基类 - 纯数据层，不可访问 View 和 Controller
- 新增 `UIController` 基类 - 控制器层，可访问 Model 和 View
- 修改 `UIWindowDescriptor` 以支持 MVC 三层注册
- 修改 `UIManager` 以管理 MVC 生命周期
- 通过接口隔离确保层级访问控制

## Impact
- Affected specs: `ui-framework`（新建）
- Affected code:
  - `Assets/EF/EFRuntime/UI/UIView.cs`
  - `Assets/EF/EFRuntime/UI/UIViewModel.cs` → 移除/重构
  - `Assets/EF/EFRuntime/UI/UIManager.cs`
  - `Assets/EF/EFRuntime/UI/UIWindowDescriptor.cs`
  - `Assets/EF/EFRuntime/UI/IUIManager.cs`
  - 所有使用现有 UI 框架的业务代码

## 层级访问控制设计

| 层级 | 可访问 | 不可访问 |
|------|--------|----------|
| Model | 无其他层 | View, Controller |
| View | Model (只读) | Controller |
| Controller | Model (读写), View | - |

实现方式：
1. `IUIModelReadOnly` 接口 - 提供给 View 的只读数据访问
2. `IUIModel` 接口 - 继承只读接口，增加写入方法，仅供 Controller 使用
3. Controller 通过构造函数注入获得 Model 和 View 引用
4. View 通过只读接口获取 Model，无法获取 Controller 引用
