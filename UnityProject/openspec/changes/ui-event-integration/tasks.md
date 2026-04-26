## 1. ControllerEventBinder 扩展

- [x] 1.1 在 `ControllerEventBinder` 中添加 `BindEvent<T>(EventChannel<T> channel, Action<T> handler)` 重载，包含参数校验和 ObjectDisposedException 检查
- [x] 1.2 在 `UIController` 中验证新 BindEvent 重载可通过 `EventBinder` 属性正常访问

## 2. EventArgs 结构体定义

- [x] 2.1 创建 `EnergyChangedEvent` — 在 `Assets/GameScripts/HotFix/GameLogic/Energy/` 中，`[EventArgs] readonly struct`，包含 Current 和 Max 字段
- [x] 2.2 创建 `LevelProgressChangedEvent` — 在 `Assets/GameScripts/HotFix/GameLogic/Level/` 中，`[EventArgs] readonly struct`，包含 LevelId、KillCount、RequiredKills 字段
- [x] 2.3 创建 `LevelCompleteEvent` — 在 `Assets/GameScripts/HotFix/GameLogic/Level/` 中，`[EventArgs] readonly struct`，无字段（纯信号事件）

## 3. Module 接口变更

- [x] 3.1 从 `IEnergyModule` 移除 `event Action<int, int> OnEnergyChanged`
- [x] 3.2 从 `ILevelModule` 移除 `event Action<int, int, int> OnProgressChanged` 和 `event Action OnLevelComplete`
- [x] 3.3 `EnergyModule` 构造函数新增 `EventHub` 参数，内部 `RaiseEnergyChanged()` 改为 `EventHub.EnergyChangedEvent.Publish`
- [x] 3.4 `LevelModule` 构造函数新增 `EventHub` 参数，`RecordKill()` 中改为通过 EventHub 派发事件
- [x] 3.5 更新 `EnergyModule.Shutdown()` 移除 `OnEnergyChanged = null`
- [x] 3.6 更新 `LevelModule.Shutdown()` 移除事件清理代码

## 4. 创建方更新

- [x] 4.1 更新 `GameLogicEntry.Init()` — 确保先创建 EventHub，再创建 Module 时传入 EventHub 引用
- [x] 4.2 更新 Module 测试代码 — 构造函数参数变更适配

## 5. Controller 迁移

- [x] 5.1 迁移 `MainController` — 将 `_energyModule.OnEnergyChanged` 绑定改为 `EventBinder.BindEvent(GameLogicEntry.Event.EnergyChangedEvent, handler)`
- [x] 5.2 迁移 `GamePlayController` — 将 EnergyModule 和 LevelModule 的事件绑定改为 EventBinder.BindEvent(channel, handler)

## 6. Code Gen 与验证

- [x] 6.1 重新运行 Event Code Gen — 在 Unity 编辑器中 EF/Generate Event System，生成包含新 Channel 的 EventHub
- [ ] 6.2 验证编译通过 — 确保所有修改后无编译错误
- [ ] 6.3 验证 Controller 事件绑定 — 运行游戏，确认 Controller 能正确订阅和响应 EventChannel 事件
- [ ] 6.4 验证 Event Monitor 面板 — 确认新 Channel 在面板中可见且数据正确
