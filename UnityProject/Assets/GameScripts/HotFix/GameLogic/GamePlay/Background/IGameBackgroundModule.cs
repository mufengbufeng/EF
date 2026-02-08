using Cysharp.Threading.Tasks;
using EF.Common;
using UnityEngine;

namespace GameLogic
{
    /// <summary>
    /// 飞机大战：背景模块接口。
    /// 负责背景加载、滚动与可选切换。
    /// </summary>
    public interface IGameBackgroundModule : IEFManager
    {
        /// <summary>
        /// 配置背景资源与滚动参数。
        /// </summary>
        /// <param name="prefabName">背景预制体资源名。</param>
        /// <param name="speed">滚动速度（单位：世界坐标/秒，正值向下，负值向上）。</param>
        /// <param name="autoCloneIfSingle">仅有一个背景片段时是否自动克隆。</param>
        void Configure(string prefabName, float speed = 1f, bool autoCloneIfSingle = true);

        /// <summary>
        /// 设置背景挂载根节点。
        /// </summary>
        /// <param name="backgroundRoot">背景根节点（为空时挂载到场景根节点）。</param>
        void SetBackgroundRoot(Transform backgroundRoot);

        /// <summary>
        /// 加载并初始化背景。
        /// </summary>
        UniTask LoadAsync();

        /// <summary>
        /// 设置滚动速度。
        /// </summary>
        void SetSpeed(float speed);

        /// <summary>
        /// 切换背景 Sprite 并重建布局。
        /// </summary>
        void SetSprite(Sprite sprite);

        /// <summary>
        /// 设置目标相机（为空时使用 MainCamera）。
        /// </summary>
        void SetTargetCamera(Camera camera);
    }
}
