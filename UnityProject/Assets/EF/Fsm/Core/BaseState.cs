using UnityEngine;

namespace EF
{
    /// <summary>
    /// 状态基类，提供IState接口的默认实现和通用功能
    /// </summary>
    public abstract class BaseState : IState
    {
        /// <summary>
        /// 此状态所属的FSM
        /// </summary>
        protected FiniteStateMachine fsm;

        /// <summary>
        /// 状态拥有者/上下文对象
        /// </summary>
        protected object owner;

        /// <summary>
        /// 构造函数
        /// </summary>
        /// <param name="fsm">所属的FSM</param>
        public BaseState(FiniteStateMachine fsm)
        {
            this.fsm = fsm;
            this.owner = fsm?.Owner;
        }

        /// <summary>
        /// 进入状态时调用
        /// </summary>
        public virtual void Enter()
        {
            Debug.Log($"进入 {GetType().Name} 状态");
        }

        /// <summary>
        /// 状态更新时调用
        /// </summary>
        public virtual void Update()
        {
            // 基类中为空实现，子类根据需要重写
        }

        /// <summary>
        /// 退出状态时调用
        /// </summary>
        public virtual void Exit()
        {
            Debug.Log($"退出 {GetType().Name} 状态");
        }

        /// <summary>
        /// 切换到指定类型的状态
        /// </summary>
        /// <typeparam name="T">目标状态类型</typeparam>
        protected void ChangeState<T>() where T : IState
        {
            fsm?.ChangeState<T>();
        }
    }
}