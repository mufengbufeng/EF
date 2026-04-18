## Context

当前 `EnergyModule` 是一个纯消耗/恢复模块，没有时间维度的自动恢复。模块通过 `ISaveManager` 做本地 JSON 持久化，构造时加载存档数据。EF 框架已提供 `ITimerManager`（定时器）和 `ISaveManager`（存档），可直接复用。

现有存档结构 `EnergySaveData`：
```csharp
{ currentEnergy, maxEnergy }
```

需要在其中加入 `lastRecoverTimestamp`（上次恢复的服务器/本地时间戳），以支持离线补偿计算。

## Goals / Non-Goals

**Goals:**
- 每隔固定时间间隔自动恢复 1 点体力（默认 6 分钟）
- 支持离线补偿：重新打开游戏时根据经过时间计算应恢复的体力
- 接口层面暴露恢复进度信息（下次恢复剩余时间）
- 保持与现有 `TryConsume`/`Recover` 的兼容性

**Non-Goals:**
- 不做服务器时间同步（纯本地时间戳）
- 不做体力购买/道具恢复（那是其他功能）
- 不做体力上限随等级变化（超出本次范围）

## Decisions

### 1. 时间戳存储方式

**选择**：使用 `DateTimeOffset.UtcNow.ToUnixTimeSeconds()` 存储为 `long`。

**理由**：简单、跨平台一致、方便计算差值。不做服务器同步，本地时间足够。

### 2. 恢复驱动方式

**选择**：使用 `ITimerManager` 注册重复定时器 + 进入游戏时做离线补偿。

**理由**：
- EF 已有 `ITimerManager`，无需引入新机制
- 离线补偿在 `LoadOrCreateState()` 中用时间差计算，简单直接
- 备选方案是用 `Update()` 帧驱动，但定时器更节能且语义更清晰

### 3. 接口扩展策略

**选择**：在 `IEnergyModule` 上新增属性，不修改已有方法签名。

**新增**：
- `int RecoveryIntervalSeconds` — 恢复间隔（秒）
- `float TimeToNextRecovery` — 距下次恢复剩余秒数
- `bool IsRecovering` — 当前是否在恢复中（未满时为 true）

**理由**：纯增量扩展，不破坏任何现有调用方。

### 4. 恢复暂停条件

**选择**：体力已满时暂停定时器，`TryConsume` 后重新启动。

**理由**：避免不必要的定时器触发和存盘操作。`TryConsume` 导致体力不满时重新注册定时器即可。

## Risks / Trade-offs

- **[本地时间篡改]** → 玩家可改系统时间加速恢复。当前为单机游戏，可接受。未来如需防作弊需引入服务器时间校验。
- **[长时间离线导致大量计算]** → 离线补偿上限为 `maxEnergy - currentEnergy`，天然有上限保护。
- **[频繁存盘]** → 每次恢复 1 点就存盘一次，6 分钟一次的频率完全可接受。
