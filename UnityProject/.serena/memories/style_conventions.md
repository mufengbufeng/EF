# 风格与约定

## 语言
- 与用户沟通：中文
- 文档与代码注释：中文（技术术语可保留英文）
- 日志消息：中文

## 代码风格
- 遵循项目现有代码风格（命名清晰、职责明确、结构简单）
- 优先小而直接的实现，避免不必要的抽象
- 修改应聚焦需求，不做无关重构

## OpenSpec 工作流
- 遇到“proposal/spec/change/plan”等或新增能力/破坏性变更：先走 OpenSpec 提案阶段
- 提案阶段不写代码，只写：`proposal.md`、`tasks.md`、`design.md`（必要时）与 spec deltas
- 提案完成后使用 `openspec validate <change-id> --strict` 校验
