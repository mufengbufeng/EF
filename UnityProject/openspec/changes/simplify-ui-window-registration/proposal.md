# Proposal: Simplify UI Window Registration

## Summary
简化UI框架的窗口注册流程，将UIWindowDescriptor.Create方法的参数直接移动到OpenWindowAsync方法中，消除预先注册窗口的需求。

## Why
当前UI框架要求开发者执行多步操作才能打开一个窗口，这增加了不必要的复杂性和出错风险：

### 当前痛点
1. **多步操作流程**: 开发者必须记住并执行3个步骤：创建描述符、注册窗口、打开窗口
2. **状态管理负担**: 需要管理窗口描述符的生命周期和注册状态
3. **类型信息分离**: 窗口名称（字符串）与类型信息分离，容易出现不一致
4. **预注册要求**: 必须在使用前注册所有窗口，增加初始化复杂度
5. **开发体验差**: 简单的"打开窗口"操作变成了复杂的多步流程

### 业务影响
- **开发效率低**: 每个新窗口都需要重复相同的样板代码
- **维护成本高**: 窗口名称和类型分离导致重构困难
- **错误易发**: 字符串名称易拼写错误，运行时才能发现问题

## Motivation
通过将窗口配置参数直接集成到OpenWindowAsync方法中，我们可以：
1. 将3步操作简化为1步
2. 提供编译时类型安全保障
3. 消除字符串名称管理的复杂性
4. 改善整体开发者体验

## Proposed Solution
修改`OpenWindowAsync`方法，接受原本在`UIWindowDescriptor.Create`中的参数，实现即开即用的窗口管理。

### Current Usage
```csharp
// 当前需要预先注册
var descriptor = UIWindowDescriptor.Create<EntryView, EntryController>(
    name: "EntryView",
    location: "EntryView",
    layer: UILayer.Normal,
    cacheOnClose: false,
    allowMultiple: false
);
_uiManager.RegisterWindow(descriptor);

// 然后才能打开
await _uiManager.OpenWindowAsync("EntryView");
```

### Proposed Usage
```csharp
// 直接打开，无需预先注册
await _uiManager.OpenWindowAsync<EntryView, EntryController>(
    location: "EntryView",
    layer: UILayer.Normal,
    cacheOnClose: false,
    allowMultiple: false
);
```

## Benefits
1. **简化API**: 减少方法调用，从3步变为1步
2. **类型安全**: 泛型参数提供编译时类型检查
3. **减少状态管理**: 不需要维护注册表
4. **更直观**: 窗口类型和打开操作在同一处
5. **向后兼容**: 可以保留原有API作为兼容方案

## Impact Assessment
- **Breaking Changes**: 最小 - 可以保留现有API作为重载
- **Performance**: 轻微改善 - 减少查找注册表的开销
- **Complexity**: 显著降低 - 减少概念和步骤数

## Implementation Strategy
分阶段实现：
1. 添加新的泛型OpenWindowAsync重载
2. 内部重构窗口创建逻辑
3. 更新示例代码和文档
4. （可选）标记旧API为过时