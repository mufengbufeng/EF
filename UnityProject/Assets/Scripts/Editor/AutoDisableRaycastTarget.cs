// using UnityEngine;
// using System.Collections;
// using UnityEditor;
// using UnityEngine.UI;
// using UnityEditor.SceneManagement;
// using UnityEditor.Experimental.SceneManagement;
// using UnityEngine.SceneManagement;
// using EF;

// public class UITools
// {
//     // /// <summary>
//     // /// 自动取消RaycastTarget
//     // /// </summary>
//     [MenuItem("GameObject/UI/Text - TextMeshPro")]
//     static void CreateTextMeshProUGUI()
//     {
//         CreateUIElement<TMPro.TextMeshProUGUI>("TextMeshPro");
//     }

//     [MenuItem("GameObject/UI/Raw Image")]
//     static void CreateRawImage()
//     {
//         CreateUIElement<RawImage>("RawImage");
//     }

//     // [MenuItem("GameObject/UI/Panel")]
//     // static void CreatePanel()
//     // {
//     //     CreateUIElement<Canvas>("Panel");
//     // }

//     [MenuItem("GameObject/UI/TImage")]
//     static void CreateImage()
//     {
//         Log.Info("aaaaaa");
//         CreateUIElement<Image>("Image");
//     }

//     private static GameObject GetRootForUI()
//     {
//         // Prefab 模式
//         var prefabStage = PrefabStageUtility.GetCurrentPrefabStage();
//         if (prefabStage != null)
//         {
//             // Prefab 模式下，返回 Prefab 根节点
//             return prefabStage.prefabContentsRoot;
//         }

//         // 场景模式
//         var scene = SceneManager.GetActiveScene();
//         var roots = scene.GetRootGameObjects();
//         // 优先找 Canvas
//         foreach (var go in roots)
//         {
//             var canvas = go.GetComponentInChildren<Canvas>();
//             if (canvas != null)
//                 return canvas.gameObject;
//         }
//         // 没有 Canvas 就返回第一个根节点
//         return roots.Length > 0 ? roots[0] : null;
//     }
//     private static void CreateUIElement<T>(string name) where T : Component
//     {
//         GameObject parent = Selection.activeGameObject;
//         if (parent == null)
//         {
//             parent = GetRootForUI();
//             if (parent == null)
//             {
//                 Debug.LogWarning("未找到合适的根节点，请先创建一个 Canvas 或根 GameObject。");
//                 return;
//             }
//         }

//         GameObject go = new GameObject(name, typeof(RectTransform), typeof(T));
//         Graphic graphicComponent = go.GetComponent<Graphic>();
//         if (graphicComponent != null)
//         {
//             graphicComponent.raycastTarget = false;
//         }
//         else
//         {
//             Debug.LogWarning("The component type T does not have a raycastTarget property.");
//         }

//         go.transform.SetParent(parent.transform, false);
//         go.GetComponent<RectTransform>().localPosition = Vector3.zero;

//     }


// }

