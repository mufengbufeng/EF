# Change: 添加子弹碰撞检测与伤害系统

## Why
当前子弹系统只有发射和移动功能,子弹击中敌人或玩家时没有任何反馈,无法实现游戏玩法的核心机制。需要实现子弹碰撞检测、伤害计算和击中后的反馈效果。

## What Changes
- 将 BulletData.OwnerTag 从 string 改为 enum 类型,提高类型安全性
- 为子弹预制体添加 Collider2D 组件和碰撞检测脚本
- 实现子弹击中目标后的自动销毁逻辑
- 为玩家和敌人实体添加生命值系统
- 实现伤害计算和应用逻辑,基于 OwnerTag 判断友军
- 添加击中反馈(播放死亡动画、隐藏实体)

## Impact
- Affected specs: 新增 `bullet-collision` capability
- Affected code:
  - `Assets/GameScripts/HotFix/GameLogic/GamePlay/Bullet/BulletData.cs` - 添加 BulletOwnerType enum
  - `Assets/GameScripts/HotFix/GameLogic/GamePlay/Bullet/BulletModule.cs` - 传递碰撞上下文
  - `Assets/GameScripts/HotFix/GameLogic/GamePlay/Bullet/` - 新增 BulletCollisionHandler.cs
  - `Assets/GameScripts/HotFix/GameLogic/GamePlay/Enemy/EnemyEntity.cs` - 添加 Health 和 TakeDamage 方法
  - `Assets/GameScripts/HotFix/GameLogic/GamePlay/Avatar/PlayerAvatarEntity.cs` - 添加 Health 和 TakeDamage 方法
  - `Assets/AssetRaw/Prefabs/Bullet/BulletCommon.prefab` - 添加 Collider2D 组件
