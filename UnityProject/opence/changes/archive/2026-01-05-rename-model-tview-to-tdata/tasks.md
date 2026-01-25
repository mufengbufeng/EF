# 任务清单

## 任务列表

### 1. 修改核心框架文件

#### 1.1 修改 ModelBase.cs
- [x] 将泛型参数 `TView` 改为 `TData`
- [x] 将字段 `_view` 改为 `_data`
- [x] 将属性 `View` 改为 `Data`
- [x] 将方法 `CreateView()` 改为 `CreateData()`
- [x] 更新所有相关 XML 注释

#### 1.2 修改 ModelManager.cs
- [x] 更新 `Register<TModel, TView>` 方法签名为 `Register<TModel, TData>`
- [x] 更新 `Get<TView>` 方法签名为 `Get<TData>`
- [x] 更新 `TryGet<TView>` 方法签名为 `TryGet<TData>`
- [x] 更新方法内部变量名 `viewInstance` 为 `dataInstance`
- [x] 更新 `UnregisterByView<TView>` 为 `UnregisterByData<TData>`
- [x] 更新 `TryGetModelByView` 为 `TryGetModelByData`
- [x] 更新所有相关 XML 注释

#### 1.3 更新 Model/README.md
- [x] 将示例代码中的 `TView` 更新为 `TData`
- [x] 将方法名 `CreateView` 更新为 `CreateData`
- [x] 将属性名 `View` 更新为 `Data`

### 2. 修改游戏逻辑文件

#### 2.1 修改 MainModel.cs
- [x] 将接口 `IMainModelView` 改为 `IMainModelData`
- [x] 将私有类 `MainModelView` 改为 `MainModelData`
- [x] 更新 `CreateView()` 方法为 `CreateData()`
- [x] 更新所有引用和注释

#### 2.2 修改 MainView.cs
- [x] 将 `IMainModelView` 引用改为 `IMainModelData`
- [x] 将变量名 `modelView` 改为 `modelData`

### 3. 额外修改（发现需要同步修改）

#### 3.1 修改 UIView.cs
- [x] 将 `GetModelView` 方法改为 `GetModelData`
- [x] 将 `TryGetModelView` 方法改为 `TryGetModelData`
- [x] 更新相关 XML 注释

#### 3.2 更新 UI/README.md
- [x] 更新所有示例代码中的 API 引用
- [x] 更新 API 参考表

### 4. 验证

#### 4.1 编译验证
- [x] 检查所有代码文件中无旧的 API 引用
- [ ] 在 Unity Editor 中编译 EF.Runtime 程序集
- [ ] 在 Unity Editor 中编译 GameLogic 程序集
- [ ] 确保没有编译错误

#### 4.2 功能验证
- [ ] 运行游戏，验证 MainModel 功能正常
- [ ] 验证 ModelManager 的注册和获取功能
- [ ] 验证数据绑定和 UI 更新

## 修改文件清单

### 核心框架文件 (EF.Runtime)
- [x] `Assets/EF/EFRuntime/Model/ModelBase.cs`
- [x] `Assets/EF/EFRuntime/Model/ModelManager.cs`
- [x] `Assets/EF/EFRuntime/Model/README.md`
- [x] `Assets/EF/EFRuntime/UI/UIView.cs`
- [x] `Assets/EF/EFRuntime/UI/README.md`

### 游戏逻辑文件 (GameLogic)
- [x] `Assets/GameScripts/HotFix/GameLogic/UI/Main/MainModel.cs`
- [x] `Assets/GameScripts/HotFix/GameLogic/UI/Main/MainView.cs`
- [x] `Assets/GameScripts/HotFix/GameLogic/GamePlay/Model/GamePlayModel.cs`

## 依赖关系

```
1.1 ModelBase.cs
  ↓
1.2 ModelManager.cs (依赖 ModelBase.cs)
  ↓
2.1 MainModel.cs (依赖 ModelBase.cs)
  ↓
2.2 MainView.cs (依赖 MainModel.cs)
  ↓
3.1 UIView.cs (依赖 ModelManager.cs)
  ↓
3.2 UI/README.md (文档更新)
  ↓
4. 编译和功能验证
```

## 可并行任务

- 1.1、1.2、1.3 可并行进行（同一文件内按顺序修改）
- 2.1 和 2.2 必须顺序进行
- 任务 1 和任务 2 可并行进行

