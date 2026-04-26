using Cysharp.Threading.Tasks;
using EF.Debugger;
using EF.Scene;

namespace GameLogic
{
    /// <summary>
    /// 游戏场景管理器实现
    /// 负责游戏逻辑层的场景切换流程管理
    /// </summary>
    public class GameSceneManager : IGameSceneManager
    {
        private readonly ISceneManager _sceneManager;
        private readonly EventHub _eventHub;

        /// <summary>
        /// 构造函数
        /// </summary>
        /// <param name="sceneManager">框架层场景管理器</param>
        /// <param name="eventHub">事件系统枢纽</param>
        public GameSceneManager(ISceneManager sceneManager, EventHub eventHub)
        {
            _sceneManager = sceneManager ?? throw new System.ArgumentNullException(nameof(sceneManager));
            _eventHub = eventHub ?? throw new System.ArgumentNullException(nameof(eventHub));
        }

        /// <summary>
        /// 进入游戏玩法场景
        /// </summary>
        public async UniTask EnterGamePlaySceneAsync()
        {
            const string sceneName = "Game";

            Log.Info($"[GameSceneManager] 准备进入游戏玩法场景: {sceneName}");

            _eventHub.BeforeSceneEnterEvent.Enqueue(new BeforeSceneEnterEvent(sceneName));

            bool success = await _sceneManager.LoadSceneAsync(sceneName);

            if (success)
            {
                Log.Info($"[GameSceneManager] 成功进入游戏玩法场景: {sceneName}");
                _eventHub.SceneEnterEvent.Enqueue(new SceneEnterEvent(sceneName));
            }
            else
            {
                Log.Error($"[GameSceneManager] 进入游戏玩法场景失败: {sceneName}");
            }
        }

        /// <summary>
        /// 进入战斗场景
        /// </summary>
        public async UniTask EnterBattleSceneAsync()
        {
            const string sceneName = "Battle";

            Log.Info($"[GameSceneManager] 准备进入战斗场景: {sceneName}");

            _eventHub.BeforeSceneEnterEvent.Enqueue(new BeforeSceneEnterEvent(sceneName));

            bool success = await _sceneManager.LoadSceneAsync(sceneName);

            if (success)
            {
                Log.Info($"[GameSceneManager] 成功进入战斗场景: {sceneName}");
                _eventHub.SceneEnterEvent.Enqueue(new SceneEnterEvent(sceneName));
            }
            else
            {
                Log.Error($"[GameSceneManager] 进入战斗场景失败: {sceneName}");
            }
        }

        /// <summary>
        /// 返回大厅场景
        /// </summary>
        public async UniTask ReturnToLobbyAsync()
        {
            const string sceneName = "Lobby";

            Log.Info($"[GameSceneManager] 准备返回大厅场景: {sceneName}");

            _eventHub.BeforeSceneEnterEvent.Enqueue(new BeforeSceneEnterEvent(sceneName));

            bool success = await _sceneManager.LoadSceneAsync(sceneName);

            if (success)
            {
                Log.Info($"[GameSceneManager] 成功返回大厅场景: {sceneName}");
                _eventHub.SceneEnterEvent.Enqueue(new SceneEnterEvent(sceneName));
            }
            else
            {
                Log.Error($"[GameSceneManager] 返回大厅场景失败: {sceneName}");
            }
        }
    }
}
