## Context

EFRuntime 是 Unity 游戏项目的自研框架层，包含 13 个模块（Event、Common、ObjectPool、Timer、Model、Fsm、Feature、Save、Entity、UI、Sound、Scene、Debugger）。当前只有 4 个 Example 文件（MonoBehaviour 演示），无任何自动化测试。项目已有 NUnit 测试基础设施（`GameLogic.Tests.EditMode` 程序集），包含 EnergyModuleTests 和 MainControllerTests 两个成熟的测试文件，可作为风格参考。

## Goals / Non-Goals

**Goals:**
- 覆盖 P0 + P1 层全部 6 个核心模块（Event、ModuleSystem、ObjectPool、Timer、Model、Fsm），确保关键路径零盲区
- 覆盖 P2 层 3 个功能模块（Feature、Save、Procedure），达到合理覆盖
- 所有测试可复用、可维护，作为框架行为的活文档
- 测试风格与现有 EnergyModuleTests 保持一致

**Non-Goals:**
- 不覆盖 P3 Unity 重度依赖层（Entity、UI、Sound、Scene、Resource）—— 测试成本高、回报低，按需补充
- 不引入新的测试框架或依赖包
- 不修改 EFRuntime 源码（纯新增测试）
- 不做性能基准测试
- 不做 PlayMode 集成测试

## Decisions

### D1: 测试放置位置

**决定**: 在 `Tests/EditMode/Framework/` 下按模块分文件组织。

**理由**: 复用现有 `GameLogic.Tests.EditMode` 程序集，无需新建 asmdef。测试需要访问 EFRuntime 的 internal 成员时，可通过 `[assembly: InternalsVisibleTo("GameLogic.Tests.EditMode")]` 解决（如需要）。

**备选**: 在 `Assets/EF/EFRuntime/Tests/` 下单独建测试程序集。放弃原因是多一个程序集增加维护成本，且现有 Fake 模式已证明在业务测试程序集中测框架完全可行。

### D2: 测试隔离策略

**决定**: 每个测试文件使用手写 Fake/Stub 隔离外部依赖，与现有 EnergyModuleTests 风格一致。

**理由**: 项目未引入 Mock 框架（Moq/NSubstitute），手写 Fake 虽然样板代码多，但类型安全、调试友好、无反射开销。对于框架层测试，依赖接口通常只有 2-5 个方法，手写成本可控。

### D3: ModuleSystem 测试的 TearDown 策略

**决定**: 每个 `[SetUp]` 调用 `ModuleSystem.ShutdownAll()`，`[TearDown]` 同样调用，确保测试间状态隔离。这与 MainControllerTests 的模式一致。

### D4: Example 文件处理

**决定**: 暂不删除 Example 文件。测试覆盖后 Example 的文档价值降低，但删除属于破坏性操作，可在后续变更中处理。

### D5: 测试命名约定

**决定**: 采用 `MethodName_Scenario_ExpectedBehavior` 三段式命名，与现有测试一致（如 `TryConsume_WhenAmountIsZero_ShouldSucceedAndNotChangeEnergy`）。

## Risks / Trade-offs

**[Internal 成员访问]** → 部分框架类使用 internal 可见性。若测试需要访问 internal 成员（如 EnergyModuleTests 通过反射访问 `EnergySaveData`），优先用反射测试。仅在反射成本过高时才考虑添加 `InternalsVisibleTo`。

**[ModuleSystem 全局状态]** → ModuleSystem 是静态类，测试间可能互相影响。缓解：严格 `[SetUp]`/`[TearDown]` 调用 `ShutdownAll()`，测试中避免并行。

**[测试数量膨胀]** → 8 个模块可能产生 100+ 个测试方法。缓解：按模块分文件，每个测试类保持在一个文件内，用 `#region` 按场景分组（参考 EnergyModuleTests 的组织方式）。
