# 规范：模型检索与自动注册

> **状态**: 提案阶段  
> **能力**: model-retrieval  
> **变更**: refactor-modelmanager-getorregister-logic

## 能力概述

模型检索与自动注册能力提供了统一的接口来获取和管理模型实例，支持按需自动创建和注册模型，简化了模型使用的样板代码。

## ADDED Requirements

### Requirement: GetModel 必须只获取已注册模型

`GetModel<TModel>()` 方法 MUST 仅用于获取已经通过 `Register` 注册的模型实例，如果模型未注册 MUST 抛出明确的异常。

**优先级**: 高  
**类型**: 功能性

#### Scenario: 获取已注册的模型

**Given** 模型 `UserModel` 已通过 `Register` 注册  
**When** 调用 `GetModel<UserModel>()`  
**Then** 返回已注册的 `UserModel` 实例

#### Scenario: 获取未注册的模型抛出异常

**Given** 模型 `UserModel` 未注册  
**When** 调用 `GetModel<UserModel>()`  
**Then** 抛出 `KeyNotFoundException` 异常  
**And** 异常消息包含模型的完整类型名称

---

### Requirement: TryGetModel 必须支持自动注册

`TryGetModel<TModel>()` 泛型方法 MUST 实现"获取或创建"语义：如果模型已注册则返回现有实例，如果未注册则自动创建并注册新实例。该方法 MUST 保证返回非空实例。

**优先级**: 高  
**类型**: 功能性

#### Scenario: 获取已注册的模型

**Given** 模型 `UserModel` 已通过 `Register` 注册  
**When** 调用 `TryGetModel<UserModel>()`  
**Then** 返回已注册的 `UserModel` 实例  
**And** 不创建新实例

#### Scenario: 自动注册未注册的模型

**Given** 模型 `UserModel` 未注册  
**And** `UserModel` 具有无参构造函数  
**When** 调用 `TryGetModel<UserModel>()`  
**Then** 创建新的 `UserModel` 实例  
**And** 调用 `Initialize` 初始化模型  
**And** 将模型注册到管理器  
**And** 返回新创建的实例

#### Scenario: 多次调用返回同一实例

**Given** 模型 `UserModel` 未注册  
**When** 首次调用 `TryGetModel<UserModel>()`  
**And** 再次调用 `TryGetModel<UserModel>()`  
**Then** 两次调用返回同一个实例

#### Scenario: 自动注册失败抛出异常

**Given** 模型 `UserModel` 未注册  
**And** `UserModel` 的初始化过程抛出异常（如视图类型冲突）  
**When** 调用 `TryGetModel<UserModel>()`  
**Then** 抛出 `InvalidOperationException`  
**And** 模型未被添加到注册表

---

### Requirement: TryGetModel 泛型版本必须有 new() 约束

`TryGetModel<TModel>()` 泛型方法 MUST 要求类型参数 `TModel` 具有 `new()` 约束，以确保能够自动创建实例。

**优先级**: 高  
**类型**: 约束性

#### Scenario: 编译时验证无参构造函数

**Given** 模型类型 `UserModel` 没有无参构造函数  
**When** 尝试编译调用 `TryGetModel<UserModel>()` 的代码  
**Then** 编译失败并提示缺少 `new()` 约束

---

### Requirement: TryGetModel(Type) 必须仅执行查找

`TryGetModel(Type modelType)` 方法 MUST 仅执行查找操作，不支持自动注册。如果模型未注册，MUST 返回 `null`。此方法用于运行时类型检查场景。

**优先级**: 中  
**类型**: 功能性

#### Scenario: 查找已注册的模型

**Given** 模型 `UserModel` 已注册  
**When** 调用 `TryGetModel(typeof(UserModel))`  
**Then** 返回已注册的 `UserModel` 实例

#### Scenario: 查找未注册的模型返回 null

**Given** 模型 `UserModel` 未注册  
**When** 调用 `TryGetModel(typeof(UserModel))`  
**Then** 返回 `null`  
**And** 不创建或注册任何实例

---

### Requirement: 线程安全的检查和注册

`TryGetModel` 的"检查-创建-注册"过程 MUST 是原子操作，确保并发调用时不会创建重复实例。

**优先级**: 高  
**类型**: 非功能性（性能、安全）

#### Scenario: 并发调用同一模型类型

**Given** 模型 `UserModel` 未注册  
**When** 两个线程同时调用 `TryGetModel<UserModel>()`  
**Then** 只创建一个 `UserModel` 实例  
**And** 两个线程返回同一个实例  
**And** 模型只被注册一次

#### Scenario: 并发 TryGetModel 和 Register

**Given** 模型 `UserModel` 未注册  
**When** 线程 A 调用 `TryGetModel<UserModel>()`  
**And** 线程 B 同时调用 `Register(new UserModel())`  
**Then** 其中一个操作成功  
**And** 另一个操作抛出"模型已注册"异常  
**And** 最终只有一个实例被注册

---

## ADDED Requirements

### Requirement: 移除 out 参数重载

移除返回 `bool` 并使用 `out` 参数的 `TryGetModel` 重载，这些方法的语义与新的自动注册行为不一致。此要求记录了 API 的移除决策。

**优先级**: 高  
**类型**: API 变更

#### 已移除的方法

- `bool TryGetModel<TModel>(out TModel model)`
- `bool TryGetModel(Type modelType, out ModelBase model)`

#### Scenario: 使用 out 参数重载的代码无法编译

**Given** 代码使用 `TryGetModel(out var model)` 模式  
**When** 尝试编译  
**Then** 编译失败并提示方法不存在

---

## ADDED Requirements

### Requirement: Register 内部重构以支持原子操作

`Register` 方法 MUST 重构为两层结构：公共方法（加锁）和内部方法（不加锁），以支持 `TryGetModel` 在持有锁的情况下调用注册逻辑。

**优先级**: 高  
**类型**: 内部实现

#### Scenario: Register 公共方法保持现有行为

**Given** 调用 `Register(new UserModel())`  
**When** 注册过程执行  
**Then** 行为与重构前完全一致  
**And** 外部调用者无感知

#### Scenario: TryGetModel 内部调用注册逻辑

**Given** `TryGetModel` 在锁内检测到模型未注册  
**When** 调用内部注册方法  
**Then** 不发生嵌套锁  
**And** 注册成功完成

---

## 相关能力

无（新增能力）

## 实现注意事项

1. **锁重入问题**：必须避免 `TryGetModel` 调用 `Register` 导致的嵌套锁，通过提取 `RegisterInternal` 解决
2. **异常安全**：如果模型创建或初始化失败，必须确保不留下部分注册状态
3. **类型约束**：泛型版本使用 `new()` 约束，Type 参数版本不支持自动创建
4. **向后兼容**：此为破坏性变更，需要提供迁移指南

## 测试要求

- 单元测试覆盖所有场景
- 线程安全测试验证并发行为
- 性能测试确保自动注册不引入显著开销
- 集成测试验证在真实 UI 流程中的行为

## 文档要求

- XML 注释清晰说明 GetModel 和 TryGetModel 的差异
- 强调 TryGetModel 的自动注册行为
- 说明泛型版本和 Type 参数版本的不同语义
- 提供迁移指南和代码示例
