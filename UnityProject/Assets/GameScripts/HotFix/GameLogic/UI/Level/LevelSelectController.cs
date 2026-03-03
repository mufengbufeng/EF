using System;
using System.Collections.Generic;
using EF.Common;
using EF.Debugger;
using EF.UI;

namespace GameLogic
{
    /// <summary>
    /// 关卡选择界面控制器。
    /// </summary>
    public class LevelSelectController : UIController
    {
        private const int TotalLevels = 100;

        private LevelSelectView _view;
        private IEnergyModule _energyModule;
        private ILevelModule _levelModule;

        protected override void OnInitialize()
        {
            base.OnInitialize();
            _view = GetView<LevelSelectView>();
            Log.Info("[LevelSelectController] OnInitialize");
        }

        protected override void OnEnter(object userData)
        {
            base.OnEnter(userData);
            InitializeModules();
            BindViewEvents();
            RefreshUI();
        }

        protected override void OnUpdate(float elapseSeconds, float realElapseSeconds)
        {
            base.OnUpdate(elapseSeconds, realElapseSeconds);

            _energyModule?.Update(elapseSeconds, realElapseSeconds);
            _levelModule?.Update(elapseSeconds, realElapseSeconds);

            if (_view != null && _energyModule != null)
            {
                _view.UpdateEnergy(_energyModule.CurrentEnergy, _energyModule.MaxEnergy);
            }
        }

        protected override void OnExit()
        {
            base.OnExit();
        }

        protected override void OnRelease()
        {
            if (_energyModule != null)
            {
                _energyModule.Shutdown();
                _energyModule = null;
            }

            if (_levelModule != null)
            {
                _levelModule.Shutdown();
                _levelModule = null;
            }

            _view = null;
            base.OnRelease();
        }

        private void InitializeModules()
        {
            _energyModule = ModuleSystem.Get<IEnergyModule>();
            if (_energyModule == null)
            {
                var energy = new EnergyModule();
                energy.Configure(100, 300, 10);
                energy.Initialize();
                ModuleSystem.Register(energy, replace: true);
                _energyModule = energy;
            }

            _levelModule = ModuleSystem.Get<ILevelModule>();
            if (_levelModule == null)
            {
                var level = new LevelModule();
                level.Configure(TotalLevels);
                level.Initialize();
                ModuleSystem.Register(level, replace: true);
                _levelModule = level;
            }
        }

        private void BindViewEvents()
        {
            if (_view == null)
            {
                return;
            }

            BindEvent<Action<int>>(
                h => _view.OnLevelClicked += h,
                h => _view.OnLevelClicked -= h,
                HandleLevelClicked);

            BindEvent<Action>(
                h => _view.OnBackClicked += h,
                h => _view.OnBackClicked -= h,
                HandleBackClicked);
        }

        private void RefreshUI()
        {
            if (_view == null)
            {
                return;
            }

            if (_energyModule != null)
            {
                _view.UpdateEnergy(_energyModule.CurrentEnergy, _energyModule.MaxEnergy);
            }

            if (_levelModule != null)
            {
                Dictionary<int, int> stars = new(_levelModule.GetAllLevelStars());
                _view.InitializeLevels(_levelModule.MaxUnlockedLevelId, stars, TotalLevels);
                _view.UpdateTotalStars(_levelModule.GetTotalStars(), TotalLevels * 3);
            }
        }

        private void HandleLevelClicked(int levelId)
        {
            if (_levelModule == null || _energyModule == null)
            {
                return;
            }

            if (_levelModule.EnterLevel(levelId))
            {
                var procedure = GameLogicEntry.Procedure.GetProcedure<LevelSelectProcedure>();
                procedure?.StartLevelGameplay();
            }

            RefreshUI();
        }

        private void HandleBackClicked()
        {
            var procedure = GameLogicEntry.Procedure.GetProcedure<LevelSelectProcedure>();
            if (procedure != null)
            {
                procedure.BackToMainMenu();
            }
            else
            {
                GameLogicEntry.UI.CloseWindowAsync("LevelSelectView");
            }
        }
    }
}
