using UnityEngine;
using System.Collections.Generic;
using Cysharp.Threading.Tasks;
using UnityEngine.PlayerLoop; // UniTask异步任务库

namespace EF
{
    public class UIManager : BehaviourSingleton<UIManager>
    {
        public Transform Canvas;
        public Dictionary<string, BaseUIView> ViewDict = new Dictionary<string, BaseUIView>();
        protected override void Init()
        {
            base.Init();
            Canvas = GameObject.FindGameObjectWithTag("MainCanvas").transform;
        }
        // 打开UI
        public T OpenUI<T>(string uiName, UILayer layer, params object[] userData) where T : BaseUIView
        {
            if (ViewDict.TryGetValue(uiName, out var existingView))
            {
                existingView.ShowView();
                return (T)existingView;
            }

            GameObject uiObj = ResourceModule.Instance.LoadGameObject(uiName, Canvas);
            var canvas = uiObj.GetComponent<Canvas>();
            if (canvas == null)
            {
                canvas = uiObj.AddComponent<Canvas>();
            }

            canvas.overrideSorting = true;
            canvas.sortingOrder = (int)layer;

            var view = uiObj.AddComponent<T>();
            view.Init(userData);
            view.ShowView();
            ViewDict.Add(uiName, view);
            return view;
        }

        public async UniTask<T> OpenUIAsync<T>(string uiName, UILayer layer, params object[] userData) where T : BaseUIView
        {
            if (ViewDict.TryGetValue(uiName, out var existingView))
            {
                existingView.ShowView();
                return (T)existingView;
            }

            GameObject uiObj = await ResourceModule.Instance.LoadGameObjectAsync(uiName, Canvas);
            var canvas = uiObj.GetComponent<Canvas>();
            if (canvas == null)
            {
                canvas = uiObj.AddComponent<Canvas>();
            }

            canvas.overrideSorting = true;
            canvas.sortingOrder = (int)layer;

            var view = uiObj.AddComponent<T>();
            view.Init(userData);
            ViewDict.Add(uiName, view);
            return view;
        }

        public void ShowUI(string uiName)
        {
            if (ViewDict.TryGetValue(uiName, out var view))
            {
                view.ShowView();
            }
            else
            {
                Log.Error($"UI {uiName} not found in ViewDict.");
            }
        }

        public void HideUI(string uiName)
        {
            if (ViewDict.TryGetValue(uiName, out var view))
            {
                view.HideView();
            }
            else
            {
                Log.Error($"UI {uiName} not found in ViewDict.");
            }
        }

        public void CloseUI(string uiName)
        {
            if (ViewDict.TryGetValue(uiName, out var view))
            {
                view.CloseView();
                ViewDict.Remove(uiName);
            }
            else
            {
                Log.Error($"UI {uiName} not found in ViewDict.");
            }
        }
    }
}