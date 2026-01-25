using System;
using EF.Debugger;
using EF.UI;
using UnityEngine;
using UnityEngine.UI;

namespace GameLogic
{
    /// <summary>
    /// 游戏主界面视图
    /// 使用 UHub 实现自动组件绑定和事件管理
    /// </summary>
    public class MainView : UIView
    {
        // 使用 UHub 自动绑定，字段名 _startGameBtn 映射到 ReferenceCollector 中的 "StartGameBtn"
        public Button _startGameBtn;

        /// <summary>
        /// 开始游戏事件
        /// </summary>
        public event Action OnStartGameRequested;

        protected override void OnInitialize()
        {
            base.OnInitialize();
            UHub.Initialize();
            // UHub 会自动绑定 _startGameBtn 到 "StartGameBtn" 组件
            // 无需手动从 ReferenceCollector 获取组件引用
        }

        protected override void OnBindings()
        {
            base.OnBindings();

            // 使用 UHub 统一事件管理，会在 UIView 释放时自动清理
            if (_startGameBtn != null)
            {
                BindEvent(_startGameBtn.onClick, OnStartGameButtonClicked);
            }

            // 记录 UHub 状态用于调试
            Log.Info($"[MainView] UHub 初始化完成，绑定了 {UHub.EventBindingCount} 个事件");
        }

        protected override void OnOpen(object userData)
        {
            base.OnOpen(userData);

            // 验证组件绑定结果
            if (_startGameBtn != null)
            {
                Log.Info("[MainView] 开始游戏按钮组件绑定成功");
            }
            else
            {
                Log.Warning("[MainView] 开始游戏按钮组件绑定失败，请检查 ReferenceCollector 配置");
            }
        }

        protected override void OnRefresh(object userData)
        {
            base.OnRefresh(userData);

            // 根据模型状态刷新界面
            if (TryGetModelData<IMainModelData>(out var modelData))
            {
                // 更新按钮可交互状态
                if (_startGameBtn != null)
                {
                    _startGameBtn.interactable = modelData.IsInteractable;
                }
            }
        }

        private void OnStartGameButtonClicked()
        {
            Log.Info("[MainView] 开始游戏按钮被点击");

            // 触发开始游戏事件，让Controller处理具体逻辑
            OnStartGameRequested?.Invoke();

        }

        protected override void OnRelease()
        {
            // 清理 C# 事件订阅 (UHub 只管理 Unity 事件)
            OnStartGameRequested = null;

            // UHub 会自动清理所有通过 BindEvent 绑定的 Unity 事件
            // 无需手动调用 _startGameBtn.onClick.RemoveListener

            base.OnRelease();
        }
    }
}