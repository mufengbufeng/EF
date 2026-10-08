using System.Collections;
using System.Reflection;
using Cysharp.Threading.Tasks;
using EF.Common;
using EF.Resource;
using EF.UI.WFramework;
using EF.UI.WFramework.Utils;
using NUnit.Framework;
using UnityEngine;
using UnityEngine.TestTools;
using UITimer = EF.UI.WFramework.Utils.Timer;

namespace GameLogic.Tests.PlayMode.Framework
{
    /// <summary>
    /// 验证真实 PlayerLoop 运行时，W-Framework UI 计时器和动画完成事件只由 ModuleSystem.Update 推进。
    /// </summary>
    public sealed class WFrameworkUiFrameTests
    {
        private GameObject _sceneCanvas;
        private GameObject _animationObject;
        private WFrameworkUIManager _manager;

        /// <summary>
        /// 构造已序列化配置的 UIRoot，并将真实 WFrameworkUIManager 注册到模块系统。
        /// </summary>
        [SetUp]
        public void SetUp()
        {
            _sceneCanvas = new GameObject("WFrameworkFrameSceneCanvas", typeof(RectTransform), typeof(Canvas));
            _sceneCanvas.GetComponent<Canvas>().renderMode = RenderMode.ScreenSpaceOverlay;

            var rootObject = new GameObject("WFrameworkFrameRoot", typeof(RectTransform), typeof(Canvas));
            rootObject.transform.SetParent(_sceneCanvas.transform, false);
            var canvas = rootObject.GetComponent<Canvas>();
            canvas.overrideSorting = true;
            rootObject.SetActive(false);
            var root = rootObject.AddComponent<UIRoot>();
            SetSerializedField(root, "m_RootCanvas", canvas);
            SetSerializedField(root, "m_ParentForUI", rootObject.GetComponent<RectTransform>());
            SetSerializedField(root, "m_LayerForHide", 2);
            rootObject.SetActive(true);

            _manager = new WFrameworkUIManager(new ResourceManager());
            _manager.Initialize(false);
            ModuleSystem.Register<IWFrameworkUIManager>(_manager);
        }

        /// <summary>
        /// 注销模块并销毁测试对象，避免影响其它 PlayMode 测试。
        /// </summary>
        [TearDown]
        public void TearDown()
        {
            ModuleSystem.Unregister<IWFrameworkUIManager>(true);
            _manager = null;
            if (_animationObject != null)
            {
                Object.Destroy(_animationObject);
            }

            Object.Destroy(_sceneCanvas);
        }

        /// <summary>
        /// 真实 Unity 帧推进不触发 UI 计时器，一次模块更新才执行到期回调。
        /// </summary>
        [UnityTest]
        public IEnumerator UITimer_真实帧不推进_模块更新才执行() => UniTask.ToCoroutine(async () =>
        {
            int defaultFired = 0;
            int realtimeFired = 0;
            UITimer.Default.Add(0f, () => defaultFired++);
            UITimer.DefaultRealTime.Add(System.TimeSpan.Zero, () => realtimeFired++);

            await UniTask.Yield(PlayerLoopTiming.Update);
            await UniTask.Yield(PlayerLoopTiming.Update);
            Assert.That(defaultFired, Is.EqualTo(0));
            Assert.That(realtimeFired, Is.EqualTo(0));

            ModuleSystem.Update(0.016f, 0.016f);
            Assert.That(defaultFired, Is.EqualTo(1));
            Assert.That(realtimeFired, Is.EqualTo(1));
        });

        /// <summary>
        /// 动画进度到达终点后，只推进 Unity 帧不派发完成回调；一次模块更新只派发一次。
        /// </summary>
        [UnityTest]
        public IEnumerator AnimExtension_完成事件_只由模块更新派发() => UniTask.ToCoroutine(async () =>
        {
            Animation animation = CreateLegacyAnimation("WFrameworkAnimProbe", 1);
            int finished = 0;
            AnimExtension.AnimParam param = AnimExtension.AnimParam.Default.SetSpeed(1f).SetCrossFade(0f);
            Assert.IsTrue(animation.PlayAnim("probe0", param, () => finished++));

            animation["probe0"].normalizedTime = 1f;
            await UniTask.Yield(PlayerLoopTiming.Update);
            await UniTask.Yield(PlayerLoopTiming.Update);
            Assert.That(finished, Is.EqualTo(0));

            ModuleSystem.Update(0.016f, 0.016f);
            Assert.That(finished, Is.EqualTo(1));

            ModuleSystem.Update(0.016f, 0.016f);
            Assert.That(finished, Is.EqualTo(1));
        });

        /// <summary>
        /// 完成回调内关闭 UI 管理器时，同一轮剩余动画事件不再派发。
        /// </summary>
        [UnityTest]
        public IEnumerator AnimExtension_回调内关闭_同轮剩余事件取消() => UniTask.ToCoroutine(async () =>
        {
            Animation animation = CreateLegacyAnimation("WFrameworkAnimShutdownProbe", 2);
            int finished = 0;
            AnimExtension.AnimParam firstLayer = AnimExtension.AnimParam.Default.SetSpeed(1f).SetCrossFade(0f).SetLayer(0);
            AnimExtension.AnimParam secondLayer = AnimExtension.AnimParam.Default.SetSpeed(1f).SetCrossFade(0f).SetLayer(1);
            Assert.IsTrue(animation.PlayAnim("probe0", firstLayer, () => { finished++; UIManager.Shutdown(); }));
            Assert.IsTrue(animation.PlayAnim("probe1", secondLayer, () => { finished++; UIManager.Shutdown(); }));
            animation["probe0"].normalizedTime = 1f;
            animation["probe1"].normalizedTime = 1f;

            await UniTask.Yield(PlayerLoopTiming.Update);
            ModuleSystem.Update(0.016f, 0.016f);

            Assert.That(finished, Is.EqualTo(1));
        });

        /// <summary>
        /// 创建仅存在于内存中的 legacy Animation，包含指定数量、长度为 1 秒的 ClampForever 剪辑。
        /// </summary>
        private Animation CreateLegacyAnimation(string name, int clipCount)
        {
            _animationObject = new GameObject(name);
            var animation = _animationObject.AddComponent<Animation>();
            for (int i = 0; i < clipCount; i++)
            {
                var clip = new AnimationClip { legacy = true, wrapMode = WrapMode.ClampForever };
                clip.SetCurve(string.Empty, typeof(Transform), "localPosition.x", AnimationCurve.Linear(0f, 0f, 1f, 1f));
                animation.AddClip(clip, "probe" + i);
            }

            return animation;
        }

        /// <summary>
        /// 复现 Unity 对 UIRoot 私有序列化字段的反序列化写入。
        /// </summary>
        private static void SetSerializedField(UIRoot root, string fieldName, object value)
        {
            FieldInfo field = typeof(UIRoot).GetField(fieldName, BindingFlags.Instance | BindingFlags.NonPublic);
            Assert.IsNotNull(field, $"未找到 UIRoot 序列化字段：{fieldName}");
            field.SetValue(root, value);
        }
    }
}
