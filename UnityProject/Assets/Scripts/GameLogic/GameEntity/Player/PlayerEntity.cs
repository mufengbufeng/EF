using UnityEngine;
using EF;
using GameConfig;
using System;
using DG.Tweening;

namespace GameLogic
{
    public class PlayerEntity : MonoBehaviour
    {
        #region 字段与属性
        private InputManager _inputManager;
        private FiniteStateMachine _fsm;
        private PlayerModel _playerModel;

        // 提供对 PlayerModel 的访问，以便状态类可以使用
        public PlayerModel Model => _playerModel;

        public GameObject HoleTrigger;
        public GameObject Hole;

        #endregion

        #region Unity生命周期
        public void Awake()
        {
            // 获取InputManager
            _inputManager = InputManager.Instance;
            _playerModel = PlayerModel.Instance;
            _fsm = new FiniteStateMachine(this);
            var UHub = transform.GetOrAddComponent<UHubComponent>();
            UHub.BindUI(this, gameObject);

            UpdateInfoByLevel(_playerModel.Level);
            BindEvents();

            // 创建并添加PlayerMoveState
            var moveState = new PlayerMoveState(_fsm, this);
            _fsm.AddState(moveState);

            // 启动状态机并设置PlayerMoveState为初始状态
            _fsm.Start<PlayerMoveState>();

            // 向FSMManager注册状态机
            if (FSMManager.Instance != null)
            {
                FSMManager.Instance.RegisterFSM(_fsm);
            }
            else
            {
                Debug.LogError("PlayerEntity: FSMManager不可用，状态机将不会被管理器更新");
            }
        }

        private void OnDestroy()
        {
            // 注销状态机
            // if (FSMManager.Instance != null && _fsm != null)
            // {
            //     FSMManager.Instance.UnregisterFSM(_fsm);
            // }
        }
        #endregion

        #region 状态机与事件绑定
        private void BindEvents()
        {
            GameModule.Event.Add(EventDefine.PlayerLevelChange, OnPlayerLevelChange);
        }

        private void OnPlayerLevelChange(object[] obj)
        {
            if (obj.Length == 0 || obj[0] is not int level)
            {
                return;
            }
            UpdateInfoByLevel(level);
            // 处理玩家等级变化的逻辑
            Log.Info($"PlayerEntity: 玩家等级变化，新的等级为 {level}");
        }
        #endregion

        #region 判断玩家位置
        /// <summary>
        /// 获取洞口半径
        /// </summary>
        public float GetHoleRadius()
        {
            float radius = HoleTrigger.GetComponent<CapsuleCollider>().radius;
            // 父物体放大倍数
            float fatherScale = Mathf.Max(Hole.transform.localScale.x, Hole.transform.localScale.z); // 受到父物体缩放影响
            // 玩家当前等级放大
            float playerScale = GetSizeByLevel(_playerModel.Level);
            Log.Info($"PlayerEntity: radius :{radius}  fatherScale :{fatherScale}  playerScale :{playerScale}  result :{radius * fatherScale * playerScale}");
            return radius * fatherScale * playerScale;
        }

        /// <summary>
        /// 获取玩家当前位置
        /// </summary>
        /// <returns>玩家当前位置的Vector3坐标</returns>
        public Vector3 GetPosition()
        {
            return transform.position;
        }
        #endregion

        #region 等级与体型相关
        /// <summary>
        /// 获取玩家当前等级放大
        /// </summary>
        public float GetSizeByLevel(int level)
        {
            var config = GameModule.Data.HoleLevelConfig.GetOrDefault(level);
            if (config == null)
            {
                Log.Error($"PlayerEntity: 没有找到等级为 {level} 的配置");
                return 0;
            }
            return config.Size * 0.01f;
        }

        /// <summary>
        /// 初始化视图层角色信息
        /// </summary>
        public void UpdateInfoByLevel(int level)
        {
            var size = GetSizeByLevel(level);

            // 使用DoTween创建放大回弹效果
            var scale = new Vector3(size * 1.1f, size * 1.1f, size * 1.1f);
            transform.DOScale(scale, 0.2f)
                .SetEase(Ease.OutQuad)
                .OnComplete(() =>
                {
                    transform.DOScale(new Vector3(size, size, size), 0.3f)
                        .SetEase(Ease.OutBounce);
                });

            Log.Info($"PlayerEntity: 更新角色信息，等级为 {level}，大小为 {size}");
        }
        #endregion

        #region 输入相关
        public Vector2 GetInput()
        {
            return _inputManager != null ? _inputManager.MovementValue : Vector2.zero;
        }
        #endregion

        #region 触发器相关
        void OnTriggerEnter(Collider other)
        {
            Log.Info($"PlayerEntity: 触碰到{other.gameObject.name}");
        }

        void OnTriggerExit(Collider other)
        {
            Log.Info($"PlayerEntity: 离开{other.gameObject.name}");
        }

        void OnTriggerStay(Collider other)
        {
            Log.Info($"{other.gameObject.name} 仍在触碰中");
        }
        #endregion
    }
}
