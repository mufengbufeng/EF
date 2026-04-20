## ADDED Requirements

### Requirement: HealthFeature 管理生命值与死亡
HealthFeature SHALL 继承 FeatureBase（或 FeatureBase<TData>），管理实体的当前生命值、最大生命值和死亡状态。提供 TakeDamage(float damage) 方法供外部调用。

#### Scenario: 初始化时设置最大生命值
- **WHEN** HealthFeature 通过 OnSetup 接收到配置数据（包含 MaxHealth）
- **THEN** CurrentHealth 等于 MaxHealth，IsDead 为 false

#### Scenario: 受到伤害后生命值减少
- **WHEN** CurrentHealth > 0 时调用 TakeDamage(20f)
- **THEN** CurrentHealth 减少 20f

#### Scenario: 生命值降为 0 时触发死亡
- **WHEN** CurrentHealth <= 0 时
- **THEN** IsDead 变为 true，CurrentHealth 钳制为 0

#### Scenario: 已死亡时忽略伤害
- **WHEN** IsDead 为 true 时调用 TakeDamage
- **THEN** 无任何效果

### Requirement: DragInputFeature 处理拖拽输入
DragInputFeature SHALL 处理鼠标和触控的拖拽输入，支持偏移量对齐（点击位置与实体中心不一致时的平滑过渡）。通过 Entity.Handle 操作 Transform 位置。

#### Scenario: 鼠标按下在实体上开始拖拽
- **WHEN** 鼠标左键按下且命中实体 Collider2D
- **THEN** 记录拖拽偏移量，进入拖拽状态

#### Scenario: 拖拽中实体跟随指针移动
- **WHEN** 拖拽状态中鼠标/触控持续移动
- **THEN** 实体位置 = 指针世界坐标 + 偏移量（偏移量逐渐归零）

#### Scenario: 释放鼠标/触控结束拖拽
- **WHEN** 鼠标左键释放或触控结束
- **THEN** 重置拖拽状态

#### Scenario: 同时支持 Input System 和 Legacy Input
- **WHEN** 使用 #if ENABLE_INPUT_SYSTEM / ENABLE_LEGACY_INPUT_MANAGER 编译指令
- **THEN** 两种输入后端均可正常工作

### Requirement: AttackFeature 处理自动攻击
AttackFeature SHALL 按固定间隔执行自动攻击，支持默认子弹发射和自定义攻击执行器。攻击间隔和子弹速度通过 OnSetup 传入。

#### Scenario: 按间隔自动发射子弹
- **WHEN** 攻击计时器累积达到 AttackInterval
- **THEN** 通过 IBulletModule.Fire 发射一枚默认子弹

#### Scenario: 自定义攻击执行器优先执行
- **WHEN** 设置了自定义攻击执行器且返回 true
- **THEN** 不执行默认子弹发射

#### Scenario: 自定义攻击执行器返回 false 时回退默认
- **WHEN** 设置了自定义攻击执行器且返回 false（或抛异常）
- **THEN** 执行默认子弹发射

#### Scenario: Feature 禁用时不攻击
- **WHEN** AttackFeature.Enabled 为 false
- **THEN** OnUpdate 中不累积攻击计时器

### Requirement: PositionClampFeature 限制位置边界
PositionClampFeature SHALL 将实体位置约束在摄像机可视区域内，支持正交和透视摄像机，可配置边界内边距。

#### Scenario: 正交摄像机下约束位置
- **WHEN** 使用正交摄像机且实体位置超出可视区域
- **THEN** 实体位置被钳制在可视区域减去 BoundaryPadding 的范围内

#### Scenario: 内边距大于可视区域时居中
- **WHEN** BoundaryPadding 值使得有效区域宽度或高度为负
- **THEN** 实体 x 或 y 坐标钳制到摄像机中心

#### Scenario: 透视摄像机下通过 Viewport 坐标约束
- **WHEN** 使用透视摄像机
- **THEN** 通过 WorldToViewportPoint / ViewportToWorldPoint 进行约束

### Requirement: PlayerAvatarEntity 编排 Feature 生命周期
PlayerAvatarEntity SHALL 在 OnShow 中添加所有 Feature 并注册回调，在 OnHide 中清理回调并移除 Feature。Entity 仍实现 IHealth 接口，通过回调字段转发给 HealthFeature。

#### Scenario: OnShow 时创建 Feature 并注册回调
- **WHEN** PlayerAvatarEntity.OnShow 被调用
- **THEN** 依次 AddFeature 四个 Feature，将 HealthFeature 的方法注册到 Entity 的回调字段

#### Scenario: OnUpdate 编排 Feature 启停
- **WHEN** HealthFeature.IsDead 为 true
- **THEN** 禁用 DragInputFeature 和 AttackFeature

#### Scenario: OnHide 时清理所有 Feature
- **WHEN** PlayerAvatarEntity.OnHide 被调用
- **THEN** 清空所有回调字段，移除所有 Feature

#### Scenario: IHealth 接口通过回调转发
- **WHEN** 外部通过 IHealth 接口调用 TakeDamage
- **THEN** 调用被转发到 HealthFeature.TakeDamage

#### Scenario: 未注册回调时安全返回默认值
- **WHEN** 回调字段为 null（如 Feature 未注册）
- **THEN** CurrentHealth / MaxHealth 返回 0，IsDead 返回 false，TakeDamage 不执行
