using System;

using UnityEngine;

public static class SettingUtils
{
    public static string GetPlatformName()
    {
#if UNITY_ANDROID
        return "Android";
#elif UNITY_IOS
        return "IOS";
#elif UNITY_WEBGL
        return "WebGL";
#else
        switch (Application.platform)
        {
            case RuntimePlatform.WindowsEditor:
                return "Windows64";
            case RuntimePlatform.WindowsPlayer:
                return "Windows64";

            case RuntimePlatform.OSXEditor:
            case RuntimePlatform.OSXPlayer:
                return "MacOS";

            case RuntimePlatform.IPhonePlayer:
                return "IOS";

            case RuntimePlatform.Android:
                return "Android";
            case RuntimePlatform.WebGLPlayer:
                return "WebGL";

            case RuntimePlatform.PS5:
                return "PS5";
            default:
                throw new NotSupportedException($"Platform '{Application.platform.ToString()}' is not supported.");
        }
#endif
    }
    // public static HybridCLRCustomGlobalSettings HybridCLRCustomGlobalSettings => GlobalSettings.BybridCLRCustomGlobalSettings;
    // public static void SetHybridCLRHotUpdateAssemblies(List<string> hotUpdateAssemblies)
    // {
    //     HybridCLRCustomGlobalSettings.HotUpdateAssemblies.Clear();
    //     HybridCLRCustomGlobalSettings.HotUpdateAssemblies.AddRange(hotUpdateAssemblies);
    // }

    // public static void SetHybridCLRAOTMetaAssemblies(List<string> aOTMetaAssemblies)
    // {
    //     HybridCLRCustomGlobalSettings.AOTMetaAssemblies.Clear();
    //     HybridCLRCustomGlobalSettings.AOTMetaAssemblies.AddRange(aOTMetaAssemblies);
    // }


}