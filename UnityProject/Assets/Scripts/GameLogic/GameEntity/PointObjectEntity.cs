using EF;
using UnityEngine;

public class PointObjectEntity : MonoBehaviour
{
    // 积分值
    public int PointId = 1;
    private Rigidbody _rb;
    private BoxCollider _collider;

    void Awake()
    {
        _rb = GetComponent<Rigidbody>();
        _collider = GetComponent<BoxCollider>();
        _rb.useGravity = true;
    }




    public void EnterPhysics()
    {
        Log.Info("进入物理");
        _rb.excludeLayers = 1 << LayerMask.NameToLayer("Plane");
        // _rb.useGravity = true;
        // _rb.WakeUp();
    }

    public void WakeUp()
    {
        _rb.WakeUp();
    }

    public void ExitPhysics()
    {
        // 强制禁用物理
        // _rb.useGravity = false;
        Log.Info("退出物理");
        _rb.velocity = Vector3.zero;
        _rb.excludeLayers = 0;
    }

}
