using UnityEngine;

namespace EF
{
    /// <summary>
    /// 单例接口，定义所有单例类必须实现的方法
    /// </summary>
    public interface ISingleton
    {
        /// <summary>
        /// 激活单例
        /// </summary>
        void Active();

        /// <summary>
        /// 释放单例实例
        /// </summary>
        void Release();
    }
}