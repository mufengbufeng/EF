# 玩家 Avatar 模块设计

## 背景

当前飞机大战玩法已具备以下能力：
- 背景滚动（`GameBackgroundModule`）
- 敌机生成与行为（`EnemySpawnerModule` + `EnemyEntity`）
- 子弹系统（`BulletModule`）

缺口在于玩家侧：`GamePlayProcedure` 有 `PlayerPoint` 场景锚点，但没有对应玩家实体与操控模块，无法形成完整玩法闭环。

## 目标

1. 在 `GamePlayProcedure` 中引入玩家 Avatar 模块，保证进入玩法后自动生成玩家实体。
2. 玩家支持点击命中后拖拽（鼠标）和触屏拖拽（移动端）。
3. 玩家支持自动攻击，攻击实现保持易读并可被后续技能系统替换/扩展。
4. 明确 Avatar 动画 `Move` / `Boom` 的状态使用约定。

## 非目标

1. 不实现完整伤害结算和碰撞系统。
2. 不实现技能 UI、技能输入、技能配置系统。
3. 不引入复杂输入框架，保持最小可行实现。

## 关键决策

### 决策 1：沿用“模块 + 实体”分层

- `PlayerAvatarModule` 负责流程级职责：创建实体组、生成/回收实体、配置参数。
- `PlayerAvatarEntity` 负责运行时行为：拖拽输入、位置更新、自动攻击、动画状态。

理由：
- 与现有 `EnemySpawnerModule` / `EnemyEntity` 模式一致，便于维护。
- `GamePlayProcedure` 只处理模块装配，不承载细粒度行为逻辑。

### 决策 2：输入处理放在玩家实体内部，统一鼠标与触屏语义

- 在 `OnUpdate` 中读取输入状态。
- 使用“按下命中玩家 -> 进入拖拽 -> 持续更新位置 -> 松开结束拖拽”的状态机。
- 仅追踪一个有效指针（鼠标或单指），避免首版多指复杂度。

理由：
- 最小复杂度即可满足“点击/触屏拖拽”需求。
- 行为集中在实体内部，后续改为输入系统注入时迁移成本可控。

### 决策 3：攻击逻辑预留可替换执行入口

- 首版提供默认攻击（向上单发子弹）。
- 将攻击触发与具体发射实现解耦，保留可替换入口（如策略接口或独立执行器）。

理由：
- 满足当前“玩家和敌人一样自动攻击”。
- 兼容后续技能模块接管攻击，不需要重写输入与移动逻辑。

### 决策 4：动画状态采用显式播放约定

- 常态/出生后播放 `Move`。
- 死亡流程入口播放 `Boom`（由后续碰撞/血量系统触发调用）。

理由：
- 与现有资源命名一致（`AvatarAnimation.controller` 中存在 `Move`、`Boom`）。
- 保持状态切换可读、可追踪。

## 结构草图（工作阶段参考）

- `Assets/GameScripts/HotFix/GameLogic/GamePlay/Avatar/IPlayerAvatarModule.cs`
- `Assets/GameScripts/HotFix/GameLogic/GamePlay/Avatar/PlayerAvatarModule.cs`
- `Assets/GameScripts/HotFix/GameLogic/GamePlay/Avatar/PlayerAvatarEntity.cs`
- `Assets/GameScripts/HotFix/GameLogic/GamePlay/Avatar/PlayerAvatarBehaviorData.cs`
- 修改 `Assets/GameScripts/HotFix/GameLogic/Procedure/GamePlay/GamePlayProcedure.cs`

## 生命周期与时序

1. `GamePlayProcedure.OnEnterAsync`
- 清理旧 scope
- 初始化背景模块
- 初始化子弹模块并等待就绪
- 加载游戏场景并绑定 `PlayerPoint`
- 注册并初始化 `PlayerAvatarModule`
- 由模块生成玩家实体

2. 运行中
- `ModuleSystem.Update` 驱动 `PlayerAvatarEntity.OnUpdate`
- 玩家处理拖拽输入、移动与自动攻击

3. `GamePlayProcedure.OnLeave`
- `ModuleSystem.ShutdownScope(GamePlayScope)`
- `PlayerAvatarModule.Shutdown()` 回收玩家实体并清理状态

## 风险与权衡

1. 命中检测依赖碰撞组件
- 风险：`Avatar.prefab` 当前可能无 `Collider2D`，导致“点击命中”判定不稳定。
- 缓解：在实施阶段补充最小 `Collider2D`，并在任务中加入资源契约校验。

2. 触屏与鼠标行为差异
- 风险：多指触控会引入指针抢占问题。
- 缓解：首版仅支持单指有效指针，后续再扩展多指策略。

3. 攻击扩展接口设计过度
- 风险：为未来技能过早抽象，影响首版可读性。
- 缓解：只保留一个可替换入口，不引入完整技能框架。

## 待确认项

1. 玩家拖拽边界是否以“相机可视区域内边距”作为统一规则（本计划默认是）。
2. 默认攻击参数（间隔、子弹速度）是否交由策划配置文件统一管理（本计划先在模块配置中提供）。
