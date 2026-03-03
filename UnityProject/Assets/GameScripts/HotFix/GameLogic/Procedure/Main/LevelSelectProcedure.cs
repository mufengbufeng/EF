using EF.Debugger;
using EF.Procedure;
using ProcedureOwner = EF.Fsm.IFsm<EF.Procedure.IProcedureManager>;

namespace GameLogic
{
    /// <summary>
    /// 关卡选择流程：负责打开/关闭关卡选择界面。
    /// </summary>
    public class LevelSelectProcedure : ProcedureBase
    {
        private EF.UI.IUIManager _uiManager;
        private ProcedureOwner _procedureOwner;

        protected override void OnInit(ProcedureOwner procedureOwner)
        {
            base.OnInit(procedureOwner);
            _procedureOwner = procedureOwner;
            _uiManager = GameLogicEntry.UI;
            Log.Info("[LevelSelectProcedure] OnInit");
        }

        protected override async void OnEnter(ProcedureOwner procedureOwner)
        {
            base.OnEnter(procedureOwner);
            Log.Info("[LevelSelectProcedure] OnEnter - open level select view");

            try
            {
                await _uiManager.OpenWindowAsync<LevelSelectView, LevelSelectController>(
                    location: "LevelSelectView",
                    layer: EF.UI.UILayer.Normal,
                    cacheOnClose: false,
                    allowMultiple: false);
            }
            catch (System.Exception e)
            {
                Log.Error($"[LevelSelectProcedure] Failed to open level select view: {e.Message}");
            }
        }

        protected override void OnLeave(ProcedureOwner procedureOwner, bool isShutdown)
        {
            base.OnLeave(procedureOwner, isShutdown);
            _uiManager.CloseWindowAsync("LevelSelectView");
            Log.Info("[LevelSelectProcedure] OnLeave");
        }

        public void StartLevelGameplay()
        {
            ChangeState<GamePlayProcedure>(_procedureOwner);
        }

        public void BackToMainMenu()
        {
            ChangeState<MainMenuProcedure>(_procedureOwner);
        }
    }
}
