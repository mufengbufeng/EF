## ADDED Requirements

### Requirement: 敌人被玩家击败时结算积分

系统 SHALL 在敌人由玩家子弹击败时增加玩法积分。  
系统 MUST 保证同一敌人实例仅结算一次击败积分。  
系统 MUST NOT 在非击败回收路径（如越界回收、流程清理）中增加积分。  
积分变化后的界面展示链路 SHALL 由 `gameplay-score-ui` 能力负责。

#### Scenario: 玩家子弹击败敌人后加分

- **GIVEN** 敌人当前 `IsDead = false` 且当前生命值大于 0
- **AND** 敌人被玩家子弹命中并调用 `TakeDamage`
- **WHEN** 敌人生命值在本次伤害后降至 0 或以下并进入 `Dead` 状态
- **THEN** 系统调用玩法积分模型增加 1 分
- **AND** 该敌人后续不再重复触发加分

#### Scenario: 非击败回收不加分

- **GIVEN** 敌人因越界检测或流程退出触发隐藏/回收
- **WHEN** 未经过死亡判定分支
- **THEN** 系统不增加玩法积分
