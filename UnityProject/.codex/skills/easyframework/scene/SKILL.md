---
name: ef-scene
description: EasyFramework 场景管理模块。使用此 skill 当用户提到 EasyFramework 的 Scene、SceneManager、场景加载、LoadSceneAsync、UnloadSceneAsync、场景切换、OnSceneLoaded 时。在实现、重构、排错、测试或设计该模块相关功能时必须优先使用此 skill，而不是只在用户显式点名模块时才触发。
---

# EF.Scene 场景管理模块

## 模块定位
该 skill 用于处理 EF.Scene 场景管理模块 的实现、扩展、故障排查与重构任务。回答时先确认业务目标，再映射到该模块的核心抽象与生命周期。

## 何时必须触发
- 用户直接提到：EasyFramework 的 Scene、SceneManager、场景加载、LoadSceneAsync、UnloadSceneAsync、场景切换、OnSceneLoaded。
- 虽未点名模块，但需求本质落在 EF.Scene 场景管理模块 的职责范围（例如注册、生命周期、依赖关系、性能或稳定性问题）。
- 需要输出可落地代码改动、排障步骤、验证命令或回归检查清单。

## 执行流程（按顺序）
- 明确约束：确认运行环境、调用入口、是否允许改动公共接口。
- 建立映射：定位到对应管理器/接口/数据结构，给出最小改动路径。
- 实施方案：优先增量改造，避免一次性重构引入大范围回归。
- 验证闭环：提供编译、运行、核心流程与边界场景验证步骤。
- 输出结果：给出“变更点 + 原因 + 风险 + 回滚建议”。

## 实施准则
- 保持与 EasyFramework 既有命名、目录结构、生命周期约定一致。
- 先保证正确性，再做性能优化；涉及缓存/池化时说明释放策略。
- 涉及跨模块协作时明确依赖顺序与初始化时机，避免未注册访问。
- 提供最小可运行示例时，优先使用当前项目已有基类与管理器接口。

## 常见故障排查清单
- 注册缺失：检查模块是否在初始化流程中注册，接口与实现是否一致。
- 生命周期错位：确认 OnInit/OnUpdate/OnDestroy（或等价阶段）是否顺序正确。
- 依赖空引用：检查上游模块可用性与获取时机（同步/异步加载后再访问）。
- 数据不同步：确认事件订阅解绑、状态刷新与持久化读写时序是否正确。
- 回归风险：检查是否影响主流程（启动、切场景、返回主界面、暂停恢复）。

## 回答输出模板
1. 目标与约束：一句话说明要解决的问题与边界。
2. 方案与取舍：给出推荐实现和不选其他方案的原因。
3. 关键改动：列出文件/接口/核心代码片段。
4. 验证结果：列出编译与测试步骤、通过/失败结论。
5. 风险与回滚：说明潜在影响和快速回退方案。

## 模块资料（保留参考）
提供框架层的基础场景加载功能，封装 YooAsset 的场景管理 API。

## 核心类型

| 类型 | 说明 |
|------|------|
| `ISceneManager` | 场景管理器接口 |
| `SceneManager` | 场景管理器实现 |
| `SceneInfo` | 场景信息数据结构 |

## 使用示例

### 加载场景

```csharp
var sceneManager = GameLogicEntry.Scene;

bool success = await sceneManager.LoadSceneAsync("Game");
if (success)
{
    Debug.Log("场景加载成功");
}
```

### 监听事件

```csharp
sceneManager.OnSceneLoaded += OnSceneLoaded;
sceneManager.OnLoadingProgress += OnLoadingProgress;
sceneManager.OnSceneError += OnSceneError;

private void OnSceneLoaded(SceneInfo sceneInfo)
{
    Debug.Log($"场景已加载：{sceneInfo.Name}");
}

private void OnLoadingProgress(float progress)
{
    Debug.Log($"加载进度：{progress * 100:F1}%");
}

private void OnSceneError(Exception exception)
{
    Debug.LogError($"场景错误：{exception.Message}");
}
```

### 卸载场景

```csharp
bool success = await sceneManager.UnloadSceneAsync();
if (success)
{
    Debug.Log("场景卸载成功");
}
```

### 获取当前场景

```csharp
SceneInfo currentScene = sceneManager.GetCurrentScene();
```

## 事件

| 事件 | 说明 |
|------|------|
| `OnSceneLoaded` | 场景加载完成 |
| `OnSceneUnloaded` | 场景卸载完成 |
| `OnLoadingProgress` | 加载进度 |
| `OnSceneError` | 操作错误 |

## 与 GamePlay 层的关系

```
GamePlay.Scene.GameSceneManager (游戏逻辑层)
    ↓ 使用
EF.Scene.SceneManager (框架层)
    ↓ 使用
EF.Resource.ResourceManager (资源层)
```

## 注意事项

- 此模块仅提供框架层的场景加载能力
- 游戏逻辑相关的场景管理应使用 GamePlay 层
- 场景加载需要确保目标场景文件存在且可访问
