using UnityEngine;
using UnityEngine.Events;
using UnityEngine.EventSystems;
using UnityEngine.UI;

namespace GameLogic
{
    public class JoystickBehavior : MonoBehaviour, IPointerDownHandler, IDragHandler, IPointerUpHandler
    {
        [SerializeField] Canvas canvas;
        [SerializeField] CanvasGroup canvasGroup;

        [Header("Joystick")]
        [SerializeField] Image backgroundImage;
        [SerializeField] Image handleImage;

        [Space]
        [SerializeField] float handleRange = 1;
        [SerializeField] float deadZone = 0;

        private RectTransform baseRectTransform;
        private RectTransform backgroundRectTransform;
        private RectTransform handleRectTransform;

        private bool isBeingUsed;
        public bool IsBeingUsed => isBeingUsed;
        // [SerializeField]
        // private InputManager _InputManager;
        private Camera canvasCamera;

        // private Vector2 value = Vector2.zero; // 由 InputManager 管理
        // public Vector2 Value => value; // 由 InputManager 管理

        private Vector2 defaultAnchoredPosition;

        public event UnityAction OnBeingUsed;

        public bool IsEnabled { get; private set; }

        void Awake()
        {
            // Log.Info("InputManager InstanceId " + _InputManager.GetInstanceID());
            // _InputManager = InputManager.Instance;

            baseRectTransform = GetComponent<RectTransform>();
            backgroundRectTransform = backgroundImage.rectTransform;
            handleRectTransform = handleImage.rectTransform;

            if (canvas.renderMode == RenderMode.ScreenSpaceCamera)
                canvasCamera = canvas.worldCamera;

            var center = new Vector2(0.5f, 0.5f);
            backgroundRectTransform.pivot = center;
            handleRectTransform.anchorMin = center;
            handleRectTransform.anchorMax = center;
            handleRectTransform.pivot = center;
            handleRectTransform.anchoredPosition = Vector2.zero;

            isBeingUsed = false;

            defaultAnchoredPosition = backgroundRectTransform.anchoredPosition;

        }

        void Start()
        {

        }

        public void OnPointerDown(PointerEventData eventData)
        {
            if (RectTransformUtility.ScreenPointToLocalPointInRectangle(baseRectTransform, eventData.position, canvasCamera, out var localPoint))
            {
                var pivotOffset = baseRectTransform.pivot * baseRectTransform.sizeDelta;
                backgroundRectTransform.anchoredPosition = localPoint - (backgroundRectTransform.anchorMax * baseRectTransform.sizeDelta) + pivotOffset;
            }
            else
            {
                backgroundRectTransform.anchoredPosition = Vector2.zero;
            }

            isBeingUsed = true;
            InputManager.Instance.NotifyJoystickUsed(); // 通知 InputManager 摇杆被使用
            // _InputManager.NotifyJoystickUsed();

            OnBeingUsed?.Invoke();

            OnDrag(eventData);
        }

        public void OnPointerUp(PointerEventData eventData)
        {
            if (!isBeingUsed)
                return;

            isBeingUsed = false;

            ResetJoystick();
        }

        public void OnDrag(PointerEventData eventData)
        {
            if (!isBeingUsed)
                return;


            // 暂时保留 Handle 的视觉更新逻辑，但需要确认 InputManager 是否提供类似功能或是否需要调整
            // 如果 InputManager 完全接管输入值，这里的 Handle 位置更新可能需要基于 InputManager 的值，或者简化为仅视觉反馈
            // 根据当前任务要求，仅移除本地 value 计算，暂时注释掉 Handle 位置更新
            var position = RectTransformUtility.WorldToScreenPoint(canvasCamera, backgroundRectTransform.position);
            var radiusVector = backgroundRectTransform.sizeDelta / 2; // radius is a Vector2
            var radius = radiusVector.x; // Use x component as the float radius
            var localPos = (eventData.position - position) / (canvas.scaleFactor); // 计算相对于背景的本地位置
            var clampedPos = Vector2.ClampMagnitude(localPos, radius * handleRange); // 使用 float radius
            handleRectTransform.anchoredPosition = clampedPos; // 更新 Handle 位置以提供视觉反馈
            InputManager.Instance.SetJoystickValue(clampedPos / (radius * handleRange)); // 计算并设置摇杆值
            // _InputManager.SetJoystickValue(clampedPos / (radius * handleRange)); // 计算并设置摇杆值
        }

        public void ResetJoystick()
        {
            isBeingUsed = false;

            backgroundRectTransform.anchoredPosition = defaultAnchoredPosition;

            // value = Vector2.zero; // 由 InputManager 管理
            handleRectTransform.anchoredPosition = Vector2.zero;
            InputManager.Instance.SetJoystickValue(Vector2.zero); // 由 InputManager 管理
            // _InputManager.SetJoystickValue(Vector2.zero); // 由 InputManager 管理
        }

        public void Enable()
        {
            IsEnabled = true;
            canvasGroup.alpha = 1;
        }

        public void Disable()
        {
            IsEnabled = false;
            canvasGroup.alpha = 0;

            isBeingUsed = false;

            ResetJoystick();
        }

        private void OnDestroy()
        {
        }

        public void Hide()
        {
            backgroundImage.color = backgroundImage.color.SetAlpha(0f);
            handleImage.color = backgroundImage.color.SetAlpha(0f);
        }

        public void Show()
        {
            backgroundImage.SetAlpha(1f);
            handleImage.SetAlpha(1f);
        }
    }
}
