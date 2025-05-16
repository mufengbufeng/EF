namespace EF
{
    public enum UILayer
    {
        Background = 0,    // 背景层
        Normal = 100,      // 普通UI层 (例如主界面)
        Fixed = 200,       // 固定UI层 (例如顶部信息条)
        PopUp = 300,       // 弹出窗口层 (例如通用弹窗、确认框)
        Dialog = 350,      // 对话框层 (例如剧情对话)
        Toast = 400,       // 提示信息层 (例如短暂的文字提示)
        Guide = 450,       // 新手引导层
        Top = 500,         // 最顶层 (例如加载界面、全局错误提示)
        System = 1000      // 系统级，比Top还高
    }
}