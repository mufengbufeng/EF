# score-model Specification

## Purpose
提供游戏积分数据的统一管理，支持 UI 显示和游戏逻辑访问积分数据。

## Requirements

### Requirement: ScoreModel 数据模型

系统 SHALL 提供 `IScoreModel` 接口和 `ScoreModel` 实现，用于管理游戏积分数据。

#### Scenario: 获取当前积分
- **WHEN** 调用 `IScoreModel.Score` 属性时
- **THEN** 返回当前积分值（int 类型）
- **AND** 默认值为 0

#### Scenario: 增加积分
- **WHEN** 调用 `IScoreModel.AddScore(int points)` 时
- **THEN** 将 `points` 累加到当前积分
- **AND** 触发 `PropertyChanged` 事件通知订阅者
- **AND** 支持正数和负数（扣除积分）

#### Scenario: 重置积分
- **WHEN** 调用 `IScoreModel.ResetScore()` 时
- **THEN** 将积分重置为 0
- **AND** 触发 `PropertyChanged` 事件

#### Scenario: 数据绑定支持
- **GIVEN** `ScoreModel` 继承 `ModelBase<IScoreModel>`
- **WHEN** `Score` 属性发生变化时
- **THEN** 自动触发 `INotifyPropertyChanged.PropertyChanged` 事件
- **AND** UI 可以绑定属性实现自动更新

---

### Requirement: ScoreModel 注册到 ModelManager

系统 SHALL 将 `ScoreModel` 注册到 EF 框架的 `ModelManager`，供全局访问。

#### Scenario: 注册 ScoreModel
- **WHEN** 调用 `ModelManager.Register<IScoreModel>(scoreModel)` 时
- **THEN** ScoreModel 被添加到 ModelManager
- **AND** 可通过 `ModelManager.Get<IScoreModel>()` 获取

#### Scenario: 获取 ScoreModel
- **WHEN** 调用 `ModelManager.Get<IScoreModel>()` 时
- **THEN** 返回已注册的 ScoreModel 实例
- **AND** 如果未注册则抛出异常或返回 null

#### Scenario: 在 GamePlayProcedure 中注册
- **GIVEN** GamePlayProcedure 进入玩法流程
- **WHEN** 调用 `RegisterModels()` 方法时
- **THEN** 创建并注册 ScoreModel 到 ModelManager
- **AND** 积分初始化为 0

#### Scenario: 在 GamePlayProcedure 中清理
- **GIVEN** GamePlayProcedure 退出玩法流程
- **WHEN** 调用 `OnLeave()` 时
- **THEN** ScoreModel 从 ModelManager 注销
- **AND** 积分数据被清理

---

### Requirement: ScoreModel 线程安全

ScoreModel SHOULD 在主线程环境中使用，暂不需要跨线程访问。

#### Scenario: 主线程访问
- **GIVEN** 所有游戏逻辑和 UI 更新在主线程执行
- **WHEN** 在主线程访问 ScoreModel 时
- **THEN** 操作是线程安全的
- **AND** 不需要额外的锁机制

---

### Requirement: ScoreModel 扩展性

ScoreModel SHOULD 为后续功能扩展预留接口。

#### Scenario: 支持连击倍率（未来扩展）
- **WHEN** 后续添加连击系统时
- **THEN** 可在 ScoreModel 中添加 `ComboMultiplier` 属性
- **AND** `AddScore()` 可接受倍率参数计算最终积分

#### Scenario: 支持高分记录（未来扩展）
- **WHEN** 后续添加存档系统时
- **THEN** 可在 ScoreModel 中添加 `HighScore` 属性
- **AND** 提供保存和加载高分的方法
