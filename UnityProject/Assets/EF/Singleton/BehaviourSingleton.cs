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
        /// 标记单例是否正在初始化过程中，避免重复初始化
        /// </summary>
        protected static bool _isInitializing = false;

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
                // 如果已经有实例，直接返回
                if (_instance != null)
                {
                    return _instance;
                }

                // 检测是否正在初始化中，防止在Awake或其他初始化过程中循环引用
                if (_isInitializing)
                {
                    Log.Warning($"检测到 {typeof(T).Name} 在初始化过程中递归访问Instance属性，可能导致多实例问题");
                    return null;
                }

                _isInitializing = true;

                try
                {
                    // 先尝试从SingletonModule获取
                    _instance = SingletonModule.Get<T>();

                    if (_instance == null)
                    {
                        Log.Info($"创建 {typeof(T).Name} 单例实例");
                        // 创建新实例
                        GameObject singletonObject = new GameObject($"{typeof(T).Name} (Singleton)");
                        _instance = singletonObject.AddComponent<T>();
                        // 注意：AddComponent会触发Awake，此时_isInitializing为true
                    }

                    // 确保实例被初始化和注册
                    if (_instance != null && !SingletonModule.Contains<T>())
                    {
                        _instance.Init();
                        SingletonModule.Register(_instance);
                    }
                }
                finally
                {
                    _isInitializing = false;
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

            // 如果当前没有实例，则进行初始化
            if (_instance == null)
            {
                _instance = this as T;

                // 如果需要，设置为不随场景切换而销毁
                if (_dontDestroyOnLoad && transform.parent == null)
                {
                    DontDestroyOnLoad(gameObject);
                }

                // 仅当不是通过Instance属性创建的实例才执行初始化
                // 因为Instance属性中创建的实例会直接调用Init和Register
                if (!_isInitializing && !SingletonModule.Contains<T>())
                {
                    Init();
                    SingletonModule.Register(this);
                }
            }
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