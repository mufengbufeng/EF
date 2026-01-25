# Design: ModuleSystem Scope 清理

## Context

`EF.Common.ModuleSystem` 以静态类形式存在，维护：
- `serviceType -> moduleInstance` 的映射（用于 Get/TryGet）
- `moduleInstance -> aliases` 的映射（用于同一实例注册多个服务别名）
- `_updateOrder`（用于统一 Update 分发）

现状缺少“按业务阶段分组”的能力，导致在退出某个流程（如 `GamePlayProcedure.OnLeave`）时，必须手动判断并逐个清理相关模块。

## Goals / Non-Goals

**Goals**
- 支持模块注册时声明 Scope，并在框架层记录该元数据
- 支持按 Scope 批量注销并关闭模块
- 保持向后兼容：现有 `Register` 调用无需修改即可继续工作（默认 scope = 0）
- 清理顺序可预期：遵循与 `ShutdownAll` 一致的“反向注册顺序”原则

**Non-Goals**
- 不尝试自动推断模块属于哪个 Scope（例如按命名空间/目录自动识别）
- 不强制解决“外部仍持有模块引用”的问题（这属于业务层引用管理范畴）
- 本次仅覆盖 `ModuleSystem`；`ModelManager` 等其他注册中心是否引入 Scope 作为后续议题

## Decisions

### Decision 1: Scope 绑定到“模块实例”，而非“服务类型”

同一模块实例可能通过别名绑定到多个 `serviceType`（接口、抽象类、具体类）。Scope 应属于模块实例本身：

- 优点：一个模块只有一个 Scope，按 Scope 清理时不会出现“同一实例部分别名被清理、部分没清理”的不一致
- 约束：同一实例重复注册时，Scope 必须保持一致；冲突应直接报错以暴露错误配置

### Decision 2: API 以最小增量扩展实现向后兼容

- 为 `Register<TService>` / `Register(Type, ...)` 增加可选 `int scope` 参数（默认 `0`）
- 新增 `ShutdownScope(scope)` API 作为批量清理入口
- 不修改 `IEFManager` 接口，避免破坏所有管理器实现

### Decision 3: 清理顺序遵循反向注册顺序

`ShutdownAll` 以 `_updateOrder` 的反向顺序调用 `Shutdown`。`ShutdownScope` 应遵循同样的原则，以减少依赖关系导致的释放顺序问题：

- 若 A 先注册、B 后注册，且二者同 Scope，则清理时先 `B.Shutdown()` 再 `A.Shutdown()`

### Decision 4（可选增强）: 更新分发中的清理安全性

`ModuleSystem.Update` 使用快照遍历。若在更新过程中触发 Scope 清理/Unregister，快照仍可能包含已注销模块，导致同一帧后续仍调用其 `Update`。

可选增强方向：
- 在 `Update` 分发前对每个模块做“仍处于注册态”的检查，已注销的模块跳过更新
- 或引入“延迟关闭队列”，在安全点统一执行 Shutdown

此项是否纳入本变更，取决于项目对“更新中动态清理”的实际需求与可接受复杂度。

## Architecture / Data Model

建议在 `ModuleSystem` 内增加一份 Scope 元数据表：

- `Dictionary<IEFManager, int> _scopes`

并在 `RemoveModuleInternal` / `ShutdownAll` 中同步清理该表，确保生命周期一致。

## Migration Plan

1. 保持现有注册不变：未传 scope 的模块默认 `scope = 0`
2. 在进入 `GamePlay` 时，对仅属于该流程的模块用业务层定义的非 0 scope 注册（例如 `(int)GameScope.GamePlay`）
3. 在退出 `GamePlay` 时调用 `ModuleSystem.ShutdownScope(scopeValue)` 一键清理

## Open Questions

1. **业务层 scope 取值约定**：是否统一维护一份 enum（如 `GameScope`）并转 int 传入？是否需要避免重复值？
2. **scope 值范围限制**：是否允许负数？（建议仅约定 `0` 为全局，其余由业务层自行规划）
3. **Scope 清理边界**：是否仅清理 `ModuleSystem` 中的 `IEFManager` 模块，还是也希望覆盖 `ModelManager` 中的 Model、UIManager 中的窗口等？
