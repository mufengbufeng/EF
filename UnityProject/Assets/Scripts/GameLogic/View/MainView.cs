
using EF;
using UnityEngine.UI;
namespace GameLogic
{
    public class MainView : BaseView
    {
        public UHubComponent UHub;
        public Button StartGameBtn;
        protected override void InitView(params object[] data)
        {
            UHub = root.transform.GetOrAddComponent<UHubComponent>();
            UHub.BindUI(this, root);
            UHub.BindClick(StartGameBtn, OnStartGameBtnClick);
        }

        public void OnStartGameBtnClick()
        {
            GameModule.Event.Trigger(EventDefine.StartGame);
        }


    }
}