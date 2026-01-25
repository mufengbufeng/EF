# Implementation Tasks

## 1. Core Interfaces
- [x] 1.1 创建 `IEntity.cs` - 实体接口定义
- [x] 1.2 创建 `IEntityGroup.cs` - 实体组接口定义
- [x] 1.3 创建 `IEntityHelper.cs` - 实例化辅助接口
- [x] 1.4 创建 `IEntityManager.cs` - 实体管理器接口
- [x] 1.5 创建 `EntityGroupOptions.cs` - 实体组配置类

## 2. Base Classes
- [x] 2.1 创建 `EntityBase.cs` - IEntity 的抽象基类实现
- [x] 2.2 创建 `EntityGroup.cs` - IEntityGroup 的实现类
- [x] 2.3 创建 `EntityManager.cs` - IEntityManager 的实现类
- [x] 2.4 创建 `DefaultEntityHelper.cs` - 默认的 IEntityHelper 实现

## 3. Integration
- [x] 3.1 在 `ModuleSystem` 中注册 EntityManager
- [x] 3.2 添加单元测试（如有测试框架）

## 4. Documentation
- [x] 4.1 创建 README.md 说明使用方法
- [x] 4.2 添加示例代码

## 5. Validation
- [x] 5.1 编译通过，无警告
- [ ] 5.2 运行时测试实体创建和回收
- [ ] 5.3 测试实体层级 Attach/Detach
- [ ] 5.4 测试对象池复用
