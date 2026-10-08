using Cysharp.Threading.Tasks;
using EF.UI.WFramework;
using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Text.RegularExpressions;
using UnityEngine;
using UnityEngine.TestTools;
using Object = UnityEngine.Object;

namespace GameLogic.Tests
{
    /// <summary>
    /// 验证 W-Framework UI 通过 UIManager.Update 统一分发 Logic 与 Window 帧回调。
    /// </summary>
    public sealed partial class WFrameworkUiIntegrationTests
    {
        private static readonly List<string> s_frameLog = new List<string>();

        /// <summary>
        /// 可见窗口每帧只更新一次，Logic 先于 Window，两种 delta 原样传递。
        /// </summary>
        [Test]
        public void FrameUpdate_可见窗口_Logic先于Window且传递原始delta()
        {
            GameObject root = CreateRoot("WFrameworkFrameOrderRoot");
            try
            {
                ProbeLoader loader = InitializeProbe(root);
                loader.Register("Main", typeof(ProbeStackLogic));
                ProbeOptions main = OpenProbe("Main", new ProbeOptions("Main"));

                UIManager.Update(0.25f, 0.5f, false);

                CollectionAssert.AreEqual(new[] { "logic:Main", "window:Main" }, s_frameLog);
                Assert.That(main.Window.Elapsed, Is.EqualTo(0.25f));
                Assert.That(main.Window.RealElapsed, Is.EqualTo(0.5f));

                UIManager.Update(0.25f, 0.5f, false);
                Assert.That(main.LogicUpdates, Is.EqualTo(2));
                Assert.That(main.Window.Updates, Is.EqualTo(2));
                Assert.That(main.Window.Elapsed, Is.EqualTo(0.5f));
            }
            finally
            {
                Object.DestroyImmediate(root);
            }
        }

        /// <summary>
        /// 被全屏窗口隐藏时停止更新，关闭覆盖层后的下一帧恢复，且不补发隐藏期间的时间。
        /// </summary>
        [Test]
        public void FrameUpdate_全屏覆盖隐藏_停止更新且恢复后不补发时间(
            [Values(eUIVisibleOperateType.SetActive, eUIVisibleOperateType.LayerMask, eUIVisibleOperateType.OutOfScreen)]
            eUIVisibleOperateType visibility)
        {
            GameObject root = CreateRoot("WFrameworkFrameHideRoot");
            try
            {
                ProbeLoader loader = InitializeProbe(root);
                loader.Register("Base", typeof(ProbeStackLogic));
                loader.Register("Cover", typeof(ProbeStackLogic));
                ProbeOptions bottom = OpenProbe("Base", new ProbeOptions("Base") { Visibility = visibility });
                UIManager.Update(0.25f, 0.5f, false);

                ProbeOptions cover = OpenProbe("Cover", new ProbeOptions("Cover") { FullScreen = true });
                UIManager.Update(0.25f, 0.5f, false);
                UIManager.Update(0.25f, 0.5f, false);

                Assert.That(bottom.LogicUpdates, Is.EqualTo(1));
                Assert.That(bottom.Window.Updates, Is.EqualTo(1));
                Assert.That(cover.LogicUpdates, Is.EqualTo(2));

                Assert.IsTrue(UIManager.CloseSingle("Cover"));
                UIManager.Update(0.25f, 0.5f, false);

                Assert.That(bottom.LogicUpdates, Is.EqualTo(2));
                Assert.That(bottom.Window.Updates, Is.EqualTo(2));
                Assert.That(bottom.Window.Elapsed, Is.EqualTo(0.5f));
            }
            finally
            {
                Object.DestroyImmediate(root);
            }
        }

        /// <summary>
        /// 固定窗口按插入顺序先更新，堆叠窗口由底至顶更新；非全屏浮层不会停止下层窗口。
        /// </summary>
        [Test]
        public void FrameUpdate_固定与堆叠共存_固定优先且堆叠由底至顶()
        {
            GameObject root = CreateRoot("WFrameworkFrameMixedRoot");
            try
            {
                ProbeLoader loader = InitializeProbe(root);
                loader.Register("Bottom", typeof(ProbeStackLogic));
                loader.Register("Top", typeof(ProbeStackLogic));
                loader.Register("Hud", typeof(ProbeFixedLogic));
                OpenProbe("Bottom", new ProbeOptions("Bottom"));
                OpenProbe("Top", new ProbeOptions("Top"));
                OpenProbe("Hud", new ProbeOptions("Hud"));

                UIManager.Update(0.25f, 0.5f, false);

                CollectionAssert.AreEqual(
                    new[] { "logic:Hud", "window:Hud", "logic:Bottom", "window:Bottom", "logic:Top", "window:Top" },
                    s_frameLog);
            }
            finally
            {
                Object.DestroyImmediate(root);
            }
        }

        /// <summary>
        /// 组件禁用只停止该组件；根节点失活停止整个实例；没有 Window 绑定的根仍更新 Logic。
        /// </summary>
        [Test]
        public void FrameUpdate_组件禁用与根节点失活_按范围停止更新()
        {
            GameObject root = CreateRoot("WFrameworkFrameActiveRoot");
            try
            {
                ProbeLoader loader = InitializeProbe(root);
                loader.Register("Main", typeof(ProbeStackLogic));
                loader.Register("Bare", typeof(ProbeStackLogic), false);
                ProbeOptions main = OpenProbe("Main", new ProbeOptions("Main"));
                ProbeOptions bare = OpenProbe("Bare", new ProbeOptions("Bare"));
                Assert.IsNull(bare.Window);

                main.Window.enabled = false;
                UIManager.Update(0.25f, 0.5f, false);
                Assert.That(main.LogicUpdates, Is.EqualTo(1));
                Assert.That(main.Window.Updates, Is.EqualTo(0));
                Assert.That(bare.LogicUpdates, Is.EqualTo(1));

                main.Window.enabled = true;
                main.Root.SetActive(false);
                UIManager.Update(0.25f, 0.5f, false);
                Assert.That(main.LogicUpdates, Is.EqualTo(1));
                Assert.That(main.Window.Updates, Is.EqualTo(0));
                Assert.That(bare.LogicUpdates, Is.EqualTo(2));
            }
            finally
            {
                Object.DestroyImmediate(root);
            }
        }

        /// <summary>
        /// 回调关闭自身或后续窗口后，被关闭目标在本帧剩余的钩子不再执行。
        /// </summary>
        [Test]
        public void FrameUpdate_回调关闭自身或后续窗口_被关闭目标不再执行()
        {
            GameObject root = CreateRoot("WFrameworkFrameCloseRoot");
            try
            {
                ProbeLoader loader = InitializeProbe(root);
                loader.Register("A", typeof(ProbeStackLogic));
                loader.Register("B", typeof(ProbeStackLogic));
                loader.Register("C", typeof(ProbeStackLogic));
                ProbeOptions a = OpenProbe("A", new ProbeOptions("A"));
                ProbeOptions b = OpenProbe("B", new ProbeOptions("B"));
                ProbeOptions c = OpenProbe("C", new ProbeOptions("C"));
                a.OnLogicUpdate = () => UIManager.CloseSingle("C");
                b.OnLogicUpdate = () => UIManager.CloseSingle("B");

                UIManager.Update(0.25f, 0.5f, false);

                CollectionAssert.AreEqual(new[] { "logic:A", "window:A", "logic:B" }, s_frameLog);
                Assert.That(c.LogicUpdates, Is.EqualTo(0));
            }
            finally
            {
                Object.DestroyImmediate(root);
            }
        }

        /// <summary>
        /// 本帧新开、关闭后缓存重开、隐藏后恢复的实例都从下一帧开始更新。
        /// </summary>
        [Test]
        public void FrameUpdate_同帧新开重开或隐藏恢复_下一帧才更新()
        {
            GameObject root = CreateRoot("WFrameworkFrameDeferRoot");
            try
            {
                ProbeLoader loader = InitializeProbe(root);
                loader.Register("A", typeof(ProbeStackLogic));
                loader.Register("B", typeof(ProbeStackLogic));
                loader.Register("Late", typeof(ProbeStackLogic));
                loader.Register("Cover", typeof(ProbeStackLogic));
                ProbeOptions a = OpenProbe("A", new ProbeOptions("A"));
                ProbeOptions oldB = OpenProbe("B", new ProbeOptions("B"));
                var late = new ProbeOptions("Late");
                var newB = new ProbeOptions("B");
                a.OnLogicUpdate = () =>
                {
                    a.OnLogicUpdate = null;
                    Assert.IsTrue(UIManager.Open("Late", late));
                    Assert.IsTrue(UIManager.CloseSingle("B"));
                    Assert.IsTrue(UIManager.Open("B", newB));
                };

                UIManager.Update(0.25f, 0.5f, false);
                Assert.That(late.LogicUpdates, Is.EqualTo(0));
                Assert.That(newB.LogicUpdates, Is.EqualTo(0));
                Assert.That(oldB.LogicUpdates, Is.EqualTo(0));

                UIManager.Update(0.25f, 0.5f, false);
                Assert.That(late.LogicUpdates, Is.EqualTo(1));
                Assert.That(newB.LogicUpdates, Is.EqualTo(1));

                a.OnLogicUpdate = () =>
                {
                    a.OnLogicUpdate = null;
                    Assert.IsTrue(UIManager.Open("Cover", new ProbeOptions("Cover") { FullScreen = true }));
                    Assert.IsTrue(UIManager.CloseSingle("Cover"));
                };
                UIManager.Update(0.25f, 0.5f, false);
                Assert.That(a.Window.Updates, Is.EqualTo(2));
                Assert.That(late.LogicUpdates, Is.EqualTo(1));
                Assert.That(newB.LogicUpdates, Is.EqualTo(1));

                UIManager.Update(0.25f, 0.5f, false);
                Assert.That(a.Window.Updates, Is.EqualTo(3));
                Assert.That(late.LogicUpdates, Is.EqualTo(2));
                Assert.That(newB.LogicUpdates, Is.EqualTo(2));
            }
            finally
            {
                Object.DestroyImmediate(root);
            }
        }

        /// <summary>
        /// 单个钩子抛出异常时只记录日志，后续有效目标照常更新。
        /// </summary>
        [Test]
        public void FrameUpdate_单个钩子异常_记录日志且后续目标继续()
        {
            GameObject root = CreateRoot("WFrameworkFrameExceptionRoot");
            try
            {
                ProbeLoader loader = InitializeProbe(root);
                loader.Register("A", typeof(ProbeStackLogic));
                loader.Register("B", typeof(ProbeStackLogic));
                ProbeOptions a = OpenProbe("A", new ProbeOptions("A"));
                ProbeOptions b = OpenProbe("B", new ProbeOptions("B"));
                a.OnLogicUpdate = () => throw new InvalidOperationException("探针逻辑异常");
                b.OnWindowUpdate = () => throw new InvalidOperationException("探针窗口异常");
                LogAssert.Expect(LogType.Exception, new Regex("探针逻辑异常"));
                LogAssert.Expect(LogType.Exception, new Regex("探针窗口异常"));

                UIManager.Update(0.25f, 0.5f, false);

                Assert.That(a.Window.Updates, Is.EqualTo(1));
                Assert.That(b.LogicUpdates, Is.EqualTo(1));
                Assert.That(b.Window.Updates, Is.EqualTo(1));
            }
            finally
            {
                Object.DestroyImmediate(root);
            }
        }

        /// <summary>
        /// 回调内关闭并重建 UI 管理器后，旧帧快照不再派发，新实例从下一帧开始更新。
        /// </summary>
        [Test]
        public void FrameUpdate_回调内关闭并重建_旧快照不再派发()
        {
            GameObject root = CreateRoot("WFrameworkFrameShutdownRoot");
            try
            {
                var loader = new ProbeLoader();
                UIRoot uiRoot = RegisterSerializedRoot(root);
                UIManager.Init(loader, null, false);
                s_frameLog.Clear();
                loader.Register("A", typeof(ProbeStackLogic));
                loader.Register("B", typeof(ProbeStackLogic));
                loader.Register("Fresh", typeof(ProbeStackLogic));
                ProbeOptions a = OpenProbe("A", new ProbeOptions("A"));
                ProbeOptions b = OpenProbe("B", new ProbeOptions("B"));
                var fresh = new ProbeOptions("Fresh");
                a.OnLogicUpdate = () =>
                {
                    a.OnLogicUpdate = null;
                    UIManager.Shutdown();
                    UIManager.SetUIRoot(uiRoot);
                    UIManager.Init(loader, null, false);
                    Assert.IsTrue(UIManager.Open("Fresh", fresh));
                };

                UIManager.Update(0.25f, 0.5f, false);
                CollectionAssert.AreEqual(new[] { "logic:A" }, s_frameLog);
                Assert.That(b.LogicUpdates, Is.EqualTo(0));
                Assert.That(fresh.LogicUpdates, Is.EqualTo(0));

                UIManager.Update(0.25f, 0.5f, false);
                Assert.That(fresh.LogicUpdates, Is.EqualTo(1));
                Assert.That(fresh.Window.Updates, Is.EqualTo(1));
            }
            finally
            {
                Object.DestroyImmediate(root);
            }
        }

        /// <summary>
        /// 回调内递归调用帧更新会被拒绝，下一次正常帧仍可执行。
        /// </summary>
        [Test]
        public void FrameUpdate_回调内重入_拒绝且下一帧正常()
        {
            GameObject root = CreateRoot("WFrameworkFrameReentryRoot");
            try
            {
                ProbeLoader loader = InitializeProbe(root);
                loader.Register("A", typeof(ProbeStackLogic));
                ProbeOptions a = OpenProbe("A", new ProbeOptions("A"));
                InvalidOperationException captured = null;
                a.OnLogicUpdate = () =>
                {
                    a.OnLogicUpdate = null;
                    captured = Assert.Throws<InvalidOperationException>(() => UIManager.Update(0f, 0f, false));
                };

                UIManager.Update(0.25f, 0.5f, false);
                Assert.IsNotNull(captured);
                Assert.That(captured.Message, Is.EqualTo("W-Framework UI 不支持重入帧更新。"));
                Assert.That(a.Window.Updates, Is.EqualTo(1));

                UIManager.Update(0.25f, 0.5f, false);
                Assert.That(a.LogicUpdates, Is.EqualTo(2));
                Assert.That(a.Window.Updates, Is.EqualTo(2));
            }
            finally
            {
                Object.DestroyImmediate(root);
            }
        }

        /// <summary>
        /// 注册测试根节点并以探针加载器初始化，同时清空帧日志。
        /// </summary>
        private static ProbeLoader InitializeProbe(GameObject root)
        {
            var loader = new ProbeLoader();
            InitializeCore(root, loader);
            s_frameLog.Clear();
            return loader;
        }

        /// <summary>
        /// 通过真实 UIManager.Open 打开探针窗口并确认已完成同步打开。
        /// </summary>
        private static ProbeOptions OpenProbe(string id, ProbeOptions options)
        {
            Assert.IsTrue(UIManager.Open(id, options));
            Assert.IsNotNull(options.Root, $"{id} 未完成打开");
            return options;
        }

        /// <summary>
        /// 探针窗口参数与观测数据。
        /// </summary>
        private sealed class ProbeOptions
        {
            public ProbeOptions(string name)
            {
                Name = name;
            }

            public string Name { get; }
            public bool FullScreen;
            public eUIVisibleOperateType Visibility = eUIVisibleOperateType.LayerMask;
            public Action OnLogicUpdate;
            public Action OnWindowUpdate;
            public GameObject Root;
            public ProbeWindow Window;
            public int LogicUpdates;

            /// <summary>
            /// 记录打开后的根节点和探针 Window 组件。
            /// </summary>
            public void Bind(GameObject go)
            {
                Root = go;
                Window = go.GetComponent<ProbeWindow>();
                if (Window != null)
                {
                    Window.Options = this;
                }
            }

            /// <summary>
            /// 记录 Logic 帧回调并执行测试注入动作。
            /// </summary>
            public void RecordLogicUpdate()
            {
                LogicUpdates++;
                s_frameLog.Add("logic:" + Name);
                OnLogicUpdate?.Invoke();
            }
        }

        /// <summary>
        /// 记录帧回调的堆叠探针逻辑。
        /// </summary>
        private sealed class ProbeStackLogic : UIStackLogicBase
        {
            private ProbeOptions _options;

            protected override bool IsFullScreen => _options.FullScreen;
            protected override bool NewGroup => true;
            protected override eUIVisibleOperateType VisibleOperateType => _options.Visibility;
            protected override string OpenAnim => null;
            protected override string CloseAnim => null;

            protected override bool OnCreate(object parameter)
            {
                _options = (ProbeOptions)parameter;
                return true;
            }

            protected override void OnOpen(GameObject go, int baseSortingOrder)
            {
                _options.Bind(go);
            }

            protected override void OnUpdate(float elapseSeconds, float realElapseSeconds)
            {
                _options.RecordLogicUpdate();
            }
        }

        /// <summary>
        /// 记录帧回调的固定探针逻辑。
        /// </summary>
        private sealed class ProbeFixedLogic : UIFixedLogicBase
        {
            private ProbeOptions _options;

            protected override int SortingOrderBias => 0;
            protected override string OpenAnim => null;
            protected override string CloseAnim => null;

            protected override bool OnCreate(object parameter)
            {
                _options = (ProbeOptions)parameter;
                return true;
            }

            protected override void OnOpen(GameObject go, int baseSortingOrder)
            {
                _options.Bind(go);
            }

            protected override void OnUpdate(float elapseSeconds, float realElapseSeconds)
            {
                _options.RecordLogicUpdate();
            }
        }

        /// <summary>
        /// 累加两种 delta 并记录执行次序的探针 Window。
        /// </summary>
        private sealed class ProbeWindow : UIWindowBase
        {
            public ProbeOptions Options;
            public int Updates;
            public float Elapsed;
            public float RealElapsed;

            protected override void OnUpdate(float elapseSeconds, float realElapseSeconds)
            {
                Updates++;
                Elapsed += elapseSeconds;
                RealElapsed += realElapseSeconds;
                s_frameLog.Add("window:" + Options.Name);
                Options.OnWindowUpdate?.Invoke();
            }
        }

        /// <summary>
        /// 按窗口 id 返回探针逻辑类型，并同步生成可选挂载 ProbeWindow 的根节点。
        /// </summary>
        private sealed class ProbeLoader : IUILoader
        {
            private readonly Dictionary<string, Type> _logicTypes = new Dictionary<string, Type>();
            private readonly HashSet<string> _withoutWindow = new HashSet<string>();

            /// <summary>
            /// 注册窗口 id 及其逻辑类型。
            /// </summary>
            public void Register(string id, Type logicType, bool withWindow = true)
            {
                _logicTypes[id] = logicType;
                if (!withWindow)
                {
                    _withoutWindow.Add(id);
                }
            }

            public ParametersForUI GetParameterForUI(string id)
            {
                if (!_logicTypes.TryGetValue(id, out Type logicType))
                {
                    return default;
                }

                return new ParametersForUI { id = id, prefab_path = id, logic_type = logicType };
            }

            public UniTask<GameObject> LoadUIObject(string path)
            {
                var instance = new GameObject(path, typeof(RectTransform));
                if (!_withoutWindow.Contains(path))
                {
                    instance.AddComponent<ProbeWindow>();
                }

                return UniTask.FromResult(instance);
            }

            public void UnloadUIObject(GameObject go)
            {
                if (go != null)
                {
                    Object.DestroyImmediate(go);
                }
            }
        }
    }
}
