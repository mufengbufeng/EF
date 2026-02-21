# 变更提案：添加 GamePlayUI（玩法界面）

## 动机

当前 `GamePlayProcedure` 已具备背景滚动、敌机生成、子弹系统和玩家飞机等核心玩法功能，但缺少面向玩家的 UI 交互层。玩家无法查看当前游戏积分，也无法通过界面按钮暂停游戏。

本次变更聚焦添加 GamePlayUI，提供：
1. **积分显示**：实时显示玩家当前积分
2. **暂停按钮**：允许玩家暂停/继续游戏

## 变更内容

1. 新增 `gameplay-ui` 能力
   - 创建 GamePlayView（视图层）和 GamePlayController（控制层）
   - 集成到 EF UI 框架，使用 `IUIManager` 打开和管理
   - 使用 UHubComponent 实现自动组件绑定和事件管理

2. 新增 `score-model` 能力
   - 创建 `IScoreModel` 接口和数据模型
   - 提供积分获取、增加、重置等操作
   - 通过 ModelManager 注册，供 UI 和游戏逻辑访问

3. 新增 `game-pause` 能力
   - 通过 Unity TimeScale 实现游戏暂停/继续
   - 暂停时显示可选的暂停状态提示
   - 确保暂停不影响 UI 交互

4. 集成到玩法流程
   - 在 `GamePlayProcedure` 进入场景后打开 GamePlayUI
   - 注册 ScoreModel 到 ModelManager
   - 在流程退出时关闭 UI 并清理 Model

## 影响范围

- 受影响规范：
  - 新增 `gameplay-ui`
  - 新增 `score-model`
  - 新增 `game-pause`
- 受影响代码（工作阶段实施）：
  - `Assets/GameScripts/HotFix/GameLogic/Procedure/GamePlay/GamePlayProcedure.cs`
  - `Assets/GameScripts/HotFix/GameLogic/UI/GamePlay/`（计划新增目录）
  - `Assets/GameScripts/HotFix/GameLogic/Model/`（计划新增目录）
  - `Assets/AssetRaw/UI/GamePlay/GamePlayView.prefab`（计划新增预制体）
- 复用依赖：
  - `EF.UI.IUIManager`
  - `EF.Model.ModelManager`
  - `EF.UI.UIView`
  - `EF.UI.UIController`
  - `UnityEngine.Time`

## UI 界面规格

用户需要提供一个简洁的 GamePlayUI 界面，布局如下：

```
┌──────────────────────────────────────┐
│ Score: 0                      [暂停] │
│                                    │
│                                    │
│         游戏画面区域                  │
│                                    │
└──────────────────────────────────────┘
```

### 左上角：积分显示
- 位置：距左边缘 20px，距上边缘 20px
- 内容：TextMeshPro 文本组件
- 格式：`Score: {分数}` 或 `{分数}分`
- 颜色：白色或亮黄色
- 字号：36pt
- 可选：深色半透明背景提升可读性

### 右上角：暂停按钮
- 位置：距右边缘 20px，距上边缘 20px
- 尺寸：约 80x80 像素
- 状态切换：
  - 运行中：显示"暂停"文本或暂停图标（||）
  - 已暂停：显示"继续"文本或播放图标（▶）
- 交互：点击切换暂停/继续状态

### Canvas 配置
- 渲染模式：Screen Space - Overlay
- 缩放顺序：100（确保在游戏画面之上）
- 缩放类型：Scale With Screen Size
- 参考分辨率：1920x1080
- 匹配模式：0.5

## 验收标准

1. 进入 GamePlayProcedure 后，GamePlayUI 自动打开并显示
2. UI 左上角显示当前积分为 0（格式："Score: 0"）
3. UI 右上角显示暂停按钮，默认显示"暂停"或暂停图标
4. 点击暂停按钮后：
   - TimeScale 设置为 0（游戏暂停）
   - 按钮状态更新为"继续"或播放图标
   - UI 仍可交互（点击继续可恢复）
5. 再次点击按钮后：
   - TimeScale 设置为 1（游戏继续）
   - 按钮状态恢复为"暂停"或暂停图标
6. 退出 GamePlayProcedure 后，UI 关闭，ScoreModel 被清理
7. 在不同分辨率下 UI 布局保持一致

## 非目标

1. 本次不实现完整的游戏暂停菜单（如设置、退出等）
2. 本次不实现积分获取逻辑（仅提供数据模型和接口）
3. 本次不实现游戏结束界面
4. 本次不实现高分记录、成就等扩展功能
