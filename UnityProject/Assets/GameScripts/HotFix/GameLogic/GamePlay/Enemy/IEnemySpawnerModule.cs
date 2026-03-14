using EF.Common;
using UnityEngine;

namespace GameLogic
{
    /// <summary>
    /// 敌人生成器模块接口。
    /// 负责敌人的波次生成、数量控制和生成速率调节。
    /// </summary>
    public interface IEnemySpawnerModule : IEFManager
    {
        /// <summary>
        /// 初始化模块，创建实体组。
        /// </summary>
        void Initialize();

        /// <summary>
        /// 配置敌人生成参数。
        /// </summary>
        /// <param name="enemyPrefabName">敌人预制体资源名称。</param>
        /// <param name="spawnInterval">生成间隔（秒）。</param>
        /// <param name="maxEnemyCount">同屏最大敌人数量。</param>
        void Configure(string enemyPrefabName, float spawnInterval, int maxEnemyCount);

        /// <summary>
        /// 设置生成区域的锚点 Transform。
        /// 敌人将在该锚点的 X 范围内随机生成。
        /// </summary>
        /// <param name="spawnAreaCenter">生成区域中心锚点。</param>
        /// <param name="spawnAreaHalfWidth">生成区域半宽度。</param>
        void SetSpawnArea(Transform spawnAreaCenter, float spawnAreaHalfWidth);

        /// <summary>
        /// 设置生成间隔。
        /// </summary>
        /// <param name="interval">新的生成间隔（秒）。</param>
        void SetSpawnInterval(float interval);

        /// <summary>
        /// 设置同屏最大敌人数量。
        /// </summary>
        /// <param name="maxCount">新的最大数量。</param>
        void SetMaxEnemyCount(int maxCount);
    }
}
