# Tasks: 子弹碰撞检测与伤害系统实现

## 1. 数据结构优化
- [x] 1.1 在 BulletData.cs 中添加 BulletOwnerType 枚举(Player, Enemy)
- [x] 1.2 修改 BulletData.OwnerTag 从 string 改为 BulletOwnerType
- [x] 1.3 更新所有调用 BulletData 的代码(PlayerAvatarEntity, EnemyEntity)

## 2. 生命值系统
- [x] 2.1 创建 IHealth 接口(CurrentHealth, MaxHealth, TakeDamage, IsDead)
- [x] 2.2 在 PlayerAvatarEntity 中实现 IHealth 接口
- [x] 2.3 在 EnemyEntity 中实现 IHealth 接口
- [x] 2.4 在实体初始化时配置初始生命值

## 3. 子弹碰撞检测
- [x] 3.1 创建 BulletCollisionHandler.cs MonoBehaviour 脚本
- [x] 3.2 在 BulletCollisionHandler 中实现 OnTriggerEnter2D 方法
- [x] 3.3 实现基于 OwnerType 的友军判断逻辑(Player 子弹不伤害 Player)
- [x] 3.4 实现子弹击中后的回收逻辑

## 4. 子弹模块集成
- [x] 4.1 修改 BulletModule.ActiveBullet 结构体,添加 OwnerType 字段
- [x] 4.2 在 BulletModule.Fire 中为子弹 GameObject 添加 BulletCollisionHandler 组件
- [x] 4.3 传递 BulletOwnerType 和对象池回收回调给 BulletCollisionHandler
- [x] 4.4 在 BulletModule.OnBulletRecycle 中清理 BulletCollisionHandler 组件

## 5. 预制体配置
- [ ] 5.1 在 BulletCommon.prefab 中添加 CircleCollider2D 组件
- [ ] 5.2 设置 CircleCollider2D 为 IsTrigger = true
- [ ] 5.3 配置合适的碰撞半径
- [ ] 5.4 确保子弹在正确的 Layer 上

## 6. 击中反馈
- [x] 6.1 在 EnemyEntity.TakeDamage 中检查生命值,触发死亡时播放死亡动画
- [x] 6.2 在 PlayerAvatarEntity.TakeDamage 中检查生命值,触发死亡时播放爆炸动画
- [x] 6.3 死亡后延迟隐藏实体(等待动画播放)
- [x] 6.4 添加必要的日志输出用于调试

## 7. 测试验证
- [ ] 7.1 测试玩家子弹击中敌人是否正常扣血和销毁
- [ ] 7.2 测试敌人子弹击中玩家是否正常扣血和销毁
- [ ] 7.3 测试友军判断(玩家子弹不击中玩家)
- [ ] 7.4 测试子弹是否正确回收到对象池
- [ ] 7.5 测试死亡动画和实体隐藏是否正常
