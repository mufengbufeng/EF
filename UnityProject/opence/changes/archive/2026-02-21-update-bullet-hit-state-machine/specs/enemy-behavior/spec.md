## MODIFIED Requirements

### Requirement: 敌人行为状态管理
系统 SHALL 使用状态枚举管理敌人的行为模式（`Moving`、`Staying`、`Dead`）。  
敌人进入 `Dead` 状态后 MUST 停止移动、停留与攻击更新，并等待死亡回收流程结束。

#### Scenario: 初始状态为 Moving
- **WHEN** `OnShow` 被调用
- **THEN** 敌人的初始状态为 `Moving`
- **AND** 在 `OnUpdate` 中执行移动逻辑

#### Scenario: 状态切换到 Staying
- **GIVEN** 敌人到达停留位置
- **WHEN** `OnUpdate` 检测到满足停留条件
- **THEN** 状态切换为 `Staying`

#### Scenario: 生命值归零切换到 Dead
- **GIVEN** 敌人当前生命值将被伤害降至 0 或以下
- **WHEN** `TakeDamage` 完成死亡判定
- **THEN** 敌人状态切换为 `Dead`
- **AND** 后续帧不再执行移动/停留/攻击逻辑

## ADDED Requirements

### Requirement: 敌人受击扣血与死亡动画联动
敌人实体 SHALL 支持子弹命中扣血，并在死亡时切换到死亡动画状态机。

#### Scenario: 受到伤害时扣减生命值
- **GIVEN** 敌人 `IsDead = false`
- **WHEN** 敌方判定为敌对的子弹命中并调用 `TakeDamage`
- **THEN** 敌人当前生命值按伤害值减少

#### Scenario: 死亡时播放 EnemyDead 并延迟隐藏
- **GIVEN** 敌人生命值降至 0 或以下
- **WHEN** 敌人进入 `Dead` 状态
- **THEN** Animator 播放 `EnemyDead`
- **AND** 敌人碰撞组件被禁用以避免重复受击
- **AND** 敌人触发“清理自身已发射在场子弹”的流程
- **AND** 敌人在死亡动画窗口后调用隐藏/回收流程
