using Cysharp.Threading.Tasks;
using EF.Common;

namespace GameLogic
{
    /// <summary>
    /// 子弹模块接口。
    /// 负责子弹的生成、对象池管理和生命周期控制。
    /// 子弹通用于玩家和敌人双方。
    /// </summary>
    public interface IBulletModule : IEFManager
    {
        /// <summary>
        /// 异步初始化模块，加载预制体并创建对象池。
        /// 必须在 Configure 之后、使用 Fire 之前调用。
        /// 调用方应 await 此方法以确保初始化完成。
        /// </summary>
        UniTask InitializeAsync();

        /// <summary>
        /// 配置子弹预制体资源名称。
        /// </summary>
        /// <param name="bulletPrefabName">子弹预制体的资源名称。</param>
        void Configure(string bulletPrefabName);

        /// <summary>
        /// 发射一颗子弹。
        /// </summary>
        /// <param name="data">子弹生成参数。</param>
        void Fire(BulletData data);
    }
}
