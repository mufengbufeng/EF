## ADDED Requirements

### Requirement: 玩法主界面实时展示当前积分

系统 SHALL 通过 `GamePlayController` 订阅 `GamePlayModel.CurrentScore` 变化并刷新 `GamePlayView`。  
系统 MUST 在玩法界面打开时显示积分默认值。  
积分文本格式 MUST 统一为“击败积分: {score}”。

#### Scenario: 打开玩法界面时显示默认积分

- **GIVEN** 玩家进入玩法并打开 `GamePlayView`
- **WHEN** `GamePlayView.OnOpen` 执行
- **THEN** 积分文本显示为“击败积分: 0”

#### Scenario: 击败敌人后主界面积分实时刷新

- **GIVEN** 玩法主界面已打开且积分当前为 0
- **AND** 敌人被玩家击败触发加分（见 `enemy-behavior`）
- **WHEN** `GamePlayModel.CurrentScore` 更新为 1
- **THEN** `GamePlayController` 刷新 `GamePlayView` 积分文本为“击败积分: 1”

### Requirement: 暂停菜单积分与主界面保持一致

系统 SHALL 在暂停菜单打开时展示当前积分，并在菜单保持打开期间持续同步积分变化。

#### Scenario: 打开暂停菜单时显示当前积分

- **GIVEN** 当前积分为 3
- **WHEN** 玩家点击暂停并打开 `GameMenuView`
- **THEN** 暂停菜单积分显示为“击败积分: 3”

#### Scenario: 暂停菜单打开期间同步积分变化

- **GIVEN** 暂停菜单处于打开状态且当前显示积分为 3
- **AND** 发生新的敌人击败事件使积分变为 4
- **WHEN** `GamePlayController` 处理 `CurrentScore` 属性变化
- **THEN** `GameMenuView` 积分显示同步更新为“击败积分: 4”
