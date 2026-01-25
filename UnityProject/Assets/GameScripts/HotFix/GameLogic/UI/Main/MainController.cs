using System;
using EF.Debugger;
using EF.UI;

namespace GameLogic
{
    /// <summary>
    /// 游戏主界面控制器
    /// </summary>
    public class MainController : UIController
    {
        private MainView _mainView;
        private MainModel _mainModel;

        protected override void OnInitialize()
        {
            base.OnInitialize();

            // 获取强类型View
            _mainView = GetView<MainView>();

            // 获取数据模型
            _mainModel = GetModel<MainModel>();

            Log.Info("[MainController] 主界面控制器初始化完成");
        }

        protected override void OnEnter(object userData)
        {
            base.OnEnter(userData);

            // 使用 BindEvent 订阅 View 事件，OnExit 时会自动取消订阅
            if (_mainView != null)
            {
                BindEvent<Action>(
                    h => _mainView.OnStartGameRequested += h,
                    h => _mainView.OnStartGameRequested -= h,
                    HandleStartGame);
            }

            // 确保模型处于正确初始状态
            if (_mainModel != null)
            {
                _mainModel.SetGameStarted(false);
                _mainModel.SetInteractable(true);
            }

            Log.Info("[MainController] 主界面已打开");
        }

        protected override void OnExit()
        {
            // 不再需要手动取消订阅，EventBinder 会在 InternalExit 中自动清理
            base.OnExit();
            Log.Info("[MainController] 主界面已关闭");
        }

        /// <summary>
        /// 处理开始游戏请求
        /// </summary>
        private void HandleStartGame()
        {
            StartGame();
        }

        /// <summary>
        /// 开始游戏
        /// </summary>
        public async void StartGame()
        {
            Log.Info("[MainController] 用户点击开始游戏按钮");

            GameLogicEntry.Procedure.GetProcedure<MainMenuProcedure>().StartGame();

        }

    }
}