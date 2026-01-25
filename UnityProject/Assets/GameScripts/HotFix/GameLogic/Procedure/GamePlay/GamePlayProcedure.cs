using EF.Common;
using EF.Debugger;
using EF.Procedure;
using ProcedureOwner = EF.Fsm.IFsm<EF.Procedure.IProcedureManager>;

namespace GameLogic
{
    /// <summary>
    /// 游戏玩法流程。
    /// 负责游戏场景的加载和游戏逻辑的运行。
    /// </summary>
    public class GamePlayProcedure : ProcedureBase
    {
        private const int GamePlayScope = 1001;
        private const string BackgroundPrefabName = "BackgroundPrefab";

        private IGameSceneManager _gameSceneManager;
        private IGameEnemyModule _gameEnemyModule;
        private IGameBackgroundModule _gameBackgroundModule;

        protected override void OnInit(ProcedureOwner procedureOwner)
        {
            base.OnInit(procedureOwner);
            _gameSceneManager = GameLogicEntry.GameScene;
            Log.Info("[GamePlayProcedure] OnInit");
        }

        protected override async void OnEnter(ProcedureOwner procedureOwner)
        {
            base.OnEnter(procedureOwner);
            Log.Info("[GamePlayProcedure] OnEnter - 进入游戏玩法流程");

            try
            {
                // 进入玩法前，清理上一次遗留的玩法作用域模块（幂等）。
                int cleanedCount = ModuleSystem.ShutdownScope(GamePlayScope);
                if (cleanedCount > 0)
                {
                    Log.Info($"[GamePlayProcedure] 已清理遗留玩法模块数量：{cleanedCount}");
                }

                // 注册玩法模块（当前仅敌机模块）。
                _gameEnemyModule = new GameEnemyModule(GameLogicEntry.Entity);
                ModuleSystem.Register<IGameEnemyModule>(_gameEnemyModule, replace: true, scope: GamePlayScope);

                // 注册背景模块。
                _gameBackgroundModule = new GameBackgroundModule(GameLogicEntry.Resource, GameLogicEntry.ObjectPool);
                _gameBackgroundModule.Configure(BackgroundPrefabName, speed: 1f);
                ModuleSystem.Register(_gameBackgroundModule, replace: true, scope: GamePlayScope);

                // 进入玩法场景（复用现有 GameSceneManager）。
                if (_gameSceneManager != null)
                {
                    await _gameSceneManager.EnterGamePlaySceneAsync();
                    Log.Info("[GamePlayProcedure] 游戏场景加载完成");

                    if (_gameBackgroundModule != null)
                    {
                        await _gameBackgroundModule.LoadAsync();
                    }

                    // TODO：外部配置敌机的 entityAssetName / groupName 后再启动刷怪。
                    _gameEnemyModule.StartSpawning();
                }
                else
                {
                    Log.Warning("[GamePlayProcedure] GameSceneManager 未初始化");
                }
            }
            catch (System.Exception e)
            {
                Log.Error($"[GamePlayProcedure] 进入游戏场景失败：{e.Message}");
            }
        }

        protected override void OnUpdate(ProcedureOwner procedureOwner, float elapseSeconds, float realElapseSeconds)
        {
            base.OnUpdate(procedureOwner, elapseSeconds, realElapseSeconds);
            // 玩法模块的 Update 由 ModuleSystem.Update 统一驱动。
        }

        protected override void OnLeave(ProcedureOwner procedureOwner, bool isShutdown)
        {
            base.OnLeave(procedureOwner, isShutdown);
            Log.Info("[GamePlayProcedure] OnLeave - 退出游戏玩法流程");

            int cleanedCount = ModuleSystem.ShutdownScope(GamePlayScope);
            Log.Info($"[GamePlayProcedure] 已清理玩法模块数量：{cleanedCount}");
            _gameEnemyModule = null;
            _gameBackgroundModule = null;

        }

        protected override void OnDestroy(ProcedureOwner procedureOwner)
        {
            base.OnDestroy(procedureOwner);
            Log.Info("[GamePlayProcedure] OnDestroy");
        }

        /// <summary>
        /// 返回主菜单
        /// </summary>
        public void ReturnToMainMenu(ProcedureOwner procedureOwner)
        {
            Log.Info("[GamePlayProcedure] 返回主菜单");
            ChangeState<MainMenuProcedure>(procedureOwner);
        }
    }
}
