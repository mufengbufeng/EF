# UI Framework MVC Specification

## ADDED Requirements

### Requirement: MVC 层级架构
UI 框架 SHALL 采用 MVC（Model-View-Controller）分层架构，将 UI 逻辑分离为三个独立层级。

#### Scenario: 创建 MVC UI 窗口
- **WHEN** 开发者创建新的 UI 窗口
- **THEN** 需要实现三个类：继承 UIModel 的数据类、继承 UIView 的视图类、继承 UIController 的控制器类

#### Scenario: UIManager 管理 MVC 实例
- **WHEN** UIManager 打开一个窗口
- **THEN** 依次创建 Model、View、Controller 实例并正确注入依赖

---

### Requirement: Model 层访问隔离
UIModel SHALL 完全隔离于 View 和 Controller，不持有也不可访问任何 View 或 Controller 的引用。

#### Scenario: Model 类不可访问 View
- **GIVEN** 一个继承 UIModel 的数据类
- **WHEN** 开发者尝试在 Model 中获取 View 引用
- **THEN** 编译器报错，因为 UIModel 基类未提供任何 View 访问方法

#### Scenario: Model 类不可访问 Controller
- **GIVEN** 一个继承 UIModel 的数据类
- **WHEN** 开发者尝试在 Model 中获取 Controller 引用
- **THEN** 编译器报错，因为 UIModel 基类未提供任何 Controller 访问方法

---

### Requirement: View 层只读 Model 访问
UIView SHALL 只能通过只读接口 `IUIModelReadOnly` 访问 Model 数据，不可修改 Model 状态。

#### Scenario: View 读取 Model 数据
- **GIVEN** 一个已绑定 Model 的 View
- **WHEN** View 需要显示数据
- **THEN** View 通过 `IUIModelReadOnly` 接口读取数据

#### Scenario: View 不可修改 Model
- **GIVEN** 一个继承 UIView 的视图类
- **WHEN** 开发者尝试调用 Model 的写入方法
- **THEN** 编译器报错，因为 View 只持有 `IUIModelReadOnly` 接口

#### Scenario: View 不可访问 Controller
- **GIVEN** 一个继承 UIView 的视图类
- **WHEN** 开发者尝试获取 Controller 引用
- **THEN** 编译器报错，因为 UIView 基类未提供任何 Controller 访问方法

---

### Requirement: Controller 层完整访问权限
UIController SHALL 持有 Model（完整读写接口 `IUIModel`）和 View 的引用，负责协调数据和视图。

#### Scenario: Controller 修改 Model 数据
- **GIVEN** 一个已初始化的 Controller
- **WHEN** 用户触发某个操作
- **THEN** Controller 调用 `IUIModel` 接口方法更新数据

#### Scenario: Controller 操作 View
- **GIVEN** 一个已初始化的 Controller
- **WHEN** 需要触发 View 的特定行为
- **THEN** Controller 调用 View 的公开方法

#### Scenario: Controller 响应 View 事件
- **GIVEN** View 上有用户交互元素（如按钮）
- **WHEN** 用户点击按钮
- **THEN** Controller 的事件处理方法被调用

---

### Requirement: 只读 Model 接口
框架 SHALL 提供 `IUIModelReadOnly` 接口，仅暴露数据读取和属性变更通知能力。

#### Scenario: 接口定义属性变更事件
- **GIVEN** `IUIModelReadOnly` 接口
- **THEN** 接口包含 `PropertyChanged` 事件用于数据绑定

#### Scenario: 接口不包含写入方法
- **GIVEN** `IUIModelReadOnly` 接口
- **THEN** 接口不定义任何修改数据状态的方法

---

### Requirement: 完整 Model 接口
框架 SHALL 提供 `IUIModel` 接口，继承 `IUIModelReadOnly` 并增加生命周期管理方法。

#### Scenario: 接口继承只读接口
- **GIVEN** `IUIModel` 接口
- **THEN** 接口继承自 `IUIModelReadOnly`

#### Scenario: 接口包含生命周期方法
- **GIVEN** `IUIModel` 接口
- **THEN** 接口定义 `Initialize()` 和 `Release()` 方法

---

### Requirement: MVC 生命周期管理
UIManager SHALL 按照特定顺序调用 MVC 各层的生命周期方法。

#### Scenario: 窗口打开生命周期
- **WHEN** UIManager 打开一个窗口
- **THEN** 按以下顺序调用：Model.Initialize → View.Initialize → Controller.Initialize → Controller.OnEnter → View.OnOpen

#### Scenario: 窗口关闭生命周期
- **WHEN** UIManager 关闭一个窗口
- **THEN** 按以下顺序调用：Controller.OnExit → View.OnClose → Controller.Release → View.Release → Model.Release

#### Scenario: 窗口刷新
- **WHEN** UIManager 刷新一个已打开的窗口
- **THEN** 调用 Controller.OnRefresh，由 Controller 决定是否需要更新 View

---

### Requirement: UIWindowDescriptor MVC 支持
UIWindowDescriptor SHALL 支持注册 Model 类型、View 类型和 Controller 类型。

#### Scenario: 注册 MVC 类型
- **GIVEN** 创建新的 UIWindowDescriptor
- **WHEN** 配置窗口描述信息
- **THEN** 可以指定 ModelType、ViewType、ControllerType 以及对应的工厂方法
