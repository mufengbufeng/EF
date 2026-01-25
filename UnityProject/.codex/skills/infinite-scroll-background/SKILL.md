---
name: infinite-scroll-background
description: Unity 2D 背景无限滚动的实现与接入要点
metadata:
  short-description: Unity 2D 背景无限滚动的实现与接入要点
---

# infinite-scroll-background

## 何时使用
- 飞机大战等固定相机玩法需要纵向连续滚动背景
- 需要运行时调整滚动速度或切换 Sprite
- 需要复用现有 GameBackgroundModule 逻辑

## 关联实现
- 模块接口：`Assets/GameScripts/HotFix/GameLogic/GamePlay/Background/IGameBackgroundModule.cs`
- 模块实现：`Assets/GameScripts/HotFix/GameLogic/GamePlay/Background/GameBackgroundModule.cs`
- 接入流程：`Assets/GameScripts/HotFix/GameLogic/Procedure/GamePlay/GamePlayProcedure.cs`

## 使用步骤
1. 场景中放置 `BackgroundRoot`（可选；没有则挂到场景根节点）。
2. 准备背景预制体：包含 1~N 个 SpriteRenderer 子物体（只有 1 个时模块会自动克隆）。
3. 进入玩法时创建并注册模块（建议 scope = GamePlayScope）：
   - `Configure(prefabName, speed)`
   - `LoadAsync()` 在进入场景后调用
4. 运行时控制：
   - `SetSpeed` 立即生效，0 表示暂停
   - `SetSprite` 会重建布局，保持无缝滚动
   - `SetTargetCamera` 可指定非 MainCamera 的相机
5. 确保 `ModuleSystem.Update` 每帧驱动（当前由 `GameEntry.Update` 调用）。

## 关键机制
- 运行时通过 `SpriteRenderer.bounds.size.y` 计算单张高度
- 通过相机视口顶/底判断超出阈值后回收到队列顶部
- 速度正值向下、负值向上

## 常见问题
- 背景不滚动：检查 `ModuleSystem.Update` 是否在驱动；速度是否为 0
- 出现缝隙：确认 SpriteRenderer 缩放一致、Pivot 与拼接顺序正确
- 无背景：确认资源名与预制体路径可被 `IResourceManager` 正确加载
