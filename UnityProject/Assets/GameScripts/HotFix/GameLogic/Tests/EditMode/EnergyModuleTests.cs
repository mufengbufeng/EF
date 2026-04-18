using System;
using System.Collections.Generic;
using System.Reflection;
using EF.Save;
using NUnit.Framework;

namespace GameLogic.Tests.EditMode
{
    [TestFixture]
    public class EnergyModuleTests
    {
        private const string SaveKey = "game_logic_energy_state";

        #region 原有测试

        [Test]
        public void TryConsume_WhenAmountIsZero_ShouldSucceedAndNotChangeEnergy()
        {
            var save = new FakeSaveManager();
            var module = new EnergyModule(save);

            int eventCount = 0;
            module.OnEnergyChanged += (_, _) => eventCount++;

            bool result = module.TryConsume(0);

            Assert.That(result, Is.True);
            Assert.That(module.CurrentEnergy, Is.EqualTo(module.MaxEnergy));
            Assert.That(eventCount, Is.EqualTo(0));
            Assert.That(save.SaveCalls.Count, Is.EqualTo(1));
        }

        [Test]
        public void TryConsume_WhenAmountIsNegative_ShouldSucceedAndNotChangeEnergy()
        {
            var save = new FakeSaveManager();
            var module = new EnergyModule(save);

            int current = module.CurrentEnergy;
            bool result = module.TryConsume(-3);

            Assert.That(result, Is.True);
            Assert.That(module.CurrentEnergy, Is.EqualTo(current));
            Assert.That(save.SaveCalls.Count, Is.EqualTo(1));
        }

        [Test]
        public void TryConsume_WhenEnergyIsInsufficient_ShouldFailAndNotPersist()
        {
            var save = new FakeSaveManager();
            var module = new EnergyModule(save);

            Assert.That(module.TryConsume(module.MaxEnergy), Is.True);
            int saveCountAfterDrain = save.SaveCalls.Count;

            bool result = module.TryConsume(1);

            Assert.That(result, Is.False);
            Assert.That(module.CurrentEnergy, Is.EqualTo(0));
            Assert.That(save.SaveCalls.Count, Is.EqualTo(saveCountAfterDrain));
        }

        [Test]
        public void Recover_WhenAmountIsZeroOrNegative_ShouldNotChangeEnergy()
        {
            var save = new FakeSaveManager();
            var module = new EnergyModule(save);
            Assert.That(module.TryConsume(4), Is.True);
            int current = module.CurrentEnergy;
            int saveCount = save.SaveCalls.Count;

            module.Recover(0);
            module.Recover(-10);

            Assert.That(module.CurrentEnergy, Is.EqualTo(current));
            Assert.That(save.SaveCalls.Count, Is.EqualTo(saveCount));
        }

        [Test]
        public void Recover_WhenExceedMax_ShouldClampToMax()
        {
            var save = new FakeSaveManager();
            var module = new EnergyModule(save);

            Assert.That(module.TryConsume(2), Is.True);
            module.Recover(1000);

            Assert.That(module.CurrentEnergy, Is.EqualTo(module.MaxEnergy));
        }

        [Test]
        public void LoadOrCreateState_WhenNoSave_ShouldUseDefaultAndPersist()
        {
            var save = new FakeSaveManager();

            var module = new EnergyModule(save);

            Assert.That(module.MaxEnergy, Is.EqualTo(10));
            Assert.That(module.CurrentEnergy, Is.EqualTo(10));
            Assert.That(save.SaveCalls.Count, Is.EqualTo(1));
            Assert.That(save.HasKey(SaveKey), Is.True);
        }

        [Test]
        public void LoadOrCreateState_WhenSaveDataIsNull_ShouldUseDefaultWithoutOverwrite()
        {
            var save = new FakeSaveManager();
            save.RawStore[SaveKey] = null;

            var module = new EnergyModule(save);

            Assert.That(module.MaxEnergy, Is.EqualTo(10));
            Assert.That(module.CurrentEnergy, Is.EqualTo(10));
            Assert.That(save.SaveCalls.Count, Is.EqualTo(0));
        }

        [Test]
        public void LoadOrCreateState_WhenSavedMaxIsInvalid_ShouldFallbackDefaultAndClampCurrent()
        {
            var save = new FakeSaveManager();
            save.RawStore[SaveKey] = CreatePrivateSaveData(99, 0, 0);

            var module = new EnergyModule(save);

            Assert.That(module.MaxEnergy, Is.EqualTo(10));
            Assert.That(module.CurrentEnergy, Is.EqualTo(10));
        }

        [Test]
        public void LoadOrCreateState_WhenCurrentEnergyOutOfRange_ShouldClampToValidRange()
        {
            var save = new FakeSaveManager();
            save.RawStore[SaveKey] = CreatePrivateSaveData(-8, 20, 0);

            var module = new EnergyModule(save);

            Assert.That(module.MaxEnergy, Is.EqualTo(20));
            Assert.That(module.CurrentEnergy, Is.EqualTo(0));
        }

        [Test]
        public void OnEnergyChanged_ShouldFireOnConsumeAndRecoverOnly()
        {
            var save = new FakeSaveManager();
            var module = new EnergyModule(save);
            var events = new List<(int current, int max)>();

            module.OnEnergyChanged += (current, max) => events.Add((current, max));

            Assert.That(module.TryConsume(1), Is.True);
            Assert.That(module.TryConsume(0), Is.True);
            module.Recover(0);
            module.Recover(1);

            Assert.That(events.Count, Is.EqualTo(2));
            Assert.That(events[0], Is.EqualTo((9, 10)));
            Assert.That(events[1], Is.EqualTo((10, 10)));
        }

        [Test]
        public void Shutdown_ShouldPersistAndClearEventHandlers()
        {
            var save = new FakeSaveManager();
            var module = new EnergyModule(save);
            Assert.That(module.TryConsume(1), Is.True);

            int events = 0;
            module.OnEnergyChanged += (_, _) => events++;

            module.Shutdown();
            module.Recover(1);

            Assert.That(module.CurrentEnergy, Is.EqualTo(10));
            Assert.That(save.SaveCalls.Count, Is.EqualTo(4));
            Assert.That(events, Is.EqualTo(0));
        }

        #endregion

        #region 离线补偿测试

        [Test]
        public void OfflineRecovery_LongOffline_ShouldRecoverCorrectAmountNotExceedMax()
        {
            // 关闭时体力 3/10，离线 1800 秒（5 个恢复周期），应恢复 5 点
            var save = new FakeSaveManager();
            long pastTimestamp = DateTimeOffset.UtcNow.ToUnixTimeSeconds() - 1800;
            save.RawStore[SaveKey] = CreatePrivateSaveData(3, 10, pastTimestamp);

            var module = new EnergyModule(save);

            Assert.That(module.CurrentEnergy, Is.EqualTo(8));
            Assert.That(module.MaxEnergy, Is.EqualTo(10));
        }

        [Test]
        public void OfflineRecovery_ShortOffline_ShouldNotRecover()
        {
            // 离线 200 秒（不足 360 秒），不恢复
            var save = new FakeSaveManager();
            long pastTimestamp = DateTimeOffset.UtcNow.ToUnixTimeSeconds() - 200;
            save.RawStore[SaveKey] = CreatePrivateSaveData(5, 10, pastTimestamp);

            var module = new EnergyModule(save);

            Assert.That(module.CurrentEnergy, Is.EqualTo(5));
        }

        [Test]
        public void OfflineRecovery_FullEnergy_ShouldNotRecover()
        {
            // 体力已满，离线再久也不变
            var save = new FakeSaveManager();
            long pastTimestamp = DateTimeOffset.UtcNow.ToUnixTimeSeconds() - 7200;
            save.RawStore[SaveKey] = CreatePrivateSaveData(10, 10, pastTimestamp);

            var module = new EnergyModule(save);

            Assert.That(module.CurrentEnergy, Is.EqualTo(10));
        }

        [Test]
        public void OfflineRecovery_ShouldClampToMax()
        {
            // 体力 8/10，离线 7200 秒（可恢复 20 点），但只能恢复到 10
            var save = new FakeSaveManager();
            long pastTimestamp = DateTimeOffset.UtcNow.ToUnixTimeSeconds() - 7200;
            save.RawStore[SaveKey] = CreatePrivateSaveData(8, 10, pastTimestamp);

            var module = new EnergyModule(save);

            Assert.That(module.CurrentEnergy, Is.EqualTo(10));
        }

        #endregion

        #region 旧存档兼容测试

        [Test]
        public void LoadOrCreateState_WhenMissingTimestamp_ShouldNotCrash()
        {
            var save = new FakeSaveManager();
            save.RawStore[SaveKey] = CreatePrivateSaveData(5, 10, 0);

            var module = new EnergyModule(save);

            Assert.That(module.CurrentEnergy, Is.EqualTo(5));
            Assert.That(module.MaxEnergy, Is.EqualTo(10));
        }

        #endregion

        #region 恢复状态属性测试

        [Test]
        public void IsRecovering_WhenNotFull_ShouldReturnTrue()
        {
            var save = new FakeSaveManager();
            var module = new EnergyModule(save);
            Assert.That(module.TryConsume(3), Is.True);

            Assert.That(module.IsRecovering, Is.True);
        }

        [Test]
        public void IsRecovering_WhenFull_ShouldReturnFalse()
        {
            var save = new FakeSaveManager();
            var module = new EnergyModule(save);

            Assert.That(module.IsRecovering, Is.False);
        }

        [Test]
        public void TimeToNextRecovery_WhenFull_ShouldReturnZero()
        {
            var save = new FakeSaveManager();
            var module = new EnergyModule(save);

            Assert.That(module.TimeToNextRecovery, Is.EqualTo(0f));
        }

        [Test]
        public void TimeToNextRecovery_WhenNotFull_ShouldBePositive()
        {
            var save = new FakeSaveManager();
            var module = new EnergyModule(save);
            Assert.That(module.TryConsume(1), Is.True);

            Assert.That(module.TimeToNextRecovery, Is.GreaterThan(0f));
            Assert.That(module.TimeToNextRecovery, Is.LessThanOrEqualTo(module.RecoveryIntervalSeconds));
        }

        [Test]
        public void RecoveryIntervalSeconds_ShouldBe360()
        {
            var save = new FakeSaveManager();
            var module = new EnergyModule(save);

            Assert.That(module.RecoveryIntervalSeconds, Is.EqualTo(360));
        }

        #endregion

        #region 时间戳计算测试

        [Test]
        public void CurrentEnergy_ShouldIncreaseOverTimeWithoutTimer()
        {
            // 保存一个体力为 3 的快照，时间戳在 720 秒前（2 个恢复周期）
            var save = new FakeSaveManager();
            long pastTimestamp = DateTimeOffset.UtcNow.ToUnixTimeSeconds() - 720;
            save.RawStore[SaveKey] = CreatePrivateSaveData(3, 10, pastTimestamp);

            var module = new EnergyModule(save);

            // 应该恢复 2 点
            Assert.That(module.CurrentEnergy, Is.EqualTo(5));
        }

        [Test]
        public void TryConsume_RefreshesSnapshotBeforeConsuming()
        {
            // 快照 3，时间在 720 秒前（应恢复 2 点 = 5），然后消耗 1 点
            var save = new FakeSaveManager();
            long pastTimestamp = DateTimeOffset.UtcNow.ToUnixTimeSeconds() - 720;
            save.RawStore[SaveKey] = CreatePrivateSaveData(3, 10, pastTimestamp);

            var module = new EnergyModule(save);
            Assert.That(module.CurrentEnergy, Is.EqualTo(5));

            Assert.That(module.TryConsume(1), Is.True);

            // 消耗后应该是 4，时间戳被刷新
            Assert.That(module.CurrentEnergy, Is.EqualTo(4));
        }

        #endregion

        #region 辅助方法

        private static object CreatePrivateSaveData(int baseEnergy, int maxEnergy, long baseTimestamp)
        {
            Type saveDataType = typeof(EnergyModule).GetNestedType("EnergySaveData", BindingFlags.NonPublic);
            Assert.That(saveDataType, Is.Not.Null);

            object saveData = Activator.CreateInstance(saveDataType);
            saveDataType.GetField("baseEnergy", BindingFlags.Instance | BindingFlags.Public)?.SetValue(saveData, baseEnergy);
            saveDataType.GetField("maxEnergy", BindingFlags.Instance | BindingFlags.Public)?.SetValue(saveData, maxEnergy);
            saveDataType.GetField("baseTimestamp", BindingFlags.Instance | BindingFlags.Public)?.SetValue(saveData, baseTimestamp);
            return saveData;
        }

        private sealed class FakeSaveManager : ISaveManager
        {
            public SaveStrategyType CurrentStrategyType => SaveStrategyType.Json;

            public Dictionary<string, object> RawStore { get; } = new Dictionary<string, object>();

            public List<string> SaveCalls { get; } = new List<string>();

            public void SetSaveStrategy(SaveStrategyType strategyType)
            {
            }

            public bool Save<T>(string key, T data)
            {
                RawStore[key] = data;
                SaveCalls.Add(key);
                return true;
            }

            public T Load<T>(string key, T defaultValue = default)
            {
                if (RawStore.TryGetValue(key, out object value))
                {
                    if (value == null)
                    {
                        return default;
                    }

                    if (value is T typed)
                    {
                        return typed;
                    }
                }

                return defaultValue;
            }

            public bool HasKey(string key)
            {
                return RawStore.ContainsKey(key);
            }

            public bool Delete(string key)
            {
                return RawStore.Remove(key);
            }

            public void DeleteAll()
            {
                RawStore.Clear();
            }

            public void Update(float elapseSeconds, float realElapseSeconds)
            {
            }

            public void Shutdown()
            {
            }
        }

        #endregion
    }
}
