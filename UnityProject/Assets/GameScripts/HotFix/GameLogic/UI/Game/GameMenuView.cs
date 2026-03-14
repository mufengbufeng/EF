using System;
using EF.Debugger;
using EF.UI;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

namespace GameLogic
{
    /// <summary>
    /// 暂停菜单视图。
    /// </summary>
    public class GameMenuView : UIView
    {
        public Button _continueButton;
        public Button _backButton;
        public TextMeshProUGUI _pointText;

        public event Action OnContinueClicked;
        public event Action OnBackClicked;

        protected override void OnInitialize()
        {
            base.OnInitialize();
            UHub.Initialize();
            EnsurePointText();
        }

        protected override void OnBindings()
        {
            base.OnBindings();

            if (_continueButton != null)
            {
                BindEvent(_continueButton.onClick, HandleContinueClicked);
            }
            else
            {
                Log.Warning("[GameMenuView] ContinueButton 绑定失败，请检查 ReferenceCollector 配置");
            }

            if (_backButton != null)
            {
                BindEvent(_backButton.onClick, HandleBackClicked);
            }
            else
            {
                Log.Warning("[GameMenuView] BackButton 绑定失败，请检查 ReferenceCollector 配置");
            }
        }

        protected override void OnOpen(object userData)
        {
            base.OnOpen(userData);
            if (userData is int score)
            {
                UpdateScore(score);
            }
        }

        /// <summary>
        /// 刷新暂停菜单中的击败积分文本。
        /// </summary>
        /// <param name="score">积分值。</param>
        public void UpdateScore(int score)
        {
            if (_pointText == null)
            {
                return;
            }

            int safeScore = score < 0 ? 0 : score;
            _pointText.text = $"击败积分: {safeScore}";
        }

        protected override void OnRelease()
        {
            OnContinueClicked = null;
            OnBackClicked = null;
            base.OnRelease();
        }

        private void EnsurePointText()
        {
            if (_pointText != null)
            {
                return;
            }

            var pointTextObject = new GameObject("pointText");
            pointTextObject.transform.SetParent(transform, false);
            pointTextObject.layer = gameObject.layer;

            var rectTransform = pointTextObject.AddComponent<RectTransform>();
            rectTransform.anchorMin = new Vector2(0.5f, 1f);
            rectTransform.anchorMax = new Vector2(0.5f, 1f);
            rectTransform.pivot = new Vector2(0.5f, 1f);
            rectTransform.anchoredPosition = new Vector2(0f, -120f);
            rectTransform.sizeDelta = new Vector2(260f, 60f);

            _pointText = pointTextObject.AddComponent<TextMeshProUGUI>();
            _pointText.fontSize = 32f;
            _pointText.alignment = TextAlignmentOptions.Center;
            _pointText.color = Color.white;
            _pointText.text = "击败积分: 0";
        }

        private void HandleContinueClicked()
        {
            Log.Info("[GameMenuView] 点击继续按钮");
            OnContinueClicked?.Invoke();
        }

        private void HandleBackClicked()
        {
            Log.Info("[GameMenuView] 点击返回按钮");
            OnBackClicked?.Invoke();
        }
    }
}
