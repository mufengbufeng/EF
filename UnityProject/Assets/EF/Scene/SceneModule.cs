using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using YooAsset;

namespace EF
{
    public class SceneModule : BehaviourSingleton<SceneModule>
    {
        public Dictionary<string, SceneHandle> sceneHandles = new Dictionary<string, SceneHandle>();
        public Scene LoadScene(string sceneName, LoadSceneMode sceneMode = LoadSceneMode.Single, LocalPhysicsMode physicsMode = LocalPhysicsMode.None)
        {
            if (sceneHandles.ContainsKey(sceneName))
            {
                Debug.LogError($"Scene {sceneName} is already loaded.");
                return default;
            }

            var sceneHandle = ResourceModule.Instance.LoadScene(sceneName, sceneMode, physicsMode);
            var obj = sceneHandle.SceneObject;
            sceneHandles.Add(sceneName, sceneHandle);
            return obj;
        }

        public void UnloadScene(string sceneName)
        {
            if (sceneHandles.ContainsKey(sceneName))
            {
                var sceneHandle = sceneHandles[sceneName];
                sceneHandle.Release();
                sceneHandles.Remove(sceneName);
                Debug.Log($"Scene {sceneName} unloaded.");
            }
            else
            {
                Debug.LogError($"Scene {sceneName} is not loaded.");
            }
        }
    }
}