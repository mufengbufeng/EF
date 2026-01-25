# background-scroll Specification Delta

## MODIFIED Requirements
### Requirement: 纵向向下无限滚动背景
系统 MUST 在固定相机下提供纵向向下的无限滚动背景，并保持滚动连续无缝。

#### Scenario: 背景连续循环且不在视口中间重排
- **WHEN** 背景以设定速度向下滚动
- **THEN** 当任一背景片段的上边界低于相机下边界时，必须将其移动到队列顶部以保持连续
- **AND** 重排行为必须发生在该片段完全离开视口之后

### Requirement: 可配置滚动速度
系统 MUST 允许在运行时配置并调整背景滚动速度，速度为 0 时视为暂停；正值向下，负值向上。

#### Scenario: 运行时调整速度与方向
- **WHEN** 游戏在运行时修改滚动速度为正值或负值
- **THEN** 背景移动方向应分别向上或向下并立即生效

## ADDED Requirements
### Requirement: 背景片段对象池复用
系统 MUST 使用对象池复用背景片段实例，避免在无限滚动过程中频繁创建与销毁。

#### Scenario: 片段复用
- **WHEN** 背景片段需要被补齐或重排
- **THEN** 系统应从对象池取出或回收实例完成复用
