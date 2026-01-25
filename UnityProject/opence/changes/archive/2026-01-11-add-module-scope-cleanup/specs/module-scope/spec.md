# module-scope Specification

## Purpose
为 `EF.Common.ModuleSystem` 引入 Scope（作用域）概念：在框架层以 `int scope` 标签记录模块所属作用域（默认 `0` 表示全局），业务层可自定义 enum 并转换为 int 传入。退出阶段时可按 scope 批量注销并关闭模块，从而减少手工维护清理列表的成本与风险。

## ADDED Requirements

### Requirement: 注册时记录模块 Scope

系统 SHALL 支持在 `ModuleSystem.Register(...)` 时传入 `int scope` 参数，并将 scope 绑定到 **模块实例**（而非服务类型别名）。

#### Scenario: 默认 Scope 为 Global

**Given** 开发者以现有方式注册一个模块且未指定 `scope`
**When** 调用 `ModuleSystem.Register(...)`
**Then** 系统将该模块实例的 scope 记录为 `0`
**And** 不影响现有 `Get/TryGet` 行为

#### Scenario: 同一实例重复注册必须 Scope 一致

**Given** 某模块实例已通过 `ModuleSystem.Register` 以 `scope = 1001` 注册（业务层自定义值示例）
**When** 再次将同一实例注册到另一个服务类型别名，并指定 `scope = 1001`
**Then** 注册成功
**And** 该实例的 scope 保持为 `1001`

#### Scenario: 同一实例重复注册出现 Scope 冲突

**Given** 某模块实例已通过 `ModuleSystem.Register` 以 `scope = 1001` 注册（业务层自定义值示例）
**When** 再次将同一实例注册到另一个服务类型别名，但指定 `scope = 0`
**Then** 系统抛出异常以提示配置冲突
**And** 系统不修改既有注册状态

---

### Requirement: 按 Scope 注销并关闭模块

系统 SHALL 提供按 Scope 批量清理模块的能力（例如 `ModuleSystem.ShutdownScope(scope)`），并对被清理模块调用其 `Shutdown()` 以释放资源。

#### Scenario: 退出 GamePlay 时清理 GamePlay Scope

**Given** 系统中存在若干模块实例，其中部分以 `scope = 1001` 注册（业务层自定义值示例），部分以 `scope = 0` 注册
**When** 调用 `ModuleSystem.ShutdownScope(1001)`
**Then** 所有 `scope = 1001` 的模块被注销（移除全部服务别名绑定）
**And** 对这些模块调用 `Shutdown()`
**And** `scope = 0` 的模块保持注册且可继续被 `Get/TryGet` 访问

#### Scenario: 清理顺序为反向注册顺序

**Given** 在同一 scope 中先后注册模块 A（先）与模块 B（后）
**When** 调用 `ModuleSystem.ShutdownScope(scope)`
**Then** 系统先调用 `B.Shutdown()` 再调用 `A.Shutdown()`
