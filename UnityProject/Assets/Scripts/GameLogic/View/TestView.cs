using EF;
using UnityEngine.UI;

namespace GameLogic
{
    public class TestView : BaseUIView
    {
        public Image Image;
        public UHubComponent UHub;
        protected override void InitView(params object[] data)
        {
            Log.Info($"0:{data[0]}, 1:{data[1]}");
            UHub = root.transform.GetOrAddComponent<UHubComponent>();
            UHub.BindUI(this, root);
        }

        public override void ShowView()
        {
            base.ShowView();
            Image.sprite = GameModule.Resource.LoadSprite("Atlas_Common", "Common_001");
        }
    }

}