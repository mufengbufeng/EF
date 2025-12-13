# FrifloEcs 模块

该目录用于集成和管理 Friflo.Engine.ECS 相关功能，包括：

- `IFrifloEcsManager`：定义框架内统一的 Friflo ECS 管理接口。
- `FrifloEcsManager`：具体实现，负责 `EntityStore` 的创建与管理，以及 `SystemRoot` 系统组的调度更新。

推荐在游戏启动时通过 `ModuleSystem.Get<IFrifloEcsManager>()` 获取管理器，并在热更或业务层中注册自定义的 `QuerySystem` / `BaseSystem`。
