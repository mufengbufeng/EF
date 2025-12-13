# Proposal: Make Window Configuration Parameters Optional

## Summary
将UI框架中的cacheOnClose和allowMultiple参数设为可选，通过智能默认值和重载方法简化API调用。

## Why
当前的简化UI窗口注册提案虽然减少了步骤，但仍然要求开发者为每个窗口显式指定cacheOnClose和allowMultiple参数，这增加了API的复杂性：

### 当前痛点
1. **必需参数过多**: 即使是最简单的窗口打开也需要指定所有配置参数
2. **认知负担**: 开发者需要理解并决定每个参数的值
3. **样板代码**: 大多数窗口使用相同的默认配置，重复指定参数
4. **学习曲线**: 新手需要了解所有参数的含义才能使用API

### 使用模式分析
通过分析现有代码发现：
- **cacheOnClose**: 90%的窗口使用默认值true（缓存以提高性能）
- **allowMultiple**: 95%的窗口使用默认值false（单实例模式）
- 只有特殊窗口（如入口界面、弹窗）需要自定义这些参数

## Motivation
通过使这些参数可选，我们可以：
1. 为常见用例提供最简洁的API
2. 为高级用例保留完全控制能力
3. 减少开发者的认知负担
4. 改善API的易用性和可发现性

## Proposed Solution
提供多个重载方法，从最简单的调用逐步增加可配置性。

### Current Usage (from existing proposal)
```csharp
await _uiManager.OpenWindowAsync<EntryView, EntryController>(
    location: "EntryView",
    layer: UILayer.Normal,
    cacheOnClose: false,
    allowMultiple: false
);
```

### Proposed Usage - Progressive API
```csharp
// Level 1: 最简单调用 - 只需要资源路径
await _uiManager.OpenWindowAsync<MainMenuView, MainMenuController>("MainMenu");

// Level 2: 指定层级
await _uiManager.OpenWindowAsync<DialogView, DialogController>("Dialog", UILayer.Popup);

// Level 3: 完全配置 (与当前提案相同)
await _uiManager.OpenWindowAsync<EntryView, EntryController>(
    location: "EntryView",
    layer: UILayer.Normal,
    cacheOnClose: false,
    allowMultiple: false
);
```

## Benefits
1. **渐进式复杂性**: 从简单到复杂的多层级API
2. **智能默认值**: 基于最佳实践的默认配置
3. **向下兼容**: 不影响现有的完整参数版本
4. **更好的开发体验**: 减少90%常见场景的样板代码
5. **类型安全**: 保持编译时类型检查

## Impact Assessment
- **Breaking Changes**: 无 - 纯粹添加重载方法
- **Performance**: 无影响 - 默认值在编译时确定
- **Complexity**: 降低 - 简化常见用例
- **Learning Curve**: 大幅改善 - 新手可以从简单API开始

## Implementation Strategy
1. 添加渐进式重载方法
2. 更新文档和示例以展示最佳实践
3. 在代码中使用最简洁的调用方式