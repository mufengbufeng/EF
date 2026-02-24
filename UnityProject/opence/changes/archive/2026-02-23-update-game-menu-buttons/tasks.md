## 1. 修改 GameMenuController 的 Back 按钮处理逻辑
- [x] 1.1 修改 `HandleBackClicked()`：先关闭暂停菜单窗口并恢复 `Time.timeScale`，再触发 `OnBackRequested` 事件
- [x] 1.2 确认 `HandleContinueClicked()` 逻辑无需变更

## 2. 在 GamePlayController 中订阅 OnBackRequested 并触发返回主菜单
- [x] 2.1 在 `OpenPauseMenuAsync()` 打开暂停菜单成功后，获取 `GameMenuController` 实例并订阅 `OnBackRequested` 事件
- [x] 2.2 在 `OnBackRequested` 回调中，通过 `GameLogicEntry.Procedure.GetProcedure<GamePlayProcedure>()` 获取流程实例并调用 `ReturnToMainMenu()` 切换到 `MainMenuProcedure`
- [x] 2.3 确保在 `GamePlayController.OnExit()` 中通过 `UnsubscribeMenuController()` 正确取消订阅，避免内存泄漏

## 3. 补充修改：GamePlayProcedure
- [x] 3.1 在 `OnInit` 中缓存 `_procedureOwner`（参照 `MainMenuProcedure` 模式）
- [x] 3.2 将 `ReturnToMainMenu(ProcedureOwner)` 改为无参方法 `ReturnToMainMenu()`

## 4. 验证
- [x] 4.1 确认代码无编译错误（无旧签名遗留调用）
- [x] 4.2 确认 Continue 按钮行为：关闭暂停菜单、恢复 TimeScale、继续游戏
- [x] 4.3 确认 Back 按钮行为：关闭暂停菜单、恢复 TimeScale、切换流程回到主菜单
