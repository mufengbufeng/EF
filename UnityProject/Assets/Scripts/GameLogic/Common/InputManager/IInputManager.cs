using UnityEngine;

namespace GameLogic
{
    public interface IInputManager
    {
        InputType InputType { get; }
        InputSystem_Actions InputAsset { get; }

        Vector2 MovementValue { get; }

        JoystickBehavior Joystick { get; }


    }

    public enum InputType
    {
        UIJoystick = 1, // 虚拟摇杆
        Keyboard = 2,// 键盘
        Gamepad = 4, // 手柄
    }
}
