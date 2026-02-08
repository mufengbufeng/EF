# 敌人生成系统 - 快速参考

## 系统概览

**功能**：自动生成敌人飞机，控制移动、停留和攻击行为

**架构**：
```
GamePlayProcedure (1001)
  └─ EnemySpawnerModule
       └─ EnemyEntity (对象池)
```

## 关键参数

| 参数 | 值 | 位置 |
|------|-----|------|
| 生成间隔 | 2 秒 | `GamePlayProcedure.OnEnter` |
| 最大数量 | 10 个 | `GamePlayProcedure.OnEnter` |
| 移动速度 | 2 单位/秒 | `EnemySpawnerModule.SpawnEnemy` |
| 停留位置 | Y=2 | `EnemySpawnerModule.SpawnEnemy` |
| 停留时长 | 2 秒 | `EnemySpawnerModule.SpawnEnemy` |
| 攻击间隔 | 1.5 秒 | `EnemySpawnerModule.SpawnEnemy` |
| 销毁边界 | Y=-6 | `EnemyEntity.OnUpdate` |

## 核心文件

### 模块
- `IEnemySpawnerModule.cs` - 生成器接口
- `EnemySpawnerModule.cs` - 生成器实现（约 180 行）
- `EnemyBehaviorData.cs` - 行为配置数据

### 实体
- `EnemyEntity.cs` - 敌人实体（约 180 行）

### 集成
- `GamePlayProcedure.cs` - 流程集成（修改了 `OnEnter` 和 `OnLeave`）

### 资源
- `EnemyPlane.prefab` - 敌人预制体
- 资源地址：`"EnemyPlane"`（YooAsset）

## 代码位置

**模块和实体**：
```
Assets/GameScripts/HotFix/GameLogic/GamePlay/Enemy/
├── IEnemySpawnerModule.cs
├── EnemySpawnerModule.cs
├── EnemyBehaviorData.cs
└── EnemyEntity.cs
```

**流程集成**：
```
Assets/GameScripts/HotFix/GameLogic/Procedure/GamePlay/GamePlayProcedure.cs
```

**预制体**：
```
Assets/AssetRaw/Prefabs/Enemy/EnemyPlane.prefab
```

## 生命周期

### 启动流程
```
GamePlayProcedure.OnEnter()
  ├─ new EnemySpawnerModule(entityManager)
  ├─ spawner.OnInit()                    // 创建实体组
  ├─ spawner.Configure(...)              // 配置参数
  └─ ModuleSystem.Register(spawner, 1001)  // 注册到 GamePlayScope
```

### 运行流程
```
ModuleSystem.Update()
  └─ EnemySpawnerModule.Update()
       ├─ 检查生成计时器
       ├─ 清理已销毁的敌人引用
       └─ 达到间隔时：SpawnEnemy()
            ├─ 加载预制体 (异步)
            ├─ 创建 EnemyBehaviorData
            └─ entityManager.ShowEntityAsync()
```

### 实体生命周期
```
EnemyEntity
  ├─ OnInit(entityData)        // 初始化基本信息
  ├─ OnShow(userData)          // 显示时配置行为数据
  ├─ OnUpdate(deltaTime)       // 每帧更新
  │    ├─ 状态: Moving  → 移动逻辑
  │    ├─ 状态: Staying → 停留 + 攻击
  │    └─ 边界检测 → 销毁
  ├─ OnHide()                  // 隐藏时清理
  └─ OnRecycle()               // 回收到对象池
```

### 清理流程
```
GamePlayProcedure.OnLeave()
  └─ ModuleSystem.ShutdownScope(1001)
       └─ EnemySpawnerModule.Shutdown()
            ├─ 遍历 _aliveEnemies
            ├─ entityManager.HideEntity(enemy)
            └─ _aliveEnemies.Clear()
```

## API 速查

### IEnemySpawnerModule

```csharp
// 配置生成器
void Configure(string enemyPrefabName, float spawnInterval, int maxEnemyCount);

// 动态调整间隔
void SetSpawnInterval(float interval);

// 动态调整数量上限
void SetMaxEnemyCount(int maxCount);
```

### EnemyEntity 状态

```csharp
enum EnemyState
{
    Moving,   // 移动中
    Staying   // 停留中
}
```

## 配置修改

### 修改生成参数

在 `GamePlayProcedure.OnEnter()` 中：

```csharp
// 当前配置
_enemySpawnerModule.Configure("EnemyPlane", spawnInterval: 2f, maxEnemyCount: 10);

// 示例：更快生成，更多敌人
_enemySpawnerModule.Configure("EnemyPlane", spawnInterval: 1f, maxEnemyCount: 20);
```

### 修改行为参数

在 `EnemySpawnerModule.SpawnEnemy()` 中：

```csharp
var behaviorData = new EnemyBehaviorData
{
    SpawnPosition = spawnPos,
    MoveSpeed = 2f,              // 改这里：移动速度
    MoveDirection = Vector3.down,
    StayPosition = stayPos,      // 改这里：停留位置 Y 坐标
    StayDuration = 2f,           // 改这里：停留时长
    AttackInterval = 1.5f        // 改这里：攻击间隔
};
```

### 添加新敌人类型

1. 创建新预制体（例如：`EnemyBomber.prefab`）
2. 放入 `Assets/AssetRaw/Prefabs/Enemy/`
3. 构建 AssetBundle
4. 配置时使用新名称：

```csharp
_enemySpawnerModule.Configure("EnemyBomber", 3f, 5);
```

## 调试技巧

### 启用详细日志

在 `EnemySpawnerModule` 和 `EnemyEntity` 中已包含关键日志：

```csharp
// 查找这些日志来追踪问题
[EnemySpawnerModule] 敌人实体组创建成功
[EnemySpawnerModule] 生成敌人: EnemyPlane 于位置 (x, y, z)
[EnemySpawnerModule] 已达到最大敌人数量

[EnemyEntity] 到达停留位置
[EnemyEntity] 敌人攻击！
[EnemyEntity] 停留结束，继续移动
[EnemyEntity] 敌人超出边界，销毁
```

### Inspector 检查

运行时查看 Hierarchy：
- 展开 `Enemy/EnemyPlane` 查看实例
- 观察 Transform 位置变化
- 检查对象数量是否 ≤ 10

### Profiler 分析

- **CPU Usage**：检查 `EnemyEntity.OnUpdate`
- **Memory**：检查对象池是否正常回收
- **Rendering**：检查绘制调用

## 常见修改场景

### 1. 改变生成位置

```csharp
// 在 EnemySpawnerModule.SpawnEnemy() 中
float randomX = UnityEngine.Random.Range(-5f, 5f); // 当前范围
float spawnY = Camera.main.orthographicSize + 1f;  // 屏幕上方

// 修改为固定位置
float randomX = 0f; // 中间生成

// 修改为更宽范围
float randomX = UnityEngine.Random.Range(-8f, 8f);
```

### 2. 改变移动模式

```csharp
// 在 EnemyEntity.OnUpdate() 中
// 当前：直线向下
_handle.transform.position += _moveDirection * (_moveSpeed * deltaTime);

// 改为：曲线移动
float wave = Mathf.Sin(Time.time * 2f) * 0.5f;
_handle.transform.position += new Vector3(wave, -_moveSpeed * deltaTime, 0);
```

### 3. 禁用停留功能

```csharp
// 在 EnemySpawnerModule.SpawnEnemy() 中
var behaviorData = new EnemyBehaviorData
{
    // ...
    StayDuration = 0f,  // 设为 0 跳过停留
};
```

### 4. 添加生命值

```csharp
// 在 EnemyBehaviorData 中添加
public int MaxHealth { get; set; }
public int CurrentHealth { get; set; }

// 在 EnemyEntity 中添加方法
public void TakeDamage(int damage)
{
    _currentHealth -= damage;
    if (_currentHealth <= 0)
    {
        GameLogicEntry.Entity.HideEntity(this);
    }
}
```

## 性能注意事项

### 优化建议

1. **对象池预热**（可选）：
   ```csharp
   // 在 EnemySpawnerModule.OnInit 后
   for (int i = 0; i < 5; i++)
   {
       // 预创建一些实体
   }
   ```

2. **批量处理**：
   - 当前已实现批量清理
   - 每帧只清理已销毁的引用

3. **避免频繁查找**：
   - Camera.main 已缓存在变量中
   - 实体 Handle 在 OnShow 中缓存

4. **减少 GC 压力**：
   - 使用对象池（已实现）
   - 避免 Update 中创建新对象
   - 复用 Vector3（当前实现良好）

### 性能基准

| 指标 | 预期值 | 备注 |
|------|--------|------|
| FPS | ≥60 | 10 个敌人同屏 |
| 内存 | <100MB | 增量占用 |
| GC Alloc | <1KB/frame | 稳定运行时 |

## 扩展点

系统设计为可扩展，可以轻松添加：

### 1. AI 系统
- 在 `EnemyEntity.OnUpdate` 中替换简单状态机
- 使用行为树或状态机框架

### 2. 攻击系统
- 在 `PerformAttack()` 中替换日志
- 创建子弹实体
- 添加碰撞检测

### 3. 配置系统
- 创建 `EnemyConfig.cs` ScriptableObject
- 从配置加载参数而非硬编码

### 4. 波次系统
- 创建 `WaveManager`
- 控制不同波次的敌人类型和数量

## 故障排除清单

问题排查时按此顺序检查：

1. ✅ Unity 编译无错误
2. ✅ YooAsset 已构建资源包
3. ✅ Camera.main 存在且为正交模式
4. ✅ GamePlayProcedure 正确启动
5. ✅ Console 没有资源加载错误
6. ✅ EnemySpawnerModule 已注册到 ModuleSystem
7. ✅ 实体组创建成功（查看日志）

## 相关文档

- 📖 [完整测试指南](./TESTING_GUIDE.md)
- 📖 [实施总结](./IMPLEMENTATION_SUMMARY.md)
- 📖 [Bug 修复记录](./BUGFIX_SUMMARY.md)
- 📖 [设计文档](./design.md)
- 📖 [提案文档](./proposal.md)
- 📋 [任务清单](./tasks.md)

## 版本信息

- **实现日期**：2026-01-31
- **Unity 版本**：6000
- **框架**：EasyFramework + HybridCLR
- **资源系统**：YooAsset
- **代码行数**：约 400 行（含注释）
