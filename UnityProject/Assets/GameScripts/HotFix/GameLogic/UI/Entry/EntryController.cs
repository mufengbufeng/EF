using System;
using EF.Debugger;
using EF.UI;

namespace GameLogic
{
    /// <summary>
    /// 游戏入口界面控制器
    /// </summary>
    public class EntryController : UIController
    {
        private EntryView _entryView;

        protected override void OnInitialize()
        {
            base.OnInitialize();

            // 获取强类型View
            _entryView = GetView<EntryView>();

            Log.Info("[EntryController] 入口界面控制器初始化完成");
        }

        protected override void OnEnter(object userData)
        {
            base.OnEnter(userData);

            // 订阅View的事件
            // if (_entryView != null)
            // {
            //     _entryView.OnStartGameRequested += HandleStartGame;
            // }
            BindEvent<Action>(
                h => _entryView.OnStartGameRequested += h,
                h => _entryView.OnStartGameRequested -= h,
                HandleStartGame);



            Log.Info("[EntryController] 入口界面已打开");
        }

        protected override void OnExit()
        {
            // 取消订阅View的事件
            // if (_entryView != null)
            // {
            //     _entryView.OnStartGameRequested -= HandleStartGame;
            // }


            base.OnExit();
            Log.Info("[EntryController] 入口界面已关闭");
        }

        /// <summary>
        /// 处理开始游戏请求
        /// </summary>
        private void HandleStartGame()
        {
            OpenMainView();
        }

        /// <summary>
        /// 打开游戏主界面
        /// </summary>
        public async void OpenMainView()
        {
            Log.Info("[EntryController] 用户点击入口按钮，准备打开主界面");

            try
            {
                GameLogicEntry.Procedure.GetProcedure<LoginProcedure>().StartGame();
            }
            catch (System.Exception ex)
            {
                Log.Error($"[EntryController] 打开主界面过程中发生错误：{ex.Message}");
                // 可以在这里添加错误处理，比如重新打开入口界面
            }
        }

        /// <summary>
        /// 场景加载进度回调
        /// </summary>
        /// <param name="progress">加载进度 0-1</param>
        private void OnSceneLoadingProgress(float progress)
        {
            Log.Info($"[EntryController] 游戏场景加载进度：{progress * 100:F1}%");
            // 这里可以更新UI显示加载进度
            // 例如：_entryView?.UpdateLoadingProgress(progress);
        }

        /// <summary>
        /// 场景加载错误回调
        /// </summary>
        /// <param name="exception">错误信息</param>
        private void OnSceneError(System.Exception exception)
        {
            Log.Error($"[EntryController] 游戏场景加载发生错误：{exception.Message}");
            // 这里可以显示错误提示并重新打开入口界面
            // 例如：ShowErrorDialog(exception.Message);
        }
    }
}