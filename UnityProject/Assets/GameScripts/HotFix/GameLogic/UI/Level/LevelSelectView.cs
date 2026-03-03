using System;
using System.Collections.Generic;
using EF.Debugger;
using EF.UI;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

namespace GameLogic
{
    public class LevelSelectView : UIView
    {
        [UHubBind("EnergyText")] public TextMeshProUGUI _energyText;
        [UHubBind("TotalStarsText")] public TextMeshProUGUI _totalStarsText;
        [UHubBind("BackButton")] public Button _backButton;
        [UHubBind("LevelPanel")] public RectTransform _levelPanel;

        public GameObject _levelButtonPrefab;

        private readonly List<LevelButton> _levelButtons = new();

        public event Action<int> OnLevelClicked;
        public event Action OnBackClicked;

        protected override void OnInitialize()
        {
            base.OnInitialize();
            UHub.Initialize();
        }

        protected override void OnBindings()
        {
            base.OnBindings();

            if (_backButton != null)
            {
                BindEvent(_backButton.onClick, HandleBackButtonClicked);
            }
            else
            {
                Log.Warning("[LevelSelectView] BackButton binding failed");
            }
        }

        public void UpdateEnergy(int current, int max)
        {
            if (_energyText != null)
            {
                _energyText.text = $"体力: {current}/{max}";
            }
        }

        public void UpdateTotalStars(int totalStars, int maxStars)
        {
            if (_totalStarsText != null)
            {
                _totalStarsText.text = $"总星级: {totalStars}/{maxStars}";
            }
        }

        public void InitializeLevels(int maxUnlockedLevel, Dictionary<int, int> levelStars, int totalLevels)
        {
            foreach (var btn in _levelButtons)
            {
                if (btn != null)
                {
                    btn.OnClick -= HandleLevelButtonClicked;
                    Destroy(btn.gameObject);
                }
            }
            _levelButtons.Clear();

            if (_levelPanel == null || _levelButtonPrefab == null)
            {
                Log.Warning("[LevelSelectView] Level panel or prefab is not configured");
                return;
            }

            for (int i = 1; i <= totalLevels; i++)
            {
                int stars = levelStars != null && levelStars.TryGetValue(i, out int s) ? s : 0;
                CreateLevelButton(i, i <= maxUnlockedLevel, stars);
            }
        }

        public void UpdateLevelState(int levelId, bool isUnlocked, int stars)
        {
            foreach (var btn in _levelButtons)
            {
                if (btn != null && btn.LevelId == levelId)
                {
                    btn.UpdateState(isUnlocked, stars);
                    return;
                }
            }
        }

        private void CreateLevelButton(int levelId, bool isUnlocked, int stars)
        {
            var go = Instantiate(_levelButtonPrefab, _levelPanel);
            var levelButton = go.GetComponent<LevelButton>() ?? go.AddComponent<LevelButton>();
            levelButton.Setup(levelId, isUnlocked, stars);
            levelButton.OnClick += HandleLevelButtonClicked;
            _levelButtons.Add(levelButton);
        }

        private void HandleLevelButtonClicked(int levelId)
        {
            OnLevelClicked?.Invoke(levelId);
        }

        private void HandleBackButtonClicked()
        {
            OnBackClicked?.Invoke();
        }

        protected override void OnRelease()
        {
            foreach (var btn in _levelButtons)
            {
                if (btn != null)
                {
                    btn.OnClick -= HandleLevelButtonClicked;
                }
            }
            _levelButtons.Clear();

            OnLevelClicked = null;
            OnBackClicked = null;
            base.OnRelease();
        }
    }

    public class LevelButton : MonoBehaviour
    {
        [UHubBind("LevelText")] public TextMeshProUGUI _levelText;
        [UHubBind("StarContainer")] public GameObject _starContainer;
        [UHubBind("LockOverlay")] public GameObject _lockOverlay;

        public int LevelId { get; private set; }

        public event Action<int> OnClick;

        private Button _button;

        private void Awake()
        {
            _button = GetComponent<Button>();
            if (_button != null)
            {
                _button.onClick.AddListener(HandleClick);
            }
        }

        public void Setup(int levelId, bool isUnlocked, int stars)
        {
            LevelId = levelId;
            if (_levelText != null)
            {
                _levelText.text = levelId.ToString();
            }

            UpdateState(isUnlocked, stars);
        }

        public void UpdateState(bool isUnlocked, int stars)
        {
            if (_lockOverlay != null)
            {
                _lockOverlay.SetActive(!isUnlocked);
            }

            if (_button != null)
            {
                _button.interactable = isUnlocked;
            }

            if (_starContainer != null)
            {
                var starText = _starContainer.GetComponent<TextMeshProUGUI>();
                if (starText != null)
                {
                    int safeStars = Math.Clamp(stars, 0, 3);
                    starText.text = safeStars > 0 ? new string('★', safeStars) : string.Empty;
                }
            }
        }

        private void HandleClick()
        {
            OnClick?.Invoke(LevelId);
        }

        private void OnDestroy()
        {
            if (_button != null)
            {
                _button.onClick.RemoveListener(HandleClick);
            }
            OnClick = null;
        }
    }
}
