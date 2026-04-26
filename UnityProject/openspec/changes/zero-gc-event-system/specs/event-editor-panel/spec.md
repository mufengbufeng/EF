## ADDED Requirements

### Requirement: Event System Monitor 编辑器窗口

系统 SHALL 提供一个 Unity Editor 窗口（`EFEventMonitorWindow`），可通过菜单 `Window/EF/Event Monitor` 打开，实时展示所有事件 channel 的状态。

#### Scenario: 打开 Event Monitor
- **WHEN** 用户点击菜单 `Window/EF/Event Monitor`
- **THEN** 打开一个 EditorWindow，显示所有已注册的事件 channel 列表

### Requirement: 展示事件 channel 列表

窗口 SHALL 以表格形式展示每个事件 channel 的：事件名称、handler 数量、待分发（pending）队列深度、活跃状态。

#### Scenario: 显示多个 channel 信息
- **WHEN** EventHub 注册了 SceneEnterEvent（2 个 handler、0 pending）和 PlayerDamageEvent（0 个 handler、3 pending）
- **THEN** 窗口表格显示两行数据，handler 和 pending 数量正确

#### Scenario: 运行时实时刷新
- **WHEN** 游戏运行中，有新事件被 Enqueue
- **THEN** 窗口的 pending 列数字实时更新（通过 EditorApplication.update 或定时刷新）

### Requirement: 展示 handler 详细信息

用户 SHALL 能在窗口中展开某个事件 channel，查看其所有 handler 的目标方法名称（`ClassName.MethodName` 格式）。

#### Scenario: 展开 channel 查看 handler 列表
- **WHEN** 用户点击某个事件 channel 行
- **THEN** 展开显示该 channel 所有 handler 的 `TargetType.MethodName` 字符串

### Requirement: 无事件系统时的空状态提示

当 EventHub 未初始化（编辑器模式/未进入 Play）时，窗口 SHALL 显示提示信息而非空白。

#### Scenario: 非 Play 模式下打开窗口
- **WHEN** 游戏未运行（未进入 Play Mode）
- **THEN** 窗口显示 "事件系统在运行时初始化，请进入 Play Mode 查看" 提示
