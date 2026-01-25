using EF.Common;

namespace GameLogic
{
    /// <summary>
    /// 飞机大战：敌机模块接口。
    /// 负责敌机生成与回收，并受 ModuleSystem 的 scope 生命周期管理。
    /// </summary>
    public interface IGameEnemyModule : IEFManager
    {
        /// <summary>
        /// 配置敌机刷怪参数。
        /// 注意：模块内部不会硬编码敌机的资源名/实体组名，这些参数由外部传入。
        /// </summary>
        /// <param name="enemyEntityAssetName">敌机实体资源名。</param>
        /// <param name="enemyEntityGroupName">敌机实体组名。</param>
        /// <param name="spawnIntervalSeconds">刷怪间隔（秒）。</param>
        void Configure(string enemyEntityAssetName, string enemyEntityGroupName, float spawnIntervalSeconds = 1f);

        /// <summary>
        /// 开始刷怪。
        /// </summary>
        void StartSpawning();

        /// <summary>
        /// 停止刷怪。
        /// </summary>
        void StopSpawning();
    }
}

