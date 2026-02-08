# enemy-behavior 规范增量

## ADDED Requirements

### Requirement: 敌人实体继承 EntityBase

系统 SHALL 提供 `EnemyEntity` 类，继承自 `EntityBase`，实现敌人的生命周期和行为逻辑。

#### Scenario: 实体初始化时设置默认状态

- **WHEN** `OnInit` 被调用
- **THEN** 敌人实体的 Id、EntityAssetName、EntityGroup 被正确设置
- **AND** 内部状态（如行为模式、计时器）被重置为默认值

#### Scenario: 实体回收时清理状态

- **WHEN** `OnRecycle` 被调用
- **THEN** 敌人的运动状态、攻击计时器等数据被清空
- **AND** 实体准备好被对象池复用

---

### Requirement: 敌人显示时初始化位置和行为参数

系统 SHALL 在 `OnShow` 中接收 `userData`，初始化敌人的位置、移动速度、停留参数和攻击间隔。

#### Scenario: 接收行为配置数据

- **GIVEN** userData 包含 EnemyBehaviorData { MoveSpeed=3f, MoveDirection=(0,-1,0), StayDuration=2f }
- **WHEN** `OnShow(userData)` 被调用
- **THEN** 敌人的移动速度设置为 3 单位/秒
- **AND** 移动方向设置为向下 (0,-1,0)
- **AND** 停留时长设置为 2 秒

#### Scenario: 设置初始位置

- **GIVEN** userData 包含 SpawnPosition=(0, 5, 0)
- **WHEN** `OnShow(userData)` 被调用
- **THEN** 敌人的 GameObject 位置被设置为 (0, 5, 0)

#### Scenario: 激活 GameObject

- **WHEN** `OnShow` 被调用
- **THEN** 敌人的 GameObject.SetActive(true)
- **AND** 敌人在场景中可见

---

### Requirement: 敌人移动逻辑

系统 SHALL 在 `OnUpdate` 中根据移动速度和方向更新敌人位置。

#### Scenario: 直线向下移动

- **GIVEN** 敌人移动速度为 3 单位/秒，方向为 (0,-1,0)
- **WHEN** `OnUpdate(elapseSeconds: 0.1f)` 被调用
- **THEN** 敌人的 Y 轴位置减少 0.3 单位
- **AND** X 轴和 Z 轴位置保持不变

#### Scenario: 到达屏幕底部时自动销毁

- **GIVEN** 敌人当前位置为 (0, -6, 0)，屏幕底部边界为 Y = -5
- **WHEN** `OnUpdate` 检测到敌人超出边界
- **THEN** 调用 `IEntityManager.HideEntity(this.Id)` 销毁自身
- **AND** 敌人从场景中移除并回收到对象池

---

### Requirement: 敌人停留逻辑

系统 SHALL 支持敌人在到达指定位置后停留一段时间，然后继续移动或销毁。

#### Scenario: 到达停留位置时暂停移动

- **GIVEN** 敌人停留位置为 (0, 2, 0)，停留时长为 2 秒
- **WHEN** 敌人移动到 Y = 2 附近（误差 ±0.1）
- **THEN** 敌人进入停留状态
- **AND** 停止更新位置
- **AND** 启动停留计时器

#### Scenario: 停留时间结束后继续移动

- **GIVEN** 敌人已停留 2 秒
- **WHEN** 停留计时器到期
- **THEN** 敌人恢复移动状态
- **AND** 继续按原方向移动

#### Scenario: 停留期间可以攻击

- **GIVEN** 敌人处于停留状态，攻击间隔为 1 秒
- **WHEN** 停留计时器累计 1 秒
- **THEN** 触发攻击行为（如播放特效或发射子弹）
- **AND** 攻击计时器重置

---

### Requirement: 敌人攻击逻辑

系统 SHALL 支持敌人按固定间隔触发攻击行为。

#### Scenario: 定时触发攻击

- **GIVEN** 敌人攻击间隔为 1.5 秒
- **WHEN** `OnUpdate` 累计 1.5 秒
- **THEN** 触发攻击行为（初期可为日志输出或特效播放）
- **AND** 攻击计时器重置为 0

#### Scenario: 移动状态下可以攻击

- **GIVEN** 敌人处于移动状态，攻击间隔为 1 秒
- **WHEN** 移动过程中攻击计时器到期
- **THEN** 触发攻击行为
- **AND** 移动逻辑不受影响

#### Scenario: 停留状态下可以攻击

- **GIVEN** 敌人处于停留状态，攻击间隔为 1 秒
- **WHEN** 停留过程中攻击计时器到期
- **THEN** 触发攻击行为
- **AND** 停留计时器继续累加

---

### Requirement: 敌人隐藏时清理状态

系统 SHALL 在 `OnHide` 中清理敌人的运动和攻击状态，准备回收。

#### Scenario: 停用 GameObject

- **WHEN** `OnHide(isShutdown: false, userData: null)` 被调用
- **THEN** 敌人的 GameObject.SetActive(false)
- **AND** 敌人在场景中不可见

#### Scenario: 清理行为状态

- **WHEN** `OnHide` 被调用
- **THEN** 移动速度、方向、停留计时器、攻击计时器等数据被重置
- **AND** 实体准备回收到对象池

---

### Requirement: 敌人行为状态管理

系统 SHALL 使用状态枚举管理敌人的行为模式（移动、停留、攻击）。

#### Scenario: 初始状态为移动

- **WHEN** `OnShow` 被调用
- **THEN** 敌人的初始状态为 Moving
- **AND** 在 OnUpdate 中执行移动逻辑

#### Scenario: 状态切换到停留

- **GIVEN** 敌人到达停留位置
- **WHEN** OnUpdate 检测到满足停留条件
- **THEN** 状态切换为 Staying
- **AND** 在 OnUpdate 中执行停留逻辑

#### Scenario: 状态切换回移动

- **GIVEN** 敌人停留时间到期
- **WHEN** 停留计时器结束
- **THEN** 状态切换回 Moving
- **AND** 在 OnUpdate 中恢复移动逻辑
