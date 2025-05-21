using UnityEngine;
using System.IO;

namespace GameLogic
{
    public static class PathDefine
    {
        #region 基础路径

        /// <summary>
        /// 持久化数据路径（跨平台）
        /// </summary>
        public static readonly string PersistentDataPath = Application.persistentDataPath;

        /// <summary>
        /// 流数据路径（跨平台）
        /// </summary>
        public static readonly string StreamingAssetsPath = Application.streamingAssetsPath;

        /// <summary>
        /// 临时缓存路径（跨平台）
        /// </summary>
        public static readonly string TemporaryCachePath = Application.temporaryCachePath;

        /// <summary>
        /// 数据路径（跨平台）
        /// </summary>
        public static readonly string DataPath = Application.dataPath;

        #endregion

        #region 资源路径 - AssetRaw

        /// <summary>
        /// 资源根路径，跨平台兼容
        /// </summary>
        public static readonly string AssetRawPath =
            Path.Combine(StreamingAssetsPath, "AssetRaw/");

        /// <summary>
        /// 美术资源路径
        /// </summary>
        public static string ArtPath => Path.Combine(AssetRawPath, "Art").Replace("\\", "/") + "/";

        /// <summary>
        /// 原始美术资源路径
        /// </summary>
        public static string ArtRawPath => Path.Combine(AssetRawPath, "ArtRaw").Replace("\\", "/") + "/";

        /// <summary>
        /// 音频资源路径
        /// </summary>
        public static string AudioPath => Path.Combine(AssetRawPath, "Audio").Replace("\\", "/") + "/";

        /// <summary>
        /// 配置文件路径
        /// </summary>
        public static string ConfigsPath => Path.Combine(AssetRawPath, "Configs").Replace("\\", "/") + "/";

        /// <summary>
        /// DLL文件路径
        /// </summary>
        public static string DLLPath => Path.Combine(AssetRawPath, "DLL").Replace("\\", "/") + "/";

        /// <summary>
        /// 特效资源路径
        /// </summary>
        public static string EffectsPath => Path.Combine(AssetRawPath, "Effects").Replace("\\", "/") + "/";

        /// <summary>
        /// 字体资源路径
        /// </summary>
        public static string FontsPath => Path.Combine(AssetRawPath, "Fonts").Replace("\\", "/") + "/";

        /// <summary>
        /// 材质资源路径
        /// </summary>
        public static string MaterialsPath => Path.Combine(AssetRawPath, "Materials").Replace("\\", "/") + "/";

        /// <summary>
        /// 网格资源路径
        /// </summary>
        public static string MeshPath => Path.Combine(AssetRawPath, "Mesh").Replace("\\", "/") + "/";

        /// <summary>
        /// 预制体资源路径
        /// </summary>
        public static string PrefabsPath => Path.Combine(AssetRawPath, "Prefabs").Replace("\\", "/") + "/";

        /// <summary>
        /// 场景资源路径
        /// </summary>
        public static string ScenesPath => Path.Combine(AssetRawPath, "Scenes").Replace("\\", "/") + "/";

        /// <summary>
        /// 着色器资源路径
        /// </summary>
        public static string ShaderPath => Path.Combine(AssetRawPath, "Shader").Replace("\\", "/") + "/";

        /// <summary>
        /// UI资源路径
        /// </summary>
        public static string UIPath => Path.Combine(AssetRawPath, "UI").Replace("\\", "/") + "/";

        #endregion

        #region Resources资源路径

        /// <summary>
        /// Resources根路径
        /// </summary>
        public const string ResourcesPath = "Assets/Resources/";

        #endregion

        #region AssetBundle路径

        /// <summary>
        /// AssetBundle根目录（在StreamingAssets下）
        /// </summary>
        public static readonly string AssetBundlePath = Path.Combine(StreamingAssetsPath, "yoo");

        /// <summary>
        /// 默认包路径
        /// </summary>
        public static readonly string DefaultPackagePath = Path.Combine(AssetBundlePath, "DefaultPackage");

        #endregion

        #region 数据存储路径

        /// <summary>
        /// 游戏存档路径
        /// </summary>
        public static readonly string SaveDataPath = Path.Combine(PersistentDataPath, "SaveData");

        /// <summary>
        /// 用户设置路径
        /// </summary>
        public static readonly string UserSettingsPath = Path.Combine(PersistentDataPath, "UserSettings");

        /// <summary>
        /// 缓存数据路径
        /// </summary>
        public static readonly string CachePath = Path.Combine(PersistentDataPath, "Cache");

        /// <summary>
        /// 下载内容路径
        /// </summary>
        public static readonly string DownloadPath = Path.Combine(PersistentDataPath, "Download");

        #endregion

        #region 辅助方法

        /// <summary>
        /// 获取Resources下的资源完整路径（不包含扩展名）
        /// </summary>
        public static string GetResourcePath(string relativePath)
        {
            return relativePath.Replace("\\", "/").TrimEnd('/');
        }

        /// <summary>
        /// 获取Assets下的资源完整路径
        /// </summary>
        public static string GetAssetPath(string relativePath)
        {
            return Path.Combine("Assets", relativePath).Replace("\\", "/");
        }

        /// <summary>
        /// 获取持久化数据存储路径
        /// </summary>
        public static string GetPersistentPath(string relativePath)
        {
            return Path.Combine(PersistentDataPath, relativePath).Replace("\\", "/");
        }

        /// <summary>
        /// 获取AssetRaw下的资源路径，跨平台兼容
        /// </summary>
        public static string GetAssetRawPath(string relativePath)
        {
            // 运行时，使用StreamingAssets下的路径
            return Path.Combine(AssetRawPath, relativePath).Replace("\\", "/");
        }

        #endregion
    }
}