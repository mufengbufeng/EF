using System.Collections.Generic;
using UnityEngine;
using YooAsset;

public static class GameDefine
{
    public static string PackageName = "DefaultPackage";
    public static string PackageVersion = "v1.0";   // YooAsset的包版本号
    public static string BigVersion = "1.0.0";  // 大版本号
    public static EPlayMode PlayMode = EPlayMode.EditorSimulateMode;
    public static string DefaultCDN = "http://172.16.13.210:8000/CDN";
    public static string FallBackCDN = "http://172.16.13.210:8000/CDN";

    public static List<string> Dlls = new List<string> { "GameProto", "GameLogic" };

    public static string DefaultHostServer = $"{GameDefine.DefaultCDN}/{GameDefine.Platform}/{GameDefine.BigVersion}";
    public static string FallBackHostServer = $"{GameDefine.FallBackCDN}/{GameDefine.Platform}/{GameDefine.BigVersion}";
    public static List<string> AOTMetaAssemblyFiles = new() { "mscorlib.dll", "System.dll", "System.Core.dll", "YooAsset.dll", "UniTask.dll", "EF.dll" };
    public static string Platform
    {
        get
        {
            string platform = string.Empty;
            switch (Application.platform)
            {
                case RuntimePlatform.Android:
                    platform = "Android";
                    break;
                case RuntimePlatform.IPhonePlayer:
                    platform = "IOS";
                    break;
                case RuntimePlatform.WindowsPlayer:
                    platform = "Windows";
                    break;
                case RuntimePlatform.OSXPlayer:
                    platform = "MacOS";
                    break;
                default:
                    platform = "Windows";
                    break;
            }
            return platform;
        }
    }
}