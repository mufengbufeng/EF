## Why

PlayerAvatarEntity 当前是一个 770 行的"上帝实体"，同时承担了拖拽输入、自动攻击、生命值/死亡、动画控制和位置约束五项独立职责。Feature 系统已经就绪（`EF.Feature`），但尚未被任何实体使用。通过将具体行为下沉到 Feature 中，可以降低实体复杂度、提高行为复用性，同时验证 Feature 框架在实际业务中的适用性。

## What Changes

- **扩展 Feature 框架**：为 `IFeature` 增加 `OnSetup(object data)` 数据接收点，`IFeatureContainer` 增加 `AddFeature<T>(object data)` 和 `SetupFeature<T>(object data)` 重载，支持 Feature 创建时传入配置数据
- **新增强类型 Feature 基类**：`FeatureBase<TData>` 提供类型安全的 `OnSetup(TData data)` 虚方法
- **拆分 PlayerAvatarEntity 为四个 Feature**：
  - `HealthFeature`：生命值管理、受伤判定、死亡通知
  - `DragInputFeature`：鼠标/触控拖拽输入、偏移量对齐
  - `AttackFeature`：自动攻击计时、默认子弹发射、自定义攻击执行器
  - `PositionClampFeature`：摄像机可视区域边界约束
- **重构 PlayerAvatarEntity 为编排者**：仅保留 Handle 管理、Feature 注册/移除、状态编排和对外 API（IHealth 回调转发）
- **Feature 生命周期采用方案 B**：OnShow 时 AddFeature + 注册回调，OnHide 时清理回调 + RemoveFeature

## Capabilities

### New Capabilities
- `feature-data-init`: Feature 框架数据初始化扩展——为 IFeature/IFeatureContainer 增加数据传递能力
- `avatar-features`: 玩家飞机实体 Feature 拆分——HealthFeature、DragInputFeature、AttackFeature、PositionClampFeature 四个独立特性

### Modified Capabilities

## Impact

- **框架层（EF.Runtime）**：`IFeature`、`FeatureBase`、`IFeatureContainer`、`FeatureContainer` 需要扩展，属于 **BREAKING** 变更（新增接口方法）
- **业务层（GameLogic）**：`PlayerAvatarEntity` 大幅精简，新增 4 个 Feature 类；`PlayerAvatarBehaviorData` 可能需要拆分为各 Feature 的配置数据
- **碰撞检测**：`BulletEntity` 无需改动（Entity 仍实现 IHealth，通过回调转发）
- **模块层**：`PlayerAvatarModule` 无需改动（Entity 对外接口不变）
