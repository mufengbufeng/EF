using Cysharp.Threading.Tasks;
using EF;
using UnityEngine.SceneManagement;


namespace GameLogic
{
    public static class GameModule
    {
        public static ResourceModule Resource;
        public static EventModule Event;
        public static UIManager UI;
        public static FSMManager FSM;
        public static SceneModule Scene;
        public static GameConfig.Tables Data;

        public static void Run()
        {
            Init();
        }

        public static void Init()
        {
            FSM = FSMManager.Instance;
            Resource = ResourceModule.Instance;
            Event = EventModule.Instance;
            UI = UIManager.Instance;
            Scene = SceneModule.Instance;
            Data = ConfigSystem.Instance.Tables;

            Start();
        }
        public static void Start()
        {
            GameModel.Instance.InitGame();
            // GamePlayController.Instance.StartGame();
            StartGameCommon().Forget();
        }

        public static async UniTaskVoid StartGameCommon()
        {
            Scene scene = await GameModule.Scene.LoadSceneAsync("Game");
            UI.OpenUI<MainView>("MainView", UILayer.Normal);
            UnityEngine.GameObject[] objs = scene.GetRootGameObjects();
            GameSceneEntity entity = null;
            foreach (var obj in objs)
            {
                if (obj.name == "Root")
                {
                    entity = obj.AddComponent<GameSceneEntity>();
                }
            }
            entity.Init(GameState.Home).Forget();
        }


    }
}
