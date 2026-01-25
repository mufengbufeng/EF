# 提案：将 ModelBase 泛型参数 TView 重命名为 TData

## 背景

当前 `ModelBase<TView>` 中的泛型参数 `TView` 命名为 "View"，但从实际使用模式来看，这个泛型参数表示的是模型的"只读数据接口"，而不是 UI 层的"视图"。

现有的命名已经体现了这种不一致：
- `MainModel` 使用 `IMainModelView` 接口
- `GamePlayModel` 使用 `IGamePlayModelData` 接口

将 `TView` 重命名为 `TData` 可以更准确地反映其语义：模型通过只读数据接口向外部暴露数据，外部无法直接修改模型内部状态。

## 目标

1. 将 `ModelBase<TView>` 的泛型参数名 `TView` 改为 `TData`
2. 更新 `ModelManager` 中所有使用 `TView` 的泛型方法
3. 将现有接口 `IMainModelView` 重命名为 `IMainModelData` 以保持一致性
4. 更新相关文档和注释

## 影响范围

### 核心框架文件 (EF.Runtime)
- `Assets/EF/EFRuntime/Model/ModelBase.cs` - 泛型类定义
- `Assets/EF/EFRuntime/Model/ModelManager.cs` - 泛型方法签名
- `Assets/EF/EFRuntime/Model/README.md` - 文档更新

### 游戏逻辑文件 (GameLogic)
- `Assets/GameScripts/HotFix/GameLogic/UI/Main/MainModel.cs` - 接口和实现
- `Assets/GameScripts/HotFix/GameLogic/UI/Main/MainView.cs` - 接口引用

## 风险评估

- **破坏性变更**：这是 API 级别的命名变更，不影响运行时行为
- **影响范围**：仅限于编译时，所有使用 `ModelBase<>` 的代码需要更新
- **兼容性**：需要重新编译 EF.Runtime.dll 和 GameLogic.dll

## 替代方案

1. **保持现状**：不进行重命名，但命名会继续存在语义不一致
2. **部分重命名**：只改泛型参数名，不改现有接口名（可能导致新代码不一致）

## 建议

采用完整重命名方案，确保命名一致性。
