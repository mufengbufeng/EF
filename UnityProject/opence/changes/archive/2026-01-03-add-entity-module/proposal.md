# Change: Add Entity Module

## Why

当前 EF 框架缺少实体（Entity）管理能力，游戏开发中需要统一的实体生命周期管理系统来处理游戏对象（如角色、道具、特效等）的创建、显示、隐藏、回收和层级关系管理。参考 Game Framework 的 Entity 模块设计，为 EF 框架添加符合项目风格的实体管理功能。

## What Changes

- 新增 `EF.Entity` 命名空间，包含实体管理相关接口和实现
- 新增 `IEntity` 接口 - 定义实体的生命周期和层级关系回调
- 新增 `IEntityGroup` 接口 - 管理同类型实体的对象池
- 新增 `IEntityManager` 接口 - 实体的创建、显示、隐藏和层级关系管理
- 新增 `IEntityHelper` 接口 - 实例化 GameObject 的辅助接口
- 新增 `EntityBase` 抽象类 - 提供 IEntity 的默认实现基类
- 新增 `EntityManager` 实现类 - IEntityManager 的具体实现
- 集成现有的 `IObjectPoolManager` 和 `IResourceManager`

## Impact

- 受影响的规范: 新增 `entity-module` 规范
- 受影响的代码:
  - `Assets/EF/EFRuntime/Entity/` - 新增目录，包含所有实体管理相关代码
  - 现有代码无破坏性变更，纯新增功能

## Design Highlights

- 与 EF 框架现有设计风格保持一致：
  - 管理器继承 `AEFManager` 并实现 `IEFManager`
  - 使用泛型接口定义能力（如 `IEntity<T>`）
  - 依赖注入模式，通过 `SetObjectPoolManager` 和 `SetResourceManager` 注入依赖
- 支持实体组（EntityGroup）概念，同类型实体共享对象池
- 支持实体父子层级关系（Attach/Detach）
- 使用 UniTask 进行异步加载
