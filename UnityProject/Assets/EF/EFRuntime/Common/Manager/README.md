# ModuleSystem 模块管理

`ModuleSystem` 提供一个线程安全的注册中心，用于托管框架内实现了 `IEFManager` 的各类运行时模块。核心能力如下：

- **注册与别名**：通过 `ModuleSystem.Register` 将模块绑定到接口 / 抽象类，并可选择同时以具体类型注册，方便依赖方获取。
- **检索**：使用 `ModuleSystem.Get` 或 `TryGet` 在任意位置解析模块，避免手动保存单例引用。
- **更新驱动**：在游戏主循环中调用 `ModuleSystem.Update(elapseSeconds, realElapseSeconds)`，即可批量调度所有模块的逐帧逻辑。
- **生命周期管理**：支持 `Unregister` 移除模块（可选自动 `Shutdown`），以及 `ShutdownAll` 一键关闭全部模块，常用于游戏退出或热重载。

## 使用建议

1. 启动阶段为必要模块创建实例，并通过 `ModuleSystem.Register` 注册。例如：
   ```csharp
   ModuleSystem.Register<IDebuggerManager>(DebuggerManager.Instance);
   ModuleSystem.Register<IResourceManager>(new ResourceManager(), exposeConcreteType: true);
   ```
2. 框架入口（如 `MonoBehaviour`）中调用 `ModuleSystem.Update`，确保模块获得逐帧更新。
3. 在退出、切场景或需要重置框架时调用 `ModuleSystem.ShutdownAll`，释放内部资源。
4. 若需要替换模块实现，可在注册时传入 `replace: true`，系统会自动卸载旧实例并调用其 `Shutdown`。
