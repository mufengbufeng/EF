# Change: 添加无限滚动背景（2D SpriteRenderer）

## Why
飞机大战的固定相机玩法需要持续向下滚动的背景来营造飞行感，同时需要可控速度以配合后续节奏与表现效果。

## What Changes
- 新增 World SpriteRenderer 的纵向向下无限滚动背景能力
- 支持运行时可调的滚动速度（含 0 速度暂停）
- 预留背景切换接口，便于后续关卡切换

## Impact
- 影响规格：background-scroll
- 影响代码：GamePlay 相关背景脚本与预制体（具体路径待实现阶段确认）
