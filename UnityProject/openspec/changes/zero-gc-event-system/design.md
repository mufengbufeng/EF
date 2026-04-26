## Context

当前 EF.Event 系统采用 `Dictionary<int, List<EventHandler<object>>>` 统一存储所有事件的 handler。每次 Publish 时：
1. 反射解析 EventId（有缓存但首次仍用反射）
2. `CreateSnapshot()` 创建 `new List<EventHandler<object>>()` 做快照
3. 通过 `CreateWrapper` 闭包拆箱调用 typed handler

这三个环节在热路径上产生 GC 分配。项目目标是高频事件场景（如战斗、物理）下 0 GC。

当前调用点：`GameSceneManager` 使用 `IEventManager.Publish`，事件定义在 `GameSceneEvents.cs`。

### 约束

- AOT/HotFix 分离：EF.Runtime 是 AOT，不能引用 GameLogic（热更新）
- 所有游戏事件定义在 GameLogic 程序集中
- 生成代码必须放在 GameLogic 中（或可被 GameLogic 引用的位置）
- EF.Runtime 只提供基础设施（泛型类、接口、Attribute）

## Goals / Non-Goals

**Goals:**
- Publish 热路径零 GC（无 List 分配、无闭包、无装箱）
- 零反射（EventId 通过 Code Gen 在编译期确定）
- 类型安全的 API（`EventHub.SceneEnter.Publish(in args)`，编译器保证类型正确）
- Editor 可视化面板，实时展示事件订阅和分发状态
- Code Gen 自动化（文件变化触发 + 菜单手动触发）

**Non-Goals:**
- 不支持 class 类型的事件参数（强制 struct）
- 不做线程安全（Unity 主线程模型，事件操作全在主线程）
- 不做跨进程/网络事件分发
- 不保留旧 `IEventManager` API 兼容

## Decisions

### D1: EventChannel<T> 泛型类放在 EF.Runtime

**选择**: `EventChannel<T>` 作为通用泛型类放在 EF.Runtime 中。

**理由**: 所有 Channel 共享完全相同的逻辑（handler 数组、ring buffer、version 保护），只有类型参数不同。泛型类由 JIT 为每个 T 生成独立代码，等价于手写 N 个类。无需为每个事件类型生成 Channel 类。

**替代方案**:
- 为每个事件类型生成独立 Channel 类 — 代码量大，且逻辑完全重复
- 用 Source Generator 生成 — Unity 对 Roslyn Source Generator 支持不稳定

### D2: readonly struct 事件参数 + `[EventArgs]` Attribute

**选择**: 事件参数定义为 `readonly struct`，用 `[EventArgs]` Attribute 标记。

**理由**: struct 是值类型，`Publish(in T args)` 传引用，整个发布链零堆分配。`[EventArgs]` 供 Code Gen 扫描识别。readonly struct 防止意外修改。

**替代方案**:
- class + 对象池 — 需要 Rent/Return 纪律，忘记 Return 就泄漏
- 普通 struct（非 readonly） — 可能被意外修改，且编译器无法优化

### D3: 版本号替代快照保护迭代安全

**选择**: Channel 维护 `_version` 计数器，Publish 迭代时检测变更，不创建快照 List。

**理由**: 每次 Publish 创建快照 List 是当前最大 GC 源头。版本号方案：Subscribe/Unsubscribe 时 `_version++`，Publish 循环中检测版本变化后重新对齐迭代边界。零分配。

**替代方案**:
- Copy-on-write 数组 — 每次 Modify 复制数组，有 GC
- 标记删除 + 延迟压缩 — 复杂度高，且有内存泄漏风险

### D4: 环形缓冲区实现异步派发

**选择**: 每个 Channel 内置 `T[]` 环形缓冲区，`Enqueue` 写入、`Flush` 在 Update 时消费。

**理由**: 预分配定长数组，指针环绕移动，零分配。struct 存储在数组中无 GC。Power-of-2 大小可用位运算取模。

**替代方案**:
- `Queue<T>` — 内部数组扩容时有 GC，且 API 不如 ring buffer 紧凑
- 全局统一队列 — 需要类型擦除，引入 `object` 或接口分配

### D5: Code Gen 只生成 EventHub 聚合类

**选择**: Generator 扫描所有 `[EventArgs]` struct，生成一个 `EventHub` partial 类，包含每个事件类型的 `EventChannel<T>` 属性和 `IEventChannel[]` 注册表。

**理由**: 最小生成量。`EventChannel<T>` 的所有逻辑已在泛型基类中，不需要为每个事件类型生成独立类。

**触发方式**:
1. `[MenuItem("EF/Generate Event System")]` 手动触发
2. `AssetPostprocessor.OnPostprocessAllAssets` 监听 `.cs` 文件变化自动触发

### D6: Editor 面板通过 IEventChannelInfo 接口获取数据

**选择**: `EventChannel<T>` 实现 `IEventChannelInfo` 接口（EventName、HandlerCount、PendingCount、GetHandlerNames），Editor 窗口遍历 `EventHub` 的所有 channel 展示信息。

**理由**: 不依赖反射获取信息，接口调用零分配。面板可以实时刷新。

## Risks / Trade-offs

- **[Risk] struct 事件参数含引用类型字段（如 string）仍会产生堆分配** → 这是用户侧控制，框架本身不分配。文档中建议事件参数尽量使用值类型字段。
- **[Risk] 环形缓冲区满时的扩容会产生一次性 GC** → 仅在异常积压时发生，正常游戏循环不应出现。扩容后空间保留，不再重复分配。
- **[Risk] Code Gen 在 CI/构建流程中需要显式触发** → 提供菜单按钮 + 自动监听双保险；构建前可加 pre-build 步骤。
- **[Trade-off] 不保留旧 API 兼容** → 所有调用点需一次性迁移。当前已知调用点极少（GameSceneManager、GameSceneEvents），迁移成本低。
- **[Trade-off] 不做线程安全** → 与 Unity 主线程模型一致。如需跨线程事件，应在业务层用队列调度回主线程。
