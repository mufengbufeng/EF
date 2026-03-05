using System;
using EF.Debugger;
using EF.UI;
using TMPro;
using UnityEngine;
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
            EnsureRuntimeTextComponents();
            UpdateScore(0);
            UpdateLevel(1, 0, 10);
            UpdateEnergy(0, 0);
        }

        private void EnsureRuntimeTextComponents()
        {
            RectTransform root = transform as RectTransform;
            if (root == null) return;

            // 创建关卡文本（左上角，在积分下方）
            if (_levelText == null)
            {
                _levelText = CreateRuntimeText(
                    root,
                    "LevelTextRuntime",
                    new Vector2(0f, 1f),
                    new Vector2(0f, 1f),
                    new Vector2(24f, -60f),
                    new Vector2(300f, 40f),
                    24,
                    Color.yellow,
                    TextAlignmentOptions.TopLeft);
            }

            // 创建体力文本（左上角，在关卡下方）
            if (_energyText == null)
            {
                _energyText = CreateRuntimeText(
                    root,
                    "EnergyTextRuntime",
                    new Vector2(0f, 1f),
                    new Vector2(0f, 1f),
                    new Vector2(24f, -100f),
                    new Vector2(200f, 40f),
                    24,
                    Color.cyan,
                    TextAlignmentOptions.TopLeft);
            }
        }

        private static TextMeshProUGUI CreateRuntimeText(
            RectTransform parent,
            string objectName,
            Vector2 anchorMin,
            Vector2 anchorMax,
            Vector2 anchoredPosition,
            Vector2 sizeDelta,
            float fontSize,
            Color color,
            TextAlignmentOptions alignment)
        {
            GameObject textObject = new GameObject(objectName, typeof(RectTransform), typeof(TextMeshProUGUI));
            RectTransform rectTransform = textObject.GetComponent<RectTransform>();
            rectTransform.SetParent(parent, false);
            rectTransform.anchorMin = anchorMin;
            rectTransform.anchorMax = anchorMax;
            rectTransform.pivot = new Vector2(0.5f, 0.5f);
            rectTransform.anchoredPosition = anchoredPosition;
            rectTransform.sizeDelta = sizeDelta;

            TextMeshProUGUI text = textObject.GetComponent<TextMeshProUGUI>();
            text.fontSize = fontSize;
            text.color = color;
            text.alignment = alignment;
            text.raycastTarget = false;
            text.text = string.Empty;
            return text;
        }

        /// <summary>
        /// 刷新击败积分显示。
        /// </summary>
        /// <param name="score">积分值。</param>
        public void UpdateScore(int score)
        {
            EnsureRuntimeTextComponents();
            
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
            EnsureRuntimeTextComponents();
            
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
            EnsureRuntimeTextComponents();
            
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
