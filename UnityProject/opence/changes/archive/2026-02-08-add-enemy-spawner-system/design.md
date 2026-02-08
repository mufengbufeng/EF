# 敌人生成系统设计文档

## 架构概览

敌人生成系统由两个核心能力组成：

1. **EnemySpawnerModule (enemy-spawner)**：负责敌人的生成调度和数量控制。
2. **EnemyEntity (enemy-behavior)**：负责单个敌人的行为逻辑（移动、停留、攻击）。

两者通过 `IEntityManager` 连接：Spawner 使用 `ShowEntityAsync` 创建敌人实体，EnemyEntity 实现 `IEntity` 接口定义行为。

## 模块职责划分

### EnemySpawnerModule

**职责**：
- 管理敌人生成的时机、频率和数量。
- 维护当前存活敌人的引用，防止超过最大数量限制。
- 提供配置接口，支持运行时调整生成参数。
- 在 ModuleSystem 的 Update 中定时触发生成逻辑。

**设计决策**：
- 实现 `IEFManager` 接口，注册到 GamePlayScope (1001)。
- 使用计时器（累加 elapseSeconds）控制生成间隔。
- 通过 `IEntityManager.ShowEntityAsync` 创建敌人实体。
- 监听敌人销毁事件（通过回调或轮询检查）以更新存活数量。

**关键方法**：
```csharp
void Configure(string enemyPrefabName, float spawnInterval, int maxEnemyCount);
void SetSpawnInterval(float interval);
void SetMaxEnemyCount(int maxCount);
void OnUpdate(float elapseSeconds, float realElapseSeconds); // 驱动生成逻辑
```

### EnemyEntity

**职责**：
- 实现敌人的移动逻辑（直线、曲线、停留）。
- 触发攻击行为（可为简单的定时触发或条件判定）。
- 管理敌人的生命周期（OnShow 初始化位置和状态，OnHide 回收）。

**设计决策**：
- 继承 `EntityBase`，复用实体生命周期管理。
- 在 `OnUpdate` 中实现移动和行为逻辑。
- 使用状态机或简单的枚举状态（Moving, Staying, Attacking）控制行为切换。
- 移动参数（速度、方向、停留时间）通过 `userData` 在 `OnShow` 时传入。

**关键方法**：
```csharp
void OnShow(object userData); // 初始化敌人位置、移动参数和行为状态
void OnUpdate(float elapseSeconds, float realElapseSeconds); // 执行移动、停留和攻击逻辑
void OnHide(bool isShutdown, object userData); // 清理状态，准备回收
```

## 数据流

1. **GamePlayProcedure.OnEnter** → 创建并注册 `EnemySpawnerModule` 到 ModuleSystem (Scope: 1001)。
2. **ModuleSystem.Update** → 调用 `EnemySpawnerModule.OnUpdate`。
3. **EnemySpawnerModule.OnUpdate** → 判断是否达到生成间隔和数量限制，调用 `IEntityManager.ShowEntityAsync`。
4. **IEntityManager** → 加载敌人预制体，从 EntityGroup 获取实例，调用 `EnemyEntity.OnShow`。
5. **EnemyEntity.OnShow** → 初始化位置、速度和行为状态。
6. **ModuleSystem.Update** → 驱动所有已显示的 `EnemyEntity.OnUpdate`。
7. **EnemyEntity.OnUpdate** → 执行移动逻辑，判断是否到达停留位置，触发攻击。
8. **GamePlayProcedure.OnLeave** → 调用 `ModuleSystem.ShutdownScope(1001)`，清理 EnemySpawnerModule 和所有敌人实体。

## 配置与扩展性

### 生成配置

初期使用代码配置，后续可扩展为 ScriptableObject 或配置表：

```csharp
public class EnemySpawnConfig
{
    public string EnemyPrefabName;
    public float SpawnInterval;     // 生成间隔（秒）
    public int MaxEnemyCount;       // 同屏最大数量
    public Vector3 SpawnPosition;   // 生成位置（默认屏幕上方随机）
}
```

### 行为配置

敌人行为参数通过 `userData` 传递：

```csharp
public class EnemyBehaviorData
{
    public float MoveSpeed;         // 移动速度
    public Vector3 MoveDirection;   // 移动方向
    public float StayDuration;      // 停留时长
    public Vector3 StayPosition;    // 停留位置
    public float AttackInterval;    // 攻击间隔
}
```

### 扩展点

1. **多种敌人类型**：通过不同的 EnemyEntity 子类实现（如 `EnemyPlaneEntity`, `EnemyBossEntity`）。
2. **波次生成**：在 EnemySpawnerModule 中增加波次配置（如每波敌人数量、间隔时间）。
3. **路径系统**：引入路径组件（PathComponent），敌人沿预定义路径移动。
4. **攻击多样化**：抽象攻击行为为独立组件（AttackComponent），支持不同攻击模式。

## 性能优化策略

1. **对象池复用**：所有敌人实体通过 EntityGroup 的对象池管理，避免频繁创建销毁。
2. **数量限制**：通过 `MaxEnemyCount` 限制同屏敌人数量，防止性能下降。
3. **空间分区**：若敌人数量增加，可引入空间分区（如四叉树）优化碰撞检测。
4. **异步加载**：敌人预制体使用 `ShowEntityAsync` 异步加载，避免阻塞主线程。

## 测试策略

1. **单元测试**：验证 EnemySpawnerModule 的生成间隔和数量限制逻辑。
2. **集成测试**：验证敌人实体的生命周期（OnShow → OnUpdate → OnHide → OnRecycle）。
3. **性能测试**：测试同屏最大敌人数量下的帧率表现。
4. **流程测试**：验证退出 GamePlayProcedure 时敌人模块和实体的清理是否完整。
