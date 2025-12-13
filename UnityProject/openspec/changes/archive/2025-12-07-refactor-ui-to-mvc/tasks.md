# Tasks: UI 框架 MVC 重构（集成 ModelManager）

## 1. 基础类型定义
- [x] 1.1 创建 `UIController` 抽象基类（通过 ModelManager 访问数据）

## 2. 修改现有类型
- [x] 2.1 修改 `UIView` 基类，移除 ViewModel 引用，通过 ModelManager 获取只读视图
- [x] 2.2 修改 `UIWindowDescriptor`，移除 ModelFactory，只保留 View/Controller
- [x] 2.3 修改 `UIRuntimeContext`，添加 ModelManager 引用

## 3. 修改 UIManager
- [x] 3.1 修改 `UIManager` 构造函数，注入 ModelManager
- [x] 3.2 修改 `UIManager.CreateOrReuseInstanceAsync` 创建 View + Controller
- [x] 3.3 修改 `UIWindowInstance` 内部类，移除 Model 存储
- [x] 3.4 修改生命周期调用顺序
- [x] 3.5 修改 `IUIManager` 接口，移除 TryGetModel 方法

## 4. 数据绑定适配
- [x] 4.1 修改 `UIBindingCollection` 支持 `INotifyPropertyChanged` 接口
- [x] 4.2 修改 `UIPropertyBinding` 适配新的绑定方式

## 5. 清理
- [x] 5.1 删除旧的 `UIViewModel.cs` 文件
- [x] 5.2 删除独立的 `IUIModel.cs` 和 `UIModel.cs` 文件
- [x] 5.3 修改 `UIWindowHandle` 移除 Model 引用

## 设计要点
- UI 层 Model 数据通过 ModelManager 管理，不在 UI 框架中创建
- Controller 通过 `Context.ModelManager.GetModel<T>()` 获取完整 Model
- View 通过 `Context.ModelManager.Get<TView>()` 获取只读视图
- 数据绑定支持任何实现 `INotifyPropertyChanged` 的对象
