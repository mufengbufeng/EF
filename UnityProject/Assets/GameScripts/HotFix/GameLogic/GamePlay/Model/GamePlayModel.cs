using System;
using System.Collections.Generic;
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

        /// <summary>
        /// 当前关卡ID。
        /// </summary>
        int CurrentLevelId { get; }

        /// <summary>
        /// 当前关卡进度。
        /// </summary>
        int CurrentLevelProgress { get; }

        /// <summary>
        /// 当前关卡星级。
        /// </summary>
        int CurrentLevelStars { get; }
    }

    /// <summary>
    /// 玩法模型。
    /// 本次仅提供积分的读写入口，供 UI 展示使用。
    /// </summary>
    public class GamePlayModel : ModelBase<IGamePlayModelData>
    {
        private readonly ModelValue<int> _currentScore;
        private readonly ModelValue<int> _currentLevelId;
        private readonly ModelValue<int> _currentLevelProgress;
        private readonly ModelValue<int> _currentLevelStars;

        /// <summary>
        /// 当前积分。
        /// </summary>
        public int CurrentScore => GetValue(_currentScore);

        /// <summary>
        /// 当前关卡ID。
        /// </summary>
        public int CurrentLevelId => GetValue(_currentLevelId);

        /// <summary>
        /// 当前关卡进度。
        /// </summary>
        public int CurrentLevelProgress => GetValue(_currentLevelProgress);

        /// <summary>
        /// 当前关卡星级。
        /// </summary>
        public int CurrentLevelStars => GetValue(_currentLevelStars);

        public GamePlayModel()
        {
            _currentScore = CreateValue(0);
            _currentLevelId = CreateValue(0);
            _currentLevelProgress = CreateValue(0);
            _currentLevelStars = CreateValue(0);
        }

        protected override IGamePlayModelData CreateData()
        {
            return new GamePlayModelData(this);
        }

        protected override void OnModelInitialized()
        {
            base.OnModelInitialized();
            SetValue(_currentScore, 0, nameof(CurrentScore));
            SetValue(_currentLevelId, 0, nameof(CurrentLevelId));
            SetValue(_currentLevelProgress, 0, nameof(CurrentLevelProgress));
            SetValue(_currentLevelStars, 0, nameof(CurrentLevelStars));
            Log.Info("[GamePlayModel] 玩法模型初始化完成");
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

        /// <summary>
        /// 设置当前关卡ID。
        /// </summary>
        /// <param name="levelId">关卡ID。</param>
        public void SetCurrentLevel(int levelId)
        {
            SetValue(_currentLevelId, levelId, nameof(CurrentLevelId));
            SetValue(_currentLevelStars, 0, nameof(CurrentLevelStars));
        }

        /// <summary>
        /// 设置当前关卡进度。
        /// </summary>
        /// <param name="progress">进度值。</param>
        public void SetLevelProgress(int progress)
        {
            int safeProgress = progress < 0 ? 0 : progress;
            SetValue(_currentLevelProgress, safeProgress, nameof(CurrentLevelProgress));
        }

        /// <summary>
        /// 增加关卡进度。
        /// </summary>
        /// <param name="delta">增量。</param>
        public void AddLevelProgress(int delta)
        {
            if (delta <= 0)
            {
                return;
            }
            SetLevelProgress(CurrentLevelProgress + delta);
        }

        /// <summary>
        /// 设置关卡星级。
        /// </summary>
        /// <param name="stars">星级（1-3）。</param>
        public void SetLevelStars(int stars)
        {
            int safeStars = Math.Clamp(stars, 0, 3);
            SetValue(_currentLevelStars, safeStars, nameof(CurrentLevelStars));
        }

        /// <summary>
        /// 重置关卡数据。
        /// </summary>
        public void ResetLevelData()
        {
            SetValue(_currentLevelId, 0, nameof(CurrentLevelId));
            SetValue(_currentLevelProgress, 0, nameof(CurrentLevelProgress));
            SetValue(_currentLevelStars, 0, nameof(CurrentLevelStars));
        }

        protected override void OnModelReleased()
        {
            SetValue(_currentScore, 0, nameof(CurrentScore));
            ResetLevelData();
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
            public int CurrentLevelId => _model.CurrentLevelId;
            public int CurrentLevelProgress => _model.CurrentLevelProgress;
            public int CurrentLevelStars => _model.CurrentLevelStars;
        }
    }
}
