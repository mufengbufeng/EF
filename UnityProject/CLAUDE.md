<!-- OPENSPEC:START -->
# OpenSpec Instructions

These instructions are for AI assistants working in this project.

Always open `@/openspec/AGENTS.md` when the request:
- Mentions planning or proposals (words like proposal, spec, change, plan)
- Introduces new capabilities, breaking changes, architecture shifts, or big performance/security work
- Sounds ambiguous and you need the authoritative spec before coding

Use `@/openspec/AGENTS.md` to learn:
- How to create and apply change proposals
- Spec format and conventions
- Project structure and guidelines

Keep this managed block so 'openspec update' can refresh the instructions.

<!-- OPENSPEC:END -->

# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Language

中文

## 项目环境

系统： Windows 11
Unity 版本： Unity 6000

## Build Commands

### Unity Editor Build
```bash
# Build AssetBundles (required before HybridCLR operations)
# Use Unity menu: YooAsset → AssetBundle Builder → Build AssetBundles
# Or call programmatically: BuildAssetBundleCommand.BuildAll()

# Build HybridCLR DLLs and copy to AssetRaw/DLL
# Use Unity menu: HybridCLR → Build → BuildAssets And CopyTo AssemblyTextAssetPath
# Or call programmatically: BuildDLLCommand.BuildAndCopyDlls()

# Full game build
# Use Unity menu: File → Build Settings → Build
```

### HybridCLR Commands
```bash
# Enable HybridCLR
Unity Menu: HybridCLR → Define Symbols → Enable HybridCLR

# Disable HybridCLR
Unity Menu: HybridCLR → Define Symbols → Disable HybridCLR

# Build AOT and HotFix DLLs
Unity Menu: HybridCLR → Build → BuildAssets And CopyTo AssemblyTextAssetPath
```

### Hot Update Package Creation
```bash
# Create hot update package (for deployed games)
# 1. Build AssetBundles first
# 2. Create hot package in: Bundles/StandaloneWindows64/HotUpdate/
# Package includes: version.txt, manifest files, and DLLs
```

## Architecture Overview

### Core Framework Structure
This project uses **EasyFramework (EF)** - a modular Unity framework with **HybridCLR** for hot updates.



#### Resource Loading Modes
The framework supports 4 modes via `ResourceModeConfig`:
1. **EditorSimulate** - Editor debugging with direct asset access
2. **OfflinePlay** - Local bundled assets
3. **HostPlay** - Remote CDN assets (for hot updates)
4. **WebPlay** - WebGL compatible mode

### Hot Update Architecture

#### DLL Separation
- **Runtime DLLs**: Core framework (`EF.Runtime.dll`)
- **Hot Update DLLs**: `GameLogic.dll`, `GameProto.dll`
- **AOT Metadata DLLs**: `mscorlib.dll`, `System.dll`, etc.

#### Critical Files for HybridCLR
- `HybridCLRGenerate/link.xml` - Preserves type metadata for AOT dlls
- `HybridCLRGenerate/AOTGenericReferences.cs` - Generic type preservation
- `HotFixConfig.cs` - DLL loading configuration


### Asset Bundle System
Uses **YooAsset** for advanced asset management:
- Build output: `Bundles/{Platform}/DefaultPackage/`
- Auto-generated manifests and version files
- Support for multiple packages and CDN fallbacks
- Asset collection via `AssetBundleCollectorSetting.asset`

### Project Structure
```
Assets/
├── EF/                     # EasyFramework core
│   └── EFRuntime/          # Runtime framework code
├── GameScripts/            # Game code (Runtime & HotFix)
│   ├── Runtime/            # Code compiled into game
│   └── HotFix/             # Hot updateable code
├── HybridCLRGenerate/      # HybridCLR configuration
├── AssetRaw/               # Raw assets (DLLs, configs)
└── Resources/              # Unity resources
```

## Development Workflow

### Making Changes to Hot Update Code
1. Edit code in `GameScripts/HotFix/`
2. Use HybridCLR menu to rebuild DLLs
3. Copy DLLs to `AssetRaw/DLL/`
4. Build AssetBundles if needed
5. Test with `HostPlay` mode to simulate hot update

### Adding New Managers
1. Create interface in `EF/EFRuntime/Common/`
2. Implement manager class
3. Register in `GameLifetimeScope.cs`
4. Add to `GameFramework.cs` initialization

### Resource Loading Best Practices
- Always use `IResourceManager` instead of direct Unity APIs
- Release handles when done: `resourceManager.Release(handle)`
- Use async loading with progress callbacks for UI
- Configure `ResourceModeConfig.asset` for target environment

### HybridCLR Configuration Rules
- Add new hot update types to `link.xml`
- Update `AOTGenericReferences.cs` for new generic types
- Ensure AOT dlls are included in `AssetRaw/DLL/`
- Test both AOT and hot update paths

## Key Dependencies
- **HybridCLR** - Hot update system
- **YooAsset v2.3.16** - Asset management
- **UniTask** - Async operations
- **Luban** - Configuration system
- **Unity URP** - Rendering pipeline

## Common Issues
- If DLL copy fails, ensure `AssetRaw/DLL/` directory exists
- AOT dlls only generate after full game build
- Always rebuild AssetBundles after HybridCLR changes
- Use `SyncAssemblyContent.RefreshAssembly()` if assembly loading issues occur