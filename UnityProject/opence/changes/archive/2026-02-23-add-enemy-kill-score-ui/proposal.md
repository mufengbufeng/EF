# 变更提案：增加敌人击败积分并同步玩法 UI

## 动机

当前玩法中，`GamePlayModel` 已具备积分读写能力，`GamePlayView` 与 `GamePlayController` 也具备积分展示链路，但“敌人死亡 -> 积分增加”尚未接通，导致界面分数无法随战斗进展增长。  
本次变更聚焦打通最小闭环：玩家击败敌人后增加积分，并让玩法界面实时反映积分变化。

## 变更内容

1. 补齐击败加分链路
- 在敌人死亡判定处接入积分累加逻辑。
- 约束同一敌人实例只结算一次积分，避免重复加分。
- 非击败回收（如越界回收、流程清理）不计分。

2. 修改玩法积分 UI 展示
- `GamePlayView` 统一展示“击败积分”文案与数值。
- `GamePlayController` 继续以 `GamePlayModel.CurrentScore` 作为单一数据源，驱动界面刷新。
- 暂停菜单打开时显示当前积分，打开后继续保持同步。

3. 保持实现范围最小
- 默认每击败一个敌人增加 1 分。
- 不引入连杀、倍率、敌人类型差异计分等扩展规则。

## 影响范围

- 受影响规范：
  - 新增 `gameplay-score-ui`
  - 扩展 `enemy-behavior`
- 受影响代码（工作阶段实施）：
  - `Assets/GameScripts/HotFix/GameLogic/GamePlay/Enemy/EnemyEntity.cs`
  - `Assets/GameScripts/HotFix/GameLogic/UI/Game/GamePlayView.cs`
  - `Assets/GameScripts/HotFix/GameLogic/UI/Game/GamePlayController.cs`
  - `Assets/GameScripts/HotFix/GameLogic/UI/Game/GameMenuView.cs`（如需统一积分文案）
  - `Assets/AssetRaw/UI/GamePlay/GamePlayView.prefab`（如需调整默认积分文本）

## 验收标准

1. 玩家子弹击败一个敌人后，当前积分立即增加 1。
2. 同一个敌人实例无论受到多少次后续碰撞，积分最多增加一次。
3. 敌人因越界或流程退出被回收时，不会增加积分。
4. 玩法主界面的积分文本可实时显示最新积分。
5. 暂停菜单打开时显示当前积分，且在菜单保持打开时也能同步最新积分。

## 非目标

1. 本次不实现击败连击、倍率或按敌人类型差异化奖励。
2. 本次不改动敌人生成节奏、血量配置和子弹伤害平衡。
3. 本次不引入新的 UI 框架或动画系统。
