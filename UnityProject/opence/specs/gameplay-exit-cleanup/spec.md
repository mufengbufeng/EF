# gameplay-exit-cleanup Specification

## Purpose
定义玩法退出到主界面的统一清理规范，明确 OnLeave 收口、场景卸载策略、局内数据重置与事件解绑要求，避免局内数据、场景与回调在多局之间产生残留。
## Requirements
### Requirement: 返回主界面时执行统一玩法退出清理
系统 SHALL 在所有返回主界面的路径（至少包括暂停菜单 Back 与玩家死亡自动返回）执行同一套玩法退出清理。  
该清理流程 MUST 统一绑定在 `GamePlayProcedure.OnLeave`，并 SHALL NOT 分散在各退出入口重复实现。  
该清理流程 MUST 包含：关闭玩法相关 UI、恢复 `Time.timeScale = 1`、恢复摄像机堆栈状态、执行 `ModuleSystem.ShutdownScope(GamePlayScope)`。

#### Scenario: 暂停菜单 Back 返回时执行统一清理
- **GIVEN** 玩家处于 `GamePlayProcedure` 且暂停菜单已打开
- **WHEN** 玩家点击 Back 返回主界面
- **THEN** 玩法相关 UI 被关闭（`GamePlayView` 与 `GameMenuView`）
- **AND** `Time.timeScale` 恢复为 1
- **AND** `ModuleSystem.ShutdownScope(GamePlayScope)` 被调用并清理玩法模块
- **AND** UICamera 从玩法摄像机堆栈中移除并恢复为 Base

#### Scenario: 玩家死亡返回时执行统一清理
- **GIVEN** 玩家在 `GamePlayProcedure` 内死亡并触发自动返回
- **WHEN** 流程切换离开 `GamePlayProcedure`
- **THEN** 系统执行与 Back 返回相同的退出清理序列
- **AND** 不出现遗漏清理的玩法模块或窗口残留

#### Scenario: 新增退出方式时复用 OnLeave 清理收口
- **GIVEN** 后续新增任意退出入口（例如结算页按钮）
- **WHEN** 该入口触发从 `GamePlayProcedure` 离开
- **THEN** 系统仍通过 `GamePlayProcedure.OnLeave` 执行完整清理
- **AND** 退出入口本身不重复实现另一套清理逻辑

### Requirement: 退出玩法时必须清除局内数据与运行时引用
系统 MUST 在退出玩法时清除局内数据，并释放玩法级运行时引用，避免跨局残留。  
至少包括：重置 `GamePlayModel` 局内数据（例如 `CurrentScore`）、清空玩法流程持有的模块/场景引用、解除玩法级事件订阅。

#### Scenario: 回到主界面后重新开局不继承上一局数据
- **GIVEN** 上一局玩法中 `CurrentScore` 大于 0
- **WHEN** 玩家返回主界面后再次进入玩法
- **THEN** 新一局 `CurrentScore` 从 0 开始显示（见 `gameplay-score-ui`）
- **AND** 不触发上一局残留的事件回调或控制器回调

### Requirement: 退出玩法时执行玩法场景卸载策略
系统 MUST 在 `GamePlayProcedure.OnLeave` 阶段触发玩法场景卸载尝试，以尽早释放 `Game` 场景资源。  
若卸载失败，系统 SHALL 记录错误日志并继续主流程切换，MUST NOT 阻断返回主界面。

#### Scenario: 返回主界面时尝试卸载玩法场景
- **GIVEN** 当前已加载 `Game` 场景且流程从 `GamePlayProcedure` 离开
- **WHEN** `OnLeave` 执行退出清理
- **THEN** 系统触发场景卸载调用
- **AND** 卸载成功时 `Game` 场景资源被释放

#### Scenario: 场景卸载失败时不中断返回主界面
- **GIVEN** `OnLeave` 已进入场景卸载步骤
- **WHEN** 场景卸载调用失败或抛出异常
- **THEN** 系统记录失败日志
- **AND** 流程仍成功切换到 `MainMenuProcedure`
