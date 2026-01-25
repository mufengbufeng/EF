# Implementation Tasks

## 1. 基础类型与数据结构
- [x] 1.1 约定 `scope = 0` 为全局 Scope（框架层不新增 enum，业务层自定义分类并转 int 传入）
- [x] 1.2 在 `ModuleSystem` 内增加模块实例到 scope 的映射表，并保证线程安全

## 2. 注册流程改造（保持兼容）
- [x] 2.1 扩展 `ModuleSystem.Register<TService>` / `Register(Type, ...)` 增加可选 `int scope` 参数（默认 `0`）
- [x] 2.2 同一模块实例重复注册时校验 Scope 一致性；冲突时报错
- [x] 2.3 `replace/unregister/shutdownAll` 时同步移除 Scope 元数据

## 3. 按 Scope 清理能力
- [x] 3.1 新增 `ModuleSystem.ShutdownScope(int scope)`（建议返回本次清理的模块数量）
- [x] 3.2 清理顺序与 `ShutdownAll` 保持一致：反向注册顺序
- [x] 3.3（可选）处理“更新分发中触发清理”的安全性，避免同帧继续 Update 已注销模块

## 4. 集成示例（GamePlay 退出清理）
- [x] 4.1 在 `GamePlayProcedure.OnLeave` 增加 Scope 清理调用（示例：清理业务层约定的 GamePlay scope 值）

## 5. 文档与验证
- [x] 5.1 更新 `Assets/EF/EFRuntime/Common/Manager/README.md`，补充 Scope 用法与最佳实践
- [x] 5.2 编译校验：`dotnet build EF.Runtime.csproj` 通过（在沙箱环境中可设置 `DOTNET_CLI_HOME` 避免首次运行写入失败）
- [x] 5.3 OpenSpec 校验：`openspec validate add-module-scope-cleanup --strict` 通过
- [x] 5.4 为 `Assets/EF/EFRuntime/Common/Manager/ModuleSystem.cs` 关键函数补充中文注释
