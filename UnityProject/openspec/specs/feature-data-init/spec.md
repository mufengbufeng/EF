## Requirements

### Requirement: IFeature.OnSetup 接收配置数据
IFeature 接口 SHALL 增加 `void OnSetup(object data)` 方法。FeatureBase SHALL 提供空实现（不做任何操作）。OnSetup 在 AddFeature 流程中、OnInit 之前被调用。

#### Scenario: AddFeature 传入数据时 OnSetup 被调用
- **WHEN** 调用 `Features.AddFeature<MyFeature>(data)` 且 data 不为 null
- **THEN** Feature 的 OnSetup(data) 被调用，随后 OnInit() 被调用

#### Scenario: AddFeature 无数据时 OnSetup 传入 null
- **WHEN** 调用 `Features.AddFeature<MyFeature>()`（无参版本）
- **THEN** Feature 的 OnSetup(null) 被调用，随后 OnInit() 被调用

#### Scenario: FeatureBase 默认实现不抛异常
- **WHEN** Feature 继承 FeatureBase 且未重写 OnSetup
- **THEN** 调用 OnSetup(null) 或 OnSetup(data) 不抛出异常

### Requirement: FeatureBase<TData> 强类型数据基类
FeatureBase<TData> SHALL 继承 FeatureBase，其中 TData 为 class 约束。OnSetup(object data) 做类型检查，若 data 是 TData 类型则调用 OnSetup(TData data)。

#### Scenario: 强类型 OnSetup 接收匹配类型数据
- **WHEN** 调用 AddFeature<HealthFeature>(healthData) 且 healthData 类型为 HealthData
- **THEN** HealthFeature.OnSetup(HealthData data) 被调用

#### Scenario: 强类型 OnSetup 接收不匹配类型数据
- **WHEN** 调用 AddFeature<HealthFeature>(invalidData) 且 invalidData 类型不是 HealthData
- **THEN** HealthFeature.OnSetup(TData) 不被调用（静默忽略）

### Requirement: IFeatureContainer.AddFeature 支持数据参数
IFeatureContainer SHALL 增加 `T AddFeature<T>(object data) where T : IFeature, new()` 重载。FeatureContainer SHALL 在创建实例、SetEntity 之后、OnInit 之前调用 OnSetup(data)。

#### Scenario: 带数据的 AddFeature 完整流程
- **WHEN** 调用 `entity.Features.AddFeature<MyFeature>(myData)`
- **THEN** 执行顺序为：new MyFeature() → SetEntity → OnSetup(myData) → OnInit() → 返回实例

#### Scenario: 原有无参 AddFeature 不受影响
- **WHEN** 调用 `entity.Features.AddFeature<MyFeature>()`
- **THEN** 行为与扩展前一致，仅额外调用 OnSetup(null)

### Requirement: IFeatureContainer.SetupFeature 刷新已有 Feature 数据
IFeatureContainer SHALL 增加 `void SetupFeature<T>(object data) where T : IFeature` 方法，对已存在的 Feature 调用 OnSetup(data)。

#### Scenario: 对已注册的 Feature 刷新数据
- **WHEN** Feature 已通过 AddFeature 注册，调用 `entity.Features.SetupFeature<MyFeature>(newData)`
- **THEN** 该 Feature 的 OnSetup(newData) 被调用

#### Scenario: Feature 不存在时静默返回
- **WHEN** 调用 `entity.Features.SetupFeature<MyFeature>(data)` 但 MyFeature 未注册
- **THEN** 不抛出异常，静默返回
