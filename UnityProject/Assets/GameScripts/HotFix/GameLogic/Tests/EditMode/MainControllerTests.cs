using System;
using System.Reflection;
using EF.Common;
using EF.Model;
using EF.Procedure;
using EF.UI;
using NUnit.Framework;
using UnityEngine;

namespace GameLogic.Tests.EditMode
{
    [TestFixture]
    public class MainControllerTests
    {
        [SetUp]
        public void SetUp()
        {
            ModuleSystem.ShutdownAll();
            SetProcedureManager(null);
        }

        [TearDown]
        public void TearDown()
        {
            ModuleSystem.ShutdownAll();
            SetProcedureManager(null);
        }

        [Test]
        public void StartGame_WhenEnergyIsInsufficient_ShouldNotSwitchProcedure()
        {
            var energy = new FakeEnergyModule(0, 10);
            var procedureManager = new FakeProcedureManager(hasProcedure: true, procedure: new MainMenuProcedure());
            ModuleSystem.Register<IEnergyModule>(energy, replace: true);
            SetProcedureManager(procedureManager);

            using var harness = new ControllerHarness();

            harness.Controller.StartGame();

            Assert.That(energy.TryConsumeCalls, Is.EqualTo(1));
            Assert.That(energy.LastTryConsumeAmount, Is.EqualTo(1));
            Assert.That(energy.RecoverCalls, Is.EqualTo(0));
            Assert.That(procedureManager.HasProcedureCalls, Is.EqualTo(0));
            Assert.That(procedureManager.GetProcedureCalls, Is.EqualTo(0));
            Assert.That(energy.CurrentEnergy, Is.EqualTo(0));
        }

        [Test]
        public void StartGame_WhenProcedureUnavailable_ShouldRollbackEnergy()
        {
            var energy = new FakeEnergyModule(5, 10);
            var procedureManager = new FakeProcedureManager(hasProcedure: false, procedure: null);
            ModuleSystem.Register<IEnergyModule>(energy, replace: true);
            SetProcedureManager(procedureManager);

            using var harness = new ControllerHarness();

            harness.Controller.StartGame();

            Assert.That(energy.TryConsumeCalls, Is.EqualTo(1));
            Assert.That(energy.RecoverCalls, Is.EqualTo(1));
            Assert.That(procedureManager.HasProcedureCalls, Is.EqualTo(1));
            Assert.That(procedureManager.GetProcedureCalls, Is.EqualTo(0));
            Assert.That(energy.CurrentEnergy, Is.EqualTo(5));
        }

        [Test]
        public void StartGame_WhenProcedureStartFails_ShouldRollbackEnergy()
        {
            var energy = new FakeEnergyModule(5, 10);
            var procedureManager = new FakeProcedureManager(hasProcedure: true, procedure: new MainMenuProcedure());
            ModuleSystem.Register<IEnergyModule>(energy, replace: true);
            SetProcedureManager(procedureManager);

            using var harness = new ControllerHarness();

            harness.Controller.StartGame();

            Assert.That(procedureManager.HasProcedureCalls, Is.EqualTo(1));
            Assert.That(procedureManager.GetProcedureCalls, Is.EqualTo(1));
            Assert.That(energy.RecoverCalls, Is.EqualTo(1));
            Assert.That(energy.CurrentEnergy, Is.EqualTo(5));
        }

        [Test]
        public void StartGame_WhenProcedureReturnsNull_ShouldRollbackEnergy()
        {
            var energy = new FakeEnergyModule(5, 10);
            var procedureManager = new FakeProcedureManager(hasProcedure: true, procedure: null);
            ModuleSystem.Register<IEnergyModule>(energy, replace: true);
            SetProcedureManager(procedureManager);

            using var harness = new ControllerHarness();

            harness.Controller.StartGame();

            Assert.That(procedureManager.HasProcedureCalls, Is.EqualTo(1));
            Assert.That(procedureManager.GetProcedureCalls, Is.EqualTo(1));
            Assert.That(energy.RecoverCalls, Is.EqualTo(1));
            Assert.That(energy.CurrentEnergy, Is.EqualTo(5));
        }

        [Test]
        public void StartGame_WhenProcedureManagerMissing_ShouldRollbackEnergy()
        {
            var energy = new FakeEnergyModule(5, 10);
            ModuleSystem.Register<IEnergyModule>(energy, replace: true);
            SetProcedureManager(null);

            using var harness = new ControllerHarness();

            harness.Controller.StartGame();

            Assert.That(energy.TryConsumeCalls, Is.EqualTo(1));
            Assert.That(energy.RecoverCalls, Is.EqualTo(1));
            Assert.That(energy.CurrentEnergy, Is.EqualTo(5));
        }

        [Test]
        public void StartGame_WhenEnergyModuleMissing_ShouldNotCrashAndSkipProcedure()
        {
            var procedureManager = new FakeProcedureManager(hasProcedure: true, procedure: new MainMenuProcedure());
            SetProcedureManager(procedureManager);

            using var harness = new ControllerHarness();

            Assert.DoesNotThrow(() => harness.Controller.StartGame());
            Assert.That(procedureManager.HasProcedureCalls, Is.EqualTo(0));
            Assert.That(procedureManager.GetProcedureCalls, Is.EqualTo(0));
        }

        private static void SetProcedureManager(IProcedureManager procedureManager)
        {
            var field = typeof(GameLogicEntry).GetField("_procedureManager", BindingFlags.NonPublic | BindingFlags.Static);
            Assert.That(field, Is.Not.Null);
            field.SetValue(null, procedureManager);
        }

        private static object InvokeNonPublic(object target, string methodName, params object[] args)
        {
            Type currentType = target.GetType();
            while (currentType != null)
            {
                var method = currentType.GetMethod(methodName, BindingFlags.Instance | BindingFlags.NonPublic | BindingFlags.Public);
                if (method != null)
                {
                    return method.Invoke(target, args);
                }

                currentType = currentType.BaseType;
            }

            Assert.Fail($"未找到方法: {methodName}");
            return null;
        }

        private sealed class ControllerHarness : IDisposable
        {
            private readonly GameObject _gameObject;
            private readonly UIView _view;

            public ControllerHarness()
            {
                _gameObject = new GameObject("MainControllerTests_MainView");
                _view = _gameObject.AddComponent<TestMainView>();

                var modelManager = new ModelManager();
                modelManager.Register<MainModel>();

                UIRuntimeContext context = CreateRuntimeContext(modelManager, _gameObject.transform);
                InvokeNonPublic(_view, "InternalInitialize", context);

                Controller = new MainController();
                InvokeNonPublic(Controller, "InternalInitialize", _view, context);
                InvokeNonPublic(Controller, "InternalEnter", null);
            }

            public MainController Controller { get; }

            public void Dispose()
            {
                try
                {
                    InvokeNonPublic(Controller, "InternalExit");
                    InvokeNonPublic(Controller, "InternalRelease");
                    Controller.Dispose();
                }
                finally
                {
                    InvokeNonPublic(_view, "InternalRelease");
                    UnityEngine.Object.DestroyImmediate(_gameObject);
                }
            }

            private static UIRuntimeContext CreateRuntimeContext(ModelManager modelManager, Transform layerRoot)
            {
                var ctor = typeof(UIRuntimeContext).GetConstructor(
                    BindingFlags.Instance | BindingFlags.NonPublic,
                    binder: null,
                    types: new[]
                    {
                        typeof(IUIManager),
                        typeof(ModelManager),
                        typeof(UIWindowDescriptor),
                        typeof(Transform)
                    },
                    modifiers: null);

                Assert.That(ctor, Is.Not.Null);
                return (UIRuntimeContext)ctor.Invoke(new object[] { null, modelManager, null, layerRoot });
            }
        }

        private sealed class FakeEnergyModule : IEnergyModule
        {
            private int _currentEnergy;

            public FakeEnergyModule(int currentEnergy, int maxEnergy)
            {
                _currentEnergy = currentEnergy;
                MaxEnergy = maxEnergy;
            }

            public int CurrentEnergy => _currentEnergy;

            public int MaxEnergy { get; }

            public int TryConsumeCalls { get; private set; }

            public int RecoverCalls { get; private set; }

            public int LastTryConsumeAmount { get; private set; }

            public event Action<int, int> OnEnergyChanged;

            public bool CanConsume(int amount)
            {
                if (amount <= 0)
                {
                    return true;
                }

                return _currentEnergy >= amount;
            }

            public bool TryConsume(int amount)
            {
                TryConsumeCalls++;
                LastTryConsumeAmount = amount;

                if (!CanConsume(amount))
                {
                    return false;
                }

                if (amount > 0)
                {
                    _currentEnergy -= amount;
                    OnEnergyChanged?.Invoke(_currentEnergy, MaxEnergy);
                }

                return true;
            }

            public void Recover(int amount)
            {
                RecoverCalls++;
                if (amount <= 0)
                {
                    return;
                }

                _currentEnergy = Mathf.Min(MaxEnergy, _currentEnergy + amount);
                OnEnergyChanged?.Invoke(_currentEnergy, MaxEnergy);
            }

            public void Update(float elapseSeconds, float realElapseSeconds)
            {
            }

            public void Shutdown()
            {
                OnEnergyChanged = null;
            }
        }

        private sealed class FakeProcedureManager : IProcedureManager
        {
            private readonly bool _hasProcedure;
            private readonly MainMenuProcedure _procedure;

            public FakeProcedureManager(bool hasProcedure, MainMenuProcedure procedure)
            {
                _hasProcedure = hasProcedure;
                _procedure = procedure;
            }

            public int HasProcedureCalls { get; private set; }

            public int GetProcedureCalls { get; private set; }

            public ProcedureBase CurrentProcedure => _procedure;

            public float CurrentProcedureTime => 0f;

            public void Initialize(EF.Fsm.IFsmManager fsmManager, params ProcedureBase[] procedures)
            {
            }

            public void StartProcedure<T>() where T : ProcedureBase
            {
            }

            public void StartProcedure(Type procedureType)
            {
            }

            public bool HasProcedure<T>() where T : ProcedureBase
            {
                if (typeof(T) == typeof(MainMenuProcedure))
                {
                    HasProcedureCalls++;
                    return _hasProcedure;
                }

                return false;
            }

            public bool HasProcedure(Type procedureType)
            {
                if (procedureType == typeof(MainMenuProcedure))
                {
                    HasProcedureCalls++;
                    return _hasProcedure;
                }

                return false;
            }

            public T GetProcedure<T>() where T : ProcedureBase
            {
                GetProcedureCalls++;
                return _procedure as T;
            }

            public ProcedureBase GetProcedure(Type procedureType)
            {
                if (procedureType == typeof(MainMenuProcedure))
                {
                    GetProcedureCalls++;
                    return _procedure;
                }

                return null;
            }

            public void Update(float elapseSeconds, float realElapseSeconds)
            {
            }

            public void Shutdown()
            {
            }
        }

        private sealed class TestMainView : MainView
        {
        }
    }
}
