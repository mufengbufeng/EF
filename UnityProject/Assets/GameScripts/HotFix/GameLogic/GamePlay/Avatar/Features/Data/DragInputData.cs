using UnityEngine;

namespace GameLogic
{
    /// <summary>
    /// 拖拽输入特性配置数据。
    /// </summary>
    public sealed class DragInputData
    {
        /// <summary>
        /// 拖拽边界内边距（世界单位）。
        /// </summary>
        public float BoundaryPadding { get; set; }

        /// <summary>
        /// 固定 Z 坐标。
        /// </summary>
        public float FixedZ { get; set; }
    }
}
