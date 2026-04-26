using EF.Event;

namespace GameLogic
{
    /// <summary>
    /// 场景进入事件数据
    /// </summary>
    [EventArgs]
    public readonly struct SceneEnterEvent
    {
        /// <summary>
        /// 场景名称
        /// </summary>
        public readonly string SceneName;

        /// <summary>
        /// 创建场景进入事件
        /// </summary>
        public SceneEnterEvent(string sceneName)
        {
            SceneName = sceneName;
        }
    }

    /// <summary>
    /// 场景进入前事件数据
    /// </summary>
    [EventArgs]
    public readonly struct BeforeSceneEnterEvent
    {
        /// <summary>
        /// 场景名称
        /// </summary>
        public readonly string SceneName;

        /// <summary>
        /// 创建场景进入前事件
        /// </summary>
        public BeforeSceneEnterEvent(string sceneName)
        {
            SceneName = sceneName;
        }
    }
}
