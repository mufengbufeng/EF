# Change: 进入 GamePlay 时为 GameCamera 添加 UICamera Overlay

## Why

当前 Game 场景中的 `GameCamera`（Base 摄像机）和 Entry 场景中持久化的 `UICamera`（也是 Base 摄像机）各自独立渲染，没有建立 URP Camera Stack 关系。这导致 UI 无法正确叠加在游戏画面之上（两个独立的 Base 摄像机会产生渲染冲突或 UI 层遮挡问题）。

需要在进入 GamePlay 流程时，将 UICamera 的渲染类型切换为 Overlay，并添加到 GameCamera 的 camera stack 中，使 UI 正确渲染在游戏画面上方。离开 GamePlay 流程时恢复 UICamera 为独立 Base 摄像机。

## What Changes

- **GameLogicEntry.cs**：在 `MangerLogicInit` 中将获取的 `uiCamera` 引用缓存为静态字段，供其他模块使用
- **GamePlayProcedure.cs**：
  - `OnEnter` 阶段：获取 Game 场景中的 `GameCamera`，将 UICamera 的 `CameraRenderType` 设为 `Overlay`，并通过 `UniversalAdditionalCameraData.cameraStack` 将 UICamera 添加到 GameCamera 的 stack
  - `OnLeave` 阶段：将 UICamera 从 GameCamera stack 移除，恢复 `CameraRenderType` 为 `Base`
- **新增 capability spec**：`gameplay-camera-stack`，定义 URP 摄像机堆栈管理的需求

## Impact

- 受影响 specs：新增 `gameplay-camera-stack`
- 受影响代码：
  - `Assets/GameScripts/HotFix/GameLogic/GameLogicEntry.cs`（缓存 UICamera 引用）
  - `Assets/GameScripts/HotFix/GameLogic/Procedure/GamePlay/GamePlayProcedure.cs`（摄像机 stack 管理）
- 不影响现有的 `Camera.main` 使用方式（GameCamera 保持 `MainCamera` tag）
- 不影响其他 Procedure（UICamera 在非 GamePlay 流程中保持 Base 类型）
