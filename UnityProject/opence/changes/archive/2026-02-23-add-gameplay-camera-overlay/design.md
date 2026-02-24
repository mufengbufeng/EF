## Context

当前项目使用 URP（Universal Render Pipeline），有两个主要摄像机：

| 摄像机 | 场景 | URP 类型 | Tag | CullingMask | 生命周期 |
|--------|------|----------|-----|-------------|----------|
| UICamera | Entry | Base | Untagged | Layer 5 (UI) | DontDestroyOnLoad，全局持久 |
| GameCamera | Game | Base | MainCamera | 除 Layer 5 外所有层 | 随 Game 场景加载/卸载 |

问题：两个独立 Base 摄像机同时存在时，URP 会各自执行独立渲染通道。需要通过 Camera Stack 机制让 UICamera 作为 GameCamera 的 Overlay，实现正确的渲染层叠。

## Goals / Non-Goals

**Goals:**
- 进入 GamePlay 时建立 GameCamera → UICamera 的 URP Camera Stack
- 离开 GamePlay 时清理 stack 关系，恢复 UICamera 独立渲染能力
- 缓存 UICamera 引用到 GameLogicEntry，避免重复查找

**Non-Goals:**
- 不修改 Game 场景文件（通过代码动态管理 stack）
- 不修改 Entry 场景中 UICamera 的默认序列化配置
- 不改变现有 `Camera.main` 的使用方式

## Decisions

### 1. 运行时动态管理 Camera Stack（而非场景序列化）

**决定**：在代码中通过 `UniversalAdditionalCameraData` API 动态切换 UICamera 的 Render Type 并管理 stack。

**理由**：
- UICamera 是 DontDestroyOnLoad 对象，GameCamera 随场景加载创建，两者不在同一场景，无法在编辑器中预配置 stack
- 动态管理更灵活，可适应未来不同流程对摄像机的不同需求

**替代方案**：
- 在 Game 场景中预配置 stack 引用 → 不可行，UICamera 在 DontDestroyOnLoad 场景中
- 使用全局 Camera Manager 单例 → 过度设计，当前仅 GamePlay 有此需求

### 2. UICamera 引用缓存在 GameLogicEntry

**决定**：在 `GameLogicEntry.MangerLogicInit()` 中将已获取但未使用的 `uiCamera` 引用缓存为 `Camera` 组件的静态字段。

**理由**：
- `MangerLogicInit` 已经通过 `ReferenceCollector` 获取了 `uiCamera` GameObject 但未使用
- 缓存为 `Camera` 组件避免每次使用时 `GetComponent`
- 作为静态属性暴露，与现有 `Resource`、`UI` 等管理器引用模式一致

### 3. 在 GamePlayProcedure 中管理 stack 生命周期

**决定**：在 `OnEnterAsync` 场景加载完成后建立 stack，在 `OnLeave` 中清理。

**理由**：
- GameCamera 在场景加载完成后才存在，必须在 `EnterGamePlaySceneAsync` 之后获取
- `OnLeave` 是流程退出的统一清理点，已有模块清理逻辑
- 通过 `TryResolveSceneReferences` 中已有的 `ReferenceCollector` 获取 GameCamera 引用

## Risks / Trade-offs

| 风险 | 缓解措施 |
|------|---------|
| UICamera 或 GameCamera 获取失败 | 添加 null 检查和日志警告，降级为独立渲染 |
| OnLeave 时 GameCamera 已被销毁（场景切换） | 先检查 GameCamera 是否为 null，仅恢复 UICamera 的 Render Type |
| 其他流程也需要摄像机 stack | 当前方案在 GamePlayProcedure 中局部管理，未来如有需要可抽取为独立模块 |

## Open Questions

- 无
