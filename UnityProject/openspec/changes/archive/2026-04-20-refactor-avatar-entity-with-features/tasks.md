## 1. Feature 框架数据初始化扩展

- [x] 1.1 IFeature 接口增加 `void OnSetup(object data)` 方法声明
- [x] 1.2 FeatureBase 增加 `public virtual void OnSetup(object data)` 空实现
- [x] 1.3 新建 FeatureBase<TData> 泛型基类，实现 OnSetup 类型检查转发到 OnSetup(TData data)
- [x] 1.4 IFeatureContainer 增加 `T AddFeature<T>(object data)` 和 `void SetupFeature<T>(object data)` 重载
- [x] 1.5 FeatureContainer 实现带数据的 AddFeature：在 SetEntity 之后、OnInit 之前调用 OnSetup(data)
- [x] 1.6 FeatureContainer 实现 SetupFeature：对已有 Feature 调用 OnSetup(data)，不存在时静默返回
- [x] 1.7 原有无参 AddFeature<T>() 保持兼容，内部调用 AddFeature<T>(null)

## 2. Feature 配置数据类

- [x] 2.1 新建 HealthFeatureData：MaxHealth(float)
- [x] 2.2 新建 DragInputData：BoundaryPadding(float), FixedZ(float)
- [x] 2.3 新建 AttackData：AttackInterval(float), BulletSpeed(float), SourceEntityId(int)
- [x] 2.4 新建 PositionClampData：BoundaryPadding(float), FixedZ(float)

## 3. HealthFeature

- [x] 3.1 新建 HealthFeature : FeatureBase<HealthFeatureData>，管理 CurrentHealth/MaxHealth/IsDead
- [x] 3.2 实现 OnSetup(HealthFeatureData) 初始化生命值
- [x] 3.3 实现 TakeDamage(float) 伤害逻辑与死亡判定
- [x] 3.4 暴露死亡回调事件供 Entity 编排使用

## 4. DragInputFeature

- [x] 4.1 新建 DragInputFeature : FeatureBase<DragInputData>，处理鼠标/触控拖拽
- [x] 4.2 实现 OnSetup(DragInputData) 配置边界参数和固定 Z
- [x] 4.3 从 PlayerAvatarEntity 迁移 UpdateDragInput 全套逻辑（Touch/Mouse 双输入后端）
- [x] 4.4 通过 Entity.Handle 和 Entity.Features.GetFeature<PositionClampFeature>() 操作位置

## 5. AttackFeature

- [x] 5.1 新建 AttackFeature : FeatureBase<AttackData>，处理自动攻击
- [x] 5.2 实现 OnSetup(AttackData) 配置攻击间隔和子弹速度
- [x] 5.3 从 PlayerAvatarEntity 迁移 UpdateAttack / ExecuteAttack / FireDefaultBullet 逻辑
- [x] 5.4 保留 SetCustomAttackExecutor(Func<Vector3, bool>) 支持
- [x] 5.5 OnUpdate 中累积计时器并执行攻击，Disabled 时跳过

## 6. PositionClampFeature

- [x] 6.1 新建 PositionClampFeature : FeatureBase<PositionClampData>，限制位置边界
- [x] 6.2 实现 OnSetup(PositionClampData) 配置边界参数
- [x] 6.3 从 PlayerAvatarEntity 迁移 ClampToCameraBounds / SetClampedPosition 逻辑
- [x] 6.4 提供公共 ClampPosition(Vector3) → Vector3 方法供 DragInputFeature 调用

## 7. PlayerAvatarEntity 重构

- [x] 7.1 移除所有内联的拖拽、攻击、生命值、位置约束逻辑
- [x] 7.2 OnShow：解析 PlayerAvatarBehaviorData，AddFeature 四个 Feature 并传入配置数据
- [x] 7.3 OnShow：将 HealthFeature 方法注册到 IHealth 回调字段
- [x] 7.4 OnUpdate：调用 base.OnUpdate() 分发到 Feature，检查 HealthFeature 状态编排其他 Feature 启停
- [x] 7.5 OnHide：清空回调字段，移除所有 Feature
- [x] 7.6 OnRecycle：确保 ResetRuntimeState 清理所有本地状态
- [x] 7.7 保留 Handle 管理、动画控制（PlayMoveAnimation/PlayBoomAnimation）在 Entity 中
- [x] 7.8 保留死亡流程编排（禁用碰撞器、清理子弹、播放爆炸动画、延迟隐藏）在 Entity 中

## 8. 验证

- [x] 8.1 编译通过，无编译错误
- [x] 8.2 运行游戏，验证玩家拖拽、自动攻击、受伤死亡流程正常
