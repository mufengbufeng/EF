## ADDED Requirements

### Requirement: 纵向向下无限滚动背景
系统 MUST 在固定相机下提供纵向向下的无限滚动背景，并保持滚动连续无缝。

#### Scenario: 背景连续循环
- **WHEN** 背景以设定速度向下滚动
- **THEN** 当任一背景超出重置阈值时必须被移动到队列顶部以保持连续

### Requirement: 运行时自动计算拼接尺寸
系统 MUST 在运行时依据 SpriteRenderer 的实际尺寸计算循环间距，避免依赖手工填写尺寸。

#### Scenario: 自动读取尺寸并设置间距
- **WHEN** 组件初始化时读取 SpriteRenderer.bounds.size
- **THEN** 使用该高度作为循环间距并完成初始排布

### Requirement: 可配置滚动速度
系统 MUST 允许在运行时配置并调整背景滚动速度，速度为 0 时视为暂停。

#### Scenario: 运行时调整速度
- **WHEN** 游戏在运行时修改滚动速度
- **THEN** 背景移动速度应立即使用新的配置值

### Requirement: 可选的背景切换接口
系统 MUST 提供可选接口用于替换背景 Sprite 并重置布局，以支持后续关卡切换。

#### Scenario: 切换背景资源
- **WHEN** 在运行时指定新的背景 Sprite
- **THEN** 系统应重新计算尺寸并重置背景排布以保持无缝滚动
