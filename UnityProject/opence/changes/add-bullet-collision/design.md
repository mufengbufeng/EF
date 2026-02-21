# Design: 子弹碰撞检测与伤害系统

## Context
当前游戏中玩家和敌人都可以发射子弹,但子弹击中目标后没有任何反馈,无法实现游戏的核心战斗玩法。需要添加完整的碰撞检测、伤害计算和击中反馈系统。

**约束条件:**
- 使用 Unity 2D 物理系统(Collider2D, Trigger)
- 子弹由对象池管理,需要在回收时清理状态
- 需要区分友军和敌军,避免误伤
- 实体系统已存在(PlayerAvatarEntity, EnemyEntity)

## Goals / Non-Goals

**Goals:**
- 实现子弹击中目标时的碰撞检测
- 基于 OwnerType 判断友军,避免误伤
- 实现生命值系统和伤害计算
- 子弹击中后自动回收到对象池
- 实体死亡时播放动画和隐藏

**Non-Goals:**
- 不实现复杂的伤害类型系统(暴击、穿透等)
- 不实现击中特效和音效(后续迭代)
- 不实现生命值 UI 显示(另一个 change)
- 不实现玩家复活机制

## Decisions

### 1. 使用 enum 替代 string 作为 OwnerTag
**决策:** 将 `BulletData.OwnerTag` 从 `string` 改为 `BulletOwnerType` 枚举。

**理由:**
- 类型安全:编译期检查,避免拼写错误("Player" vs "player")
- 性能优化:enum 比较比 string 比较更快
- 代码可读性:IDE 自动补全,代码意图更清晰
- 易于扩展:后续添加新类型(Neutral, Boss 等)更方便

**替代方案:**
- 保持 string:灵活但易出错,性能略差
- 使用 Layer 系统:Unity 内置,但 Layer 数量有限(32 个)

### 2. 碰撞检测实现方式
**决策:** 在子弹预制体上添加 `CircleCollider2D` 和 `BulletCollisionHandler` MonoBehaviour 脚本。

**理由:**
- Unity 标准做法:使用 OnTriggerEnter2D 事件
- 性能优化:使用 Trigger 而非 Collision,避免物理计算
- 解耦设计:碰撞逻辑独立于 BulletModule
- 对象池兼容:组件在 Spawn/Recycle 时自动激活/禁用

**替代方案:**
- 在 BulletModule.Update 中手动检测:性能差,代码复杂
- 使用 Physics2D.OverlapCircle:需要每帧轮询,性能浪费

### 3. 生命值系统设计
**决策:** 创建 `IHealth` 接口,在 PlayerAvatarEntity 和 EnemyEntity 中实现。

**理由:**
- 接口隔离:BulletCollisionHandler 只依赖 IHealth 接口
- 多态设计:玩家和敌人可以有不同的伤害响应逻辑
- 易于测试:可以 mock IHealth 接口
- 未来扩展:可以添加护盾、伤害吸收等复杂逻辑

**接口定义:**
```csharp
public interface IHealth
{
    float CurrentHealth { get; }
    float MaxHealth { get; }
    bool IsDead { get; }
    void TakeDamage(float damage);
}
```

**替代方案:**
- 创建单独的 Health 组件:增加复杂度,需要额外管理
- 直接在 Entity 中硬编码:缺乏扩展性

### 4. 子弹回收时机
**决策:** 子弹击中目标后立即回收到对象池。

**理由:**
- 避免二次碰撞:子弹击中后立即失效
- 节省内存:不需要等待子弹飞出屏幕
- 对象池效率:快速回收,提高复用率

**实现方式:**
- BulletCollisionHandler 持有对 BulletModule 的回调引用
- 在 OnTriggerEnter2D 中调用回调通知 BulletModule 回收子弹

### 5. 友军判断逻辑
**决策:** 在 BulletCollisionHandler 中判断,只有敌对阵营才造成伤害。

**判断规则:**
- Player 子弹只伤害 Enemy 实体
- Enemy 子弹只伤害 Player 实体

**实现方式:**
```csharp
if (bulletOwnerType == BulletOwnerType.Player && targetEntity is EnemyEntity)
{
    // 造成伤害
}
else if (bulletOwnerType == BulletOwnerType.Enemy && targetEntity is PlayerAvatarEntity)
{
    // 造成伤害
}
```

**替代方案:**
- 使用 Unity Layer Collision Matrix:更灵活,但需要配置 Layer
- 使用 Tag 系统:string 比较,性能略差

### 6. 死亡动画处理
**决策:** 在 TakeDamage 方法中检查生命值,触发死亡时播放动画,延迟隐藏实体。

**理由:**
- 用户体验:玩家能看到死亡反馈
- 代码内聚:死亡逻辑集中在实体内部
- 动画完整性:等待动画播放完再隐藏

**实现方式:**
```csharp
public void TakeDamage(float damage)
{
    _currentHealth -= damage;
    if (_currentHealth <= 0 && !_isDead)
    {
        _isDead = true;
        PlayDeadAnimation();
        // 延迟 1 秒后隐藏实体(等待动画)
        DelayedHide(1.0f);
    }
}
```

## Risks / Trade-offs

### 风险 1: 对象池回收时机冲突
**风险:** 子弹击中时需要立即回收,但对象池可能正在被其他地方访问。

**缓解措施:**
- 使用回调机制,由 BulletModule 统一管理回收
- 在 BulletModule.Update 的末尾批量处理回收请求
- 标记待回收子弹,下一帧再回收

### 风险 2: 碰撞检测性能问题
**风险:** 大量子弹和实体时,碰撞检测可能成为性能瓶颈。

**缓解措施:**
- 使用 Trigger 而非 Collision,避免物理计算
- 配置合理的 Physics2D 设置(Fixed Timestep)
- 限制同时存在的子弹数量
- 后续可以考虑使用 Spatial Hash 或 Quadtree 优化

### 风险 3: 动画播放期间实体被再次击中
**风险:** 敌人死亡动画播放时,可能被再次击中导致重复扣血。

**缓解措施:**
- 使用 IsDead 标志,死亡后不再接受伤害
- 死亡时立即禁用 Collider2D
- 或者设置死亡后的无敌时间

### Trade-off: 简单性 vs 扩展性
**选择:** 当前设计偏向简单性,满足基本需求。

**考虑:**
- 当前没有伤害类型系统(物理、魔法等)
- 当前没有伤害倍率系统(暴击、弱点等)
- 当前没有伤害数字显示

**未来扩展点:**
- 可以在 TakeDamage 中添加 DamageInfo 参数
- 可以通过事件系统通知 UI 层显示伤害数字
- 可以在 IHealth 接口中添加更多方法

## Migration Plan

### Phase 1: 数据结构和接口(无破坏性)
1. 添加 BulletOwnerType 枚举
2. 添加 IHealth 接口
3. 在 BulletData 中同时保留 OwnerTag(string) 和 OwnerType(enum)

### Phase 2: 实现生命值系统
1. 在 PlayerAvatarEntity 和 EnemyEntity 中实现 IHealth
2. 添加初始生命值配置

### Phase 3: 实现碰撞检测
1. 创建 BulletCollisionHandler 脚本
2. 修改 BulletModule 集成碰撞处理

### Phase 4: 清理和优化
1. 移除 BulletData.OwnerTag(string),只保留 OwnerType
2. 更新所有调用代码
3. 测试验证所有功能

### Rollback Plan
如果出现严重问题:
1. 子弹碰撞脚本可以直接禁用(SetActive(false))
2. 生命值系统不影响现有逻辑,可以暂时不调用 TakeDamage
3. BulletData 的 OwnerTag 保持兼容,可以快速回滚

## Open Questions

1. **伤害值如何配置?**
   - 当前方案:硬编码在 BulletCollisionHandler 中(例如 10 点伤害)
   - 未来考虑:在 BulletData 中添加 Damage 字段

2. **玩家死亡后是否需要复活?**
   - 当前方案:玩家死亡后直接隐藏实体
   - 未来考虑:添加 Game Over UI 或复活机制

3. **敌人死亡后是否需要掉落奖励?**
   - 当前方案:敌人死亡后直接隐藏
   - 未来考虑:添加掉落物系统

4. **是否需要伤害数字显示?**
   - 当前方案:不显示伤害数字
   - 未来考虑:通过事件系统通知 UI 层
