using EF;

namespace GameLogic
{
    public class GameView : BaseView
    {
        public JoystickBehavior Joystick;
        protected override void InitView(params object[] data)
        {
            root.transform.GetOrAddComponent<UHubComponent>();
        }


    }
}