using System;
using EF.Debugger;
using EF.UI;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

namespace GameLogic
{
    /// <summary>
    /// 游戏主界面视图
    /// 使用 UHub 实现自动组件绑定和事件管理
    /// </summary>
    public class MainView : UIView
    {
        // 使用 UHub 自动绑定，字段名 _startGameBtn 映射到 ReferenceCollector 中的 "StartGameBtn"
        public Button _startGameBtn;

        /// <summary>
        /// 体力显示文本，可在 Prefab 绑定；未绑定时会在运行时自动创建。
        /// </summary>
        public TextMeshProUGUI _energyText;

        /// <summary>
        /// 关卡显示文本，可在 Prefab 绑定；未绑定时会在运行时自动创建。
        /// </summary>
        public TextMeshProUGUI _levelText;

        /// <summary>
        /// 反馈文本，可在 Prefab 绑定；未绑定时会在运行时自动创建。
        /// </summary>
        public TextMeshProUGUI _feedbackText;

        /// <summary>
        /// 开始游戏事件
        /// </summary>
        public event Action OnStartGameRequested;

        protected override void OnInitialize()
        {
            base.OnInitialize();
            UHub.Initialize();
            // UHub 会自动绑定 _startGameBtn 到 "StartGameBtn" 组件
            // 无需手动从 ReferenceCollector 获取组件引用
        }

        protected override void OnBindings()
        {
            base.OnBindings();

            // 使用 UHub 统一事件管理，会在 UIView 释放时自动清理
            if (_startGameBtn != null)
            {
                BindEvent(_startGameBtn.onClick, OnStartGameButtonClicked);
            }

            // 记录 UHub 状态用于调试
            Log.Info($"[MainView] UHub 初始化完成，绑定了 {UHub.EventBindingCount} 个事件");
        }

        protected override void OnOpen(object userData)
        {
            base.OnOpen(userData);

            EnsureRuntimeTextComponents();

            // 验证组件绑定结果
            if (_startGameBtn != null)
            {
                Log.Info("[MainView] 开始游戏按钮组件绑定成功");
            }
            else
            {
                Log.Warning("[MainView] 开始游戏按钮组件绑定失败，请检查 ReferenceCollector 配置");
            }

            SetFeedbackText(string.Empty);
        }

        protected override void OnRefresh(object userData)
        {
            base.OnRefresh(userData);

            // 根据模型状态刷新界面
            if (TryGetModelData<IMainModelData>(out var modelData))
            {
                // 更新按钮可交互状态
                SetStartButtonInteractable(modelData.IsInteractable);
            }
        }

        public void SetEnergyText(int currentEnergy, int maxEnergy)
        {
            EnsureRuntimeTextComponents();
            if (_energyText != null)
            {
                _energyText.text = $"体力：{currentEnergy}/{maxEnergy}";
            }
        }

        public void SetEnergyDisplayUnavailable()
        {
            EnsureRuntimeTextComponents();
            if (_energyText != null)
            {
                _energyText.text = "体力：--/--";
            }
        }

        public void SetLevelText(int levelId)
        {
            EnsureRuntimeTextComponents();
            if (_levelText != null)
            {
                _levelText.text = $"当前关卡：{levelId}";
            }
        }

        public void SetLevelDisplayUnavailable()
        {
            EnsureRuntimeTextComponents();
            if (_levelText != null)
            {
                _levelText.text = "当前关卡：--";
            }
        }

        public void SetFeedbackText(string message)
        {
            EnsureRuntimeTextComponents();
            if (_feedbackText != null)
            {
                _feedbackText.text = message ?? string.Empty;
            }
        }

        public void SetStartButtonInteractable(bool interactable)
        {
            if (_startGameBtn != null)
            {
                _startGameBtn.interactable = interactable;
            }
        }

        private void OnStartGameButtonClicked()
        {
            Log.Info("[MainView] 开始游戏按钮被点击");

            // 触发开始游戏事件，让Controller处理具体逻辑
            OnStartGameRequested?.Invoke();
        }

        private void EnsureRuntimeTextComponents()
        {
            RectTransform root = transform as RectTransform;
            if (root == null)
            {
                return;
            }

            if (_energyText == null)
            {
                _energyText = CreateRuntimeText(
                    root,
                    "EnergyTextRuntime",
                    new Vector2(0f, 1f),
                    new Vector2(0f, 1f),
                    new Vector2(24f, -24f),
                    new Vector2(300f, 40f),
                    26,
                    Color.white,
                    TextAlignmentOptions.TopLeft);
            }

            if (_levelText == null)
            {
                _levelText = CreateRuntimeText(
                    root,
                    "LevelTextRuntime",
                    new Vector2(0f, 1f),
                    new Vector2(0f, 1f),
                    new Vector2(24f, -70f),
                    new Vector2(300f, 40f),
                    26,
                    Color.white,
                    TextAlignmentOptions.TopLeft);
            }

            if (_feedbackText == null)
            {
                _feedbackText = CreateRuntimeText(
                    root,
                    "FeedbackTextRuntime",
                    new Vector2(0.5f, 0f),
                    new Vector2(0.5f, 0f),
                    new Vector2(0f, 120f),
                    new Vector2(500f, 48f),
                    28,
                    new Color(1f, 0.35f, 0.35f, 1f),
                    TextAlignmentOptions.Center);
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

        protected override void OnRelease()
        {
            // 清理 C# 事件订阅 (UHub 只管理 Unity 事件)
            OnStartGameRequested = null;

            // UHub 会自动清理所有通过 BindEvent 绑定的 Unity 事件
            // 无需手动调用 _startGameBtn.onClick.RemoveListener

            base.OnRelease();
        }
    }
}
