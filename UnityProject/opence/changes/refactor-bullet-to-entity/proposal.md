# Change: 重构子弹为 Entity 系统

## Why
当前子弹使用 MonoBehaviour (BulletCollisionHandler) 处理碰撞,与项目的 Entity 架构不一致。敌人和玩家都使用 Entity 系统,而子弹使用传统的 GameObject + MonoBehaviour,导致架构不统一且难以扩展。

需要将子弹重构为完整的 Entity,使其能够:
1. 与现有 Entity 系统统一管理
2. 利用 Entity 的生命周期管理(OnInit, OnShow, OnHide, OnRecycle)
3. 使用 Entity 的对象池机制,而非 BulletModule 自定义的对象池
4. 通过 Collider2D 的 OnTriggerEnter2D 实现碰撞检测

## What Changes
- 创建 `BulletEntity` 类,继承自 `EntityBase`
- 移除 `BulletCollisionHandler` MonoBehaviour
- 移除 `BulletModule` 中的对象池管理代码
- 修改 `BulletModule.Fire` 使用 `IEntityManager.ShowEntityAsync` 创建子弹
- 在 `BulletEntity` 中实现碰撞检测逻辑(OnTriggerEnter2D)
- 子弹击中后使用 `IEntityManager.HideEntity` 隐藏实体

## Impact
- Affected specs: 新增 `bullet-entity` capability, 修改 `bullet-collision` capability
- Affected code:
  - `Assets/GameScripts/HotFix/GameLogic/GamePlay/Bullet/` - 新增 BulletEntity.cs
  - `Assets/GameScripts/HotFix/GameLogic/GamePlay/Bullet/BulletModule.cs` - 重构为使用 EntityManager
  - `Assets/GameScripts/HotFix/GameLogic/GamePlay/Bullet/BulletCollisionHandler.cs` - **删除**
  - `Assets/GameScripts/HotFix/GameLogic/GamePlay/Bullet/IBulletModule.cs` - 简化接口
- Breaking changes:
  - **BREAKING**: BulletModule 不再管理对象池,依赖 EntityManager
  - **BREAKING**: 需要创建 "Bullet" EntityGroup
