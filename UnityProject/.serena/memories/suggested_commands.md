# 常用命令 / 操作（Windows + Unity）

## OpenSpec
- `openspec list`
- `openspec list --specs`
- `openspec show <id>`
- `openspec validate <id> --strict`

## Unity（菜单操作）
- 构建 AssetBundles：`YooAsset → AssetBundle Builder → Build AssetBundles`
- 构建 HybridCLR DLL 并复制：`HybridCLR → Build → BuildAssets And CopyTo AssemblyTextAssetPath`
- 开关 HybridCLR：`HybridCLR → Define Symbols → Enable/Disable HybridCLR`
- 主工程构建：`File → Build Settings → Build`

## Git（常用）
- `git status`
- `git diff`
- `git log -n 20 --oneline`

## 搜索 / 浏览（PowerShell）
- 查找：`rg -n "关键词"`（若可用）
- 目录：`Get-ChildItem -Recurse`
