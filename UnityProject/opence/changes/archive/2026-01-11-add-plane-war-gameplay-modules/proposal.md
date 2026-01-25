# Change: Add Plane-War GameEnemyModule

## Why

当前 `GamePlayProcedure` 仅包含进入玩法流程的框架代码，缺少对“玩法场景加载完成后如何启动玩法逻辑（刷怪/清理）”的模块化拆分与可复用生命周期管理。  
同时项目中已存在 `GameSceneManager`（`IGameSceneManager`），其职责已覆盖“玩法场景切换/进入”，因此本次变更不再新增 `GameSceneModule`，直接复用现有 `GameSceneManager` 即可。

本提案仅新增一个 HotFix 侧玩法模块：

- `GameEnemyModule`：负责敌机生成、回收与玩法退出时的清理（敌机全部使用 `EF.Entity.IEntityManager` 创建为 Entity）。

并利用 `EF.Common.ModuleSystem` 已具备的 `scope` 与 `ShutdownScope(scope)` 能力，确保玩法退出时一次性释放玩法相关模块与资源，避免跨流程污染。

## What Changes

- 新增 `GameEnemyModule`（HotFix）并注册到 `ModuleSystem` 的“玩法作用域（GamePlay scope）”
- 调整 `GamePlayProcedure` 的职责：
  - `OnEnter`：进入玩法场景（复用 `GameLogicEntry.GameScene`）、创建/注册敌机模块、启动刷怪
  - `OnLeave`：调用 `ModuleSystem.ShutdownScope(GamePlayScope)` 清理玩法模块（当前仅包含敌机模块）
- `ModuleSystem` 本身不新增新能力，直接复用现有 `Register(..., scope)` / `ShutdownScope(scope)`。

## Impact

- 对现有框架模块（EF 管理器）无破坏性变更。
- 玩法模块按 scope 管理，退出玩法后不会残留在全局服务中。
- 风险点：需要确认项目是否存在统一的 `ModuleSystem.Update(...)` 驱动；若没有，玩法模块的每帧逻辑需要由 `GamePlayProcedure.OnUpdate` 显式驱动（或在后续实现阶段补齐驱动入口）。

## Out of Scope

- 玩家飞机、子弹、碰撞、得分、关卡配置等完整玩法系统（后续可在 `GameEnemyModule` 周边扩展）。
- UI/音效/特效资源的完整接入（仅保留扩展点）。

## Notes

1. 敌机全部使用 `EF.Entity.IEntityManager` 创建为 Entity。
2. 本次不制定敌机 `entityAssetName` / `groupName` 的命名约定；`GameEnemyModule` 仅提供接口，相关参数由调用方传入或后续配置系统提供。
