## ADDED Requirements

### Requirement: 子弹归属类型枚举
子弹系统 SHALL 使用枚举类型表示子弹的归属方,而非字符串类型。

#### Scenario: 定义子弹归属类型
- **WHEN** 定义子弹归属方
- **THEN** 系统 SHALL 提供 BulletOwnerType 枚举,包含 Player 和 Enemy 两个值
- **AND** BulletData 类 SHALL 使用 BulletOwnerType 类型的 OwnerType 属性

#### Scenario: 类型安全的归属判断
- **WHEN** 判断子弹归属方
- **THEN** 系统 SHALL 使用枚举值比较,避免字符串拼写错误
- **AND** 编译器 SHALL 在编译期检查类型正确性

### Requirement: 子弹碰撞检测
子弹 SHALL 在击中目标时触发碰撞检测,并执行相应的伤害逻辑。

#### Scenario: 子弹击中敌人
- **WHEN** 玩家发射的子弹击中敌人实体
- **THEN** 系统 SHALL 检测到碰撞
- **AND** 系统 SHALL 对敌人实体造成伤害
- **AND** 子弹 SHALL 立即回收到对象池

#### Scenario: 子弹击中玩家
- **WHEN** 敌人发射的子弹击中玩家实体
- **THEN** 系统 SHALL 检测到碰撞
- **AND** 系统 SHALL 对玩家实体造成伤害
- **AND** 子弹 SHALL 立即回收到对象池

#### Scenario: 友军判断
- **WHEN** 子弹击中目标
- **THEN** 系统 SHALL 根据子弹的 OwnerType 判断是否为敌对关系
- **AND** 玩家子弹 SHALL NOT 对玩家造成伤害
- **AND** 敌人子弹 SHALL NOT 对敌人造成伤害

#### Scenario: 子弹预制体配置
- **WHEN** 加载子弹预制体
- **THEN** 预制体 SHALL 包含 CircleCollider2D 组件
- **AND** Collider2D SHALL 设置为 IsTrigger = true
- **AND** 预制体 SHALL 包含 BulletCollisionHandler 脚本组件

### Requirement: 实体生命值系统
玩家和敌人实体 SHALL 实现生命值系统,支持扣血和死亡判断。

#### Scenario: 实体初始化生命值
- **WHEN** 实体显示时(OnShow)
- **THEN** 系统 SHALL 初始化实体的当前生命值(CurrentHealth)
- **AND** 系统 SHALL 设置实体的最大生命值(MaxHealth)
- **AND** IsDead 标志 SHALL 设置为 false

#### Scenario: 实体受到伤害
- **WHEN** 实体调用 TakeDamage 方法
- **THEN** 系统 SHALL 减少实体的当前生命值
- **AND** 系统 SHALL 检查生命值是否小于等于 0
- **AND** 若生命值小于等于 0,系统 SHALL 标记实体为死亡状态(IsDead = true)

#### Scenario: 实体死亡
- **WHEN** 实体生命值降至 0 或以下
- **THEN** 系统 SHALL 设置 IsDead = true
- **AND** 系统 SHALL 播放死亡动画
- **AND** 系统 SHALL 在动画播放完成后隐藏实体
- **AND** 死亡后实体 SHALL NOT 再接受伤害

#### Scenario: 实体生命值接口
- **WHEN** 其他系统需要访问实体生命值
- **THEN** 实体 SHALL 实现 IHealth 接口
- **AND** IHealth 接口 SHALL 包含 CurrentHealth 属性
- **AND** IHealth 接口 SHALL 包含 MaxHealth 属性
- **AND** IHealth 接口 SHALL 包含 IsDead 属性
- **AND** IHealth 接口 SHALL 包含 TakeDamage(float damage) 方法

### Requirement: 子弹击中后自动回收
子弹击中目标后 SHALL 立即回收到对象池,避免重复碰撞和资源浪费。

#### Scenario: 击中时回收子弹
- **WHEN** 子弹碰撞检测到有效目标
- **THEN** BulletCollisionHandler SHALL 通知 BulletModule 回收该子弹
- **AND** BulletModule SHALL 将子弹 GameObject 回收到对象池
- **AND** 子弹 SHALL 被标记为非活跃状态

#### Scenario: 对象池回收清理
- **WHEN** 子弹被回收到对象池
- **THEN** 系统 SHALL 禁用子弹 GameObject(SetActive(false))
- **AND** 系统 SHALL 清理 BulletCollisionHandler 的运行时状态
- **AND** 子弹 SHALL 准备好下次复用

### Requirement: 碰撞处理组件生命周期
BulletCollisionHandler 组件 SHALL 正确管理子弹的碰撞检测生命周期。

#### Scenario: 子弹生成时初始化
- **WHEN** 子弹从对象池中生成(Spawn)
- **THEN** BulletModule SHALL 为子弹 GameObject 添加或获取 BulletCollisionHandler 组件
- **AND** 系统 SHALL 设置 BulletCollisionHandler 的 OwnerType 属性
- **AND** 系统 SHALL 设置回收回调(OnBulletHit)

#### Scenario: 子弹回收时清理
- **WHEN** 子弹被回收到对象池(Recycle)
- **THEN** 系统 SHALL 清空 BulletCollisionHandler 的 OwnerType 属性
- **AND** 系统 SHALL 清空回收回调引用
- **AND** Collider2D SHALL 保持启用状态(下次 Spawn 时可用)

### Requirement: 死亡动画和延迟隐藏
实体死亡时 SHALL 播放死亡动画,并在动画完成后隐藏实体。

#### Scenario: 敌人死亡动画
- **WHEN** 敌人实体生命值归零
- **THEN** 系统 SHALL 调用 PlayDeadAnimation 方法
- **AND** Animator SHALL 播放 EnemyDead 动画状态
- **AND** 系统 SHALL 在 1 秒后隐藏敌人实体

#### Scenario: 玩家死亡动画
- **WHEN** 玩家实体生命值归零
- **THEN** 系统 SHALL 调用 PlayBoomAnimation 方法
- **AND** Animator SHALL 播放 Boom 动画状态
- **AND** 系统 SHALL 在动画播放完成后隐藏玩家实体

#### Scenario: 死亡期间不接受伤害
- **WHEN** 实体处于死亡状态(IsDead = true)
- **THEN** 后续的 TakeDamage 调用 SHALL 被忽略
- **AND** 系统 SHALL NOT 重复播放死亡动画
- **AND** 系统 SHALL NOT 重复隐藏实体
