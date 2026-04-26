## ADDED Requirements

### Requirement: Register 注册 Model
ModelManager SHALL 支持 Register<TModel>() 注册 Model 实例并自动初始化。

#### Scenario: 注册后可获取
- **WHEN** 调用 Register<TestModel>() 后调用 GetModel<TestModel>()
- **THEN** 返回非 null 的 TestModel 实例

#### Scenario: 重复注册抛出异常
- **WHEN** 对同一 TModel 调用 Register 两次
- **THEN** 第二次抛出 InvalidOperationException

### Requirement: Get 通过 Data 类型获取
ModelManager SHALL 支持 Get<TData>() 通过数据类型反向查找 Model。

#### Scenario: 通过 Data 类型获取数据
- **WHEN** 注册 ModelBase<TestData> 后调用 Get<TestData>()
- **THEN** 返回 TestData 实例

### Requirement: Unregister 注销 Model
ModelManager SHALL 支持 Unregister<TModel>() 注销并释放 Model。

#### Scenario: 注销后不可获取
- **WHEN** 调用 Unregister<TestModel>()
- **THEN** HasModel<TestModel>() 返回 false

### Requirement: ModelCount 计数
ModelManager SHALL 通过 ModelCount 返回当前注册的 Model 数量。

#### Scenario: 注册和注销影响计数
- **WHEN** 注册 3 个 Model 后注销 1 个
- **THEN** ModelCount 为 2

### Requirement: Shutdown 清理
ModelManager SHALL 通过 Shutdown 清理所有注册的 Model。

#### Scenario: Shutdown 后 ModelCount 归零
- **WHEN** 调用 Shutdown()
- **THEN** ModelCount 归零，所有 Model 的 OnShutdown 被调用
