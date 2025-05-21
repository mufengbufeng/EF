using UnityEngine;
using System.Collections.Generic;
#if UNITY_EDITOR
using UnityEditor;
#endif
namespace GameLogic
{
    public class BoxColliderCornersCollector : MonoBehaviour
    {
        [Header("所有BoxCollider的四角XZ坐标")]
        public Vector2[] AllBoxColliderCorners;

        // void Awake()
        // {
        //     CollectAllBoxColliderCorners();
        // }
        public Vector2[] GetAllBoxColliderCorners()
        {
            if (AllBoxColliderCorners == null || AllBoxColliderCorners.Length < 4)
            {
                CollectAllBoxColliderCorners();
            }
            return AllBoxColliderCorners;
        }

        public void CollectAllBoxColliderCorners()
        {
            List<Vector2> cornersList = new List<Vector2>();
            // 获取所有BoxCollider（包括子物体）
            var colliders = GetComponentsInChildren<BoxCollider>();
            foreach (var box in colliders)
            {
                // 获取BoxCollider的中心和尺寸（本地空间）
                Vector3 center = box.center;
                Vector3 size = box.size * 0.5f;

                // 计算本地空间下的四个角（忽略Y轴）
                Vector3[] localCorners = new Vector3[4];
                localCorners[0] = center + new Vector3(-size.x, 0, -size.z);
                localCorners[1] = center + new Vector3(-size.x, 0, size.z);
                localCorners[2] = center + new Vector3(size.x, 0, size.z);
                localCorners[3] = center + new Vector3(size.x, 0, -size.z);

                // 转换到世界空间，并只取X、Z分量
                foreach (var localCorner in localCorners)
                {
                    Vector3 worldCorner = box.transform.TransformPoint(localCorner);
                    cornersList.Add(new Vector2(worldCorner.x, worldCorner.z));
                }
            }
            AllBoxColliderCorners = cornersList.ToArray();
        }

#if UNITY_EDITOR
        [CustomEditor(typeof(BoxColliderCornersCollector))]
        public class BoxColliderCornersCollectorEditor : Editor
        {
            public override void OnInspectorGUI()
            {
                DrawDefaultInspector();
                BoxColliderCornersCollector collector = (BoxColliderCornersCollector)target;
                if (GUILayout.Button("收集BoxCollider四角坐标"))
                {
                    collector.CollectAllBoxColliderCorners();
                    EditorUtility.SetDirty(collector);
                }
            }
        }
#endif

        // Scene视图辅助线
        void OnDrawGizmos()
        {
            if (AllBoxColliderCorners == null || AllBoxColliderCorners.Length < 4)
                return;
            Gizmos.color = Color.red;
            int rectCount = AllBoxColliderCorners.Length / 4;
            for (int i = 0; i < rectCount; i++)
            {
                int idx = i * 4;
                Vector3 p0 = new Vector3(AllBoxColliderCorners[idx + 0].x, transform.position.y, AllBoxColliderCorners[idx + 0].y);
                Vector3 p1 = new Vector3(AllBoxColliderCorners[idx + 1].x, transform.position.y, AllBoxColliderCorners[idx + 1].y);
                Vector3 p2 = new Vector3(AllBoxColliderCorners[idx + 2].x, transform.position.y, AllBoxColliderCorners[idx + 2].y);
                Vector3 p3 = new Vector3(AllBoxColliderCorners[idx + 3].x, transform.position.y, AllBoxColliderCorners[idx + 3].y);
                Gizmos.DrawLine(p0, p1);
                Gizmos.DrawLine(p1, p2);
                Gizmos.DrawLine(p2, p3);
                Gizmos.DrawLine(p3, p0);
            }
        }
    }
}