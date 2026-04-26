using System;
using EF.Common;
using EF.Debugger;
using EF.Timer;
using EF.UI;

namespace GameLogic
{
    /// <summary>
    /// 游戏主界面控制器
    /// </summary>
    public class MainController : UIController
    {
        private const int StartGameEnergyCost = 1;

        private MainView _mainView;
        private MainModel _mainModel;
        private IEnergyModule _energyModule;
        private ILevelModule _levelModule;
        private ITimerManager _timerManager;
        private int _countdownTimerId;

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
                _mainModel.SetEnergy(0, 0);
            }

            InitializeEnergyBindings();

            // 初始化关卡显示
            InitializeLevelDisplay();

            // 初始化恢复倒计时
            InitializeCountdownTimer();

            Log.Info("[MainController] 主界面已打开");
        }

        protected override void OnExit()
        {
            CancelCountdownTimer();
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
        /// 开始游戏（带体力校验）。
        /// </summary>
        public void StartGame()
        {
            Log.Info("[MainController] 用户点击开始游戏按钮");

            if (_energyModule == null)
            {
                _mainView?.SetFeedbackText("体力模块未就绪，请稍后重试");
                Log.Warning("[MainController] 体力模块未就绪，阻止进入游戏");
                return;
            }

            if (!_energyModule.TryConsume(StartGameEnergyCost))
            {
                _mainView?.SetFeedbackText($"体力不足，至少需要 {StartGameEnergyCost} 点");
                _mainView?.SetStartButtonInteractable(false);
                Log.Info("[MainController] 体力不足，阻止进入游戏");
                return;
            }

            if (!TryGetMainMenuProcedure(out MainMenuProcedure mainMenuProcedure))
            {
                // 流程不可用时回滚体力，避免错误扣除。
                _energyModule.Recover(StartGameEnergyCost);
                _mainView?.SetFeedbackText("流程未就绪，请稍后再试");
                Log.Warning("[MainController] MainMenuProcedure 不可用，已回滚体力消耗");
                return;
            }

            bool changed = mainMenuProcedure.StartGame();
            if (!changed)
            {
                _energyModule.Recover(StartGameEnergyCost);
                _mainView?.SetFeedbackText("进入玩法失败，请重试");
                Log.Warning("[MainController] 状态切换失败，已回滚体力消耗");
                return;
            }

            _mainView?.SetFeedbackText(string.Empty);
            _mainModel?.SetGameStarted(true);
        }

        private void InitializeEnergyBindings()
        {
            if (!ModuleSystem.TryGet<IEnergyModule>(out _energyModule))
            {
                _energyModule = null;
                _mainView?.SetEnergyDisplayUnavailable();
                _mainView?.SetFeedbackText("体力系统未初始化");
                _mainView?.SetStartButtonInteractable(false);
                _mainModel?.SetInteractable(false);
                _mainModel?.SetEnergy(0, 0);
                Log.Warning("[MainController] 未找到 IEnergyModule，主界面仅显示占位信息");
                return;
            }

            EventBinder.BindEvent(GameLogicEntry.Event.EnergyChangedEvent, HandleEnergyChanged);

            HandleEnergyChanged(new EnergyChangedEvent(_energyModule.CurrentEnergy, _energyModule.MaxEnergy));
        }

        private void HandleEnergyChanged(EnergyChangedEvent e)
        {
            _mainView?.SetEnergyText(e.Current, e.Max);
            UpdateCountdownDisplay();

            bool canStart = e.Current >= StartGameEnergyCost;
            _mainView?.SetStartButtonInteractable(canStart);

            _mainModel?.SetInteractable(canStart);
            _mainModel?.SetEnergy(e.Current, e.Max);

            if (canStart)
            {
                _mainView?.SetFeedbackText(string.Empty);
            }

            // 同时刷新关卡显示
            RefreshLevelDisplay();
        }

        private void InitializeLevelDisplay()
        {
            if (!ModuleSystem.TryGet<ILevelModule>(out _levelModule))
            {
                _levelModule = null;
                _mainView?.SetLevelDisplayUnavailable();
                Log.Warning("[MainController] 未找到 ILevelModule");
                return;
            }

            RefreshLevelDisplay();
        }

        private void RefreshLevelDisplay()
        {
            if (_levelModule == null)
            {
                _mainView?.SetLevelDisplayUnavailable();
                return;
            }

            _mainView?.SetLevelText(_levelModule.CurrentLevelId);
        }

        private void InitializeCountdownTimer()
        {
            if (!ModuleSystem.TryGet<ITimerManager>(out _timerManager))
            {
                return;
            }

            // 每秒刷新倒计时显示
            _countdownTimerId = _timerManager.ScheduleLoop(1f, 1f, UpdateCountdownDisplay);
        }

        private void UpdateCountdownDisplay()
        {
            if (_energyModule == null || _mainView == null)
            {
                return;
            }

            // 每秒刷新体力数值（动态计算）和倒计时
            _mainView.SetEnergyText(_energyModule.CurrentEnergy, _energyModule.MaxEnergy);

            bool canStart = _energyModule.CurrentEnergy >= StartGameEnergyCost;
            _mainView.SetStartButtonInteractable(canStart);

            if (_energyModule.IsRecovering)
            {
                _mainView.SetEnergyRecoveryCountdown(_energyModule.TimeToNextRecovery);
            }
        }

        private void CancelCountdownTimer()
        {
            if (_countdownTimerId != 0 && _timerManager != null)
            {
                _timerManager.Cancel(_countdownTimerId);
                _countdownTimerId = 0;
            }
        }

        private bool TryGetMainMenuProcedure(out MainMenuProcedure procedure)
        {
            procedure = null;

            var procedureManager = GameLogicEntry.Procedure;
            if (procedureManager == null)
            {
                return false;
            }

            if (!procedureManager.HasProcedure<MainMenuProcedure>())
            {
                return false;
            }

            procedure = procedureManager.GetProcedure<MainMenuProcedure>();
            return procedure != null;
        }
    }
}
