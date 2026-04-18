using System;
using EF.Common;

namespace GameLogic
{
    /// <summary>
    /// 体力模块接口，负责管理主流程体力值。
    /// </summary>
    public interface IEnergyModule : IEFManager
    {
        /// <summary>
        /// 当前体力值。
        /// </summary>
        int CurrentEnergy { get; }

        /// <summary>
        /// 体力上限。
        /// </summary>
        int MaxEnergy { get; }

        /// <summary>
        /// 自动恢复间隔（秒）。
        /// </summary>
        int RecoveryIntervalSeconds { get; }

        /// <summary>
        /// 距下次自动恢复剩余秒数。体力已满时返回 0。
        /// </summary>
        float TimeToNextRecovery { get; }

        /// <summary>
        /// 当前是否正在自动恢复中（体力未满时为 true）。
        /// </summary>
        bool IsRecovering { get; }

        /// <summary>
        /// 体力变化事件。
        /// </summary>
        event Action<int, int> OnEnergyChanged;

        /// <summary>
        /// 是否可消耗指定体力。
        /// </summary>
        bool CanConsume(int amount);

        /// <summary>
        /// 尝试消耗体力。
        /// </summary>
        bool TryConsume(int amount);

        /// <summary>
        /// 恢复体力。
        /// </summary>
        void Recover(int amount);
    }
}
