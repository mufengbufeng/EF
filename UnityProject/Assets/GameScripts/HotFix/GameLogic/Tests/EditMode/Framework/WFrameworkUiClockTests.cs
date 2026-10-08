using Cysharp.Threading.Tasks;
using EF.UI.WFramework;
using EF.UI.WFramework.Utils;
using NUnit.Framework;
using System;
using UnityEngine;
using Object = UnityEngine.Object;
using UITimer = EF.UI.WFramework.Utils.Timer;

namespace GameLogic.Tests
{
    /// <summary>
    /// 验证 UI 计时器与准备超时只在 UIManager 帧分发中推进。
    /// </summary>
    public sealed partial class WFrameworkUiIntegrationTests
    {
        /// <summary>
        /// 默认计时器只按逻辑 delta 推进，真实 delta 不影响触发。
        /// </summary>
        [Test]
        public void UITimer_默认计时器_只按逻辑delta推进()
        {
            UIManager.Shutdown();
            GameObject root = CreateRoot("WFrameworkTimerDefaultRoot");
            try
            {
                InitializeCore(root);
                int fired = 0;
                UITimer.Default.Add(0.125f, () => fired++);

                UIManager.Update(0.0625f, 1f, false);
                Assert.That(fired, Is.EqualTo(0));

                UIManager.Update(0.0625f, 0f, false);
                Assert.That(fired, Is.EqualTo(1));

                UIManager.Update(1f, 1f, false);
                Assert.That(fired, Is.EqualTo(1));
            }
            finally
            {
                Object.DestroyImmediate(root);
            }
        }

        /// <summary>
        /// 实时计时器保持墙钟目标语义，但到期回调只在 UI 帧分发时执行。
        /// </summary>
        [Test]
        public void UITimer_实时计时器_到期回调只在帧分发时执行()
        {
            UIManager.Shutdown();
            GameObject root = CreateRoot("WFrameworkTimerRealtimeRoot");
            try
            {
                InitializeCore(root);
                int fired = 0;
                var param = new TimerCore<DateTime, TimeSpan>.Param
                {
                    _mode_delay = false,
                    _target_time = DateTime.MinValue,
                    _times = 1,
                    _on_timer_1 = () => fired++
                };
                UITimer.DefaultRealTime.Add(param);
                Assert.That(fired, Is.EqualTo(0));

                UIManager.Update(0f, 0f, false);
                Assert.That(fired, Is.EqualTo(1));

                UIManager.Update(0f, 0f, false);
                Assert.That(fired, Is.EqualTo(1));
            }
            finally
            {
                Object.DestroyImmediate(root);
            }
        }

        /// <summary>
        /// UI 管理器关闭会清空计时器，重建后旧回调不再执行。
        /// </summary>
        [Test]
        public void UITimer_管理器关闭_清空计时器且重建后旧回调不执行()
        {
            UIManager.Shutdown();
            GameObject firstRoot = CreateRoot("WFrameworkTimerShutdownRootA");
            GameObject secondRoot = CreateRoot("WFrameworkTimerShutdownRootB");
            try
            {
                InitializeCore(firstRoot);
                int fired = 0;
                TimerHandler handler = UITimer.Default.Add(0.125f, () => fired++);
                Assert.IsTrue(handler.IsRunning());

                UIManager.Shutdown();
                Assert.IsFalse(handler.IsRunning());

                InitializeCore(secondRoot);
                UIManager.Update(1f, 1f, false);
                Assert.That(fired, Is.EqualTo(0));
            }
            finally
            {
                Object.DestroyImmediate(firstRoot);
                Object.DestroyImmediate(secondRoot);
            }
        }

        /// <summary>
        /// Prefab 已加载但准备未完成时，按真实 delta 计时并在超时后只终止一次。
        /// </summary>
        [Test]
        public void UIPrepare_准备超时_按真实delta终止一次()
        {
            GameObject root = CreateRoot("WFrameworkPrepareTimeoutRoot");
            try
            {
                var loader = new ProbeLoader();
                loader.Register("Slow", typeof(SlowPrepareLogic));
                InitializeCore(root, loader);
                var options = new PrepareOptions();
                Assert.IsTrue(UIManager.Open("Slow", options));

                UIManager.Update(10f, 0.25f, false);
                Assert.That(options.TerminatedCount, Is.EqualTo(0));

                UIManager.Update(10f, 0.75f, false);
                Assert.That(options.TerminatedCount, Is.EqualTo(1));
                Assert.That(options.OpenedCount, Is.EqualTo(0));

                UIManager.Update(10f, 1f, false);
                Assert.That(options.TerminatedCount, Is.EqualTo(1));
            }
            finally
            {
                Object.DestroyImmediate(root);
            }
        }

        /// <summary>
        /// Prefab 未到达时超时结果先保存，加载到达后关闭并卸载一次。
        /// </summary>
        [Test]
        public void UIPrepare_Prefab未到达时超时_加载到达后关闭并卸载一次()
        {
            GameObject root = CreateRoot("WFrameworkPrepareLateRoot");
            try
            {
                var loader = new DeferredWindowLoader("SlowDeferred", typeof(SlowPrepareLogic));
                InitializeCore(root, loader);
                var options = new PrepareOptions();
                Assert.IsTrue(UIManager.Open("SlowDeferred", options));

                UIManager.Update(0f, 1f, false);
                Assert.That(options.TerminatedCount, Is.EqualTo(0));

                loader.Complete(new GameObject("SlowDeferredLate", typeof(RectTransform)));
                Assert.That(options.TerminatedCount, Is.EqualTo(1));
                Assert.That(options.OpenedCount, Is.EqualTo(0));
                Assert.That(loader.UnloadCount, Is.EqualTo(1));
            }
            finally
            {
                Object.DestroyImmediate(root);
            }
        }

        /// <summary>
        /// 准备超时探针的观测数据。
        /// </summary>
        private sealed class PrepareOptions
        {
            public readonly UniTaskCompletionSource<bool> Completion = new UniTaskCompletionSource<bool>();
            public int OpenedCount;
            public int TerminatedCount;
        }

        /// <summary>
        /// 准备阶段永不自行完成、超时为 1 秒的探针逻辑。
        /// </summary>
        private sealed class SlowPrepareLogic : UIStackLogicBase
        {
            private PrepareOptions _options;

            protected override bool IsFullScreen => false;
            protected override bool NewGroup => true;
            protected override string OpenAnim => null;
            protected override string CloseAnim => null;

            protected override bool OnCreate(object parameter)
            {
                _options = (PrepareOptions)parameter;
                return true;
            }

            protected override bool OnPrepareCheck(ref float timeout, ref bool closeWhenTimeout)
            {
                timeout = 1f;
                return true;
            }

            protected override UniTask<bool> OnPrepareExecute()
            {
                return _options.Completion.Task;
            }

            protected override void OnOpen(GameObject go, int baseSortingOrder)
            {
                _options.OpenedCount++;
            }

            protected override void OnTerminated()
            {
                _options.TerminatedCount++;
            }
        }
    }
}
