# 场景管理器规范

该规范定义了 EasyFramework 中游戏场景管理器的功能要求、API接口和行为规范。

## ADDED Requirements

### Requirement: 场景管理器核心功能
场景管理器 SHALL 提供基于状态机的场景生命周期管理，支持异步场景加载和卸载。

#### Scenario: 加载游戏场景
```
GIVEN 游戏处于空闲状态
AND 用户点击开始游戏按钮
WHEN 调用 SceneManager.LoadSceneAsync("Game")
THEN 场景管理器状态切换为 Loading
AND 开始异步加载 Game.unity 场景
AND 提供加载进度回调
AND 加载完成后状态切换为 Loaded
AND 触发 OnSceneLoaded 事件
```

#### Scenario: 处理场景加载失败
```
GIVEN 场景管理器正在加载场景
AND 目标场景文件不存在或损坏
WHEN 场景加载失败
THEN 状态切换为 Error
AND 触发 OnSceneError 事件，包含错误信息
AND 提供重试或回退选项
```

### Requirement: 状态机集成
场景管理器 MUST 基于现有的 EF.Fsm 框架实现状态管理。

#### Scenario: 状态机状态转换
```
GIVEN 场景管理器已初始化
WHEN 系统启动
THEN 状态机初始状态为 Idle
AND 支持以下状态转换：
  - Idle → Loading（开始加载）
  - Loading → Loaded（加载成功）
  - Loading → Error（加载失败）
  - Loaded → Unloading（开始卸载）
  - Unloading → Idle（卸载成功）
  - Error → Idle（重置）
```

#### Scenario: 状态查询
```
GIVEN 场景管理器运行中
WHEN 调用 GetCurrentStatus()
THEN 返回当前准确的场景状态
AND 状态包括：Idle, Loading, Loaded, Unloading, Error
```

### Requirement: ResourceManager集成
场景管理器 MUST 与现有的ResourceManager集成，复用场景加载功能。

#### Scenario: 异步场景加载
```
GIVEN ResourceManager已初始化
AND 场景管理器已初始化
WHEN 调用场景加载功能
THEN 使用 ResourceManager.LoadSceneAsync() 进行实际加载
AND 支持所有ResourceManager的加载参数
AND 正确处理ResourceManager返回的SceneHandle
```

#### Scenario: 场景卸载
```
GIVEN 当前有已加载的场景
WHEN 调用 UnloadSceneAsync()
THEN 使用 ResourceManager.UnloadScene() 进行实际卸载
AND 正确释放场景资源句柄
AND 确保内存正确回收
```

### Requirement: API设计
场景管理器 SHALL 提供简洁易用的API接口，符合框架风格。

#### Scenario: 基础API调用
```
GIVEN 场景管理器已注册到框架
WHEN 开发者需要加载场景
THEN 可以使用以下API：
  - LoadSceneAsync(sceneName) : UniTask<bool>
  - UnloadSceneAsync() : UniTask<bool>
  - GetCurrentStatus() : SceneStatus
  - GetCurrentScene() : SceneInfo?
```

#### Scenario: 事件订阅
```
GIVEN 场景管理器已初始化
WHEN 开发者需要监听场景事件
THEN 可以订阅以下事件：
  - OnSceneLoaded : Action<SceneInfo>
  - OnSceneUnloaded : Action<string>
  - OnLoadingProgress : Action<float>
  - OnSceneError : Action<Exception>
```

### Requirement: 错误处理
场景管理器 MUST 提供完善的错误处理和恢复机制。

#### Scenario: 网络错误重试
```
GIVEN 场景加载因网络问题失败
WHEN 错误类型为临时性网络错误
THEN 自动重试最多3次
AND 每次重试间隔递增
AND 最终失败时触发错误事件
```

#### Scenario: 状态错误检查
```
GIVEN 场景管理器当前状态为Loading
WHEN 尝试加载另一个场景
THEN 抛出InvalidOperationException
AND 错误消息说明当前状态不支持该操作
```

### Requirement: 框架集成
场景管理器 MUST 正确集成到EF框架的生命周期管理中。

#### Scenario: 管理器注册
```
GIVEN EF框架启动过程
WHEN 注册场景管理器
THEN 场景管理器继承自AEFManager
AND 实现ISceneManager接口
AND 正确注册到GameLogicEntry
AND 支持依赖注入（ResourceManager等）
```

#### Scenario: 框架生命周期
```
GIVEN 框架运行中
WHEN 框架更新循环执行
THEN 场景管理器的状态机得到正确更新
AND 所有异步操作在主线程回调
AND 框架关闭时正确释放资源
```

### Requirement: 性能要求
场景管理器 SHALL 满足性能和内存使用要求。

#### Scenario: 内存管理
```
GIVEN 场景已加载
WHEN 场景被卸载
THEN 所有相关资源句柄被正确释放
AND 不存在内存泄漏
AND GC压力最小化
```

#### Scenario: 响应性要求
```
GIVEN 用户触发场景切换
WHEN 场景开始加载
THEN UI在100ms内开始显示加载指示器
AND 加载进度至少每200ms更新一次
AND 用户操作保持响应性
```

### Requirement: EntryController集成
场景管理器 MUST 与现有的EntryController正确集成。

#### Scenario: 开始游戏集成
```
GIVEN 用户在入口界面
AND EntryController已初始化
WHEN 用户点击开始游戏按钮
THEN EntryController调用SceneManager.LoadSceneAsync("Game")
AND 关闭入口界面
AND 显示场景加载进度（如果需要）
AND Game.unity场景成功加载后开始游戏
```

### Requirement: 配置和扩展性
场景管理器 SHALL 支持配置和未来的功能扩展。

#### Scenario: 场景信息配置
```
GIVEN 项目需要管理多个场景
WHEN 定义场景配置
THEN 支持通过SceneInfo结构定义场景元信息
AND 包括场景名称、位置、加载模式等
AND 支持运行时动态配置
```

#### Scenario: 插件扩展
```
GIVEN 未来需要扩展场景功能
WHEN 设计扩展接口
THEN 预留IScenePlugin接口
AND 支持在场景生命周期关键点注入自定义逻辑
AND 保持向后兼容性
```