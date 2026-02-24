using System;
using EF.Debugger;
using EF.UI;
using TMPro;
using UnityEngine.UI;

namespace GameLogic
{
    /// <summary>
    /// 玩法主界面视图。
    /// </summary>
    public class GamePlayView : UIView
    {
        public TextMeshProUGUI _pointText;
        public Button _pauseButton;

        public event Action OnPauseClicked;

        protected override void OnInitialize()
        {
            base.OnInitialize();
            UHub.Initialize();
        }

        protected override void OnBindings()
        {
            base.OnBindings();

            if (_pauseButton != null)
            {
                BindEvent(_pauseButton.onClick, HandlePauseButtonClicked);
            }
            else
            {
                Log.Warning("[GamePlayView] PauseButton 绑定失败，请检查 ReferenceCollector 的 PauseButton 配置");
            }
        }

        protected override void OnOpen(object userData)
        {
            base.OnOpen(userData);
            UpdateScore(0);
        }

        /// <summary>
        /// 刷新击败积分显示。
        /// </summary>
        /// <param name="score">积分值。</param>
        public void UpdateScore(int score)
        {
            if (_pointText == null)
            {
                Log.Warning("[GamePlayView] PointText 绑定失败，请检查 ReferenceCollector 的 PointText 配置");
                return;
            }

            int safeScore = score < 0 ? 0 : score;
            _pointText.text = $"击败积分: {safeScore}";
        }

        protected override void OnRelease()
        {
            OnPauseClicked = null;
            base.OnRelease();
        }

        private void HandlePauseButtonClicked()
        {
            Log.Info("[GamePlayView] 点击暂停按钮");
            OnPauseClicked?.Invoke();
        }
    }
}
