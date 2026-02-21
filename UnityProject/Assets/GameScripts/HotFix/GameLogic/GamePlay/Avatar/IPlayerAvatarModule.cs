using Cysharp.Threading.Tasks;
using EF.Common;
using UnityEngine;

namespace GameLogic
{
    /// <summary>
    /// 玩家飞机模块接口。
    /// 负责玩家实体的生成、配置与回收。
    /// </summary>
    public interface IPlayerAvatarModule : IEFManager
    {
        /// <summary>
        /// 配置玩家实体参数。
        /// </summary>
        /// <param name="avatarPrefabName">玩家预制体资源名称。</param>
        /// <param name="avatarGroupName">玩家实体组名称。</param>
        /// <param name="attackInterval">自动攻击间隔（秒）。</param>
        /// <param name="bulletSpeed">默认子弹速度。</param>
        /// <param name="dragBoundaryPadding">拖拽边界内边距（世界单位）。</param>
        void Configure(
            string avatarPrefabName,
            string avatarGroupName,
            float attackInterval,
            float bulletSpeed,
            float dragBoundaryPadding);

        /// <summary>
        /// 设置玩家出生锚点。
        /// </summary>
        /// <param name="spawnAnchor">出生锚点（可为空）。</param>
        void SetSpawnAnchor(Transform spawnAnchor);

        /// <summary>
        /// 异步初始化玩家模块并生成玩家实体。
        /// </summary>
        UniTask InitializeAsync();
    }
}
