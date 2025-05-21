
using System;
using System.Collections.Generic;
using Cysharp.Threading.Tasks;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.U2D;
using YooAsset;

namespace EF
{
    public class ResourceModule : BehaviourSingleton<ResourceModule>
    {
        public ResourcePackage package;
        public string packageName = "DefaultPackage";
        private readonly Dictionary<string, AssetInfo> _assetInfoMap = new Dictionary<string, AssetInfo>();
        protected override void Init()
        {
            base.Init();
            if (package == null)
            {
                package = YooAssets.GetPackage(packageName);
            }
        }

        #region 资源信息
        public AssetInfo[] GetAssetInfos(string tag)
        {

            return YooAssets.GetAssetInfos(tag);

        }
        /// <summary>
        /// 获取资源信息。
        /// </summary>
        /// <param name="location">资源的定位地址。</param>
        /// <param name="packageName">资源包名称。</param>
        /// <returns>资源信息。</returns>
        public AssetInfo GetAssetInfo(string location)
        {
            if (string.IsNullOrEmpty(location))
            {
                Log.Error("GetAssetInfo location is null");
                return null;
            }

            if (string.IsNullOrEmpty(packageName))
            {
                if (_assetInfoMap.TryGetValue(location, out AssetInfo assetInfo))
                {
                    return assetInfo;
                }

                assetInfo = YooAssets.GetAssetInfo(location);
                _assetInfoMap[location] = assetInfo;
                return assetInfo;
            }
            else
            {
                string key = $"{packageName}/{location}";
                if (_assetInfoMap.TryGetValue(key, out AssetInfo assetInfo))
                {
                    return assetInfo;
                }

                var package = YooAssets.GetPackage(packageName);
                if (package == null)
                {
                    Log.Error($"GetAssetInfo package is null, packageName = {packageName}");
                    return null;
                }

                assetInfo = package.GetAssetInfo(location);
                _assetInfoMap[key] = assetInfo;
                return assetInfo;
            }
        }

        public HasAssetResult HasAsset(string location)
        {
            if (string.IsNullOrEmpty(location))
            {
                Log.Error("HasAsset location is null");
            }

            AssetInfo assetInfo = GetAssetInfo(location);

            if (!CheckLocationValid(location))
            {
                return HasAssetResult.Valid;
            }

            if (assetInfo == null)
            {
                return HasAssetResult.NotExist;
            }

            if (IsNeedDownloadFromRemote(assetInfo))
            {
                return HasAssetResult.AssetOnline;
            }

            return HasAssetResult.AssetOnDisk;
        }

        /// <summary>
        /// 是否需要从远端更新下载。
        /// </summary>
        /// <param name="location">资源的定位地址。</param>
        /// <param name="packageName">资源包名称。</param>
        public bool IsNeedDownloadFromRemote(string location)
        {
            if (string.IsNullOrEmpty(location))
            {
                Log.Error("IsNeedDownloadFromRemote location is null");
                return false;
            }
            return YooAssets.IsNeedDownloadFromRemote(location);
        }

        /// <summary>
        /// 是否需要从远端更新下载。
        /// </summary>
        /// <param name="assetInfo">资源信息。</param>
        /// <param name="packageName">资源包名称。</param>
        public bool IsNeedDownloadFromRemote(AssetInfo assetInfo, string packageName = "")
        {
            if (string.IsNullOrEmpty(packageName))
            {
                return YooAssets.IsNeedDownloadFromRemote(assetInfo);
            }
            else
            {
                var package = YooAssets.GetPackage(packageName);
                return package.IsNeedDownloadFromRemote(assetInfo);
            }
        }

        /// <summary>
        /// 检查资源定位地址是否有效。
        /// </summary>
        /// <param name="location">资源的定位地址</param>
        /// <param name="packageName">资源包名称。</param>
        public bool CheckLocationValid(string location, string packageName = "")
        {
            if (string.IsNullOrEmpty(packageName))
            {
                return YooAssets.CheckLocationValid(location);
            }
            else
            {
                var package = YooAssets.GetPackage(packageName);
                return package.CheckLocationValid(location);
            }
        }
        #endregion

        #region 资源句柄
        /// <summary>
        /// 获取同步资源句柄。
        /// </summary>
        /// <param name="location">资源定位地址。</param>
        /// <param name="packageName">指定资源包的名称。不传使用默认资源包</param>
        /// <typeparam name="T">资源类型。</typeparam>
        /// <returns>资源句柄。</returns>
        private AssetHandle GetHandleASync<T>(string location) where T : UnityEngine.Object
        {
            return GetHandleASync(location, typeof(T));
        }

        private AssetHandle GetHandleASync(string location, Type assetType)
        {
            if (string.IsNullOrEmpty(location))
            {
                Log.Error("GetHandleSync location is null");
                return null;
            }

            return YooAssets.LoadAssetSync(location, assetType);
        }

        /// <summary>
        /// 获取异步资源句柄。
        /// </summary>
        /// <param name="location">资源定位地址。</param>
        /// <typeparam name="T">资源类型。</typeparam>
        /// <returns>资源句柄。</returns>
        private AssetHandle GetHandleAsync<T>(string location) where T : UnityEngine.Object
        {
            return GetHandleAsync(location, typeof(T));
        }

        private AssetHandle GetHandleAsync(string location, Type assetType)
        {
            if (string.IsNullOrEmpty(location))
            {
                Log.Error("GetHandleAsync location is null");
                return null;
            }
            var package = YooAssets.GetPackage(packageName);
            return package.LoadAssetAsync(location, assetType);
        }
        #endregion

        #region 资源加载
        /// <summary>
        /// 加载资源。
        /// </summary>
        /// <typeparam name="T">资源类型</typeparam>
        /// <param name="location">资源名</param>
        /// <returns>资源对象</returns>
        public T LoadAsset<T>(string location) where T : UnityEngine.Object
        {
            if (string.IsNullOrEmpty(location))
            {
                Log.Error("LoadAsset location is null");
                return null;
            }

            var assetHandle = package.LoadAssetSync<T>(location);
            if (assetHandle != null)
            {
                return assetHandle.AssetObject as T;
            }

            return null; ;
        }

        /// <summary>
        /// 异步加载资源。
        /// </summary>
        /// <param name="location">资源定位地址。</param>
        /// <typeparam name="T">资源类型。</typeparam>
        /// <returns>资源对象。</returns>
        public async UniTask<T> LoadAssetAsync<T>(string location) where T : UnityEngine.Object
        {
            if (string.IsNullOrEmpty(location))
            {
                Log.Error("LoadAssetAsync location is null");
                return null;
            }
            var assetHandle = package.LoadAssetAsync<T>(location);
            if (assetHandle != null)
            {
                await assetHandle.ToUniTask();
                return assetHandle.AssetObject as T;
            }
            return null;
        }
        /// <summary>
        /// 异步加载子资源。
        /// </summary>
        /// <typeparam name="T">类型</typeparam>
        /// <param name="location">资源定位地址:图集名</param>
        /// <param name="subName">子资源名称:图集下的图片名</param>
        /// <returns></returns>
        public async UniTask<List<T>> LoadSubAssetsAsync<T>(string location, string subName) where T : UnityEngine.Object
        {
            if (string.IsNullOrEmpty(location))
            {
                Log.Error("LoadSubAssetsAsync location is null");
                return null;
            }
            var assetHandle = package.LoadSubAssetsAsync<T>(location);
            await assetHandle.ToUniTask();
            var srpite = assetHandle?.GetSubAssetObject<T>(subName);
            if (srpite != null)
            {
                return new List<T> { srpite };
            }
            else
            {
                Log.Error($"LoadSubAssetsAsync location is null, subName = {subName}");
            }
            return null;

        }

        public Sprite LoadSprite(string location, string spriteName)
        {
            if (string.IsNullOrEmpty(location) || string.IsNullOrEmpty(spriteName))
            {
                Log.Error("LoadSprite location is null");
                return null;
            }
            var assetHandle = LoadAsset<SpriteAtlas>(location);
            if (assetHandle != null)
            {
                return assetHandle.GetSprite(spriteName);
            }
            return null;
        }

        public async UniTask<Sprite> LoadSpriteAsync(string location, string spriteName)
        {
            if (string.IsNullOrEmpty(location) || string.IsNullOrEmpty(spriteName))
            {
                Log.Error("LoadSprite location is null");
                return null;
            }

            var assetHandle = await LoadAssetAsync<SpriteAtlas>(location);
            if (assetHandle != null) return assetHandle.GetSprite(spriteName);
            return null;
        }
        /// <summary>
        /// 同步加载子资源。
        /// </summary>
        /// <typeparam name="T">类型</typeparam>
        /// <param name="location">资源定位地址:图集名</param>
        /// <param name="subName">子资源名称:图集下的图片名</param>
        /// <returns></returns>
        public T LoadSubAssets<T>(string location, string subName) where T : UnityEngine.Object
        {
            if (string.IsNullOrEmpty(location))
            {
                Log.Error("LoadSubAssets location is null");
                return null;
            }
            var assetHandle = package.LoadSubAssetsSync<T>(location);
            if (assetHandle == null)
            {
                Log.Error($"Unable to load sub asset {subName}");
                return null;
            }
            var subAsset = assetHandle?.GetSubAssetObject<T>(subName);
            if (subAsset != null)
            {
                return subAsset;
            }
            else
            {
                Log.Error($"LoadSubAssets location is null, subName = {subName}");
            }
            return null;
        }

        /// <summary>
        /// 加载资源包内所有资源。
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <param name="location">只需要填写资源包里任意资源地址</param>
        /// <returns></returns>
        public List<T> LoadAllAsset<T>(string location) where T : UnityEngine.Object
        {
            AllAssetsHandle handle = package.LoadAllAssetsSync<T>(location);
            if (handle == null)
            {
                Log.Error($"LoadAllAsset location is null");
                return null;
            }

            List<T> allAssets = new List<T>(handle.AllAssetObjects.Count);
            foreach (var assetHandle in handle.AllAssetObjects)
            {
                allAssets.Add(assetHandle as T);
            }
            return allAssets;
        }

        /// <summary>
        /// 异步加载资源包内所有资源。
        /// </summary>
        /// <typeparam name="T"></typeparam>
        /// <param name="location"></param>
        /// <returns></returns>
        public async UniTask<List<T>> LoadAllAssetAsync<T>(string location) where T : UnityEngine.Object
        {
            AllAssetsHandle handle = package.LoadAllAssetsAsync<T>(location);
            if (handle == null)
            {
                Log.Error($"LoadAllAssetAsync location is null");
                return null;
            }
            await handle.ToUniTask();
            List<T> allAssets = new List<T>(handle.AllAssetObjects.Count);
            foreach (var assetHandle in handle.AllAssetObjects)
            {
                allAssets.Add(assetHandle as T);
            }
            return allAssets;
        }

        /// <summary>
        /// 加载场景。
        /// </summary>
        /// <param name="location">场景地址</param>
        /// <param name="sceneMode">场景模式</param>
        /// <param name="physicsMode">物理模式</param>
        /// <returns></returns>
        public SceneHandle LoadScene(string location, LoadSceneMode sceneMode = LoadSceneMode.Single, LocalPhysicsMode physicsMode = LocalPhysicsMode.None)
        {
            if (string.IsNullOrEmpty(location))
            {
                Log.Error("LoadScene location is null");
                return null;
            }
            var sceneHandle = package.LoadSceneSync(location, sceneMode, physicsMode);
            if (sceneHandle != null)
            {
                return sceneHandle;
            }
            return null;
        }

        public async UniTask<SceneHandle> LoadSceneAsync(string location, LoadSceneMode sceneMode = LoadSceneMode.Single, LocalPhysicsMode physicsMode = LocalPhysicsMode.None)
        {
            if (string.IsNullOrEmpty(location))
            {
                Log.Error("LoadSceneAsync location is null");
                return null;
            }
            var sceneHandle = package.LoadSceneAsync(location, sceneMode, physicsMode);
            await sceneHandle.ToUniTask();
            if (sceneHandle != null)
            {
                return sceneHandle;
            }
            return null;
        }

        public GameObject LoadGameObject(string location, Transform parent = null)
        {
            if (string.IsNullOrEmpty(location))
            {
                Log.Error("LogGameOBject location is null");
                return null;
            }
            var assetHandle = package.LoadAssetSync<GameObject>(location);
            if (assetHandle != null)
            {

                GameObject go;
                if (parent == null)
                {
                    go = assetHandle.InstantiateSync();
                }
                else
                {
                    go = assetHandle.InstantiateSync(parent);
                }
                return go;
            }
            return null;
        }

        public async UniTask<GameObject> LoadGameObjectAsync(string location, Transform parent = null)
        {
            if (string.IsNullOrEmpty(location))
            {
                Log.Error("LoadGameOObjectAsync location is null");
                return null;
            }
            var assetHandle = package.LoadAssetAsync<GameObject>(location);
            if (assetHandle != null)
            {
                await assetHandle.ToUniTask();
                GameObject go;
                if (parent == null)
                {
                    go = assetHandle.InstantiateSync();
                }
                else
                {
                    go = assetHandle.InstantiateSync(parent);
                }
                return go;
            }
            return null;
        }
        #endregion


        /// <summary>
        /// 卸载未使用的资源
        /// </summary>
        public async UniTaskVoid UnloadUnusedAssets()
        {
            UnloadAllAssetsOperation result = package.UnloadAllAssetsAsync();
            await result.ToUniTask();
            if (result.Status == EOperationStatus.Succeed)
            {
                Log.Info("UnloadUnusedAssets Succeed");
            }
            else
            {
                Log.Error($"UnloadUnusedAssets Failed, Error = {result.Error}");
            }
        }

        // 尝试卸载指定的资源对象
        // 注意：如果该资源还在被使用，该方法会无效。
        public void TryUnloadUnusedAsset(string location)
        {
            package.TryUnloadUnusedAsset(location);
        }

    }
}