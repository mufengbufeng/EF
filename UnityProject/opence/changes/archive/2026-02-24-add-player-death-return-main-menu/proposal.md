# 变更提案：角色死亡后返回主界面并补齐玩法退出清理

## Why
当前玩法只支持通过暂停菜单 Back 返回主界面，玩家死亡后仅隐藏实体，不会结束玩法流程。  
同时，返回主界面时“局内数据清理”和“运行时引用释放”缺少统一约束，容易出现积分残留、窗口残留或回调残留。  
代码复核显示 `GamePlayProcedure.OnLeave` 当前仅关闭 `GamePlayView`、清理摄像机堆栈并 `ShutdownScope(GamePlayScope)`，尚未统一处理 `Time.timeScale`、`GameMenuView`、`GamePlayModel` 数据重置以及玩法场景卸载策略。

## What Changes
- 新增 `gameplay-death-return` 能力：玩家死亡后自动触发返回 `MainMenuProcedure`。
- 新增 `gameplay-exit-cleanup` 能力：将暂停返回与死亡返回统一到同一套退出清理流程。
- 明确退出清理代码统一绑定在 `GamePlayProcedure.OnLeave`，后续新增任意退出方式都必须复用该清理收口。
- 明确退出清理最小必做项：恢复 `Time.timeScale`、关闭玩法相关 UI、`ShutdownScope(GamePlayScope)`、恢复摄像机堆栈、重置 `GamePlayModel` 局内数据、释放玩法强引用与事件订阅。
- 补充场景清理策略：基于现有 `SceneManager` 能力明确是否在 `OnLeave` 主动卸载当前玩法场景，并定义失败时降级行为（记录日志且不阻断流程切换）。
- 补充幂等要求，避免死亡回调/重复点击导致重复切流程或重复清理。

## Impact
- Affected specs:
  - `gameplay-death-return`（新增）
  - `gameplay-exit-cleanup`（新增）
  - 关联 `game-menu-buttons`、`module-scope`、`gameplay-score-ui`
- Affected code（work 阶段实施）:
  - `Assets/GameScripts/HotFix/GameLogic/Procedure/GamePlay/GamePlayProcedure.cs`
  - `Assets/GameScripts/HotFix/GameLogic/GamePlay/Scene/GameSceneManager.cs`（如需扩展统一卸载入口）
  - `Assets/GameScripts/HotFix/GameLogic/GamePlay/Avatar/PlayerAvatarModule.cs`
  - `Assets/GameScripts/HotFix/GameLogic/GamePlay/Avatar/IPlayerAvatarModule.cs`
  - `Assets/GameScripts/HotFix/GameLogic/GamePlay/Avatar/PlayerAvatarEntity.cs`
  - `Assets/GameScripts/HotFix/GameLogic/GamePlay/Avatar/PlayerAvatarBehaviorData.cs`（如需传递死亡回调）
  - `Assets/GameScripts/HotFix/GameLogic/UI/Game/GamePlayController.cs`（如需统一暂停菜单关闭链路）
- Breaking changes:
  - 无对外破坏性 API 变更（如扩展接口，将采用向后兼容方式）
