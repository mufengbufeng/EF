using UnityEngine;

namespace EF
{
    /// <summary>
    /// 状态接口，定义状态的基本行为
    /// </summary>
    public interface IState
    {
        /// <summary>
        /// 当进入此状态时调用
        /// </summary>
        void Enter();

        /// <summary>
        /// 当此状态激活时，每帧调用
        /// </summary>
        void Update();

        /// <summary>
        /// 当退出此状态时调用
        /// </summary>
        void Exit();
    }
}