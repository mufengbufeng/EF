# Change: Add Feature Binding

## Why

当前的 Entity 模块仅支持 OOP 风格的实体管理（通过继承 EntityBase 实现游戏逻辑）。为了支持更灵活的特性式开发模式，需要添加 Entity 与 Feature 的绑定能力，允许：

1. **动态组合**：通过组合不同类型的 Feature 来构建实体行为，而非深层继承
2. **复用性**：同一 Feature 类型可在多个 Entity 间复用
3. **灵活性**：支持运行时动态添加/移除 Feature

## What Changes

- 新增 `EF.Feature` 命名空间，包含特性管理相关接口和实现
- 新增 `IFeature` 接口 - 定义特性的基础能力
- 新增 `IFeatureContainer` 接口 - 特性容器，管理 Entity 上的所有 Feature
- 扩展 `IEntity` 接口 - 添加 `Features` 属性访问特性容器
- 新增 `FeatureBase` 抽象类 - 提供数据+行为的特性基类
- 新增特性标记 Attribute - 标记特性特性（单例/多例）
- 集成现有的 `IEntityManager` 和 `IEntity`

## Impact

- 受影响的规范: 新增 `feature-binding` 规范
- 受影响的代码:
  - `Assets/EF/EFRuntime/Feature/` - 新增目录，包含所有特性管理相关代码
  - `Assets/EF/EFRuntime/Entity/IEntity.cs` - 扩展 `Features` 属性
  - `Assets/EF/EFRuntime/Entity/EntityBase.cs` - 实现特性容器
- 现有代码无破坏性变更，纯新增功能

## Design Highlights

- **特性风格**：采用数据+行为的特性式设计，Feature 可包含自己的 Update 等方法
- **绑定关系**：
  - 默认 1:1 绑定（同类型特性只能有一个）
  - 支持通过 `[AllowMultiple]` 标记实现 1:N 绑定
- **生命周期**：Feature 支持 `OnInit/OnEnable/OnDisable/OnDestroy` 回调
- **无 System 调度**：特性更新由游戏层自行控制，不实现统一调度器
- **与 EF 框架一致**：继承 `AEFManager` 的管理模式，使用 UniTask 进行异步操作
