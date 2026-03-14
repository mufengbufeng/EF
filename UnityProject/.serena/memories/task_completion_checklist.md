# 完成任务后的检查清单（建议）

## 提案（OpenSpec）
- 变更文档齐全：`proposal.md`、`tasks.md`、（需要时）`design.md`、spec deltas
- 严格校验通过：`openspec validate <change-id> --strict`

## 代码变更
- Unity Editor 编译无报错
- 如涉及热更新：使用 HybridCLR 菜单重新构建并验证热更 DLL
- 如涉及资源：按需重建 AssetBundles 并验证加载流程
