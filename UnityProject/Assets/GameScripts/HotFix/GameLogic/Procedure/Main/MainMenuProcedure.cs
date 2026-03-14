using Cysharp.Threading.Tasks;
using EF.Common;
using EF.Debugger;
using EF.Procedure;
using ProcedureOwner = EF.Fsm.IFsm<EF.Procedure.IProcedureManager>;

namespace GameLogic
{
    /// <summary>
    /// 主菜单流程。
    /// 负责显示主菜单界面并处理用户交互。
    /// </summary>
    public class MainMenuProcedure : ProcedureBase
    {
        private EF.UI.IUIManager _uiManager;
        private ProcedureOwner _procedureOwner;

        protected override void OnInit(ProcedureOwner procedureOwner)
        {
            base.OnInit(procedureOwner);
            _procedureOwner = procedureOwner;
            _uiManager = GameLogicEntry.UI;
            Log.Info("[MainMenuProcedure] OnInit");
        }

        protected override async void OnEnter(ProcedureOwner procedureOwner)
        {
            base.OnEnter(procedureOwner);
            Log.Info("[MainMenuProcedure] OnEnter - 打开主菜单界面");

            try
            {
                // 打开游戏入口界面
                var handle = await _uiManager.OpenWindowAsync<MainView, MainController>(
                    location: "MainView",
                    layer: EF.UI.UILayer.Normal,
                    cacheOnClose: false,
                    allowMultiple: false
                );
                Log.Info("[MainMenuProcedure] 主菜单界面已打开");
            }
            catch (System.Exception e)
            {
                Log.Error($"[MainMenuProcedure] 打开主菜单界面失败：{e.Message}");
            }
        }

        protected override void OnLeave(ProcedureOwner procedureOwner, bool isShutdown)
        {
            base.OnLeave(procedureOwner, isShutdown);
            Log.Info("[MainMenuProcedure] OnLeave - 关闭主菜单界面");

            // 关闭主菜单界面
            try
            {
                _uiManager.CloseWindowAsync("MainView").Forget();
            }
            catch (System.Exception e)
            {
                Log.Warning($"[MainMenuProcedure] 关闭主菜单界面时出错：{e.Message}");
            }
        }

        protected override void OnDestroy(ProcedureOwner procedureOwner)
        {
            base.OnDestroy(procedureOwner);
            Log.Info("[MainMenuProcedure] OnDestroy");
        }

        /// <summary>
        /// 开始游戏，切换到游戏玩法流程
        /// </summary>
        public bool StartGame()
        {
            if (_procedureOwner == null)
            {
                Log.Error("[MainMenuProcedure] ProcedureOwner 为空，无法切换到玩法流程");
                return false;
            }

            ChangeState<GamePlayProcedure>(_procedureOwner);
            return true;
        }
    }
}
