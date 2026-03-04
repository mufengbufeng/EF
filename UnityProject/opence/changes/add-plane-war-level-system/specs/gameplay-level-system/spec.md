## ADDED Requirements
### Requirement: 玩法关卡配置加载
系统 MUST 通过 Luban 配置表提供关卡参数，至少包含关卡 ID、关卡名、通关击杀目标、敌人速度倍率与敌人生成间隔。玩法流程 MUST 能读取当前关卡配置并用于运行时参数。

#### Scenario: 进入玩法时读取当前关卡配置
- **GIVEN** 配置系统已加载且存在 `TbLevel`
- **AND** 当前关卡 ID 为有效配置项
- **WHEN** 玩家进入 `GamePlayProcedure`
- **THEN** 流程读取当前关卡配置
- **AND** 将敌人速度倍率和生成间隔应用到敌人生成逻辑

### Requirement: 关卡进度持久化与恢复
系统 MUST 提供关卡模块用于持久化当前关卡 ID，并在游戏启动后恢复；持久化介质 MUST 为 PlayerPrefs。

#### Scenario: 启动后恢复关卡进度
- **GIVEN** PlayerPrefs 已保存关卡 ID
- **WHEN** 关卡模块初始化
- **THEN** 模块恢复该关卡 ID 作为当前关卡
- **AND** 若配置缺失则回退到最小可用关卡 ID

### Requirement: 杀敌计数与通关判定
系统 MUST 在玩法中记录本局对当前关卡的杀敌计数，并基于 `kill_target` 进行通关判定。

#### Scenario: 击败敌人累计到通关阈值
- **GIVEN** 当前关卡 `kill_target` 为 10
- **AND** 当前杀敌计数为 9
- **WHEN** 再次击败 1 个敌人
- **THEN** 关卡模块将杀敌计数更新为 10
- **AND** 通关状态为已达成

### Requirement: 通关推进到下一关
系统 MUST 在当前关卡达成通关条件后推进到下一关，并持久化新的关卡 ID。

#### Scenario: 通关后推进关卡
- **GIVEN** 当前关卡为 1 且下一关配置存在
- **WHEN** 当前关卡达成通关
- **THEN** 系统将当前关卡推进为 2
- **AND** 新关卡 ID 被写入 PlayerPrefs

#### Scenario: 最后一关通关时保持在末关
- **GIVEN** 当前关卡已是配置表中最大关卡 ID
- **WHEN** 当前关卡达成通关
- **THEN** 系统保持当前关卡 ID 不变
- **AND** 不发生越界关卡访问

### Requirement: 与主流程和体力校验协同
系统 MUST 保持开始游戏前的体力校验流程，且 `MainMenuProcedure.StartGame()` 在切换玩法流程前能够明确进入当前关卡上下文。

#### Scenario: 体力充足后进入当前关卡玩法
- **GIVEN** 主界面体力校验通过
- **WHEN** 调用 `MainMenuProcedure.StartGame()`
- **THEN** 流程切换到 `GamePlayProcedure`
- **AND** 玩法按照关卡模块的当前关卡配置运行
