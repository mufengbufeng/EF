## Why

当前体力系统只有消耗和手动恢复，没有自动恢复机制。玩家用完 10 点体力后无法继续游戏，只能通过修改存档恢复。这在实际运营中是不可接受的——需要自动恢复来保证玩家留存和游戏体验。

## What Changes

- 在 `EnergyModule` 中增加基于时间的自动恢复逻辑：每隔固定间隔恢复 1 点体力，直到上限
- 持久化恢复时间戳，支持离线计算——关闭游戏后再次打开也能恢复对应体力
- `IEnergyModule` 接口增加查询恢复状态的能力（距离下次恢复的剩余时间等）
- MainView 显示恢复倒计时信息

## Capabilities

### New Capabilities
- `energy-auto-recovery`: 体力自动恢复机制，包括定时恢复、离线补偿、恢复状态查询

### Modified Capabilities

## Impact

- `IEnergyModule` 接口 — 新增恢复相关属性/方法（需保持向后兼容，不破坏现有调用方）
- `EnergyModule` 实现 — 核心修改，加入定时器和时间戳逻辑
- `MainView` / `MainController` — 展示倒计时信息
- `EnergySaveData` — 新增 `lastRecoverTimestamp` 字段
- 依赖 `ITimerManager`（已存在于 EF 框架）
- 单元测试需更新覆盖恢复逻辑
