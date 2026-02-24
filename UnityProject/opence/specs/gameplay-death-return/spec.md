# gameplay-death-return Specification

## Purpose
定义“玩家死亡后自动返回主界面”的流程规范，约束死亡通知到流程切换的触发时机、幂等行为与主菜单回归结果，确保玩法结束可预测且可回归验证。
## Requirements
### Requirement: 玩家死亡后自动结束玩法并返回主界面
系统 SHALL 在玩家死亡流程完成后自动触发玩法流程从 `GamePlayProcedure` 切换到 `MainMenuProcedure`。  
该流程 MUST 复用 `GamePlayProcedure.ReturnToMainMenu()` 作为统一入口，避免绕过既有退出清理逻辑。

#### Scenario: 玩家血量归零后自动返回主界面
- **GIVEN** 玩家处于 `GamePlayProcedure` 且玩家实体存活
- **WHEN** 玩家受到致命伤害并完成死亡流程
- **THEN** 系统自动调用 `GamePlayProcedure.ReturnToMainMenu()`
- **AND** 流程状态从 `GamePlayProcedure` 切换到 `MainMenuProcedure`
- **AND** 主菜单界面被重新打开

### Requirement: 死亡返回请求必须幂等
系统 MUST 对同一局内的“返回主界面”请求做幂等保护。  
在一次流程切换完成前，系统 SHALL NOT 重复触发第二次切换或重复执行退出清理。

#### Scenario: 同一死亡窗口收到重复返回请求
- **GIVEN** 玩家死亡后已发起一次返回主界面请求
- **WHEN** 同一帧或后续短时间内再次收到死亡回调或返回请求
- **THEN** 系统忽略重复请求
- **AND** 最终只发生一次 `GamePlayProcedure` 到 `MainMenuProcedure` 的切换
