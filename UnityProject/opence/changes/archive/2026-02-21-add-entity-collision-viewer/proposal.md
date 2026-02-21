# Change: 添加 EntityView 碰撞桥接机制

## Why
当前 EntityBase 是纯 C# 类，不继承 MonoBehaviour，导致 Unity 物理事件（如 OnTriggerEnter2D）无法触发。BulletEntity 中的 OnTriggerEnter2D 方法不会被 Unity 调用，子弹碰撞检测完全失效。需要一种机制在保留 Entity 架构的前提下，让 Entity 能够响应 Unity 物理事件。

## What Changes
- 创建 `EntityView` MonoBehaviour 组件，作为 Unity 物理事件与 Entity 之间的桥梁
- 创建 `ICollisionHandler` 接口，定义碰撞事件处理方法
- 修改 `BulletEntity` 实现 `ICollisionHandler` 接口
- 修改 `EntityManager` 在实例化 Entity 时自动注入 EntityView
- 为子弹预制体添加 EntityView 组件

## Impact
- Affected specs: 新增 `entity-collision` capability，修改 `entity-module` capability
- Affected code:
  - `Assets/EF/EFRuntime/Entity/EntityView.cs` - 新增
  - `Assets/EF/EFRuntime/Entity/ICollisionHandler.cs` - 新增
  - `Assets/EF/EFRuntime/Entity/EntityBase.cs` - 可选实现接口
  - `Assets/EF/EFRuntime/Entity/EntityManager.cs` - 实例化时注入 View
  - `Assets/GameScripts/HotFix/GameLogic/GamePlay/Bullet/BulletEntity.cs` - 移除无效的 OnTriggerEnter2D
  - `Assets/AssetRaw/Prefabs/Bullet/BulletCommon.prefab` - 添加 EntityView 组件
