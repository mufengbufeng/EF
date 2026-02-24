using System;
using EF.Debugger;
using EF.Model;

namespace GameLogic
{
    /// <summary>
    /// 玩法只读模型接口。
    /// </summary>
    public interface IGamePlayModelData
    {
        /// <summary>
        /// 当前积分。
        /// </summary>
        int CurrentScore { get; }
    }

    /// <summary>
    /// 玩法模型。
    /// 本次仅提供积分的读写入口，供 UI 展示使用。
    /// </summary>
    public class GamePlayModel : ModelBase<IGamePlayModelData>
    {
        private readonly ModelValue<int> _currentScore;

        /// <summary>
        /// 当前积分。
        /// </summary>
        public int CurrentScore => GetValue(_currentScore);

        public GamePlayModel()
        {
            _currentScore = CreateValue(0);
        }

        protected override IGamePlayModelData CreateData()
        {
            return new GamePlayModelData(this);
        }

        protected override void OnModelInitialized()
        {
            base.OnModelInitialized();
            SetValue(_currentScore, 0, nameof(CurrentScore));
            Log.Info("[GamePlayModel] 玩法模型初始化完成，积分已重置为 0");
        }

        /// <summary>
        /// 重置积分。
        /// </summary>
        public void ResetScore()
        {
            SetScore(0);
        }

        /// <summary>
        /// 设置积分。
        /// </summary>
        /// <param name="score">积分值。</param>
        public void SetScore(int score)
        {
            int safeScore = score < 0 ? 0 : score;
            SetValue(_currentScore, safeScore, nameof(CurrentScore));
        }

        /// <summary>
        /// 增加积分。
        /// </summary>
        /// <param name="delta">增量，负数将被忽略。</param>
        public void AddScore(int delta)
        {
            if (delta <= 0)
            {
                Log.Warning($"[GamePlayModel] AddScore 收到非正增量 {delta}，已忽略");
                return;
            }

            SetScore(CurrentScore + delta);
        }

        protected override void OnModelReleased()
        {
            SetValue(_currentScore, 0, nameof(CurrentScore));
            Log.Info("[GamePlayModel] 释放游戏玩法模型资源");
            base.OnModelReleased();
        }

        private sealed class GamePlayModelData : IGamePlayModelData
        {
            private readonly GamePlayModel _model;

            public GamePlayModelData(GamePlayModel model)
            {
                _model = model ?? throw new ArgumentNullException(nameof(model));
            }

            public int CurrentScore => _model.CurrentScore;
        }
    }
}
