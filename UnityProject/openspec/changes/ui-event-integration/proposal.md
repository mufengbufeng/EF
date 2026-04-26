## Why

游戏模块（EnergyModule、LevelModule）通过 C# event 暴露事件，Controller 直接引用 Module 并手动绑定/解绑。这些事件本质上是游戏级广播，应该通过 EventHub 集中管理以获得零 GC 派发、Editor 可视化监控、以及任意系统可订阅的能力。同时 Controller 缺少便捷的 EventChannel 订阅入口，需要手动管理生命周期。

## What Changes

- **ControllerEventBinder 新增 EventChannel\<T\> 绑定支持**：添加 `BindEvent<T>(EventChannel<T>, Action<T>)` 重载，Controller 可一行代码订阅 EventChannel 事件并在 OnExit 自动清理
- **新增 [EventArgs] 事件结构体**：`EnergyChangedEvent`、`LevelProgressChangedEvent`、`LevelCompleteEvent`
- **BREAKING: IEnergyModule 移除 OnEnergyChanged 事件**：EnergyModule 改为通过 EventHub.Publish 派发
- **BREAKING: ILevelModule 移除 OnProgressChanged / OnLevelComplete 事件**：LevelModule 改为通过 EventHub.Publish 派发
- **Controllers 迁移**：MainController、GamePlayController 改用 `EventBinder.BindEvent(channel, handler)` 订阅模块事件
- **重新运行 Event Code Gen**：生成包含新 Channel 的 EventHub

## Capabilities

### New Capabilities
- `event-channel-binding`: ControllerEventBinder 支持 EventChannel\<T\> 订阅，OnExit 时自动 Unsubscribe

### Modified Capabilities
- `energy-auto-recovery`: IEnergyModule 事件通知方式从 C# event 变更为 EventHub（行为不变，API 变更）

## Impact

- **接口变更**：`IEnergyModule`、`ILevelModule` 移除 C# event 成员，所有引用方需迁移
- **Controller 迁移**：`MainController`、`GamePlayController` 中的模块事件绑定方式改变
- **Code Gen 输出**：EventHub.Generated.cs 新增 3 个 Channel
- **依赖**：需要 EF Event 系统（已完成 zero-gc-event-system 变更）
