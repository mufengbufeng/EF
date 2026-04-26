using System;
using Cysharp.Threading.Tasks;
using EF.Common;
using EF.Debugger;
using EF.Procedure;
using EF.Scene;
using EF.UI;
using UnityEngine;
using UnityEngine.Rendering.Universal;
using ProcedureOwner = EF.Fsm.IFsm<EF.Procedure.IProcedureManager>;

namespace GameLogic
{
    /// <summary>
    /// 游戏玩法流程。
    /// 负责游戏场景的加载和游戏逻辑的运行。
    /// </summary>
    public class GamePlayProcedure : ProcedureBase
    {
        private const string BackgroundPrefabName = "BackgroundPrefab";
        private const string EnemyPrefabName = "EnemyPlane";
        private const string AvatarPrefabName = "Avatar";
        private const string BulletPrefabName = "BulletCommon";
        private const string AvatarGroupName = "PlayerAvatar";
        private const float AvatarAttackInterval = 0.2f;
        private const float AvatarBulletSpeed = 8f;
        private const float AvatarDragBoundaryPadding = 0.25f;
        private const string GameRootName = "Root";
        private const string GamePlayWindowName = "GamePlayView";
        private const string GameMenuWindowName = "GameMenuView";

        private ProcedureOwner _procedureOwner;
        private IGameSceneManager _gameSceneManager;
        private IGameBackgroundModule _gameBackgroundModule;
        private IEnemySpawnerModule _enemySpawnerModule;
        private IPlayerAvatarModule _playerAvatarModule;
        private IBulletModule _bulletModule;
        private Transform _backgroundRoot;
        private Camera _gameCamera;
        private bool _isReturningToMainMenu;
        private int _enterSequence;
        [UHubBind("PlayerPoint")] private Transform _playerPoint;
        [UHubBind("EnemyPont")] private Transform _enemyPoint;

        protected override void OnInit(ProcedureOwner procedureOwner)
        {
            base.OnInit(procedureOwner);
            _procedureOwner = procedureOwner;
            _gameSceneManager = GameLogicEntry.GameScene;
            Log.Info("[GamePlayProcedure] OnInit");
        }

        protected override void OnEnter(ProcedureOwner procedureOwner)
        {
            base.OnEnter(procedureOwner);
            _isReturningToMainMenu = false;
            int enterSequence = ++_enterSequence;
            Log.Info("[GamePlayProcedure] OnEnter - 进入游戏玩法流程");
            OnEnterAsync(procedureOwner, enterSequence).Forget();
        }

        /// <summary>
        /// OnEnter 的异步实现，使用 UniTaskVoid 避免 async void 问题。
        /// </summary>
        private async UniTaskVoid OnEnterAsync(ProcedureOwner procedureOwner, int enterSequence)
        {
            try
            {
                if (!IsEnterSequenceActive(enterSequence, "开始进入流程"))
                {
                    return;
                }

                // 进入玩法前，清理上一次遗留的玩法作用域模块（幂等）。
                int cleanedCount = ModuleSystem.ShutdownScope(ModuleScope.GAME_PLAY);
                if (cleanedCount > 0)
                {
                    Log.Info($"[GamePlayProcedure] 已清理遗留玩法模块数量：{cleanedCount}");
                }

                GameLogicEntry.UI.OpenWindowAsync<GamePlayView, GamePlayController>(GamePlayWindowName).Forget();

                // 注册背景模块。
                _gameBackgroundModule = new GameBackgroundModule(GameLogicEntry.Resource, GameLogicEntry.ObjectPool);
                _gameBackgroundModule.Configure(BackgroundPrefabName, speed: 1f);
                ModuleSystem.Register(_gameBackgroundModule, replace: true, scope: ModuleScope.GAME_PLAY);

                // 注册子弹模块（先注册并初始化，确保敌人攻击前子弹系统就绪）。
                _bulletModule = new BulletModule(GameLogicEntry.Entity);
                _bulletModule.Configure(BulletPrefabName);
                ModuleSystem.Register(_bulletModule, replace: true, scope: ModuleScope.GAME_PLAY);
                await _bulletModule.InitializeAsync();
                if (!IsEnterSequenceActive(enterSequence, "子弹模块初始化完成"))
                {
                    return;
                }

                Log.Info("[GamePlayProcedure] 子弹模块已注册并初始化完成");

                // 注册敌人生成器模块。
                _enemySpawnerModule = new EnemySpawnerModule(GameLogicEntry.Entity);
                _enemySpawnerModule.Configure(EnemyPrefabName, spawnInterval: 2f, maxEnemyCount: 10);
                _enemySpawnerModule.Initialize();
                ModuleSystem.Register(_enemySpawnerModule, replace: true, scope: ModuleScope.GAME_PLAY);
                Log.Info("[GamePlayProcedure] 敌人生成器模块已注册");

                // 进入玩法场景（复用现有 GameSceneManager）。
                if (_gameSceneManager != null)
                {
                    if (!IsEnterSequenceActive(enterSequence, "准备加载玩法场景"))
                    {
                        return;
                    }

                    await _gameSceneManager.EnterGamePlaySceneAsync();
                    if (!IsEnterSequenceActive(enterSequence, "玩法场景加载完成"))
                    {
                        return;
                    }

                    Log.Info("[GamePlayProcedure] 游戏场景加载完成");

                    TryResolveSceneReferences();

                    // 建立 URP 摄像机堆栈：将 UICamera 作为 Overlay 添加到 GameCamera
                    SetupCameraStack();

                    if (_gameBackgroundModule != null)
                    {
                        if (!IsEnterSequenceActive(enterSequence, "准备加载背景模块"))
                        {
                            return;
                        }

                        _gameBackgroundModule.SetBackgroundRoot(_backgroundRoot);
                        await _gameBackgroundModule.LoadAsync();
                        if (!IsEnterSequenceActive(enterSequence, "背景模块加载完成"))
                        {
                            return;
                        }
                    }

                    if (!IsEnterSequenceActive(enterSequence, "准备注册玩家模块"))
                    {
                        return;
                    }

                    // 注册玩家 Avatar 模块并生成玩家实体（依赖场景锚点和子弹模块已就绪）。
                    _playerAvatarModule = new PlayerAvatarModule(GameLogicEntry.Entity);
                    _playerAvatarModule.Configure(
                        AvatarPrefabName,
                        AvatarGroupName,
                        AvatarAttackInterval,
                        AvatarBulletSpeed,
                        AvatarDragBoundaryPadding);
                    _playerAvatarModule.OnPlayerDied += HandlePlayerDied;
                    _playerAvatarModule.SetSpawnAnchor(_playerPoint);
                    ModuleSystem.Register(_playerAvatarModule, replace: true, scope: ModuleScope.GAME_PLAY);
                    await _playerAvatarModule.InitializeAsync();
                    if (!IsEnterSequenceActive(enterSequence, "玩家模块初始化完成"))
                    {
                        return;
                    }

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
            // 使当前进入链路立即失效，阻止离开后继续执行异步进入步骤。
            _enterSequence++;

            // 统一恢复时间缩放，避免暂停态残留到主界面。
            Time.timeScale = 1f;

            // 关闭玩法相关界面（在模块清理前执行，确保 Controller 能正常 OnExit）。
            GameLogicEntry.UI.CloseWindowAsync(GamePlayWindowName).Forget();
            GameLogicEntry.UI.CloseWindowAsync(GameMenuWindowName).Forget();

            // 解除事件订阅，避免流程离开后残留回调。
            UnsubscribePlayerAvatarEvents();

            // 恢复摄像机堆栈状态（在模块清理前执行，避免依赖丢失）
            CleanupCameraStack();

            ResetGamePlayModelData();

            int cleanedCount = ModuleSystem.ShutdownScope(ModuleScope.GAME_PLAY);
            Log.Info($"[GamePlayProcedure] 已清理玩法模块数量：{cleanedCount}");

            // 退出玩法时主动尝试卸载场景，失败只记录日志，不阻断流程。
            SceneInfo? leavingSceneSnapshot = GameLogicEntry.Scene?.GetCurrentScene();
            if (leavingSceneSnapshot.HasValue)
            {
                TryUnloadGamePlaySceneAsync(leavingSceneSnapshot.Value).Forget();
            }
            else
            {
                Log.Warning("[GamePlayProcedure] 未获取到离开场景快照，跳过玩法场景卸载以避免误卸载");
            }

            _gameBackgroundModule = null;
            _enemySpawnerModule = null;
            _playerAvatarModule = null;
            _bulletModule = null;
            _backgroundRoot = null;
            _gameCamera = null;
            _playerPoint = null;
            _enemyPoint = null;
            _isReturningToMainMenu = false;
        }

        protected override void OnDestroy(ProcedureOwner procedureOwner)
        {
            base.OnDestroy(procedureOwner);
            Log.Info("[GamePlayProcedure] OnDestroy");
        }

        /// <summary>
        /// 返回主菜单。
        /// </summary>
        public void ReturnToMainMenu()
        {
            if (_isReturningToMainMenu)
            {
                Log.Info("[GamePlayProcedure] 忽略重复的返回主菜单请求");
                return;
            }

            _isReturningToMainMenu = true;
            Log.Info("[GamePlayProcedure] 返回主菜单");
            ChangeState<MainMenuProcedure>(_procedureOwner);
        }

        private void HandlePlayerDied()
        {
            Log.Info("[GamePlayProcedure] 玩家死亡，触发返回主菜单");
            ReturnToMainMenu();
        }

        private void UnsubscribePlayerAvatarEvents()
        {
            if (_playerAvatarModule == null)
            {
                return;
            }

            _playerAvatarModule.OnPlayerDied -= HandlePlayerDied;
        }

        private void ResetGamePlayModelData()
        {
            var modelManager = GameLogicEntry.Model;
            if (modelManager == null)
            {
                Log.Warning("[GamePlayProcedure] ModelManager 不可用，跳过玩法数据重置");
                return;
            }

            if (modelManager.TryGetModel(typeof(GamePlayModel)) is GamePlayModel gamePlayModel)
            {
                gamePlayModel.ResetScore();
                Log.Info("[GamePlayProcedure] 已重置玩法局内数据（积分）");
                return;
            }

            Log.Warning("[GamePlayProcedure] 未找到 GamePlayModel，跳过玩法数据重置");
        }

        private async UniTaskVoid TryUnloadGamePlaySceneAsync(SceneInfo expectedSceneSnapshot)
        {
            var sceneManager = GameLogicEntry.Scene;
            if (sceneManager == null)
            {
                Log.Warning("[GamePlayProcedure] SceneManager 不可用，跳过玩法场景卸载");
                return;
            }

            try
            {
                bool unloaded = await sceneManager.UnloadSceneAsync(expectedSceneSnapshot);
                if (unloaded)
                {
                    Log.Info("[GamePlayProcedure] 玩法场景卸载成功");
                }
                else
                {
                    Log.Warning("[GamePlayProcedure] 玩法场景未卸载（可能无已加载场景或卸载失败）");
                }
            }
            catch (Exception e)
            {
                Log.Error($"[GamePlayProcedure] 玩法场景卸载异常：{e.Message}");
            }
        }

        private bool IsEnterSequenceActive(int enterSequence, string stage)
        {
            if (_enterSequence == enterSequence)
            {
                return true;
            }

            Log.Info($"[GamePlayProcedure] 已离开玩法流程，忽略过期进入步骤：{stage}");
            return false;
        }

        /// <summary>
        /// 建立 URP 摄像机堆栈：将 UICamera 设为 Overlay 并添加到 GameCamera 的 camera stack 中。
        /// </summary>
        private void SetupCameraStack()
        {
            Camera uiCamera = GameLogicEntry.UICamera;
            if (uiCamera == null)
            {
                Log.Warning("[GamePlayProcedure] UICamera 不可用，跳过摄像机堆栈设置。");
                return;
            }

            if (_gameCamera == null)
            {
                Log.Warning("[GamePlayProcedure] GameCamera 不可用，跳过摄像机堆栈设置。");
                return;
            }

            var gameCameraData = _gameCamera.GetUniversalAdditionalCameraData();
            var uiCameraData = uiCamera.GetUniversalAdditionalCameraData();

            if (gameCameraData == null || uiCameraData == null)
            {
                Log.Warning("[GamePlayProcedure] 无法获取 UniversalAdditionalCameraData，跳过摄像机堆栈设置。");
                return;
            }

            // 将 UICamera 的渲染类型切换为 Overlay
            uiCameraData.renderType = CameraRenderType.Overlay;

            // 将 UICamera 添加到 GameCamera 的 camera stack
            if (!gameCameraData.cameraStack.Contains(uiCamera))
            {
                gameCameraData.cameraStack.Add(uiCamera);
            }

            Log.Info("[GamePlayProcedure] 摄像机堆栈已建立：UICamera 作为 Overlay 添加到 GameCamera。");
        }

        /// <summary>
        /// 清理 URP 摄像机堆栈：将 UICamera 从 GameCamera stack 中移除，恢复为 Base 摄像机。
        /// </summary>
        private void CleanupCameraStack()
        {
            Camera uiCamera = GameLogicEntry.UICamera;
            if (uiCamera == null)
            {
                return;
            }

            // 如果 GameCamera 仍然存在，从其 stack 中移除 UICamera
            if (_gameCamera != null)
            {
                var gameCameraData = _gameCamera.GetUniversalAdditionalCameraData();
                if (gameCameraData != null)
                {
                    gameCameraData.cameraStack.Remove(uiCamera);
                }
            }

            // 恢复 UICamera 的渲染类型为 Base
            var uiCameraData = uiCamera.GetUniversalAdditionalCameraData();
            if (uiCameraData != null)
            {
                uiCameraData.renderType = CameraRenderType.Base;
            }

            Log.Info("[GamePlayProcedure] 摄像机堆栈已清理：UICamera 恢复为独立 Base 摄像机。");
        }

        private void TryResolveSceneReferences()
        {
            _backgroundRoot = null;
            _playerPoint = null;
            _enemyPoint = null;
            _gameCamera = null;

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

            // 获取 GameCamera 引用（用于 URP Camera Stack）
            _gameCamera = collector.Get<Camera>("GameCamera");
            if (_gameCamera == null)
            {
                Log.Warning("[GamePlayProcedure] ReferenceCollector 缺少 GameCamera。");
            }

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

            Log.Info(
                $"[GamePlayProcedure] 场景引用解析完成 - BackgroundRoot:{(_backgroundRoot != null)}, PlayerPoint:{(_playerPoint != null)}, EnemyPont:{(_enemyPoint != null)}");
        }
    }
}
