# 设计文档：ModelBase 泛型参数重命名

## 命名约定变更

### 之前
```csharp
public abstract class ModelBase<TView> : ModelBase where TView : class
{
    protected abstract TView CreateView();
    protected TView View => (TView)GetViewInstance();
}
```

### 之后
```csharp
public abstract class ModelBase<TData> : ModelBase where TData : class
{
    protected abstract TData CreateData();
    protected TData Data => (TData)GetDataInstance();
}
```

## 语义说明

| 名称 | 用途 |
|------|------|
| `TData` | 模型对外暴露的只读数据接口类型 |
| `CreateData()` | 创建只读数据实例的方法 |
| `Data` | 只读数据实例的访问属性 |

## 文件修改清单

### 1. ModelBase.cs

**修改内容：**
- 泛型参数 `TView` → `TData`
- 方法名 `CreateView()` → `CreateData()`
- 属性名 `View` → `Data`
- 所有相关注释和 XML 文档

**代码变更：**
```csharp
// 第 184 行：泛型类定义
public abstract class ModelBase<TData> : ModelBase where TData : class

// 第 187 行：私有字段
private TData _data;

// 第 207 行：属性
protected TData Data => (TData)GetDataInstance();

// 第 212 行：方法调用
_data = CreateData() ?? throw new InvalidOperationException(...)

// 第 220 行：清理
_data = null;

// 第 240 行：抽象方法
protected abstract TData CreateData();
```

### 2. ModelManager.cs

**修改内容：**
- 所有泛型方法中的 `TView` → `TData`
- 方法内部变量名 `viewInstance` → `dataInstance`
- 相关注释

**代码变更：**
```csharp
// 第 83 行：Register 方法签名
public TData Register<TModel, TData>(TModel model)
    where TModel : ModelBase<TData>
    where TData : class

// 第 88 行：返回语句
return (TData)((IModelInternal)model).DataInstance;

// 第 103 行：Register 无参方法
public TData Register<TModel, TData>()
    where TModel : ModelBase<TData>, new()
    where TData : class

// 第 108 行：返回语句
return (TData)((IModelInternal)model).DataInstance;

// 第 151-154 行：UnregisterByData 方法（原 UnregisterByView）
public bool UnregisterByData<TData>() where TData : class
{
    return UnregisterByData(typeof(TData));
}

// 第 159-177 行：UnregisterByData 方法（原 UnregisterByView）
public bool UnregisterByData(Type dataType)

// 第 201 行：Get 方法
public TData Get<TData>() where TData : class

// 第 259 行：TryGet 方法
public bool TryGet<TData>(out TData data) where TData : class

// 第 298 行：TryGet 方法
public TData TryGet<TData>() where TData : class

// 第 316-343 行：TryGetModelByData 方法（原 TryGetModelByView）
public bool TryGetModelByData<TData>(out ModelBase model) where TData : class
public bool TryGetModelByData(Type dataType, out ModelBase model)
```

### 3. MainModel.cs

**修改内容：**
- 接口 `IMainModelView` → `IMainModelData`
- 私有类 `MainModelView` → `MainModelData`
- 所有相关引用

**代码变更：**
```csharp
// 第 10 行：接口定义
public interface IMainModelData

// 第 27 行：基类声明
public class MainModel : ModelBase<IMainModelData>

// 第 51 行：方法签名
protected override IMainModelData CreateData()

// 第 53 行：返回语句
return new MainModelData(this);

// 第 101 行：私有类定义
private class MainModelData : IMainModelData

// 第 105 行：构造函数参数
public MainModelData(MainModel model)
```

### 4. MainView.cs

**修改内容：**
- `IMainModelView` → `IMainModelData`
- 变量名 `modelView` → `modelData`（可选，建议一并修改）

### 5. README.md

**修改内容：**
- 将示例代码中的 `TView` 更新为 `TData`
- 将方法名 `CreateView` 更新为 `CreateData`
- 将属性名 `View` 更新为 `Data`

## IModelInternal 接口

**保持不变：**
```csharp
Type ViewType { get; }
object ViewInstance { get; }
```

**理由：** `IModelInternal` 是内部接口，其成员命名不需要与公共 API 保持一致。`ViewType` 和 `ViewInstance` 在内部上下文中仍然是合理的命名。

## 兼容性说明

- 这是一个编译时破坏性变更
- 运行时行为完全不变
- 需要重新编译 EF.Runtime.dll 和 GameLogic.dll
- 不影响已构建的 AssetBundles（因为这是纯代码变更）
