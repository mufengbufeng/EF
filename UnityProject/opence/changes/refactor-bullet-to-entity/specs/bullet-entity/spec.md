## ADDED Requirements

### Requirement: 子弹实体类
系统 SHALL 提供 BulletEntity 类,继承 EntityBase,管理子弹的生命周期。

#### Scenario: 子弹实体初始化
- **WHEN** 子弹实体创建时
- **THEN** 系统 SHALL 调用 OnInit 方法
- **AND** 设置实体 ID、资源名称和实体组

#### Scenario: 子弹实体显示
- **WHEN** 调用 OnShow 方法时
- **THEN** 系统 SHALL 从 userData 获取 BulletData
- **AND** 设置子弹的位置、方向、速度和归属类型
- **AND** 根据飞行方向设置子弹旋转角度
- **AND** 激活子弹 GameObject

#### Scenario: 子弹实体更新
- **WHEN** 每帧调用 OnUpdate 方法时
- **THEN** 系统 SHALL 根据方向和速度移动子弹
- **AND** 检测子弹是否超出边界
- **AND** 如果超出边界则调用 HideEntity 隐藏自己

#### Scenario: 子弹实体隐藏
- **WHEN** 调用 OnHide 方法时
- **THEN** 系统 SHALL 清理子弹的运行时数据
- **AND** 停用子弹 GameObject

#### Scenario: 子弹实体回收
- **WHEN** 调用 OnRecycle 方法时
- **THEN** 系统 SHALL 重置所有字段为初始值
- **AND** 准备实体复用

### Requirement: 子弹实体碰撞检测
BulletEntity SHALL 在内部实现碰撞检测逻辑,无需额外的 MonoBehaviour 组件。

#### Scenario: 碰撞触发
- **WHEN** 子弹的 Collider2D 触发 OnTriggerEnter2D 事件时
- **THEN** 系统 SHALL 获取碰撞对象的 EntityBase 组件
- **AND** 如果碰撞对象不是实体则忽略

#### Scenario: 友军判断
- **WHEN** 碰撞对象是实体时
- **THEN** 系统 SHALL 根据子弹的 OwnerType 和目标实体类型判断是否应造成伤害
- **AND** 玩家子弹 SHALL 只伤害 EnemyEntity
- **AND** 敌人子弹 SHALL 只伤害 PlayerAvatarEntity
- **AND** 友军不造成伤害

#### Scenario: 伤害应用
- **WHEN** 判断应该造成伤害时
- **THEN** 系统 SHALL 获取目标实体的 IHealth 接口
- **AND** 调用 TakeDamage 方法应用伤害
- **AND** 记录日志

#### Scenario: 子弹销毁
- **WHEN** 伤害应用完成后
- **THEN** 系统 SHALL 调用 EntityManager.HideEntity 隐藏自己
- **AND** 子弹实体回收到对象池

#### Scenario: 死亡目标不受伤
- **WHEN** 目标实体的 IsDead 为 true 时
- **THEN** 系统 SHALL NOT 应用伤害
- **AND** 系统 SHALL 继续隐藏子弹

### Requirement: BulletModule 使用 EntityManager
BulletModule SHALL 使用 EntityManager 创建和管理子弹实体,而非自定义对象池。

#### Scenario: 初始化子弹实体组
- **WHEN** BulletModule.InitializeAsync 被调用时
- **THEN** 系统 SHALL 检查 EntityManager 中是否存在 "Bullet" 实体组
- **AND** 如果不存在则创建 "Bullet" 实体组
- **AND** 配置对象池选项(初始大小、最大大小)

#### Scenario: 发射子弹使用 EntityManager
- **WHEN** BulletModule.Fire 被调用时
- **THEN** 系统 SHALL 生成唯一的子弹实体 ID
- **AND** 调用 EntityManager.ShowEntityAsync 创建子弹实体
- **AND** 将 BulletData 作为 userData 传递给实体
- **AND** 不等待异步完成(fire-and-forget)

#### Scenario: 子弹 ID 生成
- **WHEN** 需要生成子弹实体 ID 时
- **THEN** 系统 SHALL 使用自增 ID 生成器
- **AND** 子弹 ID 从 1000000 开始
- **AND** 每次发射 ID 自增 1

#### Scenario: 移除自定义对象池
- **WHEN** BulletModule 重构完成后
- **THEN** 系统 SHALL NOT 包含自定义对象池代码
- **AND** 系统 SHALL NOT 在 Update 中移动子弹
- **AND** 系统 SHALL NOT 管理活跃子弹列表

#### Scenario: 模块关闭
- **WHEN** BulletModule.Shutdown 被调用时
- **THEN** 系统 SHALL 销毁 "Bullet" 实体组
- **AND** EntityManager 自动隐藏所有子弹实体

### Requirement: 移除 BulletCollisionHandler
系统 SHALL 移除 BulletCollisionHandler MonoBehaviour 组件。

#### Scenario: 不再使用独立碰撞组件
- **WHEN** 子弹预制体加载时
- **THEN** 预制体 SHALL NOT 包含 BulletCollisionHandler 组件
- **AND** 只包含 BulletEntity 组件
- **AND** 碰撞逻辑在 BulletEntity 内部实现

#### Scenario: 代码清理
- **WHEN** 重构完成后
- **THEN** BulletCollisionHandler.cs 文件 SHALL 被删除
- **AND** BulletModule SHALL NOT 引用 BulletCollisionHandler

### Requirement: 子弹预制体配置
子弹预制体 SHALL 配置必要的组件以支持 Entity 系统和碰撞检测。

#### Scenario: 必需组件
- **WHEN** 子弹预制体被加载时
- **THEN** 预制体 SHALL 包含 BulletEntity 脚本组件
- **AND** 预制体 SHALL 包含 CircleCollider2D 组件(IsTrigger = true)
- **AND** 预制体 SHALL 包含 Rigidbody2D 组件(Kinematic 模式)
- **AND** 预制体 SHALL 配置正确的 Layer

#### Scenario: Collider 配置
- **WHEN** 子弹预制体配置 Collider 时
- **THEN** CircleCollider2D.IsTrigger SHALL 为 true
- **AND** Radius SHALL 设置为合适的值(0.1-0.15)

#### Scenario: Rigidbody 配置
- **WHEN** 子弹预制体配置 Rigidbody 时
- **THEN** Rigidbody2D.bodyType SHALL 为 Kinematic
- **AND** Rigidbody2D.simulated SHALL 为 true
- **AND** 用于触发 OnTriggerEnter2D 事件

### Requirement: 子弹边界检测
BulletEntity SHALL 在 OnUpdate 中检测边界并自动销毁。

#### Scenario: 检测屏幕边界
- **WHEN** 子弹更新时
- **THEN** 系统 SHALL 获取摄像机的可视区域边界
- **AND** 添加缓冲区域(BoundaryBuffer = 1f)

#### Scenario: 超出边界销毁
- **WHEN** 子弹位置超出边界时
- **THEN** 系统 SHALL 调用 EntityManager.HideEntity 隐藏自己
- **AND** 记录日志

#### Scenario: 边界检测优化
- **WHEN** 计算边界时
- **THEN** 系统 SHALL 缓存摄像机引用
- **AND** 如果摄像机为空则使用默认边界值
