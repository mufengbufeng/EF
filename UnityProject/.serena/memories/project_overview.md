# 项目概览（UnityProject）

## 目的
- 这是一个基于 Unity 的模块化框架项目（EasyFramework / EF），并集成 HybridCLR 实现热更新。
- 运行时框架代码主要位于 `Assets/EF/EFRuntime/`，游戏代码分为 Runtime 与 HotFix 两部分。

## 技术栈
- Unity 6000（Windows 11）
- C# / Unity
- HybridCLR（热更新）
- YooAsset（AssetBundle 与资源管理）
- UniTask（异步）
- Luban（配置）

## 目录结构（关键）
- `Assets/EF/`：框架核心代码
- `Assets/GameScripts/Runtime/`：随主包编译的业务代码
- `Assets/GameScripts/HotFix/`：可热更新的业务代码
- `Assets/HybridCLRGenerate/`：HybridCLR 生成与配置
- `Bundles/`：资源构建输出（含 HotUpdate 包）
- `openspec/`：规格驱动开发（OpenSpec）文档
