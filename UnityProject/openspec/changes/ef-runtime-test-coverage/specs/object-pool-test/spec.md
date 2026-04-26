## ADDED Requirements

### Requirement: Spawn 获取对象
ObjectPool SHALL 通过 Spawn 从可用队列获取对象，无可用时通过工厂创建。

#### Scenario: 首次 Spawn 通过工厂创建
- **WHEN** 池为空时调用 Spawn()
- **THEN** 通过 defaultFactory 创建新对象，TotalCount 和 SpawnedCount 各增 1

#### Scenario: 有可用对象时直接复用
- **WHEN** 已有 Recycled 对象时调用 Spawn()
- **THEN** 从可用队列取出复用，不调用工厂，TotalCount 不变

#### Scenario: Spawn 触发 onSpawn 回调
- **WHEN** 调用 Spawn()
- **THEN** onSpawn 回调被调用，参数为 spawned 对象

### Requirement: Recycle 回收对象
ObjectPool SHALL 通过 Recycle 将对象归还到可用队列。

#### Scenario: 回收后 AvailableCount 增加
- **WHEN** Spawn 一个对象后调用 Recycle(obj)
- **THEN** AvailableCount 增加 1，SpawnedCount 减少 1

#### Scenario: 回收触发 onRecycle 回调
- **WHEN** 调用 Recycle(obj)
- **THEN** onRecycle 回调被调用

#### Scenario: TryRecycle 未使用对象返回 false
- **WHEN** 对象未被 Spawn 时调用 TryRecycle(obj)
- **THEN** 返回 false，池状态不变

### Requirement: Prewarm 预热
ObjectPool SHALL 通过 Prewarm 预先创建指定数量的对象。

#### Scenario: Prewarm 填充可用队列
- **WHEN** 调用 Prewarm(10)
- **THEN** 创建 10 个对象放入可用队列，TotalCount 增加 10

### Requirement: AutoRelease 自动释放
ObjectPool SHALL 在 Update 中检查过期对象并自动释放。

#### Scenario: 超过 ExpireTime 自动释放
- **WHEN** 设置 ExpireTime = 5f，回收对象后 Update 累计 6 秒
- **THEN** 过期对象被 onDestroy 回调销毁，TotalCount 减少

### Requirement: SetLocked 锁定
ObjectPool SHALL 支持通过 SetLocked 阻止自动释放。

#### Scenario: 锁定后不自动释放
- **WHEN** 调用 SetLocked(true) 后超过 ExpireTime
- **THEN** 对象不被释放

### Requirement: ObjectPoolManager 多池管理
ObjectPoolManager SHALL 管理多个 ObjectPool 实例。

#### Scenario: CreatePool 创建并获取
- **WHEN** 调用 CreatePool<T>(name, options) 后调用 GetPool<T>(name)
- **THEN** 返回刚创建的池实例

#### Scenario: DestroyPool 销毁池
- **WHEN** 调用 DestroyPool<T>(name)
- **THEN** HasPool<T>(name) 返回 false

#### Scenario: 不同类型同名池共存
- **WHEN** 调用 CreatePool<string>(name) 和 CreatePool<int>(name)
- **THEN** 两个池独立存在，互不影响
