using EF.Feature;
using UnityEngine;

namespace GameLogic
{
    /// <summary>
    /// 位置约束特性，将实体位置限制在摄像机可视区域内。
    /// </summary>
    public class PositionClampFeature : FeatureBase<PositionClampData>
    {
        private float _boundaryPadding;
        private float _fixedZ;

        protected override void OnSetup(PositionClampData data)
        {
            _boundaryPadding = Mathf.Max(0f, data.BoundaryPadding);
            _fixedZ = data.FixedZ;
        }

        /// <summary>
        /// 将目标位置约束在摄像机可视区域内。
        /// </summary>
        /// <param name="targetPosition">目标位置。</param>
        /// <returns>约束后的位置。</returns>
        public Vector3 ClampPosition(Vector3 targetPosition)
        {
            Camera camera = Camera.main;
            if (camera == null)
            {
                return targetPosition;
            }

            if (camera.orthographic)
            {
                return ClampOrthographic(camera, targetPosition);
            }

            return ClampPerspective(camera, targetPosition);
        }

        /// <summary>
        /// 每帧将实体位置约束在摄像机可视区域内。
        /// </summary>
        public override void OnUpdate(float elapseSeconds, float realElapseSeconds)
        {
            if (Entity?.Handle == null)
            {
                return;
            }

            Entity.Handle.transform.position = ClampPosition(Entity.Handle.transform.position);
        }

        /// <summary>
        /// 正交摄像机下的位置约束。
        /// </summary>
        private Vector3 ClampOrthographic(Camera camera, Vector3 targetPosition)
        {
            float halfHeight = camera.orthographicSize;
            float halfWidth = halfHeight * camera.aspect;
            float minX = camera.transform.position.x - halfWidth + _boundaryPadding;
            float maxX = camera.transform.position.x + halfWidth - _boundaryPadding;
            float minY = camera.transform.position.y - halfHeight + _boundaryPadding;
            float maxY = camera.transform.position.y + halfHeight - _boundaryPadding;

            if (minX > maxX)
            {
                minX = maxX = camera.transform.position.x;
            }

            if (minY > maxY)
            {
                minY = maxY = camera.transform.position.y;
            }

            targetPosition.x = Mathf.Clamp(targetPosition.x, minX, maxX);
            targetPosition.y = Mathf.Clamp(targetPosition.y, minY, maxY);
            targetPosition.z = _fixedZ;
            return targetPosition;
        }

        /// <summary>
        /// 透视摄像机下的位置约束，通过 Viewport 坐标实现。
        /// </summary>
        private Vector3 ClampPerspective(Camera camera, Vector3 targetPosition)
        {
            float zDistance = Mathf.Abs(camera.transform.position.z - _fixedZ);
            Vector3 viewport = camera.WorldToViewportPoint(targetPosition);
            viewport.x = Mathf.Clamp01(viewport.x);
            viewport.y = Mathf.Clamp01(viewport.y);
            Vector3 world = camera.ViewportToWorldPoint(new Vector3(viewport.x, viewport.y, zDistance));
            world.z = _fixedZ;
            return world;
        }
    }
}
