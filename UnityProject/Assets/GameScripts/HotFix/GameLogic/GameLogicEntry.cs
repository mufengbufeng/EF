using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using Cysharp.Threading.Tasks;
using EF.Common;
using EF.Debugger;
using EF.Entity;
using EF.Event;
using EF.Fsm;
using EF.Model;
using EF.ObjectPool;
using EF.Procedure;
using EF.Resource;
using EF.Save;
using EF.Scene;
using EF.Sound;
using EF.Timer;
using EF.UI;
using UnityEngine;

namespace GameLogic
{
    /// <summary>
    /// 热更新游戏逻辑入口
    /// 负责初始化游戏逻辑相关的管理器、模型和ECS系统
    /// </summary>
    public static class GameLogicEntry
    {
        // EF 框架管理器引用
        private static IResourceManager _resourceManager;
        private static IEventManager _eventManager;
        private static IUIManager _uiManager;
        private static ISoundManager _soundManager;
        private static ITimerManager _timerManager;
        private static IObjectPoolManager _objectPoolManager;
        private static IFsmManager _fsmManager;
        private static IProcedureManager _procedureManager;
        private static ISaveManager _saveManager;
        private static ISceneManager _sceneManager;
        private static ModelManager _modelManager;
        private static IEntityManager _entityManager;
        private static IGameSceneManager _gameSceneManager;

        // 游戏配置系统
        private static ConfigSystem _configSystem;

        /// <summary>
        /// 资源管理器
        /// </summary>
        public static IResourceManager Resource => _resourceManager;

        /// <summary>
        /// 事件管理器
        /// </summary>
        public static IEventManager Event => _eventManager;

        /// <summary>
        /// UI 管理器
        /// </summary>
        public static IUIManager UI => _uiManager;

        /// <summary>
        /// 音频管理器
        /// </summary>
        public static ISoundManager Sound => _soundManager;

        /// <summary>
        /// 计时器管理器
        /// </summary>
        public static ITimerManager Timer => _timerManager;

        /// <summary>
        /// 对象池管理器
        /// </summary>
        public static IObjectPoolManager ObjectPool => _objectPoolManager;

        /// <summary>
        /// 状态机管理器
        /// </summary>
        public static IFsmManager Fsm => _fsmManager;

        /// <summary>
        /// 流程管理器
        /// </summary>
        public static IProcedureManager Procedure => _procedureManager;

        /// <summary>
        /// 本地保存管理器
        /// </summary>
        public static ISaveManager Save => _saveManager;

        /// <summary>
        /// 场景管理器
        /// </summary>
        public static ISceneManager Scene => _sceneManager;

        /// <summary>
        /// 模型管理器
        /// </summary>
        public static ModelManager Model => _modelManager;

        /// <summary>
        /// 配置系统
        /// </summary>
        public static ConfigSystem Config => _configSystem;

        /// <summary>
        /// 实体管理器
        /// </summary>
        public static IEntityManager Entity => _entityManager;

        /// <summary>
        /// 游戏场景管理器
        /// </summary>
        public static IGameSceneManager GameScene => _gameSceneManager;

        /// <summary>
        /// 热更新代码入口点
        /// </summary>
        public static void Init()
        {
            Log.Info("[GameLogicEntry] 开始初始化热更新逻辑...");

            // 从 ModuleSystem 获取所有 EF 框架管理器引用
            _resourceManager = ModuleSystem.Get<IResourceManager>();
            _eventManager = ModuleSystem.Get<IEventManager>();
            _uiManager = ModuleSystem.Get<IUIManager>();
            _soundManager = ModuleSystem.Get<ISoundManager>();
            _timerManager = ModuleSystem.Get<ITimerManager>();
            _objectPoolManager = ModuleSystem.Get<IObjectPoolManager>();
            _fsmManager = ModuleSystem.Get<IFsmManager>();
            _procedureManager = ModuleSystem.Get<IProcedureManager>();
            _saveManager = ModuleSystem.Get<ISaveManager>();
            _entityManager = ModuleSystem.Get<IEntityManager>();

            // 从 ModuleSystem 获取 ModelManager（已在 GameEntry 中创建并注册）
            _modelManager = ModuleSystem.Get<ModelManager>();

            // 创建场景管理器
            _sceneManager = new SceneManager(_resourceManager);

            // 创建游戏场景管理器
            _gameSceneManager = new GameSceneManager(_sceneManager, _eventManager);

            Log.Info("[GameLogicEntry] EF 框架管理器初始化完成。");

            MangerLogicInit();

            // 初始化配置系统（但不加载，加载由 InitProcedure 处理）
            _configSystem = new ConfigSystem(_resourceManager);

            // 初始化流程管理器
            InitializeProcedures();

            Log.Info("[GameLogicEntry] 游戏逻辑初始化完成。");
        }

        private static void MangerLogicInit()
        {
            var entryGo = GameObject.Find("Entry");
            if (entryGo == null)
            {
                Log.Error("[GameLogicEntry] 未找到 Entry 游戏对象，无法初始化管理器逻辑。");
                return;
            }

            var rc = entryGo.GetComponent<ReferenceCollector>();
            if (rc == null)
            {
                Log.Error("[GameLogicEntry] Entry 游戏对象缺少 ReferenceCollector 组件，无法初始化管理器逻辑。");
                return;
            }

            // 初始化 UI 管理器逻辑
            var uiRoot = rc.Get<GameObject>("UIRoot");

            var background = rc.Get<GameObject>("Background");
            var normal = rc.Get<GameObject>("Normal");
            var popup = rc.Get<GameObject>("Popup");
            var overlay = rc.Get<GameObject>("Overlay");

            _uiManager.RegisterLayerRoot(UILayer.Background, background.transform);
            _uiManager.RegisterLayerRoot(UILayer.Normal, normal.transform);
            _uiManager.RegisterLayerRoot(UILayer.Popup, popup.transform);
            _uiManager.RegisterLayerRoot(UILayer.Overlay, overlay.transform);

            // 注册游戏相关的数据模型
            InitializeModels();

            Log.Info("[GameLogicEntry] 管理器逻辑初始化完成。");
        }

        /// <summary>
        /// 初始化游戏数据模型
        /// </summary>
        private static void InitializeModels()
        {
            try
            {
                // 注册主界面数据模型
                _modelManager.Register<MainModel>();

                // 注册游戏玩法数据模型
                // _modelManager.Register<GamePlayModel>();

                Log.Info("[GameLogicEntry] 游戏数据模型初始化完成");
            }
            catch (System.Exception ex)
            {
                Log.Error($"[GameLogicEntry] 游戏数据模型初始化失败：{ex.Message}");
            }
        }

        /// <summary>
        /// 初始化流程管理器
        /// </summary>
        private static void InitializeProcedures()
        {
            Log.Info("[GameLogicEntry] 初始化流程管理器...");

            try
            {
                // 创建所有 Procedure 实例
                var procedureType = typeof(ProcedureBase);
                var assembly = Assembly.GetExecutingAssembly();

                var procedureTypes = assembly.GetTypes()
                    .Where(t => procedureType.IsAssignableFrom(t) && !t.IsAbstract && !t.IsInterface)
                    .ToList();
                List<ProcedureBase> procedureInstances = new List<ProcedureBase>();
                foreach (var type in procedureTypes)
                {
                    procedureInstances.Add((ProcedureBase)System.Activator.CreateInstance(type));
                    Log.Info($"[GameLifetimeScope] 注册流程: {type.Name}");
                }

                _procedureManager.Initialize(_fsmManager, procedureInstances.ToArray());
                // 初始化 ProcedureManager

                // 启动第一个流程
                _procedureManager.StartProcedure<InitProcedure>();

                Log.Info("[GameLogicEntry] 流程管理器启动完成。");
            }
            catch (System.Exception e)
            {
                Log.Error($"[GameLogicEntry] 流程管理器初始化失败：{e.Message}");
            }
        }
    }
}
