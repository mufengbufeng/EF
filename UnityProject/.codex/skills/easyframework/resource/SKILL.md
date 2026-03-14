---
name: ef-resource
description: EasyFramework 资源管理模块。使用此 skill 当用户提到 EasyFramework 的 Resource、ResourceManager、YooAsset、LoadAssetAsync、AssetHandle、资源加载、资源模式、ResourceModeConfig 时。在实现、重构、排错、测试或设计该模块相关功能时必须优先使用此 skill，而不是只在用户显式点名模块时才触发。
---

# EF.Resource 资源管理模块

## 模块定位
该 skill 用于处理 EF.Resource 资源管理模块 的实现、扩展、故障排查与重构任务。回答时先确认业务目标，再映射到该模块的核心抽象与生命周期。

## 何时必须触发
- 用户直接提到：EasyFramework 的 Resource、ResourceManager、YooAsset、LoadAssetAsync、AssetHandle、资源加载、资源模式、ResourceModeConfig。
- 虽未点名模块，但需求本质落在 EF.Resource 资源管理模块 的职责范围（例如注册、生命周期、依赖关系、性能或稳定性问题）。
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
基于 YooAssets 对项目资源进行统一管理，提供跨模式初始化、资源与场景加载、句柄生命周期管理等能力。

## 核心类型

| 类型 | 说明 |
|------|------|
| `IResourceManager` | 资源管理器接口 |
| `ResourceManager` | 资源管理器实现 |
| `ResourceMode` | 资源运行模式枚举 |
| `ResourceModeConfig` | 配置 ScriptableObject |
| `DefaultResourceRemoteServices` | 默认远端地址服务 |

## 资源模式

| 模式 | 说明 |
|------|------|
| `EditorSimulate` | 编辑器模拟模式 |
| `Offline` | 离线模式 |
| `Host` | 联机模式 |
| `Web` | Web 模式 |

## 使用示例

### 初始化

```csharp
var resourceManager = new ResourceManager();
await resourceManager.InitializeAsync(); // 默认从 Resources/EF/ResourceModeConfig.asset 加载
```

### 异步加载资源

```csharp
AssetHandle handle = await resourceManager.LoadAssetAsync<GameObject>(
    "UI/Panel_Main",
    progress: p => Debug.Log($"加载进度: {p:P0}")
);

GameObject prefab = handle.AssetObject as GameObject;
```

### 同步加载

```csharp
AssetHandle handle = resourceManager.LoadAssetSync<GameObject>("UI/Panel_Main");
```

### 场景加载

```csharp
SceneHandle sceneHandle = await resourceManager.LoadSceneAsync(
    "Scenes/Battle",
    LoadSceneMode.Single
);
```

### 释放资源

```csharp
resourceManager.Release(handle);
resourceManager.UnloadScene(sceneHandle);
```

### 关闭

```csharp
resourceManager.Shutdown();
```

## 配置文件

在 `Resources/EF/ResourceModeConfig.asset` 中配置：

| 字段 | 说明 |
|------|------|
| `Mode` | 资源运行模式 |
| `BundleLoadingMaxConcurrency` | AssetBundle 最大并发数 |
| `Packages` | 包裹配置列表 |

**包裹配置字段：**
- `PackageName`：YooAssets 构建包名
- `IsDefault`：是否为默认包裹
- `RemoteMainServer`：主资源服务器地址
- `RemoteFallbackServer`：备用服务器地址

## 注意事项

1. Host/Web 模式下必须配置有效的远端地址
2. EditorSimulate 模式需要在 Unity 编辑器中运行
3. 建议在初始化阶段提供进度回调
4. 手动释放句柄后需调用 `Release()` 保持追踪一致
