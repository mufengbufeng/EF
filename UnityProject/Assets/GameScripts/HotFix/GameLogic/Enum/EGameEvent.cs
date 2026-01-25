using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace GameLogic
{
    public enum EGameEvent
    {
        /// <summary>
        /// 进入场景事件
        /// </summary>
        SceneEnterEvent = 1,

        /// <summary>
        /// 进入场景前事件
        /// </summary>
        BeforeSceneEnterEvent = 2,
    }
}