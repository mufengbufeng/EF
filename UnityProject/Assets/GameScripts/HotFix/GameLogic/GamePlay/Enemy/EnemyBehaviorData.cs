using UnityEngine;

namespace GameLogic
{
    /// <summary>
    /// 敌人行为配置数据。
    /// 用于在 OnShow 时传递敌人的初始参数。
    /// </summary>
    public class EnemyBehaviorData
    {
        /// <summary>
        /// 生成位置。
        /// </summary>
        public Vector3 SpawnPosition { get; set; }

        /// <summary>
        /// 移动速度（单位/秒）。
        /// </summary>
        public float MoveSpeed { get; set; }

        /// <summary>
        /// 移动方向（归一化向量）。
        /// </summary>
        public Vector3 MoveDirection { get; set; }

        /// <summary>
        /// 停留位置。
        /// </summary>
        public Vector3 StayPosition { get; set; }

        /// <summary>
        /// 停留时长（秒）。
        /// </summary>
        public float StayDuration { get; set; }

        /// <summary>
        /// 攻击间隔（秒）。
        /// </summary>
        public float AttackInterval { get; set; }
    }
}
