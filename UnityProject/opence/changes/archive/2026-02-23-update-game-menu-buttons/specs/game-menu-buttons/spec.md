## ADDED Requirements

### Requirement: 暂停菜单 Continue 按钮关闭菜单继续游戏
当玩家点击暂停菜单的 Continue 按钮时，系统 SHALL 恢复 `Time.timeScale` 为 1 并关闭暂停菜单窗口，使游戏继续运行。

#### Scenario: 玩家点击 Continue 继续游戏
- **WHEN** 玩家在暂停菜单中点击 Continue 按钮
- **THEN** `Time.timeScale` 恢复为 1
- **THEN** 暂停菜单窗口被关闭
- **THEN** 游戏从暂停处继续运行

### Requirement: 暂停菜单 Back 按钮退出游戏回到主界面
当玩家点击暂停菜单的 Back 按钮时，系统 SHALL 关闭暂停菜单窗口、恢复 `Time.timeScale` 为 1，并切换流程状态到 `MainMenuProcedure`，使玩家回到主界面。

#### Scenario: 玩家点击 Back 退出游戏
- **WHEN** 玩家在暂停菜单中点击 Back 按钮
- **THEN** `Time.timeScale` 恢复为 1
- **THEN** 暂停菜单窗口被关闭
- **THEN** 流程状态从 `GamePlayProcedure` 切换到 `MainMenuProcedure`
- **THEN** `GamePlayProcedure.OnLeave` 自动执行清理（摄像机堆栈恢复、玩法模块销毁）
- **THEN** 主菜单界面被打开

#### Scenario: Back 按钮触发后玩法资源被正确清理
- **WHEN** 玩家点击 Back 按钮回到主界面
- **THEN** 所有注册在 GamePlayScope 的模块被 `ShutdownScope` 清理
- **THEN** 摄像机堆栈恢复为独立 Base 模式
