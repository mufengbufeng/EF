using Cysharp.Threading.Tasks;
using EF.Common;
using EF.Debugger;
using EF.Procedure;
using EF.UI;
using UnityEngine;
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
        private const string EnemyPrefabName = "EnemyPlane";
        private const string AvatarPrefabName = "Avatar";
        private const string BulletPrefabName = "BulletCommon";
        private const string AvatarGroupName = "PlayerAvatar";
        private const float AvatarAttackInterval = 0.2f;
        private const float AvatarBulletSpeed = 8f;
        private const float AvatarDragBoundaryPadding = 0.25f;
        private const string GameRootName = "Root";

        private IGameSceneManager _gameSceneManager;
        private IGameBackgroundModule _gameBackgroundModule;
        private IEnemySpawnerModule _enemySpawnerModule;
        private IPlayerAvatarModule _playerAvatarModule;
        private IBulletModule _bulletModule;
        private Transform _backgroundRoot;
        [UHubBind("PlayerPoint")]
        private Transform _playerPoint;
        [UHubBind("EnemyPont")]
        private Transform _enemyPoint;

        protected override void OnInit(ProcedureOwner procedureOwner)
        {
            base.OnInit(procedureOwner);
            _gameSceneManager = GameLogicEntry.GameScene;
            Log.Info("[GamePlayProcedure] OnInit");
        }

        protected override void OnEnter(ProcedureOwner procedureOwner)
        {
            base.OnEnter(procedureOwner);
            Log.Info("[GamePlayProcedure] OnEnter - 进入游戏玩法流程");
            OnEnterAsync(procedureOwner).Forget();
        }

        /// <summary>
        /// OnEnter 的异步实现，使用 UniTaskVoid 避免 async void 问题。
        /// </summary>
        private async UniTaskVoid OnEnterAsync(ProcedureOwner procedureOwner)
        {
            try
            {
                // 进入玩法前，清理上一次遗留的玩法作用域模块（幂等）。
                int cleanedCount = ModuleSystem.ShutdownScope(GamePlayScope);
                if (cleanedCount > 0)
                {
                    Log.Info($"[GamePlayProcedure] 已清理遗留玩法模块数量：{cleanedCount}");
                }

                // 注册背景模块。
                _gameBackgroundModule = new GameBackgroundModule(GameLogicEntry.Resource, GameLogicEntry.ObjectPool);
                _gameBackgroundModule.Configure(BackgroundPrefabName, speed: 1f);
                ModuleSystem.Register(_gameBackgroundModule, replace: true, scope: GamePlayScope);

                // 注册子弹模块（先注册并初始化，确保敌人攻击前子弹系统就绪）。
                _bulletModule = new BulletModule(GameLogicEntry.Entity);
                _bulletModule.Configure(BulletPrefabName);
                ModuleSystem.Register(_bulletModule, replace: true, scope: GamePlayScope);
                await _bulletModule.InitializeAsync();
                Log.Info("[GamePlayProcedure] 子弹模块已注册并初始化完成");

                // 注册敌人生成器模块。
                _enemySpawnerModule = new EnemySpawnerModule(GameLogicEntry.Entity);
                _enemySpawnerModule.Configure(EnemyPrefabName, spawnInterval: 2f, maxEnemyCount: 10);
                _enemySpawnerModule.Initialize();
                ModuleSystem.Register(_enemySpawnerModule, replace: true, scope: GamePlayScope);
                Log.Info("[GamePlayProcedure] 敌人生成器模块已注册");

                // 进入玩法场景（复用现有 GameSceneManager）。
                if (_gameSceneManager != null)
                {
                    await _gameSceneManager.EnterGamePlaySceneAsync();
                    Log.Info("[GamePlayProcedure] 游戏场景加载完成");

                    TryResolveSceneReferences();

                    if (_gameBackgroundModule != null)
                    {
                        _gameBackgroundModule.SetBackgroundRoot(_backgroundRoot);
                        await _gameBackgroundModule.LoadAsync();
                    }

                    // 注册玩家 Avatar 模块并生成玩家实体（依赖场景锚点和子弹模块已就绪）。
                    _playerAvatarModule = new PlayerAvatarModule(GameLogicEntry.Entity);
                    _playerAvatarModule.Configure(
                        AvatarPrefabName,
                        AvatarGroupName,
                        AvatarAttackInterval,
                        AvatarBulletSpeed,
                        AvatarDragBoundaryPadding);
                    _playerAvatarModule.SetSpawnAnchor(_playerPoint);
                    ModuleSystem.Register(_playerAvatarModule, replace: true, scope: GamePlayScope);
                    await _playerAvatarModule.InitializeAsync();
                    Log.Info("[GamePlayProcedure] 玩家 Avatar 模块已注册并初始化完成");

                    if (_playerPoint == null)
                    {
                        Log.Warning("[GamePlayProcedure] PlayerPoint 未找到，玩家出生位置使用后备方案");
                    }

                    // 将场景中的敌人生成区域锚点传递给敌人生成器模块
                    if (_enemySpawnerModule != null && _enemyPoint != null)
                    {
                        // 使用 EnemyPoint 作为生成中心，半宽度为摄像机可见宽度的 40%
                        float halfWidth = 3f;
                        Camera mainCamera = Camera.main;
                        if (mainCamera != null)
                        {
                            halfWidth = mainCamera.orthographicSize * mainCamera.aspect * 0.8f;
                        }
                        _enemySpawnerModule.SetSpawnArea(_enemyPoint, halfWidth);
                        Log.Info("[GamePlayProcedure] 已将敌人生成区域传递给生成器模块");
                    }
                    else if (_enemyPoint == null)
                    {
                        Log.Warning("[GamePlayProcedure] EnemyPoint 未找到，敌人生成器将使用后备位置计算");
                    }

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
            _gameBackgroundModule = null;
            _enemySpawnerModule = null;
            _playerAvatarModule = null;
            _bulletModule = null;
            _backgroundRoot = null;
            _playerPoint = null;
            _enemyPoint = null;

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

        private void TryResolveSceneReferences()
        {
            _backgroundRoot = null;
            _playerPoint = null;
            _enemyPoint = null;

            GameObject rootObject = GameObject.Find(GameRootName);
            if (rootObject == null)
            {
                Log.Warning($"[GamePlayProcedure] 未找到场景节点 {GameRootName}，无法解析玩法引用。");
                return;
            }

            ReferenceCollector collector = rootObject.GetComponent<ReferenceCollector>();
            if (collector == null)
            {
                Log.Warning($"[GamePlayProcedure] 节点 {GameRootName} 未挂载 ReferenceCollector，无法解析玩法引用。");
                return;
            }

            ComponentBinder binder = new ComponentBinder();
            int bindCount = binder.BindComponents(this, collector);
            Log.Info($"[GamePlayProcedure] UHub 自动绑定完成，成功数量：{bindCount}");

            if (_backgroundRoot == null)
            {
                Log.Warning("[GamePlayProcedure] ReferenceCollector 缺少 BackgroundRoot。");
            }

            if (_playerPoint == null)
            {
                Log.Warning("[GamePlayProcedure] ReferenceCollector 缺少 PlayerPoint。");
            }

            if (_enemyPoint == null)
            {
                Log.Warning("[GamePlayProcedure] ReferenceCollector 缺少 EnemyPont。");
            }

            Log.Info($"[GamePlayProcedure] 场景引用解析完成 - BackgroundRoot:{(_backgroundRoot != null)}, PlayerPoint:{(_playerPoint != null)}, EnemyPont:{(_enemyPoint != null)}");
        }
    }
}
