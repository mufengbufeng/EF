// ---------------------
// 负责存储游戏中角色外围数据
// ---------------------
using Cysharp.Threading.Tasks;
using EF;
using UnityEngine.SceneManagement;

namespace GameLogic
{
    public class GameModel : BaseModel<GameModel>
    {
        public int Chapter { get; private set; }
        // public Scene Scene { get; private set; }

        public void InitGame()
        {
            // TODO: 尝试读取数据 如果有缓存数据，回复缓存数据
            bool hasCache = true;
            if (hasCache)
            {
                // TODO: 读取缓存数据
                Chapter = 1;
            }
            else
            {
                Chapter = 1;
            }
        }

      
    }
}