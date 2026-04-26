## ADDED Requirements

### Requirement: AddFeature 添加特性
FeatureContainer SHALL 支持通过 AddFeature<T>() 添加特性实例。

#### Scenario: 添加后可获取
- **WHEN** 调用 AddFeature<TestFeature>() 后调用 GetFeature<TestFeature>()
- **THEN** 返回非 null 的 TestFeature 实例

#### Scenario: 添加后 FeatureCount 增加
- **WHEN** 添加一个 Feature
- **THEN** FeatureCount 增加 1

### Requirement: AllowMultiple 多实例控制
FeatureContainer SHALL 根据 AllowMultipleAttribute 控制是否允许同一类型添加多个实例。

#### Scenario: 未标记 AllowMultiple 重复添加抛出异常
- **WHEN** 对未标记 [AllowMultiple] 的类型调用 AddFeature 两次
- **THEN** 第二次抛出 InvalidOperationException

#### Scenario: 标记 AllowMultiple 允许多实例
- **WHEN** 对标记 [AllowMultiple] 的类型调用 AddFeature 两次
- **THEN** 两个实例都存在，GetFeatures<T>() 返回 2 个

### Requirement: RemoveFeature 移除特性
FeatureContainer SHALL 支持通过 RemoveFeature<T>() 移除指定类型的特性。

#### Scenario: 移除后不可获取
- **WHEN** 调用 RemoveFeature<TestFeature>()
- **THEN** HasFeature<TestFeature>() 返回 false

### Requirement: SetFeatureEnabled 启用/禁用
FeatureContainer SHALL 支持通过 SetFeatureEnabled<T>(bool) 控制特性的启用状态。

#### Scenario: 禁用后 HasFeature 仍返回 true
- **WHEN** 调用 SetFeatureEnabled<TestFeature>(false)
- **THEN** HasFeature<TestFeature>() 仍返回 true，但 Update 中不调用该 Feature

### Requirement: RequireFeature 依赖检查
FeatureContainer SHALL 在添加带有 [RequireFeature] 标记的特性时检查依赖是否存在。

#### Scenario: 依赖存在时正常添加
- **WHEN** 先添加 DepFeature 后添加带 [RequireFeature(typeof(DepFeature))] 的 Feature
- **THEN** 添加成功

#### Scenario: 依赖缺失时抛出异常
- **WHEN** 未添加 DepFeature 时添加带 [RequireFeature(typeof(DepFeature))] 的 Feature
- **THEN** 抛出 InvalidOperationException

### Requirement: Update 批量更新
FeatureContainer SHALL 通过 Update 只调用 enabled 状态的 Feature。

#### Scenario: 禁用的 Feature 的 OnUpdate 不被调用
- **WHEN** SetFeatureEnabled<TestFeature>(false) 后调用 Update(1f, 1f)
- **THEN** TestFeature.OnUpdate 不被调用
