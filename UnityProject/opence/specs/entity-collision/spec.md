# entity-collision Specification

## Purpose
定义 Entity 与 Unity 2D 物理系统之间的碰撞事件桥接机制，使纯 C# Entity 类能够响应 OnTriggerEnter2D 等物理事件。
## Requirements
### Requirement: 碰撞事件桥接
系统 SHALL 提供 EntityView 组件，作为 Unity 物理事件与 Entity 之间的桥梁，使非 MonoBehaviour 的 Entity 能够响应碰撞事件。

#### Scenario: 子弹碰撞检测
- **WHEN** 子弹的 Collider2D 触发 OnTriggerEnter2D
- **THEN** EntityView 组件将事件转发给关联的 Entity（如果实现了 ICollisionHandler）

#### Scenario: 碰撞事件上下文传递
- **WHEN** 发生碰撞事件
- **THEN** 碰撞上下文（碰撞双方信息）被正确传递给 Entity

### Requirement: 碰撞处理器接口
系统 SHALL 提供 ICollisionHandler 接口，Entity 可实现该接口以接收碰撞事件。

#### Scenario: Entity 实现碰撞接口
- **WHEN** Entity 实现 ICollisionHandler 接口
- **THEN** 该 Entity 可以在 HandleCollision 方法中处理碰撞逻辑

### Requirement: EntityView 自动注入
EntityManager 在实例化 Entity 时 SHALL 自动查找或添加 EntityView 组件，并建立 Entity 与 EntityView 的关联。

#### Scenario: 自动关联 EntityView
- **WHEN** EntityManager 实例化一个带有 Collider2D 的 Entity
- **THEN** 自动为 GameObject 添加或复用 EntityView 组件
- **AND** 将 Entity 引用注入到 EntityView

#### Scenario: 实体回收时清理引用
- **WHEN** Entity 被隐藏或回收
- **THEN** EntityView 中的 Entity 引用被清除，避免内存泄漏

