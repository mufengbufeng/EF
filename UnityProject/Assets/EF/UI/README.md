# EF W-Framework UI

本目录将 GreatClock W-Framework UI 封装为按需程序集 `EF.UI`，并接入 `EF.Base` 提供的模块生命周期。项目不再保留 EF MVC UI 流程，`IWFrameworkUIManager` 是唯一注册到 `ModuleSystem` 的 UI 管理器；上游五个 GreatClock 依赖均以适配后的源码纳入 `Assets/EF`，不通过 Git Package Manager 导入。

## 源码来源与许可证

| 来源 | 固定提交 | 本次用途 |
| --- | --- | --- |
| `greatclock/w-framework` | `636bc77dab200b008d6fe4a2b53a96e9c5461e56` | UI 逻辑基类、自动释放、内容绑定、Toggle 绑定 |
| `greatclock/unity_ui_manager` | `a89e86af22fb703ee2f281cb75354d5813581a07` | 堆叠/分组/焦点/异步准备 UI 管理器及编辑器工具 |
| `greatclock/unity_collections` | `864c1ff3a3cd2fedcf4ba34bdcc8f033c7918888` | 焦点和动画使用的优先级队列 |
| `greatclock/data_driven` | `5d89a7310bd81d74581a72cdea469bb3e7ad2299` | 数据节点、事件、绑定扩展与代码生成器 |
| `greatclock/serialize_component_tool` | `2f35e21146ce3a9f0cdf8eaef1a6ba4c5a808fbb` | 序列化组件绑定编辑器工具 |
| `greatclock/unity_utils` | `734aaeac97634287b018fc81db8ae88d12842d26` | UI 开关动画及 Inspector 属性绘制器 |

`w-framework`、`unity_collections`、`data_driven`、`unity_ui_manager` 和 `unity_utils` 使用 MIT 许可证，完整文本保存在 [LICENSE](LICENSE)。`serialize_component_tool` 的固定上游提交未声明许可证；它按本项目需求以源码方式纳入，发布前应向上游确认授权。完整来源清单见 [EF 第三方声明](../../THIRD_PARTY_NOTICES.md)。

## EF 集成方式

- `IWFrameworkUIManager` 由 `GameEntry` 注册到 `ModuleSystem`，不再注册或保留原有的 `IUIManager`、`UIView`、`UIController` MVC 流程。
- `Entry` 场景在原有 `UIRoot` 下序列化独立的 `WFrameworkUI` Canvas，并在该节点挂载原生 `UIRoot`；`GameLogicEntry.InitializeUI()` 只消费 `UIManager.Root`，不会运行时创建或重配 Canvas。
- 热更新入口将自身程序集传给加载器；因此仍按窗口命名约定解析 Logic，同时不会在同进程热更后误用旧程序集类型。
- `WFrameworkResourceLoader` 使用 `IResourceManager` 和 YooAsset 资源地址加载 Prefab、Sprite、Texture 与图集 Sprite，并在关闭时释放对应句柄。
- `WFrameworkUIManager.Update()` 使用新 Input System 分发 Escape；上游旧输入 API 已移除。
- UI 帧统一由 `ModuleSystem` → `WFrameworkUIManager.Update()` 驱动，依次处理屏幕/相机变化、Escape、UI 计时器、动画事件及窗口回调；不再使用 `UIRoot` 独立 Update 或工具内部的 UniTask 帧循环。
- Logic 可重写 `OnUpdate(float elapseSeconds, float realElapseSeconds)`；绑定组件继承 `UIWindowBase` 后可重写同名方法。仅已打开、可见、完成初始化且根节点活跃的窗口接收回调，Logic 先于 Window；禁用的 Window 组件不更新。
- 绑定生成器支持 `TextMeshProUGUI`，以 `Window` 结尾且使用默认 MonoBehaviour 基类的绑定自动继承 `UIWindowBase`；显式自定义基类保留不变。启动界面的状态文案使用 TMP，Prefab 必须提供 `Panel/StatusText` 的 `TMP_Text` 组件。
- 上游静态管理器增加了 `Shutdown()`，由 EF 模块生命周期清理窗口、动态绑定与静态状态。
- 数据驱动运行时位于 `Assets/EF/EFRuntime/DataDriven/`，命名空间为 `EF.DataDriven`；编辑器菜单为 `EF/Data Driven/Regenerate Code`。
- 组件绑定工具位于 `Assets/EF/EFEditor/Editor/SerializeComponentTool/`，编辑器菜单为 `EF/Serialize Component Tool/Open Binding Tool`。

## 使用方式

默认情况下，窗口 id 同时是 YooAsset 资源地址，窗口逻辑按名称自动解析：`InventoryWindow` 会加载地址为 `InventoryWindow` 的 Prefab，并使用 `InventoryLogic`。热更新逻辑可直接打开：

```csharp
GameLogicEntry.WFrameworkUI.Open("InventoryWindow");
```

需要在窗口打开完成后继续执行时，使用 `await GameLogicEntry.WFrameworkUI.OpenAsync("InventoryWindow")`。`Open` 的布尔值只表示请求是否受理；`OpenAsync` 在 `OnOpened` 时返回 `true`，请求被拒绝或打开前终止时返回 `false`。调用方可按业务需要附加取消令牌或超时；取消等待不会关闭窗口。

窗口逻辑可以继承 `UIStackLogicBase` 或 `UIFixedLogicBase`。项目窗口统一遵循上述命名和资源地址约定；需要不同映射时，应扩展 Loader 规则，而不是在业务层维护窗口注册表。编辑器侧的 UI Logic 生成器、Prefab 检查器和动画属性绘制器位于 `Assets/EF/EFEditor/Editor/WFramework/`。
