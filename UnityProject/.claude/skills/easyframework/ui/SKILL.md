---
name: ef-ui
description: EasyFramework UI 管理模块。使用此 skill 当用户提到 EasyFramework 的 UI、UIManager、UIView、UIController、MVC、数据绑定、UIWindowDescriptor、UILayer、BindProperty 时。在实现、重构、排错、测试或设计该模块相关功能时必须优先使用此 skill，而不是只在用户显式点名模块时才触发。
---

# EF.UI UI 管理模块

## 模块定位
该 skill 用于处理 EF.UI UI 管理模块 的实现、扩展、故障排查与重构任务。回答时先确认业务目标，再映射到该模块的核心抽象与生命周期。

## 何时必须触发
- 用户直接提到：EasyFramework 的 UI、UIManager、UIView、UIController、MVC、数据绑定、UIWindowDescriptor、UILayer、BindProperty。
- 虽未点名模块，但需求本质落在 EF.UI UI 管理模块 的职责范围（例如注册、生命周期、依赖关系、性能或稳定性问题）。
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
基于 MVC 架构的 Unity UI 管理系统，提供完整的 UI 生命周期管理、数据绑定和层级控制。

## 核心类型

| 类型 | 说明 |
|------|------|
| `IUIManager` | UI 管理器接口 |
| `UIManager` | UI 管理器实现 |
| `UIView` | 视图基类（MonoBehaviour） |
| `UIController` | 控制器基类 |
| `UIWindowDescriptor` | 窗口描述符 |
| `UIWindowHandle` | 窗口句柄 |
| `UIRuntimeContext` | 运行时上下文 |
| `UILayer` | UI 层级枚举 |

## 使用示例

### 创建 View

```csharp
public class MainMenuView : UIView
{
    [SerializeField] private Text playerNameText;
    [SerializeField] private Button startButton;
    
    protected override void OnInitialize()
    {
        startButton.onClick.AddListener(OnStartClicked);
    }
    
    protected override void OnBindings()
    {
        var playerData = GetModelData<IPlayerData>();
        BindProperty(playerModel, x => x.Gold, value => goldText.text = $"金币: {value}");
    }
    
    protected override void OnRefresh(object userData)
    {
        if (TryGetModelData<IPlayerData>(out var player))
        {
            playerNameText.text = player.Name;
        }
    }
    
    protected override void OnRelease()
    {
        startButton.onClick.RemoveListener(OnStartClicked);
    }
}
```

### 创建 Controller

```csharp
public class MainMenuController : UIController
{
    private PlayerModel _playerModel;
    
    protected override void OnInitialize()
    {
        _playerModel = GetModel<PlayerModel>();
    }
    
    public void OnStartButtonClicked()
    {
        _playerModel.AddGold(100);
    }
}
```

### 打开窗口

```csharp
// 级别1：最简单
var handle = await uiManager.OpenWindowAsync<MainMenuView, MainMenuController>(
    "UI/MainMenuPrefab");

// 级别2：指定层级和缓存
var handle = await uiManager.OpenWindowAsync<DialogView, DialogController>(
    "UI/DialogPrefab",
    UILayer.Popup,
    cacheOnClose: false);

// 级别3：完整控制
var descriptor = UIWindowDescriptor.Create<SettingsView, SettingsController>(
    name: "Settings",
    location: "UI/SettingsPrefab",
    layer: UILayer.Overlay);
uiManager.RegisterWindow(descriptor);
await uiManager.OpenWindowAsync("Settings");
```

### 关闭窗口

```csharp
await handle.CloseAsync();
// 或
await uiManager.CloseWindowAsync("MainMenu");
```

## UI 层级

| 层级 | 说明 |
|------|------|
| `Background` | 背景层 |
| `Normal` | 普通层（默认） |
| `Popup` | 弹窗层 |
| `Overlay` | 覆盖层（最上层） |

## 数据绑定

```csharp
protected override void OnBindings()
{
    var model = Context.ModelManager.GetModel<PlayerModel>();
    
    // 属性绑定 - 数据变更自动刷新 UI
    BindProperty(model, x => x.Gold, value => goldText.text = $"金币: {value}");
    BindProperty(model, x => x.Level, value => levelText.text = $"等级: {value}");
}
```

## 生命周期

```
OpenWindowAsync()
    ↓
View.OnInitialize()
    ↓
View.OnBindings()
    ↓
Controller.OnInitialize()
    ↓
Controller.OnPrepareAsync() [异步]
    ↓
View.OnPrepareAsync() [异步]
    ↓
Controller.OnEnter()
    ↓
View.OnOpen()
    ↓
[每帧 Controller.OnUpdate() / View.OnUpdate()]
    ↓
CloseWindowAsync()
    ↓
Controller.OnExit()
    ↓
View.OnClose()
    ↓
[缓存或销毁]
```
