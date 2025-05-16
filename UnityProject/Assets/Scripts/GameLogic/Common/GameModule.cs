using Cysharp.Threading.Tasks;
using GameProto;
using EF;
using JetBrains.Annotations;
using UnityEngine;
using UnityEngine.PlayerLoop;
using System.CodeDom;


namespace GameLogic
{
    public static class GameModule
    {
        public static ResourceModule Resource;
        public static EventModule Event;
        public static UIManager UI;
        public static SceneModule Scene;
        public static void Run()
        {
            Init();
        }

        public static void Init()
        {
            Resource = ResourceModule.Instance;
            Event = EventModule.Instance;
            UI = UIManager.Instance;
            Scene = SceneModule.Instance;
            Start();
        }

        public static void Start()
        {
            GameModule.Event.Add(1, (obj) =>
            {
                NULL.TestLog("1111");
            });

            Resource.LoadGameObjectAsync("Cube").Forget();
            var testView = UI.OpenUI<TestView>("TestView", UILayer.Normal, 0, 1);

            var sceneobj = Scene.LoadScene("TestScene");

            NULL.TestLog("2222");

            GameModule.Event.Trigger(1);
        }


    }
}
