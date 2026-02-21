using System;
using EF.Common;
using EF.Debugger;
using EF.Entity;
using UnityEngine;
#if ENABLE_INPUT_SYSTEM
using UnityEngine.InputSystem;
#endif

namespace GameLogic
{
    /// <summary>
    /// 玩家飞机实体。
    /// 负责拖拽输入、自动攻击与动画状态控制。
    /// </summary>
    public sealed class PlayerAvatarEntity : EntityBase, IHealth
    {
        private enum ActivePointerType
        {
            None,
            Mouse,
            Touch
        }

        private const string MoveAnimationState = "Move";
        private const string BoomAnimationState = "Boom";

        private GameObject _handleField;
        private IBulletModule _bulletModule;
        private IEntityManager _entityManager;
        private Animator _animator;
        private SpriteRenderer _spriteRenderer;
        private Collider2D _collider2D;

        private ActivePointerType _activePointerType;
        private int _activeTouchId;
        private Vector3 _dragOffset;
        private float _attackInterval;
        private float _attackTimer;
        private float _bulletSpeed;
        private float _dragBoundaryPadding;
        private float _fixedZ;
        private Camera _mainCamera;
        private bool _cameraWarningLogged;
        private bool _bulletWarningLogged;
        private int _lifecycleToken;

        // 生命值系统
        private float _currentHealth;
        private float _maxHealth;
        private bool _isDead;

        /// <summary>
        /// 当前生命值。
        /// </summary>
        public float CurrentHealth => _currentHealth;

        /// <summary>
        /// 最大生命值。
        /// </summary>
        public float MaxHealth => _maxHealth;

        /// <summary>
        /// 是否已死亡。
        /// </summary>
        public bool IsDead => _isDead;

        // 技能系统可通过该入口接管攻击；返回 true 表示已处理，不再执行默认攻击。
        private Func<Vector3, bool> _customAttackExecutor;

        /// <summary>
        /// 实体关联的 GameObject。
        /// </summary>
        public override GameObject Handle
        {
            get => _handleField;
            set => _handleField = value;
        }

        /// <summary>
        /// 设置自定义攻击执行器。
        /// </summary>
        /// <param name="attackExecutor">自定义攻击逻辑。</param>
        public void SetCustomAttackExecutor(Func<Vector3, bool> attackExecutor)
        {
            _customAttackExecutor = attackExecutor;
        }

        /// <summary>
        /// 播放爆炸动画。
        /// </summary>
        public void PlayBoomAnimation()
        {
            if (_animator != null)
            {
                _animator.Play(BoomAnimationState);
            }
        }

        /// <summary>
        /// 接受伤害。
        /// </summary>
        /// <param name="damage">伤害值。</param>
        public void TakeDamage(float damage)
        {
            if (_isDead)
            {
                return;
            }

            _currentHealth -= damage;
            Log.Info($"[PlayerAvatarEntity] 实体 {Id} 受到伤害 {damage}，当前生命值: {_currentHealth}/{_maxHealth}");

            if (_currentHealth <= 0)
            {
                _isDead = true;
                _currentHealth = 0;
                Log.Info($"[PlayerAvatarEntity] 实体 {Id} 已死亡");

                // 禁用碰撞器避免重复击中
                if (_collider2D != null)
                {
                    _collider2D.enabled = false;
                }

                ResetPointerState();
                ClearOwnedBullets();

                // 播放死亡动画
                PlayBoomAnimation();

                // 延迟隐藏实体(等待动画播放)
                DelayedHide(1.0f, _lifecycleToken, Id);
            }
        }

        /// <summary>
        /// 延迟隐藏实体。
        /// </summary>
        private async void DelayedHide(float delay, int expectedToken, int expectedEntityId)
        {
            await Cysharp.Threading.Tasks.UniTask.Delay(System.TimeSpan.FromSeconds(delay));

            if (expectedToken != _lifecycleToken || !_isDead || Id != expectedEntityId)
            {
                return;
            }

            if (Handle != null && _entityManager != null)
            {
                _entityManager.HideEntity(expectedEntityId);
                Log.Info($"[PlayerAvatarEntity] 实体 {expectedEntityId} 已隐藏");
            }
        }

        /// <summary>
        /// 实体初始化。
        /// </summary>
        public override void OnInit(int entityId, string entityAssetName, IEntityGroup entityGroup, bool isNewInstance, object userData)
        {
            base.OnInit(entityId, entityAssetName, entityGroup, isNewInstance, userData);
            ResetRuntimeState();
        }

        /// <summary>
        /// 实体显示。
        /// </summary>
        public override void OnShow(object userData)
        {
            base.OnShow(userData);

            if (Handle == null)
            {
                Log.Warning($"[PlayerAvatarEntity] 实体 {Id} Handle 为空，无法显示");
                return;
            }

            if (!ModuleSystem.TryGet<IBulletModule>(out _bulletModule))
            {
                _bulletModule = null;
            }

            if (!ModuleSystem.TryGet<IEntityManager>(out _entityManager))
            {
                _entityManager = null;
            }

            Handle.SetActive(true);

            _animator = Handle.GetComponent<Animator>();
            _spriteRenderer = Handle.GetComponent<SpriteRenderer>();
            _collider2D = Handle.GetComponent<Collider2D>();
            _mainCamera = Camera.main;
            _cameraWarningLogged = false;
            _bulletWarningLogged = false;

            if (_collider2D == null)
            {
                // 资源缺失碰撞组件时自动补最小命中组件，保证点击命中稳定。
                _collider2D = Handle.AddComponent<BoxCollider2D>();
                Log.Warning("[PlayerAvatarEntity] Avatar 缺少 Collider2D，已自动补充 BoxCollider2D 用于命中检测");
            }

            if (_collider2D != null)
            {
                _collider2D.enabled = true;
            }

            if (userData is PlayerAvatarBehaviorData behaviorData)
            {
                Handle.transform.position = behaviorData.SpawnPosition;
                _fixedZ = behaviorData.SpawnPosition.z;
                _attackInterval = behaviorData.AttackInterval;
                _bulletSpeed = behaviorData.BulletSpeed;
                _dragBoundaryPadding = Mathf.Max(0f, behaviorData.DragBoundaryPadding);
                
                // 初始化生命值
                _maxHealth = 100f;
                _currentHealth = _maxHealth;
                _isDead = false;
            }
            else
            {
                Vector3 currentPosition = Handle.transform.position;
                _fixedZ = currentPosition.z;
                _attackInterval = 0.2f;
                _bulletSpeed = 8f;
                _dragBoundaryPadding = 0.25f;
                
                // 初始化生命值
                _maxHealth = 100f;
                _currentHealth = _maxHealth;
                _isDead = false;
                
                Log.Warning($"[PlayerAvatarEntity] 实体 {Id} 未接收到行为数据，使用默认参数");
            }

            _attackTimer = 0f;
            ResetPointerState();
            PlayMoveAnimation();
            ClampCurrentPosition();
        }

        /// <summary>
        /// 每帧更新。
        /// </summary>
        public override void OnUpdate(float elapseSeconds, float realElapseSeconds)
        {
            base.OnUpdate(elapseSeconds, realElapseSeconds);

            if (Handle == null)
            {
                return;
            }

            if (_isDead)
            {
                return;
            }

            UpdateDragInput();
            ClampCurrentPosition();
            UpdateAttack(elapseSeconds);
        }

        /// <summary>
        /// 实体隐藏。
        /// </summary>
        public override void OnHide(bool isShutdown, object userData)
        {
            base.OnHide(isShutdown, userData);

            if (Handle != null)
            {
                Handle.SetActive(false);
            }

            ResetRuntimeState();
        }

        /// <summary>
        /// 实体回收。
        /// </summary>
        public override void OnRecycle()
        {
            base.OnRecycle();
            ResetRuntimeState();
        }

        private void UpdateDragInput()
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
                UpdateMouseDrag(camera);
                return;
            }

            UpdateTouchDrag(camera);
        }

        private bool TryBeginTouchDrag(Camera camera)
        {
            // 同一帧可能有多个触点开始，必须逐个命中检测，避免漏掉后续有效触点。
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
                    _dragOffset = Handle.transform.position - touchWorldPosition;
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
                _dragOffset = Handle.transform.position - touchWorldPosition;
                return true;
            }
#endif
            return false;
        }

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
            _dragOffset = Handle.transform.position - mouseWorldPosition;
        }

        private void UpdateMouseDrag(Camera camera)
        {
            if (!TryGetMouseHeldPosition(out Vector2 mouseScreenPosition))
            {
                ResetPointerState();
                return;
            }

            Vector3 mouseWorldPosition = ScreenToWorld(camera, mouseScreenPosition, _fixedZ);
            Vector3 targetPosition = mouseWorldPosition + _dragOffset;
            SetClampedPosition(camera, targetPosition);
        }

        private void UpdateTouchDrag(Camera camera)
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
            Vector3 targetPosition = touchWorldPosition + _dragOffset;
            SetClampedPosition(camera, targetPosition);
        }

        private void UpdateAttack(float elapseSeconds)
        {
            if (_attackInterval <= 0f)
            {
                return;
            }

            _attackTimer += elapseSeconds;
            if (_attackTimer < _attackInterval)
            {
                return;
            }

            _attackTimer = 0f;
            ExecuteAttack();
        }

        private void ExecuteAttack()
        {
            if (Handle == null)
            {
                return;
            }

            if (_customAttackExecutor != null)
            {
                try
                {
                    if (_customAttackExecutor.Invoke(Handle.transform.position))
                    {
                        return;
                    }
                }
                catch (Exception e)
                {
                    Log.Error($"[PlayerAvatarEntity] 自定义攻击执行器异常: {e.Message}");
                }
            }

            FireDefaultBullet();
        }

        private void FireDefaultBullet()
        {
            if (_bulletModule == null && !ModuleSystem.TryGet<IBulletModule>(out _bulletModule))
            {
                if (!_bulletWarningLogged)
                {
                    _bulletWarningLogged = true;
                    Log.Warning($"[PlayerAvatarEntity] 实体 {Id} 无法获取 IBulletModule，跳过默认攻击");
                }
                return;
            }

            _bulletWarningLogged = false;
            var bulletData = new BulletData
            {
                SpawnPosition = Handle.transform.position,
                Direction = Vector3.up,
                Speed = _bulletSpeed,
                OwnerType = BulletOwnerType.Player,
                Damage = 10f,
                SourceEntityId = Id
            };
            _bulletModule.Fire(bulletData);
        }

        private void ClearOwnedBullets()
        {
            if (_bulletModule == null && !ModuleSystem.TryGet<IBulletModule>(out _bulletModule))
            {
                return;
            }

            _bulletModule.ClearBulletsBySource(Id);
        }

        private void PlayMoveAnimation()
        {
            if (_animator != null)
            {
                _animator.Play(MoveAnimationState);
            }
        }

        private void ClampCurrentPosition()
        {
            if (Handle == null)
            {
                return;
            }

            Camera camera = GetMainCamera();
            if (camera == null)
            {
                return;
            }

            SetClampedPosition(camera, Handle.transform.position);
        }

        private void SetClampedPosition(Camera camera, Vector3 targetPosition)
        {
            Vector3 clampedPosition = ClampToCameraBounds(camera, targetPosition);
            Handle.transform.position = clampedPosition;
        }

        private Vector3 ClampToCameraBounds(Camera camera, Vector3 targetPosition)
        {
            if (camera.orthographic)
            {
                float halfHeight = camera.orthographicSize;
                float halfWidth = halfHeight * camera.aspect;
                float minX = camera.transform.position.x - halfWidth + _dragBoundaryPadding;
                float maxX = camera.transform.position.x + halfWidth - _dragBoundaryPadding;
                float minY = camera.transform.position.y - halfHeight + _dragBoundaryPadding;
                float maxY = camera.transform.position.y + halfHeight - _dragBoundaryPadding;

                if (minX > maxX)
                {
                    minX = maxX = camera.transform.position.x;
                }

                if (minY > maxY)
                {
                    minY = maxY = camera.transform.position.y;
                }

                targetPosition.x = Mathf.Clamp(targetPosition.x, minX, maxX);
                targetPosition.y = Mathf.Clamp(targetPosition.y, minY, maxY);
                targetPosition.z = _fixedZ;
                return targetPosition;
            }

            float zDistance = Mathf.Abs(camera.transform.position.z - _fixedZ);
            Vector3 viewport = camera.WorldToViewportPoint(targetPosition);
            viewport.x = Mathf.Clamp01(viewport.x);
            viewport.y = Mathf.Clamp01(viewport.y);
            Vector3 world = camera.ViewportToWorldPoint(new Vector3(viewport.x, viewport.y, zDistance));
            world.z = _fixedZ;
            return world;
        }

        private bool IsPointerOnAvatar(Vector3 pointerWorldPosition)
        {
            if (_collider2D != null)
            {
                return _collider2D.OverlapPoint(pointerWorldPosition);
            }

            if (_spriteRenderer != null)
            {
                return _spriteRenderer.bounds.Contains(pointerWorldPosition);
            }

            return Vector3.SqrMagnitude(Handle.transform.position - pointerWorldPosition) <= 0.64f;
        }

        private Camera GetMainCamera()
        {
            if (_mainCamera == null)
            {
                _mainCamera = Camera.main;
            }

            if (_mainCamera == null && !_cameraWarningLogged)
            {
                _cameraWarningLogged = true;
                Log.Warning($"[PlayerAvatarEntity] 实体 {Id} 未找到主摄像机，拖拽输入暂不可用");
            }

            return _mainCamera;
        }

        private static Vector3 ScreenToWorld(Camera camera, Vector2 screenPosition, float targetZ)
        {
            float distance = Mathf.Abs(camera.transform.position.z - targetZ);
            Vector3 worldPosition = camera.ScreenToWorldPoint(new Vector3(screenPosition.x, screenPosition.y, distance));
            worldPosition.z = targetZ;
            return worldPosition;
        }

        private bool TryGetMouseDownPosition(out Vector2 screenPosition)
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

        private bool TryGetMouseHeldPosition(out Vector2 screenPosition)
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

        private bool TryGetTouchPosition(int touchId, out Vector2 screenPosition, out bool isPressed)
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

        private void ResetPointerState()
        {
            _activePointerType = ActivePointerType.None;
            _activeTouchId = -1;
            _dragOffset = Vector3.zero;
        }

        private void ResetRuntimeState()
        {
            ResetPointerState();
            _attackInterval = 0f;
            _attackTimer = 0f;
            _bulletSpeed = 0f;
            _dragBoundaryPadding = 0f;
            _fixedZ = 0f;
            _bulletModule = null;
            _animator = null;
            _spriteRenderer = null;
            _collider2D = null;
            _mainCamera = null;
            _cameraWarningLogged = false;
            _bulletWarningLogged = false;
            _entityManager = null;
            _customAttackExecutor = null;
            _currentHealth = 0f;
            _maxHealth = 0f;
            _isDead = false;
            _lifecycleToken++;
        }
    }
}
