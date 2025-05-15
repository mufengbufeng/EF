using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace EF
{
    public static class Log
    {
        public static void Info(string message)
        {
            LogHelper.Send(LogLevel.Info, message);
        }

        public static void Warning(string message)
        {
            LogHelper.Send(LogLevel.Warning, message);
        }

        public static void Error(string message)
        {
            LogHelper.Send(LogLevel.Error, message);
        }

        public static void Fatal(string message)
        {
            LogHelper.Send(LogLevel.Fatal, message);
        }
    }
}