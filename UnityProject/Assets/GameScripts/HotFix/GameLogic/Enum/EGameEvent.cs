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

        /// <summary>
        /// 体力变化事件
        /// </summary>
        EnergyChangedEvent = 3,

        /// <summary>
        /// 体力不足事件
        /// </summary>
        EnergyNotEnoughEvent = 4,

        /// <summary>
        /// 关卡进入事件
        /// </summary>
        LevelEnterEvent = 5,

        /// <summary>
        /// 关卡开始事件
        /// </summary>
        LevelStartEvent = 6,

        /// <summary>
        /// 关卡完成事件
        /// </summary>
        LevelCompleteEvent = 7,

        /// <summary>
        /// 关卡失败事件
        /// </summary>
        LevelFailedEvent = 8,

        /// <summary>
        /// 关卡解锁事件
        /// </summary>
        LevelUnlockedEvent = 9,
    }
}