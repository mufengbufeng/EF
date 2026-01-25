# background-scroll Specification

## Purpose
TBD - created by archiving change add-infinite-scroll-background. Update Purpose after archive.
## Requirements
### Requirement: 纵向向下无限滚动背景
系统 MUST 在固定相机下提供纵向向下的无限滚动背景，并保持滚动连续无缝。

#### Scenario: 背景连续循环且不在视口中间重排
- **WHEN** 背景以设定速度向下滚动
- **THEN** 当任一背景片段的上边界低于相机下边界时，必须将其移动到队列顶部以保持连续
- **AND** 重排行为必须发生在该片段完全离开视口之后

### Requirement: 运行时自动计算拼接尺寸
系统 MUST 在运行时依据 SpriteRenderer 的实际尺寸计算循环间距，避免依赖手工填写尺寸。

#### Scenario: 自动读取尺寸并设置间距
- **WHEN** 组件初始化时读取 SpriteRenderer.bounds.size
- **THEN** 使用该高度作为循环间距并完成初始排布

### Requirement: 可配置滚动速度
系统 MUST 允许在运行时配置并调整背景滚动速度，速度为 0 时视为暂停；正值向下，负值向上。

#### Scenario: 运行时调整速度与方向
- **WHEN** 游戏在运行时修改滚动速度为正值或负值
- **THEN** 背景移动方向应分别向上或向下并立即生效

### Requirement: 可选的背景切换接口
系统 MUST 提供可选接口用于替换背景 Sprite 并重置布局，以支持后续关卡切换。

#### Scenario: 切换背景资源
- **WHEN** 在运行时指定新的背景 Sprite
- **THEN** 系统应重新计算尺寸并重置背景排布以保持无缝滚动

### Requirement: 背景片段对象池复用
系统 MUST 使用对象池复用背景片段实例，避免在无限滚动过程中频繁创建与销毁。

#### Scenario: 片段复用
- **WHEN** 背景片段需要被补齐或重排
- **THEN** 系统应从对象池取出或回收实例完成复用

