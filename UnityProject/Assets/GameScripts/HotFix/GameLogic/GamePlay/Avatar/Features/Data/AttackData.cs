namespace GameLogic
{
    /// <summary>
    /// 攻击特性配置数据。
    /// </summary>
    public sealed class AttackData
    {
        /// <summary>
        /// 攻击间隔（秒）。
        /// </summary>
        public float AttackInterval { get; set; }

        /// <summary>
        /// 子弹速度。
        /// </summary>
        public float BulletSpeed { get; set; }

        /// <summary>
        /// 子弹所属实体 ID。
        /// </summary>
        public int SourceEntityId { get; set; }
    }
}
