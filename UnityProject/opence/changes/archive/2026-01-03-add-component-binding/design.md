# Feature Binding Design

## Context

现有 Entity 模块实现了 OOP 风格的实体管理，通过继承 `EntityBase` 来实现游戏逻辑。这种方式在简单场景下工作良好，但随着游戏复杂度增加，会出现以下问题：

1. **继承层次过深**：为了复用代码，不得不创建多层继承
2. **代码重复**：不同实体类型的相似功能难以复用
3. **扩展困难**：添加新功能需要修改基类或创建新的子类

特性式开发模式通过组合而非继承来解决这些问题。本文档设计 Entity 与 Feature 的绑定机制，支持：

- 动态添加/移除特性
- 特性生命周期管理
- 单例/多例特性支持
- 特性间依赖管理

## Goals / Non-Goals

### Goals

- 提供简洁的 Entity-Feature 绑定 API
- 支持特性生命周期回调（Init/Enable/Disable/Destroy）
- 支持默认单例模式，可选择允许多例
- 特性可包含数据和行为（Update 方法等）
- 与现有 Entity 模块无缝集成

### Non-Goals

- 不实现 ECS 风格的数据导向设计
- 不实现 System 调度器（由游戏层自行控制特性更新）
- 不实现特性序列化（由 Save 模块负责）
- 不实现跨网络同步（由游戏层自行实现）

## Decisions

### 1. 特性接口层次

```
IFeature                    - 特性接口
  └── FeatureBase           - 特性抽象基类（可选继承）

IFeatureContainer           - 特性容器接口
  └── FeatureContainer      - 特性容器实现

IFeatureManager             - 特性管理器接口（可选）
  └── FeatureManager        - 特性管理器实现（可选）
```

### 2. 特性标记

使用 Attribute 标记特性：

```csharp
// 默认：每个实体只能有一个该类型特性
public class MyFeature : FeatureBase { }

// 允许多个：一个实体可以有多个该类型特性
[AllowMultiple]
public class MultiFeature : FeatureBase { }

// 依赖：添加该特性前必须先有指定特性
[RequireFeature(typeof(AnotherFeature))]
public class DependentFeature : FeatureBase { }
```

### 3. 与 Entity 的集成

在 `IEntity` 接口添加 `Features` 属性：

```csharp
public interface IEntity
{
    // ... 现有属性
    IFeatureContainer Features { get; }
}
```

`EntityBase` 实现特性容器：

```csharp
public abstract class EntityBase : IEntity
{
    private readonly IFeatureContainer _features;

    public EntityBase()
    {
        _features = new FeatureContainer(this);
    }

    public IFeatureContainer Features => _features;
}
```

### 4. 特性生命周期

特性的生命周期与关联的 Entity 绑定：

| 事件 | 触发时机 |
|------|----------|
| `OnInit` | 特性首次添加到实体时 |
| `OnEnable` | 实体显示时，或特性被启用 |
| `OnDisable` | 实体隐藏时，或特性被禁用 |
| `OnDestroy` | 实体回收或特性被移除时 |
| `OnUpdate` | 每帧更新（仅在启用时） |

### 5. 特性容器 API

```csharp
public interface IFeatureContainer
{
    int FeatureCount { get; }
    IEntity Owner { get; }

    // 添加特性
    T AddFeature<T>() where T : IFeature, new();
    IFeature AddFeature(Type featureType);

    // 获取特性
    T GetFeature<T>() where T : IFeature;
    IFeature GetFeature(Type featureType);
    T[] GetFeatures<T>() where T : IFeature;

    // 判断是否有特性
    bool HasFeature<T>() where T : IFeature;
    bool HasFeature(Type featureType);

    // 移除特性
    bool RemoveFeature<T>() where T : IFeature;
    bool RemoveFeature(IFeature feature);

    // 启用/禁用特性
    void SetFeatureEnabled<T>(bool enabled) where T : IFeature;

    // 获取所有特性
    IReadOnlyList<IFeature> GetAllFeatures();
}
```

### 6. 特性更新策略

由于不实现统一的 System 调度器，特性更新采用以下策略：

1. **Entity 驱动**：`EntityBase.OnUpdate` 中自动更新所有启用的特性
2. **手动控制**：游戏层可直接遍历 `Features.GetAllFeatures()` 自行更新

```csharp
public abstract class EntityBase : IEntity
{
    public virtual void OnUpdate(float elapseSeconds, float realElapseSeconds)
    {
        _features.Update(elapseSeconds, realElapseSeconds);
    }
}
```

## Architecture

```
┌─────────────────────────────────────────────────────────┐
│                      Entity                             │
│  - Id, Handle, EntityGroup                             │
│  - Features: IFeatureContainer                          │
└────────────────────────┬────────────────────────────────┘
                         │
                         ▼
┌─────────────────────────────────────────────────────────┐
│                  FeatureContainer                       │
│  - AddFeature<T>()                                      │
│  - GetFeature<T>()                                      │
│  - RemoveFeature<T>()                                   │
│  - SetFeatureEnabled<T>()                               │
└────────────────────────┬────────────────────────────────┘
                         │
        ┌────────────────┼────────────────┐
        ▼                ▼                ▼
┌─────────────┐  ┌─────────────┐  ┌─────────────┐
│  Position   │  │   Render    │  │   Physics   │
│  Feature    │  │  Feature    │  │  Feature    │
└─────────────┘  └─────────────┘  └─────────────┘
```

## Class Structure

### IFeature

```csharp
public interface IFeature
{
    bool Enabled { get; set; }
    IEntity Entity { get; }
    bool IsInitialized { get; }

    void OnInit();
    void OnEnable();
    void OnDisable();
    void OnDestroy();
    void OnUpdate(float elapseSeconds, float realElapseSeconds);
}
```

### FeatureBase

```csharp
public abstract class FeatureBase : IFeature
{
    public IEntity Entity { get; private set; }
    public bool Enabled { get; set; } = true;
    public bool IsInitialized { get; private set; }

    public virtual void OnInit() { }
    public virtual void OnEnable() { }
    public virtual void OnDisable() { }
    public virtual void OnDestroy() { }
    public virtual void OnUpdate(float elapseSeconds, float realElapseSeconds) { }

    internal void SetEntity(IEntity entity) => Entity = entity;
}
```

### FeatureAttribute

```csharp
[AttributeUsage(AttributeTargets.Class)]
public class AllowMultipleAttribute : Attribute
{
    public bool AllowMultiple { get; }

    public AllowMultipleAttribute(bool allowMultiple = true)
    {
        AllowMultiple = allowMultiple;
    }
}

[AttributeUsage(AttributeTargets.Class)]
public class RequireFeatureAttribute : Attribute
{
    public Type RequiredType { get; }

    public RequireFeatureAttribute(Type requiredType)
    {
        RequiredType = requiredType;
    }
}
```

## Risks / Trade-offs

| Risk | Mitigation |
|------|-----------|
| 特性过多导致更新开销 | 提供禁用功能，只更新启用的特性 |
| 循环依赖导致死锁 | RequireFeature 只做运行时检查，不强制约束 |
| 特性更新顺序不可控 | 提供 FeatureOrder 属性允许排序 |

## Migration Plan

- 这是一个纯新增功能，现有 Entity 代码无需修改
- 新代码可以选择使用特性模式或继承模式
- 两种模式可以混用（Entity 继承 EntityBase，同时添加 Feature）

## Open Questions

1. 是否需要特性池？
   - **决策**：初始版本不包含，按需添加
2. 是否需要特性热更新？
   - **决策**：支持通过 HybridCLR 热更新特性类型
3. 是否需要特性事件？
   - **决策**：初始版本不包含事件，按需添加
