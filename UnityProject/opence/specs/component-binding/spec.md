# component-binding Specification

## Purpose
TBD - created by archiving change add-component-binding. Update Purpose after archive.
## Requirements
### Requirement: 添加组件到实体

系统 SHALL 允许在运行时动态添加组件到实体，支持泛型和类型参数两种方式。添加组件后 SHALL 自动调用组件的 OnInit 方法。

#### Scenario: 添加单个组件

```csharp
IEntity entity = entityManager.GetEntity(entityId);
var transform = entity.Components.AddComponent<TransformComponent>();
// transform.OnInit() 被自动调用
```

#### Scenario: 添加多个不同类型组件

```csharp
var entity = GetPlayerEntity();
entity.Components.AddComponent<PositionComponent>();
entity.Components.AddComponent<RenderComponent>();
entity.Components.AddComponent<PhysicsComponent>();
```

### Requirement: 获取实体上的组件

系统 SHALL 支持获取单个组件或多个同类型组件（当标记 AllowMultiple 时）。当组件不存在时，GetComponent SHALL 返回 null。

#### Scenario: 获取单个组件

```csharp
IEntity entity = entityManager.GetEntity(entityId);
var position = entity.Components.GetComponent<PositionComponent>();
if (position != null)
{
    Vector3 pos = position.Value;
}
```

#### Scenario: 获取多个同类型组件

```csharp
[AllowMultiple]
public class BuffComponent : ComponentBase { }

var buffs = entity.Components.GetComponents<BuffComponent>();
foreach (var buff in buffs)
{
    buff.ApplyEffect();
}
```

#### Scenario: 判断组件是否存在

```csharp
if (entity.Components.HasComponent<RenderComponent>())
{
    entity.Components.SetComponentEnabled<RenderComponent>(true);
}
```

### Requirement: 移除实体上的组件

系统 SHALL 支持按类型或按实例移除组件。移除组件时 SHALL 调用组件的 OnDestroy 方法，并从容器中移除该组件。

#### Scenario: 按类型移除组件

```csharp
bool removed = entity.Components.RemoveComponent<PhysicsComponent>();
if (removed)
{
    // PhysicsComponent.OnDestroy() 已被调用
}
```

#### Scenario: 按实例移除组件

```csharp
var component = entity.Components.GetComponent<BuffComponent>();
entity.Components.RemoveComponent(component);
```

### Requirement: 组件生命周期管理

系统 SHALL 在组件添加、启用、禁用、销毁时触发相应的生命周期回调。OnInit 只在组件首次添加时调用一次；OnEnable/OnDisable 在组件启用状态变化时调用；OnDestroy 在组件移除时调用。

#### Scenario: 组件初始化

```csharp
public class MyComponent : ComponentBase
{
    public override void OnInit()
    {
        // 只在组件首次添加时调用一次
        // 可以在这里安全地访问 Entity
        Debug.Log($"Component initialized on {Entity.Id}");
    }
}
```

#### Scenario: 组件启用/禁用

```csharp
public class RenderComponent : ComponentBase
{
    public override void OnEnable()
    {
        // 组件被启用时调用
        if (Handle != null) Handle.SetActive(true);
    }

    public override void OnDisable()
    {
        // 组件被禁用时调用
        if (Handle != null) Handle.SetActive(false);
    }

    public override void OnUpdate(float elapseSeconds, float realElapseSeconds)
    {
        // 只在 Enabled = true 时调用
    }
}
```

#### Scenario: 组件销毁

```csharp
public class AudioComponent : ComponentBase
{
    private AudioSource _source;

    public override void OnDestroy()
    {
        // 组件从实体移除或实体回收时调用
        if (_source != null)
        {
            UnityEngine.Object.Destroy(_source);
        }
    }
}
```

### Requirement: 组件启用/禁用控制

系统 SHALL 支持在不移除组件的情况下禁用组件。禁用的组件 MUST NOT 接收 OnUpdate 回调。

#### Scenario: 禁用和启用组件

```csharp
// 禁用渲染组件
entity.Components.SetComponentEnabled<RenderComponent>(false);

// 稍后重新启用
entity.Components.SetComponentEnabled<RenderComponent>(true);
```

#### Scenario: 组件内部控制自身启用状态

```csharp
public class AutoDisableComponent : ComponentBase
{
    public float Lifetime = 5f;
    private float _elapsed;

    public override void OnUpdate(float elapseSeconds, float realElapseSeconds)
    {
        _elapsed += elapseSeconds;
        if (_elapsed >= Lifetime)
        {
            Enabled = false; // 禁用自身
        }
    }
}
```

### Requirement: 多实例组件支持

系统 SHALL 支持通过 `[AllowMultiple]` 标记允许同类型组件有多个实例。默认情况下，同类型组件只能有一个实例。

#### Scenario: 单实例组件（默认行为）

```csharp
public class HealthComponent : ComponentBase
{
    public int Health;
}

// 添加第一个
entity.Components.AddComponent<HealthComponent>();

// 再次添加会返回已存在的实例或替换（取决于实现）
var health = entity.Components.AddComponent<HealthComponent>();
// health 是之前添加的同一个实例
```

#### Scenario: 多实例组件

```csharp
[AllowMultiple]
public class StatusEffect : ComponentBase
{
    public string EffectName;
    public float Duration;
}

// 可以添加多个
entity.Components.AddComponent<StatusEffect>();
entity.Components.AddComponent<StatusEffect>();
entity.Components.AddComponent<StatusEffect>();

var effects = entity.Components.GetComponents<StatusEffect>();
// effects.Length == 3
```

### Requirement: 组件依赖声明

系统 SHALL 支持通过 `[RequireComponent]` 声明组件依赖。添加组件时，系统 MUST 检查依赖是否存在，若不存在则抛出 InvalidOperationException。

#### Scenario: 组件依赖检查

```csharp
[RequireComponent(typeof(TransformComponent))]
public class RenderComponent : ComponentBase
{
    public override void OnInit()
    {
        // TransformComponent 必定存在
        var transform = Entity.Components.GetComponent<TransformComponent>();
    }
}

// 如果实体没有 TransformComponent，添加 RenderComponent 时会抛出异常
```

### Requirement: Entity 自动驱动组件更新

EntityBase.OnUpdate SHALL 自动转发给所有启用的组件。禁用的组件 MUST NOT 接收 OnUpdate 回调。

#### Scenario: 组件自动更新

```csharp
public class RotateComponent : ComponentBase
{
    public float RotationSpeed = 90f;

    public override void OnUpdate(float elapseSeconds, float realElapseSeconds)
    {
        if (Handle != null)
        {
            Handle.transform.Rotate(0f, elapseSeconds * RotationSpeed, 0f);
        }
    }
}

// EntityBase.OnUpdate 实现
public override void OnUpdate(float elapseSeconds, float realElapseSeconds)
{
    // 自动更新所有启用的组件
    Components.Update(elapseSeconds, realElapseSeconds);
}
```

### Requirement: 遍历实体上的所有组件

系统 SHALL 支持获取实体上所有组件的只读列表，用于遍历或批量操作。

#### Scenario: 遍历所有组件

```csharp
var allComponents = entity.Components.GetAllComponents();
foreach (var component in allComponents)
{
    Debug.Log($"Component: {component.GetType().Name}, Enabled: {component.Enabled}");
}
```

#### Scenario: 组件统计

```csharp
int count = entity.Components.ComponentCount;
Debug.Log($"Entity {entity.Id} has {count} components");
```

### Requirement: 组件访问所属实体

组件 SHALL 可以访问其所属的实体，用于获取其他组件或实体属性。IComponent 接口 MUST 提供 Entity 属性。

#### Scenario: 组件访问其他组件

```csharp
public class AttackComponent : ComponentBase
{
    public void Attack()
    {
        // 获取同一实体上的其他组件
        var health = Entity.Components.GetComponent<HealthComponent>();
        var anim = Entity.Components.GetComponent<AnimationComponent>();

        health.TakeDamage(10);
        anim.Play("Attack");
    }
}
```

#### Scenario: 组件访问实体属性

```csharp
public class FollowPlayerComponent : ComponentBase
{
    public override void OnUpdate(float elapseSeconds, float realElapseSeconds)
    {
        // 访问实体的 Id
        Debug.Log($"Updating entity {Entity.Id}");

        // 访问实体的 Handle
        if (Entity.Handle != null)
        {
            // 执行跟随逻辑
        }
    }
}
```

