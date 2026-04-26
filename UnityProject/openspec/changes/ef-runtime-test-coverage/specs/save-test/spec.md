## ADDED Requirements

### Requirement: Save 保存数据
SaveManager SHALL 通过当前策略保存数据。

#### Scenario: Save 后 HasKey 返回 true
- **WHEN** 调用 Save("key", data)
- **THEN** HasKey("key") 返回 true

### Requirement: Load 加载数据
SaveManager SHALL 通过当前策略加载已保存的数据。

#### Scenario: 加载已保存的数据
- **WHEN** 先 Save("key", value) 后 Load<T>("key")
- **THEN** 返回 value

#### Scenario: 加载不存在的 key 返回 default
- **WHEN** 调用 Load<T>("nonexistent", defaultValue)
- **THEN** 返回 defaultValue

### Requirement: SetSaveStrategy 策略切换
SaveManager SHALL 支持动态切换存储策略。

#### Scenario: 切换后使用新策略
- **WHEN** 调用 SetSaveStrategy(SaveStrategyType.PlayerPrefs)
- **THEN** CurrentStrategyType 变为 PlayerPrefs

### Requirement: Delete 删除数据
SaveManager SHALL 支持通过 Delete 删除指定 key 的数据。

#### Scenario: 删除后 HasKey 返回 false
- **WHEN** 先 Save("key", data) 后 Delete("key")
- **THEN** HasKey("key") 返回 false

### Requirement: DeleteAll 清空所有数据
SaveManager SHALL 支持通过 DeleteAll 清空所有已保存数据。

#### Scenario: 清空后所有 key 不存在
- **WHEN** 保存多个 key 后调用 DeleteAll()
- **THEN** 所有 HasKey 返回 false

### Requirement: Shutdown 清理
SaveManager SHALL 通过 Shutdown 清理资源。

#### Scenario: Shutdown 后状态干净
- **WHEN** 调用 Shutdown()
- **THEN** 无异常，Manager 可安全释放
