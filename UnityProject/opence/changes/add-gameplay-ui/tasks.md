# 任务列表：GamePlayUI 实现

## 任务 1：创建 ScoreModel 数据模型
**优先级**: 高
**预估**: 0.5h
**依赖**: 无

### 验收标准
- [ ] 创建 `Assets/GameScripts/HotFix/GameLogic/Model/ScoreModel.cs`
- [ ] 实现 `IScoreModel` 接口（Score 属性、AddScore、ResetScore 方法）
- [ ] 继承 `ModelBase<IScoreModel>` 实现数据绑定
- [ ] 编译通过，无错误

---

## 任务 2：创建 GamePlayView 视图层
**优先级**: 高
**预估**: 1h
**依赖**: 任务 1

### 验收标准
- [ ] 创建 `Assets/GameScripts/HotFix/GameLogic/UI/GamePlay/GamePlayView.cs`
- [ ] 继承 `UIView`，使用 UHub 自动绑定组件
- [ ] 定义 `Text _scoreText` 和 `Button _pauseButton` 字段
- [ ] 实现 `OnInitialize()` 调用 `UHub.Initialize()`
- [ ] 实现 `OnBindings()` 绑定暂停按钮点击事件
- [ ] 定义 `event Action OnPauseClicked` 事件
- [ ] 提供 `UpdateScore(int score)` 方法更新积分显示
- [ ] 提供 `SetPauseState(bool paused)` 方法更新按钮状态

---

## 任务 3：创建 GamePlayController 控制层
**优先级**: 高
**预估**: 0.5h
**依赖**: 任务 2

### 验收标准
- [ ] 创建 `Assets/GameScripts/HotFix/GameLogic/UI/GamePlay/GamePlayController.cs`
- [ ] 继承 `UIController`
- [ ] 在 `OnInitialize()` 获取 `GamePlayView` 引用
- [ ] 在 `OnEnter()` 订阅 View 的 `OnPauseClicked` 事件
- [ ] 实现 `HandlePauseClicked()` 处理暂停逻辑
- [ ] 实现 `TogglePause()` 方法修改 `Time.timeScale`
- [ ] 从 ModelManager 获取 `IScoreModel` 并绑定到 View

---

## 任务 4：创建 GamePlayView.prefab 预制体
**优先级**: 高
**预估**: 1.5h
**依赖**: 任务 2

### UI 界面需求

用户需要提供一个简洁的玩法 UI 界面，包含以下元素：

#### 布局结构
```
GamePlayView.prefab
├── Canvas (Screen Space - Overlay, Sort Order: 100)
│   ├── Canvas Scaler (Scale With Screen Size, Ref Res: 1920x1080, Match: 0.5)
│   │   ├── ScorePanel (左上角锚点: Top-Left 0, 0)
│   │   │   └── ScoreText (TextMeshPro, 文本: "Score: 0", 字号: 36)
│   │   └── PauseButton (右上角锚点: Top-Right 0, 0)
│   │       └── Button 组件
│   │       └── Text/Image (显示"暂停"或播放图标）
│   └── ReferenceCollector (注册引用)
└── UIView 脚本
```

#### 视觉规格
- **积分显示区域**：
  - 位置：屏幕左上角（距边缘 20px）
  - 背景：可选深色半透明背景（如 RGBA: 0,0,0,0.5）
  - 文本颜色：白色或亮黄色（如 #FFFF00）
  - 字号：24-36pt
  - 对齐：左对齐

- **暂停按钮**：
  - 位置：屏幕右上角（距边缘 20px）
  - 尺寸：约 80x80 像素
  - 背景：圆形或圆角方形
  - 未暂停状态：显示暂停图标（||）或文本"暂停"
  - 已暂停状态：显示播放图标（▶）或文本"继续"

#### 响应式布局
- Canvas Scaler：`Scale With Screen Size`
- 参考分辨率：1920x1080
- 匹配模式：0.5（取 1920 和 1080 的中间值，避免拉伸）
- 所有 UI 元素使用锚点确保在不同分辨率下位置正确

### 验收标准
- [ ] 在 `Assets/AssetRaw/UI/GamePlay/` 创建 GamePlayView.prefab
- [ ] 添加 Canvas（Screen Space - Overlay, Sort Order: 100）
- [ ] 添加 Canvas Scaler（Scale With Screen Size, 1920x1080, Match 0.5）
- [ ] 添加 ScorePanel（左上角锚点: 0, 0）
  - [ ] 添加 TextMeshPro 组件，命名为 "ScoreText"
  - [ ] 设置初始文本为 "Score: 0"
  - [ ] 设置字号为 36，颜色为白色
  - [ ] 可选：添加半透明黑色背景
- [ ] 添加 PauseButton（右上角锚点: 1, 0）
  - [ ] 添加 Button 组件，命名为 "PauseButton"
  - [ ] 添加 Text 或 Image 子对象显示状态
  - [ ] 设置适当尺寸（如 80x80）
- [ ] 添加 ReferenceCollector 组件到根节点
  - [ ] 注册 "ScoreText" → ScorePanel 下的 TextMeshPro 组件
  - [ ] 注册 "PauseButton" → PauseButton
- [ ] 添加 UIView 脚本到根节点
- [ ] 在编辑器中预览，验证 UI 在不同 Game 窗口尺寸下显示正常
- [ ] 验证暂停按钮可点击且响应正确

---

## 任务 5：集成 ScoreModel 到 ModelManager
**优先级**: 中
**预估**: 0.5h
**依赖**: 任务 1

### 验收标准
- [ ] 在 `GameLogicEntry.cs` 添加 `RegisterModels()` 方法
- [ ] 创建并注册 `ScoreModel` 实例到 `ModelManager`
- [ ] 在 `GamePlayProcedure.OnEnter()` 调用 `RegisterModels()`
- [ ] 在 `GamePlayProcedure.OnLeave()` 调用 `UnregisterModels()` 或通过 `ShutdownScope` 清理
- [ ] 添加日志验证 Model 注册成功

---

## 任务 6：集成 GamePlayUI 到 GamePlayProcedure
**优先级**: 中
**预估**: 1h
**依赖**: 任务 3, 任务 4, 任务 5

### 验收标准
- [ ] 在 `GamePlayProcedure` 添加 `IUIManager` 字段
- [ ] 在 `OnEnterAsync()` 场景加载完成后调用 `OpenGamePlayUI()`
- [ ] 实现 `OpenGamePlayUI()` 使用 `IUIManager.OpenWindowAsync<GamePlayView, GamePlayController>()`
- [ ] 定义常量 `const string GamePlayUIPath = "UI/GamePlay/GamePlayView";`
- [ ] 在 `OnLeave()` 调用 `IUIManager.CloseWindowAsync("GamePlayView")`
- [ ] 添加错误处理和日志
- [ ] 测试进入/退出流程无报错

---

## 任务 7：实现暂停功能
**优先级**: 中
**预估**: 0.5h
**依赖**: 任务 3

### 验收标准
- [ ] 在 `GamePlayController` 实现 `TogglePause()` 方法
- [ ] 暂停时设置 `Time.timeScale = 0`
- [ ] 继续时设置 `Time.timeScale = 1`
- [ ] 更新 `GamePlayView` 按钮状态（文本或图标）
- [ ] 添加日志记录暂停/继续操作
- [ ] 测试暂停后 UI 仍可交互

---

## 任务 8：实现积分显示功能
**优先级**: 中
**预估**: 0.5h
**依赖**: 任务 2, 任务 3, 任务 5

### 验收标准
- [ ] 在 `GamePlayController.OnEnter()` 绑定 `IScoreModel.Score` 属性到 `GamePlayView.UpdateScore()`
- [ ] 使用 `UIView.BindProperty()` 或手动订阅 `PropertyChanged` 事件
- [ ] `GamePlayView.UpdateScore()` 更新 `_scoreText.text` 显示
- [ ] 初始显示积分为 0
- [ ] 格式化积分显示（如 "Score: 0" 或 "0分"）
- [ ] 测试积分变化时 UI 自动更新

---

## 任务 9：添加积分增加逻辑（占位）
**优先级**: 低
**预估**: 0.5h
**依赖**: 任务 5

### 验收标准
- [ ] 在 `EnemyEntity` 或子弹命中逻辑中调用 `IScoreModel.AddScore()`
- [ ] 添加测试积分增加逻辑（如击杀敌人 +10 分）
- [ ] 验证积分正确累加
- [ ] 注释说明后续需替换为真实游戏逻辑

---

## 任务 10：整体测试与优化
**优先级**: 低
**预估**: 1h
**依赖**: 所有前置任务

### 验收标准
- [ ] 完整流程测试：进入玩法 → UI 显示 → 暂停/继续 → 积分更新 → 退出玩法
- [ ] 验证无内存泄漏（无残留 UI、Model）
- [ ] 验证日志输出正常
- [ ] 验证不同分辨率下 UI 显示正常
- [ ] 代码 Review 并添加必要注释
- [ ] 更新相关文档（如有需要）

---

## 并行工作建议

- **阶段 1**（任务 1-3）：可并行开发 Model、View、Controller
- **阶段 2**（任务 4）：需等待任务 2 完成，独立制作预制体
- **阶段 3**（任务 5-8）：串行集成，逐步验证功能
- **阶段 4**（任务 9-10）：可选优化和测试

## 总预估时间

约 7.5 小时（不含任务 9-10 的可选部分）
