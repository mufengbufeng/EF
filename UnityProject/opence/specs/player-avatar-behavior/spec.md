# player-avatar-behavior Specification

## Purpose
定义玩家飞机实体（`PlayerAvatarEntity`）的输入拖拽、边界限制、自动攻击与动画状态约束，并保留后续技能系统接管攻击行为的扩展点。
## Requirements
### Requirement: 玩家实体支持点击命中后拖拽（鼠标与触屏）

系统 SHALL 提供 `PlayerAvatarEntity`（继承 `EntityBase`）并在 `OnUpdate` 中处理拖拽输入。  
玩家拖拽 MUST 采用“按下命中玩家后开始拖拽”的规则，避免点击空白区域误移动。  
当首次按下位置不在飞机中心时，系统 MUST 在拖拽持续期间让“飞机中心相对指针/触点的偏移量”逐步收敛到 0，以获得一致的起手手感。  
偏移收敛过程 SHALL 保持连续，不得出现瞬时跳变；并且该过程 MUST 保持与 `玩家拖拽位置限制在有效战斗区域` 的边界约束兼容。

#### Scenario: 鼠标从机体非中心位置按下后中心逐步对齐

**Given** 玩家实体已显示且可被指针命中  
**And** 玩家在飞机中心以外的位置按下鼠标左键并持续按住  
**When** 玩家保持拖拽输入  
**Then** 玩家实体进入拖拽状态并持续跟随指针移动  
**And** 飞机中心相对指针的偏移量逐步减小并最终接近 0  
**And** 释放鼠标后退出拖拽状态

#### Scenario: 触屏从机体非中心位置按下后中心逐步对齐

**Given** 玩家实体已显示且可被触点命中  
**And** 玩家使用单指在飞机中心以外的位置按下并持续拖动  
**When** 玩家保持触屏拖拽输入  
**Then** 玩家实体进入拖拽状态并持续跟随触点移动  
**And** 飞机中心相对触点的偏移量逐步减小并最终接近 0  
**And** 手指抬起后退出拖拽状态

#### Scenario: 从中心按下时保持直接跟随体验

**Given** 玩家实体已显示且玩家从飞机中心附近按下开始拖拽  
**When** 玩家持续拖动  
**Then** 玩家实体表现为近似中心直接跟随  
**And** 不引入明显额外迟滞

### Requirement: 玩家拖拽位置限制在有效战斗区域

系统 SHALL 对玩家拖拽结果做边界限制，防止玩家实体移动到不可见或不可交互区域。  
玩家位置更新后 MUST 保持固定的 `Z` 轴值，避免 2D 平面错层。

#### Scenario: 拖拽超出屏幕边界时被钳制

**Given** 玩家正在拖拽且目标位置超出允许范围  
**When** 位置计算完成  
**Then** 玩家位置被钳制在战斗区域内  
**And** 玩家不会离开相机可视范围

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

