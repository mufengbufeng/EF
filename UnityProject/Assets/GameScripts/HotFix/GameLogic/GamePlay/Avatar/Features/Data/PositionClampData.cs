namespace GameLogic
{
    /// <summary>
    /// 位置约束特性配置数据。
    /// </summary>
    public sealed class PositionClampData
    {
        /// <summary>
        /// 边界内边距（世界单位）。
        /// </summary>
        public float BoundaryPadding { get; set; }

        /// <summary>
        /// 固定 Z 坐标。
        /// </summary>
        public float FixedZ { get; set; }
    }
}
