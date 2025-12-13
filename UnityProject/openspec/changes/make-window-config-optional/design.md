# Design: Optional Window Configuration Parameters

## Architecture Overview

### Current State (from simplify-ui-window-registration proposal)
```
Application Code → OpenWindowAsync<TView,TController>(location, layer, cacheOnClose, allowMultiple, ...)
```

### Proposed State (Progressive API)
```
Application Code → Choose appropriate overload:
  ├── OpenWindowAsync<TView,TController>(location)                    [90% cases]
  ├── OpenWindowAsync<TView,TController>(location, layer)            [8% cases]
  └── OpenWindowAsync<TView,TController>(location, layer, cache, multi) [2% cases]
```

## Key Design Decisions

### 1. 渐进式复杂性API设计
**Decision**: 提供三个层次的重载方法，从简单到复杂

**Method Signatures**:
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

// Level 3: 完全配置 (与现有提案相同)
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

**Rationale**:
- **学习曲线**: 开发者可以从简单开始，按需增加复杂性
- **常见用例优化**: 90%的调用使用最简形式
- **不失灵活性**: 高级场景仍可完全控制

### 2. 智能默认值策略
**Decision**: 基于现有使用模式确定默认值

| Parameter | Default Value | Rationale |
|-----------|--------------|-----------|
| `layer` | `UILayer.Normal` | 大部分UI窗口使用Normal层 |
| `cacheOnClose` | `true` | 提高性能，减少GC压力 |
| `allowMultiple` | `false` | 大部分窗口单实例模式 |

**Exception Cases**:
- **Entry/Login windows**: 通常设置`cacheOnClose=false`
- **Dialog/Popup windows**: 可能需要`allowMultiple=true`
- **Overlay windows**: 需要`layer=UILayer.Overlay`

### 3. 方法解析策略
**Decision**: 使用C#重载解析规则确保最优匹配

**Resolution Order**:
1. 精确匹配参数数量和类型的重载
2. 具有可选参数的重载
3. 编译器错误（避免歧义）

**Implementation Approach**:
```csharp
// 内部统一调用完整版本
private async UniTask<UIWindowHandle> OpenWindowAsyncInternal<TView, TController>(
    string location,
    UILayer layer,
    bool cacheOnClose,
    bool allowMultiple,
    object userData,
    CancellationToken cancellationToken)
{
    // 核心实现逻辑
}

// 各重载方法调用内部方法
public UniTask<UIWindowHandle> OpenWindowAsync<TView, TController>(string location, ...)
    => OpenWindowAsyncInternal<TView, TController>(location, UILayer.Normal, true, false, ...);
```

### 4. 向后兼容保证
**Decision**: 完全向后兼容，不破坏现有API

**Compatibility Strategy**:
- 保留所有现有方法签名
- 新重载方法不影响现有调用的解析
- 行为完全一致，只是调用方式简化

## 使用模式分析

### 典型使用场景映射

| Scenario | Recommended Overload | Example |
|----------|---------------------|---------|
| **普通游戏窗口** | Level 1 | `OpenWindowAsync<InventoryView, InventoryController>("Inventory")` |
| **弹窗对话框** | Level 2 | `OpenWindowAsync<ConfirmDialog, ConfirmController>("Confirm", UILayer.Popup)` |
| **入口/登录界面** | Level 3 | `OpenWindowAsync<LoginView, LoginController>("Login", UILayer.Normal, false, false)` |
| **系统覆盖层** | Level 2 | `OpenWindowAsync<LoadingView, LoadingController>("Loading", UILayer.Overlay)` |

### API Discovery Path
```
Developer Journey:
1. Start with simplest call → immediate success
2. Need different layer → discover layer parameter
3. Need special behavior → discover full configuration
4. Become expert → use appropriate level for each case
```

## Performance Considerations

### Compilation Impact
- **Method Resolution**: Compile-time, zero runtime cost
- **Default Parameters**: Compiled as constants, no performance penalty
- **Inlining**: Simple forwarding methods likely inlined by JIT

### Runtime Behavior
- **Call Path**: All overloads → same internal implementation
- **Object Creation**: No additional allocations
- **Cache Behavior**: Identical to current implementation

## Error Handling Strategy

### Compile-time Safety
- **Type Constraints**: Prevent invalid View/Controller types
- **Overload Resolution**: Clear disambiguation through parameter counts
- **IntelliSense**: Provides guided discovery of appropriate overload

### Runtime Validation
- **Parameter Validation**: Consistent across all overloads
- **Error Messages**: Include information about which overload was called
- **Exception Types**: Maintain consistency with existing framework

## Alternative Designs Considered

### 1. Builder Pattern
```csharp
// Considered but rejected
await _uiManager.OpenWindow<View, Controller>()
    .WithLocation("path")
    .WithLayer(UILayer.Popup)
    .ExecuteAsync();
```
**Rejected因为**: 增加API复杂性，不符合简化目标

### 2. Options Object Pattern
```csharp
// Considered but rejected
await _uiManager.OpenWindowAsync<View, Controller>("path", new WindowOptions 
{
    Layer = UILayer.Popup,
    CacheOnClose = false
});
```
**Rejected因为**: 不如直接重载简洁，增加概念数量

### 3. Attribute-based Configuration
```csharp
// Considered but rejected
[WindowConfig(Layer = UILayer.Normal, CacheOnClose = true)]
public class MyView : UIView { }
```
**Rejected因为**: 降低运行时灵活性，增加反射开销

## Integration Points

### 与simplify-ui-window-registration的关系
- **Builds Upon**: 扩展现有提案，不替换
- **Dependency**: 需要现有提案先实现
- **Enhancement**: 添加易用性层，不改变核心架构

### 与现有UI框架的集成
- **UIManager**: 添加重载方法，保持核心逻辑不变
- **UIWindowDescriptor**: 继续使用，默认值在重载中设定
- **Caching/Lifecycle**: 行为完全一致