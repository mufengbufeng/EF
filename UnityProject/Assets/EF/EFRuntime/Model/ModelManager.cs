using System;
using System.Collections.Generic;
using EF.Common;

namespace EF.Model
{
    /// <summary>
    /// 全局模型管理器，负责模型的注册、检索与生命周期管理。
    /// </summary>
    public sealed class ModelManager : AEFManager
    {
        private readonly Dictionary<Type, IModelInternal> _models = new();
        private readonly Dictionary<Type, Type> _viewToModel = new();
        private readonly List<IModelInternal> _updateOrder = new();
        private readonly object _syncRoot = new();

        /// <summary>
        /// 当前已注册的模型数量。
        /// </summary>
        public int ModelCount
        {
            get
            {
                lock (_syncRoot)
                {
                    return _models.Count;
                }
            }
        }

        /// <summary>
        /// 注册一个模型实例。
        /// </summary>
        /// <typeparam name="TModel">模型类型。</typeparam>
        /// <param name="model">模型实例。</param>
        public TModel Register<TModel>(TModel model)
            where TModel : ModelBase
        {
            if (model == null)
            {
                throw new ArgumentNullException(nameof(model));
            }

            IModelInternal internalModel = model;

            lock (_syncRoot)
            {
                Type concreteType = model.GetType();
                if (_models.ContainsKey(concreteType))
                {
                    throw new InvalidOperationException($"模型 {concreteType.FullName} 已经注册，不能重复注册。");
                }

                Type viewType = internalModel.ViewType ?? throw new InvalidOperationException($"模型 {concreteType.FullName} 未提供有效的视图类型。");
                if (_viewToModel.ContainsKey(viewType))
                {
                    throw new InvalidOperationException($"视图类型 {viewType.FullName} 已被模型 {_viewToModel[viewType].FullName} 占用。");
                }

                internalModel.Initialize(this);
                object viewInstance = internalModel.ViewInstance ?? throw new InvalidOperationException($"模型 {concreteType.FullName} 无法创建视图实例。");

                _models.Add(concreteType, internalModel);
                _viewToModel.Add(viewType, concreteType);
                _updateOrder.Add(internalModel);
            }

            return model;
        }

        /// <summary>
        /// 注册一个模型实例并返回对应视图。
        /// </summary>
        public TView Register<TModel, TView>(TModel model)
            where TModel : ModelBase<TView>
            where TView : class
        {
            Register(model);
            return (TView)((IModelInternal)model).ViewInstance;
        }

        /// <summary>
        /// 通过类型自动创建并注册模型。
        /// </summary>
        public TModel Register<TModel>()
            where TModel : ModelBase, new()
        {
            return Register(new TModel());
        }

        /// <summary>
        /// 通过类型自动创建并注册模型，并返回对应视图。
        /// </summary>
        public TView Register<TModel, TView>()
            where TModel : ModelBase<TView>, new()
            where TView : class
        {
            TModel model = Register(new TModel());
            return (TView)((IModelInternal)model).ViewInstance;
        }

        /// <summary>
        /// 注销某个模型。
        /// </summary>
        public bool Unregister<TModel>() where TModel : ModelBase
        {
            return Unregister(typeof(TModel));
        }

        /// <summary>
        /// 注销指定类型的模型。
        /// </summary>
        public bool Unregister(Type modelType)
        {
            if (modelType == null)
            {
                throw new ArgumentNullException(nameof(modelType));
            }

            IModelInternal removed = null;

            lock (_syncRoot)
            {
                if (!_models.TryGetValue(modelType, out IModelInternal model))
                {
                    return false;
                }

                removed = model;
                _models.Remove(modelType);
                _viewToModel.Remove(model.ViewType);
                _updateOrder.Remove(model);
            }

            removed.Shutdown();
            return true;
        }

        /// <summary>
        /// 根据视图类型注销模型。
        /// </summary>
        public bool UnregisterByView<TView>() where TView : class
        {
            return UnregisterByView(typeof(TView));
        }

        /// <summary>
        /// 根据视图类型注销模型。
        /// </summary>
        public bool UnregisterByView(Type viewType)
        {
            if (viewType == null)
            {
                throw new ArgumentNullException(nameof(viewType));
            }

            Type modelType;

            lock (_syncRoot)
            {
                if (!_viewToModel.TryGetValue(viewType, out modelType))
                {
                    return false;
                }
            }

            return Unregister(modelType);
        }

        /// <summary>
        /// 获取某个模型实例。
        /// </summary>
        public TModel GetModel<TModel>() where TModel : ModelBase
        {
            if (TryGetModel(out TModel model))
            {
                return model;
            }

            throw new KeyNotFoundException($"模型 {typeof(TModel).FullName} 尚未注册。");
        }

        /// <summary>
        /// 获取只读视图。
        /// </summary>
        public TView Get<TView>() where TView : class
        {
            if (TryGet(out TView view))
            {
                return view;
            }

            throw new KeyNotFoundException($"视图 {typeof(TView).FullName} 尚未注册。");
        }

        /// <summary>
        /// 尝试获取模型实例。
        /// </summary>
        public bool TryGetModel<TModel>(out TModel model) where TModel : ModelBase
        {
            lock (_syncRoot)
            {
                if (_models.TryGetValue(typeof(TModel), out IModelInternal internalModel))
                {
                    model = (TModel)internalModel;
                    return true;
                }
            }

            model = null;
            return false;
        }

        /// <summary>
        /// 尝试获取只读视图。
        /// </summary>
        public bool TryGet<TView>(out TView view) where TView : class
        {
            lock (_syncRoot)
            {
                if (_viewToModel.TryGetValue(typeof(TView), out Type modelType) &&
                    _models.TryGetValue(modelType, out IModelInternal model))
                {
                    view = (TView)model.ViewInstance;
                    return true;
                }
            }

            view = null;
            return false;
        }

        /// <summary>
        /// 判断模型是否已经注册。
        /// </summary>
        public bool HasModel<TModel>() where TModel : ModelBase
        {
            lock (_syncRoot)
            {
                return _models.ContainsKey(typeof(TModel));
            }
        }

        /// <summary>
        /// 清空并关闭所有模型。
        /// </summary>
        public override void Shutdown()
        {
            IModelInternal[] snapshot;

            lock (_syncRoot)
            {
                if (_updateOrder.Count == 0)
                {
                    return;
                }

                snapshot = _updateOrder.ToArray();
                _updateOrder.Clear();
                _models.Clear();
                _viewToModel.Clear();
            }

            for (int index = snapshot.Length - 1; index >= 0; index--)
            {
                snapshot[index].Shutdown();
            }
        }

        /// <summary>
        /// 更新所有已注册模型。
        /// </summary>
        public override void Update(float elapseSeconds, float realElapseSeconds)
        {
            IModelInternal[] snapshot;

            lock (_syncRoot)
            {
                if (_updateOrder.Count == 0)
                {
                    return;
                }

                snapshot = _updateOrder.ToArray();
            }

            for (int i = 0; i < snapshot.Length; i++)
            {
                snapshot[i].Update(elapseSeconds, realElapseSeconds);
            }
        }
    }
}
