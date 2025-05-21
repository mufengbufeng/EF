using UnityEngine;
using UnityEngine.UI; // Required for Canvas

namespace EF
{
    public abstract class BaseView : MonoBehaviour, IUIView
    {
        public GameObject root;

        public void Init(params object[] data)
        {
            root = gameObject;
            InitView(data);
        }

        protected abstract void InitView(params object[] data);

        public virtual void ShowView()
        {
            root.SetActive(true);
        }

        public virtual void HideView()
        {
            root.SetActive(false);
        }

        public virtual void CloseView()
        {
            Destroy(gameObject);
        }


    }
}