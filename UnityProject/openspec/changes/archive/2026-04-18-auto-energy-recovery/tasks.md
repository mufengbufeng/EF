## 1. 存档数据扩展

- [x] 1.1 在 `EnergySaveData` 中添加 `lastRecoverTimestamp` 字段（long 类型）
- [x] 1.2 更新 `LoadOrCreateState()` 处理旧存档兼容：缺少时间戳时使用当前时间
- [x] 1.3 更新 `SaveState()` 写入时间戳

## 2. 离线补偿计算

- [x] 2.1 在 `LoadOrCreateState()` 中实现离线补偿：根据时间差计算恢复量，钳制到上限
- [x] 2.2 恢复进度保留余数（如离线 800 秒 / 360 秒间隔 → 恢复 2 点，剩余 80 秒进度）

## 3. 接口扩展

- [x] 3.1 在 `IEnergyModule` 中新增 `RecoveryIntervalSeconds`、`TimeToNextRecovery`、`IsRecovering` 属性
- [x] 3.2 在 `EnergyModule` 中实现这些属性

## 4. 定时恢复驱动

- [x] 4.1 注入 `ITimerManager` 依赖到 `EnergyModule` 构造函数
- [x] 4.2 实现定时器注册：体力未满时每 `RecoveryIntervalSeconds` 恢复 1 点
- [x] 4.3 体力满时暂停定时器，`TryConsume` 后不满时重新启动
- [x] 4.4 `Shutdown()` 时清理定时器

## 5. 注册更新

- [x] 5.1 更新 `InitProcedure` 中 `EnergyModule` 的构造调用，传入 `ITimerManager`

## 6. 测试覆盖

- [x] 6.1 测试离线补偿：长时间离线恢复正确量，不超过上限
- [x] 6.2 测试离线补偿：离线时间不足时不恢复
- [x] 6.3 测试旧存档兼容：缺少时间戳时不崩溃
- [x] 6.4 测试恢复状态属性：`IsRecovering`、`TimeToNextRecovery` 返回正确值
- [x] 6.5 测试消耗后恢复重启：消耗后定时器重新启动

## 7. UI 展示（可选）

- [x] 7.1 `MainView` 显示恢复倒计时文本（如"下次恢复：4:32"）
