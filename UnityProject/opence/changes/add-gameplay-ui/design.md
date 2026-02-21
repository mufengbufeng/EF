# 设计文档：GamePlayUI 实现

## UI 界面设计

### 视觉布局

```
┌──────────────────────────────────────┐
│ Score: 0                      [暂停] │  ← GamePlayUI
│                                    │
│                                    │
│         游戏画面区域                  │
│                                    │
└──────────────────────────────────────┘
```

### 组件清单

| 组件 | 类型 | 名称 | 位置 | 功能 |
|------|------|------|------|------|
| Canvas | Canvas | - | Screen Overlay | UI 根节点 |
| Canvas Scaler | Canvas Scaler | - | - | 响应式缩放 |
| ScorePanel | GameObject | - | 左上角 | 积分显示容器 |
| ScoreText | TextMeshPro | "ScoreText" | ScorePanel 内 | 显示积分文本 |
| PauseButton | Button | "PauseButton" | 右上角 | 暂停/继续按钮 |
| ReferenceCollector | ReferenceCollector | - | Canvas 根节点 | 自动组件绑定 |

### 颜色和样式

**积分显示（ScoreText）：**
- 文本颜色：`#FFFFFF`（白色）或 `#FFFF00`（亮黄色）
- 字号：36
- 对齐：Left
- 溢边距：距左边缘 20px，距上边缘 20px
- 可选背景：`rgba(0, 0, 0, 0.5)` 半透明黑色

**暂停按钮（PauseButton）：**
- 尺寸：80x80 像素
- 锚点：右上角，距右边缘 20px，距上边缘 20px
- 可选：圆形背景（`Image` 组件 + `Mask`）
- 文本/图标：
  - 运行中："暂停"或 `||` 图标
  - 暂停中："继续"或 `▶` 图标

### Canvas 配置

- **渲染模式**：Screen Space - Overlay
- **缩放顺序**：100（确保在游戏画面之上）
- **缩放类型**：Scale With Screen Size
- **参考分辨率**：1920x1080
- **匹配模式**：0.5（取 1920 和 1080 的中间值，避免拉伸）

## 架构概览

本设计遵循 EF 框架的 UI 架构模式，采用 Model-View-Controller (MVC) 分离：

```
┌─────────────────┐     ┌─────────────────┐     ┌─────────────────┐
│  GamePlayView   │────▶│ GamePlayController│◀────│  ScoreModel     │
│   (UIView)      │     │  (UIController)  │     │  (ModelBase)    │
│                 │     │                  │     │                 │
│ - 积分 Text    │     │ - 处理暂停逻辑   │     │ - Score 属性    │
│ - 暂停 Button  │     │ - 刷新积分显示   │     │ - 增加/重置     │
└─────────────────┘     └─────────────────┘     └─────────────────┘
        ▲                       │
        │                       │
        └───────────────────────┘
            通过 UHub 自动绑定
```

## 设计决策

### 1. UI 层级与生命周期

**决策**：GamePlayUI 注册为 `UILayer.Normal` 层级，单实例模式，关闭时缓存。

**理由**：
- Normal 层级适合常规游戏界面
- 单实例确保同时只显示一个 GamePlayUI
- 缓存优化性能，避免重复加载

### 2. 积分数据存储

**决策**：使用 `ModelBase<TData>` 实现积分模型，通过 ModelManager 注册。

**理由**：
- 符合 EF 框架的数据管理模式
- 支持数据绑定（INotifyPropertyChanged）
- UI 可直接绑定 Score 属性实现自动更新
- 与游戏逻辑解耦，便于测试

### 3. 暂停实现方式

**决策**：通过修改 `Time.timeScale` 实现全局暂停。

**理由**：
- Unity 标准做法，影响所有物理和动画
- 实现简单，性能开销低
- UI 使用 `unscaledTime` 保持交互

**考虑点**：
- 粒子系统需要 `unscaledTime` 支持
- 音效播放不受影响（可能需要额外处理）

### 4. UI 预制体结构

```
GamePlayView.prefab
├── Canvas (Screen Space - Overlay)
├── ScorePanel
│   └── ScoreText (TextMeshPro)
└── PauseButton
```

**考虑点**：
- 使用 ReferenceCollector 统一管理组件引用
- UHub 自动绑定字段（`_scoreText`, `_pauseButton`）

## 扩展点

### 1. 积分获取接口

```csharp
public interface IScoreModel
{
    int Score { get; }
    void AddScore(int points);
    void ResetScore();
}
```

**扩展方向**：
- 后续可添加连击分数、倍率等
- 可集成成就系统触发

### 2. 暂停状态管理

```csharp
public enum PauseState
{
    Running,   // 正常运行
    Paused     // 已暂停
}
```

**扩展方向**：
- 后续可添加 PauseMenu（设置、退出）
- 可区分"强制暂停"和"玩家暂停"

### 3. UI 事件

```csharp
public class GamePlayView : UIView
{
    public event Action OnPauseClicked;
}
```

**扩展方向**：
- 后续可添加设置、技能等按钮事件
- 支持手势操作（如双击暂停）

## 风险与缓解

| 风险 | 影响 | 缓解措施 |
|------|------|---------|
| TimeScale 影响未考虑的系统 | 动画、物理异常 | 使用 unscaledTime 处理 UI 动画 |
| Model 线程安全 | 并发访问积分 | ModelManager 在主线程，暂不需锁 |
| UI 预制体路径错误 | 加载失败 | 使用常量定义路径，添加日志 |

## 测试策略

1. **单元测试**（可选）：
   - ScoreModel 数据绑定测试
   - 积分增加/重置逻辑测试

2. **集成测试**：
   - GamePlayProcedure 进入/退出流程测试
   - UI 打开/关闭生命周期测试
   - 暂停/继续功能测试

3. **手动测试**：
   - 暂停时 UI 仍可响应
   - 积分显示正确更新
   - 退出玩法无残留 UI
