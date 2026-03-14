---
name: ef-entity
description: EasyFramework 实体管理模块。使用此 skill 当用户提到 EasyFramework 的实体、EntityManager、GameObject 实例化、对象池复用、实体组、父子实体关系、EntityView、ShowEntity、HideEntity 时。在实现、重构、排错、测试或设计该模块相关功能时必须优先使用此 skill，而不是只在用户显式点名模块时才触发。
---

# EF.Entity 实体管理模块

## 模块定位
该 skill 用于处理 EF.Entity 实体管理模块 的实现、扩展、故障排查与重构任务。回答时先确认业务目标，再映射到该模块的核心抽象与生命周期。

## 何时必须触发
- 用户直接提到：EasyFramework 的实体、EntityManager、GameObject 实例化、对象池复用、实体组、父子实体关系、EntityView、ShowEntity、HideEntity。
- 虽未点名模块，但需求本质落在 EF.Entity 实体管理模块 的职责范围（例如注册、生命周期、依赖关系、性能或稳定性问题）。
- 需要输出可落地代码改动、排障步骤、验证命令或回归检查清单。

## 执行流程（按顺序）
- 明确约束：确认运行环境、调用入口、是否允许改动公共接口。
- 建立映射：定位到对应管理器/接口/数据结构，给出最小改动路径。
- 实施方案：优先增量改造，避免一次性重构引入大范围回归。
- 验证闭环：提供编译、运行、核心流程与边界场景验证步骤。
- 输出结果：给出“变更点 + 原因 + 风险 + 回滚建议”。

## 实施准则
- 保持与 EasyFramework 既有命名、目录结构、生命周期约定一致。
- 先保证正确性，再做性能优化；涉及缓存/池化时说明释放策略。
- 涉及跨模块协作时明确依赖顺序与初始化时机，避免未注册访问。
- 提供最小可运行示例时，优先使用当前项目已有基类与管理器接口。

## 常见故障排查清单
- 注册缺失：检查模块是否在初始化流程中注册，接口与实现是否一致。
- 生命周期错位：确认 OnInit/OnUpdate/OnDestroy（或等价阶段）是否顺序正确。
- 依赖空引用：检查上游模块可用性与获取时机（同步/异步加载后再访问）。
- 数据不同步：确认事件订阅解绑、状态刷新与持久化读写时序是否正确。
- 回归风险：检查是否影响主流程（启动、切场景、返回主界面、暂停恢复）。

## 回答输出模板
1. 目标与约束：一句话说明要解决的问题与边界。
2. 方案与取舍：给出推荐实现和不选其他方案的原因。
3. 关键改动：列出文件/接口/核心代码片段。
4. 验证结果：列出编译与测试步骤、通过/失败结论。
5. 风险与回滚：说明潜在影响和快速回退方案。

## 模块资料（保留参考）
实体管理器负责 GameObject 的实例化、对象池复用和父子关系管理。

## 核心类型

| 类型 | 说明 |
|------|------|
| `IEntityManager` | 实体管理器接口 |
| `EntityManager` | 实体管理器实现 |
| `IEntity` | 实体接口 |
| `EntityBase` | 实体基类 |
| `IEntityGroup` | 实体组接口 |
| `EntityGroup` | 实体组实现 |
| `EntityView` | 实体视图组件（MonoBehaviour） |
| `EntityGroupOptions` | 实体组配置 |

## 使用示例

### 创建实体组

```csharp
// 获取实体管理器
var entityManager = GameLogicEntry.EntityManager;

// 创建实体组
entityManager.AddEntityGroup("Enemy", new EntityGroupOptions
{
    PoolCapacity = 100,
    ExpireTime = 30f,
    AutoReleaseInterval = 5f,
    AllowMultiSpawn = false
});
```

### 显示实体

```csharp
// 异步显示实体
int entityId = entityManager.GenerateEntityId();
IEntity entity = await entityManager.ShowEntityAsync(
    entityId,
    "Prefabs/Enemy",
    "Enemy",
    userData: enemyConfig
);

// 实体初始化后会调用 OnShow
```

### 隐藏实体

```csharp
// 隐藏单个实体
entityManager.HideEntity(entityId);

// 隐藏所有已加载实体
entityManager.HideAllLoadedEntities();
```

### 父子关系

```csharp
// 附加子实体
entityManager.AttachEntity(childId, parentId);

// 分离子实体
entityManager.DetachEntity(childId);
```

### 自定义实体

```csharp
public class EnemyEntity : EntityBase
{
    private int _hp;
    
    public override void OnInit(int id, string assetName, IEntityGroup group, bool isNewInstance, object userData)
    {
        base.OnInit(id, assetName, group, isNewInstance, userData);
        // 初始化逻辑
    }
    
    public override void OnShow(object userData)
    {
        // 显示逻辑
    }
    
    public override void OnHide(bool isShutdown, object userData)
    {
        // 隐藏逻辑
    }
    
    public override void OnUpdate(float elapseSeconds, float realElapseSeconds)
    {
        // 每帧更新
    }
}
```

## 生命周期

```
ShowEntityAsync()
    ↓
从对象池获取或创建实体
    ↓
OnInit() [仅新实例]
    ↓
OnShow()
    ↓
[每帧 OnUpdate() 仅当 Handle.activeInHierarchy]
    ↓
HideEntity()
    ↓
OnHide()
    ↓
回收至对象池 / 销毁
```

## 依赖模块

- `EF.ObjectPool` - 实体对象池
- `EF.Resource` - 资源加载
