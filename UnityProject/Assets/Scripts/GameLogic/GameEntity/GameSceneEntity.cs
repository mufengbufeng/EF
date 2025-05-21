using Cinemachine;
using Cysharp.Threading.Tasks;
using EF;
using UnityEditor.Playables;
using UnityEngine;

// 暂时把ChapterEntity 逻辑写到此脚本，因为感觉逻辑太少
namespace GameLogic
{
    public enum GameState
    {
        Home,
        Game,
    }

    public class GameSceneEntity : MonoBehaviour
    {
        public CinemachineVirtualCamera GameCamera;
        public GameObject StartPoint;
        public GameState GameState;
        public GameObject LevelObj;
        public GameObject Fruit;
        public BoxColliderCornersCollector Plane;
        public void Awake()
        {
            var uHub = transform.GetOrAddComponent<UHubComponent>();
            uHub.BindUI(this, gameObject);
            GameModule.Event.Add(EventDefine.StartGame, OnStartGame);
        }

        private void OnStartGame(object[] data)
        {
            Init(GameState.Game).Forget();
        }

        public async UniTaskVoid Init(GameState gameState)
        {

            if (gameState == GameState.Home)
            {
                InitHome().Forget();
            }
            else if (gameState == GameState.Game)
            {
                InitGame();
            }
        }

        private async UniTaskVoid InitHome()
        {
            var player = await GameModule.Resource.LoadGameObjectAsync("Player");
            GameCamera.Follow = player.transform;
            GameCamera.LookAt = player.transform;
            var chapter = GameModel.Instance.Chapter;
            var chapterEx = GameModule.Data.ChapterConfig.GetOrDefault(chapter);
            if (chapterEx == null)
            {
                Log.Error($"未找到关卡,ID: {chapter}");
                return;
            }
            // 设置摄像头
            string levelPrefabName = chapterEx.Prefab;
            LevelObj = await GameModule.Resource.LoadGameObjectAsync(levelPrefabName);

            var levelObjRf = LevelObj.GetComponent<ReferenceCollector>();
            StartPoint = levelObjRf.Get<GameObject>("StartPoint");
            Fruit = levelObjRf.Get<GameObject>("Fruit");
            Plane = levelObjRf.Get<BoxColliderCornersCollector>("Plane");
            Fruit.SetActive(false);
            player.transform.position = StartPoint.transform.position;
        }

        private void InitGame()
        {
            Fruit.SetActive(true);
            GameModule.UI.CloseUI("MainView");
            GameModule.UI.OpenUIAsync<GameView>("GameView", UILayer.Normal).Forget();   // 打开UI
            var levelObjRf = LevelObj.GetComponent<ReferenceCollector>();
            var AllBoxColliderCorners = Plane.GetAllBoxColliderCorners();
            GamePlayModel.Instance.SetAllBoxColliderCorners(AllBoxColliderCorners);
        }
    }
}