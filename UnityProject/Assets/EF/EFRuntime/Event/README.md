# EF Event 事件系统

## 概述

EF Event 是一个高性能、线程安全的事件管理系统，专为 Unity 游戏引擎设计。它提供了灵活的事件注册、派发和生命周期管理能力，支持同步/异步事件处理，并通过池化策略实现运行时行为调整。

## 核心特性

- **类型安全**：基于泛型设计，编译期类型检查，避免运行时类型错误
- **线程安全**：内部使用锁机制，确保多线程环境下的数据一致性
- **灵活派发**：支持同步立即派发（`PublishNow`）和异步队列派发（`Publish`）
- **池化策略**：通过 `EventPoolModel` 动态控制事件注册约束
- **高性能**：使用快照机制避免锁内调用外部逻辑，事件 ID 缓存减少反射开销
- **生命周期管理**：与 Unity Update 循环集成，自动处理待派发事件

## 架构组件

### 核心类

| 类名 | 说明 |
|------|------|
| `EventManager` | 事件管理器主类，实现 `IEventManager` 接口 |
| `BaseEventArgs` | 所有事件参数的抽象基类 |
| `EventHandlerRegistry` | 处理器注册表，管理事件与监听器的映射关系 |
| `EventTypeResolver` | 事件类型解析器，负责类型校验和 ID 缓存 |
| `PendingEventQueue` | 待派发事件队列，用于异步事件处理 |
| `EventPoolModel` | 池化策略枚举，控制事件注册行为 |

### 类图关系

```
IEventManager
    ↑
EventManager ──┬──> EventHandlerRegistry
               ├──> EventTypeResolver
               ├──> PendingEventQueue
               └──> EventPoolModel

BaseEventArgs (abstract)
    ↑
GameEventArgs / YourCustomEventArgs
```

## 快速开始

### 1. 定义事件参数

继承 `BaseEventArgs` 并提供唯一的 `EventId`：

```csharp
using EF.Event;

public class PlayerLevelUpEventArgs : BaseEventArgs
{
    // 方式 1: 使用静态字段（推荐，避免实例化）
    public static readonly int EventIdValue = 1001;

    public override int EventId => EventIdValue;

    public int Level { get; set; }
    public int Experience { get; set; }
}
```

### 2. 订阅事件

```csharp
EventManager eventManager = new EventManager();

// 订阅事件
eventManager.Subscribe<PlayerLevelUpEventArgs>(OnPlayerLevelUp);

void OnPlayerLevelUp(object sender, PlayerLevelUpEventArgs e)
{
    Debug.Log($"玩家升级到 {e.Level} 级，当前经验值：{e.Experience}");
}
```

### 3. 派发事件

```csharp
// 异步派发（进入下一帧队列）
eventManager.Publish(new PlayerLevelUpEventArgs
{
    Level = 10,
    Experience = 5000
});

// 同步立即派发
eventManager.PublishNow(new PlayerLevelUpEventArgs
{
    Level = 10,
    Experience = 5000
});
```

### 4. 取消订阅

```csharp
eventManager.Unsubscribe<PlayerLevelUpEventArgs>(OnPlayerLevelUp);
```

### 5. 集成到 Unity 生命周期

```csharp
void Update()
{
    // 处理待派发事件队列
    eventManager.Update(Time.deltaTime, Time.unscaledDeltaTime);
}

void OnDestroy()
{
    // 清理资源
    eventManager.Shutdown();
}
```

## 池化策略配置

`EventPoolModel` 提供了灵活的运行时约束控制，可按位组合使用：

### 策略枚举

| 枚举值 | 说明 |
|--------|------|
| `Default` | 默认策略（值为 0），禁止多监听器和重复注册 |
| `AllowNoHandler` | 允许派发没有监听器的事件（默认会抛异常） |
| `AllowMultiHandler` | 允许同一事件注册多个监听器 |
| `AllowDuplicateHandler` | 允许同一监听器重复注册到同一事件 |

### 使用示例

```csharp
// 创建时使用默认策略
EventManager eventManager = new EventManager();

// 运行时调整：允许多个监听器
eventManager.PoolModel = EventPoolModel.AllowMultiHandler;

// 组合使用：允许多监听器 + 允许无监听器触发
eventManager.PoolModel = EventPoolModel.AllowMultiHandler
                       | EventPoolModel.AllowNoHandler;
```

### 策略场景

| 场景 | 推荐策略 |
|------|----------|
| UI 系统（多个 UI 监听同一事件） | `AllowMultiHandler` |
| 日志系统（允许无监听器触发） | `AllowNoHandler` |
| 单例模式（严格单一监听器） | `Default` |
| 调试模式（允许重复注册） | `AllowDuplicateHandler` |

## 高级特性

### 1. 事件 ID 解析优先级

`EventTypeResolver` 按以下优先级解析事件 ID：

1. **静态属性**（最高优先级，推荐）
2. **静态字段**
3. **实例属性**（通过无参构造函数创建实例）

```csharp
// 推荐：静态属性
public class MyEventArgs : BaseEventArgs
{
    public static int EventIdValue => 2001;
    public override int EventId => EventIdValue;
}
```

### 2. 线程安全保障

- 所有公共 API 都是线程安全的
- 内部使用快照机制避免在锁内调用外部代码
- 事件 ID 缓存使用双重检查锁定模式

### 3. 性能优化

- **类型缓存**：首次解析后缓存事件类型与 ID 的映射 (`EventTypeResolver.cs:12`)
- **快照分发**：创建处理器快照后释放锁，避免阻塞注册/反注册 (`EventHandlerRegistry.cs:175`)
- **批量处理**：异步事件在 Update 中批量处理，减少逐帧开销 (`EventManager.cs:83-94`)

### 4. 异常处理

系统在以下情况会抛出异常：

| 异常类型 | 触发条件 | 位置 |
|----------|----------|------|
| `ArgumentNullException` | 监听器为空 | `EventManager.cs:47` |
| `InvalidOperationException` | 重复注册监听器（取决于 `PoolModel`） | `EventHandlerRegistry.cs:99` |
| `InvalidOperationException` | 事件无监听器（`AllowNoHandler` 未设置） | `EventManager.cs:113` |
| `InvalidCastException` | 事件载荷类型不匹配 | `EventHandlerRegistry.cs:206` |

## API 参考

### IEventManager 接口

```csharp
public interface IEventManager
{
    int EventCount { get; }              // 当前注册的事件种类数量
    int EventHandlerCount { get; }       // 已注册的处理器总数

    int Count(int id);                   // 获取指定事件的处理器数量
    bool Check(int id, EventHandler<object> listener); // 检查是否包含处理器

    void Subscribe<T>(EventHandler<T> listener);       // 订阅事件
    void Unsubscribe<T>(EventHandler<T> listener);     // 取消订阅

    void Publish<T>(T eventData);        // 异步派发
    void PublishNow<T>(T eventData);     // 同步派发
}
```

## 最佳实践

### ✅ 推荐做法

1. **使用静态字段/属性定义 EventId**，避免实例化开销
2. **在合适的生命周期调用 `Update`**，确保异步事件及时处理
3. **及时取消订阅**，避免内存泄漏（特别是 MonoBehaviour 销毁时）
4. **优先使用异步派发**（`Publish`），除非需要立即响应
5. **在 Editor 下启用严格模式**（`Default` 策略），及早发现问题

### ❌ 避免做法

1. **不要在事件处理器中派发同类事件**，可能导致无限递归
2. **不要在锁内调用外部代码**（系统已通过快照机制避免）
3. **不要忘记调用 `Shutdown`**，可能导致资源泄漏
4. **不要在性能敏感路径频繁订阅/取消订阅**

### 示例：资源管理

```csharp
public class UIController : MonoBehaviour
{
    private EventManager _eventManager;

    void Start()
    {
        _eventManager = /* 获取事件管理器实例 */;
        _eventManager.Subscribe<PlayerLevelUpEventArgs>(OnPlayerLevelUp);
    }

    void OnDestroy()
    {
        // 重要：取消订阅避免内存泄漏
        if (_eventManager != null)
        {
            _eventManager.Unsubscribe<PlayerLevelUpEventArgs>(OnPlayerLevelUp);
        }
    }

    void OnPlayerLevelUp(object sender, PlayerLevelUpEventArgs e)
    {
        // 处理逻辑
    }
}
```

## 常见问题

### Q: 异步事件什么时候被处理？
A: 异步事件（通过 `Publish` 派发）会进入队列，在下次调用 `Update` 方法时批量处理。

### Q: 如何处理事件派发时没有监听器的情况？
A: 默认会抛出 `InvalidOperationException`。如果这是预期行为，可设置 `PoolModel` 包含 `AllowNoHandler` 标志。

### Q: 支持多播委托吗？
A: 支持。设置 `PoolModel` 为 `AllowMultiHandler` 即可为同一事件注册多个监听器。

### Q: 性能如何？
A: 系统使用了多种优化手段（类型缓存、快照机制、批量处理），适用于高频事件场景。建议在性能敏感场景进行 Profiling 测试。

## 版本历史

- **初始版本**：实现核心事件管理功能
- 支持同步/异步派发
- 线程安全设计
- 池化策略配置

## 许可证

本项目为 EF 框架的一部分，遵循项目整体许可证。

---

**文档版本**: 1.0
**最后更新**: 2024-10
