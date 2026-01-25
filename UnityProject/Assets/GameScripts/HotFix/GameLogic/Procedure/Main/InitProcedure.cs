using Cysharp.Threading.Tasks;
using EF.Common;
using EF.Debugger;
using EF.Procedure;
using ProcedureOwner = EF.Fsm.IFsm<EF.Procedure.IProcedureManager>;

namespace GameLogic
{
    /// <summary>
    /// 初始化流程。
    /// 负责加载配置系统、初始化数据模型和保存策略。
    /// </summary>
    public class InitProcedure : ProcedureBase
    {
        private ConfigSystem _configSystem;
        private EF.Model.ModelManager _modelManager;
        private EF.Save.ISaveManager _saveManager;

        protected override void OnInit(ProcedureOwner procedureOwner)
        {
            base.OnInit(procedureOwner);

            // 从 GameLogicEntry 获取管理器引用
            _configSystem = GameLogicEntry.Config;
            _modelManager = GameLogicEntry.Model;
            _saveManager = GameLogicEntry.Save;

            Log.Info("[InitProcedure] OnInit");
        }

        protected override async void OnEnter(ProcedureOwner procedureOwner)
        {
            base.OnEnter(procedureOwner);
            Log.Info("[InitProcedure] OnEnter - 开始初始化...");

            try
            {
                // 1. 设置保存策略
                _saveManager.SetSaveStrategy(EF.Save.SaveStrategyType.Json);
                Log.Info("[InitProcedure] 保存策略已设置");

                // 2. 初始化配置系统
                _configSystem.Load();
                Log.Info("[InitProcedure] 配置系统加载完成");

                // 验证配置是否加载成功
                var tables = _configSystem.Tables;
                if (tables != null)
                {
                    Log.Info($"[InitProcedure] 配置表加载成功，道具表数量: {tables.TbItem.DataList.Count}");
                }
                else
                {
                    Log.Error("[InitProcedure] 配置表加载失败！");
                }

                // 稍微延迟以确保初始化完成
                await UniTask.Delay(100);

                // 切换到 SplashProcedure
                Log.Info("[InitProcedure] 初始化完成，切换到 SplashProcedure");
                ChangeState<LoginProcedure>(procedureOwner);
            }
            catch (System.Exception e)
            {
                Log.Error($"[InitProcedure] 初始化失败：{e.Message}");
            }
        }

        protected override void OnLeave(ProcedureOwner procedureOwner, bool isShutdown)
        {
            base.OnLeave(procedureOwner, isShutdown);
            Log.Info("[InitProcedure] OnLeave");
        }

        protected override void OnDestroy(ProcedureOwner procedureOwner)
        {
            base.OnDestroy(procedureOwner);
            Log.Info("[InitProcedure] OnDestroy");
        }
    }
}
