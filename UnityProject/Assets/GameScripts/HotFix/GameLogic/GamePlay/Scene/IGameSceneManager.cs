using System;
using Cysharp.Threading.Tasks;

namespace GameLogic
{
    /// <summary>
    /// 游戏场景管理器接口
    /// 负责游戏逻辑层的场景切换流程管理
    /// </summary>
    public interface IGameSceneManager
    {
        /// <summary>
        /// 进入游戏玩法场景
        /// </summary>
        UniTask EnterGamePlaySceneAsync();

        /// <summary>
        /// 进入战斗场景
        /// </summary>
        UniTask EnterBattleSceneAsync();

        /// <summary>
        /// 返回大厅场景
        /// </summary>
        UniTask ReturnToLobbyAsync();

    }
}
