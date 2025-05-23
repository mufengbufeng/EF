using System.Collections.Generic;
using EF;
using UnityEditor;
using UnityEngine;

/// <summary>
/// 同步程序集上下文。
/// </summary>
public static class SyncAssemblyContent
{
    public static List<string> HotUpdateAssemblies = new List<string>() { };
    public static List<string> AOTMetaAssemblies = new List<string>() { };

    public static void RefreshAssembly()
    {
        var hotUpdateAssemblyFiles = HybridCLR.Editor.SettingsUtil.HotUpdateAssemblyFilesIncludePreserved;
        var aotAssemblyNames = HybridCLR.Editor.SettingsUtil.AOTAssemblyNames;

        // 检查两个列表是否都为空，如果是，记录日志并返回。
        if (hotUpdateAssemblyFiles.Count == 0 && aotAssemblyNames.Count == 0)
        {
            Log.Info("HybridCLR.Editor.SettingsUtil 程序集列表值为空");
            return;
        }

        // 如果列表不为空，则更新相应的设置。
        // if (hotUpdateAssemblyFiles.Count > 0)
        // {
        //     SettingsUtils.SetHybridCLRHotUpdateAssemblies(hotUpdateAssemblyFiles);
        // }

        // if (aotAssemblyNames.Count > 0)
        // {
        //     SettingsUtils.SetHybridCLRAOTMetaAssemblies(aotAssemblyNames);
        // }

        if (hotUpdateAssemblyFiles.Count > 0)
        {
            SyncAssemblyContent.HotUpdateAssemblies.Clear();
            foreach (var assembly in hotUpdateAssemblyFiles)
            {
                SyncAssemblyContent.HotUpdateAssemblies.Add(assembly);
            }
        }

        Log.Info($"AOT COUNT {aotAssemblyNames.Count}");
        if (aotAssemblyNames.Count > 0)
        {
            SyncAssemblyContent.AOTMetaAssemblies.Clear();
            foreach (var assembly in aotAssemblyNames)
            {
                SyncAssemblyContent.AOTMetaAssemblies.Add(assembly);
            }
        }

        AssetDatabase.Refresh();
        AssetDatabase.SaveAssets();
    }
}
