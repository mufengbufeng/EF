using Cysharp.Threading.Tasks;
using GameProto;
using EF;
using JetBrains.Annotations;
using UnityEngine;
using UnityEngine.PlayerLoop;


namespace GameLogic
{
    public static class GameModule
    {
        public static ResourceModule Resource;
        public static void Run()
        {
            Init();
        }

        public static void Init()
        {
            Resource = ResourceModule.Instance;
            Log.Info("Sphere");
            // Resource.LoadGameObjectAsync("Sphere").Forget();
            Resource.LoadGameObjectAsync("Cube").Forget();
            NULL.TestLog("2222");
        }


    }
}
