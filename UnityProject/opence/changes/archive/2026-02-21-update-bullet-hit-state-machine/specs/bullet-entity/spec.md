## ADDED Requirements

### Requirement: 子弹命中敌对单位时扣血并立即回收
`BulletEntity` SHALL 在触发碰撞且判定为敌对目标时，对目标应用伤害并立即销毁（回收）自身。

#### Scenario: 玩家子弹命中敌人
- **GIVEN** 子弹 `OwnerType = Player`，目标实体实现 `IHealth`
- **WHEN** 子弹命中 `EnemyEntity`
- **THEN** 系统对敌人调用 `TakeDamage(BulletData.Damage)`
- **AND** 子弹调用 `IEntityManager.HideEntity(子弹Id)` 回收自身

#### Scenario: 敌人子弹命中玩家
- **GIVEN** 子弹 `OwnerType = Enemy`，目标实体实现 `IHealth`
- **WHEN** 子弹命中 `PlayerAvatarEntity`
- **THEN** 系统对玩家调用 `TakeDamage(BulletData.Damage)`
- **AND** 子弹调用 `IEntityManager.HideEntity(子弹Id)` 回收自身

#### Scenario: 命中已死亡目标
- **GIVEN** 目标实现 `IHealth` 且 `IsDead = true`
- **WHEN** 子弹命中该目标
- **THEN** 系统 SHALL NOT 再次调用 `TakeDamage`
- **AND** 子弹仍应立即回收，避免同帧重复碰撞

### Requirement: 子弹隐藏后不可见且不可继续参与碰撞
子弹被回收后 MUST 停用其 `Handle` 并重置运行时数据，确保对象池复用安全。

#### Scenario: 子弹隐藏时停用对象
- **WHEN** `BulletEntity.OnHide` 被调用
- **THEN** 子弹 `Handle` 被设为非激活状态
- **AND** 场景中不再可见该子弹

#### Scenario: 子弹回收后数据清理
- **WHEN** `BulletEntity.OnRecycle` 被调用
- **THEN** 飞行方向、速度、归属方与伤害等运行时字段被重置
- **AND** 下次复用不会继承上一发子弹的状态

### Requirement: 子弹记录发射者并支持按发射者清理
子弹系统 SHALL 记录每颗子弹的发射者实体标识，并提供按发射者批量清理能力，以支持“角色死亡时清理自己发射的子弹”。

#### Scenario: 发射时记录发射者
- **GIVEN** 发射方调用 `IBulletModule.Fire` 时提供发射者实体标识
- **WHEN** 子弹实体 `OnShow` 完成初始化
- **THEN** 子弹保存该发射者实体标识用于后续筛选

#### Scenario: 按发射者清理子弹
- **GIVEN** 某角色实体 ID 为 `X`
- **WHEN** 调用子弹模块的按发射者清理接口并传入 `X`
- **THEN** 系统隐藏所有发射者 ID 为 `X` 的在场子弹
- **AND** 发射者 ID 不为 `X` 的子弹保持不变
