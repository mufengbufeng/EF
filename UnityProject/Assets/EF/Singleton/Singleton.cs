using System.Diagnostics;
using UnityEngine;

namespace EF
{

    /// <summary>
    /// 通用单例模式基类，适用于普通C#类的单例实现
    /// </summary>
    /// <typeparam name="T">子类类型</typeparam>
    public abstract class Singleton<T> : ISingleton where T : Singleton<T>, new()
    {
        /// <summary>
        /// 单例实例的静态引用
        /// </summary>
        protected static T _instance = default(T);

        /// <summary>
        /// 获取单例实例。如果实例不存在，则创建一个新实例，初始化并注册到SingletonModule。
        /// </summary>
        public static T Instance
        {
            get
            {
                if (null == _instance)
                {
                    _instance = new T();
                    _instance.Init();
                    SingletonModule.Register(_instance);

                    // 在应用程序退出时自动释放单例
                    Application.quitting += () =>
                    {
                        if (_instance != null)
                        {
                            _instance.Release();
                        }
                    };
                }

                return _instance;
            }
        }

        /// <summary>
        /// 检查单例实例是否有效（是否已创建）
        /// </summary>
        public static bool IsValid => _instance != null;

        /// <summary>
        /// 受保护的构造函数，防止外部直接实例化。
        /// 在编辑器模式下检查实例化方式，确保只通过Instance属性创建实例。
        /// </summary>
        protected Singleton()
        {
#if UNITY_EDITOR
            string st = new StackTrace().ToString();
            // 检查是否通过Instance属性创建实例
            if (!st.Contains("EF.Singleton`1[T].get_Instance"))
            {
                UnityEngine.Debug.LogError($"请必须通过Instance属性来实例化 {typeof(T).FullName} 类");
            }
#endif
        }

        /// <summary>
        /// 初始化方法，在实例首次创建时调用。
        /// 子类可重写此方法以实现自定义初始化逻辑。
        /// </summary>
        protected virtual void Init()
        {
            Log.Info($"单例 {typeof(T).Name} 已初始化");
        }

        /// <summary>
        /// 激活方法，当单例被注册到SingletonModule时调用。
        /// 子类可重写此方法以实现自定义激活逻辑。
        /// </summary>
        public virtual void Active()
        {
            Log.Info($"单例 {typeof(T).Name} 已激活");
        }

        /// <summary>
        /// 释放方法，用于清理单例实例。
        /// 调用此方法将从SingletonModule中注销实例并将引用设为null。
        /// 子类可重写此方法以实现自定义释放逻辑。
        /// </summary>
        public virtual void Release()
        {
            Log.Info($"单例 {typeof(T).Name} 准备释放");

            if (_instance != null)
            {
                OnRelease();
                SingletonModule.Release(_instance);
                _instance = null;
            }
        }

        /// <summary>
        /// 在实例被释放前调用，用于执行额外的清理工作
        /// 子类可重写此方法以实现自定义释放前逻辑
        /// </summary>
        protected virtual void OnRelease()
        {
            // 默认为空实现，子类可根据需求重写
        }
    }
}