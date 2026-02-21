# Tasks: EntityView 碰撞桥接机制实现

## 1. 接口定义
- [x] 1.1 创建 `ICollisionHandler` 接口，定义 HandleTriggerEnter2D 方法

## 2. EntityView 组件
- [x] 2.1 创建 `EntityView` MonoBehaviour 类
- [x] 2.2 添加 Entity 引用字段
- [x] 2.3 实现 OnTriggerEnter2D，转发给 ICollisionHandler

## 3. EntityManager 集成
- [x] 3.1 在 SetEntityHandle 中为 GameObject 添加 EntityView 组件
- [x] 3.2 将 Entity 引用注入到 EntityView
- [x] 3.3 在 OnEntityRecycle 中清理 EntityView 的引用
- [x] 3.4 复用实体时重新注入 EntityView（Review 修复）

## 4. BulletEntity 修改
- [x] 4.1 实现 ICollisionHandler 接口
- [x] 4.2 将 OnTriggerEnter2D 方法改为 HandleTriggerEnter2D 接口方法
- [x] 4.3 修改获取目标实体的方式（通过 EntityView）

## 5. 预制体 Collider 修复
- [x] 5.1 Enemy1.prefab: BoxCollider (3D) → BoxCollider2D (2D)
- [x] 5.2 Avatar.prefab: BoxCollider (3D) → BoxCollider2D (2D)
- [x] 5.3 EnemyPlane.prefab: BoxCollider (3D) → BoxCollider2D (2D)
- [x] 5.4 BulletCommon.prefab: 添加 Rigidbody2D (Kinematic 模式)

## 6. 代码清理（Review 修复）
- [x] 6.1 清理 EntityView.cs 中的调试日志
- [x] 6.2 清理 BulletEntity.cs 中的调试日志
- [x] 6.3 清理被注释掉的冗余日志代码

## 7. 测试验证
- [x] 7.1 测试玩家子弹击中敌人是否正常触发碰撞
- [x] 7.2 测试敌人子弹击中玩家是否正常触发碰撞
- [x] 7.3 验证实体复用时碰撞正常
