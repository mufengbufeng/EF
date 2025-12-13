// using UnityEditor;
// using UnityEngine;

// namespace EF.Debugger.Editor
// {
//     /// <summary>
//     /// Unity Editor 菜单控制日志等级。
//     /// 提供快捷菜单来切换运行时日志等级。
//     /// </summary>
//     public static class DebuggerMenu
//     {
//         private const string MenuRoot = "EF/Debugger/";
//         private const string LogNoneMenu = MenuRoot + "LogNone";
//         private const string LogErrorMenu = MenuRoot + "LogError";
//         private const string LogWarningMenu = MenuRoot + "LogWarning";
//         private const string LogInfoMenu = MenuRoot + "LogInfo";
//         private const string LogAllMenu = MenuRoot + "LogAll";
//         private const string ResetMenu = MenuRoot + "Reset to Compile Level";
//         private const string PersistMenu = MenuRoot + "Persist Level";

//         private const int MenuPriority = 100;

//         [MenuItem(LogNoneMenu, false, MenuPriority)]
//         private static void SetLogLevelNone()
//         {
//             SetLogLevel(LogLevel.None);
//         }

//         [MenuItem(LogErrorMenu, false, MenuPriority + 1)]
//         private static void SetLogLevelError()
//         {
//             SetLogLevel(LogLevel.Error);
//         }

//         [MenuItem(LogWarningMenu, false, MenuPriority + 2)]
//         private static void SetLogLevelWarning()
//         {
//             SetLogLevel(LogLevel.Warning);
//         }

//         [MenuItem(LogInfoMenu, false, MenuPriority + 3)]
//         private static void SetLogLevelInfo()
//         {
//             SetLogLevel(LogLevel.Log);
//         }

//         [MenuItem(LogAllMenu, false, MenuPriority + 4)]
//         private static void SetLogLevelAll()
//         {
//             SetLogLevel(LogLevel.All);
//         }

//         [MenuItem(ResetMenu, false, MenuPriority + 20)]
//         private static void ResetToCompileLevel()
//         {
//             Log.Reset(false);
//             Debug.Log($"[EF.Debugger] Reset to compile-time level: {Log.CompileTimeLevel}");
//         }

//         [MenuItem(PersistMenu, false, MenuPriority + 21)]
//         private static void TogglePersist()
//         {
//             var shouldPersist = !IsPersistEnabled();
//             SetPersistState(shouldPersist);

//             if (shouldPersist)
//             {
//                 // 如果启用持久化，保存当前等级
//                 Log.SetLevel(Log.CurrentLevel, true);
//                 Debug.Log($"[EF.Debugger] Persistence enabled. Current level {Log.CurrentLevel} saved.");
//             }
//             else
//             {
//                 Debug.Log("[EF.Debugger] Persistence disabled. Use 'Reset to Compile Level' to clear saved level.");
//             }
//         }

//         // 验证菜单：显示勾选标记
//         [MenuItem(LogNoneMenu, true)]
//         private static bool ValidateLogLevelNone()
//         {
//             Menu.SetChecked(LogNoneMenu, Log.CurrentLevel == LogLevel.None);
//             return true;
//         }

//         [MenuItem(LogErrorMenu, true)]
//         private static bool ValidateLogLevelError()
//         {
//             Menu.SetChecked(LogErrorMenu, Log.CurrentLevel == LogLevel.Error);
//             return true;
//         }

//         [MenuItem(LogWarningMenu, true)]
//         private static bool ValidateLogLevelWarning()
//         {
//             Menu.SetChecked(LogWarningMenu, Log.CurrentLevel == LogLevel.Warning);
//             return true;
//         }

//         [MenuItem(LogInfoMenu, true)]
//         private static bool ValidateLogLevelInfo()
//         {
//             Menu.SetChecked(LogInfoMenu, Log.CurrentLevel == LogLevel.Log);
//             return true;
//         }

//         [MenuItem(LogAllMenu, true)]
//         private static bool ValidateLogLevelAll()
//         {
//             Menu.SetChecked(LogAllMenu, Log.CurrentLevel == LogLevel.All);
//             return true;
//         }

//         [MenuItem(PersistMenu, true)]
//         private static bool ValidatePersist()
//         {
//             Menu.SetChecked(PersistMenu, IsPersistEnabled());
//             return true;
//         }

//         private static void SetLogLevel(LogLevel level)
//         {
//             var shouldPersist = IsPersistEnabled();
//             Log.SetLevel(level, shouldPersist);

//             var persistMsg = shouldPersist ? " (persisted)" : "";
//             Debug.Log($"[EF.Debugger] Log level set to: {level}{persistMsg}");
//         }

//         private static bool IsPersistEnabled()
//         {
//             return EditorPrefs.GetBool("EF.Debugger.PersistEnabled", false);
//         }

//         private static void SetPersistState(bool enabled)
//         {
//             EditorPrefs.SetBool("EF.Debugger.PersistEnabled", enabled);
//         }
//     }

//     /// <summary>
//     /// 在 Project Settings 中显示当前日志等级信息。
//     /// </summary>
//     public static class DebuggerStatusBar
//     {
//         [InitializeOnLoadMethod]
//         private static void Initialize()
//         {
//             EditorApplication.update += UpdateStatusBar;
//         }

//         private static void UpdateStatusBar()
//         {
//             // 只在编辑器启动时记录一次
//             EditorApplication.update -= UpdateStatusBar;

//             var compileLevel = Log.CompileTimeLevel;
//             var currentLevel = Log.CurrentLevel;

//             Debug.Log($"[EF.Debugger] Initialized - Compile Level: {compileLevel}, Current Level: {currentLevel}");
//         }
//     }
// }
