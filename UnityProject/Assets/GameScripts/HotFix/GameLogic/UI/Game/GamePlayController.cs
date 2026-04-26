using System;
using System.ComponentModel;
using Cysharp.Threading.Tasks;
using EF.Common;
using EF.Debugger;
using EF.UI;
using UnityEngine;

namespace GameLogic
{
    /// <summary>
    /// 玩法主界面控制器。
    /// </summary>
    public class GamePlayController : UIController
    {
        private const string GameMenuViewLocation = "GameMenuView";
        private const string GameMenuWindowName = "GameMenuView";

        private GamePlayView _gamePlayView;
        private GamePlayModel _gamePlayModel;
        private IUIManager _uiManager;
        private bool _isOpeningPauseMenu;
        private GameMenuController _gameMenuController;
        private IEnergyModule _energyModule;
        private ILevelModule _levelModule;
        private bool _levelCompleted;

        protected override void OnInitialize()
        {
            base.OnInitialize();
            _gamePlayView = GetView<GamePlayView>();
            _gamePlayModel = TryGetModel<GamePlayModel>();
            _uiManager = GameLogicEntry.UI;
            Log.Info("[GamePlayController] 玩法主界面控制器初始化完成");
        }

        protected override void OnEnter(object userData)
        {
            base.OnEnter(userData);
            _levelCompleted = false;

            if (_gamePlayView != null)
            {
                BindEvent<Action>(
                    h => _gamePlayView.OnPauseClicked += h,
                    h => _gamePlayView.OnPauseClicked -= h,
                    HandlePauseClicked);
            }

            if (_gamePlayModel != null)
            {
                BindEvent<PropertyChangedEventHandler>(
                    h => _gamePlayModel.PropertyChanged += h,
                    h => _gamePlayModel.PropertyChanged -= h,
                    HandleGamePlayModelChanged);

                RefreshScore(_gamePlayModel.CurrentScore);
            }
            else
            {
                RefreshScore(0);
                Log.Warning("[GamePlayController] 未找到 GamePlayModel，积分显示将固定为 0");
            }

            // 初始化体力绑定
            InitializeEnergyBindings();

            // 初始化关卡绑定
            InitializeLevelBindings();
        }

        protected override void OnExit()
        {
            UnsubscribeMenuController();
            _isOpeningPauseMenu = false;
            base.OnExit();
        }

        private void HandlePauseClicked()
        {
            OpenPauseMenuAsync();
        }

        private async void OpenPauseMenuAsync()
        {
            if (_uiManager == null)
            {
                Log.Warning("[GamePlayController] UIManager 为空，无法打开暂停菜单");
                return;
            }

            if (_isOpeningPauseMenu)
            {
                return;
            }

            if (_uiManager.TryGetController<GameMenuController>(GameMenuWindowName, out _))
            {
                return;
            }

            _isOpeningPauseMenu = true;

            try
            {
                int currentScore = _gamePlayModel != null ? _gamePlayModel.CurrentScore : 0;
                await _uiManager.OpenWindowAsync<GameMenuView, GameMenuController>(
                    location: GameMenuViewLocation,
                    layer: UILayer.Popup,
                    cacheOnClose: false,
                    allowMultiple: false,
                    userData: currentScore);

                // 暂停菜单打开成功后，订阅事件
                if (_uiManager.TryGetController<GameMenuController>(GameMenuWindowName, out var menuController))
                {
                    _gameMenuController = menuController;
                    _gameMenuController.OnBackRequested += HandleBackToMainMenu;
                    _gameMenuController.OnContinueRequested += HandleContinueGame;
                }
            }
            catch (Exception ex)
            {
                Log.Error($"[GamePlayController] 打开暂停菜单失败：{ex.Message}");
            }
            finally
            {
                _isOpeningPauseMenu = false;
            }
        }

        private void HandleBackToMainMenu()
        {
            UnsubscribeMenuController();

            var procedure = GameLogicEntry.Procedure.GetProcedure<GamePlayProcedure>();
            if (procedure != null)
            {
                try
                {
                    procedure.ReturnToMainMenu();
                    EnsureBackTransitionFallbackAsync().Forget();
                }
                catch (Exception ex)
                {
                    Time.timeScale = 1f;
                    _uiManager?.CloseWindowAsync(GameMenuWindowName).Forget();
                    Log.Error($"[GamePlayController] 返回主菜单异常：{ex.Message}");
                }
            }
            else
            {
                Time.timeScale = 1f;
                _uiManager?.CloseWindowAsync(GameMenuWindowName).Forget();
                Log.Error("[GamePlayController] 无法获取 GamePlayProcedure，返回主菜单失败");
            }
        }

        private void HandleContinueGame()
        {
            UnsubscribeMenuController();
            Log.Info("[GamePlayController] 玩家选择继续游戏");
        }

        private async UniTaskVoid EnsureBackTransitionFallbackAsync()
        {
            await UniTask.Yield();

            if (_uiManager == null)
            {
                return;
            }

            if (!_uiManager.TryGetController<GameMenuController>(GameMenuWindowName, out _))
            {
                return;
            }

            Time.timeScale = 1f;
            _uiManager.CloseWindowAsync(GameMenuWindowName).Forget();
            Log.Warning("[GamePlayController] 返回主菜单后暂停菜单仍存在，已执行回退清理");
        }

        private void UnsubscribeMenuController()
        {
            if (_gameMenuController != null)
            {
                _gameMenuController.OnBackRequested -= HandleBackToMainMenu;
                _gameMenuController.OnContinueRequested -= HandleContinueGame;
                _gameMenuController = null;
            }
        }

        private void HandleGamePlayModelChanged(object sender, PropertyChangedEventArgs e)
        {
            if (!string.IsNullOrEmpty(e.PropertyName) && e.PropertyName != nameof(GamePlayModel.CurrentScore))
            {
                return;
            }

            if (_gamePlayModel == null)
            {
                return;
            }

            RefreshScore(_gamePlayModel.CurrentScore);
        }

        private void RefreshScore(int score)
        {
            _gamePlayView?.UpdateScore(score);

            if (_uiManager != null && _uiManager.TryGetView<GameMenuView>(GameMenuWindowName, out var gameMenuView))
            {
                gameMenuView.UpdateScore(score);
            }
        }

        private void InitializeEnergyBindings()
        {
            if (!ModuleSystem.TryGet<IEnergyModule>(out _energyModule))
            {
                _energyModule = null;
                Log.Warning("[GamePlayController] 未找到 IEnergyModule");
                return;
            }

            EventBinder.BindEvent(GameLogicEntry.Event.EnergyChangedEvent, HandleEnergyChanged);

            HandleEnergyChanged(new EnergyChangedEvent(_energyModule.CurrentEnergy, _energyModule.MaxEnergy));
        }

        private void InitializeLevelBindings()
        {
            if (!ModuleSystem.TryGet<ILevelModule>(out _levelModule))
            {
                _levelModule = null;
                Log.Warning("[GamePlayController] 未找到 ILevelModule");
                return;
            }

            // 订阅进度变化事件
            EventBinder.BindEvent(GameLogicEntry.Event.LevelProgressChangedEvent, HandleLevelProgressChanged);

            // 订阅通关事件
            EventBinder.BindEvent(GameLogicEntry.Event.LevelCompleteEvent, HandleLevelCompleteEvent);

            // 初始显示
            HandleLevelProgressChanged(new LevelProgressChangedEvent(_levelModule.CurrentLevelId, _levelModule.KillCount, _levelModule.RequiredKills));
        }

        private void HandleLevelProgressChanged(LevelProgressChangedEvent e)
        {
            _gamePlayView?.UpdateLevel(e.LevelId, e.KillCount, e.RequiredKills);
        }

        private void HandleLevelCompleteEvent(LevelCompleteEvent e)
        {
            if (_levelCompleted) return;
            _levelCompleted = true;
            
            Log.Info("[GamePlayController] 关卡通关!");
            HandleLevelComplete();
        }

        private void HandleEnergyChanged(EnergyChangedEvent e)
        {
            _gamePlayView?.UpdateEnergy(e.Current, e.Max);
        }

        private void RefreshLevelDisplay()
        {
            if (_levelModule == null || _gamePlayView == null) return;

            _gamePlayView.UpdateLevel(
                _levelModule.CurrentLevelId,
                _levelModule.KillCount,
                _levelModule.RequiredKills);

            // 检查通关条件
            if (!_levelCompleted && _levelModule.CheckLevelComplete())
            {
                _levelCompleted = true;
                Log.Info("[GamePlayController] 关卡通关!");
                HandleLevelComplete();
            }
        }

        private void HandleLevelComplete()
        {
            if (_levelModule != null)
            {
                _levelModule.AdvanceToNextLevel();
            }

            // 返回主菜单
            var procedure = GameLogicEntry.Procedure.GetProcedure<GamePlayProcedure>();
            procedure?.ReturnToMainMenu();
        }
    }
}
