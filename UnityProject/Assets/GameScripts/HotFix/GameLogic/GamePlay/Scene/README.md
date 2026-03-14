# GamePlay.Scene 模块说明

## 模块目标

- 提供游戏逻辑层的场景管理功能，基于状态机实现复杂的场景流程控制。
- 封装框架层的场景加载能力，提供游戏特定的场景管理逻辑。
- 支持游戏场景的生命周期管理、状态跟踪和错误恢复。

## 目录结构

- `GameSceneManager.cs`：游戏场景管理器核心实现，基于状态机的场景流程管理。
- `GameSceneStatus.cs`：游戏场景状态枚举定义。
- `GameSceneState.cs`：游戏场景状态基类，封装状态机通用功能。
- `GameSceneIdleState.cs`：空闲状态，等待场景操作请求。
- `GameSceneLoadingState.cs`：加载状态，处理游戏场景加载逻辑。
- `GameSceneLoadedState.cs`：已加载状态，游戏场景运行中状态。
- `GameSceneUnloadingState.cs`：卸载状态，处理游戏场景卸载逻辑。
- `GameSceneErrorState.cs`：错误状态，处理场景操作异常和恢复。

## 核心特性

- **基于状态机**：利用 `EF.Fsm` 框架实现清晰的游戏场景状态管理。
- **框架层封装**：基于 `EF.Scene.SceneManager` 提供游戏逻辑层的场景管理。
- **异步操作**：支持异步游戏场景加载和卸载，提供进度回调。
- **事件驱动**：提供丰富的游戏场景事件接口，便于游戏逻辑响应。
- **错误恢复**：完善的错误处理和状态恢复机制，支持重试和重置。
- **游戏逻辑集成**：专为游戏逻辑设计的场景管理功能。

## 状态转换图

```
[空闲] --加载请求--> [加载中] --成功--> [已加载]
  ↑                      |           |
  |                   失败↓       卸载请求
  |                   [错误] <--------↓
  ↑                      |        [卸载中]
  |                   重置↓           |
  +---------- 卸载完成 ----------------+
```

## 架构层级

```
GamePlay.Scene.GameSceneManager (游戏逻辑层)
    ↓ 使用
EF.Scene.SceneManager (框架层)
    ↓ 使用
EF.Resource.ResourceManager (资源层)
```

## 快速上手

### 1. 初始化游戏场景管理器

游戏场景管理器会在 `GameLogicEntry` 中自动创建和初始化：

```csharp
// 已集成到 GameLogicEntry，无需手动创建
var gameSceneManager = GameLogicEntry.GameScene;
```

### 2. 加载游戏场景

```csharp
// 异步加载游戏场景
bool success = await GameLogicEntry.GameScene.LoadGameSceneAsync("Game");
if (success)
{
    Debug.Log("游戏场景加载成功");
}
```

### 3. 卸载游戏场景

```csharp
// 异步卸载当前游戏场景
bool success = await GameLogicEntry.GameScene.UnloadGameSceneAsync();
if (success)
{
    Debug.Log("游戏场景卸载成功");
}
```

### 4. 监听游戏场景事件

```csharp
// 订阅游戏场景事件
GameLogicEntry.GameScene.OnGameSceneLoaded += OnGameSceneLoaded;
GameLogicEntry.GameScene.OnGameSceneLoadingProgress += OnGameSceneLoadingProgress;
GameLogicEntry.GameScene.OnGameSceneError += OnGameSceneError;

private void OnGameSceneLoaded(SceneInfo sceneInfo)
{
    Debug.Log($"游戏场景已加载：{sceneInfo.Name}");
    // 在这里添加游戏特定的场景初始化逻辑
}

private void OnGameSceneLoadingProgress(float progress)
{
    Debug.Log($"游戏场景加载进度：{progress * 100:F1}%");
    // 更新游戏 UI 的加载进度条
}

private void OnGameSceneError(Exception exception)
{
    Debug.LogError($"游戏场景错误：{exception.Message}");
    // 处理游戏场景错误，显示错误界面等
}
```

### 5. 查询游戏场景状态

```csharp
// 获取当前游戏场景状态
GameSceneStatus status = GameLogicEntry.GameScene.GetCurrentStatus();

// 获取当前场景信息
SceneInfo? currentScene = GameLogicEntry.GameScene.GetCurrentScene();
if (currentScene.HasValue)
{
    Debug.Log($"当前游戏场景：{currentScene.Value.Name}");
}
```

### 6. 错误处理和恢复

```csharp
// 在错误状态下，可以选择重试或重置
if (GameLogicEntry.GameScene.GetCurrentStatus() == GameSceneStatus.Error)
{
    // 重试加载
    // 注意：这需要扩展 GameSceneErrorState 的公开方法
    
    // 或者重置到空闲状态
    // 注意：这需要扩展 GameSceneErrorState 的公开方法
}
```

## API 参考

### GameSceneManager 类

| 方法 | 描述 |
|------|------|
| `LoadGameSceneAsync(sceneName, ...)` | 异步加载游戏场景 |
| `UnloadGameSceneAsync()` | 异步卸载当前游戏场景 |
| `GetCurrentStatus()` | 获取当前游戏场景状态 |
| `GetCurrentScene()` | 获取当前场景信息 |

### 游戏场景事件

| 事件 | 描述 |
|------|------|
| `OnGameSceneLoaded` | 游戏场景加载完成事件 |
| `OnGameSceneUnloaded` | 游戏场景卸载完成事件 |
| `OnGameSceneLoadingProgress` | 游戏场景加载进度事件 |
| `OnGameSceneError` | 游戏场景操作错误事件 |

### GameSceneStatus 枚举

| 值 | 描述 |
|---|------|
| `Idle` | 空闲状态 |
| `Loading` | 加载中状态 |
| `Loaded` | 已加载状态 |
| `Unloading` | 卸载中状态 |
| `Error` | 错误状态 |

## 设计原则

1. **分层设计**：游戏逻辑层不直接操作框架层的场景管理，通过 GameSceneManager 进行封装。

2. **状态管理**：使用状态机模式管理复杂的游戏场景状态转换，确保状态的一致性和可预测性。

3. **事件驱动**：通过事件机制实现松耦合的场景状态通知，便于游戏逻辑响应。

4. **错误恢复**：提供完善的错误处理机制，支持自动重试和手动重置。

## 扩展指南

### 添加自定义游戏场景状态

1. 继承 `GameSceneState` 基类
2. 重写必要的生命周期方法
3. 在 `GameSceneManager` 构造函数中添加到状态机

### 添加游戏特定的场景数据

1. 扩展状态机的共享数据字典
2. 在相应的状态中处理特定数据
3. 通过事件向外部通知数据变化

### 集成游戏系统

1. 在 `GameSceneLoadedState` 中初始化游戏系统
2. 在 `GameSceneUnloadingState` 中清理游戏资源
3. 通过事件机制通知其他游戏系统场景状态变化

## 注意事项

- 游戏场景管理器基于状态机，同一时间只能进行一个场景操作
- 所有游戏逻辑应该使用 GameSceneManager 而不是直接使用框架的 SceneManager
- 场景状态的改变是异步的，需要通过事件或轮询来检查状态变化
- 错误状态需要手动处理，可以选择重试或重置到空闲状态
- 在游戏场景加载完成后，应该初始化相关的游戏系统和数据

## 集成示例

参考 `EntryController` 的实现，展示了如何在游戏入口集成游戏场景管理器：

```csharp
public async void StartGame()
{
    try
    {
        // 关闭入口界面
        await GameLogicEntry.UI.CloseWindowAsync("EntryView");
        
        // 加载游戏场景（使用游戏逻辑层的场景管理器）
        bool loadSuccess = await GameLogicEntry.GameScene.LoadGameSceneAsync("Game");
        
        if (loadSuccess)
        {
            Log.Info("游戏场景加载成功，游戏启动完成");
            // 这里可以添加游戏启动后的逻辑，如初始化玩家数据、显示主界面等
        }
        else
        {
            Log.Error("游戏场景加载失败");
            // 处理加载失败的情况，如显示错误提示、返回主菜单等
        }
    }
    catch (Exception ex)
    {
        Log.Error($"游戏启动过程中发生错误：{ex.Message}");
    }
}
```