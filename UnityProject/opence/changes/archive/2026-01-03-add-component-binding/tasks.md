# Implementation Tasks

## 1. Core Feature Interfaces
- [x] 1.1 创建 `IFeature.cs` - 特性接口定义
- [x] 1.2 创建 `IFeatureContainer.cs` - 特性容器接口定义

## 2. Feature Attributes
- [x] 2.1 创建 `AllowMultipleAttribute.cs` - 多实例特性标记
- [x] 2.2 创建 `RequireFeatureAttribute.cs` - 特性依赖标记

## 3. Feature Base Class
- [x] 3.1 创建 `FeatureBase.cs` - IFeature 的抽象基类实现

## 4. Feature Container Implementation
- [x] 4.1 创建 `FeatureContainer.cs` - IFeatureContainer 的实现类
- [x] 4.2 实现特性添加逻辑（支持单例/多例）
- [x] 4.3 实现特性获取逻辑（泛型和类型参数）
- [x] 4.4 实现特性移除逻辑
- [x] 4.5 实现特性启用/禁用逻辑
- [x] 4.6 实现特性依赖检查

## 5. Entity Integration
- [x] 5.1 扩展 `IEntity.cs` - 添加 `Features` 属性
- [x] 5.2 修改 `EntityBase.cs` - 实现特性容器并驱动更新

## 6. Examples
- [x] 6.1 创建示例特性（PositionFeature, RenderFeature, HealthFeature, AttackFeature 等）
- [x] 6.2 创建使用示例代码

## 7. Documentation
- [x] 7.1 创建 README.md 说明使用方法
- [x] 7.2 添加特性开发指南

## 8. Validation
- [x] 8.1 编译通过，无警告
- [x] 8.2 测试特性添加和获取
- [x] 8.3 测试特性移除
- [x] 8.4 测试特性启用/禁用
- [x] 8.5 测试特性生命周期回调
- [x] 8.6 测试多实例特性
- [x] 8.7 测试特性依赖检查

## 实现摘要

### 新增文件

- `Assets/EF/EFRuntime/Feature/IFeature.cs` - 特性接口
- `Assets/EF/EFRuntime/Feature/IFeatureContainer.cs` - 特性容器接口
- `Assets/EF/EFRuntime/Feature/AllowMultipleAttribute.cs` - 多实例标记特性
- `Assets/EF/EFRuntime/Feature/RequireFeatureAttribute.cs` - 特性依赖标记特性
- `Assets/EF/EFRuntime/Feature/FeatureBase.cs` - 特性抽象基类
- `Assets/EF/EFRuntime/Feature/FeatureContainer.cs` - 特性容器实现
- `Assets/EF/EFRuntime/Feature/Examples/ExampleFeatures.cs` - 示例特性
- `Assets/EF/EFRuntime/Feature/Examples/ExampleFeatureUsage.cs` - 使用示例
- `Assets/EF/EFRuntime/Feature/README.md` - 文档

### 修改文件

- `Assets/EF/EFRuntime/Entity/IEntity.cs` - 添加 `Features` 属性
- `Assets/EF/EFRuntime/Entity/EntityBase.cs` - 实现特性容器并驱动特性更新

### 功能特性

1. **特性管理**：支持动态添加、获取、移除特性
2. **单例/多例**：默认单例模式，支持 `[AllowMultiple]` 标记允许多实例
3. **特性依赖**：通过 `[RequireFeature(typeof(T))]` 标记特性依赖关系
4. **生命周期**：支持 OnInit/OnEnable/OnDisable/OnDestroy 回调
5. **自动更新**：Entity 的 OnUpdate 自动驱动所有已启用特性的更新
6. **启用/禁用**：支持运行时启用/禁用特性
