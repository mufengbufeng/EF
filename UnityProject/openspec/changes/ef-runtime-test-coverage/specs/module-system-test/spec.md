## ADDED Requirements

### Requirement: Register 注册服务
ModuleSystem SHALL 支持通过 Register<T>(instance) 注册服务实例到全局 scope。

#### Scenario: 注册并获取服务
- **WHEN** 调用 Register<ITest>(instance) 后调用 Get<ITest>()
- **THEN** 返回同一实例

#### Scenario: 注册重复类型默认失败
- **WHEN** 不带 replace 参数重复调用 Register<ITest>(instance2)
- **THEN** 抛出 InvalidOperationException，原实例不变

#### Scenario: 注册重复类型 replace 覆盖
- **WHEN** 调用 Register<ITest>(instance2, replace: true) 覆盖已有注册
- **THEN** Get<ITest>() 返回 instance2

### Requirement: Get 获取服务
ModuleSystem SHALL 支持通过 Get<T>() 和 TryGet<T>() 获取已注册服务。

#### Scenario: Get 获取已注册服务
- **WHEN** 已注册 ITest 后调用 Get<ITest>()
- **THEN** 返回注册的实例

#### Scenario: Get 未注册服务抛出异常
- **WHEN** 未注册 ITest 时调用 Get<ITest>()
- **THEN** 抛出 InvalidOperationException

#### Scenario: TryGet 未注册服务返回 false
- **WHEN** 未注册 ITest 时调用 TryGet<ITest>(out var result)
- **THEN** 返回 false，result 为 default

### Requirement: Unregister 注销服务
ModuleSystem SHALL 支持通过 Unregister<T>() 移除已注册服务。

#### Scenario: 注销已注册服务
- **WHEN** 调用 Unregister<ITest>()
- **THEN** Contains<ITest>() 返回 false，Get<ITest>() 抛出异常

#### Scenario: 注销时调用 IEFManager.Shutdown
- **WHEN** 注销的服务实现了 IEFManager
- **THEN** 该服务的 Shutdown() 方法被调用

### Requirement: Scope 隔离
ModuleSystem SHALL 支持 scope 隔离，ShutdownScope 只清理指定 scope 的服务。

#### Scenario: ShutdownScope 不影响其他 scope
- **WHEN** 在 scope A 和 scope B 各注册一个服务后调用 ShutdownScope("A")
- **THEN** scope A 的服务被清理，scope B 的服务不受影响

### Requirement: Update 批量更新
ModuleSystem SHALL 按 Update 顺序依次调用所有 IEFManager 的 Update 方法。

#### Scenario: Update 按注册顺序调用
- **WHEN** 注册 manager1 和 manager2 后调用 Update(1f, 1f)
- **THEN** 两个 manager 的 Update 都被调用

### Requirement: ShutdownAll 全量清理
ModuleSystem SHALL 通过 ShutdownAll 清理所有 scope 和所有注册的服务。

#### Scenario: ShutdownAll 后所有服务不可用
- **WHEN** 注册多个服务后调用 ShutdownAll()
- **THEN** ModuleCount 归零，所有 Get 调用抛出异常
