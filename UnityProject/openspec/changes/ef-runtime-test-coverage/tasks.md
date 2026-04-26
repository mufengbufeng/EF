## 1. 准备工作

- [x] 1.1 创建 `Assets/GameScripts/HotFix/GameLogic/Tests/EditMode/Framework/` 目录
- [x] 1.2 确认 `GameLogic.Tests.EditMode.asmdef` 已正确引用 `EF.Runtime` 程序集

## 2. P0 — EventChannel 测试

- [x] 2.1 创建 `EventChannelTests.cs`，编写 Subscribe 注册测试（正常注册、null 异常、重复注册忽略）
- [x] 2.2 编写 Unsubscribe 反注册测试（正常移除、不存在静默、null 异常）
- [x] 2.3 编写 Publish 同步派发测试（单/多 handler、按序派发、派发中注册/反注册安全性）
- [x] 2.4 编写 Enqueue/Flush 异步队列测试（PendingCount、环形缓冲区扩容、Flush 清空、空队列 Flush）
- [x] 2.5 编写 Clear 全量清空测试

## 3. P0 — ModuleSystem 测试

- [x] 3.1 创建 `ModuleSystemTests.cs`，编写 Register 注册测试（正常注册、重复抛异常、replace 覆盖）
- [x] 3.2 编写 Get/TryGet 获取测试（正常获取、未注册抛异常、TryGet 返回 false）
- [x] 3.3 编写 Unregister 注销测试（正常注销、注销时调用 Shutdown）
- [x] 3.4 编写 Scope 隔离测试（ShutdownScope 不影响其他 scope）
- [x] 3.5 编写 Update 批量更新和 ShutdownAll 全量清理测试

## 4. P1 — ObjectPool 测试

- [x] 4.1 创建 `ObjectPoolTests.cs`，编写 Spawn 测试（工厂创建、复用已有、onSpawn 回调）
- [x] 4.2 编写 Recycle/TryRecycle 测试（正常回收、onRecycle 回调、未使用对象返回 false）
- [x] 4.3 编写 Prewarm 预热测试
- [x] 4.4 编写 AutoRelease 自动释放测试（超过 ExpireTime 释放）
- [x] 4.5 编写 SetLocked 锁定测试
- [x] 4.6 创建 `ObjectPoolManagerTests.cs`，编写 CreatePool/GetPool/DestroyPool/HasPool 测试（包括不同类型同名池共存）

## 5. P1 — Timer 测试

- [x] 5.1 创建 `TimerTaskTests.cs`，编写 TimerTask 状态机测试（Cancel、IsCancelled、TrySetNextTrigger）
- [x] 5.2 创建 `TimerTaskCollectionTests.cs`，编写 CollectDue/ShiftAll/Clear 测试
- [x] 5.3 创建 `TimerManagerTests.cs`，编写 ScheduleOnce 测试（到时触发、未到时不触发、TimerId 有效）
- [x] 5.4 编写 ScheduleLoop 循环触发测试
- [x] 5.5 编写 Cancel 取消和 TimerId 唯一性测试
- [x] 5.6 编写 Clear 全量清空测试

## 6. P1 — Model 测试

- [x] 6.1 创建 `ModelManagerTests.cs`，编写 Register/GetModel 测试（正常注册获取、重复注册异常）
- [x] 6.2 编写 Get<TData> 反向查找测试
- [x] 6.3 编写 Unregister 和 ModelCount 计数测试
- [x] 6.4 编写 Shutdown 清理测试

## 7. P1 — Fsm 测试

- [x] 7.1 创建 `FsmTests.cs`，编写状态转换生命周期测试（OnEnter/OnLeave 顺序）
- [x] 7.2 编写 FsmDataCollection 数据存取测试
- [x] 7.3 创建 `FsmManagerTests.cs`，编写 CreateFsm/DestroyFsm 测试（初始状态、销毁时 OnLeave）
- [x] 7.4 编写 Update 驱动和 Shutdown 清理测试

## 8. P2 — Feature 测试

- [x] 8.1 创建 `FeatureContainerTests.cs`，编写 AddFeature/GetFeature/HasFeature 测试
- [x] 8.2 编写 AllowMultiple 多实例和 RequireFeature 依赖检查测试
- [x] 8.3 编写 RemoveFeature 和 SetFeatureEnabled 启用/禁用测试
- [x] 8.4 编写 Update 批量更新（禁用 Feature 不触发）测试

## 9. P2 — Save 测试

- [x] 9.1 创建 `SaveManagerTests.cs`，编写 Save/Load/Delete/DeleteAll 测试
- [x] 9.2 编写 SetSaveStrategy 策略切换和 Shutdown 清理测试

## 10. 验证

- [ ] 10.1 在 Unity 编辑器 Test Runner 中运行所有新增测试，确认全部通过
- [ ] 10.2 确认现有测试（EnergyModuleTests、MainControllerTests）不受影响
