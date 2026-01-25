using EF.Event;

namespace GameLogic
{
    /// <summary>
    /// 场景进入事件数据
    /// </summary>
    public class SceneEnterEvent : BaseEventArgs
    {
        /// <summary>
        /// 场景名称
        /// </summary>
        public string SceneName { get; set; }

        public override int EventId => (int)EGameEvent.SceneEnterEvent;

        public SceneEnterEvent(string sceneName)
        {
            SceneName = sceneName;
        }
    }

    /// <summary>
    /// 场景进入前事件数据
    /// </summary>
    public class BeforeSceneEnterEvent : BaseEventArgs
    {
        /// <summary>
        /// 场景名称
        /// </summary>
        public string SceneName { get; set; }

        public override int EventId => (int)EGameEvent.BeforeSceneEnterEvent;

        public BeforeSceneEnterEvent(string sceneName)
        {
            SceneName = sceneName;
        }
    }
}
