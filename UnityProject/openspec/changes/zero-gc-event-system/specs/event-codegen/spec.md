## ADDED Requirements

### Requirement: 扫描所有 [EventArgs] struct 并生成 EventHub

Code Gen 工具 SHALL 扫描项目所有程序集中被 `[EventArgs]` 标记的 `readonly struct` 类型，生成一个 `EventHub` partial 类，包含每个事件类型的 `EventChannel<T>` 自动属性和 `IEventChannel[]` 注册表数组。

#### Scenario: 扫描到多个事件类型
- **WHEN** 项目中有 `[EventArgs] struct SceneEnterEvent` 和 `[EventArgs] struct PlayerDamageEvent`
- **THEN** 生成的 EventHub 包含 `EventChannel<SceneEnterEvent> SceneEnterEvent` 和 `EventChannel<PlayerDamageEvent> PlayerDamageEvent` 两个属性

#### Scenario: 无事件类型时生成空 EventHub
- **WHEN** 项目中没有任何 `[EventArgs]` 标记的类型
- **THEN** 生成空的 EventHub 类，`_allChannels` 为空数组，不报错

### Requirement: 手动触发 Code Gen

系统 SHALL 提供 Unity 菜单项 `EF/Generate Event System`，点击后执行扫描和生成。

#### Scenario: 手动触发生成
- **WHEN** 用户点击菜单 `EF/Generate Event System`
- **THEN** 扫描所有 `[EventArgs]` 类型，重新生成 EventHub 类文件，并在 Console 输出日志

### Requirement: 文件变化自动触发 Code Gen

系统 SHALL 通过 `AssetPostprocessor.OnPostprocessAllAssets` 监听 `.cs` 文件变化，当检测到包含 `[EventArgs]` 的文件被修改时自动触发重新生成。

#### Scenario: 新增事件文件后自动生成
- **WHEN** 用户创建或修改一个包含 `[EventArgs]` struct 的 `.cs` 文件
- **THEN** 自动触发 Code Gen，EventHub 被更新

#### Scenario: 非 EventArgs 文件变化不触发
- **WHEN** 用户修改一个不包含 `[EventArgs]` 的 `.cs` 文件
- **THEN** 不触发 Code Gen

### Requirement: 生成代码输出位置

生成的 EventHub 类文件 SHALL 输出到 `Assets/GameScripts/HotFix/GameLogic/Event/Generated/` 目录下。

#### Scenario: 输出目录不存在时自动创建
- **WHEN** Generated 目录不存在
- **THEN** Code Gen 自动创建目录并输出文件

### Requirement: 生成代码包含函数级别注释

生成的代码 SHALL 遵循项目约定，所有公共接口包含中文函数注释。

#### Scenario: 生成代码注释检查
- **WHEN** Code Gen 完成
- **THEN** 生成的 EventHub 类中所有 public 成员有 `/// <summary>` 注释
