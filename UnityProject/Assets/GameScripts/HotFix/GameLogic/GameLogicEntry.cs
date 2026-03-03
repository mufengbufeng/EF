using System.Collections.Generic;
using System.Linq;
using System.Reflection;
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
    /// Game logic entry.
    /// </summary>
    public static class GameLogicEntry
    {
        // EF framework modules
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

        // UI camera (DontDestroyOnLoad + URP Camera Stack)
        private static Camera _uiCamera;

        // Game config system
        private static ConfigSystem _configSystem;

        public static IResourceManager Resource => _resourceManager;
        public static IEventManager Event => _eventManager;
        public static IUIManager UI => _uiManager;
        public static ISoundManager Sound => _soundManager;
        public static ITimerManager Timer => _timerManager;
        public static IObjectPoolManager ObjectPool => _objectPoolManager;
        public static IFsmManager Fsm => _fsmManager;
        public static IProcedureManager Procedure => _procedureManager;
        public static ISaveManager Save => _saveManager;
        public static ISceneManager Scene => _sceneManager;
        public static ModelManager Model => _modelManager;
        public static ConfigSystem Config => _configSystem;
        public static IEntityManager Entity => _entityManager;
        public static IGameSceneManager GameScene => _gameSceneManager;
        public static Camera UICamera => _uiCamera;

        public static void Init()
        {
            Log.Info("[GameLogicEntry] Initializing game logic...");

            // Get EF framework modules from ModuleSystem
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

            // Get ModelManager from ModuleSystem (registered in GameEntry)
            _modelManager = ModuleSystem.Get<ModelManager>();

            // Create scene manager
            _sceneManager = new SceneManager(_resourceManager);

            // Create game scene manager
            _gameSceneManager = new GameSceneManager(_sceneManager, _eventManager);

            Log.Info("[GameLogicEntry] EF framework modules initialized");

            MangerLogicInit();

            // Initialize config system
            _configSystem = new ConfigSystem(_resourceManager);

            // Initialize game modules (LevelModule, EnergyModule, etc.)
            InitializeGameModules();

            // Initialize procedures
            InitializeProcedures();

            Log.Info("[GameLogicEntry] Game logic initialization complete");
        }

        private static void InitializeGameModules()
        {
            try
            {
                // Register LevelModule
                var levelModule = new LevelModule();
                levelModule.Configure(100); // Max level count
                levelModule.Initialize();
                ModuleSystem.Register<ILevelModule>(levelModule);
                Log.Info("[GameLogicEntry] LevelModule registered");

                // Check if EnergyModule exists (optional module)
                if (ModuleSystem.TryGet<IEnergyModule>(out var energyModule))
                {
                    Log.Info("[GameLogicEntry] EnergyModule already registered");
                }
                else
                {
                    Log.Warning("[GameLogicEntry] EnergyModule not registered (optional)");
                }
            }
            catch (System.Exception ex)
            {
                Log.Error($"[GameLogicEntry] Game modules initialization failed: {ex.Message}");
            }
        }

        private static void MangerLogicInit()
        {
            var entryGo = GameObject.Find("Entry");
            if (entryGo == null)
            {
                Log.Error("[GameLogicEntry] Entry GameObject not found");
                return;
            }

            var rc = entryGo.GetComponent<ReferenceCollector>();
            if (rc == null)
            {
                Log.Error("[GameLogicEntry] Entry missing ReferenceCollector");
                return;
            }

            var uiRoot = rc.Get<GameObject>("UIRoot");
            var background = rc.Get<GameObject>("Background");
            var normal = rc.Get<GameObject>("Normal");
            var popup = rc.Get<GameObject>("Popup");
            var overlay = rc.Get<GameObject>("Overlay");
            var uiCamera = rc.Get<GameObject>("UICamera");
            
            if (uiCamera != null)
            {
                _uiCamera = uiCamera.GetComponent<Camera>();
                if (_uiCamera == null)
                {
                    Log.Warning("[GameLogicEntry] UICamera not found");
                }
            }
            else
            {
                Log.Warning("[GameLogicEntry] UICamera not found in ReferenceCollector");
            }

            _uiManager.RegisterLayerRoot(UILayer.Background, background.transform);
            _uiManager.RegisterLayerRoot(UILayer.Normal, normal.transform);
            _uiManager.RegisterLayerRoot(UILayer.Popup, popup.transform);
            _uiManager.RegisterLayerRoot(UILayer.Overlay, overlay.transform);

            InitializeModels();
            Log.Info("[GameLogicEntry] Manager logic initialized");
        }

        private static void InitializeModels()
        {
            try
            {
                _modelManager.Register<MainModel>();
                _modelManager.Register<GamePlayModel>();
                Log.Info("[GameLogicEntry] Game models initialized");
            }
            catch (System.Exception ex)
            {
                Log.Error($"[GameLogicEntry] Game models initialization failed: {ex.Message}");
            }
        }

        private static void InitializeProcedures()
        {
            Log.Info("[GameLogicEntry] Initializing procedures...");

            try
            {
                var procedureType = typeof(ProcedureBase);
                var assembly = Assembly.GetExecutingAssembly();

                var procedureTypes = assembly.GetTypes()
                    .Where(t => procedureType.IsAssignableFrom(t) && !t.IsAbstract && !t.IsInterface)
                    .ToList();
                List<ProcedureBase> procedureInstances = new List<ProcedureBase>();
                foreach (var type in procedureTypes)
                {
                    procedureInstances.Add((ProcedureBase)System.Activator.CreateInstance(type));
                    Log.Info($"[GameLifetimeScope] Registered procedure: {type.Name}");
                }

                _procedureManager.Initialize(_fsmManager, procedureInstances.ToArray());
                _procedureManager.StartProcedure<InitProcedure>();

                Log.Info("[GameLogicEntry] Procedures initialized");
            }
            catch (System.Exception e)
            {
                Log.Error($"[GameLogicEntry] Procedure initialization failed: {e.Message}");
            }
        }
    }
}