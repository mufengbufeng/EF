# Design: EntityView 碰撞桥接机制

## Context
当前 EntityBase 是纯 C# 类，用于游戏逻辑的解耦和对象池管理。Unity 的物理事件（OnTriggerEnter2D 等）只会触发在 MonoBehaviour 组件上，因此 Entity 无法直接接收这些事件。

## Goals
- 保留现有 Entity 架构不变
- 使 Entity 能够响应 Unity 物理事件
- 保持代码简洁，避免过度抽象

## Non-Goals
- 不改变 EntityBase 继承 MonoBehaviour
- 不引入复杂的 ECS 模式

## Decisions

### 方案选择：EntityView 桥接模式
选择在 GameObject 上添加 EntityView 组件作为桥梁，而不是：
1. **修改 EntityBase 继承 MonoBehaviour** - 会破坏现有架构和对象池逻辑
2. **使用 Physics2D.OverlapXXX 轮询检测** - 性能较差，每帧需要检测所有实体
3. **让 Entity 直接作为组件添加到 GameObject** - 与当前设计理念冲突

### 接口设计
```csharp
// 碰撞处理器接口
public interface ICollisionHandler
{
    void HandleTriggerEnter2D(Collider2D other);
}

// EntityView 组件
public class EntityView : MonoBehaviour
{
    public EntityBase Entity { get; set; }
    
    private void OnTriggerEnter2D(Collider2D other)
    {
        if (Entity is ICollisionHandler handler)
        {
            handler.HandleTriggerEnter2D(other);
        }
    }
}
```

### 注入时机
在 `EntityManager.ShowEntityAsync` 中，实例化 GameObject 后：
1. 检查是否已有 EntityView 组件
2. 如果没有，动态添加
3. 设置 Entity 引用

在 `EntityManager.HideEntity` 中，清理 EntityView 的引用。

## Risks / Trade-offs

| 风险 | 缓解措施 |
|------|----------|
| EntityView 引用未及时清理导致内存泄漏 | 在 HideEntity 和 OnRecycle 中强制清除 |
| 预制体上忘记添加 EntityView | EntityManager 自动补充 |
| 多个 EntityView 组件冲突 | 使用 GetOrAddComponent 模式 |

## Migration Plan
1. 添加 ICollisionHandler 接口和 EntityView 组件
2. 修改 BulletEntity 实现接口
3. 修改 EntityManager 注入逻辑
4. 更新预制体（可选，EntityManager 会自动补充）

## Open Questions
- 是否需要支持 OnCollisionEnter2D（非 Trigger）？
  - 当前设计支持扩展，后续按需添加
