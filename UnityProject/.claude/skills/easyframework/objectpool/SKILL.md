---
name: ef-objectpool
description: EasyFramework 对象池模块。使用此 skill 当用户提到 EasyFramework 的 ObjectPool、对象池、PoolManager、Spawn、Recycle、PooledObject、复用对象、减少GC 时。在实现、重构、排错、测试或设计该模块相关功能时必须优先使用此 skill，而不是只在用户显式点名模块时才触发。
---

# EF.ObjectPool 对象池模块

## 模块定位
该 skill 用于处理 EF.ObjectPool 对象池模块 的实现、扩展、故障排查与重构任务。回答时先确认业务目标，再映射到该模块的核心抽象与生命周期。

## 何时必须触发
- 用户直接提到：EasyFramework 的 ObjectPool、对象池、PoolManager、Spawn、Recycle、PooledObject、复用对象、减少GC。
- 虽未点名模块，但需求本质落在 EF.ObjectPool 对象池模块 的职责范围（例如注册、生命周期、依赖关系、性能或稳定性问题）。
- 需要输出可落地代码改动、排障步骤、验证命令或回归检查清单。

## 执行流程（按顺序）
- 明确约束：确认运行环境、调用入口、是否允许改动公共接口。
- 建立映射：定位到对应管理器/接口/数据结构，给出最小改动路径。
- 实施方案：优先增量改造，避免一次性重构引入大范围回归。
- 验证闭环：提供编译、运行、核心流程与边界场景验证步骤。
- 输出结果：给出“变更点 + 原因 + 风险 + 回滚建议”。

## 实施准则
- 保持与 EasyFramework 既有命名、目录结构、生命周期约定一致。
- 先保证正确性，再做性能优化；涉及缓存/池化时说明释放策略。
- 涉及跨模块协作时明确依赖顺序与初始化时机，避免未注册访问。
- 提供最小可运行示例时，优先使用当前项目已有基类与管理器接口。

## 常见故障排查清单
- 注册缺失：检查模块是否在初始化流程中注册，接口与实现是否一致。
- 生命周期错位：确认 OnInit/OnUpdate/OnDestroy（或等价阶段）是否顺序正确。
- 依赖空引用：检查上游模块可用性与获取时机（同步/异步加载后再访问）。
- 数据不同步：确认事件订阅解绑、状态刷新与持久化读写时序是否正确。
- 回归风险：检查是否影响主流程（启动、切场景、返回主界面、暂停恢复）。

## 回答输出模板
1. 目标与约束：一句话说明要解决的问题与边界。
2. 方案与取舍：给出推荐实现和不选其他方案的原因。
3. 关键改动：列出文件/接口/核心代码片段。
4. 验证结果：列出编译与测试步骤、通过/失败结论。
5. 风险与回滚：说明潜在影响和快速回退方案。

## 模块资料（保留参考）
对象池模块用于统一管理可重复利用的对象实例，降低频繁创建与销毁带来的 GC 压力。

## 核心类型

| 类型 | 说明 |
|------|------|
| `IObjectPoolManager` | 对象池管理器接口 |
| `ObjectPoolManager` | 对象池管理器实现 |
| `IObjectPool<T>` | 对象池接口 |
| `ObjectPool<T>` | 对象池实现 |
| `ObjectPoolOptions` | 对象池配置 |
| `PooledObject<T>` | 池化对象包装 |

## 使用示例

### 创建对象池

```csharp
var poolManager = new ObjectPoolManager();

var bulletPool = poolManager.CreatePool(
    name: "BulletPool",
    factory: () => new Bullet(),
    options: new ObjectPoolOptions
    {
        AllowMultiSpawn = false,
        Capacity = 200,
        ExpireTime = 30f,
        AutoReleaseInterval = 5f
    },
    onSpawn: bullet => bullet.ResetState(),
    onRecycle: bullet => bullet.Deactivate(),
    onDestroy: bullet => bullet.Dispose()
);
```

### 取用与回收

```csharp
// 取用对象
Bullet bullet = bulletPool.Spawn();

// 使用对象
bullet.Fire(direction);

// 回收对象
bulletPool.Recycle(bullet);
```

### 锁定对象

```csharp
// 锁定（不会被自动释放）
bulletPool.SetLocked(bullet, true);

// 解锁
bulletPool.SetLocked(bullet, false);
```

### 批量释放

```csharp
// 释放所有空闲对象
bulletPool.ReleaseAll();

// 释放指定数量
bulletPool.ReleaseAll(10);
```

## 配置说明

| 参数 | 说明 |
|------|------|
| `AllowMultiSpawn` | 允许对象被多次取出（引用计数模式） |
| `AutoRelease` | 是否启用自动回收空闲对象 |
| `Capacity` | 容量上限 |
| `ExpireTime` | 对象空闲过期时间（秒） |
| `AutoReleaseInterval` | 自动释放检测间隔（秒） |

## 生命周期

```
CreatePool()
    ↓
[按需创建对象]
    ↓
Spawn() → onSpawn 回调
    ↓
[使用对象]
    ↓
Recycle() → onRecycle 回调
    ↓
[空闲等待]
    ↓
[超时或容量满] → onDestroy 回调
```

## 统计接口

```csharp
int total = bulletPool.TotalCount;      // 总数量
int available = bulletPool.AvailableCount;  // 可用数量
int spawned = bulletPool.SpawnedCount;  // 已取出数量
```
