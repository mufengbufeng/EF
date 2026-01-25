# Change: 为 ModuleSystem 引入 Scope，并支持按 Scope 清理

## Why

`EF.Common.ModuleSystem` 作为框架层的模块注册中心，承担了“全局单例容器 + 生命周期管理”的职责：模块一旦注册，通常会贯穿整个进程生命周期。

在游戏流程中（例如进入/退出 `GamePlay` 流程），往往需要“按业务阶段”释放对应模块（管理器、子系统等）。当前做法需要开发者在退出时手动列出并逐一 `Unregister/Shutdown`，这会带来：

- 容易遗漏：忘记清理导致资源/状态残留
- 容易误删：清理了仍被其他流程复用的模块
- 可维护性差：随着模块数量增长，退出逻辑越来越臃肿

因此希望在框架层提供统一的 **Scope** 概念：模块在注册时声明所属 Scope，退出流程时可通过 Scope 一键清理。

## What Changes

- 引入 `int scope` 标签（默认 `0` 表示全局 Scope；非 0 值由业务层自行约定）
- 扩展 `ModuleSystem.Register(...)` 支持可选 `scope` 参数（保持现有调用兼容）
- 新增 `ModuleSystem.ShutdownScope(scope)`（或等价命名）用于按 Scope 注销并关闭模块
- （可选增强）在更新分发过程中触发清理时，避免同一帧继续更新已注销模块
- 更新模块系统文档与示例用法（指导在 `GamePlayProcedure.OnLeave` 中执行 Scope 清理）

## Impact

- Affected specs: 新增 `module-scope` 规范
- Affected code（实现阶段）:
  - `Assets/EF/EFRuntime/Common/Manager/ModuleSystem.cs`
  - 可能新增/调整 `GamePlay` 流程退出处的调用示例（如 `GamePlayProcedure.OnLeave`）
- 兼容性：通过新增可选参数与新增 API，避免对既有 `Register/Get` 用法造成破坏性变更
