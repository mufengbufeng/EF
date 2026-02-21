# 实现记录（add-player-avatar-module）

## 1. 功能实现摘要

1. 新增玩家模块与接口：
- `Assets/GameScripts/HotFix/GameLogic/GamePlay/Avatar/IPlayerAvatarModule.cs`
- `Assets/GameScripts/HotFix/GameLogic/GamePlay/Avatar/PlayerAvatarModule.cs`

2. 新增玩家实体行为与数据：
- `Assets/GameScripts/HotFix/GameLogic/GamePlay/Avatar/PlayerAvatarEntity.cs`
- `Assets/GameScripts/HotFix/GameLogic/GamePlay/Avatar/PlayerAvatarBehaviorData.cs`

3. 接入玩法流程：
- 修改 `Assets/GameScripts/HotFix/GameLogic/Procedure/GamePlay/GamePlayProcedure.cs`
- 在场景引用绑定后初始化并注册 `PlayerAvatarModule`
- 使用 `PlayerPoint` 作为出生锚点，缺失时回退到相机后备位置

## 2. 资源与场景契约校验

1. Avatar 动画状态校验（任务 4.1）
- `Assets/AssetRaw/Animation/Avatar/AvatarAnimation.controller` 已包含状态 `Move`、`Boom`。

2. 点击命中方案（任务 4.2）
- `Avatar.prefab` 当前未配置 `Collider2D`。
- 实现采用“最小补偿”方案：`PlayerAvatarEntity.OnShow` 中若未找到 `Collider2D`，自动补 `BoxCollider2D`，并记录一次告警日志。
- 命中检测优先 `Collider2D.OverlapPoint`，并保留 `SpriteRenderer.bounds` 兜底逻辑。

3. 场景引用校验（任务 4.3）
- `Assets/AssetRaw/Scene/Game.unity` 的 `Root` 下 `ReferenceCollector` 包含 `PlayerPoint` 键。

## 3. 技能扩展挂点说明

1. `PlayerAvatarEntity` 内提供自定义攻击入口：
- `SetCustomAttackExecutor(Func<Vector3, bool> attackExecutor)`
- 约定：返回 `true` 表示已处理攻击，跳过默认子弹发射。

2. 默认攻击保留：
- 通过 `IBulletModule.Fire(BulletData)` 发射向上子弹（`OwnerTag = "Player"`）。

## 4. 验证说明

1. 已完成：
- `opence validate add-player-avatar-module --strict` 通过。
- 代码级联调与静态逻辑检查完成（模块生命周期、拖拽状态机、自动攻击与边界约束）。
- 已兼容 Input System：玩家拖拽输入改为 `ENABLE_INPUT_SYSTEM` 分支使用 `Mouse.current` / `Touchscreen.current`，并保留 `ENABLE_LEGACY_INPUT_MANAGER` 兼容分支。

2. 环境限制：
- 当前终端环境无法执行 Unity Editor 交互式手工验证（鼠标/触屏拖拽实操）。
- `dotnet build Assembly-CSharp.csproj` 受 Unity 生成的 `GameLogic.csproj` 文件项未即时刷新影响，未能直接用于最终行为验收。
