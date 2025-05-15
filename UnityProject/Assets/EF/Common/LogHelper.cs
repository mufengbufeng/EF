
using UnityEngine;

namespace EF
{
    public static class LogHelper
    {
        public static void Send(LogLevel level, string message)
        {
            switch (level)
            {
                case LogLevel.Info:
                    Debug.Log($"[INFO] {message}");
                    break;
                case LogLevel.Warning:
                    Debug.LogWarning($"[WARNING] {message}");
                    break;
                case LogLevel.Error:
                    Debug.LogError($"[ERROR] {message}");
                    break;
                case LogLevel.Fatal:
                    Debug.LogError($"[FATAL] {message}");
                    break;
            }
        }

    }


    public enum LogLevel
    {
        Info,   // 信息
        Warning,    // 警告
        Error,  // 错误
        Fatal,  // 致命错误
    }
}