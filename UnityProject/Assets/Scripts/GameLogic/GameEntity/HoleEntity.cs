using UnityEngine;

public class HoleEntity : MonoBehaviour
{
    /// <summary>
    /// OnTriggerExit is called when the Collider other has stopped touching the trigger.
    /// </summary>
    /// <param name="other">The other Collider involved in this collision.</param>
    void OnTriggerExit(Collider other)
    {
        if (other.transform.CompareTag("PointObject"))
        {
            other.GetComponent<PointObjectEntity>().ExitPhysics();
        }
    }



    /// <summary>
    /// OnTriggerEnter is called when the Collider other enters the trigger.
    /// </summary>
    /// <param name="other">The other Collider involved in this collision.</param>
    void OnTriggerEnter(Collider other)
    {
        if (other.transform.CompareTag("PointObject"))
        {
            // Log.Info($"触碰到: {other.gameObject.name} Layer: {other.gameObject.layer}");
            // Log.Info($"HoleMask: {LayerMask.NameToLayer("Hole")}");
            // Log.Info($"触碰到: {other.gameObject.name} Layer: {other.gameObject.layer}");
            other.GetComponent<PointObjectEntity>().EnterPhysics();
        }
    }

    /// <summary>
    /// OnTriggerStay is called once per frame for every Collider other
    /// that is touching the trigger.
    /// </summary>
    /// <param name="other">The other Collider involved in this collision.</param>
    void OnTriggerStay(Collider other)
    {
        if (other.transform.CompareTag("PointObject"))
        {
            other.GetComponent<PointObjectEntity>().WakeUp();
        }
    }
}
