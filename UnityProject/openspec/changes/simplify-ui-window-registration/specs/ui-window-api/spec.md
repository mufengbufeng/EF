# ui-window-api Capability Specification

## Purpose
提供简化的UI窗口打开API，将窗口描述符参数集成到OpenWindowAsync方法中，实现即开即用的窗口管理。

## ADDED Requirements

### Requirement: 泛型窗口打开方法
IUIManager SHALL 提供泛型OpenWindowAsync方法，接受View和Controller类型参数以及窗口配置。

#### Scenario: 直接打开窗口无需预注册
- **GIVEN** 一个实现了UIView的EntryView类和实现了UIController的EntryController类
- **WHEN** 开发者调用 `OpenWindowAsync<EntryView, EntryController>("EntryView", UILayer.Normal)`
- **THEN** 系统自动创建窗口描述符并成功打开窗口

#### Scenario: 类型安全保证
- **GIVEN** 开发者尝试使用不兼容的类型参数
- **WHEN** TView不继承自UIView或TController不继承自UIController
- **THEN** 编译器报错，防止运行时类型错误

#### Scenario: 默认参数简化调用
- **GIVEN** 大多数窗口使用标准配置
- **WHEN** 开发者调用 `OpenWindowAsync<EntryView, EntryController>("EntryView")`
- **THEN** 系统使用默认值：layer=Normal, cacheOnClose=true, allowMultiple=false

---

### Requirement: 自动窗口标识生成
系统 SHALL 基于View类型自动生成唯一的窗口标识符，无需手动管理窗口名称。

#### Scenario: 类型全名作为窗口标识
- **GIVEN** 一个EntryView类型
- **WHEN** 系统需要生成窗口标识符
- **THEN** 使用 `typeof(EntryView).FullName` 作为唯一标识

#### Scenario: 避免名称冲突
- **GIVEN** 多个命名空间中存在同名View类
- **WHEN** 系统生成窗口标识符
- **THEN** 完整类型名确保唯一性，避免冲突

---

### Requirement: 向后兼容支持
系统 SHALL 保持现有基于字符串名称的OpenWindowAsync方法，确保现有代码继续工作。

#### Scenario: 现有字符串API继续工作
- **GIVEN** 现有代码使用 `OpenWindowAsync("EntryView")`
- **WHEN** 系统升级到新版本
- **THEN** 方法正常工作，无需修改代码

#### Scenario: 过时API警告
- **GIVEN** 开发者使用旧的RegisterWindow + OpenWindowAsync模式
- **WHEN** 编译代码
- **THEN** 显示过时警告，引导使用新API

---

### Requirement: 内部窗口管理优化
UIManager SHALL 内部优化窗口注册和管理逻辑，支持动态窗口创建。

#### Scenario: 懒加载窗口描述符
- **GIVEN** 使用新的泛型OpenWindowAsync方法
- **WHEN** 首次打开某个窗口类型
- **THEN** 系统自动创建并缓存窗口描述符

#### Scenario: 复用已创建的描述符
- **GIVEN** 某个窗口类型已经打开过
- **WHEN** 再次打开相同类型的窗口
- **THEN** 系统复用已缓存的窗口描述符，提高性能

#### Scenario: 缓存机制兼容性
- **GIVEN** 设置cacheOnClose=true的窗口
- **WHEN** 窗口关闭时
- **THEN** 系统正确缓存窗口实例，下次打开时复用

---

## MODIFIED Requirements

### Requirement: OpenWindowAsync方法重载
IUIManager的OpenWindowAsync方法 SHALL 支持多种调用方式，包括泛型和传统字符串参数。

#### Scenario: 泛型重载方法签名
- **GIVEN** IUIManager接口
- **THEN** 包含以下方法签名：
```csharp
UniTask<UIWindowHandle> OpenWindowAsync<TView, TController>(
    string location,
    UILayer layer = UILayer.Normal,
    bool cacheOnClose = true,
    bool allowMultiple = false,
    object userData = null,
    CancellationToken cancellationToken = default)
    where TView : UIView
    where TController : UIController, new()
```

#### Scenario: 方法重载共存
- **GIVEN** IUIManager接口
- **WHEN** 查看可用的OpenWindowAsync方法
- **THEN** 同时存在泛型版本和字符串参数版本的重载

---

## 相关能力依赖
- **ui-framework**: 依赖现有的UI框架基础架构
- **ui-lifecycle**: 依赖窗口生命周期管理机制
- **ui-caching**: 依赖窗口缓存和资源管理