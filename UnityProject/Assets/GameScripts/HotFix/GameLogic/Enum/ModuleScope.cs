namespace GameLogic
{
    /// <summary>
    /// 模块作用域标签。
    /// 用于将通过 <see cref="EF.Common.ModuleSystem"/> 注册的模块按阶段分组，并在阶段退出时按 scope 清理。
    /// </summary>
    public struct ModuleScope
    {
        /// <summary>
        /// 全局作用域（与框架默认 scope=0 一致）。
        /// </summary>
        public const int GLOBAL = 0;
        /// <summary>
        /// GamePlay 作用域（进入 GamePlay 时注册的模块应使用该 scope）。
        /// </summary>
        public const int GAME_PLAY = 1;
    }
}
