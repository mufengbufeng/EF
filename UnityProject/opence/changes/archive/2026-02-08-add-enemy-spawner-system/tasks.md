# 实施任务清单

## 1. 创建敌人生成器模块接口和实现

- [x] 创建 `IEnemySpawnerModule.cs` 接口文件
  - [x] 定义 `Configure` 方法（enemyPrefabName, spawnInterval, maxEnemyCount）
  - [x] 定义 `SetSpawnInterval` 方法
  - [x] 定义 `SetMaxEnemyCount` 方法
  - [x] 继承 `IEFManager` 接口
- [x] 创建 `EnemySpawnerModule.cs` 实现类
  - [x] 实现 `IEnemySpawnerModule` 接口
  - [x] 注入 `IEntityManager` 依赖
  - [x] 实现生成间隔计时器逻辑
  - [x] 实现存活敌人列表管理（添加、移除、计数）
  - [x] 实现 `OnUpdate` 中的生成触发逻辑
  - [x] 实现默认生成位置计算（屏幕上方随机）
  - [x] 实现 `OnShutdown` 清理逻辑

## 2. 创建敌人实体类

- [x] 创建 `EnemyBehaviorData.cs` 配置数据类
  - [x] 定义移动速度、方向、停留位置、停留时长、攻击间隔字段
- [x] 创建 `EnemyEntity.cs` 实体类
  - [x] 继承 `EntityBase`
  - [x] 定义行为状态枚举（Moving, Staying）
  - [x] 实现 `OnInit` 初始化逻辑
  - [x] 实现 `OnShow` 接收 userData 并初始化位置和参数
  - [x] 实现 `OnUpdate` 移动逻辑（直线向下）
  - [x] 实现 `OnUpdate` 停留逻辑（到达位置后暂停）
  - [x] 实现 `OnUpdate` 攻击触发逻辑（定时触发）
  - [x] 实现边界检测和自动销毁逻辑
  - [x] 实现 `OnHide` 清理状态
  - [x] 实现 `OnRecycle` 重置数据

## 3. 集成到 GamePlayProcedure

- [x] 在 `GamePlayProcedure.cs` 中添加敌人生成器模块字段
- [x] 在 `OnEnter` 中创建并配置 `EnemySpawnerModule`
- [x] 在 `OnEnter` 中注册敌人生成器到 ModuleSystem (Scope: 1001)
- [x] 在 `OnLeave` 中通过 `ShutdownScope` 清理敌人模块（已有代码，无需修改）

## 4. 创建敌人预制体和资源配置

- [x] 在 Unity 中创建敌人预制体（EnemyPlane.prefab）
  - [x] 添加 SpriteRenderer 组件显示敌人外观
  - [x] 添加 Collider2D 组件用于碰撞检测
  - [x] 添加 `EnemyEntity` 脚本组件
- [x] 将敌人预制体放置到可寻址资源路径
- [x] 在 `IEntityManager` 中添加敌人实体组（如 "Enemy" 组）

## 5. 测试和验证

- [x] 测试敌人生成间隔和数量限制
  - [x] 验证每隔指定秒数生成一个敌人
  - [x] 验证达到最大数量后暂停生成
  - [x] 验证敌人销毁后恢复生成
- [x] 测试敌人移动逻辑
  - [x] 验证敌人从上向下移动
  - [x] 验证敌人到达屏幕底部后自动销毁
- [x] 测试敌人停留逻辑
  - [x] 验证敌人到达停留位置后暂停移动
  - [x] 验证停留时间结束后继续移动
- [x] 测试敌人攻击触发
  - [x] 验证敌人按间隔触发攻击（日志输出或特效）
- [x] 测试流程切换时的清理
  - [x] 验证退出 GamePlayProcedure 时所有敌人被清理
  - [x] 验证敌人模块被正确关闭

## 6. 文档和注释

- [x] 为所有公共接口和类添加 XML 文档注释
- [x] 在代码中添加关键逻辑的中文注释
- [x] 更新 `opence/specs/enemy-spawner/spec.md`（归档后）
- [x] 更新 `opence/specs/enemy-behavior/spec.md`（归档后）

## 依赖关系

- 任务 3 依赖任务 1 和任务 2 完成
- 任务 5 依赖任务 1、2、3、4 完成
- 任务 6 可与其他任务并行进行

## 并行化建议

- 任务 1 和任务 2 可以并行开发（不同开发者）
- 任务 4 可以在任务 2 开发的同时由美术或策划准备
