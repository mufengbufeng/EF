## ADDED Requirements

### Requirement: 玩家实体支持点击命中后拖拽（鼠标与触屏）

系统 SHALL 提供 `PlayerAvatarEntity`（继承 `EntityBase`）并在 `OnUpdate` 中处理拖拽输入。  
玩家拖拽 MUST 采用“按下命中玩家后开始拖拽”的规则，避免点击空白区域误移动。

#### Scenario: 鼠标点击命中玩家后拖拽

**Given** 玩家实体已显示且可被指针命中  
**When** 玩家使用鼠标左键在玩家飞机上按下并移动  
**Then** 玩家实体进入拖拽状态并跟随指针移动  
**And** 释放鼠标后退出拖拽状态

#### Scenario: 触屏命中玩家后拖拽

**Given** 玩家实体已显示且可被触点命中  
**When** 玩家使用单指在玩家飞机上按下并拖动  
**Then** 玩家实体进入拖拽状态并跟随触点移动  
**And** 手指抬起后退出拖拽状态

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
默认实现 MUST 发射向上子弹（`OwnerTag = "Player"`），并通过 `IBulletModule.Fire(BulletData)` 执行。  
攻击流程 SHALL 保留可替换执行入口，以便后续技能模块接管攻击行为。

#### Scenario: 定时自动发射默认子弹

**Given** 玩家攻击间隔配置为有效正数  
**When** `OnUpdate` 累计时间达到攻击间隔  
**Then** 玩家调用 `IBulletModule.Fire` 发射子弹  
**And** 子弹方向为向上  
**And** 攻击计时器被重置

#### Scenario: 注入自定义攻击执行逻辑

**Given** 玩家攻击入口已被自定义攻击执行器替换  
**When** 攻击触发条件满足  
**Then** 玩家调用自定义执行器完成攻击  
**And** 不需要改动拖拽输入与移动逻辑

### Requirement: 玩家动画状态遵循 Move/Boom 约定

玩家实体 SHALL 在常态播放 `Move`，并在死亡流程入口播放 `Boom`。  
动画状态切换 MUST 与实体生命周期保持一致，避免回收后残留错误状态。

#### Scenario: 玩家显示后进入 Move 状态

**Given** 玩家实体首次显示或从对象池复用显示  
**When** `OnShow` 完成初始化  
**Then** Animator 播放 `Move` 状态  
**And** 玩家以可操作状态进入战斗

#### Scenario: 触发死亡流程时播放 Boom

**Given** 外部系统触发玩家死亡流程  
**When** 玩家实体收到死亡播放请求  
**Then** Animator 播放 `Boom` 状态  
**And** 后续由上层流程决定何时隐藏/回收实体
