using EF.Common;

namespace GameLogic
{
    /// <summary>
    /// 体力模块接口。
    /// </summary>
    public interface IEnergyModule : IEFManager
    {
        /// <summary>
        /// 当前体力值。
        /// </summary>
        int CurrentEnergy { get; }

        /// <summary>
        /// 最大体力值。
        /// </summary>
        int MaxEnergy { get; }

        /// <summary>
        /// 每点体力恢复秒数。
        /// </summary>
        int RecoverRateSeconds { get; }

        /// <summary>
        /// 默认每关体力消耗。
        /// </summary>
        int CostPerLevel { get; }

        /// <summary>
        /// 判断当前体力是否足够消耗。
        /// </summary>
        bool CanConsume(int cost);

        /// <summary>
        /// 消耗体力，成功返回 true。
        /// </summary>
        bool Consume(int cost);
    }
}
