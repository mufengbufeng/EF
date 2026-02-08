# enemy-spawner Specification

## Purpose
TBD - created by archiving change add-enemy-spawner-system. Update Purpose after archive.
## Requirements
### Requirement: 敌人生成器模块注册

系统 SHALL 提供 `IEnemySpawnerModule` 接口，继承自 `IEFManager`，支持通过 ModuleSystem 注册和管理。

#### Scenario: 注册到 GamePlay Scope

- **WHEN** GamePlayProcedure.OnEnter 调用 `ModuleSystem.Register(enemySpawnerModule, scope: 1001)`
- **THEN** 敌人生成器模块被注册到 GamePlayScope
- **AND** ModuleSystem.Update 会自动调用模块的 OnUpdate 方法

#### Scenario: 流程退出时自动清理

- **WHEN** GamePlayProcedure.OnLeave 调用 `ModuleSystem.ShutdownScope(1001)`
- **THEN** 敌人生成器模块被关闭并注销
- **AND** 所有由该模块生成的敌人实体被隐藏和回收

---

### Requirement: 配置敌人生成参数

系统 SHALL 提供 `Configure` 方法，允许设置敌人预制体名称、生成间隔和最大数量。

#### Scenario: 配置默认生成参数

- **GIVEN** 敌人生成器模块已创建
- **WHEN** 调用 `Configure(enemyPrefabName: "EnemyPlane", spawnInterval: 2f, maxEnemyCount: 10)`
- **THEN** 生成器使用指定的预制体名称加载敌人资源
- **AND** 每隔 2 秒尝试生成一个敌人
- **AND** 同屏最多存在 10 个敌人

#### Scenario: 运行时调整生成间隔

- **GIVEN** 敌人生成器已配置并开始生成
- **WHEN** 调用 `SetSpawnInterval(1f)`
- **THEN** 生成间隔立即更新为 1 秒
- **AND** 下一次生成按新的间隔触发

#### Scenario: 运行时调整最大数量

- **GIVEN** 当前存活敌人数量为 8
- **WHEN** 调用 `SetMaxEnemyCount(5)`
- **THEN** 不再生成新敌人，直到存活数量降至 5 以下
- **AND** 已存在的 8 个敌人不会被强制销毁

---

### Requirement: 定时生成敌人实体

系统 SHALL 在 OnUpdate 中累加时间，达到生成间隔且未超过最大数量时生成敌人。

#### Scenario: 达到生成间隔时生成敌人

- **GIVEN** 生成间隔为 2 秒，当前存活敌人数量为 3，最大数量为 10
- **WHEN** 累计经过 2 秒
- **THEN** 调用 `IEntityManager.ShowEntityAsync` 生成一个敌人
- **AND** 敌人实体在场景中显示
- **AND** 存活敌人数量增加到 4

#### Scenario: 达到最大数量时暂停生成

- **GIVEN** 生成间隔为 2 秒，当前存活敌人数量为 10，最大数量为 10
- **WHEN** 累计经过 2 秒
- **THEN** 不生成新敌人
- **AND** 等待存活敌人数量减少后再恢复生成

#### Scenario: 敌人被销毁后恢复生成

- **GIVEN** 当前存活敌人数量为 10（已达上限）
- **WHEN** 一个敌人被销毁（调用 HideEntity）
- **THEN** 存活敌人数量降至 9
- **AND** 下一次生成间隔到达时可以生成新敌人

---

### Requirement: 管理敌人生成位置

系统 SHALL 提供默认生成位置逻辑，支持在屏幕上方随机位置生成敌人。

#### Scenario: 默认在屏幕上方随机生成

- **GIVEN** 主摄像机视口宽度为 10 单位
- **WHEN** 生成敌人时未指定位置
- **THEN** 敌人在 X 轴 [-5, 5] 范围内随机生成
- **AND** Y 轴位置为屏幕上方外侧（如 Y = 6）

#### Scenario: 自定义生成位置

- **GIVEN** 调用 `Configure` 时传入 `spawnPosition: new Vector3(0, 5, 0)`
- **WHEN** 生成敌人
- **THEN** 敌人在指定位置 (0, 5, 0) 生成

---

### Requirement: 跟踪存活敌人数量

系统 SHALL 维护当前存活敌人的引用列表，实时更新数量。

#### Scenario: 生成敌人时增加计数

- **GIVEN** 当前存活敌人数量为 5
- **WHEN** 成功生成一个敌人
- **THEN** 存活敌人列表新增该实体引用
- **AND** 存活数量更新为 6

#### Scenario: 敌人被销毁时减少计数

- **GIVEN** 当前存活敌人数量为 6
- **WHEN** 一个敌人实体被隐藏（调用 HideEntity）
- **THEN** 从存活敌人列表中移除该引用
- **AND** 存活数量更新为 5

#### Scenario: 流程退出时清空列表

- **WHEN** ModuleSystem.ShutdownScope 被调用
- **THEN** 所有存活敌人引用被清空
- **AND** 存活数量重置为 0

