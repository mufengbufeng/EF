# 设计：飞机大战玩法模块化（GameEnemyModule，复用 GameSceneManager）

## 背景与现状

- `Assets/GameScripts/Runtime/GameEntry.cs` 负责注册 EF 框架管理器到 `EF.Common.ModuleSystem`。
- `Assets/GameScripts/HotFix/GameLogic/GameLogicEntry.cs` 从 `ModuleSystem` 获取框架管理器，并创建 `SceneManager` 与 `GameSceneManager`。
- `Assets/GameScripts/HotFix/GameLogic/Procedure/GamePlay/GamePlayProcedure.cs` 目前仅包含进入流程的壳代码，且 `_gameSceneManager` 未初始化，导致玩法场景进入逻辑无法工作。
- `Assets/EF/EFRuntime/Common/Manager/ModuleSystem.cs` 已支持 `scope` 与 `ShutdownScope(scope)`，适合在“玩法流程”退出时回收玩法模块。

## 目标

1. 将“敌机生成/回收”从 `GamePlayProcedure` 中拆分为独立模块，降低流程类复杂度。
2. 通过 `ModuleSystem` 的 `scope` 管理玩法生命周期，确保退出玩法时统一释放资源。
3. 在保持最小实现的前提下，为后续扩展（关卡/波次/难度/刷怪点/玩家与子弹系统）预留接口。

## 复用现有场景能力（不新增 GameSceneModule）

项目已存在 `GameSceneManager`（实现 `IGameSceneManager`），其职责是“进入指定场景并发布场景事件”。  
在当前“最小实现 + 接口优先”的目标下，新增 `GameSceneModule` 只做转发并不能带来明显收益，反而会增加一层模块注册与生命周期维护成本。

因此本次变更的场景进入流程如下：

- `GamePlayProcedure` 直接调用 `GameLogicEntry.GameScene.EnterGamePlaySceneAsync()` 并等待完成
- 场景进入完成后再启动 `GameEnemyModule` 刷怪

> 后续若需要“场景内刷怪点/边界/锚点”等玩法场景专属能力，再单独引入 `GameSceneModule` 作为新的变更更合适。

## 模块职责划分

### GameEnemyModule

职责：
- 由外部在“玩法场景进入完成后”启动刷怪。
- 管理敌机的生成、存活列表与回收；玩法退出时清理所有敌机。
- 最小实现：按固定间隔生成敌机（后续扩展为波次/曲线/难度）。

依赖（推荐方案）：
- `EF.Entity.IEntityManager`：使用实体系统加载/复用敌机对象
- 可选：`EF.Resource.IResourceManager`（若需要读取配置或资源名映射）

生命周期（建议）：
- `StartSpawning()` / `StopSpawning()`（显式控制刷怪开关）
- `Update`：计时并按规则生成敌机；记录生成的 entityId
- `Shutdown`：停止刷怪、隐藏/回收所有生成过的敌机、清空内部列表（必须幂等）

## 作用域（Scope）与流程集成

### Scope 约定

- 规划一个“玩法作用域常量”，例如 `GamePlayScope = 1001`（示例值，与 `module-scope` 规范一致）。
- 本次变更涉及的玩法模块（`GameEnemyModule`）必须以 `scope = GamePlayScope` 注册到 `ModuleSystem`。

### GamePlayProcedure 负责的工作

进入：
1. 为避免异常状态残留，`OnEnter` 开始时可先调用 `ModuleSystem.ShutdownScope(GamePlayScope)`（幂等）。
2. 创建并注册 `GameEnemyModule`（建议 `replace=true` 或先清理 scope）。
3. 调用 `GameLogicEntry.GameScene.EnterGamePlaySceneAsync()` 进入玩法场景并等待完成。
4. 场景进入完成后，启动 `GameEnemyModule` 刷怪。

更新：
- 若项目已有全局驱动 `ModuleSystem.Update`：模块 `Update` 会自动被调用。
- 若没有：`GamePlayProcedure.OnUpdate` 需要显式调用 `GameEnemyModule.Update(...)`（或补齐全局驱动，见 tasks）。

退出：
- `OnLeave` 调用 `ModuleSystem.ShutdownScope(GamePlayScope)`：
  - 触发 `GameEnemyModule.Shutdown()`，回收敌机

## 关键接口（建议形态，供实现阶段参考）

- `IGameEnemyModule : IEFManager`
  - `void StartSpawning()`
  - `void StopSpawning()`

> 注：以上为建议接口形态，最终以实现阶段结合现有代码风格与依赖注入方式落地。

## 风险与约束

- 必须确认是否存在 `ModuleSystem.Update` 的统一驱动入口；否则流程/管理器更新可能无法运行（不仅影响新模块，也会影响 `ProcedureManager` 等 EF 管理器）。
- 场景名当前由 `GameSceneManager` 固定为 `"Game"`；敌机资源名与实体组名本次不做约定，推荐在实现阶段通过接口参数或外部配置输入，避免在模块内部硬编码。
