using Cysharp.Threading.Tasks;
using EF.Common;
using EF.Debugger;
using EF.Procedure;
using ProcedureOwner = EF.Fsm.IFsm<EF.Procedure.IProcedureManager>;

namespace GameLogic
{
    /// <summary>
    /// 启动画面流程。
    /// 显示启动画面并延迟后切换到主菜单。
    /// </summary>
    public class SplashProcedure : ProcedureBase
    {
        /// <summary>
        /// 启动画面显示时长（秒）
        /// </summary>
        private const float SplashDuration = 2f;

        protected override void OnInit(ProcedureOwner procedureOwner)
        {
            base.OnInit(procedureOwner);
            Log.Info("[SplashProcedure] OnInit");
        }

        protected override async void OnEnter(ProcedureOwner procedureOwner)
        {
            base.OnEnter(procedureOwner);
            Log.Info($"[SplashProcedure] OnEnter - 显示启动画面，持续 {SplashDuration} 秒");

            try
            {
                // TODO: 可以在这里显示启动画面 UI
                // await _uiManager.OpenWindowAsync<SplashView, SplashController>(...);

                // 延迟指定时间
                // await UniTask.Delay(System.TimeSpan.FromSeconds(SplashDuration));

                // Log.Info("[SplashProcedure] 启动画面完成，切换到 MainMenuProcedure");
                ChangeState<MainMenuProcedure>(procedureOwner);
            }
            catch (System.Exception e)
            {
                Log.Error($"[SplashProcedure] 执行失败：{e.Message}");
                // 即使出错也切换到主菜单
                ChangeState<MainMenuProcedure>(procedureOwner);
            }
        }

        protected override void OnLeave(ProcedureOwner procedureOwner, bool isShutdown)
        {
            base.OnLeave(procedureOwner, isShutdown);
            Log.Info("[SplashProcedure] OnLeave - 关闭启动画面");

            // TODO: 关闭启动画面 UI
        }

        protected override void OnDestroy(ProcedureOwner procedureOwner)
        {
            base.OnDestroy(procedureOwner);
            Log.Info("[SplashProcedure] OnDestroy");
        }
    }
}
