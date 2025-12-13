using System;
using System.Collections.Generic;
using System.Runtime.CompilerServices;

namespace EF.Common
{
    /// <summary>
    /// 框架模块系统：统一负责管理器的注册、更新分发与生命周期。
    /// </summary>
    public static class ModuleSystem
    {
        private static readonly Dictionary<Type, IEFManager> _services = new();
        private static readonly Dictionary<IEFManager, HashSet<Type>> _aliases = new(ReferenceComparer.Instance);
        private static readonly List<IEFManager> _updateOrder = new();
        private static readonly object _syncRoot = new();

        /// <summary>
        /// 已注册的服务绑定数量。
        /// </summary>
        public static int RegisteredServiceCount
        {
            get
            {
                lock (_syncRoot)
                {
                    return _services.Count;
                }
            }
        }

        /// <summary>
        /// 管理中的唯一模块实例数量。
        /// </summary>
        public static int ModuleCount
        {
            get
            {
                lock (_syncRoot)
                {
                    return _aliases.Count;
                }
            }
        }

        /// <summary>
        /// 将模块实例注册为指定的服务类型。
        /// </summary>
        /// <typeparam name="TService">需要绑定的服务接口或基类。</typeparam>
        /// <param name="module">模块实例。</param>
        /// <param name="replace">
        /// 若为 <c>true</c> 且服务已绑定其他实例，则会先注销旧实例（包含全部别名）再注册新实例。
        /// </param>
        /// <param name="exposeConcreteType">
        /// 若为 <c>true</c>，同时使用模块的具体类型作为别名，方便按具体类型检索。
        /// </param>
        public static void Register<TService>(TService module, bool replace = false, bool exposeConcreteType = true)
            where TService : class, IEFManager
        {
            Register(typeof(TService), module, replace, exposeConcreteType);
        }

        /// <summary>
        /// 将模块实例注册为指定的服务类型。
        /// </summary>
        /// <param name="serviceType">需要绑定的服务接口或基类。</param>
        /// <param name="module">模块实例。</param>
        /// <param name="replace">
        /// 若为 <c>true</c> 且服务已绑定其他实例，则会先注销旧实例（包含全部别名）再注册新实例。
        /// </param>
        /// <param name="exposeConcreteType">
        /// 若为 <c>true</c>，同时使用模块的具体类型作为别名，方便按具体类型检索。
        /// </param>
        public static void Register(Type serviceType, IEFManager module, bool replace = false, bool exposeConcreteType = true)
        {
            if (serviceType == null)
            {
                throw new ArgumentNullException(nameof(serviceType));
            }

            if (module == null)
            {
                throw new ArgumentNullException(nameof(module));
            }

            Type moduleType = module.GetType();
            if (!serviceType.IsAssignableFrom(moduleType))
            {
                throw new ArgumentException($"模块实例 {moduleType.FullName} 无法绑定到服务类型 {serviceType.FullName}。", nameof(module));
            }

            List<IEFManager> shutdownList = null;
            bool serviceAlreadyRegistered = false;
            lock (_syncRoot)
            {
                if (_services.TryGetValue(serviceType, out IEFManager existing))
                {
                    if (!ReferenceEquals(existing, module))
                    {
                        if (!replace)
                        {
                            throw new InvalidOperationException($"服务类型 {serviceType.FullName} 已绑定到模块 {existing.GetType().FullName}。");
                        }

                        QueueForShutdown(RemoveModuleInternal(existing));
                    }
                    else
                    {
                        serviceAlreadyRegistered = true;
                    }
                }

                if (!serviceAlreadyRegistered)
                {
                    AddMappingInternal(serviceType, module);
                }

                if (exposeConcreteType)
                {
                    Type concreteType = moduleType;
                    if (!ReferenceEquals(concreteType, serviceType))
                    {
                        bool concreteAlreadyRegistered = false;
                        if (_services.TryGetValue(concreteType, out IEFManager concreteExisting))
                        {
                            if (!ReferenceEquals(concreteExisting, module))
                            {
                                if (!replace)
                                {
                                    throw new InvalidOperationException($"类型 {concreteType.FullName} 已绑定到模块 {concreteExisting.GetType().FullName}。");
                                }

                                QueueForShutdown(RemoveModuleInternal(concreteExisting));
                            }
                            else
                            {
                                concreteAlreadyRegistered = true;
                            }
                        }

                        if (!concreteAlreadyRegistered)
                        {
                            AddMappingInternal(concreteType, module);
                        }
                    }
                }
            }

            ShutdownModulesIfNeeded(shutdownList);

            void QueueForShutdown(IEFManager candidate)
            {
                if (candidate == null)
                {
                    return;
                }

                shutdownList ??= new List<IEFManager>();
                if (!shutdownList.Contains(candidate))
                {
                    shutdownList.Add(candidate);
                }
            }
        }

        /// <summary>
        /// 判断服务是否已经注册。
        /// </summary>
        public static bool Contains<TService>() where TService : class, IEFManager
        {
            return Contains(typeof(TService));
        }

        /// <summary>
        /// 判断服务是否已经注册。
        /// </summary>
        public static bool Contains(Type serviceType)
        {
            if (serviceType == null)
            {
                throw new ArgumentNullException(nameof(serviceType));
            }

            lock (_syncRoot)
            {
                return _services.ContainsKey(serviceType);
            }
        }

        /// <summary>
        /// 尝试获取指定服务对应的模块实例。
        /// </summary>
        public static bool TryGet<TService>(out TService module) where TService : class, IEFManager
        {
            lock (_syncRoot)
            {
                if (_services.TryGetValue(typeof(TService), out IEFManager instance))
                {
                    module = instance as TService;
                    return module != null;
                }
            }

            module = null;
            return false;
        }

        /// <summary>
        /// 获取指定服务对应的模块实例，若未注册则抛出异常。
        /// </summary>
        public static TService Get<TService>() where TService : class, IEFManager
        {
            if (TryGet<TService>(out TService module))
            {
                return module;
            }

            throw new InvalidOperationException($"服务类型 {typeof(TService).FullName} 尚未注册模块。");
        }

        /// <summary>
        /// 注销指定服务对应的模块，可选调用 <see cref="IEFManager.Shutdown"/>。
        /// </summary>
        /// <typeparam name="TService">服务接口或基类。</typeparam>
        /// <param name="shutdown">若为 <c>true</c>，在移除后调用模块的 Shutdown。</param>
        public static bool Unregister<TService>(bool shutdown = true) where TService : class, IEFManager
        {
            return Unregister(typeof(TService), shutdown);
        }

        /// <summary>
        /// 注销指定服务对应的模块，可选调用 <see cref="IEFManager.Shutdown"/>。
        /// </summary>
        /// <param name="serviceType">服务接口或基类。</param>
        /// <param name="shutdown">若为 <c>true</c>，在移除后调用模块的 Shutdown。</param>
        public static bool Unregister(Type serviceType, bool shutdown = true)
        {
            if (serviceType == null)
            {
                throw new ArgumentNullException(nameof(serviceType));
            }

            IEFManager removedModule;
            lock (_syncRoot)
            {
                if (!_services.TryGetValue(serviceType, out IEFManager existing))
                {
                    return false;
                }

                removedModule = RemoveModuleInternal(existing);
            }

            if (shutdown && removedModule != null)
            {
                removedModule.Shutdown();
            }

            return removedModule != null;
        }

        /// <summary>
        /// 按注册顺序依次调用所有模块的 <see cref="IEFManager.Update"/>。
        /// </summary>
        public static void Update(float elapseSeconds, float realElapseSeconds)
        {
            IEFManager[] snapshot;
            lock (_syncRoot)
            {
                if (_updateOrder.Count == 0)
                {
                    return;
                }

                snapshot = _updateOrder.ToArray();
            }

            for (int index = 0; index < snapshot.Length; index++)
            {
                IEFManager module = snapshot[index];
                module.Update(elapseSeconds, realElapseSeconds);
            }
        }

        /// <summary>
        /// 关闭全部模块，并清空模块系统。
        /// </summary>
        public static void ShutdownAll()
        {
            IEFManager[] snapshot;
            lock (_syncRoot)
            {
                if (_updateOrder.Count == 0)
                {
                    return;
                }

                snapshot = _updateOrder.ToArray();
                _updateOrder.Clear();
                _services.Clear();
                _aliases.Clear();
            }

            for (int index = snapshot.Length - 1; index >= 0; index--)
            {
                snapshot[index].Shutdown();
            }
        }

        private static void AddMappingInternal(Type serviceType, IEFManager module)
        {
            if (!_aliases.TryGetValue(module, out HashSet<Type> aliases))
            {
                aliases = new HashSet<Type>();
                _aliases[module] = aliases;
                _updateOrder.Add(module);
            }

            aliases.Add(serviceType);
            _services[serviceType] = module;
        }

        private static IEFManager RemoveModuleInternal(IEFManager module)
        {
            if (module == null)
            {
                return null;
            }

            if (!_aliases.TryGetValue(module, out HashSet<Type> aliases))
            {
                return null;
            }

            Type[] aliasSnapshot = new Type[aliases.Count];
            aliases.CopyTo(aliasSnapshot);
            for (int index = 0; index < aliasSnapshot.Length; index++)
            {
                _services.Remove(aliasSnapshot[index]);
            }

            _aliases.Remove(module);
            _updateOrder.Remove(module);
            return module;
        }

        private static void ShutdownModulesIfNeeded(List<IEFManager> shutdownList)
        {
            if (shutdownList == null || shutdownList.Count == 0)
            {
                return;
            }

            for (int index = 0; index < shutdownList.Count; index++)
            {
                shutdownList[index].Shutdown();
            }
        }

        private sealed class ReferenceComparer : IEqualityComparer<IEFManager>
        {
            public static readonly ReferenceComparer Instance = new();

            public bool Equals(IEFManager x, IEFManager y)
            {
                return ReferenceEquals(x, y);
            }

            public int GetHashCode(IEFManager obj)
            {
                return RuntimeHelpers.GetHashCode(obj);
            }
        }
    }
}
