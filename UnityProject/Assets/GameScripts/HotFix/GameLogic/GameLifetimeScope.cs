// using System.Linq;
// using System.Reflection;
// using Cysharp.Threading.Tasks;
// using EF.Common;
// using EF.Debugger;
// using EF.Entity;
// using EF.Event;
// using EF.Fsm;
// using EF.Model;
// using EF.ObjectPool;
// using EF.Procedure;
// using EF.Resource;
// using EF.Save;
// using EF.Scene;
// using EF.Sound;
// using EF.Timer;
// using EF.UI;
// using UnityEngine;
// using VContainer;
// using VContainer.Unity;

// namespace GameLogic
// {
//     /// <summary>
//     /// 游戏逻辑层的生命周期作用域
//     /// 使用 VContainer 进行依赖注入，统一管理所有服务
//     /// </summary>
//     public class GameLifetimeScope : LifetimeScope
//     {
//         protected override void Configure(IContainerBuilder builder)
//         {
//             DontDestroyOnLoad(this);
//             Log.Info("[GameLifetimeScope] 开始配置依赖注入容器...");

//             // ========================================
//             // 注册 EF 框架管理器（从 ModuleSystem 桥接）
//             // ========================================
//             RegisterEFManagers(builder);

//             // ========================================
//             // 注册 HotFix 层服务
//             // ========================================
//             RegisterHotFixServices(builder);

//             // ========================================
//             // 注册所有 Procedure（流程）
//             // ========================================
//             RegisterProcedures(builder);

//             Log.Info("[GameLifetimeScope] 依赖注入容器配置完成。");
//         }

//         /// <summary>
//         /// 注册 EF 框架管理器（从 ModuleSystem 获取已注册的实例）
//         /// </summary>
//         private void RegisterEFManagers(IContainerBuilder builder)
//         {
//             // 从 ModuleSystem 桥接 EF 框架的管理器到 VContainer
//             builder.Register(c => ModuleSystem.Get<IResourceManager>(), Lifetime.Singleton);
//             builder.Register(c => ModuleSystem.Get<IEventManager>(), Lifetime.Singleton);
//             builder.Register(c => ModuleSystem.Get<IUIManager>(), Lifetime.Singleton);
//             builder.Register(c => ModuleSystem.Get<ISoundManager>(), Lifetime.Singleton);
//             builder.Register(c => ModuleSystem.Get<ITimerManager>(), Lifetime.Singleton);
//             builder.Register(c => ModuleSystem.Get<IObjectPoolManager>(), Lifetime.Singleton);
//             builder.Register(c => ModuleSystem.Get<IFsmManager>(), Lifetime.Singleton);
//             builder.Register(c => ModuleSystem.Get<IProcedureManager>(), Lifetime.Singleton);
//             builder.Register(c => ModuleSystem.Get<ISaveManager>(), Lifetime.Singleton);
//             builder.Register(c => ModuleSystem.Get<IEntityManager>(), Lifetime.Singleton);
//             builder.Register(c => ModuleSystem.Get<ModelManager>(), Lifetime.Singleton);

//             Log.Info("[GameLifetimeScope] EF 框架管理器注册完成。");
//         }

//         /// <summary>
//         /// 注册 HotFix 层的服务
//         /// </summary>
//         private void RegisterHotFixServices(IContainerBuilder builder)
//         {
//             // 场景管理器（依赖 ResourceManager）
//             // builder.Register<SceneManager>(Lifetime.Singleton);

//             // // 游戏场景管理器（依赖 SceneManager 和 EventManager）
//             // builder.Register<GameSceneManager>(Lifetime.Singleton);

//             // 配置系统（依赖 ResourceManager）
//             builder.Register<ConfigSystem>(Lifetime.Singleton);

//             Log.Info("[GameLifetimeScope] HotFix 层服务注册完成。");
//         }

//         /// <summary>
//         /// 注册所有 Procedure（流程）
//         /// 自动扫描并注册所有继承自 ProcedureBase 的类
//         /// </summary>
//         private void RegisterProcedures(IContainerBuilder builder)
//         {
//             var procedureType = typeof(ProcedureBase);
//             var assembly = Assembly.GetExecutingAssembly();

//             var procedureTypes = assembly.GetTypes()
//                 .Where(t => procedureType.IsAssignableFrom(t) && !t.IsAbstract && !t.IsInterface)
//                 .ToList();

//             foreach (var type in procedureTypes)
//             {
//                 // 注册为 Transient，因为每个流程可能需要独立的实例
//                 builder.Register(type, Lifetime.Transient);
//                 Log.Info($"[GameLifetimeScope] 注册流程: {type.Name}");
//             }

//             Log.Info($"[GameLifetimeScope] 共注册 {procedureTypes.Count} 个流程。");
//         }

//     }
// }