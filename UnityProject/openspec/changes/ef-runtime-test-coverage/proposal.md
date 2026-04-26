## Why

EFRuntime 框架的 13 个模块目前没有任何单元测试覆盖，仅有的 4 个 Example 文件都是 MonoBehaviour 用法演示而非测试。随着框架持续演进（最近完成了 Event 系统重构、Feature 系统引入），缺乏自动化测试导致回归风险高，重构信心不足。

## What Changes

- 为 EFRuntime 核心模块编写全面的 NUnit 单元测试
- 测试代码放置在 `Assets/GameScripts/HotFix/GameLogic/Tests/EditMode/Framework/` 目录下
- 删除不再需要的 Example 代码（Entity/Examples、SoundExample、LogExample），测试本身即文档
- 所有测试使用纯 C# NUnit `[Test]`，与现有 EnergyModuleTests/MainControllerTests 风格一致

## Capabilities

### New Capabilities

- `event-channel-test`: EventChannel\<T\> 的 Subscribe/Publish/Unsubscribe/Enqueue/Flush 全生命周期测试，包括零 GC 环形缓冲区、派发中修改 handler 列表等边界场景
- `module-system-test`: ModuleSystem 的 Register/Get/Unregister、Scope 隔离、replace 策略、Update 顺序等核心功能测试
- `object-pool-test`: ObjectPool\<T\> 的 Spawn/Recycle/Prewarm/AutoRelease/SetLocked 生命周期测试，以及 ObjectPoolManager 多池管理测试
- `timer-test`: TimerManager 的 ScheduleOnce/ScheduleLoop/Cancel、TimerTask 状态机、TimerTaskCollection 的 CollectDue/ShiftAll 测试
- `model-test`: ModelManager 的 Register/Get/Unregister 泛型解析测试，ModelBase\<TData\> 的数据变更通知测试
- `fsm-test`: Fsm\<TOwner\> 的状态转换生命周期测试，FsmManager 的 CreateFsm/DestroyFsm 多 FSM 管理测试
- `feature-test`: FeatureContainer 的 Add/Remove/AllowMultiple/RequireFeature/Enabled 状态管理测试
- `save-test`: SaveManager 的策略切换和序列化测试，JsonSaveStrategy 纯逻辑测试

### Modified Capabilities

（无已有规格需要修改）

## Impact

- **代码**: 新增约 8 个测试文件在 `Tests/EditMode/Framework/` 下；可能删除 4 个 Example 文件
- **程序集**: 复用现有 `GameLogic.Tests.EditMode.asmdef`，无需新建程序集
- **依赖**: 仅依赖已引入的 NUnit（`com.unity.ext.nunit`），无新依赖
- **CI**: 测试可通过 `Unity.exe -runTests -testPlatform EditMode` 或编辑器 Test Runner 运行
- **框架代码**: 不修改任何 EFRuntime 源码，纯新增测试
