# 变更提案：添加玩家飞机 Avatar 模块

## 动机

当前 `GamePlayProcedure` 已具备背景滚动、敌机生成和子弹系统，但缺少玩家飞机实体，导致核心交互链路（操控-射击-对抗）不完整。  
本次变更聚焦补齐玩家 Avatar 模块，提供“可拖拽操控 + 自动攻击”的最小可用能力，并为后续技能系统扩展预留清晰扩展点。

## 变更内容

1. 新增玩家模块能力 `player-avatar-module`
- 提供 `IPlayerAvatarModule` 与 `PlayerAvatarModule` 规划。
- 负责玩家实体组创建、玩家实体生成、退出玩法回收。
- 通过 `ModuleSystem` 的 GamePlay scope 统一生命周期管理。

2. 新增玩家行为能力 `player-avatar-behavior`
- 提供 `PlayerAvatarEntity` 与行为配置数据规划。
- 支持点击命中后拖拽（PC 鼠标）与触屏拖拽（移动设备）。
- 支持自动攻击（默认单发向上子弹）。
- 约定 Avatar 动画状态 `Move` 与 `Boom` 的使用方式。

3. 集成到玩法流程
- 在 `GamePlayProcedure` 场景就绪后，基于 `PlayerPoint` 初始化并启动玩家模块。
- 在流程退出时通过 `ShutdownScope` 自动清理玩家模块与玩家实体。

## 影响范围

- 受影响规范：
  - 新增 `player-avatar-module`
  - 新增 `player-avatar-behavior`
- 受影响代码（工作阶段实施）：
  - `Assets/GameScripts/HotFix/GameLogic/Procedure/GamePlay/GamePlayProcedure.cs`
  - `Assets/GameScripts/HotFix/GameLogic/GamePlay/Avatar/`（计划新增目录）
  - `Assets/AssetRaw/Prefabs/Avatar/Avatar.prefab`（必要时补充命中检测组件）
- 复用依赖：
  - `EF.Entity.IEntityManager`
  - `EF.Common.ModuleSystem`
  - `GameLogic.IBulletModule`

## 验收标准

1. 进入玩法后，玩家飞机在 `PlayerPoint` 位置生成并可见。
2. 鼠标点击飞机并拖拽时，飞机跟随移动；触屏按住飞机拖拽时同样生效。
3. 玩家飞机按固定间隔自动发射子弹（向上，`OwnerTag = "Player"`）。
4. 玩家实体默认播放 `Move` 动画；触发死亡流程时可切换到 `Boom` 动画。
5. 退出 `GamePlayProcedure` 后，玩家模块和玩家实体被完整清理，无残留实例。

## 非目标

1. 本次不实现玩家技能系统、技能 UI、技能冷却逻辑。
2. 本次不实现完整碰撞/伤害结算，仅为后续系统预留动画与攻击扩展接口。
