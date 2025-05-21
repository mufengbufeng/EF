using Cysharp.Threading.Tasks;
using EF;
using GameConfig;
using UnityEngine;
using UnityEditor;

namespace GameLogic
{
    public class PlayerModel : BaseModel<PlayerModel>
    {
        protected new bool _dontDestroyOnLoad = false;
        private float _speed = 1.0f;
        private float _radius = 1.0f;
        private float _size = 1.0f;
        private int _level = 1;
        private int _exp = 0;
        public float Speed { get { return _speed; } private set { _speed = value; } }
        public float Radius { get { return _radius; } }
        public int Level { get { return _level; } }
        public int Exp { get { return _exp; } }
        // public float Size { get { return _size; } }

        protected override void Awake()
        {
            base.Awake();
            GameModule.Event.Add(EventDefine.GetPoint, OnGetPoint);
        }
        public void InitPlayerInfo()
        {
            int baseSize = GameModule.Data.GameConfigsConfig.GetOrDefault("HoleBaseSize").IntValue;
            _size = baseSize * 0.01f; // / 100
            Log.Info($"_size 为 {_size}");
            _exp = 0;
            _speed = 1.0f;
            _level = 1;
            ChangeSizeByLevel(_level);
        }

        public void OnGetPoint(object[] args)
        {
            if (args.Length == 0 || args[0] is not int point)
            {
                return;
            }
            _exp += point;
            Log.Info($"获得经验值 {point}");
            int nextLevel = _level + 1;
            var nextEx = GameModule.Data.HoleLevelConfig.GetOrDefault(nextLevel);
            if (nextEx == null) return;
            int needExp = nextEx.Exp;
            if (_exp >= needExp)
            {
                LevelUp();
            }
        }

        private void ChangeSizeByLevel(int level)
        {
            var LevelInfo = GameModule.Data.HoleLevelConfig.GetOrDefault(level);
            _size = LevelInfo.Size * 0.01f; // / 100

            Log.Info($"_size 为 {_size}");
        }


        private void LevelUp()
        {
            _level++;
            var LevelInfo = GameModule.Data.HoleLevelConfig.GetOrDefault(_level);
            if (LevelInfo != null)
            {
                _speed = LevelInfo.Speed * 0.01f;
                _radius = LevelInfo.Size * 0.01f; // / 100
                GameModule.Event.Trigger(EventDefine.PlayerLevelChange, _level);
                Log.Info($"升级到 {_level} 级，速度为 {_speed}，半径为 {_radius}");
            }
            else
            {
                _level--; // 满级了
                Log.Warning($"没有找到等级 {_level} 的信息");
            }
        }
    }
}