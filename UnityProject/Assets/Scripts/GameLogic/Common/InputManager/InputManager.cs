using System; // System.* using 指令放在最前面
using UnityEngine;
using EF;
using UnityEngine.InputSystem;

namespace GameLogic
{
    /// <summary>
    /// 管理来自键盘、游戏手柄和 UI 摇杆的玩家输入。
    /// 提供统一的移动输入访问，并检测当前的输入类型。
    /// </summary>
    public class InputManager : BehaviourSingleton<InputManager>, IInputManager
    {
        private InputSystem_Actions _inputActions;
        private InputDevice _lastUsedDevice; // 最后使用的设备
        protected new bool _dontDestroyOnLoad = false;

        #region IInputManager 属性

        /// <summary>
        /// 获取生成的 Input Actions 资源。
        /// </summary>
        public InputSystem_Actions InputAsset => _inputActions;

        [SerializeField]
        private Vector2 _movementValue = Vector2.zero;
        /// <summary>
        /// 获取当前归一化的移动输入值（Vector2，分量范围从 -1 到 1）。
        /// </summary>
        public Vector2 MovementValue => _movementValue;

        /// <summary>
        /// 获取当前活动的输入类型（键盘、游戏手柄或 UI 摇杆）。
        /// 默认为键盘。UI 摇杆通过 NotifyJoystickUsed() 设置。
        /// </summary>
        public InputType InputType { get; private set; } = InputType.Keyboard;

        /// <summary>
        /// 获取 Joystick 行为实例。此版本未实现。
        /// </summary>
        public JoystickBehavior Joystick => null; // 根据要求，尚未实现。

        #endregion

        #region Unity 生命周期方法

        protected override void Awake() //
        {
            // SingletonBehaviour 的 Awake 可能处理实例设置和 DontDestroyOnLoad。
            // 移除了 base.Awake() 调用，因为它可能是 protected 或处理自己的逻辑。

            _inputActions = new InputSystem_Actions();
            _inputActions.Player.Enable(); // 启用 Player 操作映射

            // 注册移动输入事件
            _inputActions.Player.Move.performed += OnMovePerformed;
            _inputActions.Player.Move.canceled += OnMoveCanceled;

            // 注册以检测设备更改
            InputSystem.onActionChange += OnActionChange;

            // 如果有可用设备，则使用第一个连接的设备进行初始化
            // 这有助于在启动时连接了游戏手柄的情况下设置初始状态
            if (Gamepad.current != null)
            {
                _lastUsedDevice = Gamepad.current;
                InputType = InputType.Gamepad; // 将 CurrentInputType 更改为 InputType
            }
            else if (Keyboard.current != null)
            {
                _lastUsedDevice = Keyboard.current;
                InputType = InputType.Keyboard; // 将 CurrentInputType 更改为 InputType
            }
        }

        protected override void OnDestroy()
        {
            // 取消注册事件并释放 Input Actions 资源
            if (_inputActions != null)
            {
                _inputActions.Player.Move.performed -= OnMovePerformed;
                _inputActions.Player.Move.canceled -= OnMoveCanceled;
                _inputActions.Player.Disable(); // 禁用操作映射
                _inputActions.Dispose(); // 释放资源本身
                _inputActions = null;
            }

            InputSystem.onActionChange -= OnActionChange;

            // 如果 SingletonBehaviour 需要，确保调用基类的 OnDestroy。
            base.OnDestroy();
        }

        #endregion

        #region 输入事件处理程序

        private void OnMovePerformed(InputAction.CallbackContext context)
        {
            // Log.Info($"移动输入: {context.ReadValue<Vector2>()}");
            // 读取移动输入的 Vector2 值
            _movementValue = context.ReadValue<Vector2>();
        }

        private void OnMoveCanceled(InputAction.CallbackContext context)
        {
            // 输入取消时，将移动值重置为零向量
            // Log.Info("归零");
            _movementValue = Vector2.zero;
        }

        private void OnActionChange(object obj, InputActionChange change)
        {
            // 我们关心的是动作执行时 (ActionPerformed)，
            // 因为这表明设备正在被主动使用。
            // 移除了对 InteractionStarted 的检查，因为它不在枚举中
            if (change != InputActionChange.ActionPerformed)
            {
                return;
            }

            // 检查对象是否为 InputAction
            if (obj is not InputAction action)
            {
                return;
            }

            // 获取触发动作的设备
            var currentDevice = action.activeControl?.device;

            // 如果找到了设备，并且它与上次使用的设备不同
            if (currentDevice != null && currentDevice != _lastUsedDevice)
            {
                _lastUsedDevice = currentDevice;

                // 根据设备类型更新 InputType，
                // 但前提是 UI 摇杆不是明确设置的类型。
                // 这允许键盘/游戏手柄从默认状态接管，但不能从活动的摇杆接管。
                if (InputType != InputType.UIJoystick) // 将 CurrentInputType 更改为 InputType
                {
                    if (_lastUsedDevice is Keyboard)
                    {
                        InputType = InputType.Keyboard; // 将 CurrentInputType 更改为 InputType
                        // Debug.Log("输入类型更改：键盘");
                    }
                    else if (_lastUsedDevice is Gamepad)
                    {
                        InputType = InputType.Gamepad; // 将 CurrentInputType 更改为 InputType
                        // Debug.Log("输入类型更改：游戏手柄");
                    }
                    // 如果需要，添加对其他设备类型的检查
                }
            }
        }

        #endregion

        #region 公共方法

        /// <summary>
        /// 当 UI 摇杆被主动使用时，应从外部（例如，由 JoystickBehavior）调用此方法。
        /// 将 InputType 设置为 UIJoystick。
        /// </summary>
        public void NotifyJoystickUsed()
        {
            if (InputType != InputType.UIJoystick) // 将 CurrentInputType 更改为 InputType
            {
                // Debug.Log("输入类型更改：UI 摇杆");
                InputType = InputType.UIJoystick; // 将 CurrentInputType 更改为 InputType
                // 清除最后使用的设备，以便在释放摇杆后，
                // 下一次键盘/游戏手柄输入可以正确地切换回状态。
                _lastUsedDevice = null;
            }
        }

        public void SetJoystickValue(Vector2 v2)
        {
            // Log.Info($"Inoupt Manager ID: ${this.GetInstanceID()}");
            _movementValue = v2;
            // Log.Info(_movementValue.ToString());

        }

        #endregion
    }
}
