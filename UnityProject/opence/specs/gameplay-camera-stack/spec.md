# gameplay-camera-stack Specification

## Purpose
管理 GamePlay 流程中 URP 摄像机堆栈的建立与清理，确保 UICamera 作为 Overlay 正确叠加在 GameCamera 之上渲染 UI 层。
## Requirements
### Requirement: UICamera 引用缓存
`GameLogicEntry` SHALL 在初始化时将 Entry 场景中通过 `ReferenceCollector` 获取的 UICamera 的 `Camera` 组件缓存为静态属性，供其他模块访问。

#### Scenario: 初始化时缓存 UICamera 引用
- **GIVEN** Entry 场景的 `ReferenceCollector` 中注册了 key 为 `UICamera` 的 GameObject
- **WHEN** `GameLogicEntry.Init()` 执行 `MangerLogicInit()`
- **THEN** `GameLogicEntry.UICamera` 静态属性 SHALL 返回该 GameObject 上的 `Camera` 组件

#### Scenario: UICamera 引用缺失时的容错
- **GIVEN** `ReferenceCollector` 中不存在 `UICamera` 或其上没有 `Camera` 组件
- **WHEN** `GameLogicEntry.Init()` 执行
- **THEN** `GameLogicEntry.UICamera` SHALL 返回 null 并输出警告日志

### Requirement: 进入 GamePlay 时建立摄像机堆栈
`GamePlayProcedure` 在进入流程且游戏场景加载完成后，SHALL 将 UICamera 的 URP Render Type 切换为 Overlay，并将其添加到 GameCamera 的 `UniversalAdditionalCameraData.cameraStack` 中。

#### Scenario: 成功建立摄像机堆栈
- **GIVEN** Game 场景已加载，`GameCamera`（tag 为 MainCamera 的 Base 摄像机）存在
- **AND** `GameLogicEntry.UICamera` 不为 null
- **WHEN** `GamePlayProcedure.OnEnterAsync` 完成场景加载后执行摄像机堆栈设置
- **THEN** UICamera 的 `UniversalAdditionalCameraData.renderType` SHALL 被设置为 `CameraRenderType.Overlay`
- **AND** GameCamera 的 `UniversalAdditionalCameraData.cameraStack` SHALL 包含 UICamera

#### Scenario: GameCamera 获取失败时的容错
- **GIVEN** Game 场景已加载但 `ReferenceCollector` 中缺少 `GameCamera` 引用
- **WHEN** `GamePlayProcedure` 尝试建立摄像机堆栈
- **THEN** SHALL 输出警告日志，UICamera 保持当前 Render Type 不变，游戏继续运行

#### Scenario: UICamera 不可用时的容错
- **GIVEN** `GameLogicEntry.UICamera` 为 null
- **WHEN** `GamePlayProcedure` 尝试建立摄像机堆栈
- **THEN** SHALL 输出警告日志，跳过摄像机堆栈设置，游戏继续运行

### Requirement: 离开 GamePlay 时恢复摄像机状态
`GamePlayProcedure` 在离开流程时，SHALL 将 UICamera 从 GameCamera 的 camera stack 中移除，并恢复 UICamera 的 Render Type 为 Base。

#### Scenario: 正常退出时恢复摄像机
- **GIVEN** 摄像机堆栈已建立（UICamera 为 Overlay 且在 GameCamera stack 中）
- **WHEN** `GamePlayProcedure.OnLeave` 执行
- **THEN** UICamera SHALL 从 GameCamera 的 `cameraStack` 中被移除
- **AND** UICamera 的 `renderType` SHALL 恢复为 `CameraRenderType.Base`

#### Scenario: GameCamera 已销毁时仅恢复 UICamera
- **GIVEN** 摄像机堆栈已建立
- **AND** GameCamera 所在场景已被卸载（GameCamera 为 null）
- **WHEN** `GamePlayProcedure.OnLeave` 执行
- **THEN** UICamera 的 `renderType` SHALL 恢复为 `CameraRenderType.Base`
- **AND** 不产生 NullReferenceException

#### Scenario: 未建立堆栈时离开
- **GIVEN** 摄像机堆栈未成功建立（因容错跳过）
- **WHEN** `GamePlayProcedure.OnLeave` 执行
- **THEN** 不应产生异常或错误日志

