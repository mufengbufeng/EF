## ADDED Requirements

### Requirement: 定时自动恢复体力
当体力未满时，系统 SHALL 每隔固定时间间隔（默认 6 分钟）自动恢复 1 点体力。

#### Scenario: 体力未满时定时恢复
- **WHEN** 当前体力为 7，上限为 10，恢复间隔为 360 秒
- **THEN** 经过 360 秒后，体力自动变为 8，并持久化存档

#### Scenario: 体力已满时不恢复
- **WHEN** 当前体力等于上限
- **THEN** 定时器暂停，不触发恢复

#### Scenario: 恢复到上限时停止
- **WHEN** 当前体力为 9，上限为 10，恢复 1 点后达到上限
- **THEN** 体力变为 10，定时器暂停

### Requirement: 离线补偿
系统 SHALL 在游戏启动加载存档时，根据上次恢复时间戳与当前时间的差值，计算离线期间应恢复的体力。

#### Scenario: 离线 30 分钟恢复 5 点
- **WHEN** 关闭游戏时体力为 3/10，恢复间隔 360 秒，离线 1800 秒
- **THEN** 重新打开游戏后体力为 8（恢复 5 点，不超过上限）

#### Scenario: 离线时间不足以恢复 1 点
- **WHEN** 关闭游戏时体力为 5/10，离线 200 秒（不足 360 秒）
- **THEN** 体力仍为 5，但已积累 200 秒恢复进度

#### Scenario: 体力已满离线无变化
- **WHEN** 关闭游戏时体力为 10/10
- **THEN** 重新打开后体力仍为 10，不触发恢复逻辑

### Requirement: 恢复状态查询
`IEnergyModule` SHALL 提供恢复状态查询能力，包括恢复间隔、距下次恢复剩余时间、是否正在恢复。

#### Scenario: 查询恢复进度
- **WHEN** 体力为 7/10，恢复间隔 360 秒，距上次恢复已过 120 秒
- **THEN** `TimeToNextRecovery` 返回约 240 秒，`IsRecovering` 返回 true

#### Scenario: 体力已满时查询
- **WHEN** 体力为 10/10
- **THEN** `IsRecovering` 返回 false，`TimeToNextRecovery` 返回 0

### Requirement: 持久化恢复时间戳
系统 SHALL 在存档数据中持久化上次恢复的时间戳，以支持离线补偿计算。

#### Scenario: 存档包含时间戳
- **WHEN** 体力发生变化（恢复或消耗）
- **THEN** 存档数据中包含 `lastRecoverTimestamp` 字段，值为 Unix 秒级时间戳

#### Scenario: 旧存档兼容
- **WHEN** 加载的存档没有 `lastRecoverTimestamp` 字段（旧版本存档）
- **THEN** 使用当前时间作为初始时间戳，不执行离线补偿

### Requirement: 消耗后恢复重启
当体力因消耗而不满时，系统 SHALL 自动重新启动定时恢复。

#### Scenario: 消耗后恢复继续
- **WHEN** 体力为 10/10（定时器暂停），消耗 1 点后变为 9/10
- **THEN** 定时器重新启动，开始倒计时
