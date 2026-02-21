# game-pause Specification

## Purpose
提供游戏暂停功能，通过修改 Time.timeScale 实现，支持玩家暂停和继续游戏。

## Requirements

### Requirement: 游戏暂停实现

系统 SHALL 通过修改 `Time.timeScale` 实现游戏暂停和继续功能。

#### Scenario: 暂停游戏
- **GIVEN** 游戏正在运行（Time.timeScale = 1）
- **WHEN** 调用暂停方法时
- **THEN** 设置 `Time.timeScale = 0`
- **AND** 所有基于时间的物理、动画、Update 逻辑停止
- **AND** UI 使用 `Time.unscaledTime` 保持响应

#### Scenario: 继续游戏
- **GIVEN** 游戏已暂停（Time.timeScale = 0）
- **WHEN** 调用继续方法时
- **THEN** 设置 `Time.timeScale = 1`
- **AND** 游戏逻辑恢复正常运行
- **AND** 物理和动画从暂停点继续

#### Scenario: 切换暂停状态
- **WHEN** 调用 `TogglePause()` 方法时
- **THEN** 如果当前未暂停，则暂停游戏
- **AND** 如果当前已暂停，则继续游戏
- **AND** 更新 UI 按钮状态（暂停/继续）

---

### Requirement: UI 暂停交互

系统 SHALL 在暂停状态下保持 UI 可交互性。

#### Scenario: UI 使用 unscaledTime
- **GIVEN** 游戏已暂停（Time.timeScale = 0）
- **WHEN** 用户点击 UI 按钮时
- **THEN** 按钮点击事件正常触发
- **AND** UI 动画使用 `Time.unscaledDeltaTime` 继续播放
- **AND** UI 不受暂停影响

#### Scenario: 暂停按钮状态更新
- **GIVEN** GamePlayView 暂停按钮
- **WHEN** 游戏暂停时
- **THEN** 按钮文本更新为 "继续" 或显示播放图标
- **AND** 游戏继续时，按钮文本恢复为 "暂停" 或显示暂停图标

---

### Requirement: 暂停状态管理

系统 SHALL 维护当前暂停状态，避免重复操作。

#### Scenario: 防止重复暂停
- **GIVEN** 游戏已暂停（Time.timeScale = 0）
- **WHEN** 再次调用暂停方法时
- **THEN** 不执行任何操作
- **AND** Time.timeScale 保持为 0

#### Scenario: 防止重复继续
- **GIVEN** 游戏正在运行（Time.timeScale = 1）
- **WHEN** 再次调用继续方法时
- **THEN** 不执行任何操作
- **AND** Time.timeScale 保持为 1

---

### Requirement: 暂停与游戏逻辑

系统 SHALL 确保暂停不影响游戏状态完整性。

#### Scenario: 暂停时游戏状态保持
- **GIVEN** 游戏中有玩家、敌人、子弹等实体
- **WHEN** 游戏暂停时
- **THEN** 所有实体保持当前位置和状态
- **AND** 敌人生成器停止生成
- **AND** 玩家和敌人的 Update 逻辑停止执行
- **AND** 子弹移动停止

#### Scenario: 继续时游戏状态恢复
- **GIVEN** 游戏处于暂停状态
- **WHEN** 游戏继续时
- **THEN** 所有实体从暂停点恢复执行
- **AND** 敌人生成器恢复生成
- **AND** Update 逻辑正常执行
- **AND** 游戏状态无缝衔接

---

### Requirement: 暂停与音频

系统 SHALL 正确处理暂停状态下的音频播放。

#### Scenario: 背景音乐处理（可选）
- **GIVEN** 游戏正在播放背景音乐
- **WHEN** 游戏暂停时
- **THEN** 可选：暂停背景音乐
- **AND** 继续时恢复播放
- **AND** 或保持音乐播放（根据游戏设计）

#### Scenario: 音效播放不受影响
- **GIVEN** 游戏已暂停
- **WHEN** 用户点击 UI 按钮触发音效时
- **THEN** 音效正常播放
- **AND** 音效不受 Time.timeScale 影响

---

### Requirement: 暂停扩展性

系统 SHALL 为未来暂停菜单和功能预留扩展点。

#### Scenario: 暂停菜单接口（未来扩展）
- **WHEN** 后续添加暂停菜单时
- **THEN** 可在 `TogglePause()` 方法中添加打开暂停菜单逻辑
- **AND** 暂停菜单可包含设置、退出、重新开始等选项

#### Scenario: 强制暂停（未来扩展）
- **WHEN** 后续添加强制暂停（如失去焦点、网络断开）时
- **THEN** 可扩展 `TogglePause()` 为 `Pause(bool force)` 方法
- **AND** 强制暂停时显示不同提示
