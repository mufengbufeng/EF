using System;
using Cysharp.Threading.Tasks;
using EF.Debugger;
using EF.UI;
using UnityEngine;

namespace GameLogic
{
    /// <summary>
    /// 暂停菜单控制器。
    /// </summary>
    public class GameMenuController : UIController
    {
        private const string GameMenuWindowName = "GameMenuView";

        private GameMenuView _gameMenuView;

        public event Action OnContinueRequested;
        public event Action OnBackRequested;

        protected override void OnInitialize()
        {
            base.OnInitialize();
            _gameMenuView = GetView<GameMenuView>();
            Log.Info("[GameMenuController] 暂停菜单控制器初始化完成");
        }

        protected override void OnEnter(object userData)
        {
            base.OnEnter(userData);

            if (_gameMenuView != null)
            {
                BindEvent<Action>(
                    h => _gameMenuView.OnContinueClicked += h,
                    h => _gameMenuView.OnContinueClicked -= h,
                    HandleContinueClicked);

                BindEvent<Action>(
                    h => _gameMenuView.OnBackClicked += h,
                    h => _gameMenuView.OnBackClicked -= h,
                    HandleBackClicked);
            }

            int currentScore = userData is int score ? score : 0;
            _gameMenuView?.UpdateScore(currentScore);
            Time.timeScale = 0f;
            Log.Info($"[GameMenuController] 暂停菜单已打开，当前积分: {currentScore}");
        }

        protected override void OnExit()
        {
            base.OnExit();
            Log.Info("[GameMenuController] 暂停菜单已关闭");
        }

        protected override void OnRelease()
        {
            OnContinueRequested = null;
            OnBackRequested = null;
            base.OnRelease();
        }

        private void HandleContinueClicked()
        {
            OnContinueRequested?.Invoke();
            ResumeAndCloseMenu();
        }

        private void HandleBackClicked()
        {
            Log.Info("[GameMenuController] 点击返回按钮，准备退出游戏回到主界面");
            // 返回主菜单路径由 GamePlayProcedure.OnLeave 统一执行清理。
            if (OnBackRequested != null)
            {
                OnBackRequested.Invoke();
                return;
            }

            Log.Warning("[GameMenuController] 未订阅返回主菜单事件，执行回退清理");
            ResumeAndCloseMenu();
        }

        private void ResumeAndCloseMenu()
        {
            Time.timeScale = 1f;
            GameLogicEntry.UI.CloseWindowAsync(GameMenuWindowName).Forget();
        }
    }
}
