
using System;
using Cysharp.Threading.Tasks;
using EF.Debugger;
using EF.Model;

namespace GameLogic
{
    public interface IGamePlayModelData
    {
        
    }



    public class GamePlayModel : ModelBase<IGamePlayModelData>
    {
        protected override IGamePlayModelData CreateData()
        {
            return new GamePlayModelData(this);
        }

        protected override void OnModelInitialized()
        {
            base.OnModelInitialized();
        }

        /// <summary>
        /// 开始游戏
        /// </summary>
        public async void StartGame()
        {
            Log.Info("[GamePlayModel] 游戏开始逻辑处理");

            // 通过 GameLogicEntry 访问 GameSceneManager 进入游戏玩法场景
            // await GameLogicEntry.GameScene.EnterGamePlaySceneAsync();
        }

        protected override void OnModelReleased()
        {
            Log.Info("[GamePlayModel] 释放游戏玩法模型资源");
            base.OnModelReleased();
        }

        private class GamePlayModelData : IGamePlayModelData
        {
            private readonly GamePlayModel _model;

            public GamePlayModelData(GamePlayModel model)
            {
                _model = model ?? throw new ArgumentNullException(nameof(model));
            }

        }

    }


}