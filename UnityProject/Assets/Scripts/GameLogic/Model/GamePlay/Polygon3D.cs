using System.Collections.Generic;
using UnityEngine;

[ExecuteInEditMode]
public class Polygon3D : MonoBehaviour
{
    // 顶点列表，按顺序连接，首尾自动闭合
    public List<Vector3> points = new List<Vector3>()
    {
        new Vector3(-1,0,0),
        new Vector3(1,0,0),
        new Vector3(1,0,1),
        new Vector3(-1,0,1)
    };

    public List<Vector3> convexHull = new List<Vector3>();
}