using Cysharp.Threading.Tasks;
using EF;
using GameLogic;
using HybridCLR;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Xml.Schema;
using UnityEngine;
using YooAsset;



public class Init : MonoBehaviour
{
    public GameObject Canvas;
    public GameObject LoadingView;

    void Start()
    {
        DontDestroyOnLoad(this);
        StartInit().Forget();
    }

    private async UniTaskVoid StartInit()
    {
        var UHub = transform.GetOrAddComponent<UHubComponent>();
        UHub.BindUI(this, gameObject);
        LoadingView.SetActive(true);
        InitYooAsset().Forget();
        Destroy(LoadingView);

    }

    #region YooAsset初始化

    public async UniTaskVoid InitYooAsset()
    {
        YooAssets.Initialize();

        string packageName = GameDefine.PackageName;
        ResourcePackage package = YooAssets.TryGetPackage(packageName) ?? YooAssets.CreatePackage(packageName);
        YooAssets.SetDefaultPackage(package);

        bool initResult = await InitPackage(package);
        // 平台区分 修改 Platform

        if (!initResult) return;
        Log.Info("资源包初始化成功！");
        // 1.获取资源版本
        bool requestResult = await RequestPackageVersion(packageName);
        if (!requestResult) return;
        Log.Info("资源包版本请求成功！");
        // 2.更新资源清单
        bool updateResult = await UpdatePackageManifest(packageName);
        if (!updateResult) return;
        Log.Info("资源包清单更新成功！");
        // 3. 资源包下载
        bool downloadResult = await DownLoad(packageName);
        if (!downloadResult) return;
        Log.Info("资源包下载成功！");
        // 4. 更新新的DLL
        await UpdateDLL(package);
        // 5. 加载DLL
        LoadAssembly();

        Assembly mainLogicAssembly = null;
        foreach (var assembly in _hotfixAssemblyList)
        {
            if (string.Compare("GameLogic.dll", $"{assembly.GetName().Name}.dll", StringComparison.Ordinal) == 0)
            {
                mainLogicAssembly = assembly;
                break;
            }
        }

        Type type = mainLogicAssembly.GetType("GameLogic.GameModule");
        if (type != null)
        {
            Log.Info($"找到类型：{type}");
        }
        else
        {
            Debug.LogError("没有找到类型");
        }

        type.GetMethod("Run").Invoke(null, null);
    }

    private async UniTask<bool> DownLoad(string packageName)
    {
        int downloadingMaxNum = 10;
        int failedTryAgain = 3;
        var package = YooAssets.GetPackage(packageName);
        var downloader = package.CreateResourceDownloader(downloadingMaxNum, failedTryAgain);

        //没有需要下载的资源
        if (downloader.TotalDownloadCount == 0)
        {
            return true;
        }

        //需要下载的文件总数和总大小
        int totalDownloadCount = downloader.TotalDownloadCount;
        long totalDownloadBytes = downloader.TotalDownloadBytes;

        //注册回调方法
        downloader.DownloadFinishCallback = OnDownloadFinishFunction; //当下载器结束（无论成功或失败）
        downloader.DownloadErrorCallback = OnDownloadErrorFunction; //当下载器发生错误
        downloader.DownloadUpdateCallback = OnDownloadUpdateFunction; //当下载进度发生变化
        downloader.DownloadFileBeginCallback = OnDownloadFileBeginFunction; //当开始下载某个文件

        //开启下载
        downloader.BeginDownload();
        await downloader;

        //检测下载结果
        if (downloader.Status == EOperationStatus.Succeed)
        {
            return true;
            //下载成功
        }
        else
        {
            //下载失败
            Debug.LogError($"下载失败：{downloader.Error}");
            return false;
        }
    }
    // 当开始下载某个文件
    private void OnDownloadFileBeginFunction(DownloadFileData data)
    {
        Log.Info($"开始下载文件：{data.FileName}");
    }

    // 当下载进度发生变化
    private void OnDownloadUpdateFunction(DownloadUpdateData data)
    {
        Log.Info($"下载进度：{data.Progress}");
    }

    // 当下载器发生错误
    private void OnDownloadErrorFunction(DownloadErrorData data)
    {
        Debug.LogError($"下载错误：{data.ErrorInfo}");
    }

    // 当下载器结束（无论成功或失败）
    private void OnDownloadFinishFunction(DownloaderFinishData data)
    {
        Log.Info($"下载完成：{data.PackageName},下载是否成功：{data.Succeed}");
    }

    private async UniTask<bool> UpdatePackageManifest(string packageName)
    {
        var package = YooAssets.GetPackage(packageName);
        var operation = package.UpdatePackageManifestAsync(GameDefine.PackageVersion);
        await operation;

        if (operation.Status == EOperationStatus.Succeed)
        {
            return true;
            //更新成功
        }
        else
        {
            //更新失败
            Debug.LogError(operation.Error);
            return false;
        }
    }

    private async UniTask<bool> RequestPackageVersion(string packageName)
    {
        var package = YooAssets.GetPackage(packageName);
        var operation = package.RequestPackageVersionAsync();
        await operation;

        if (operation.Status == EOperationStatus.Succeed)
        {
            //更新成功
            GameDefine.PackageVersion = operation.PackageVersion;
            Log.Info($"Request package Version : {GameDefine.PackageVersion}");
            return true;
        }
        else
        {
            //更新失败
            Debug.LogError(operation.Error);
            return false;
        }
    }


    public async UniTask<bool> InitPackage(ResourcePackage package)
    {
        switch (GameDefine.PlayMode)
        {
            case EPlayMode.HostPlayMode:
                return await InitPackageHostModel(package);
            case EPlayMode.EditorSimulateMode:
                return await InitPackageEditorSimulateMode(package);
            case EPlayMode.OfflinePlayMode:
                return await InitPackagePlayModel(package);
            case EPlayMode.WebPlayMode:
                return await InitPackageWebPlayMode(package);
            default:
                Debug.LogError("不支持的运行模式");
                return false;
        }
    }
    // 编辑器模式
    public async UniTask<bool> InitPackageEditorSimulateMode(ResourcePackage package)
    {
        var buildResult = EditorSimulateModeHelper.SimulateBuild(GameDefine.PackageName);
        var packageRoot = buildResult.PackageRootDirectory;
        var editorFileSystemParams = FileSystemParameters.CreateDefaultEditorFileSystemParameters(packageRoot);
        var initParameters = new EditorSimulateModeParameters();
        initParameters.EditorFileSystemParameters = editorFileSystemParams;
        var initOperation = package.InitializeAsync(initParameters);
        await initOperation;

        if (initOperation.Status == EOperationStatus.Succeed)
        {
            Log.Info("资源包初始化成功！");
            return true;
        }
        else
        {
            Debug.LogError($"资源包初始化失败：{initOperation.Error}");
            return false;
        }
    }


    // 单机模式
    public async UniTask<bool> InitPackagePlayModel(ResourcePackage package)
    {
        var buildinFileSystemParams = FileSystemParameters.CreateDefaultBuildinFileSystemParameters();
        var initParameters = new OfflinePlayModeParameters();
        initParameters.BuildinFileSystemParameters = buildinFileSystemParams;
        var initOperation = package.InitializeAsync(initParameters);
        await initOperation;

        if (initOperation.Status == EOperationStatus.Succeed)
        {
            Log.Info("资源包初始化成功！");
            return true;
        }
        else
        {
            Debug.LogError($"资源包初始化失败：{initOperation.Error}");
            return false;
        }
    }

    //联机模式
    public async UniTask<bool> InitPackageHostModel(ResourcePackage package)
    {
        Log.Info("资源包初始化HostPlayMode");
        string defaultHostServer = GameDefine.DefaultHostServer;
        string fallbackHostServer = GameDefine.FallBackHostServer;

        IRemoteServices remoteServices = new RemoteServices(defaultHostServer, fallbackHostServer);

        var cacheFileSystemParams = FileSystemParameters.CreateDefaultCacheFileSystemParameters(remoteServices);
        var buildinFileSystemParams = FileSystemParameters.CreateDefaultBuildinFileSystemParameters();
        var initParameters = new HostPlayModeParameters();
#if UNITY_EDITOR
        initParameters.BuildinFileSystemParameters = null; //设置为NULL解决报错！
#else
        initParameters.BuildinFileSystemParameters = buildinFileSystemParams;
#endif
        initParameters.CacheFileSystemParameters = cacheFileSystemParams;
        var initOperation = package.InitializeAsync(initParameters);
        await initOperation;

        if (initOperation.Status == EOperationStatus.Succeed)
        {
            Log.Info("资源包初始化成功！"); return true;
        }
        else
        {
            Debug.LogError($"资源包初始化失败：{initOperation.Error}");
            return false;
        }
    }

    // WebGL模式
    public async UniTask<bool> InitPackageWebPlayMode(ResourcePackage package)
    {
        // string defaultHostServer = $"{DefaultCDN}/{Platform}/{BigVersion}";
        // string fallbackHostServer = $"{FallBackCDN}/{Platform}/{BigVersion}";
        string defaultHostServer = GameDefine.DefaultHostServer;
        string fallbackHostServer = GameDefine.FallBackHostServer;

        IRemoteServices remoteServices = new RemoteServices(defaultHostServer, fallbackHostServer);
        var webServerFileSystemParams = FileSystemParameters.CreateDefaultWebServerFileSystemParameters();
        var webRemoteFileSystemParams = FileSystemParameters.CreateDefaultWebRemoteFileSystemParameters(remoteServices); //支持跨域下载

        var initParameters = new WebPlayModeParameters();
        initParameters.WebServerFileSystemParameters = webServerFileSystemParams;
        initParameters.WebRemoteFileSystemParameters = webRemoteFileSystemParams;

        var initOperation = package.InitializeAsync(initParameters);
        await initOperation;

        if (initOperation.Status == EOperationStatus.Succeed)
        {
            Log.Info("资源包初始化成功！");
            return true;
        }
        else
        {
            Debug.LogError($"资源包初始化失败：{initOperation.Error}");
            return false;
        }
    }
    private async UniTask UpdateDLL(ResourcePackage package)
    {
        //判断是否下载成功
        // var assets = Dlls.Concat(AOTMetaAssemblyFiles);
        List<string> assets = new List<string>();
        foreach (var dll in GameDefine.Dlls)
        {
            assets.Add($"{dll}.dll");
        }
        foreach (var dll in GameDefine.AOTMetaAssemblyFiles)
        {
            assets.Add(dll);
        }

        foreach (var asset in assets)
        {
            var handle = package.LoadAssetAsync<TextAsset>(asset);
            await handle;
            var assetObj = handle.AssetObject as TextAsset;
            s_assetDatas[asset] = assetObj;
            Log.Info($"dll:{asset}   {assetObj == null}");
        }


    }

    private class RemoteServices : IRemoteServices
    {
        private readonly string _defaultHostServer;
        private readonly string _fallbackHostServer;

        public RemoteServices(string defaultHostServer, string fallbackHostServer)
        {
            _defaultHostServer = defaultHostServer;
            _fallbackHostServer = fallbackHostServer;
        }

        string IRemoteServices.GetRemoteMainURL(string fileName)
        {
            return $"{_defaultHostServer}/{fileName}";
        }

        string IRemoteServices.GetRemoteFallbackURL(string fileName)
        {
            return $"{_fallbackHostServer}/{fileName}";
        }
    }

    #endregion






    #region 补充元数据

    //补充元数据dll的列表
    //通过RuntimeApi.LoadMetadataForAOTAssembly()函数来补充AOT泛型的原始元数据

    private Dictionary<string, TextAsset> s_assetDatas = new Dictionary<string, TextAsset>();
    // private static Assembly _hotUpdateAss;
    public List<Assembly> _hotfixAssemblyList;


    public byte[] ReadBytesFromStreamingAssets(string dllName)
    {
        if (s_assetDatas.ContainsKey(dllName))
        {
            return s_assetDatas[dllName].bytes;
        }

        return Array.Empty<byte>();
    }



    /// <summary>
    /// 为aot assembly加载原始metadata， 这个代码放aot或者热更新都行。
    /// 一旦加载后，如果AOT泛型函数对应native实现不存在，则自动替换为解释模式执行
    /// </summary>
    private void LoadMetadataForAOTAssembly()
    {
        /// 注意，补充元数据是给AOT dll补充元数据，而不是给热更新dll补充元数据。
        /// 热更新dll不缺元数据，不需要补充，如果调用LoadMetadataForAOTAssembly会返回错误
        HomologousImageMode mode = HomologousImageMode.SuperSet;
        foreach (var aotDllName in GameDefine.AOTMetaAssemblyFiles)
        {
            byte[] dllBytes = ReadBytesFromStreamingAssets(aotDllName);
            // 加载assembly对应的dll，会自动为它hook。一旦aot泛型函数的native函数不存在，用解释器版本代码
            LoadImageErrorCode err = RuntimeApi.LoadMetadataForAOTAssembly(dllBytes, mode);
            Log.Info($"LoadMetadataForAOTAssembly:{aotDllName}. mode:{mode} ret:{err}");
        }
    }

    #endregion

    #region 运行测试

    void LoadAssembly()
    {
        // 加载AOT dll的元数据
        LoadMetadataForAOTAssembly();
#if !UNITY_EDITOR
#else
#endif
        _hotfixAssemblyList = new List<Assembly>();

        // 加载热更dll
        // #if !UNITY_EDITOR
        //         _hotUpdateAss = Assembly.Load(ReadBytesFromStreamingAssets("HotUpdate.dll"));
        // #else
        //             _hotUpdateAss = System.AppDomain.CurrentDomain.GetAssemblies().First(a => a.GetName().Name == "HotUpdate");
        // #endif
        // Log.Info("运行热更代码");
        // StartCoroutine(Run_InstantiateComponentByAsset());

        foreach (string hotUpdateDllName in GameDefine.Dlls)
        {
            string assetLocation = hotUpdateDllName;
#if !UNITY_EDITOR
                _hotfixAssemblyList.Add(Assembly.Load(ReadBytesFromStreamingAssets($"{assetLocation}.dll")));
#else
            // _hotfixAssemblyList.Add(Assembly.Load(ReadBytesFromStreamingAssets($"{assetLocation}.dll")));
            _hotfixAssemblyList.Add(System.AppDomain.CurrentDomain.GetAssemblies().First(a => a.GetName().Name == assetLocation));
#endif
            Log.Info($"加载热更dll：{hotUpdateDllName}");
        }

    }





    #endregion
}

public class RemoteServices : IRemoteServices
{
    private readonly string _defaultHostServer;
    private readonly string _fallbackHostServer;

    public RemoteServices(string defaultHostServer, string fallbackHostServer)
    {
        _defaultHostServer = defaultHostServer;
        _fallbackHostServer = fallbackHostServer;
    }
    string IRemoteServices.GetRemoteMainURL(string fileName)
    {
        return $"{_defaultHostServer}/{fileName}";
    }
    string IRemoteServices.GetRemoteFallbackURL(string fileName)
    {
        return $"{_fallbackHostServer}/{fileName}";
    }
}

