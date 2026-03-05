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
        public TextMeshProUGUI _levelText;
        public TextMeshProUGUI _energyText;
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
            UpdateLevel(1, 0, 10);
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

        /// <summary>
        /// 刷新关卡信息显示。
        /// </summary>
        /// <param name="levelId">关卡ID。</param>
        /// <param name="killCount">当前击杀数。</param>
        /// <param name="requiredKills">目标击杀数。</param>
        public void UpdateLevel(int levelId, int killCount, int requiredKills)
        {
            if (_levelText != null)
            {
                _levelText.text = $"关卡 {levelId} | 击杀: {killCount}/{requiredKills}";
            }
        }

        /// <summary>
        /// 刷新体力显示。
        /// </summary>
        /// <param name="currentEnergy">当前体力。</param>
        /// <param name="maxEnergy">最大体力。</param>
        public void UpdateEnergy(int currentEnergy, int maxEnergy)
        {
            if (_energyText != null)
            {
                _energyText.text = $"体力: {currentEnergy}/{maxEnergy}";
            }
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
