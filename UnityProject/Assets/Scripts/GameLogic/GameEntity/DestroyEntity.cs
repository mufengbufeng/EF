using System.Collections;
using System.Collections.Generic;
using GameLogic;
using UnityEngine;

public class DestroyEntity : MonoBehaviour
{
    void OnTriggerEnter(Collider other)
    {
        if (other.transform.CompareTag("PointObject"))
        {
            var entity = other.GetComponent<PointObjectEntity>();

            GameModule.Event.Trigger(EventDefine.GetPoint, entity.PointId);
            Destroy(other.gameObject);
        }
    }
}
