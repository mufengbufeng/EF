namespace GameLogic
{
    /// <summary>
    /// 生命值接口。
    /// 实现此接口的实体可以接受伤害和检查死亡状态。
    /// </summary>
    public interface IHealth
    {
        /// <summary>
        /// 当前生命值。
        /// </summary>
        float CurrentHealth { get; }

        /// <summary>
        /// 最大生命值。
        /// </summary>
        float MaxHealth { get; }

        /// <summary>
        /// 是否已死亡。
        /// </summary>
        bool IsDead { get; }

        /// <summary>
        /// 接受伤害。
        /// </summary>
        /// <param name="damage">伤害值。</param>
        void TakeDamage(float damage);
    }
}
