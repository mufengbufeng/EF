using System.Collections.Generic;
using UnityEngine;

namespace EF
{
    /// <summary>
    /// 单例系统，负责管理所有单例实例的生命周期
    /// </summary>
    public static class SingletonModule
    {
        // 存储所有注册的单例实例
        private static Dictionary<System.Type, ISingleton> _singletons = new();

        /// <summary>
        /// 持有（注册）单例实例
        /// </summary>
        /// <param name="singleton">要注册的单例实例</param>
        public static void Register(ISingleton singleton)
        {
            System.Type type = singleton.GetType();

            if (_singletons.ContainsKey(type))
            {
                Log.Warning($"单例类型 {type.Name} 已经被注册");
                return;
            }

            _singletons[type] = singleton;
            singleton.Active();

            Log.Info($"单例 {type.Name} 已注册到系统");
        }

        /// <summary>
        /// 释放单例实例
        /// </summary>
        /// <param name="singleton">要释放的单例实例</param>
        public static void Release(ISingleton singleton)
        {
            System.Type type = singleton.GetType();

            if (!_singletons.ContainsKey(type))
            {
                Debug.LogWarning($"尝试释放未注册的单例: {type.Name}");
                return;
            }

            _singletons.Remove(type);
            Log.Info($"单例 {type.Name} 已从系统释放");
        }

        /// <summary>
        /// 释放所有单例实例
        /// </summary>
        public static void ReleaseAll()
        {
            List<ISingleton> instances = new List<ISingleton>(_singletons.Values);
            foreach (ISingleton singleton in instances)
            {
                singleton.Release();
            }

            _singletons.Clear();
            Log.Info("所有单例实例已释放");
        }

        /// <summary>
        /// 获取所有已注册的单例类型
        /// </summary>
        /// <returns>所有已注册的单例类型列表</returns>
        public static List<System.Type> GetAllSingletonTypes()
        {
            return new List<System.Type>(_singletons.Keys);
        }

        /// <summary>
        /// 获取单例实例的总数
        /// </summary>
        public static int Count => _singletons.Count;

#if UNITY_EDITOR
        /// <summary>
        /// 在编辑器模式下查看单例状态的辅助方法
        /// </summary>
        [UnityEditor.MenuItem("工具/显示单例系统状态")]
        private static void ShowStatus()
        {
            Log.Info($"当前单例系统中有 {_singletons.Count} 个单例实例");
            foreach (var kvp in _singletons)
            {
                Log.Info($"- {kvp.Key.Name}");
            }
        }
#endif
    }
}