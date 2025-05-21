using System;
using System.Collections.Generic;
using UnityEngine;

namespace EF
{
    /// <summary>
    /// 有限状态机，管理状态和状态转换
    /// </summary>
    public class FiniteStateMachine
    {
        /// <summary>
        /// 当前激活的状态
        /// </summary>
        private IState currentState;

        /// <summary>
        /// 状态字典，存储FSM拥有的所有状态实例
        /// </summary>
        private Dictionary<Type, IState> states = new Dictionary<Type, IState>();

        /// <summary>
        /// 状态机拥有者，可以是任何对象
        /// </summary>
        public object Owner { get; private set; }

        /// <summary>
        /// 构造函数
        /// </summary>
        /// <param name="owner">状态机拥有者</param>
        public FiniteStateMachine(object owner = null)
        {
            Owner = owner;
        }

        /// <summary>
        /// 向FSM添加一个状态
        /// </summary>
        /// <param name="state">状态实例</param>
        public void AddState(IState state)
        {
            Type stateType = state.GetType();
            if (!states.ContainsKey(stateType))
            {
                states.Add(stateType, state);
            }
            else
            {
                Debug.LogWarning($"State {stateType.Name} already exists in this FSM.");
            }
        }

        /// <summary>
        /// 切换到指定类型的状态
        /// </summary>
        /// <typeparam name="T">目标状态类型</typeparam>
        public void ChangeState<T>() where T : IState
        {
            Type targetType = typeof(T);

            // 如果目标状态不存在，则输出警告并返回
            if (!states.ContainsKey(targetType))
            {
                Debug.LogWarning($"Cannot change to state {targetType.Name} as it hasn't been added to the FSM.");
                return;
            }

            // 如果当前已有状态，先退出当前状态
            currentState?.Exit();

            // 切换到新状态
            currentState = states[targetType];

            // 进入新状态
            currentState.Enter();
        }

        /// <summary>
        /// 更新当前状态
        /// </summary>
        public void Update()
        {
            // 如果当前状态存在，调用其Update方法
            currentState?.Update();
        }

        /// <summary>
        /// 启动FSM并进入初始状态
        /// </summary>
        /// <typeparam name="T">初始状态类型</typeparam>
        public void Start<T>() where T : IState
        {
            // 确保初始状态已经被添加
            if (!states.ContainsKey(typeof(T)))
            {
                Debug.LogError($"Cannot start FSM with state {typeof(T).Name} as it hasn't been added.");
                return;
            }

            // 设置当前状态并调用Enter
            currentState = states[typeof(T)];
            currentState.Enter();
        }

        /// <summary>
        /// 获取当前状态类型
        /// </summary>
        /// <returns>当前状态的类型，如果没有当前状态则返回null</returns>
        public Type GetCurrentStateType()
        {
            return currentState?.GetType();
        }

        /// <summary>
        /// 检查当前状态是否为指定类型
        /// </summary>
        /// <typeparam name="T">要检查的状态类型</typeparam>
        /// <returns>如果当前状态是指定类型则返回true，否则返回false</returns>
        public bool IsInState<T>() where T : IState
        {
            return currentState != null && currentState.GetType() == typeof(T);
        }
    }
}