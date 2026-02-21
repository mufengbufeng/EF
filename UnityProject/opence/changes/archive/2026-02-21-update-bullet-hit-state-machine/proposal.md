# Change: 更新子弹命中后的生命值与状态机联动

## Why
当前 `BulletEntity` / `PlayerAvatarEntity` / `EnemyEntity` 已具备基础扣血代码，但缺少统一且可验证的“命中后状态迁移”约束。现状中存在死亡后仍可能继续输入、移动或攻击的窗口期，也缺少对子弹命中后回收行为的明确规格约束。

## What Changes
- 明确 `BulletEntity` 命中有效目标时的行为：按 `Damage` 扣血后立即隐藏/回收子弹自身。
- 明确玩家受击后的状态机联动：生命值变化、死亡标记、碰撞禁用、动画切换与行为阻断（输入/攻击）。
- 明确敌人受击后的状态机联动：生命值变化、死亡态切换、动画切换与行为阻断（移动/停留/攻击）。
- 增加“发射者维度”子弹清理能力：角色死亡时，销毁该角色自身已发射且仍存活的子弹。
- 补充并收敛跨实体战斗交互规格，确保后续 Work 阶段可以直接按规格落地并回归验证。

## Impact
- Affected specs:
  - `bullet-entity`（新增命中扣血与回收语义）
  - `player-avatar-behavior`（补充受击/死亡状态机约束与死亡清弹）
  - `enemy-behavior`（补充受击/死亡状态机约束与死亡清弹）
- Affected code:
  - `Assets/GameScripts/HotFix/GameLogic/GamePlay/Bullet/BulletEntity.cs`
  - `Assets/GameScripts/HotFix/GameLogic/GamePlay/Bullet/BulletData.cs`
  - `Assets/GameScripts/HotFix/GameLogic/GamePlay/Bullet/IBulletModule.cs`
  - `Assets/GameScripts/HotFix/GameLogic/GamePlay/Bullet/BulletModule.cs`
  - `Assets/GameScripts/HotFix/GameLogic/GamePlay/Avatar/PlayerAvatarEntity.cs`
  - `Assets/GameScripts/HotFix/GameLogic/GamePlay/Enemy/EnemyEntity.cs`
  - （如需）对应 Prefab/Animator 配置文件
