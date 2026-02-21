using UnityEngine;

namespace GameLogic
{
    /// <summary>
    /// 玩家飞机行为配置数据。
    /// </summary>
    public sealed class PlayerAvatarBehaviorData
    {
        /// <summary>
        /// 初始出生位置。
        /// </summary>
        public Vector3 SpawnPosition { get; set; }

        /// <summary>
        /// 自动攻击间隔（秒）。
        /// </summary>
        public float AttackInterval { get; set; }

        /// <summary>
        /// 默认子弹速度。
        /// </summary>
        public float BulletSpeed { get; set; }

        /// <summary>
        /// 拖拽边界内边距（世界单位）。
        /// </summary>
        public float DragBoundaryPadding { get; set; }
    }
}
