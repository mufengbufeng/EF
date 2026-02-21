## ADDED Requirements

### Requirement: PlayerAvatarModule 负责玩家实体生成与回收

系统 SHALL 提供 `PlayerAvatarModule`（及其服务接口 `IPlayerAvatarModule`），用于在玩法运行期间生成一个玩家飞机实体，并在退出玩法时统一回收。  
`PlayerAvatarModule` MUST 基于 `IEntityManager` 创建玩家实体，MUST NOT 直接在模块内部使用 `Instantiate` 管理生命周期。

#### Scenario: 场景就绪后生成玩家飞机

**Given** `GamePlayProcedure` 已进入且玩法场景加载完成  
**And** `ReferenceCollector` 已成功绑定 `PlayerPoint`  
**And** `IBulletModule.InitializeAsync()` 已完成  
**When** `GamePlayProcedure` 启动 `PlayerAvatarModule` 的初始化流程  
**Then** `PlayerAvatarModule` 调用 `IEntityManager.ShowEntityAsync(...)` 生成玩家实体  
**And** 玩家实体初始位置与 `PlayerPoint` 对齐  
**And** 玩家实体进入 `player-avatar-behavior` 定义的运行态

### Requirement: PlayerAvatarModule 支持配置化资源与实体组

系统 SHALL 提供配置入口设置玩家预制体资源名、实体组名和基础行为参数。  
`PlayerAvatarModule` MUST NOT 在实现中硬编码玩家资源路径与实体组名。

#### Scenario: 通过配置创建并复用玩家实体组

**Given** 调用方配置 `avatarAssetName` 与 `avatarGroupName`  
**When** `PlayerAvatarModule` 初始化玩家实体组  
**Then** 模块检查目标实体组是否存在  
**And** 不存在时创建实体组并使用 `PlayerAvatarEntity` 工厂  
**And** 已存在时复用该实体组而非重复创建

### Requirement: PlayerAvatarModule 受 GamePlay Scope 生命周期管理

`PlayerAvatarModule` MUST 以玩法作用域（GamePlay scope）注册到 `ModuleSystem`，并在 `ShutdownScope(GamePlayScope)` 时被注销并执行 `Shutdown()`。  
`Shutdown()` MUST 保持幂等：重复调用不会抛错且不会造成重复回收副作用。

#### Scenario: 退出玩法时清理玩家模块与玩家实体

**Given** `PlayerAvatarModule` 已在 `GamePlayScope` 中注册且玩家实体处于显示状态  
**When** `GamePlayProcedure.OnLeave` 调用 `ModuleSystem.ShutdownScope(GamePlayScope)`  
**Then** `PlayerAvatarModule.Shutdown()` 被调用  
**And** 玩家实体被隐藏并从模块内部记录移除  
**And** 再次调用 `Shutdown()` 不产生异常
