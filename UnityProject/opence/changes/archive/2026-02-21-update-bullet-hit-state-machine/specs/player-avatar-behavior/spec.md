## MODIFIED Requirements

### Requirement: 玩家支持自动攻击并预留技能扩展挂点
系统 SHALL 支持玩家按固定间隔自动攻击。  
默认实现 MUST 发射向上子弹（`OwnerType = Player`），并通过 `IBulletModule.Fire(BulletData)` 执行。  
当玩家处于死亡状态（`IsDead = true`）时，系统 SHALL NOT 继续执行自动攻击。  
攻击流程 SHALL 保留可替换执行入口，以便后续技能模块接管攻击行为。

#### Scenario: 存活状态按间隔发射子弹
- **GIVEN** 玩家 `IsDead = false` 且攻击间隔为有效正数
- **WHEN** `OnUpdate` 累计时间达到攻击间隔
- **THEN** 玩家调用 `IBulletModule.Fire` 发射子弹

#### Scenario: 死亡后停止自动攻击
- **GIVEN** 玩家生命值已降至 0 且 `IsDead = true`
- **WHEN** 后续帧继续调用 `OnUpdate`
- **THEN** 玩家 SHALL NOT 再触发自动攻击

### Requirement: 玩家动画状态遵循 Move/Boom 约定
玩家实体 SHALL 在常态播放 `Move`，并在死亡流程入口播放 `Boom`。  
玩家接收伤害时 MUST 扣减当前生命值；当生命值小于等于 0 时 MUST 进入死亡状态。  
进入死亡状态后 MUST 禁用玩家碰撞组件，并停止拖拽输入与攻击行为。  
动画状态切换 MUST 与实体生命周期保持一致，避免回收后残留错误状态。

#### Scenario: 玩家受到子弹伤害后扣血
- **GIVEN** 玩家 `IsDead = false` 且当前生命值大于 0
- **WHEN** 敌方子弹命中并调用 `TakeDamage`
- **THEN** 玩家当前生命值按伤害值减少
- **AND** 生命值大于 0 时保持存活状态

#### Scenario: 玩家死亡时切换 Boom 并阻断行为
- **GIVEN** 玩家当前生命值将被本次伤害降至 0 或以下
- **WHEN** `TakeDamage` 完成死亡判定
- **THEN** 玩家设置 `IsDead = true` 并播放 `Boom`
- **AND** 玩家碰撞组件被禁用
- **AND** 玩家拖拽输入与自动攻击逻辑被阻断
- **AND** 玩家触发“清理自身已发射在场子弹”的流程
