# 设计文档：ModelManager 获取或注册逻辑重构

## 架构决策

### 方法职责划分

#### GetModel<TModel>()
- **职责**：获取已注册的模型实例
- **前置条件**：模型必须已经通过 `Register` 注册
- **成功路径**：返回已注册的模型实例
- **失败路径**：抛出 `KeyNotFoundException`
- **线程安全**：使用 `_syncRoot` 锁保护读取操作

#### TryGetModel<TModel>()
- **职责**：获取模型实例，如果不存在则自动注册
- **前置条件**：模型类型必须有无参构造函数
- **成功路径**：
  1. 如果模型已注册，直接返回
  2. 如果模型未注册，创建新实例并注册，然后返回
- **失败路径**：
  - 如果模型无法创建（缺少无参构造函数），编译时错误
  - 如果注册过程失败（如视图类型冲突），抛出 `InvalidOperationException`
- **线程安全**：整个"检查-创建-注册"过程必须是原子操作

## 实现策略

### 泛型约束

```csharp
// GetModel 不需要 new() 约束
public TModel GetModel<TModel>() where TModel : ModelBase

// TryGetModel 需要 new() 约束以支持自动创建
public TModel TryGetModel<TModel>() where TModel : ModelBase, new()
```

### 线程安全实现

```csharp
public TModel TryGetModel<TModel>() where TModel : ModelBase, new()
{
    lock (_syncRoot)
    {
        // 先尝试获取现有实例
        if (_models.TryGetValue(typeof(TModel), out IModelInternal existing))
        {
            return (TModel)existing;
        }
        
        // 不存在则在锁内创建并注册
        // 注意：Register 方法内部也有锁，但这里外层锁确保原子性
        TModel model = new TModel();
        return Register(model);
    }
}
```

**注意事项**：
- `Register` 方法内部已经有 `lock (_syncRoot)`
- 外层再加锁会导致可重入锁
- 需要重构 `Register` 以支持内部调用版本，或者将注册逻辑提取为不加锁的核心方法

### 重构 Register 方法

为了避免嵌套锁问题，我们需要：

1. 提取核心注册逻辑到私有方法 `RegisterInternal`（不加锁）
2. `Register` 公共方法调用 `RegisterInternal` 并加锁
3. `TryGetModel` 在持有锁的情况下调用 `RegisterInternal`

```csharp
// 私有：核心注册逻辑，调用者负责加锁
private TModel RegisterInternal<TModel>(TModel model) where TModel : ModelBase
{
    Type concreteType = model.GetType();
    if (_models.ContainsKey(concreteType))
    {
        throw new InvalidOperationException($"模型 {concreteType.FullName} 已经注册，不能重复注册。");
    }

    IModelInternal internalModel = model;
    Type viewType = internalModel.ViewType ?? throw new InvalidOperationException(...);
    if (_viewToModel.ContainsKey(viewType))
    {
        throw new InvalidOperationException(...);
    }

    internalModel.Initialize(this);
    object viewInstance = internalModel.ViewInstance ?? throw new InvalidOperationException(...);

    _models.Add(concreteType, internalModel);
    _viewToModel.Add(viewType, concreteType);
    _updateOrder.Add(internalModel);
    
    return model;
}

// 公共：加锁版本
public TModel Register<TModel>(TModel model) where TModel : ModelBase
{
    if (model == null)
    {
        throw new ArgumentNullException(nameof(model));
    }

    lock (_syncRoot)
    {
        return RegisterInternal(model);
    }
}

// TryGetModel：在锁内完成检查和注册
public TModel TryGetModel<TModel>() where TModel : ModelBase, new()
{
    lock (_syncRoot)
    {
        if (_models.TryGetValue(typeof(TModel), out IModelInternal existing))
        {
            return (TModel)existing;
        }
        
        return RegisterInternal(new TModel());
    }
}
```

## 类型重载处理

### 移除的方法

```csharp
// 移除：返回 bool 的泛型版本
public bool TryGetModel<TModel>(out TModel model) where TModel : ModelBase

// 移除：返回 bool 的 Type 版本  
public bool TryGetModel(Type modelType, out ModelBase model)

// 不再返回 null
// 修改前：public TModel TryGetModel<TModel>() where TModel : ModelBase
// 修改后：public TModel TryGetModel<TModel>() where TModel : ModelBase, new()
```

### 保留的方法

```csharp
// 保持不变：GetModel
public TModel GetModel<TModel>() where TModel : ModelBase

// 修改行为：TryGetModel（添加 new() 约束，保证返回非空）
public TModel TryGetModel<TModel>() where TModel : ModelBase, new()

// 考虑：是否需要保留 Type 参数版本？
public ModelBase TryGetModel(Type modelType)
```

**决策**：保留 `TryGetModel(Type)` 版本，但不支持自动注册（因为无法在运行时创建实例）。该版本仅执行查找，不存在时返回 null。

明确两个版本的语义：
- `TryGetModel<TModel>()` - 泛型版本，支持自动注册
- `TryGetModel(Type)` - Type 参数版本，仅查找不创建，可返回 null

## 受影响组件的更新策略

### UIController

**当前代码**：
```csharp
protected bool TryGetModel<TModel>(out TModel model) where TModel : ModelBase
{
    return Context.ModelManager.TryGetModel(out model);
}
```

**更新后**：
```csharp
// 方案 1：改为返回模型，支持自动注册
protected TModel TryGetModel<TModel>() where TModel : ModelBase, new()
{
    return Context.ModelManager.TryGetModel<TModel>();
}

// 方案 2：保留 out 语义，但不自动注册
protected bool TryGetModel<TModel>(out TModel model) where TModel : ModelBase
{
    model = Context.ModelManager.TryGetModel(typeof(TModel)) as TModel;
    return model != null;
}
```

**推荐**：方案 1。UIController 应该遵循与 ModelManager 相同的语义。

### MainController

**当前代码**：
```csharp
var gamePlayerModel = GameLogicEntry.Model.TryGetModel<GamePlayModel>();
```

**兼容性**：代码无需修改，但行为会改变：
- 修改前：如果模型不存在，返回 null
- 修改后：如果模型不存在，自动创建并注册

需要审查此处是否期望自动注册行为。

## 测试策略

### 单元测试覆盖

1. **GetModel 测试**：
   - 获取已注册模型成功
   - 获取未注册模型抛出异常

2. **TryGetModel 测试**：
   - 获取已注册模型成功
   - 自动注册未注册模型
   - 多次调用返回同一实例
   - 自动注册的模型可以被正常使用（更新、注销等）

3. **线程安全测试**：
   - 并发调用 TryGetModel 同一类型
   - 并发调用 TryGetModel 和 GetModel
   - 并发调用 TryGetModel 和 Register

4. **边界情况**：
   - 模型初始化失败时的处理
   - 视图类型冲突时的处理

### 集成测试

- UI 流程中使用 TryGetModel 的场景
- 确保自动注册的模型在整个生命周期中正常工作

## 迁移指南

### 代码迁移模式

#### 模式 1：从 out 参数迁移到返回值

```csharp
// 修改前
if (manager.TryGetModel<MyModel>(out var model))
{
    model.DoSomething();
}
else
{
    // 处理不存在的情况
}

// 修改后（自动注册）
var model = manager.TryGetModel<MyModel>();
model.DoSomething();
```

#### 模式 2：从可空返回迁移

```csharp
// 修改前
var model = manager.TryGetModel<MyModel>();
if (model != null)
{
    model.DoSomething();
}

// 修改后
var model = manager.TryGetModel<MyModel>();
model.DoSomething(); // 保证非空
```

#### 模式 3：需要检查是否存在而不创建

```csharp
// 如果需要检查模型是否存在而不自动创建
if (manager.HasModel<MyModel>())
{
    var model = manager.GetModel<MyModel>();
    model.DoSomething();
}

// 或者使用 Type 参数版本（仍返回可空）
var model = manager.TryGetModel(typeof(MyModel)) as MyModel;
if (model != null)
{
    model.DoSomething();
}
```

## 文档更新

需要更新以下文档：

1. API 参考文档
2. 迁移指南
3. 最佳实践指南
4. 代码示例

重点说明：
- GetModel vs TryGetModel 的使用场景
- TryGetModel 的自动注册行为
- 泛型版本与 Type 参数版本的差异
