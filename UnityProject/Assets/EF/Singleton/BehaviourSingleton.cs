using UnityEngine;

namespace EF
{
    /// <summary>
    /// MonoBehaviour的单例模式基类，适用于需要挂载到游戏对象的组件
    /// </summary>
    /// <typeparam name="T">子类类型</typeparam>
    public abstract class BehaviourSingleton<T> : MonoBehaviour, ISingleton where T : BehaviourSingleton<T>
    {
        /// <summary>
        /// 单例实例
        /// </summary>
        protected static T _instance = null;

        /// <summary>
        /// 是否在切换场景时保留此对象
        /// </summary>
        [SerializeField]
        protected bool _dontDestroyOnLoad = true;

        /// <summary>
        /// 在已存在实例的情况下销毁新创建的实例
        /// </summary>
        [SerializeField]
        protected bool _destroyDuplicate = true;

        /// <summary>
        /// 获取单例实例
        /// </summary>
        public static T Instance
        {
            get
            {
                if (_instance == null)
                {
                    // 尝试在场景中查找该类型的实例
                    _instance = FindObjectOfType<T>();

                    // 如果场景中不存在，则创建一个新的游戏对象并添加组件
                    if (_instance == null)
                    {
                        GameObject singletonObject = new GameObject($"{typeof(T).Name} (Singleton)");
                        _instance = singletonObject.AddComponent<T>();
                    }

                    // 初始化实例
                    _instance.Init();
                    SingletonModule.Register(_instance);
                }

                return _instance;
            }
        }

        /// <summary>
        /// 检查单例实例是否有效
        /// </summary>
        public static bool IsValid => _instance != null;

        protected virtual void Awake()
        {
            // 检查是否已经存在实例
            if (_instance != null && _instance != this)
            {
                // 如果已经存在，并且设置了销毁重复实例，则销毁当前对象
                if (_destroyDuplicate)
                {
                    Log.Warning($"发现多个 {typeof(T).Name} 的实例，正在销毁重复的实例。");
                    Destroy(gameObject);
                }
                return;
            }

            // 如果这是第一个实例，进行初始化
            _instance = this as T;

            // 如果需要，设置为不随场景切换而销毁
            if (_dontDestroyOnLoad && transform.parent == null)
            {
                DontDestroyOnLoad(gameObject);
            }

            // 注册到单例系统
            // SingletonModule.Register(_instance);
        }

        /// <summary>
        /// 初始化方法，在实例首次创建时调用
        /// 子类可重写此方法以实现自定义初始化逻辑
        /// </summary>
        protected virtual void Init()
        {
            Log.Info($"MonoBehaviour单例 {typeof(T).Name} 已初始化");
        }

        /// <summary>
        /// 激活方法，当单例被注册到SingletonModule时调用
        /// 子类可重写此方法以实现自定义激活逻辑
        /// </summary>
        public virtual void Active()
        {
            Log.Info($"MonoBehaviour单例 {typeof(T).Name} 已激活");
        }

        /// <summary>
        /// 释放方法，用于清理单例实例
        /// 调用此方法将从SingletonModule中注销实例并销毁游戏对象
        /// </summary>
        public virtual void Release()
        {
            Log.Info($"MonoBehaviour单例 {typeof(T).Name} 准备释放");

            if (_instance != null)
            {
                OnRelease();
                SingletonModule.Release(_instance);

                // MonoBehaviour单例需要销毁游戏对象
                if (gameObject != null)
                {
                    Destroy(gameObject);
                }

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

        /// <summary>
        /// 当游戏对象被销毁时调用，确保从SingletonModule中正确移除
        /// </summary>
        protected virtual void OnDestroy()
        {
            // 只有当前实例是单例实例时才执行释放逻辑
            if (_instance == this)
            {
                OnRelease();
                SingletonModule.Release(this);
                _instance = null;
                Log.Info($"MonoBehaviour单例 {typeof(T).Name} 已销毁");
            }
        }
    }
}