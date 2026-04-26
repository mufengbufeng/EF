## Context

当前 EF Event 系统已完成零 GC 重构（zero-gc-event-system），提供 `EventChannel<T>` + `EventHub` + Code Gen 架构。但游戏模块（EnergyModule、LevelModule）仍使用传统 C# event（`event Action<T>`）派发事件，Controller 通过 `ControllerEventBinder.BindEvent<THandler>(add, remove, handler)` 绑定。

问题：
1. Module 的 C# event 是游戏级广播，但只有直接持有 Module 引用的系统才能订阅
2. Controller 缺少便捷的 EventChannel 订阅方式，需要手动管理 Subscribe/Unsubscribe
3. 模块事件无法在 Event Monitor 面板中观察

## Goals / Non-Goals

**Goals:**
- ControllerEventBinder 支持 `BindEvent<T>(EventChannel<T>, Action<T>)` 一行绑定 EventChannel 事件
- 将 EnergyModule 和 LevelModule 的事件迁移到 EventHub，实现集中管理和可视化
- OnExit 时自动清理所有 EventChannel 订阅，无需手动 Unsubscribe

**Non-Goals:**
- 不迁移 View → Controller 的本地 C# 事件（1:1 通信，不是广播）
- 不迁移 INotifyPropertyChanged（Model 响应式绑定，独立机制）
- 不改变 UHubComponent 的 UnityEvent 绑定

## Decisions

### 1. ControllerEventBinder 使用闭包存储 EventChannel 订阅

**选择**：在现有 `EventSubscription` 列表中新增 `Unsubscribe` 闭包

**备选**：
- (a) 泛型 `ChannelSubscription<T>` 结构体 + 接口装箱 → 同样分配，更复杂
- (b) 独立 `List<object>` 存储类型化订阅 → 同样分配，增加维护成本

**理由**：每次 BindEvent 只分配一次闭包（~32B），发生在 OnEnter 冷路径。Publish 热路径零 GC 由 EventChannel 保证，与绑定分配无关。保持与现有代码一致的模式最简单。

### 2. Module 接口移除 C# event，改为纯状态 + EventHub 派发

**选择**：`IEnergyModule` 和 `ILevelModule` 接口中删除 `event` 成员，Module 实现内部通过 `GameLogicEntry.Event` 派发

**备选**：
- (a) 保留 C# event 同时新增 EventHub 派发（双写） → 维护负担，行为不一致
- (b) Module 不改，只让 Controller 用静态 EventBinder 订阅 → 错过集中管理收益

**理由**：单一数据流原则。事件只通过 EventHub 派发，Module 接口只保留状态查询和方法调用。如果未来需要直接监听 Module 变化，可以订阅 EventHub。

### 3. EventArgs 定义位置跟随所属模块

**选择**：事件 struct 定义在各自模块目录中（`Energy/EnergyChangedEvent.cs`、`Level/LevelProgressChangedEvent.cs`）

**理由**：与现有 SceneEnterEvent 模式一致（定义在使用处）。Code Gen 会自动扫描所有程序集中的 `[EventArgs]` 标记。

### 4. Module 获取 EventHub 引用的方式

**选择**：Module 构造函数注入 EventHub

**备选**：
- (a) 静态访问 `GameLogicEntry.Event` → Module 对 GameLogicEntry 的耦合
- (b) ModuleSystem.Get<EventHub>() → 可行但需要查找

**理由**：构造函数注入最清晰，Module 在创建时就获得 EventHub 引用，不依赖静态状态或运行时查找。

## Risks / Trade-offs

- **[接口破坏] IEnergyModule / ILevelModule 移除 event 成员** → 所有引用方（Controller、测试）需要同步迁移，需一次性完成
- **[Module 构造函数变更] EnergyModule/LevelModule 新增 EventHub 参数** → GameLogicEntry 或创建方需传入 EventHub
- **[时序依赖] Module 派发事件需要 EventHub 先创建** → GameLogicEntry.Init 中 EventHub 必须在 Module 之前创建（当前已是如此）
