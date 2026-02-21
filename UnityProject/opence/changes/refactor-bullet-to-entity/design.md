# Design: 重构子弹为 Entity 系统

## Context
当前子弹系统的实现:
- BulletModule 使用自定义对象池管理子弹 GameObject
- 使用 BulletCollisionHandler MonoBehaviour 处理碰撞
- 子弹在 BulletModule.Update 中移动和边界检测
- 子弹不是 Entity,与玩家/敌人的架构不一致

**问题:**
1. 架构不统一:玩家和敌人使用 Entity,子弹使用 GameObject + MonoBehaviour
2. 重复代码:BulletModule 实现了对象池,而 EntityManager 已有对象池
3. 难以扩展:如果要添加子弹特性(如追踪、爆炸),需要修改多个地方
4. 生命周期不清晰:子弹的生命周期由 BulletModule 管理,不统一

**目标:**
将子弹重构为标准的 Entity,利用现有的 Entity 系统架构。

## Goals / Non-Goals

**Goals:**
- 将子弹实现为 BulletEntity,继承 EntityBase
- 使用 EntityManager 管理子弹的创建和销毁
- 使用 Entity 的对象池机制,移除 BulletModule 的对象池
- 在 BulletEntity 中实现碰撞检测(OnTriggerEnter2D)
- 统一架构,所有游戏对象都是 Entity

**Non-Goals:**
- 不改变子弹的外部行为(移动、碰撞、伤害)
- 不实现子弹的新特性(追踪、爆炸等)
- 不修改玩家和敌人的实现

## Decisions

### 1. BulletEntity 作为 MonoBehaviour + EntityBase
**决策:** BulletEntity 继承 EntityBase,同时作为 MonoBehaviour 挂载到预制体上。

**理由:**
- 需要使用 OnTriggerEnter2D,必须是 MonoBehaviour
- 继承 EntityBase 可以使用 Entity 的生命周期管理
- 与 EnemyEntity 和 PlayerAvatarEntity 的实现方式一致

**实现方式:**
```csharp
public class BulletEntity : EntityBase
{
    private GameObject _handleField;
    public override GameObject Handle 
    { 
        get => _handleField; 
        set => _handleField = value; 
    }

    private void OnTriggerEnter2D(Collider2D other)
    {
        // 碰撞检测逻辑
    }
}
```

**注意:** BulletEntity 本身是 MonoBehaviour,会挂载到 BulletCommon.prefab 上。

### 2. 移除 BulletModule 的对象池管理
**决策:** BulletModule 不再管理对象池,完全依赖 EntityManager。

**理由:**
- 避免重复实现对象池逻辑
- EntityManager 已有完整的对象池机制
- 简化 BulletModule 的职责,只负责发射逻辑

**影响:**
- 移除 `_bulletPool`, `_activeBullets`, `_recycleIndices`
- 移除 `CreateBulletInstance`, `OnBulletSpawn`, `OnBulletRecycle`, `OnBulletDestroy`
- 移除 `Update` 方法中的子弹移动逻辑

### 3. 子弹移动逻辑放在 BulletEntity.OnUpdate
**决策:** 子弹的移动和边界检测在 BulletEntity.OnUpdate 中实现。

**理由:**
- 符合 Entity 的架构模式
- 每个实体负责自己的更新逻辑
- EntityManager 会自动调用所有实体的 OnUpdate

**实现方式:**
```csharp
public override void OnUpdate(float elapseSeconds, float realElapseSeconds)
{
    base.OnUpdate(elapseSeconds, realElapseSeconds);
    
    // 移动子弹
    Handle.transform.position += _direction * _speed * elapseSeconds;
    
    // 边界检测
    if (IsOutOfBounds())
    {
        HideSelf();
    }
}
```

### 4. 碰撞检测在 BulletEntity 内部实现
**决策:** 使用 OnTriggerEnter2D 在 BulletEntity 内部实现碰撞检测。

**理由:**
- 碰撞逻辑与子弹紧密相关,应内聚在 BulletEntity 中
- 不需要额外的 BulletCollisionHandler 组件
- 简化代码,减少组件数量

**实现方式:**
```csharp
private void OnTriggerEnter2D(Collider2D other)
{
    // 获取目标实体
    EntityBase entity = other.GetComponent<EntityBase>();
    if (entity == null) return;
    
    // 友军判断
    if (!ShouldDamage(entity)) return;
    
    // 应用伤害
    IHealth health = entity as IHealth;
    health?.TakeDamage(_damage);
    
    // 隐藏自己
    HideSelf();
}
```

### 5. BulletModule.Fire 使用 EntityManager
**决策:** Fire 方法不再从对象池取子弹,而是调用 `EntityManager.ShowEntityAsync`。

**理由:**
- 统一使用 EntityManager 创建实体
- 自动处理资源加载和对象池
- 简化 BulletModule 的实现

**实现方式:**
```csharp
public async void Fire(BulletData data)
{
    int bulletId = GenerateUniqueId();
    await _entityManager.ShowEntityAsync(bulletId, _bulletPrefabName, "Bullet", data);
}
```

**注意:** Fire 方法变为 async,需要处理异步问题。

### 6. 子弹隐藏使用 EntityManager.HideEntity
**决策:** 子弹击中目标或超出边界后,调用 EntityManager.HideEntity 隐藏自己。

**理由:**
- 统一使用 EntityManager 管理生命周期
- 自动回收到对象池
- 触发 OnHide 和 OnRecycle 回调

**实现方式:**
```csharp
private void HideSelf()
{
    IEntityManager entityManager = ModuleSystem.Get<IEntityManager>();
    entityManager?.HideEntity(Id);
}
```

### 7. BulletData 传递给 BulletEntity
**决策:** Fire 时将 BulletData 作为 userData 传递给 ShowEntityAsync。

**理由:**
- Entity 系统支持 userData 参数
- BulletEntity.OnShow 中可以获取 BulletData 并初始化

**实现方式:**
```csharp
// BulletModule.Fire
await _entityManager.ShowEntityAsync(bulletId, _bulletPrefabName, "Bullet", data);

// BulletEntity.OnShow
public override void OnShow(object userData)
{
    if (userData is BulletData data)
    {
        _direction = data.Direction;
        _speed = data.Speed;
        _ownerType = data.OwnerType;
        // ...
    }
}
```

## Risks / Trade-offs

### 风险 1: Fire 方法变为异步
**风险:** `Fire(BulletData data)` 需要调用 `ShowEntityAsync`,子弹创建变为异步。

**影响:**
- 子弹可能不会立即出现(等待资源加载)
- 调用方需要等待 await 或使用 fire-and-forget

**缓解措施:**
- 预加载子弹预制体,确保 ShowEntityAsync 快速完成
- 使用 fire-and-forget 模式,不等待完成
- 在 BulletModule.InitializeAsync 中预加载资源

**实现方式:**
```csharp
public async void Fire(BulletData data)  // fire-and-forget
{
    int bulletId = GenerateUniqueId();
    await _entityManager.ShowEntityAsync(bulletId, _bulletPrefabName, "Bullet", data);
}
```

### 风险 2: 子弹 ID 管理
**风险:** 每次发射子弹需要生成唯一的 entityId。

**影响:**
- 需要实现 ID 生成逻辑
- ID 可能溢出(如果使用 int)

**缓解措施:**
- 使用自增 ID 生成器
- ID 溢出后循环使用(检查是否已存在)
- 或使用 GUID/UUID

**实现方式:**
```csharp
private int _nextBulletId = 1000000; // 子弹 ID 从 1000000 开始

private int GenerateUniqueId()
{
    return _nextBulletId++;
}
```

### 风险 3: EntityGroup 需要手动创建
**风险:** 需要在 BulletModule.InitializeAsync 中创建 "Bullet" EntityGroup。

**影响:**
- 增加初始化代码
- 需要配置 EntityGroup 的对象池选项

**缓解措施:**
- 在 InitializeAsync 中检查并创建 EntityGroup
- 配置合理的对象池参数(初始大小、最大大小)

**实现方式:**
```csharp
public async UniTask InitializeAsync()
{
    if (!_entityManager.HasEntityGroup("Bullet"))
    {
        var options = new EntityGroupOptions
        {
            InitialSize = 20,
            MaxSize = 100,
            AllowMultiSpawn = false
        };
        _entityManager.AddEntityGroup("Bullet", options);
    }
}
```

### Trade-off: 简单性 vs 性能
**选择:** 使用 Entity 系统,牺牲少量性能换取架构一致性。

**考虑:**
- Entity 系统有额外的开销(对象池、生命周期回调)
- 但换来了统一的架构和更好的可维护性
- 对于子弹这种大量创建的对象,性能影响需要测试

**性能优化点:**
- 对象池预热,避免频繁创建
- 边界检测优化,避免每帧计算
- 碰撞层设置,减少不必要的碰撞检测

## Migration Plan

### Phase 1: 创建 BulletEntity
1. 创建 BulletEntity 类,继承 EntityBase
2. 实现生命周期方法(OnInit, OnShow, OnUpdate, OnHide, OnRecycle)
3. 实现碰撞检测逻辑(OnTriggerEnter2D)
4. 将 BulletEntity 挂载到 BulletCommon.prefab

### Phase 2: 重构 BulletModule
1. 添加 IEntityManager 依赖
2. 在 InitializeAsync 中创建 Bullet EntityGroup
3. 重构 Fire 方法使用 ShowEntityAsync
4. 移除对象池相关代码
5. 移除 Update 方法

### Phase 3: 清理和测试
1. 删除 BulletCollisionHandler.cs
2. 更新 IBulletModule 接口
3. 测试子弹生成、碰撞、销毁
4. 性能测试

### Rollback Plan
如果重构后出现问题:
1. 保留原有代码作为备份(git branch)
2. 可以快速回滚到 MonoBehaviour 方案
3. BulletEntity 可以独立禁用,不影响现有系统

## Open Questions

1. **子弹 ID 范围如何分配?**
   - 当前方案:从 1000000 开始自增
   - 其他方案:使用负数 ID,或单独的 ID 生成器

2. **Fire 方法是否需要返回 Entity?**
   - 当前方案:void Fire(BulletData data)
   - 其他方案:UniTask<BulletEntity> Fire(BulletData data)

3. **子弹预制体是否需要预加载?**
   - 当前方案:在 InitializeAsync 中预加载
   - 影响:第一次发射子弹的延迟

4. **EntityGroup 的对象池参数如何配置?**
   - 初始大小:20?
   - 最大大小:100?
   - 需要根据实际游戏情况调整
