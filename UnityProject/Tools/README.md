# Unity 6.6 第三方包补丁

当前锁定的微信小游戏 SDK 在 `WXRuntimeExtDef.cs` 中调用 Unity 6.6 已禁用的 `GetInstanceID()`。YooAsset 3.0.6 的小游戏示例与项目原有程序集重名，因此项目程序集改名为 `EF.MiniGame`，同时需要 YooAsset 对新程序集开放内部扩展点。直接复制两个包会引入大量平台二进制文件，因此项目跟踪限定版本的补丁脚本。

Unity 完成包解析后，从项目根目录运行：

```powershell
pwsh -File Tools/ApplyUnity66PackagePatches.ps1
```

脚本只修改 `Library/PackageCache` 中指定版本的两个源码文件；重复执行无影响。清理 `Library` 或重新解析相关包后，需要再次运行。Unity 6.6 下微信回调返回完整的 `ulong` EntityId；微信小游戏的 JavaScript 侧若依赖旧 `int` ID，发布前需验证该跨语言契约。
