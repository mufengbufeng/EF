using EF.Feature;
using UnityEngine;
#if ENABLE_INPUT_SYSTEM
using UnityEngine.InputSystem;
#endif

namespace GameLogic
{
    /// <summary>
    /// 拖拽输入特性，处理鼠标和触控的拖拽操作。
    /// </summary>
    public class DragInputFeature : FeatureBase<DragInputData>
    {
        private enum ActivePointerType
        {
            None,
            Mouse,
            Touch
        }

        private const float DragOffsetAlignSpeed = 4f;

        private ActivePointerType _activePointerType;
        private int _activeTouchId;
        private Vector3 _dragOffset;
        private Camera _mainCamera;
        private float _fixedZ;

        /// <summary>
        /// 配置拖拽参数，缓存主摄像机。
        /// </summary>
        protected override void OnSetup(DragInputData data)
        {
            _fixedZ = data.FixedZ;
            ResetPointerState();
            _mainCamera = Camera.main;
        }

        /// <summary>
        /// 重置拖拽状态并释放摄像机引用。
        /// </summary>
        public override void OnDestroy()
        {
            base.OnDestroy();
            ResetPointerState();
            _mainCamera = null;
        }

        /// <summary>
        /// 每帧处理拖拽输入。
        /// </summary>
        public override void OnUpdate(float elapseSeconds, float realElapseSeconds)
        {
            if (!Enabled || Entity?.Handle == null)
            {
                return;
            }

            UpdateDragInput(elapseSeconds);
        }

        /// <summary>
        /// 根据当前指针类型分发拖拽输入处理。
        /// </summary>
        private void UpdateDragInput(float elapseSeconds)
        {
            Camera camera = GetMainCamera();
            if (camera == null)
            {
                return;
            }

            if (_activePointerType == ActivePointerType.None)
            {
                if (TryBeginTouchDrag(camera))
                {
                    return;
                }

                TryBeginMouseDrag(camera);
                return;
            }

            if (_activePointerType == ActivePointerType.Mouse)
            {
                UpdateMouseDrag(camera, elapseSeconds);
                return;
            }

            UpdateTouchDrag(camera, elapseSeconds);
        }

        /// <summary>
        /// 尝试检测触控开始拖拽。
        /// </summary>
        /// <returns>是否成功开始触控拖拽。</returns>
        private bool TryBeginTouchDrag(Camera camera)
        {
#if ENABLE_INPUT_SYSTEM
            Touchscreen touchscreen = Touchscreen.current;
            if (touchscreen != null)
            {
                var touches = touchscreen.touches;
                for (int i = 0; i < touches.Count; i++)
                {
                    var touch = touches[i];
                    if (!touch.press.wasPressedThisFrame)
                    {
                        continue;
                    }

                    Vector2 touchScreenPosition = touch.position.ReadValue();
                    Vector3 touchWorldPosition = ScreenToWorld(camera, touchScreenPosition, _fixedZ);
                    if (!IsPointerOnAvatar(touchWorldPosition))
                    {
                        continue;
                    }

                    _activePointerType = ActivePointerType.Touch;
                    _activeTouchId = touch.touchId.ReadValue();
                    _dragOffset = Entity.Handle.transform.position - touchWorldPosition;
                    return true;
                }
            }
#endif
#if ENABLE_LEGACY_INPUT_MANAGER
            int touchCount = Input.touchCount;
            for (int i = 0; i < touchCount; i++)
            {
                Touch touch = Input.GetTouch(i);
                if (touch.phase != TouchPhase.Began)
                {
                    continue;
                }

                Vector3 touchWorldPosition = ScreenToWorld(camera, touch.position, _fixedZ);
                if (!IsPointerOnAvatar(touchWorldPosition))
                {
                    continue;
                }

                _activePointerType = ActivePointerType.Touch;
                _activeTouchId = touch.fingerId;
                _dragOffset = Entity.Handle.transform.position - touchWorldPosition;
                return true;
            }
#endif
            return false;
        }

        /// <summary>
        /// 尝试检测鼠标按下开始拖拽。
        /// </summary>
        private void TryBeginMouseDrag(Camera camera)
        {
            if (!TryGetMouseDownPosition(out Vector2 mouseScreenPosition))
            {
                return;
            }

            Vector3 mouseWorldPosition = ScreenToWorld(camera, mouseScreenPosition, _fixedZ);
            if (!IsPointerOnAvatar(mouseWorldPosition))
            {
                return;
            }

            _activePointerType = ActivePointerType.Mouse;
            _dragOffset = Entity.Handle.transform.position - mouseWorldPosition;
        }

        /// <summary>
        /// 更新鼠标拖拽，将实体移动到鼠标位置。
        /// </summary>
        private void UpdateMouseDrag(Camera camera, float elapseSeconds)
        {
            if (!TryGetMouseHeldPosition(out Vector2 mouseScreenPosition))
            {
                ResetPointerState();
                return;
            }

            Vector3 mouseWorldPosition = ScreenToWorld(camera, mouseScreenPosition, _fixedZ);
            Vector3 targetPosition = BuildDragTargetPosition(mouseWorldPosition, elapseSeconds);
            SetClampedPosition(camera, targetPosition);
        }

        /// <summary>
        /// 更新触控拖拽，将实体移动到触控位置。
        /// </summary>
        private void UpdateTouchDrag(Camera camera, float elapseSeconds)
        {
            if (!TryGetTouchPosition(_activeTouchId, out Vector2 touchScreenPosition, out bool isPressed))
            {
                ResetPointerState();
                return;
            }

            if (!isPressed)
            {
                ResetPointerState();
                return;
            }

            Vector3 touchWorldPosition = ScreenToWorld(camera, touchScreenPosition, _fixedZ);
            Vector3 targetPosition = BuildDragTargetPosition(touchWorldPosition, elapseSeconds);
            SetClampedPosition(camera, targetPosition);
        }

        /// <summary>
        /// 计算拖拽目标位置（指针位置 + 偏移量）。
        /// </summary>
        private Vector3 BuildDragTargetPosition(Vector3 pointerWorldPosition, float elapseSeconds)
        {
            UpdateDragOffset(elapseSeconds);
            return pointerWorldPosition + _dragOffset;
        }

        /// <summary>
        /// 逐渐将拖拽偏移量归零，实现中心对齐效果。
        /// </summary>
        private void UpdateDragOffset(float elapseSeconds)
        {
            if (_dragOffset == Vector3.zero)
            {
                return;
            }

            float maxDelta = Mathf.Max(0f, elapseSeconds) * DragOffsetAlignSpeed;
            if (maxDelta <= 0f)
            {
                return;
            }

            _dragOffset = Vector3.MoveTowards(_dragOffset, Vector3.zero, maxDelta);
        }

        /// <summary>
        /// 判断指针世界坐标是否命中实体。
        /// </summary>
        private bool IsPointerOnAvatar(Vector3 pointerWorldPosition)
        {
            var collider = Entity.Handle.GetComponent<Collider2D>();
            if (collider != null)
            {
                return collider.OverlapPoint(pointerWorldPosition);
            }

            var renderer = Entity.Handle.GetComponent<SpriteRenderer>();
            if (renderer != null)
            {
                return renderer.bounds.Contains(pointerWorldPosition);
            }

            return Vector3.SqrMagnitude(Entity.Handle.transform.position - pointerWorldPosition) <= 0.64f;
        }

        /// <summary>
        /// 设置实体位置，通过 PositionClampFeature 进行边界约束。
        /// </summary>
        private void SetClampedPosition(Camera camera, Vector3 targetPosition)
        {
            var clampFeature = Entity.Features.GetFeature<PositionClampFeature>();
            if (clampFeature != null)
            {
                Entity.Handle.transform.position = clampFeature.ClampPosition(targetPosition);
                return;
            }

            Entity.Handle.transform.position = targetPosition;
        }

        /// <summary>
        /// 获取主摄像机，缓存避免重复查找。
        /// </summary>
        private Camera GetMainCamera()
        {
            if (_mainCamera == null)
            {
                _mainCamera = Camera.main;
            }

            return _mainCamera;
        }

        /// <summary>
        /// 屏幕坐标转世界坐标，保持固定 Z 值。
        /// </summary>
        private static Vector3 ScreenToWorld(Camera camera, Vector2 screenPosition, float targetZ)
        {
            float distance = Mathf.Abs(camera.transform.position.z - targetZ);
            Vector3 worldPosition = camera.ScreenToWorldPoint(new Vector3(screenPosition.x, screenPosition.y, distance));
            worldPosition.z = targetZ;
            return worldPosition;
        }

        /// <summary>
        /// 尝试获取鼠标按下的屏幕坐标。
        /// </summary>
        private static bool TryGetMouseDownPosition(out Vector2 screenPosition)
        {
#if ENABLE_INPUT_SYSTEM
            Mouse mouse = Mouse.current;
            if (mouse != null && mouse.leftButton.wasPressedThisFrame)
            {
                screenPosition = mouse.position.ReadValue();
                return true;
            }
#endif
#if ENABLE_LEGACY_INPUT_MANAGER
            if (Input.GetMouseButtonDown(0))
            {
                screenPosition = Input.mousePosition;
                return true;
            }
#endif
            screenPosition = default;
            return false;
        }

        /// <summary>
        /// 尝试获取鼠标持续按住的屏幕坐标。
        /// </summary>
        private static bool TryGetMouseHeldPosition(out Vector2 screenPosition)
        {
#if ENABLE_INPUT_SYSTEM
            Mouse mouse = Mouse.current;
            if (mouse != null && mouse.leftButton.isPressed)
            {
                screenPosition = mouse.position.ReadValue();
                return true;
            }
#endif
#if ENABLE_LEGACY_INPUT_MANAGER
            if (Input.GetMouseButton(0))
            {
                screenPosition = Input.mousePosition;
                return true;
            }
#endif
            screenPosition = default;
            return false;
        }

        /// <summary>
        /// 尝试获取指定触控 ID 的屏幕坐标和按下状态。
        /// </summary>
        private static bool TryGetTouchPosition(int touchId, out Vector2 screenPosition, out bool isPressed)
        {
#if ENABLE_INPUT_SYSTEM
            Touchscreen touchscreen = Touchscreen.current;
            if (touchscreen != null)
            {
                var touches = touchscreen.touches;
                for (int i = 0; i < touches.Count; i++)
                {
                    var touch = touches[i];
                    if (touch.touchId.ReadValue() != touchId)
                    {
                        continue;
                    }

                    screenPosition = touch.position.ReadValue();
                    isPressed = touch.press.isPressed;
                    return true;
                }
            }
#endif
#if ENABLE_LEGACY_INPUT_MANAGER
            int touchCount = Input.touchCount;
            for (int i = 0; i < touchCount; i++)
            {
                Touch touch = Input.GetTouch(i);
                if (touch.fingerId != touchId)
                {
                    continue;
                }

                screenPosition = touch.position;
                isPressed = touch.phase != TouchPhase.Ended && touch.phase != TouchPhase.Canceled;
                return true;
            }
#endif
            screenPosition = default;
            isPressed = false;
            return false;
        }

        /// <summary>
        /// 重置拖拽指针状态。
        /// </summary>
        private void ResetPointerState()
        {
            _activePointerType = ActivePointerType.None;
            _activeTouchId = -1;
            _dragOffset = Vector3.zero;
        }
    }
}
