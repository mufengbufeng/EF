using System;
using System.Threading;
using Cysharp.Threading.Tasks;
using EF.Model;

namespace EF.UI
{
    /// <summary>
    /// UI Controller 抽象基类，负责协调 Model 和 View。
    /// Controller 通过 ModelManager 访问数据 Model，持有 View 的引用。
    /// </summary>
    public abstract class UIController : IDisposable
    {
        private bool _isDisposed;

        /// <summary>
        /// 当前绑定的 View。
        /// </summary>
        protected internal UIView View { get; private set; }

        /// <summary>
        /// 当前实例的运行上下文。
        /// </summary>
        protected internal UIRuntimeContext Context { get; private set; }

        /// <summary>
        /// 获取 ModelManager 中注册的数据 Model。
        /// </summary>
        protected TModel GetModel<TModel>() where TModel : ModelBase
        {
            return Context.ModelManager.GetModel<TModel>();
        }

        /// <summary>
        /// 尝试获取 ModelManager 中注册的数据 Model。
        /// </summary>
        protected bool TryGetModel<TModel>(out TModel model) where TModel : ModelBase
        {
            return Context.ModelManager.TryGetModel(out model);
        }

        /// <summary>
        /// 获取强类型 View。
        /// </summary>
        protected TView GetView<TView>() where TView : UIView
        {
            return View as TView;
        }

        /// <summary>
        /// 初始化 Controller，仅在实例创建时调用一次。
        /// </summary>
        protected virtual void OnInitialize()
        {
        }

        /// <summary>
        /// 打开界面前的异步准备阶段，可用于加载数据。
        /// </summary>
        protected virtual UniTask OnPrepareAsync(object userData, CancellationToken cancellationToken)
        {
            return UniTask.CompletedTask;
        }

        /// <summary>
        /// 进入界面时调用，可在此进行事件订阅等操作。
        /// </summary>
        protected virtual void OnEnter(object userData)
        {
        }

        /// <summary>
        /// 界面需要刷新显示数据时调用。
        /// </summary>
        protected virtual void OnRefresh(object userData)
        {
        }

        /// <summary>
        /// 界面关闭时调用，可在此取消订阅或保存状态。
        /// </summary>
        protected virtual void OnExit()
        {
        }

        /// <summary>
        /// Controller 被释放前调用，派生类可在此清理资源。
        /// </summary>
        protected virtual void OnRelease()
        {
        }

        /// <summary>
        /// 每帧更新回调，仅在 UI 处于打开状态时触发。
        /// </summary>
        protected virtual void OnUpdate(float elapseSeconds, float realElapseSeconds)
        {
        }

        /// <summary>
        /// 派生类可重写的释放操作。
        /// </summary>
        protected virtual void OnDispose()
        {
        }

        internal void InternalInitialize(UIView view, UIRuntimeContext context)
        {
            View = view ?? throw new ArgumentNullException(nameof(view));
            Context = context ?? throw new ArgumentNullException(nameof(context));
            OnInitialize();
        }

        internal UniTask InternalPrepareAsync(object userData, CancellationToken cancellationToken)
        {
            return OnPrepareAsync(userData, cancellationToken);
        }

        internal void InternalEnter(object userData)
        {
            OnEnter(userData);
        }

        internal void InternalRefresh(object userData)
        {
            OnRefresh(userData);
        }

        internal void InternalExit()
        {
            OnExit();
        }

        internal void InternalRelease()
        {
            OnRelease();
        }

        internal void InternalUpdate(float elapseSeconds, float realElapseSeconds)
        {
            OnUpdate(elapseSeconds, realElapseSeconds);
        }

        public void Dispose()
        {
            if (_isDisposed)
            {
                return;
            }

            _isDisposed = true;
            OnDispose();
            View = null;
            Context = null;
            GC.SuppressFinalize(this);
        }
    }
}
