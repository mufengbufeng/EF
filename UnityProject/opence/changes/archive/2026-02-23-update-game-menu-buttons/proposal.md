# Change: 修改暂停菜单按钮逻辑

## Why
暂停菜单中的 Back 按钮目前与 Continue 按钮行为相同（都是关闭菜单恢复游戏），缺少"退出游戏回到主界面"的功能。需要明确两个按钮的职责：Continue 关闭界面继续游戏，Back 退出当前游戏回到主界面。

## What Changes
- `GameMenuController.HandleBackClicked()` 不再调用 `ResumeAndCloseMenu()`，改为关闭暂停菜单并触发流程切换回主菜单
- `GamePlayController` 打开暂停菜单后订阅 `GameMenuController.OnBackRequested` 事件，在回调中调用 `GamePlayProcedure.ReturnToMainMenu()` 完成流程切换
- `GameMenuController.HandleContinueClicked()` 保持现有逻辑不变（恢复 TimeScale + 关闭菜单窗口）

## Impact
- 受影响代码: `GameMenuController.cs`、`GamePlayController.cs`
- 受影响流程: 玩家从游戏中退回主菜单的完整链路将被打通
- 无 **BREAKING** 变更（仅修改内部行为，不改变公共 API 签名）
