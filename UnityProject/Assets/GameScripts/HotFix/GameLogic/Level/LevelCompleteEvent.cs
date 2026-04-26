using EF.Event;

namespace GameLogic
{
    /// <summary>
    /// 关卡通关事件参数（纯信号事件）。
    /// </summary>
    [EventArgs]
    public readonly struct LevelCompleteEvent
    {
    }
}
