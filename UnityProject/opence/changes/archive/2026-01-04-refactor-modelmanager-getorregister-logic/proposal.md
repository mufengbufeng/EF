# 提案：重构 ModelManager 获取或注册逻辑

## 概述

重新整理 `ModelManager` 中模型检索方法的职责，使 `GetModel` 专注于获取已注册模型，而 `TryGetModel` 承担"获取或自动注册"的职责。

## Why

当前的 `ModelManager` API 存在语义不清的问题：

1. **`TryGetModel` 的命名与行为不匹配**：
   - 名称暗示"尝试获取，可能失败"
   - 但实际返回 `bool` 和 `out` 参数，要求调用者处理失败情况
   - 在很多使用场景中，开发者只是想"如果没有就创建一个"

2. **缺少便利方法**：
   - 缺少"获取或创建"模式的直接支持
   - 开发者需要手动检查 `TryGetModel` 返回值，然后调用 `Register`
   - 增加了样板代码

3. **API 不一致**：
   - 有返回 `bool` 的重载
   - 有返回可空类型的重载
   - 职责混乱，难以记忆

## What Changes

### API 变更

1. **ModelManager.TryGetModel<TModel>()**
   - 添加 `new()` 泛型约束
   - 实现"获取或自动注册"语义
   - 保证返回非空实例

2. **移除的方法**
   - `bool TryGetModel<TModel>(out TModel model)`
   - `bool TryGetModel(Type, out ModelBase model)`

3. **内部重构**
   - 提取 `RegisterInternal` 私有方法
   - 确保线程安全的原子操作

4. **依赖代码更新**
   - UIController.TryGetModel 改为返回实例
   - MainController 移除 null 检查

### 新增规范

- `model-retrieval`: 模型检索与自动注册能力

## 目标

1. **明确职责分离**：
   - `GetModel<TModel>()`: 获取已注册的模型，不存在则抛出异常
   - `TryGetModel<TModel>()`: 获取模型，如果不存在则自动注册并返回

2. **简化 API**：
   - 移除返回 `bool` 的重载
   - 移除返回可空类型的重载
   - 保持一致的命名约定

3. **改进开发者体验**：
   - 减少样板代码
   - 提供清晰、符合直觉的 API
   - 保持线程安全

## 非目标

- 不影响视图相关方法（`Get`/`TryGet`）
- 不改变 `Register` 方法的行为
- 不改变 `Unregister` 方法的行为
- 不添加 `GetOrRegisterView` 类似的视图方法

## 影响范围

### 破坏性变更

- `TryGetModel<TModel>(out TModel)` - 移除
- `TryGetModel(Type, out ModelBase)` - 移除  
- `TryGetModel<TModel>()` 返回可空类型 - 改为始终返回非空实例
- `TryGetModel(Type)` 返回可空类型 - 改为始终返回非空实例

### 受影响的代码

通过代码搜索发现以下使用点：

1. **UIController.cs**:
   ```csharp
   protected bool TryGetModel<TModel>(out TModel model)
   {
       return Context.ModelManager.TryGetModel(out model);
   }
   ```
   需要更新为新的语义

2. **MainController.cs**:
   ```csharp
   var gamePlayerModel = GameLogicEntry.Model.TryGetModel<GamePlayModel>();
   ```
   已经使用返回值模式，兼容新行为

## 相关规范

此变更将创建新的规范：

- `model-retrieval`: 模型检索与自动注册能力

## 问题与风险

### 风险

1. **破坏性变更影响**：
   - 现有代码使用 `out` 参数模式的地方需要更新
   - UIController 的包装方法需要重新设计

2. **自动注册的约束**：
   - 要求模型类型必须有无参构造函数（`new()` 约束）
   - 某些复杂模型可能无法自动创建

### 缓解措施

1. 在实施前全面搜索所有使用点
2. 为需要参数的模型，要求显式调用 `Register`
3. 清晰的文档说明新旧行为的差异

## 替代方案

### 方案 A：添加新方法而不是修改现有方法

添加 `GetOrRegister<TModel>()` 新方法，保留现有 `TryGetModel` 行为。

**优点**：
- 无破坏性变更
- 向后兼容

**缺点**：
- API 更加复杂
- 两个方法做相似的事情，容易混淆
- 不解决命名不一致问题

**决策**：不采用。用户已确认可以接受破坏性变更。

### 方案 B：保留 `out` 参数重载

保留 `TryGetModel(out TModel)` 同时添加自动注册版本。

**优点**：
- 向后兼容

**缺点**：
- 两个同名方法行为差异巨大，容易误用
- API 膨胀

**决策**：不采用。清晰的 API 比兼容性更重要。

## 成功标准

- [ ] `GetModel` 行为保持不变（获取或抛出异常）
- [ ] `TryGetModel` 实现自动注册逻辑
- [ ] 移除所有 `out` 参数重载
- [ ] 移除所有返回可空类型的重载
- [ ] 更新所有受影响的调用代码
- [ ] 所有单元测试通过
- [ ] 文档更新完成
- [ ] 线程安全验证通过

## 参考资料

- [ModelManager.cs](../../Assets/EF/EFRuntime/Model/ModelManager.cs)
- [UIController.cs](../../Assets/EF/EFRuntime/UI/UIController.cs)
- [MainController.cs](../../Assets/GameScripts/HotFix/GameLogic/UI/Main/MainController.cs)
