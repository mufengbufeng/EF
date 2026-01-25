# ModelManager API 迁移指南

## 变更概述

`ModelManager` 的 `TryGetModel` 方法行为已更改，现在支持自动创建和注册模型。这是一个破坏性变更。

## API 变更详情

### GetModel<TModel>() - 无变更

```csharp
// 获取已注册的模型，未注册时抛出异常
var model = modelManager.GetModel<UserModel>();
```

**行为**：与之前完全相同，无需修改代码。

---

### TryGetModel<TModel>() - 重大变更

#### 修改前
```csharp
// 旧 API：返回 bool，使用 out 参数
if (modelManager.TryGetModel<UserModel>(out var model))
{
    model.DoSomething();
}
else
{
    // 处理模型不存在的情况
}

// 或者：返回可空类型
var model = modelManager.TryGetModel<UserModel>();
if (model != null)
{
    model.DoSomething();
}
```

#### 修改后
```csharp
// 新 API：自动创建并注册，保证返回非空
var model = modelManager.TryGetModel<UserModel>();
model.DoSomething(); // model 保证非空

// 注意：TModel 必须有无参构造函数
public TModel TryGetModel<TModel>() where TModel : ModelBase, new()
```

**关键变更**：
1. ✅ 添加了 `new()` 约束
2. ✅ 如果模型未注册，自动创建并注册
3. ✅ 保证返回非空实例
4. ❌ 移除了 `out` 参数重载
5. ❌ 不再返回可空类型

---

### TryGetModel(Type) - 行为不变

```csharp
// 仅查找，不自动创建
ModelBase model = modelManager.TryGetModel(typeof(UserModel));
if (model != null)
{
    model.DoSomething();
}
```

**行为**：与之前相同，仅执行查找，不自动注册。

---

## 迁移模式

### 模式 1：从 out 参数迁移到直接返回

#### 修改前
```csharp
if (modelManager.TryGetModel<UserModel>(out var model))
{
    model.UpdateData();
}
else
{
    Log.Warning("UserModel 未注册");
}
```

#### 修改后
```csharp
// 方案 A：如果期望自动创建
var model = modelManager.TryGetModel<UserModel>();
model.UpdateData();

// 方案 B：如果需要检查是否存在而不创建
if (modelManager.HasModel<UserModel>())
{
    var model = modelManager.GetModel<UserModel>();
    model.UpdateData();
}
else
{
    Log.Warning("UserModel 未注册");
}
```

---

### 模式 2：从可空返回迁移

#### 修改前
```csharp
var model = modelManager.TryGetModel<UserModel>();
if (model != null)
{
    model.ProcessRequest();
}
```

#### 修改后
```csharp
// 方案 A：如果期望自动创建
var model = modelManager.TryGetModel<UserModel>();
model.ProcessRequest(); // 保证非空

// 方案 B：如果需要检查存在性
if (modelManager.HasModel<UserModel>())
{
    var model = modelManager.GetModel<UserModel>();
    model.ProcessRequest();
}
```

---

### 模式 3：UIController 中的用法

#### 修改前
```csharp
protected void OnEnter()
{
    if (TryGetModel<UserModel>(out var model))
    {
        model.Initialize();
    }
}
```

#### 修改后
```csharp
protected void OnEnter()
{
    // TryGetModel 现在自动创建，保证非空
    var model = TryGetModel<UserModel>();
    model.Initialize();
}
```

---

## 使用指南

### 何时使用 GetModel

使用 `GetModel` 当你：
- ✅ 确定模型已经注册
- ✅ 希望在模型未注册时得到明确的异常
- ✅ 模型是必需的依赖

```csharp
// 示例：获取核心模型
var coreModel = modelManager.GetModel<CoreModel>();
```

---

### 何时使用 TryGetModel

使用 `TryGetModel` 当你：
- ✅ 希望自动创建和注册模型
- ✅ 使用单例模式管理模型
- ✅ 模型具有无参构造函数

```csharp
// 示例：获取或创建单例模型
var settingsModel = modelManager.TryGetModel<SettingsModel>();
```

---

### 何时使用 HasModel + GetModel

使用 `HasModel` + `GetModel` 当你：
- ✅ 需要检查模型是否存在但不创建
- ✅ 模型可能存在也可能不存在，需要区分两种情况

```csharp
// 示例：条件性地使用模型
if (modelManager.HasModel<OptionalModel>())
{
    var model = modelManager.GetModel<OptionalModel>();
    model.DoOptionalWork();
}
```

---

## 约束与限制

### new() 约束

`TryGetModel<TModel>()` 要求模型类型必须有无参构造函数：

```csharp
// ✅ 可以使用 TryGetModel
public class SimpleModel : ModelBase
{
    public SimpleModel() { } // 无参构造函数
}

// ❌ 不能使用 TryGetModel
public class ComplexModel : ModelBase
{
    public ComplexModel(string config) { } // 需要参数
}

// 对于需要参数的模型，必须显式注册
var complexModel = new ComplexModel("config");
modelManager.Register(complexModel);
```

---

### Type 参数版本的差异

泛型版本和 Type 参数版本的行为不同：

```csharp
// 泛型版本：自动创建
var model1 = modelManager.TryGetModel<UserModel>(); // 保证非空

// Type 参数版本：仅查找
var model2 = modelManager.TryGetModel(typeof(UserModel)); // 可能为 null
```

---

## 常见问题

### Q: 为什么移除 out 参数版本？

A: 新的 `TryGetModel` 语义是"获取或创建"，保证返回非空实例。`out` 参数暗示可能失败，与新语义不一致。

### Q: 如何迁移依赖 null 检查的代码？

A: 使用 `HasModel<TModel>()` 检查存在性，或者接受自动创建行为。

### Q: 多次调用 TryGetModel 会创建多个实例吗？

A: 不会。`TryGetModel` 会先检查是否已注册，只有在未注册时才创建新实例。

### Q: TryGetModel 是线程安全的吗？

A: 是的。"检查-创建-注册"过程是原子操作，不会创建重复实例。

---

## 检查清单

在完成迁移前，确保：

- [ ] 所有使用 `TryGetModel(out var model)` 的地方已更新
- [ ] 所有依赖 `TryGetModel` 返回 null 的逻辑已调整
- [ ] 确认自动创建行为符合业务逻辑
- [ ] 需要参数的模型已改用显式 `Register`
- [ ] 代码编译无错误
- [ ] 功能测试通过

---

## 获取帮助

如有疑问，请参考：
- [ModelManager.cs](../Assets/EF/EFRuntime/Model/ModelManager.cs) - 源代码
- [提案文档](../openspec/changes/refactor-modelmanager-getorregister-logic/proposal.md) - 变更详情
