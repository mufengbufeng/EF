# 敌人生成系统测试指南

## 测试时间
2026-01-31

## 系统状态
✅ **实现完成**  
✅ **编译错误已修复**  
✅ **资源配置已完成**  

## 资源配置信息

### YooAsset 配置
项目使用 **YooAsset** 资源管理系统（不是 Addressables）。

**配置文件**：`Assets/AssetBundleCollectorSetting.asset`

**Prefab 收集器配置**：
- 收集路径：`Assets/AssetRaw/Prefabs`
- 地址规则：`AddressByFileName`（文件名作为资源地址）
- 打包规则：`PackDirectory`
- 过滤规则：`CollectAll`

**EnemyPlane 预制体**：
- 文件位置：`Assets/AssetRaw/Prefabs/Enemy/EnemyPlane.prefab`
- 资源地址：`"EnemyPlane"`（自动由文件名生成）
- ✅ 已在收集器范围内，会自动打包

## 测试前准备

### 1. 构建 AssetBundle（重要）

在 Unity 中测试前，必须先构建 AssetBundle：

```
1. 打开 Unity Editor
2. 找到 YooAsset 菜单（通常在顶部菜单栏）
3. 选择 "AssetBundle Builder" 或类似选项
4. 选择 DefaultPackage
5. 点击 "Build" 构建资源包
```

**注意**：如果没有构建 AssetBundle，运行时会找不到 "EnemyPlane" 资源。

### 2. 检查编译状态

打开 Unity Editor，等待编译完成：

1. 打开项目
2. 查看 Console 窗口
3. 确认没有编译错误（Error）
4. 警告（Warning）可以暂时忽略

### 3. 检查场景设置

确保场景包含：
- ✅ Camera.main（Main Camera 标签）
- ✅ 摄像机使用正交投影（Orthographic）
- ✅ GamePlayProcedure 会被正确启动

## 测试步骤

### 测试 1：基本生成功能

**目标**：验证敌人能否正常生成

**步骤**：
1. 打开 Unity Editor
2. 进入 GamePlay 场景（或运行会启动 GamePlayProcedure 的场景）
3. 点击 Play 按钮
4. 观察 Game 窗口

**预期结果**：
- ✅ 每 2 秒生成一个敌人飞机
- ✅ 敌人在屏幕顶部随机位置出现
- ✅ 敌人向下移动（速度约 2 单位/秒）
- ✅ 同屏最多 10 个敌人

**Console 日志**：
```
[EnemySpawnerModule] 敌人实体组创建成功
[EnemySpawnerModule] 生成敌人: EnemyPlane 于位置 (X, Y, 0)
```

### 测试 2：移动和停留

**目标**：验证敌人移动到指定位置后停留

**步骤**：
1. 运行场景
2. 观察单个敌人的移动轨迹
3. 注意敌人是否在 Y=2 位置停留

**预期结果**：
- ✅ 敌人持续向下移动
- ✅ 到达 Y=2 位置时停止
- ✅ 停留约 2 秒后继续移动
- ✅ 停留期间会触发攻击

**Console 日志**：
```
[EnemyEntity] 到达停留位置，开始停留 2 秒
[EnemyEntity] 敌人攻击！位置: (X, Y, 0)
[EnemyEntity] 停留结束，继续移动
```

### 测试 3：攻击系统

**目标**：验证敌人攻击逻辑

**步骤**：
1. 运行场景
2. 观察 Console 窗口
3. 查找攻击日志

**预期结果**：
- ✅ 停留期间每 1.5 秒触发一次攻击
- ✅ Console 显示攻击日志和位置信息

**Console 日志**：
```
[EnemyEntity] 敌人攻击！位置: (X, 2.0, 0)
```

### 测试 4：边界检测和清理

**目标**：验证敌人超出屏幕后自动销毁

**步骤**：
1. 运行场景
2. 等待敌人移动到屏幕底部
3. 观察敌人是否消失

**预期结果**：
- ✅ 敌人到达 Y=-6 时自动销毁
- ✅ Hierarchy 中的 GameObject 消失
- ✅ 新的敌人继续生成（保持最多 10 个）

**Console 日志**：
```
[EnemyEntity] 敌人超出边界，销毁
```

### 测试 5：数量限制

**目标**：验证同屏最多 10 个敌人

**步骤**：
1. 运行场景
2. 等待一段时间（约 20-30 秒）
3. 观察 Hierarchy 窗口中的敌人数量

**预期结果**：
- ✅ Enemy GameObject 数量始终 ≤ 10
- ✅ 达到上限后不再生成新敌人
- ✅ 有敌人销毁后才会生成新的

**Console 日志**：
```
[EnemySpawnerModule] 已达到最大敌人数量 (10)，跳过本次生成
```

### 测试 6：场景退出清理

**目标**：验证退出场景时资源正确清理

**步骤**：
1. 运行场景并生成一些敌人
2. 退出 Play 模式（或切换到其他 Procedure）
3. 检查 Hierarchy 窗口

**预期结果**：
- ✅ 所有敌人 GameObject 被销毁
- ✅ EnemySpawnerModule 被清理
- ✅ 没有残留的对象或引用

**Console 日志**：
```
[EnemySpawnerModule] 清理所有敌人实体
[ModuleSystem] Scope 1001 shutdown complete
```

## 常见问题排查

### 问题 1：敌人不生成

**症状**：场景运行但没有敌人出现

**可能原因**：
1. ❌ AssetBundle 未构建
2. ❌ EnemySpawnerModule 未配置
3. ❌ 资源地址错误

**解决方法**：
```
1. 检查 Console 是否有错误信息
2. 确认 YooAsset 资源已构建
3. 检查日志：
   - 是否有 "敌人预制体名称未配置" 警告？
   - 是否有 "敌人实体组创建成功" 日志？
   - 是否有资源加载失败的错误？
```

**检查代码**：
```csharp
// 在 GamePlayProcedure.OnEnter 中
_enemySpawnerModule.Configure("EnemyPlane", spawnInterval: 2f, maxEnemyCount: 10);
```

### 问题 2：敌人生成但不移动

**症状**：敌人出现在屏幕上但静止不动

**可能原因**：
1. ❌ Camera.main 不存在
2. ❌ 摄像机不是正交模式
3. ❌ Update 逻辑未执行

**解决方法**：
```
1. 检查场景中的 Camera：
   - Tag 是否为 "MainCamera"
   - Projection 是否为 Orthographic
2. 检查 Console 是否有 "Camera.main 不存在" 警告
3. 查看 Hierarchy 中敌人的 Transform 位置是否变化
```

### 问题 3：敌人行为异常

**症状**：移动速度、停留时间不符合预期

**可能原因**：
1. ❌ EnemyBehaviorData 配置错误
2. ❌ 状态机逻辑问题

**解决方法**：
```csharp
// 在 EnemySpawnerModule.SpawnEnemy() 中检查配置
var behaviorData = new EnemyBehaviorData
{
    SpawnPosition = spawnPos,
    MoveSpeed = 2f,            // 移动速度
    MoveDirection = Vector3.down,
    StayPosition = stayPos,     // Y=2 的位置
    StayDuration = 2f,          // 停留 2 秒
    AttackInterval = 1.5f       // 每 1.5 秒攻击
};
```

### 问题 4：内存泄漏或清理失败

**症状**：退出场景后 Hierarchy 中仍有敌人对象

**可能原因**：
1. ❌ ModuleSystem.ShutdownScope 未调用
2. ❌ 实体未正确回收

**解决方法**：
```
1. 检查 GamePlayProcedure.OnLeave() 中的清理逻辑
2. 确认 GamePlayScope (1001) 正确关闭
3. 查看 Console 日志：
   - "[EnemySpawnerModule] 清理所有敌人实体"
   - 实体 OnHide 和 OnRecycle 是否被调用
```

### 问题 5：热更新环境中的特殊问题

**症状**：HybridCLR 环境下运行异常

**可能原因**：
1. ❌ 属性访问器语法不兼容
2. ❌ Handle 属性设置失败

**解决方法**：
```
这些问题在开发阶段已修复：
- BUGFIX_HANDLE_PROPERTY.md 记录了 Handle 属性的修复
- 使用完整方法体语法替代表达式体
```

## 性能基准

**预期性能**（在开发机上）：
- FPS：≥ 60
- 内存占用：< 100MB 增量
- CPU 占用：< 5%（空闲时）

**如果性能不佳**：
1. 检查对象池是否正常工作
2. 确认实体正确回收，没有重复创建
3. 查看 Profiler 中的 GC Alloc

## 下一步开发

测试通过后，可以考虑以下增强：

### 功能增强
1. **实际攻击系统**
   - 当前只是日志输出
   - 需要实现子弹发射逻辑
   - 添加碰撞检测

2. **多种敌人类型**
   - 创建不同的敌人预制体
   - 不同的移动模式（曲线、Z字形等）
   - 不同的攻击方式

3. **波次系统**
   - 定义敌人波次配置
   - 波次间隔和难度递增
   - Boss 战支持

4. **视觉效果**
   - 攻击特效
   - 移动轨迹效果
   - 销毁动画

5. **生命值系统**
   - 敌人血量
   - 受伤效果
   - 击败奖励

### 架构优化
1. **配置数据化**
   - 将硬编码的参数移到配置文件
   - 支持运行时调整
   
2. **AI 行为树**
   - 更复杂的敌人行为
   - 可扩展的 AI 模式

3. **对象池优化**
   - 预热对象池
   - 动态调整池大小

## 测试清单

完成以下所有测试后，系统即可投入使用：

- [ ] 测试 1：基本生成功能
- [ ] 测试 2：移动和停留
- [ ] 测试 3：攻击系统
- [ ] 测试 4：边界检测和清理
- [ ] 测试 5：数量限制
- [ ] 测试 6：场景退出清理
- [ ] 性能测试（FPS、内存、CPU）
- [ ] AssetBundle 构建和加载测试

## 相关文档

- **实施总结**：`IMPLEMENTATION_SUMMARY.md`
- **编译修复记录**：`BUGFIX_SUMMARY.md`
- **任务清单**：`tasks.md`
- **设计文档**：`design.md`
- **提案文档**：`proposal.md`

## 联系方式

如有测试问题或发现 Bug，请：
1. 记录详细的错误日志
2. 截图或录屏重现步骤
3. 提供 Unity 版本和环境信息
4. 更新 `tasks.md` 中的相关项目
