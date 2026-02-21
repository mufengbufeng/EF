using UnityEngine;

namespace GameLogic
{
    /// <summary>
    /// 子弹归属类型。
    /// </summary>
    public enum BulletOwnerType
    {
        /// <summary>
        /// 玩家子弹。
        /// </summary>
        Player,

        /// <summary>
        /// 敌人子弹。
        /// </summary>
        Enemy
    }

    /// <summary>
    /// 子弹生成参数数据。
    /// 用于描述子弹的初始位置、飞行方向、速度、归属方、发射者和伤害值。
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
        /// 子弹归属类型。
        /// </summary>
        public BulletOwnerType OwnerType { get; set; }

        /// <summary>
        /// 子弹伤害值。
        /// </summary>
        public float Damage { get; set; }

        /// <summary>
        /// 发射该子弹的实体 ID。
        /// 用于角色死亡时清理自身发射的在场子弹。
        /// </summary>
        public int SourceEntityId { get; set; }
    }
}
