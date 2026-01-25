# Change: 更新背景滚动方向与生成时机并引入对象池

## Why
- 背景滚动方向与预期相反（应向上）。
- 当前重排/生成时机滞后，导致新片段在屏幕中间出现。
- 无限滚动背景需要减少频繁 Instantiate/Destroy 以优化性能。

## What Changes
- 调整背景滚动方向：速度正值向上，负值向下，0 为暂停。
- 基于相机上下边界重排背景，确保重排发生在视口之外。
- 使用 `IObjectPoolManager` 复用背景片段实例，减少运行时分配。
- 调整背景模块初始化/注入流程以提供对象池管理器。

## Impact
- Affected specs: `opence/specs/background-scroll/spec.md`
- Affected code: `Assets/GameScripts/HotFix/GameLogic/GamePlay/Background/GameBackgroundModule.cs`, `Assets/GameScripts/HotFix/GameLogic/Procedure/GamePlay/GamePlayProcedure.cs`, `Assets/GameScripts/HotFix/GameLogic/GamePlay/Background/IGameBackgroundModule.cs`
