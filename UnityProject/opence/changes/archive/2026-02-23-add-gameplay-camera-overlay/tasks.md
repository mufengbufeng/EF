## 1. GameLogicEntry 缓存 UICamera 引用

- [x] 1.1 在 `GameLogicEntry` 中添加 `private static Camera _uiCamera` 静态字段和 `public static Camera UICamera` 属性
- [x] 1.2 在 `MangerLogicInit()` 中将已获取的 `uiCamera` GameObject 的 `Camera` 组件赋值给 `_uiCamera`，添加 null 检查和日志
- [x] 1.3 添加 `using UnityEngine.Rendering.Universal` 引用（后续 URP API 需要）

## 2. GamePlayProcedure 进入时建立 Camera Stack

- [x] 2.1 在 `GamePlayProcedure` 中添加 `private Camera _gameCamera` 字段用于缓存 GameCamera 引用
- [x] 2.2 在 `TryResolveSceneReferences()` 中通过 `ReferenceCollector` 获取 `GameCamera` 引用并缓存
- [x] 2.3 在 `OnEnterAsync` 中场景加载和引用解析完成后，调用新增的 `SetupCameraStack()` 方法
- [x] 2.4 实现 `SetupCameraStack()` 方法：
  - 获取 GameCamera 和 UICamera 的 `UniversalAdditionalCameraData`
  - 将 UICamera 的 `renderType` 设为 `CameraRenderType.Overlay`
  - 将 UICamera 添加到 GameCamera 的 `cameraStack`
  - 添加完善的 null 检查和日志

## 3. GamePlayProcedure 离开时恢复 Camera 状态

- [x] 3.1 在 `OnLeave` 中调用新增的 `CleanupCameraStack()` 方法
- [x] 3.2 实现 `CleanupCameraStack()` 方法：
  - 如果 GameCamera 不为 null，从其 `cameraStack` 中移除 UICamera
  - 将 UICamera 的 `renderType` 恢复为 `CameraRenderType.Base`
  - 清空 `_gameCamera` 引用
  - 处理 GameCamera 已被销毁的情况（null 检查）

## 4. 验证

- [x] 4.1 在 Unity Editor 中运行，验证进入 GamePlay 后 UI 正确叠加在游戏画面上
- [x] 4.2 验证从 GamePlay 返回主菜单后 UICamera 恢复为独立 Base 摄像机
- [x] 4.3 验证 Game Inspector 中 GameCamera 的 camera stack 列表包含 UICamera
