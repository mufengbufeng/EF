using UnityEngine;
using EF;

namespace GameLogic
{
    /// <summary>
    /// Player移动状态，处理角色的移动逻辑
    /// </summary>
    public class PlayerMoveState : BaseState
    {
        private PlayerEntity _playerEntity;
        private Transform _transform;
        private InputManager _inputManager;
        private PlayerModel _playerModel;
        private bool _IsDebug = true;

        /// <summary>
        /// 构造函数
        /// </summary>
        /// <param name="fsm">所属的FSM</param>
        /// <param name="playerEntity">玩家实体</param>
        public PlayerMoveState(FiniteStateMachine fsm, PlayerEntity playerEntity) : base(fsm)
        {
            _playerEntity = playerEntity;
            _transform = playerEntity.transform;
        }

        /// <summary>
        /// 进入状态时调用
        /// </summary>
        public override void Enter()
        {
            base.Enter();

            // 获取InputManager单例
            _inputManager = InputManager.Instance;

            // 获取PlayerModel
            _playerModel = _playerEntity.Model;

            if (_inputManager == null)
            {
                Debug.LogError("PlayerMoveState: InputManager不可用");
            }

            if (_playerModel == null)
            {
                Debug.LogError("PlayerMoveState: PlayerModel不可用或未在PlayerEntity初始化");
            }
        }

        public Vector2 zero = new Vector2(0, 0);
        /// <summary>
        /// 状态更新时调用
        /// </summary>
        public override void Update()
        {
            base.Update();

            if (_inputManager == null || _playerModel == null)
            {
                return; // 如果依赖项不可用，则不执行更新
            }
            // 获取输入和速度
            Vector2 inputValue = _playerEntity.GetInput();
            if (inputValue == zero)
            {
                return;
            }
            float speed = _playerModel.Speed;
            Vector3 movementDirection = new Vector3(inputValue.x, 0f, inputValue.y);
            Vector3 currentPosition = _transform.position;
            Vector3 targetPosition = currentPosition + movementDirection * speed * Time.deltaTime;

            float radius = _playerEntity.GetHoleRadius();
            var gamePlayModel = GamePlayModel.Instance;
            if (gamePlayModel == null)
                return;

            // 1. 尝试完整移动
            if (IsCircleInBoundary(new Vector2(targetPosition.x, targetPosition.z), radius, gamePlayModel))
            {
                _transform.position = targetPosition;
                return;
            }

            // 2. 尝试只移动X
            if (IsCircleInBoundary(new Vector2(targetPosition.x, currentPosition.z), radius, gamePlayModel))
            {
                _transform.position = new Vector3(targetPosition.x, currentPosition.y, currentPosition.z);
                return;
            }

            // 3. 尝试只移动Z
            if (IsCircleInBoundary(new Vector2(currentPosition.x, targetPosition.z), radius, gamePlayModel))
            {
                _transform.position = new Vector3(currentPosition.x, currentPosition.y, targetPosition.z);
                return;
            }

            // 4. 三个方向都不行，则不移动
        }

        /// <summary>
        /// 检查以center为圆心，radius为半径的圆是否完全在边界内
        /// </summary>
        private bool IsCircleInBoundary(Vector2 center, float radius, GamePlayModel gamePlayModel, int sampleCount = 8)
        {
            float angleStep = 360f / sampleCount;
            for (int i = 0; i < sampleCount; i++)
            {
                float angle = angleStep * i * Mathf.Deg2Rad;
                Vector2 edgePoint = center + new Vector2(Mathf.Cos(angle), Mathf.Sin(angle)) * radius;
                if (!gamePlayModel.IsPointInAllBoxColliderCorners(edgePoint))
                {
                    return false;
                }
            }
            return true;
        }

        /// <summary>
        /// 退出状态时调用
        /// </summary>
        public override void Exit()
        {
            base.Exit();
            // 当前没有特定清理逻辑
        }

        private void SelfLog(string message)
        {
            if (_IsDebug)
            {
                Log.Info(message);
            }
        }
    }
}