## 1. 配置与代码生成
- [ ] 1.1 新增 `Configs/GameConfig/Datas/level.xlsx`，定义关卡字段与示例数据
- [ ] 1.2 更新 `Configs/GameConfig/Datas/__tables__.xlsx` 注册 `level.TbLevel`
- [ ] 1.3 运行 `gen_code_bin_to_project.bat` 生成配置二进制与 C# 代码

## 2. 关卡模块实现
- [ ] 2.1 新增 `ILevelModule.cs` 定义关卡读取、计数、通关和推进接口
- [ ] 2.2 新增 `LevelModule.cs`，实现 PlayerPrefs 持久化与配置回退逻辑
- [ ] 2.3 在 `InitProcedure` 注册全局关卡模块

## 3. 玩法流程集成
- [ ] 3.1 修改 `MainMenuProcedure.StartGame()`：进入当前关卡并记录日志
- [ ] 3.2 修改 `GamePlayProcedure`：进入时读取关卡配置并下发敌人参数
- [ ] 3.3 修改 `GamePlayProcedure`：杀敌通知关卡模块，通关后推进到下一关
- [ ] 3.4 调整 `EnemySpawnerModule` 支持敌人速度倍率下发

## 4. 验证与交付
- [ ] 4.1 完成编译验证并修复错误
- [ ] 4.2 更新任务状态，确认实现与计划一致
- [ ] 4.3 提交代码并推送分支，产出 PR 信息
