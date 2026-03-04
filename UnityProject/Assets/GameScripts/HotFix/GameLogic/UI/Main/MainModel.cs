using System;
using EF.Model;

namespace GameLogic
{

    /// <summary>
    /// 主界面模型只读数据接口
    /// </summary>
    public interface IMainModelData
    {
        /// <summary>
        /// 游戏是否已经开始
        /// </summary>
        bool IsGameStarted { get; }

        /// <summary>
        /// 主界面是否可交互
        /// </summary>
        bool IsInteractable { get; }

        /// <summary>
        /// 当前体力值。
        /// </summary>
        int CurrentEnergy { get; }

        /// <summary>
        /// 体力上限。
        /// </summary>
        int MaxEnergy { get; }
    }

    /// <summary>
    /// 游戏主界面数据模型
    /// 管理主界面相关的游戏状态和数据
    /// </summary>
    public class MainModel : ModelBase<IMainModelData>
    {
        private readonly ModelValue<bool> _isGameStarted;
        private readonly ModelValue<bool> _isInteractable;
        private readonly ModelValue<int> _currentEnergy;
        private readonly ModelValue<int> _maxEnergy;

        /// <summary>
        /// 游戏是否已经开始
        /// </summary>
        public bool IsGameStarted => GetValue(_isGameStarted);

        /// <summary>
        /// 主界面是否可交互
        /// </summary>
        public bool IsInteractable => GetValue(_isInteractable);

        /// <summary>
        /// 当前体力值。
        /// </summary>
        public int CurrentEnergy => GetValue(_currentEnergy);

        /// <summary>
        /// 体力上限。
        /// </summary>
        public int MaxEnergy => GetValue(_maxEnergy);

        public MainModel()
        {
            _isGameStarted = CreateValue(false);
            _isInteractable = CreateValue(true);
            _currentEnergy = CreateValue(0);
            _maxEnergy = CreateValue(0);
        }

        /// <summary>
        /// 创建只读数据接口实例
        /// </summary>
        protected override IMainModelData CreateData()
        {
            return new MainModelData(this);
        }

        /// <summary>
        /// 模型初始化
        /// </summary>
        protected override void OnModelInitialized()
        {
            base.OnModelInitialized();

            // 设置初始状态
            SetValue(_isGameStarted, false);
            SetValue(_isInteractable, true);
            SetValue(_currentEnergy, 0, nameof(CurrentEnergy));
            SetValue(_maxEnergy, 0, nameof(MaxEnergy));
        }

        /// <summary>
        /// 设置游戏开始状态
        /// </summary>
        /// <param name="started">是否已开始</param>
        public void SetGameStarted(bool started)
        {
            SetValue(_isGameStarted, started, nameof(IsGameStarted));
        }

        /// <summary>
        /// 设置界面交互状态
        /// </summary>
        /// <param name="interactable">是否可交互</param>
        public void SetInteractable(bool interactable)
        {
            SetValue(_isInteractable, interactable, nameof(IsInteractable));
        }

        /// <summary>
        /// 设置体力数据。
        /// </summary>
        public void SetEnergy(int currentEnergy, int maxEnergy)
        {
            int safeMax = Math.Max(0, maxEnergy);
            int safeCurrent = Math.Max(0, Math.Min(currentEnergy, safeMax));
            SetValue(_maxEnergy, safeMax, nameof(MaxEnergy));
            SetValue(_currentEnergy, safeCurrent, nameof(CurrentEnergy));
        }

        /// <summary>
        /// 模型释放
        /// </summary>
        protected override void OnModelReleased()
        {
            // 重置状态
            SetValue(_isGameStarted, false);
            SetValue(_isInteractable, true);
            SetValue(_currentEnergy, 0, nameof(CurrentEnergy));
            SetValue(_maxEnergy, 0, nameof(MaxEnergy));

            base.OnModelReleased();
        }

        /// <summary>
        /// 主界面模型只读数据接口实现
        /// </summary>
        private class MainModelData : IMainModelData
        {
            private readonly MainModel _model;

            public MainModelData(MainModel model)
            {
                _model = model ?? throw new ArgumentNullException(nameof(model));
            }

            public bool IsGameStarted => _model.IsGameStarted;
            public bool IsInteractable => _model.IsInteractable;
            public int CurrentEnergy => _model.CurrentEnergy;
            public int MaxEnergy => _model.MaxEnergy;
        }
    }
}
