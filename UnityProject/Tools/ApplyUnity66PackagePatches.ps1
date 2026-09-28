param()

$ErrorActionPreference = 'Stop'
$projectRoot = (Resolve-Path -LiteralPath (Join-Path $PSScriptRoot '..')).Path
$lockPath = Join-Path $projectRoot 'Packages/packages-lock.json'
$packages = (Get-Content -LiteralPath $lockPath -Raw | ConvertFrom-Json).dependencies

if ($packages.'com.qq.weixin.minigame'.hash -ne 'ed4ad28f433c6b52b5fd3f22a6fa155a0c98c228') {
    throw '微信小游戏 SDK 的提交已变化，请先核对补丁。'
}
if ($packages.'com.tuyoogame.yooasset'.version -ne '3.0.6') {
    throw 'YooAsset 的版本已变化，请先核对补丁。'
}

$yooAssetCaches = @(Get-ChildItem -LiteralPath (Join-Path $projectRoot 'Library/PackageCache') -Directory -Filter 'com.tuyoogame.yooasset@*')
if ($yooAssetCaches.Count -ne 1) {
    throw 'YooAsset 缓存目录数量不为 1，请确认 Unity 已完成包解析。'
}

function Apply-SourceChange {
    param([string]$Path, [string]$Original, [string[]]$ReplacementLines, [string]$Marker, [string]$Name)

    if (-not (Test-Path -LiteralPath $Path)) {
        throw "找不到 $Name 缓存源码：$Path。请先在 Unity 中解析包。"
    }

    $source = [System.IO.File]::ReadAllText($Path)
    if ($source.Contains($Marker)) {
        Write-Output "$Name 补丁已存在。"
        return
    }
    if ([regex]::Matches($source, [regex]::Escape($Original)).Count -ne 1) {
        throw "$Name 源码与预期不符，未修改 PackageCache。"
    }

    $newline = if ($source.Contains("`r`n")) { "`r`n" } else { "`n" }
    $bytes = [System.IO.File]::ReadAllBytes($Path)
    $hasBom = $bytes.Length -ge 3 -and $bytes[0] -eq 0xEF -and $bytes[1] -eq 0xBB -and $bytes[2] -eq 0xBF
    $encoding = [System.Text.UTF8Encoding]::new($hasBom)
    [System.IO.File]::WriteAllText($Path, $source.Replace($Original, ($ReplacementLines -join $newline)), $encoding)
    Write-Output "已为 $Name 缓存源码应用补丁。"
}

$wxSource = Join-Path $projectRoot 'Library/PackageCache/com.qq.weixin.minigame@ed4ad28f433c/Runtime/WXRuntimeExtDef.cs'
$originalCall = '                    return unityObject.GetInstanceID();'
Apply-SourceChange $wxSource $originalCall @(
    '#if UNITY_6000_6_OR_NEWER'
    '                    return UnityEngine.EntityId.ToULong(unityObject.GetEntityId());'
    '#else'
    $originalCall
    '#endif'
) 'return UnityEngine.EntityId.ToULong(unityObject.GetEntityId());' '微信小游戏 SDK'

$yooSource = Join-Path $yooAssetCaches[0].FullName 'Runtime/Assembly/AssemblyInfo.cs'
$friend = '[assembly: InternalsVisibleTo("YooAsset.MiniGame")]'
Apply-SourceChange $yooSource $friend @(
    $friend
    '[assembly: InternalsVisibleTo("EF.MiniGame")]'
) '[assembly: InternalsVisibleTo("EF.MiniGame")]' 'YooAsset'
