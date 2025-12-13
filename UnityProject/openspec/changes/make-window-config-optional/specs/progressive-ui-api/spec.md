# progressive-ui-api Capability Specification

## Purpose
提供渐进式复杂度的UI窗口打开API，通过多个重载方法从简单调用到完全配置，优化开发者体验。

## ADDED Requirements

### Requirement: 极简UI窗口打开方法
IUIManager SHALL 提供只需要资源路径的最简化窗口打开方法，使用智能默认值。

#### Scenario: 最简单窗口打开调用
- **GIVEN** 一个标准的游戏窗口（如背包、设置等）
- **WHEN** 开发者调用 `OpenWindowAsync<InventoryView, InventoryController>("Inventory")`
- **THEN** 系统使用默认配置打开窗口：Normal层级，缓存关闭，单实例模式

#### Scenario: 智能默认值应用
- **GIVEN** 使用最简调用方式
- **WHEN** 系统创建窗口描述符
- **THEN** 自动应用：layer=UILayer.Normal, cacheOnClose=true, allowMultiple=false

#### Scenario: 常见用例覆盖
- **GIVEN** 项目中90%的窗口使用标准配置
- **WHEN** 使用最简API
- **THEN** 无需指定任何配置参数即可正确工作

---

### Requirement: 层级指定重载方法
IUIManager SHALL 提供可指定UI层级的重载方法，用于需要特定层级的窗口。

#### Scenario: 弹窗层级窗口打开
- **GIVEN** 一个确认对话框需要在Popup层显示
- **WHEN** 开发者调用 `OpenWindowAsync<ConfirmDialog, ConfirmController>("Confirm", UILayer.Popup)`
- **THEN** 窗口在Popup层打开，其他配置使用默认值

#### Scenario: 覆盖层窗口打开
- **GIVEN** 一个加载界面需要在Overlay层显示
- **WHEN** 开发者调用 `OpenWindowAsync<LoadingView, LoadingController>("Loading", UILayer.Overlay)`
- **THEN** 窗口在Overlay层打开，覆盖所有其他UI

#### Scenario: 背景层窗口打开
- **GIVEN** 一个背景装饰窗口需要在Background层显示
- **WHEN** 开发者调用 `OpenWindowAsync<BackgroundView, BackgroundController>("Background", UILayer.Background)`
- **THEN** 窗口在Background层打开，位于所有其他UI之下

---

### Requirement: 完全配置重载方法
IUIManager SHALL 保持完全配置版本的重载方法，用于需要精确控制的高级场景。

#### Scenario: 入口界面特殊配置
- **GIVEN** 入口界面需要禁用缓存以节省内存
- **WHEN** 开发者调用完全配置版本设置cacheOnClose=false
- **THEN** 窗口关闭时直接销毁而不缓存

#### Scenario: 多实例窗口配置
- **GIVEN** 某些窗口需要允许多个实例同时存在
- **WHEN** 开发者调用完全配置版本设置allowMultiple=true
- **THEN** 系统允许同一窗口类型的多个实例

#### Scenario: 复杂场景完全控制
- **GIVEN** 高级用户需要精确控制所有窗口行为
- **WHEN** 使用完全配置版本API
- **THEN** 可以指定所有参数，获得最大灵活性

---

### Requirement: 渐进式API发现
系统 SHALL 支持开发者从简单到复杂的渐进式API学习和使用路径。

#### Scenario: IntelliSense引导发现
- **GIVEN** 开发者在IDE中输入OpenWindowAsync
- **WHEN** 查看可用的重载方法
- **THEN** 按复杂度顺序显示：简单→层级→完全配置

#### Scenario: 编译时重载解析
- **GIVEN** 开发者调用任何重载版本
- **WHEN** 编译器解析方法调用
- **THEN** 精确匹配到对应的重载，无歧义

#### Scenario: 文档渐进式组织
- **GIVEN** API文档和示例
- **WHEN** 开发者学习UI框架
- **THEN** 从最简单的用例开始，逐步介绍更复杂的场景

---

## MODIFIED Requirements

### Requirement: UI窗口API重载方法签名
IUIManager的OpenWindowAsync方法 SHALL 包含三个层次的重载，支持渐进式复杂度调用。

#### Scenario: 三层重载方法定义
- **GIVEN** IUIManager接口
- **THEN** 包含以下重载方法：

```csharp
// Level 1: 极简调用
UniTask<UIWindowHandle> OpenWindowAsync<TView, TController>(
    string location,
    object userData = null,
    CancellationToken cancellationToken = default)
    where TView : UIView
    where TController : UIController, new()

// Level 2: 指定层级
UniTask<UIWindowHandle> OpenWindowAsync<TView, TController>(
    string location,
    UILayer layer,
    object userData = null,
    CancellationToken cancellationToken = default)
    where TView : UIView
    where TController : UIController, new()

// Level 3: 完全配置
UniTask<UIWindowHandle> OpenWindowAsync<TView, TController>(
    string location,
    UILayer layer,
    bool cacheOnClose,
    bool allowMultiple,
    object userData = null,
    CancellationToken cancellationToken = default)
    where TView : UIView
    where TController : UIController, new()
```

#### Scenario: 默认值一致性
- **GIVEN** 各个重载方法
- **WHEN** 使用简化调用
- **THEN** 默认值与UIWindowDescriptor.Create的默认值保持一致

#### Scenario: 方法行为一致性
- **GIVEN** 同样的窗口类型和配置
- **WHEN** 分别通过不同重载调用
- **THEN** 窗口行为完全相同，只是调用方式不同

---

### Requirement: 智能默认值配置
系统 SHALL 基于最佳实践和使用模式提供智能的默认参数值。

#### Scenario: 默认层级选择
- **GIVEN** 未指定layer参数的调用
- **WHEN** 系统需要确定窗口层级
- **THEN** 使用UILayer.Normal作为默认值

#### Scenario: 默认缓存策略
- **GIVEN** 未指定cacheOnClose参数的调用
- **WHEN** 系统需要确定缓存行为
- **THEN** 使用true作为默认值，优化性能

#### Scenario: 默认实例策略
- **GIVEN** 未指定allowMultiple参数的调用
- **WHEN** 系统需要确定实例控制
- **THEN** 使用false作为默认值，实现单实例模式

---

## 依赖关系
- **ui-window-api**: 依赖simplify-ui-window-registration中定义的基础API结构
- **ui-framework**: 依赖现有UI框架的层级和缓存机制
- **type-safety**: 依赖泛型约束确保编译时类型安全

## 向后兼容性
- **现有API**: 完全兼容现有的所有OpenWindowAsync重载
- **行为一致**: 新重载与现有完整参数版本行为相同
- **无破坏性变更**: 纯新增功能，不修改现有接口