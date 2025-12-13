using Cysharp.Threading.Tasks;
using EF.Common;
using EF.Debugger;
using EF.Event;
using EF.FrifloEcs;
using EF.Fsm;
using EF.Model;
using EF.ObjectPool;
using EF.Resource;
using EF.Save;
using EF.Scene;
using EF.Sound;
using EF.Timer;
using EF.UI;
using Friflo.Engine.ECS;
using Friflo.Engine.ECS.Systems;
using UnityEngine;

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
    private static ISaveManager _saveManager;
    private static IFrifloEcsManager _frifloEcsManager;
    private static ISceneManager _sceneManager;
    private static ModelManager _modelManager;

    // 游戏配置系统
    private static ConfigSystem _configSystem;

    // ECS 游戏逻辑系统组
    private static SystemGroup _gameLogicGroup;

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
    /// 本地保存管理器
    /// </summary>
    public static ISaveManager Save => _saveManager;

    /// <summary>
    /// Friflo ECS 管理器
    /// </summary>
    public static IFrifloEcsManager Ecs => _frifloEcsManager;

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
    /// ECS 游戏逻辑系统组，用于添加游戏逻辑相关的系统
    /// </summary>
    public static SystemGroup GameLogicGroup => _gameLogicGroup;

    /// <summary>
    /// ECS 默认实体世界，用于创建和管理实体
    /// </summary>
    public static EntityStore World => _frifloEcsManager.DefaultStore;


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
        _saveManager = ModuleSystem.Get<ISaveManager>();
        _frifloEcsManager = ModuleSystem.Get<IFrifloEcsManager>();

        // 从 ModuleSystem 获取 ModelManager（已在 GameEntry 中创建并注册）
        _modelManager = ModuleSystem.Get<ModelManager>();

        // 创建场景管理器

        _sceneManager = new SceneManager(_resourceManager);



        Log.Info("[GameLogicEntry] EF 框架管理器初始化完成。");

        MangerLogicInit();
        EcsInit();

        // 初始化配置系统
        _configSystem = new ConfigSystem(_resourceManager);
        _configSystem.Load();

        Log.Info("[GameLogicEntry] 配置加载完成！");

        // 测试配置是否加载成功
        var tables = _configSystem.Tables;
        if (tables != null)
        {
            Log.Info($"[GameLogicEntry] 配置表加载成功，道具表数量: {tables.TbItem.DataList.Count}");
        }
        else
        {
            Log.Error("[GameLogicEntry] 配置表加载失败！");
        }

        EntryGame();
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

        _saveManager.SetSaveStrategy(SaveStrategyType.Json);

        Log.Info("[GameLogicEntry] 管理器逻辑初始化完成。");
    }

    private static void EcsInit()
    {
        // 创建游戏逻辑系统组
        _gameLogicGroup = new SystemGroup("GameLogic");
        _frifloEcsManager.AddSystem(_gameLogicGroup);

#if UNITY_EDITOR
        // 开发阶段开启性能监控
        _frifloEcsManager.SetPerformanceMonitoring(true);
#endif

        Log.Info("[GameLogicEntry] ECS 初始化完成。");
    }

    private static void EntryGame()
    {
        Log.Info("[GameLogicEntry] 进入游戏逻辑...");

        // 直接打开游戏入口界面，无需预先注册
        OpenEntryView();

        Log.Info("[GameLogicEntry] 游戏逻辑初始化完成。");
    }


    /// <summary>
    /// 打开游戏入口界面
    /// </summary>
    private static async void OpenEntryView()
    {
        try
        {
            // 使用新的简化API，需要特殊配置：禁用缓存
            var handle = await _uiManager.OpenWindowAsync<EntryView, EntryController>(
                location: "EntryView",
                layer: UILayer.Normal,
                cacheOnClose: false,
                allowMultiple: false
            );
            Log.Info("[GameLogicEntry] 游戏入口界面已打开");
        }
        catch (System.Exception e)
        {
            Log.Error($"[GameLogicEntry] 打开入口界面失败：{e.Message}");
        }
    }
}
