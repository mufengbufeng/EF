## Context
- 当前返回主界面入口只有暂停菜单 Back -> `GamePlayProcedure.ReturnToMainMenu()`。
- 玩家死亡在 `PlayerAvatarEntity` 内只执行动画与隐藏，不会通知流程层结束玩法。
- 退出玩法时已有部分清理（关 `GamePlayView`、摄像机堆栈恢复、`ShutdownScope(GamePlayScope)`、字段置空），但缺少统一约束：局内数据（如积分）清零、多入口幂等、死亡路径与 Back 路径一致性。
- 代码复核结论（基于 `GamePlayProcedure` / 场景系统）：
  - `OnLeave` 是当前唯一稳定的流程退出边界，适合作为全部清理逻辑绑定点。
  - 现有 `OnLeave` 未恢复 `Time.timeScale`，也未显式关闭 `GameMenuView`。
  - `SceneManager.LoadSceneAsync(..., LoadSceneMode.Single)` 仅在“加载下一场景”时才会触发旧场景卸载；仅切流程回主菜单不会自动卸载 `Game` 场景。
  - 当前工程存在 `Entry.unity` 与 `Game.unity`，不存在 `Lobby.unity`，而 `IGameSceneManager.ReturnToLobbyAsync()` 目标场景为 `Lobby`，现阶段不能作为可执行返回路径。
  - `Entry.unity` 挂载了 `DontDestroyComponent`，说明基础入口对象可跨场景存活，允许在退出玩法时主动卸载 `Game` 场景。

## Goals / Non-Goals
- Goals:
  - 玩家死亡后自动回到主界面。
  - 所有返回主界面路径复用同一退出清理序列。
  - 明确并落实“局内数据清理 + 局内内存残留清理”的验收点。
- Non-Goals:
  - 不新增 GameOver 结算页或复活机制。
  - 不调整敌人/玩家战斗数值。
  - 不默认引入强制 `GC.Collect()`。

## Decisions
- Decision: 使用“玩家死亡通知 -> `GamePlayProcedure.ReturnToMainMenu()`”链路驱动流程切换。
  - Why: 以最小改动打通实体层到流程层，并复用现有返回主菜单能力。
- Decision: 在 `GamePlayProcedure` 增加幂等门禁（例如 `_isReturningToMainMenu`），统一保护死亡返回和按钮返回。
  - Why: 避免并发触发导致重复切状态、重复清理或重复日志。
- Decision: 将退出清理集中在 `GamePlayProcedure.OnLeave`，并将其定义为唯一清理收口。
  - Why: 后续退出路径会增加，绑定到 `OnLeave` 可保证任何路径都走同一清理序列。
- Decision: 在 `OnLeave` 补齐完整清理清单。
  - Why: 基于现状缺口，最小必做项为：`Time.timeScale = 1`、关闭 `GamePlayView` 与 `GameMenuView`、恢复摄像机堆栈、`ShutdownScope(GamePlayScope)`、重置 `GamePlayModel`（积分归零）、清空流程级强引用、解除玩法级事件订阅。
- Decision: 在 `OnLeave` 增加“玩法场景主动卸载”步骤（异步触发，不阻塞主流程）。
  - Why: 当前回主菜单只切流程不切场景，`Game` 场景会残留到下一次开局；主动卸载可更早释放场景内存，且 `Entry` 常驻对象可承接主菜单 UI。
- Decision: 内存残留清理以“引用释放 + 资源释放 + 订阅解绑”为主，不把强制 GC 作为默认流程。
  - Why: 强制 GC 可能引起卡顿且收益不稳定，优先 deterministic cleanup。

## Risks / Trade-offs
- 风险: 死亡通知触发过早会截断死亡动画。
  - Mitigation: 通知时机与现有死亡动画延迟窗口对齐。
- 风险: 新增事件订阅若未解绑会造成回调残留。
  - Mitigation: 在 `OnLeave`/`OnExit` 显式解绑，并增加幂等要求。
- 风险: `GamePlayModel` 为全局注册模型，遗漏重置会导致跨局数据污染。
  - Mitigation: 将“退出玩法重置局内数据”作为硬性 requirement，并在回归用例覆盖重开新局场景。
- 风险: `OnLeave` 触发的异步场景卸载若失败可能留下场景资源。
  - Mitigation: 卸载失败仅告警并保持流程切换成功；下一次 `EnterGamePlaySceneAsync` 仍会通过 `LoadSceneMode.Single` 兜底触发旧场景卸载。

## Migration Plan
1. 增加死亡到流程层的通知机制并接入 `ReturnToMainMenu()`。
2. 将返回入口（Back/死亡）统一收敛到同一幂等入口。
3. 在 `OnLeave` 补齐清理序列（UI/TimeScale/Scope/模型数据/引用释放），并加入玩法场景卸载步骤。
4. 增加回归验证：连续多局进入与退出不出现数据残留、重复回调、场景残留。

## Open Questions
- 暂无。当前按“播放死亡动画后返回主界面”与“OnLeave 统一清理”规划。
