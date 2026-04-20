## Context

PlayerAvatarEntity 是当前项目中唯一一个业务实体，承载了拖拽输入、自动攻击、生命值、动画和位置约束五项职责（770 行）。EF.Feature 系统已经完整实现（IFeature、FeatureBase、FeatureContainer、AllowMultiple、RequireFeature），但尚未被任何业务代码使用。

实体使用对象池管理，生命周期为 OnInit → OnShow → OnUpdate → OnHide → OnRecycle。Feature 当前只支持无参构造（`new()` 约束），业务数据只能在 AddFeature 之后通过公开属性手动设置。

## Goals / Non-Goals

**Goals:**
- 将 PlayerAvatarEntity 从 770 行精简为编排层（~150-200 行）
- 验证 Feature 系统在实际业务中的可用性
- 为 Feature 框架增加数据初始化能力，使其可用于后续实体
- 保持 BulletEntity、PlayerAvatarModule 等外部依赖零改动

**Non-Goals:**
- 不重构 BulletEntity、EnemyEntity 等其他实体
- 不改变 EntityBase 的核心生命周期
- 不引入事件总线或消息系统
- 不实现泛型 EntityBase<TFeature> 机制

## Decisions

### 1. Feature 数据初始化：OnSetup(object data) 模式

**选择**：在 IFeature 接口增加 `void OnSetup(object data)` 方法，FeatureBase 提供空实现。

**备选方案**：
- A) 通过构造函数传参 → 需要打破 `new()` 约束，改动大
- B) 仅靠公开属性 → 无框架级约定，容易遗漏
- C) 泛型 IFeature<TData> → 接口层级复杂，容器实现困难

**理由**：OnSetup 模式最小侵入，与现有 OnInit/OnEnable 生命周期自然衔接，FeatureContainer 只需在 AddFeature 后多调一步。通过 `FeatureBase<TData>` 提供类型安全的便捷基类。

### 2. Feature 生命周期：方案 B（OnShow 创建，OnHide 销毁）

**选择**：每次 OnShow 时 AddFeature + 注册回调，OnHide 时清理回调 + RemoveFeature。

**备选方案**：
- A) OnInit 注册，OnShow 刷新数据 → Feature 与 Entity 同生命周期，数据刷新需要额外的 Reset 逻辑

**理由**：方案 B 天然保证每次 Show 时 Feature 状态干净，数据在 AddFeature 时传入（OnSetup），不需要额外的 Reset/清理逻辑。代价是每次 Show 都重新创建 Feature 实例，但对于轻量 Feature 对象来说可忽略不计。

### 3. Feature 间通信：Entity 编排模式

**选择**：Entity 在 OnUpdate 中检查 Feature 状态，通过 SetFeatureEnabled 控制其他 Feature 的启停。

**备选方案**：
- A) Feature 互相引用 → Feature 间耦合
- B) 事件总线 → 引入额外机制，过度设计

**理由**：Entity 已经持有 FeatureContainer，编排逻辑集中在 Entity 中清晰可控。Feature 保持纯粹的能力单元，不需要知道其他 Feature 的存在。

### 4. 对外 API：Entity 回调转发

**选择**：Entity 继续实现 IHealth，内部通过回调字段转发给 HealthFeature。

**理由**：BulletEntity 通过 `targetEntity as IHealth` 做碰撞检测，保持这一接口不变使得外部依赖零改动。Entity 在 OnShow 时将 Feature 方法注册到回调字段，OnHide 时清空。

### 5. Feature 的 OnSetup 调用时机

**选择**：在 AddFeature<T>(object data) 中，OnInit 之前调用 OnSetup。

**理由**：OnSetup 设置配置数据（如攻击间隔、最大生命值），OnInit 使用这些数据进行结构初始化。数据先于逻辑，顺序自然。

## Risks / Trade-offs

- **IFeature 接口变更** → 所有实现 IFeature 的类需增加 OnSetup 方法。当前仅有 FeatureBase 实现，影响可控。
- **Feature 每次重建** → 方案 B 每次 OnShow 创建新 Feature 实例，有少量 GC 压力。对于 4 个轻量 Feature 对象可忽略，若后续有重量级 Feature 可回退到方案 A。
- **Entity 仍实现 IHealth** → 回调转发增加一层间接调用，但换来了外部系统的零改动，值得。
- **回调字段管理** → 需要在 OnHide 时确保清空所有回调，否则可能产生悬挂引用。通过 ResetRuntimeState 统一清理。
