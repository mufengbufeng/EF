using Cysharp.Threading.Tasks;
using EF;
using UnityEngine.SceneManagement;

namespace GameLogic
{
    public class GamePlayController : BaseController<GamePlayController>
    {

        public void StartGame()
        {
            InitGame().Forget();
        }

        private async UniTaskVoid InitGame()
        {
            CloseOrderUI();
            PlayerModel.Instance.InitPlayerInfo(); // 初始化速度等参数
            GamePlayModel.Instance.StartGame(GameModel.Instance.Chapter);
        }

        private void CloseOrderUI()
        {
            GameModule.UI.CloseUI("MainView");
        }
    }
}