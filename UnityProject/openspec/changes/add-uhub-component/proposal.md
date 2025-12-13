# 添加 UHubComponent 提案

## 概述
为 UI 框架添加 UHubComponent 组件，提供自动化的组件绑定和统一的事件管理功能，简化 UIView 的组件引用和事件处理逻辑。

## 动机
当前 UIView 实现中，开发者需要：
1. 手动从 ReferenceCollector 获取组件引用
2. 手动绑定和解绑定事件监听器
3. 在 OnRelease 中手动清理所有事件绑定

这些重复性工作容易出错且维护困难。UHubComponent 将通过命名规范和反射自动处理这些操作。

## 目标
1. 提供基于命名规范的自动组件绑定功能
2. 统一管理所有事件绑定，自动在适当时机清理
3. 保持与现有 MVC 架构的完全兼容性
4. 简化 UIView 子类的实现复杂度

## 设计原则
- **自动化**：通过命名规范减少手动配置
- **生命周期一致**：跟随 UIView 的生命周期
- **向后兼容**：不影响现有代码
- **可选使用**：开发者可选择是否使用 UHub 功能

## 影响范围
- 新增 UHubComponent 类
- 扩展 UIView 基类以支持 UHub 集成
- 不会影响现有 UIView、UIController 或 UIModel 实现

## 实现方案
### 核心组件
1. **UHubComponent**：主要功能类，负责组件绑定和事件管理
2. **IEventBinding**：事件绑定接口，支持不同类型的事件
3. **ComponentBinder**：组件绑定器，处理反射和命名规范匹配

### 命名规范
- 字段命名：`private Button _startBtn` → 自动查找名为 "StartBtn" 的组件
- 属性命名：`public Button StartButton { get; private set; }` → 自动查找名为 "StartButton" 的组件

### 事件管理
- 统一的事件绑定接口
- 自动在 UIView.OnRelease 时清理所有绑定
- 支持 UnityEvent、C# Event、Action 等多种事件类型

## 后续步骤
1. 获得架构审查批准
2. 实施核心功能开发
3. 编写单元测试和集成测试
4. 更新文档和示例代码
5. 逐步在新 UI 界面中采用