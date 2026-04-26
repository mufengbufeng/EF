## MODIFIED Requirements

### Requirement: 体力变化通知方式
体力变化时系统 SHALL 通过 EventHub 的 EnergyChangedEvent Channel 派发事件，不再使用 IEnergyModule 的 C# event。

#### Scenario: 体力变化时派发 EnergyChangedEvent
- **WHEN** 体力因恢复、消耗或离线补偿发生变化
- **THEN** 通过 EventHub.EnergyChangedEvent.Publish 派发 EnergyChangedEvent（包含 Current、Max 字段）

#### Scenario: 外部系统订阅体力变化
- **WHEN** 任意系统通过 EventHub.EnergyChangedEvent.Subscribe 注册 handler
- **THEN** 体力变化时收到 EnergyChangedEvent 回调
