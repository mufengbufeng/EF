
using EF.Debugger;
using EF.Procedure;
using ProcedureOwner = EF.Fsm.IFsm<EF.Procedure.IProcedureManager>;

namespace GameLogic
{
    public class LoginProcedure : ProcedureBase
    {
        private ProcedureOwner _procedureOwner;

        protected override void OnInit(ProcedureOwner procedureOwner)
        {
            base.OnInit(procedureOwner);
            Log.Info("[LoginProcedure] OnInit");
        }

        protected override async void OnEnter(ProcedureOwner procedureOwner)
        {
            base.OnEnter(procedureOwner);
            _procedureOwner = procedureOwner;
            Log.Info("[LoginProcedure] OnEnter - 进入登录流程");

            try
            {
                // 打开登录界面
                var handle = await GameLogicEntry.UI.OpenWindowAsync<EntryView, EntryController>(
                                  location: "EntryView",
                                  layer: EF.UI.UILayer.Normal,
                                  cacheOnClose: false,
                                  allowMultiple: false
                              );
            }
            catch (System.Exception e)
            {
                Log.Error($"[LoginProcedure] 登录流程执行失败：{e.Message}");
            }
        }

        protected override void OnLeave(ProcedureOwner procedureOwner, bool isShutdown)
        {
            GameLogicEntry.UI.CloseWindowAsync("EntryView");
            base.OnLeave(procedureOwner, isShutdown);
            Log.Info("[LoginProcedure] OnLeave - 退出登录流程");
        }

        protected override void OnDestroy(ProcedureOwner procedureOwner)
        {
            base.OnDestroy(procedureOwner);
            Log.Info("[LoginProcedure] OnDestroy");
        }

        /// <summary>
        /// 开始游戏，切换到主菜单流程
        /// </summary>
        public void StartGame()
        {
            if (_procedureOwner == null)
            {
                Log.Error("[LoginProcedure] ProcedureOwner 为空，无法切换状态");
                return;
            }

            Log.Info("[LoginProcedure] 登录完成，准备进入主菜单流程");
            ChangeState<MainMenuProcedure>(_procedureOwner);
        }

    }
}