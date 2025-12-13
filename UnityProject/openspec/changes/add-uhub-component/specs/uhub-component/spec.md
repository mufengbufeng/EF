# uhub-component 规范

## 目的
为 UI 框架提供 UHubComponent 组件，实现自动化组件绑定和统一事件管理，简化 UIView 的开发和维护。

## ADDED Requirements

### Requirement: UHubComponent 自动组件绑定
UHubComponent SHALL 通过命名规范和反射自动将 UIView 中的字段和属性绑定到 ReferenceCollector 中的组件。

#### Scenario: 字段自动绑定
- **GIVEN** UIView 中定义了 `private Button _startBtn` 字段
- **AND** ReferenceCollector 中存在名为 "StartBtn" 的 Button 组件
- **WHEN** UHubComponent 执行自动绑定
- **THEN** `_startBtn` 字段被自动赋值为对应的 Button 组件引用

#### Scenario: 属性自动绑定  
- **GIVEN** UIView 中定义了 `public Text TitleLabel { get; set; }` 属性
- **AND** ReferenceCollector 中存在名为 "TitleLabel" 的 Text 组件
- **WHEN** UHubComponent 执行自动绑定
- **THEN** `TitleLabel` 属性被自动赋值为对应的 Text 组件引用

#### Scenario: 绑定失败处理
- **GIVEN** UIView 中定义了需要绑定的字段
- **AND** ReferenceCollector 中不存在对应名称的组件
- **WHEN** UHubComponent 执行自动绑定
- **THEN** 根据配置的失败策略输出日志警告或抛出异常

---

### Requirement: UHubComponent 生命周期管理
UHubComponent SHALL 跟随 UIView 的生命周期，在适当时机进行初始化和清理。

#### Scenario: 随 UIView 初始化
- **GIVEN** UIView 被创建并调用 OnInitialize
- **WHEN** UIView 拥有 UHubComponent
- **THEN** UHubComponent 自动执行组件绑定操作

#### Scenario: 随 UIView 释放
- **GIVEN** UIView 被销毁并调用 OnRelease
- **WHEN** UIView 拥有 UHubComponent  
- **THEN** UHubComponent 自动清理所有事件绑定并释放资源

---

### Requirement: UHubComponent 统一事件管理
UHubComponent SHALL 提供统一的事件绑定接口，自动管理事件的绑定和解绑，防止内存泄漏。

#### Scenario: Unity 事件绑定
- **GIVEN** 开发者需要绑定 Button.onClick 事件
- **WHEN** 使用 UHubComponent.BindEvent 方法绑定事件
- **THEN** 事件被正确绑定，并在 UIView 销毁时自动解绑

#### Scenario: C# 事件绑定
- **GIVEN** 开发者需要绑定 Model 的属性变更事件
- **WHEN** 使用 UHubComponent.BindEvent 方法绑定事件
- **THEN** 事件被正确绑定，并在 UIView 销毁时自动解绑

#### Scenario: 批量事件清理
- **GIVEN** UHubComponent 管理多个事件绑定
- **WHEN** UIView 需要释放资源
- **THEN** 所有事件绑定被一次性清理，无内存泄漏

---

### Requirement: 命名规范支持
UHubComponent SHALL 支持灵活的命名规范，允许字段/属性名称与组件名称的映射。

#### Scenario: 下划线字段命名
- **GIVEN** 字段名称为 `_startBtn`
- **WHEN** 执行组件绑定
- **THEN** 映射到名为 "StartBtn" 的组件 (移除下划线前缀，首字母大写)

#### Scenario: Pascal 属性命名
- **GIVEN** 属性名称为 `StartButton`  
- **WHEN** 执行组件绑定
- **THEN** 映射到名为 "StartButton" 的组件 (直接匹配)

#### Scenario: 自定义名称映射
- **GIVEN** 字段标注 `[UHubBind("CustomName")]`
- **WHEN** 执行组件绑定
- **THEN** 映射到名为 "CustomName" 的组件 (忽略字段名)

#### Scenario: 绑定排除
- **GIVEN** 字段标注 `[UHubIgnore]`
- **WHEN** 执行组件绑定  
- **THEN** 该字段被跳过，不执行自动绑定

---

### Requirement: UIView 集成支持
UIView 基类 SHALL 提供 UHubComponent 集成支持，使其成为可选的增强功能。

#### Scenario: UHub 属性访问
- **GIVEN** UIView 子类需要使用 UHub 功能
- **WHEN** 访问 `UHub` 属性
- **THEN** 自动创建并返回 UHubComponent 实例

#### Scenario: 传统方式兼容
- **GIVEN** UIView 子类不使用 UHub 功能
- **WHEN** 使用传统方式手动绑定组件和事件
- **THEN** 功能正常工作，无任何影响

#### Scenario: 混合使用支持
- **GIVEN** UIView 子类同时使用 UHub 和传统方式
- **WHEN** 部分组件用 UHub 自动绑定，部分手动绑定
- **THEN** 两种方式可以和谐共存，互不干扰

---

### Requirement: 性能和安全保证
UHubComponent SHALL 保证良好的性能表现和内存安全。

#### Scenario: 反射性能优化
- **GIVEN** UHubComponent 需要使用反射进行组件绑定
- **WHEN** 在 UIView 初始化阶段执行绑定
- **THEN** 反射操作仅在初始化时执行一次，运行时不使用反射

#### Scenario: 内存泄漏防护
- **GIVEN** 多个事件绑定到 UI 组件
- **WHEN** UIView 被销毁
- **THEN** 所有事件引用被正确清理，无循环引用或内存泄漏

#### Scenario: 错误恢复能力
- **GIVEN** 某个组件绑定失败
- **WHEN** 继续执行其他组件的绑定操作
- **THEN** 单个失败不影响其他组件的正常绑定

---

### Requirement: 智能类型推断配置
UHubComponent SHALL 支持通过 Unity ScriptableObject 配置后缀到组件类型的映射规则，实现智能类型推断。

#### Scenario: 后缀规则配置
- **GIVEN** UHubBindingConfig 中配置了 "Btn" 后缀映射到 Button 类型
- **AND** 字段定义为 `private _startBtn`
- **WHEN** UHubComponent 执行自动绑定
- **THEN** 自动推断 `_startBtn` 需要绑定 Button 类型的组件

#### Scenario: 多后缀支持
- **GIVEN** 配置规则支持 "Btn" 和 "Button" 都映射到 Button 类型
- **WHEN** 字段名为 `_closeBtn` 或 `_submitButton`
- **THEN** 都正确绑定到 Button 类型组件

#### Scenario: 配置文件加载
- **GIVEN** 项目中存在 UHubBindingConfig 资源文件
- **WHEN** UHubComponent 初始化
- **THEN** 自动加载并应用配置的绑定规则

#### Scenario: 默认规则回退
- **GIVEN** 某个后缀没有在配置中定义
- **WHEN** 执行组件绑定
- **THEN** 回退到默认的命名匹配规则 (不进行类型推断)

---

### Requirement: 运行时规则覆盖
UHubComponent SHALL 支持在运行时临时覆盖配置规则，提供更大的灵活性。

#### Scenario: 临时规则添加
- **GIVEN** 需要为特定界面使用不同的绑定规则
- **WHEN** 调用 `UHub.OverrideRule("CustomBtn", typeof(Button))`
- **THEN** 该规则在当前 UIView 实例中生效

#### Scenario: 规则优先级
- **GIVEN** 同时存在配置文件规则和运行时覆盖规则
- **WHEN** 执行组件绑定
- **THEN** 运行时覆盖规则优先于配置文件规则