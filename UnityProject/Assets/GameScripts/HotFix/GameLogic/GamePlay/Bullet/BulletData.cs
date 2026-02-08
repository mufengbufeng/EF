using UnityEngine;

namespace GameLogic
{
    /// <summary>
    /// 子弹生成参数数据。
    /// 用于描述子弹的初始位置、飞行方向、速度和归属方。
    /// </summary>
    public class BulletData
    {
        /// <summary>
        /// 子弹生成位置。
        /// </summary>
        public Vector3 SpawnPosition { get; set; }

        /// <summary>
        /// 子弹飞行方向（归一化向量）。
        /// </summary>
        public Vector3 Direction { get; set; }

        /// <summary>
        /// 子弹飞行速度。
        /// </summary>
        public float Speed { get; set; }

        /// <summary>
        /// 子弹归属标签。
        /// "Player" 表示玩家子弹，"Enemy" 表示敌人子弹。
        /// </summary>
        public string OwnerTag { get; set; }
    }
}
