# model-framework Specification

## Purpose
TBD - created by archiving change rename-model-tview-to-tdata. Update Purpose after archive.
## Requirements
### Requirement: 泛型模型基类使用 TData 作为只读数据接口参数

模型框架的泛型基类 SHALL 使用 `TData` 作为只读数据接口的泛型参数名，准确反映其语义——模型通过只读数据接口向外部暴露数据。

#### Scenario: 定义带只读数据接口的模型

**Given** 开发者需要创建一个模型类
**When** 继承 `ModelBase<TData>` 泛型基类
**Then** 泛型参数名为 `TData`，表示只读数据接口类型

**示例：**
```csharp
public interface IGamePlayModelData
{
    GameSceneManager GameSceneManager { get; }
}

public class GamePlayModel : ModelBase<IGamePlayModelData>
{
    protected override IGamePlayModelData CreateData()
    {
        return new GamePlayModelData(this);
    }
}
```

#### Scenario: 通过 ModelManager 获取只读数据

**Given** 模型已注册到 ModelManager
**When** 调用 `Get<TData>()` 或 `TryGet<TData>()` 方法
**Then** 返回模型的只读数据接口实例

**示例：**
```csharp
// 获取只读数据
IGamePlayModelData data = ModelManager.Get<IGamePlayModelData>();

// 或使用 TryGet
if (ModelManager.TryGet<IGamePlayModelData>(out var data))
{
    // 使用 data
}
```

### Requirement: 模型通过 CreateData 方法创建只读数据实例

模型 SHALL 通过实现 `CreateData()` 方法来创建只读数据接口的实例，该方法在模型初始化时被调用。

#### Scenario: 实现自定义只读数据类

**Given** 开发者创建继承 `ModelBase<TData>` 的模型类
**When** 实现 `CreateData()` 方法
**Then** 返回一个实现 `TData` 接口的数据实例

**示例：**
```csharp
public class MainModel : ModelBase<IMainModelData>
{
    protected override IMainModelData CreateData()
    {
        return new MainModelData(this);
    }

    private class MainModelData : IMainModelData
    {
        private readonly MainModel _model;

        public MainModelData(MainModel model)
        {
            _model = model ?? throw new ArgumentNullException(nameof(model));
        }

        public bool IsGameStarted => _model.IsGameStarted;
    }
}
```

### Requirement: 模型内部通过 Data 属性访问只读数据实例

模型内部 SHALL 能够通过 `Data` 属性访问只读数据实例。

#### Scenario: 在模型内部访问只读数据

**Given** 模型已完成初始化
**When** 模型内部代码访问 `Data` 属性
**Then** 返回 `CreateData()` 创建的只读数据实例

