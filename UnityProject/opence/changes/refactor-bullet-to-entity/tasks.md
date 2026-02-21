# Tasks: 重构子弹为 Entity 系统

## 1. 创建 BulletEntity
- [x] 1.1 创建 BulletEntity.cs 类,继承 EntityBase
- [x] 1.2 在 BulletEntity 中添加运行时数据(Direction, Speed, OwnerType)
- [x] 1.3 实现 OnInit 方法,初始化实体
- [x] 1.4 实现 OnShow 方法,配置子弹数据(从 userData 获取 BulletData)
- [x] 1.5 实现 OnUpdate 方法,移动子弹和边界检测
- [x] 1.6 实现 OnHide 方法,清理状态
- [x] 1.7 实现 OnRecycle 方法,重置数据
- [x] 1.8 添加 OnTriggerEnter2D 方法处理碰撞检测
- [x] 1.9 实现友军判断逻辑
- [x] 1.10 实现伤害应用和子弹隐藏逻辑

## 2. 重构 BulletModule
- [x] 2.1 移除 BulletModule 中的对象池相关代码(_bulletPool, ActiveBullet, _activeBullets)
- [x] 2.2 移除 CreateBulletInstance, OnBulletSpawn, OnBulletRecycle, OnBulletDestroy 方法
- [x] 2.3 移除 OnBulletHitTarget 回调方法
- [x] 2.4 添加 IEntityManager 依赖
- [x] 2.5 修改 Configure 方法,不再需要加载预制体
- [x] 2.6 修改 InitializeAsync 方法,创建 Bullet EntityGroup
- [x] 2.7 重构 Fire 方法,使用 EntityManager.ShowEntityAsync 创建子弹
- [x] 2.8 移除 Update 方法中的子弹移动和边界检测逻辑
- [x] 2.9 修改 Shutdown 方法,销毁 EntityGroup

## 3. 清理和接口调整
- [x] 3.1 删除 BulletCollisionHandler.cs 文件
- [x] 3.2 简化 IBulletModule 接口(移除不必要的方法)
- [x] 3.3 更新 BulletData 添加必要的字段(Damage)

## 4. 预制体和配置
- [ ] 4.1 确保 BulletCommon.prefab 有 CircleCollider2D 组件
- [ ] 4.2 确保 Collider2D 设置为 IsTrigger = true
- [ ] 4.3 确保预制体有 Rigidbody2D 组件(Kinematic 模式)

## 5. 测试验证
- [ ] 5.1 测试子弹生成和销毁是否正常
- [ ] 5.2 测试子弹碰撞检测是否正常
- [ ] 5.3 测试子弹对象池回收是否正常
- [ ] 5.4 测试玩家和敌人受伤逻辑是否正常
- [ ] 5.5 测试边界检测和自动销毁是否正常
