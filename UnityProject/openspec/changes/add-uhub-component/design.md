# UHubComponent 架构设计

## 核心设计理念

UHubComponent 采用**组合模式**而非继承，作为 UIView 的可选组件提供增强功能。这确保了与现有 MVC 架构的完全兼容性。

## 架构组件

### 1. UHubComponent (核心组件)
```csharp
// 伪代码示例
public class UHubComponent
{
    private UIView _owner;
    private ComponentBinder _binder;
    private List<IEventBinding> _eventBindings;
    
    // 自动组件绑定
    public void BindComponents();
    
    // 事件管理
    public void RegisterEventBinding(IEventBinding binding);
    public void ClearAllBindings();
}
```

**职责**：
- 协调组件自动绑定流程
- 管理所有事件绑定的生命周期
- 提供统一的清理接口

### 2. ComponentBinder (反射绑定器)
```csharp
// 伪代码示例  
public class ComponentBinder
{
    // 基于命名规范自动绑定字段和属性
    public void BindComponentsToFields(UIView target, ReferenceCollector collector);
    
    // 支持的命名模式：
    // _startBtn -> "StartBtn"
    // StartButton -> "StartButton"  
}
```

**职责**：
- 使用反射发现需要绑定的字段和属性
- 根据命名规范匹配 ReferenceCollector 中的组件
- 执行自动赋值操作

### 3. IEventBinding (事件绑定接口)
```csharp
// 伪代码示例
public interface IEventBinding
{
    void Bind();
    void Unbind();
}

// 具体实现
public class UnityEventBinding : IEventBinding { }
public class ActionEventBinding : IEventBinding { }
```

**职责**：
- 抽象不同类型的事件绑定操作
- 提供统一的绑定/解绑接口
- 支持扩展新的事件类型

## 生命周期集成

```
UIView.OnInitialize()
├── UHub = new UHubComponent(this)
├── UHub.BindComponents()  // 自动组件绑定
└── OnBindings()           // 用户自定义绑定逻辑

UIView.OnRelease()
├── UHub.ClearAllBindings() // 自动事件清理
└── base.OnRelease()
```

## 命名规范策略

### 基础命名规则

#### 字段命名 (下划线前缀)
- `private Button _startBtn` → 匹配 "StartBtn"
- `private Text _titleText` → 匹配 "TitleText"
- `private GameObject _playerIcon` → 匹配 "PlayerIcon"

#### 属性命名 (Pascal 命名)
- `public Button StartButton { get; set; }` → 匹配 "StartButton"
- `public Text TitleLabel { get; set; }` → 匹配 "TitleLabel"

### 智能类型推断 (Unity 配置)

通过 UHubBindingConfig (ScriptableObject) 配置后缀到类型的映射规则：

```csharp
// 配置示例
BindingRules:
  - Suffix: "Btn" | "Button" → typeof(Button)
  - Suffix: "Text" | "Label" → typeof(Text)
  - Suffix: "Img" | "Image" → typeof(Image) 
  - Suffix: "Slider" → typeof(Slider)
  - Suffix: "Toggle" → typeof(Toggle)
  - Suffix: "Input" → typeof(InputField)
  - Suffix: "Go" | "Obj" → typeof(GameObject)
```

#### 智能绑定示例
```csharp
// 字段名称自动推断组件类型
private _startBtn;           // 后缀 "Btn" → 自动类型 Button
private _titleText;          // 后缀 "Text" → 自动类型 Text  
private _playerImg;          // 后缀 "Img" → 自动类型 Image
private _volumeSlider;       // 后缀 "Slider" → 自动类型 Slider
```

### 配置系统设计

#### UHubBindingConfig (ScriptableObject)
```csharp
[CreateAssetMenu(fileName = "UHubBindingConfig", menuName = "EF/UI/UHub Binding Config")]
public class UHubBindingConfig : ScriptableObject
{
    [Header("后缀到类型映射规则")]
    public List<BindingRule> Rules = new List<BindingRule>();
    
    [Header("全局设置")]
    public BindingFailureMode FailureMode = BindingFailureMode.Warning;
    public bool EnableTypeInference = true;
    public bool CaseSensitive = false;
}

[Serializable]
public class BindingRule
{
    [Header("匹配规则")]
    public string[] Suffixes;           // 支持的后缀列表
    public ComponentType TargetType;    // 目标组件类型
    public bool IgnoreCase = true;      // 忽略大小写
    
    [Header("高级选项")]
    public bool RequireExactMatch;      // 需要精确匹配
    public string CustomTypeName;       // 自定义类型名称
}
```

#### 配置文件位置
```
Assets/
  Settings/
    UHub/
      DefaultBindingConfig.asset    // 全局默认配置
      ProjectSpecificConfig.asset   // 项目特定配置
```

### 灵活性支持

#### 属性标注
```csharp
// 显式指定组件名称
[UHubBind("CustomName")]
private Button _specialBtn;

// 显式指定组件类型 
[UHubBind(typeof(Image))]
private _playerAvatar;

// 完全自定义
[UHubBind("PlayerHealthBar", typeof(Slider))]
private _healthBar;

// 排除自动绑定
[UHubIgnore]
private Button _manualBtn;
```

#### 运行时规则覆盖
```csharp
protected override void OnInitialize()
{
    // 临时覆盖配置规则
    UHub.OverrideRule("CustomBtn", typeof(Button));
    UHub.OverrideRule("SpecialImg", typeof(RawImage));
}
```

## 事件绑定策略

### 1. 声明式绑定
```csharp
protected override void OnBindings()
{
    // UHub 提供的便利方法
    UHub.BindEvent(_startBtn.onClick, OnStartButtonClicked);
    UHub.BindEvent(PlayerModel.LevelChanged, OnPlayerLevelChanged);
}
```

### 2. 自动发现绑定 (高级功能)
```csharp
// 通过方法命名自动绑定
private void OnStartBtn() { } // 自动绑定到 _startBtn.onClick
private void OnCloseBtn() { } // 自动绑定到 _closeBtn.onClick
```

## 性能考虑

### 反射优化
- **初始化阶段**：一次性使用反射完成所有绑定
- **运行时阶段**：不使用反射，直接调用委托
- **缓存机制**：缓存反射结果，避免重复计算

### 内存管理
- 使用弱引用避免循环引用
- 确保事件解绑防止内存泄漏
- 支持对象池复用 (如果需要)

## 错误处理

### 绑定失败策略
```csharp
public enum BindingFailureMode
{
    Silent,      // 静默忽略
    Warning,     // 输出警告日志
    Exception    // 抛出异常
}
```

### 调试支持
- 详细的绑定日志输出
- 组件匹配状态报告
- 事件绑定状态检查工具

## 扩展性设计

### 自定义绑定器
```csharp
public interface IComponentBinder
{
    bool TryBind(FieldInfo field, ReferenceCollector collector);
}

// 允许注册自定义绑定器
UHubComponent.RegisterBinder<CustomComponentBinder>();
```

### 事件类型扩展
```csharp
// 支持新的事件绑定类型
public class TweenEventBinding : IEventBinding
{
    // 支持 DOTween 事件绑定
}
```

## 向后兼容性

UHubComponent 设计为**完全可选**：
- 现有 UIView 无需任何修改即可工作
- 开发者可以选择性地启用 UHub 功能  
- 传统手动绑定方式继续有效
- 可以在同一个项目中混合使用两种方式

这种设计确保了平滑的迁移路径和最小的破坏性变更。