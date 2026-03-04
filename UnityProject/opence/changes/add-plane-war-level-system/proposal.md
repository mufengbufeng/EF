# Change: 为飞机大战 Demo 增加关卡系统

## Why
当前玩法只有无尽刷怪和积分，没有关卡目标与进度持久化，无法形成完整闯关循环。需要在现有体力校验基础上引入关卡配置、通关判定与下一关推进能力。

## What Changes
- 新增关卡配置表 `level.xlsx`，通过 Luban 生成客户端代码和二进制配置。
- 新增 `ILevelModule` 与 `LevelModule`，负责当前关卡读取、杀敌计数、通关判定与关卡进度持久化（PlayerPrefs）。
- 在 `InitProcedure` 注册全局关卡模块。
- 在 `MainMenuProcedure.StartGame()` 接入“进入当前关卡”逻辑。
- 在 `GamePlayProcedure` 中按当前关卡配置驱动刷怪参数，并在杀敌时通知关卡模块、通关时推进下一关。
- 与现有体力系统兼容：开始游戏仍通过主界面体力校验后进入玩法。

## Impact
- Affected specs: `gameplay-level-system`
- Affected code:
  - `Assets/GameScripts/HotFix/GameLogic/Level/*`
  - `Assets/GameScripts/HotFix/GameLogic/Procedure/Main/InitProcedure.cs`
  - `Assets/GameScripts/HotFix/GameLogic/Procedure/Main/MainMenuProcedure.cs`
  - `Assets/GameScripts/HotFix/GameLogic/Procedure/GamePlay/GamePlayProcedure.cs`
  - `Assets/GameScripts/HotFix/GameLogic/GamePlay/Enemy/EnemySpawnerModule.cs`
  - `Configs/GameConfig/Datas/level.xlsx`
  - `Configs/GameConfig/Datas/__tables__.xlsx`
  - `Assets/GameScripts/HotFix/GameProto/GameConfig/*`（生成文件）
