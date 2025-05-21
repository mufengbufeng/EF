using UnityEditor;
using UnityEngine;
using System.Collections.Generic;
using System.Linq;

[CustomEditor(typeof(Polygon3D))]
public class Polygon3DEditor : Editor
{
    private Polygon3D poly;
    private void OnEnable() => poly = (Polygon3D)target;

    private void OnSceneGUI()
    {
        if (poly.points == null) return;

        Handles.color = Color.green;
        for (int i = 0; i < poly.points.Count; i++)
        {
            EditorGUI.BeginChangeCheck();
            Vector3 worldPos = poly.transform.TransformPoint(poly.points[i]);
            Handles.SphereHandleCap(0, worldPos, Quaternion.identity, 0.1f, EventType.Repaint); // 可视化点
            Vector3 newWorldPos = Handles.PositionHandle(worldPos, Quaternion.identity);
            if (EditorGUI.EndChangeCheck())
            {
                Undo.RecordObject(poly, "Move Polygon Point");
                poly.points[i] = poly.transform.InverseTransformPoint(newWorldPos);
            }

            // 画线
            int next = (i + 1) % poly.points.Count;
            Handles.DrawLine(
                poly.transform.TransformPoint(poly.points[i]),
                poly.transform.TransformPoint(poly.points[next])
            );
        }

        // 绘制凸包
        if (poly.convexHull != null && poly.convexHull.Count > 1)
        {
            Handles.color = Color.red;
            for (int i = 0; i < poly.convexHull.Count; i++)
            {
                int next = (i + 1) % poly.convexHull.Count;
                Handles.DrawLine(poly.convexHull[i], poly.convexHull[next]);
            }
        }
    }

    public override void OnInspectorGUI()
    {
        DrawDefaultInspector();

        if (GUILayout.Button("添加顶点"))
        {
            Undo.RecordObject(poly, "Add Polygon Point");
            if (poly.points.Count > 1)
            {
                // 在最后一条边的中点插入
                Vector3 last = poly.points[poly.points.Count - 1];
                Vector3 first = poly.points[0];
                poly.points.Add((last + first) * 0.5f);
            }
            else
            {
                poly.points.Add(Vector3.zero);
            }
        }

        if (poly.points.Count > 3 && GUILayout.Button("删除最后一个顶点"))
        {
            Undo.RecordObject(poly, "Remove Polygon Point");
            poly.points.RemoveAt(poly.points.Count - 1);
        }

        if (GUILayout.Button("获取物体Mesh并计算凸包"))
        {
            Undo.RecordObject(poly, "Calculate Convex Hull");
            List<Vector3> allPoints = new List<Vector3>();
            Mesh mesh = null;
            var mf = poly.GetComponent<MeshFilter>();
            if (mf != null && mf.sharedMesh != null)
            {
                mesh = mf.sharedMesh;
                foreach (var v in mesh.vertices)
                {
                    allPoints.Add(mf.transform.TransformPoint(v));
                }
            }
            else
            {
                var smr = poly.GetComponent<SkinnedMeshRenderer>();
                if (smr != null && smr.sharedMesh != null)
                {
                    mesh = smr.sharedMesh;
                    foreach (var v in mesh.vertices)
                    {
                        allPoints.Add(smr.transform.TransformPoint(v));
                    }
                }
            }
            if (allPoints.Count < 3) return;
            var hull = ConvexHull2D(allPoints);
            poly.points = hull;
            poly.convexHull.Clear();
        }
    }

    // 2D凸包算法（Graham Scan，假设Y为高度，XZ平面凸包）
    private List<Vector3> ConvexHull2D(List<Vector3> points)
    {
        if (points.Count < 3) return new List<Vector3>(points);

        // 投影到XZ平面
        var pts = points.Select(p => new Vector2(p.x, p.z)).ToList();
        var hull = new List<int>();

        // 找到最左下角点
        int left = 0;
        for (int i = 1; i < pts.Count; i++)
            if (pts[i].x < pts[left].x || (pts[i].x == pts[left].x && pts[i].y < pts[left].y))
                left = i;

        int p = left, q;
        do
        {
            hull.Add(p);
            q = (p + 1) % pts.Count;
            for (int i = 0; i < pts.Count; i++)
            {
                if (Orientation(pts[p], pts[i], pts[q]) < 0)
                    q = i;
            }
            p = q;
        } while (p != left);

        // 返回凸包点（原始3D点）
        return hull.Select(i => points[i]).ToList();
    }

    // 叉积判断方向
    private float Orientation(Vector2 p, Vector2 q, Vector2 r)
    {
        return (q.x - p.x) * (r.y - p.y) - (q.y - p.y) * (r.x - p.x);
    }
}