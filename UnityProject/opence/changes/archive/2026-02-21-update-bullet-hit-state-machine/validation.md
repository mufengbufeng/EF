# Validation Record（2026-02-21）

## 1. 代码路径验证
- [x] 玩家发射子弹会写入 `SourceEntityId = PlayerAvatarEntity.Id`。
- [x] 敌人发射子弹会写入 `SourceEntityId = EnemyEntity.Id`。
- [x] `IBulletModule` 已新增 `ClearBulletsBySource(int sourceEntityId)` 接口。
- [x] `BulletModule.ClearBulletsBySource` 已按发射者筛选在场 `BulletEntity` 并调用 `HideEntity` 回收。
- [x] `BulletEntity.OnHide` 已显式 `Handle.SetActive(false)`，并清理运行时字段（方向、速度、归属、伤害、发射者）。
- [x] `PlayerAvatarEntity` 死亡时禁用碰撞器、停止输入/攻击更新，并触发清理自身子弹。
- [x] `EnemyEntity` 已加入 `Dead` 状态，死亡后停止移动/停留/攻击/边界逻辑，并触发清理自身子弹。

## 2. 任务映射验证（对应 tasks.md 4.x）
- [x] 4.1/4.2：命中后仍由 `BulletEntity.HandleTriggerEnter2D -> TakeDamage -> HideSelf` 完成扣血与立即回收。
- [x] 4.3：玩家 `OnUpdate` 新增 `_isDead` 短路；敌人 `OnUpdate` 新增 `Dead` 短路。
- [x] 4.4/4.5：死亡清弹按 `SourceEntityId` 精确筛选，理论上不会影响其他发射者子弹。
- [x] 4.6：死亡动画入口与 `DelayedHide(1.0f)` 保留，回收后对象会停用并重置状态。
- [x] PlayMode：已由用户在 Unity PlayMode 实机验证通过（对应 4.1~4.6 场景）。

## 3. Review 修复验证
- [x] 已为玩家/敌人的 `DelayedHide` 增加生命周期 token 与实体 ID 校验，避免对象复用导致误隐藏。
- [x] 玩家 `DelayedHide` 改为使用缓存的 `_entityManager`，不再在延迟回调中调用 `ModuleSystem.Get<IEntityManager>()`。

## 4. 工具校验
- `opence validate update-bullet-hit-state-machine --strict`：通过（见终端记录）。

## 5. 已知限制
- 尝试 `dotnet build GameLogic.csproj` 时受沙箱中的 dotnet 首次初始化/工具路径问题影响，命令未提供可用编译结果；本次以代码路径审查与 opence 规范校验为主。
