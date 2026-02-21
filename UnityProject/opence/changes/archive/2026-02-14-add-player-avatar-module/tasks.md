# 实施任务清单

## 1. 玩家模块骨架（player-avatar-module）

- [x] 1.1 新增 `IPlayerAvatarModule` 接口，定义 `Configure`、`InitializeAsync`、`SetSpawnAnchor` 等能力。
- [x] 1.2 新增 `PlayerAvatarModule` 实现类，注入 `IEntityManager`，管理玩家实体生成与回收。
- [x] 1.3 在模块中创建/复用玩家实体组（`EntityFactory -> PlayerAvatarEntity`）。
- [x] 1.4 模块 `Shutdown()` 保证幂等：隐藏玩家实体、清空缓存状态、可重复调用。

## 2. 玩家实体行为（player-avatar-behavior）

- [x] 2.1 新增 `PlayerAvatarBehaviorData`，承载初始位置、拖拽边界、攻击间隔/速度等配置。
- [x] 2.2 新增 `PlayerAvatarEntity : EntityBase`，实现 `OnShow/OnUpdate/OnHide/OnRecycle` 生命周期。
- [x] 2.3 实现“命中后拖拽”输入流程：鼠标与触屏统一指针状态管理。
- [x] 2.4 实现位置边界限制（基于相机可视区域或配置边界）并保持 `Z` 轴稳定。
- [x] 2.5 实现自动攻击（默认向上单发）并接入 `IBulletModule.Fire(BulletData)`。
- [x] 2.6 拆分攻击执行入口（默认攻击 + 可替换扩展点），为后续技能模块预留挂点。
- [x] 2.7 接入动画：出生/常态使用 `Move`，死亡流程入口使用 `Boom`。

## 3. 流程集成（GamePlayProcedure）

- [x] 3.1 在 `GamePlayProcedure` 增加玩家模块字段和配置常量（Avatar 资源名等）。
- [x] 3.2 在场景引用解析后、子弹模块就绪后初始化玩家模块并生成玩家实体。
- [x] 3.3 复用 `PlayerPoint` 作为玩家初始锚点；锚点缺失时输出告警并使用后备位置。
- [x] 3.4 退出流程时依赖 `ModuleSystem.ShutdownScope(GamePlayScope)` 清理玩家模块（无需重复手动回收）。

## 4. 资源与场景契约校验

- [x] 4.1 校验 `Assets/AssetRaw/Prefabs/Avatar/Avatar.prefab` 的 Animator 状态 `Move/Boom` 可用。
- [x] 4.2 校验玩家点击命中方案：若缺少 `Collider2D`，补充最小命中组件方案并记录在实现说明。
- [x] 4.3 校验场景 `Root` 的 `ReferenceCollector` 持续提供 `PlayerPoint` 引用。

## 5. 验证与回归

- [x] 5.1 手工验证（Editor 鼠标）：点击玩家飞机拖拽移动，松开后停止。
- [x] 5.2 手工验证（触屏设备或模拟）：单指按住玩家飞机拖拽移动。
- [x] 5.3 手工验证：玩家自动攻击频率稳定，子弹方向向上，`OwnerTag` 为 `Player`。
- [x] 5.4 手工验证：切换流程离开玩法后，玩家实体与玩家模块无残留。
- [x] 5.5 执行 `opence validate add-player-avatar-module --strict`，确保规范层校验通过。

## 6. 文档与可维护性

- [x] 6.1 为新增公共接口、实体与关键行为方法补充中文 XML 注释。
- [x] 6.2 在复杂输入状态切换处补充必要中文注释（仅解释关键分支）。
- [x] 6.3 更新实现记录，明确“技能扩展挂点”的接入方式与约束。

## 依赖关系

- 任务 2 依赖任务 1 的模块与实体组约定。
- 任务 3 依赖任务 1 与任务 2 完成。
- 任务 5 依赖任务 2、任务 3、任务 4 完成。

## 并行化建议

- 任务 1 与任务 4 可并行推进（代码骨架与资源校验分开处理）。
- 任务 2.7（动画接入）可与任务 2.3~2.6 并行，由同一人最终合并验证。
