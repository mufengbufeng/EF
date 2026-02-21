# gameplay-ui Specification

## Purpose
提供游戏玩法的用户界面层，负责显示积分和暂停按钮，并处理用户交互。

## Requirements

### Requirement: GamePlayView 视图组件

系统 SHALL 提供 `GamePlayView` 类，继承 `UIView`，负责 UI 显示和组件绑定。

#### Scenario: 初始化视图
- **WHEN** `GamePlayView` 被实例化时
- **THEN** 调用 `OnInitialize()` 方法
- **AND** 初始化 `UHubComponent` 实现自动组件绑定
- **AND** 识别并绑定 `ReferenceCollector` 中的组件

#### Scenario: 绑定积分显示组件
- **GIVEN** `GamePlayView.prefab` 包含名为 "ScoreText" 的 Text 组件
- **WHEN** `OnInitialize()` 执行时
- **THEN** `_scoreText` 字段自动绑定到 "ScoreText" 组件
- **AND** 绑定通过 UHub 自动完成

#### Scenario: 绑定暂停按钮组件
- **GIVEN** `GamePlayView.prefab` 包含名为 "PauseButton" 的 Button 组件
- **WHEN** `OnInitialize()` 执行时
- **THEN** `_pauseButton` 字段自动绑定到 "PauseButton" 组件
- **AND** 绑定通过 UHub 自动完成

#### Scenario: 绑定按钮点击事件
- **WHEN** 调用 `OnBindings()` 方法时
- **THEN** 通过 `BindEvent(_pauseButton.onClick, OnPauseButtonClicked)` 绑定点击事件
- **AND** 点击按钮时触发 `OnPauseClicked` 事件
- **AND** 事件订阅在 UI 释放时自动清理

#### Scenario: 更新积分显示
- **WHEN** 调用 `UpdateScore(int score)` 方法时
- **THEN** `_scoreText.text` 更新为格式化的积分字符串
- **AND** 格式为 "Score: {score}" 或类似可读格式

#### Scenario: 更新暂停按钮状态
- **WHEN** 调用 `SetPauseState(bool paused)` 方法时
- **THEN** 如果 `paused` 为 true，按钮显示 "继续" 或类似提示
- **AND** 如果 `paused` 为 false，按钮显示 "暂停" 或类似提示
- **AND** 可选：切换按钮图标或颜色

#### Scenario: 释放视图资源
- **WHEN** 调用 `OnRelease()` 方法时
- **THEN** 清理 `OnPauseClicked` 事件订阅
- **AND** 调用基类 `OnRelease()` 清理 UHub 和绑定
- **AND** 无内存泄漏

---

### Requirement: GamePlayController 控制逻辑

系统 SHALL 提供 `GamePlayController` 类，继承 `UIController`，负责 UI 逻辑控制和模型绑定。

#### Scenario: 初始化控制器
- **WHEN** `GamePlayController` 被实例化时
- **THEN** 调用 `OnInitialize()` 方法
- **AND** 通过 `GetView<GamePlayView>()` 获取强类型视图引用
- **AND** 从 `ModelManager.Get<IScoreModel>()` 获取积分模型

#### Scenario: 进入 UI 界面
- **WHEN** UI 被打开并调用 `OnEnter(object userData)` 时
- **THEN** 订阅 `GamePlayView.OnPauseClicked` 事件
- **AND** 绑定 `IScoreModel.Score` 属性到 `GamePlayView.UpdateScore()`
- **AND** 初始化 UI 显示当前积分为 0

#### Scenario: 处理暂停按钮点击
- **WHEN** 用户点击暂停按钮时
- **THEN** 触发 `HandlePauseClicked()` 方法
- **AND** 调用 `TogglePause()` 切换暂停状态
- **AND** 更新 `GamePlayView` 按钮状态

#### Scenario: 切换暂停状态
- **WHEN** 调用 `TogglePause()` 方法时
- **THEN** 如果当前未暂停，设置 `Time.timeScale = 0` 暂停游戏
- **AND** 如果当前已暂停，设置 `Time.timeScale = 1` 继续游戏
- **AND** 更新 `GamePlayView` 按钮状态（暂停/继续）
- **AND** 记录日志

#### Scenario: 绑定积分数据模型
- **GIVEN** `IScoreModel` 实现 `INotifyPropertyChanged`
- **WHEN** 调用 `BindProperty(scoreModel, m => m.Score, UpdateScore)` 时
- **THEN** 当 `Score` 属性变化时自动调用 `UpdateScore(int)`
- **AND** `GamePlayView` 积分显示自动更新
- **AND** 绑定在 UI 释放时自动清理

#### Scenario: 退出 UI 界面
- **WHEN** 调用 `OnExit()` 方法时
- **THEN** 取消订阅 `GamePlayView.OnPauseClicked` 事件
- **AND** 清理积分数据绑定
- **AND** 调用基类 `OnExit()`

---

### Requirement: GamePlayView.prefab 预制体结构

系统 SHALL 提供 `GamePlayView.prefab` 预制体，包含积分显示和暂停按钮。

#### Scenario: 预制体基本结构
- **GIVEN** `GamePlayView.prefab` 位于 `Assets/AssetRaw/UI/GamePlay/`
- **WHEN** 加载预制体时
- **THEN** 包含 Canvas 节点（Screen Space - Overlay）
- **AND** 包含 ScorePanel 子节点（左上角）
- **AND** 包含 PauseButton 子节点（右上角）

#### Scenario: 积分显示区域
- **GIVEN** ScorePanel 子节点
- **WHEN** 查看其子对象时
- **THEN** 包含 Text 组件（或 TextMeshPro）
- **AND** 组件命名为 "ScoreText"
- **AND** 注册到 ReferenceCollector

#### Scenario: 暂停按钮
- **GIVEN** PauseButton 子节点
- **WHEN** 查看其组件时
- **THEN** 包含 Button 组件
- **AND** 组件命名为 "PauseButton"
- **AND** 注册到 ReferenceCollector
- **AND** 可选：包含 Image 或 Text 显示状态

#### Scenario: ReferenceCollector 配置
- **GIVEN** `GamePlayView.prefab` 根节点
- **WHEN** 查看 ReferenceCollector 组件时
- **THEN** 包含 "ScoreText" 引用指向积分文本组件
- **AND** 包含 "PauseButton" 引用指向暂停按钮组件

---

### Requirement: GamePlayUI 集成到 GamePlayProcedure

系统 SHALL 在 `GamePlayProcedure` 中集成 GamePlayUI，实现自动打开和关闭。

#### Scenario: 进入玩法流程时打开 UI
- **GIVEN** GamePlayProcedure 进入玩法流程
- **AND** 游戏场景已加载完成
- **WHEN** 调用 `OpenGamePlayUI()` 时
- **THEN** 通过 `IUIManager.OpenWindowAsync<GamePlayView, GamePlayController>()` 打开 UI
- **AND** 传递预制体路径 "UI/GamePlay/GamePlayView"
- **AND** UI 显示在 Normal 层级
- **AND** 记录日志

#### Scenario: 退出玩法流程时关闭 UI
- **GIVEN** GamePlayProcedure 退出玩法流程
- **WHEN** 调用 `OnLeave()` 时
- **THEN** 通过 `IUIManager.CloseWindowAsync("GamePlayView")` 关闭 UI
- **AND** UI 资源被释放或缓存
- **AND** 无残留 UI 对象

#### Scenario: UI 加载错误处理
- **GIVEN** GamePlayUI 预制体路径错误或加载失败
- **WHEN** `OpenWindowAsync()` 抛出异常时
- **THEN** 捕获异常并记录错误日志
- **AND** 不影响 GamePlayProcedure 继续执行
- **AND** 可选：显示错误提示

---

### Requirement: GamePlayUI 生命周期管理

系统 SHALL 正确管理 GamePlayUI 的生命周期，避免内存泄漏。

#### Scenario: UI 单实例模式
- **GIVEN** GamePlayUI 已打开
- **WHEN** 再次调用 `OpenWindowAsync("GamePlayView")` 时
- **THEN** 不创建新实例
- **AND** 刷新已存在的 UI（调用 `OnRefresh()`）

#### Scenario: UI 缓存策略
- **GIVEN** GamePlayUI 关闭
- **WHEN** 关闭时启用缓存策略时
- **THEN** UI 实例不被销毁
- **AND** 下次打开时复用实例

#### Scenario: UI 资源释放
- **GIVEN** GamePlayUI 不使用缓存或被强制销毁
- **WHEN** 调用 `InternalRelease()` 时
- **THEN** 清理所有事件绑定（UHub）
- **AND** 清理数据绑定
- **AND** 释放组件引用
- **AND** 无内存泄漏

---

### Requirement: GamePlayUI 响应式布局

系统 SHALL 支持 UI 在不同分辨率下正确显示。

#### Scenario: Canvas Scaler 配置
- **GIVEN** `GamePlayView.prefab` 包含 Canvas
- **WHEN** 查看 Canvas Scaler 组件时
- **THEN** 设置为 "Scale With Screen Size"
- **AND** 参考分辨率匹配游戏目标分辨率（如 1920x1080）
- **AND** 匹配模式为 0.5（平衡缩放）

#### Scenario: UI 元素锚点
- **GIVEN** ScorePanel 和 PauseButton
- **WHEN** 查看其 RectTransform 锚点时
- **THEN** ScorePanel 锚点在左上角 (0, 1)
- **AND** PauseButton 锚点在右上角 (1, 1)
- **AND** 在不同分辨率下位置保持正确
