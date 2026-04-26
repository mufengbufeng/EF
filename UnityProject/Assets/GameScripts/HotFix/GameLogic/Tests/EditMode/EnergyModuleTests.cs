using System;
using System.Collections.Generic;
using System.Reflection;
using EF.Event;
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
            var eventHub = CreateEventHub();
            var module = new EnergyModule(save, eventHub);

            int eventCount = 0;
            eventHub.EnergyChangedEvent.Subscribe((EnergyChangedEvent e) => eventCount++);

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
            var eventHub = CreateEventHub();
            var module = new EnergyModule(save, eventHub);

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
            var eventHub = CreateEventHub();
            var module = new EnergyModule(save, eventHub);

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
            var eventHub = CreateEventHub();
            var module = new EnergyModule(save, eventHub);
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
            var eventHub = CreateEventHub();
            var module = new EnergyModule(save, eventHub);

            Assert.That(module.TryConsume(2), Is.True);
            module.Recover(1000);

            Assert.That(module.CurrentEnergy, Is.EqualTo(module.MaxEnergy));
        }

        [Test]
        public void LoadOrCreateState_WhenNoSave_ShouldUseDefaultAndPersist()
        {
            var save = new FakeSaveManager();
            var eventHub = CreateEventHub();

            var module = new EnergyModule(save, eventHub);

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
            var eventHub = CreateEventHub();

            var module = new EnergyModule(save, eventHub);

            Assert.That(module.MaxEnergy, Is.EqualTo(10));
            Assert.That(module.CurrentEnergy, Is.EqualTo(10));
            Assert.That(save.SaveCalls.Count, Is.EqualTo(0));
        }

        [Test]
        public void LoadOrCreateState_WhenSavedMaxIsInvalid_ShouldFallbackDefaultAndClampCurrent()
        {
            var save = new FakeSaveManager();
            save.RawStore[SaveKey] = CreatePrivateSaveData(99, 0, 0);
            var eventHub = CreateEventHub();

            var module = new EnergyModule(save, eventHub);

            Assert.That(module.MaxEnergy, Is.EqualTo(10));
            Assert.That(module.CurrentEnergy, Is.EqualTo(10));
        }

        [Test]
        public void LoadOrCreateState_WhenCurrentEnergyOutOfRange_ShouldClampToValidRange()
        {
            var save = new FakeSaveManager();
            save.RawStore[SaveKey] = CreatePrivateSaveData(-8, 20, 0);
            var eventHub = CreateEventHub();

            var module = new EnergyModule(save, eventHub);

            Assert.That(module.MaxEnergy, Is.EqualTo(20));
            Assert.That(module.CurrentEnergy, Is.EqualTo(0));
        }

        [Test]
        public void EnergyChangedEvent_ShouldFireOnConsumeAndRecoverOnly()
        {
            var save = new FakeSaveManager();
            var eventHub = CreateEventHub();
            var module = new EnergyModule(save, eventHub);
            var events = new List<(int current, int max)>();

            eventHub.EnergyChangedEvent.Subscribe((EnergyChangedEvent e) => events.Add((e.Current, e.Max)));

            Assert.That(module.TryConsume(1), Is.True);
            Assert.That(module.TryConsume(0), Is.True);
            module.Recover(0);
            module.Recover(1);

            Assert.That(events.Count, Is.EqualTo(2));
            Assert.That(events[0], Is.EqualTo((9, 10)));
            Assert.That(events[1], Is.EqualTo((10, 10)));
        }

        [Test]
        public void Shutdown_ShouldPersistCurrentState()
        {
            var save = new FakeSaveManager();
            var eventHub = CreateEventHub();
            var module = new EnergyModule(save, eventHub);
            Assert.That(module.TryConsume(1), Is.True);

            module.Shutdown();
            module.Recover(1);

            Assert.That(module.CurrentEnergy, Is.EqualTo(10));
            Assert.That(save.SaveCalls.Count, Is.EqualTo(4));
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
            var eventHub = CreateEventHub();

            var module = new EnergyModule(save, eventHub);

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
            var eventHub = CreateEventHub();

            var module = new EnergyModule(save, eventHub);

            Assert.That(module.CurrentEnergy, Is.EqualTo(5));
        }

        [Test]
        public void OfflineRecovery_FullEnergy_ShouldNotRecover()
        {
            // 体力已满，离线再久也不变
            var save = new FakeSaveManager();
            long pastTimestamp = DateTimeOffset.UtcNow.ToUnixTimeSeconds() - 7200;
            save.RawStore[SaveKey] = CreatePrivateSaveData(10, 10, pastTimestamp);
            var eventHub = CreateEventHub();

            var module = new EnergyModule(save, eventHub);

            Assert.That(module.CurrentEnergy, Is.EqualTo(10));
        }

        [Test]
        public void OfflineRecovery_ShouldClampToMax()
        {
            // 体力 8/10，离线 7200 秒（可恢复 20 点），但只能恢复到 10
            var save = new FakeSaveManager();
            long pastTimestamp = DateTimeOffset.UtcNow.ToUnixTimeSeconds() - 7200;
            save.RawStore[SaveKey] = CreatePrivateSaveData(8, 10, pastTimestamp);
            var eventHub = CreateEventHub();

            var module = new EnergyModule(save, eventHub);

            Assert.That(module.CurrentEnergy, Is.EqualTo(10));
        }

        #endregion

        #region 旧存档兼容测试

        [Test]
        public void LoadOrCreateState_WhenMissingTimestamp_ShouldNotCrash()
        {
            var save = new FakeSaveManager();
            save.RawStore[SaveKey] = CreatePrivateSaveData(5, 10, 0);
            var eventHub = CreateEventHub();

            var module = new EnergyModule(save, eventHub);

            Assert.That(module.CurrentEnergy, Is.EqualTo(5));
            Assert.That(module.MaxEnergy, Is.EqualTo(10));
        }

        #endregion

        #region 恢复状态属性测试

        [Test]
        public void IsRecovering_WhenNotFull_ShouldReturnTrue()
        {
            var save = new FakeSaveManager();
            var eventHub = CreateEventHub();
            var module = new EnergyModule(save, eventHub);
            Assert.That(module.TryConsume(3), Is.True);

            Assert.That(module.IsRecovering, Is.True);
        }

        [Test]
        public void IsRecovering_WhenFull_ShouldReturnFalse()
        {
            var save = new FakeSaveManager();
            var eventHub = CreateEventHub();
            var module = new EnergyModule(save, eventHub);

            Assert.That(module.IsRecovering, Is.False);
        }

        [Test]
        public void TimeToNextRecovery_WhenFull_ShouldReturnZero()
        {
            var save = new FakeSaveManager();
            var eventHub = CreateEventHub();
            var module = new EnergyModule(save, eventHub);

            Assert.That(module.TimeToNextRecovery, Is.EqualTo(0f));
        }

        [Test]
        public void TimeToNextRecovery_WhenNotFull_ShouldBePositive()
        {
            var save = new FakeSaveManager();
            var eventHub = CreateEventHub();
            var module = new EnergyModule(save, eventHub);
            Assert.That(module.TryConsume(1), Is.True);

            Assert.That(module.TimeToNextRecovery, Is.GreaterThan(0f));
            Assert.That(module.TimeToNextRecovery, Is.LessThanOrEqualTo(module.RecoveryIntervalSeconds));
        }

        [Test]
        public void RecoveryIntervalSeconds_ShouldBe360()
        {
            var save = new FakeSaveManager();
            var eventHub = CreateEventHub();
            var module = new EnergyModule(save, eventHub);

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
            var eventHub = CreateEventHub();

            var module = new EnergyModule(save, eventHub);

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
            var eventHub = CreateEventHub();

            var module = new EnergyModule(save, eventHub);
            Assert.That(module.CurrentEnergy, Is.EqualTo(5));

            Assert.That(module.TryConsume(1), Is.True);

            // 消耗后应该是 4，时间戳被刷新
            Assert.That(module.CurrentEnergy, Is.EqualTo(4));
        }

        #endregion

        #region 辅助方法

        private static EventHub CreateEventHub()
        {
            return new EventHub();
        }

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

namespace GameLogic.Tests.EditMode
{
    [TestFixture]
    public class EventHubLifecycleTests
    {
        [Test]
        public void GetAllChannelInfos_WhenHubJustConstructed_ShouldKeepAllChannelsUninitialized()
        {
            var hub = new EventHub();

            var infos = hub.GetAllChannelInfos();

            Assert.That(infos, Is.Not.Null);
            Assert.That(infos.Length, Is.EqualTo(5));
            Assert.That(GetCreatedChannelCount(hub), Is.EqualTo(0));

            for (int i = 0; i < infos.Length; i++)
            {
                Assert.That(infos[i].State, Is.EqualTo(EventChannelLifecycleState.Uninitialized));
                Assert.That(infos[i].HandlerCount, Is.EqualTo(0));
                Assert.That(infos[i].PendingCount, Is.EqualTo(0));
            }
        }

        [Test]
        public void AccessingChannel_ShouldLazilyCreateSingleInstanceAndReportIdleState()
        {
            var hub = new EventHub();

            var first = hub.EnergyChangedEvent;
            var second = hub.EnergyChangedEvent;
            var info = GetChannelInfo(hub, nameof(EnergyChangedEvent));

            Assert.That(first, Is.SameAs(second));
            Assert.That(GetCreatedChannelCount(hub), Is.EqualTo(1));
            Assert.That(info.State, Is.EqualTo(EventChannelLifecycleState.Idle));
            Assert.That(info.HandlerCount, Is.EqualTo(0));
            Assert.That(info.PendingCount, Is.EqualTo(0));
        }

        [Test]
        public void EnqueueThenUpdate_ShouldActivateAndDrainOnlyActiveChannel()
        {
            var hub = new EventHub();
            int invokeCount = 0;

            hub.BeforeSceneEnterEvent.Subscribe((BeforeSceneEnterEvent _) => invokeCount++);

            Assert.That(GetActiveChannelCount(hub), Is.EqualTo(0));

            hub.BeforeSceneEnterEvent.Enqueue(new BeforeSceneEnterEvent("Battle"));

            Assert.That(GetChannelInfo(hub, nameof(BeforeSceneEnterEvent)).State, Is.EqualTo(EventChannelLifecycleState.Active));
            Assert.That(GetActiveChannelCount(hub), Is.EqualTo(1));

            hub.Update(0f, 0f);

            Assert.That(invokeCount, Is.EqualTo(1));
            Assert.That(GetChannelInfo(hub, nameof(BeforeSceneEnterEvent)).State, Is.EqualTo(EventChannelLifecycleState.Idle));
            Assert.That(GetActiveChannelCount(hub), Is.EqualTo(0));
        }

        [Test]
        public void SynchronousPublish_ShouldNotEnterActiveAsyncChannelSet()
        {
            var hub = new EventHub();
            int invokeCount = 0;

            hub.LevelCompleteEvent.Subscribe((LevelCompleteEvent _) => invokeCount++);

            Assert.That(GetActiveChannelCount(hub), Is.EqualTo(0));

            hub.LevelCompleteEvent.Publish(new LevelCompleteEvent());
            hub.Update(0f, 0f);

            Assert.That(invokeCount, Is.EqualTo(1));
            Assert.That(GetActiveChannelCount(hub), Is.EqualTo(0));
            Assert.That(GetChannelInfo(hub, nameof(LevelCompleteEvent)).State, Is.EqualTo(EventChannelLifecycleState.Idle));
        }

        [Test]
        public void Shutdown_ShouldClearCreatedChannelsAndPreserveUntouchedChannelsAsUninitialized()
        {
            var hub = new EventHub();

            hub.BeforeSceneEnterEvent.Subscribe((BeforeSceneEnterEvent _) => { });
            hub.BeforeSceneEnterEvent.Enqueue(new BeforeSceneEnterEvent("Lobby"));
            hub.LevelProgressChangedEvent.Subscribe((LevelProgressChangedEvent _) => { });

            Assert.That(GetActiveChannelCount(hub), Is.EqualTo(1));
            Assert.That(GetCreatedChannelCount(hub), Is.EqualTo(2));

            hub.Shutdown();

            var beforeSceneInfo = GetChannelInfo(hub, nameof(BeforeSceneEnterEvent));
            var levelProgressInfo = GetChannelInfo(hub, nameof(LevelProgressChangedEvent));
            var untouchedInfo = GetChannelInfo(hub, nameof(SceneEnterEvent));

            Assert.That(beforeSceneInfo.State, Is.EqualTo(EventChannelLifecycleState.Idle));
            Assert.That(beforeSceneInfo.HandlerCount, Is.EqualTo(0));
            Assert.That(beforeSceneInfo.PendingCount, Is.EqualTo(0));

            Assert.That(levelProgressInfo.State, Is.EqualTo(EventChannelLifecycleState.Idle));
            Assert.That(levelProgressInfo.HandlerCount, Is.EqualTo(0));
            Assert.That(levelProgressInfo.PendingCount, Is.EqualTo(0));

            Assert.That(untouchedInfo.State, Is.EqualTo(EventChannelLifecycleState.Uninitialized));
            Assert.That(GetActiveChannelCount(hub), Is.EqualTo(0));
            Assert.That(GetCreatedChannelCount(hub), Is.EqualTo(2));
        }

        private static IEventChannelInfo GetChannelInfo(EventHub hub, string eventName)
        {
            var infos = hub.GetAllChannelInfos();
            for (int i = 0; i < infos.Length; i++)
            {
                if (infos[i].EventName == eventName)
                {
                    return infos[i];
                }
            }

            Assert.Fail($"未找到事件信息: {eventName}");
            return null;
        }

        private static int GetCreatedChannelCount(EventHub hub)
        {
            int count = 0;
            var fields = typeof(EventHub).GetFields(BindingFlags.Instance | BindingFlags.NonPublic);
            for (int i = 0; i < fields.Length; i++)
            {
                var fieldType = fields[i].FieldType;
                if (!fieldType.IsGenericType || fieldType.GetGenericTypeDefinition() != typeof(EventChannel<>))
                {
                    continue;
                }

                if (fields[i].GetValue(hub) != null)
                {
                    count++;
                }
            }

            return count;
        }

        private static int GetActiveChannelCount(EventHub hub)
        {
            var field = typeof(EventHub).GetField("_activeChannels", BindingFlags.Instance | BindingFlags.NonPublic);
            Assert.That(field, Is.Not.Null);

            var value = field.GetValue(hub) as System.Collections.ICollection;
            Assert.That(value, Is.Not.Null);
            return value.Count;
        }
    }
}
