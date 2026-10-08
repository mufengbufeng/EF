using System;
using System.Collections.Generic;
using UnityEngine;

namespace EF.UI.WFramework {

	public partial class UIManager {


		private abstract partial class UIInstanceBase<T, U> : UIInstanceBase where T : UIInstanceBase<T, U> where U : IUILogicBase {

			private uint mUpdateVersion;
			private float mPrepareTimeoutRemaining;
			private bool mPrepareTimeoutPending;

			private void InvalidateUpdate() {
				unchecked { mUpdateVersion++; }
			}

			public override uint UpdateVersion { get { return mUpdateVersion; } }

			public override void UpdateFrame(float elapseSeconds, float realElapseSeconds, uint expectedVersion) {
				if (mUpdateVersion != expectedVersion) { return; }

				// 准备超时在可见性判断前独立处理
				if (mPrepareTimeoutPending && mState == eUIState.Preparing && mPrepareResult == ePrepareResult.None) {
					mPrepareTimeoutRemaining -= realElapseSeconds;
					if (mPrepareTimeoutRemaining <= 0f) {
						mPrepareTimeoutPending = false;
						PrepareDone(ePrepareResult.Timeout);
					}
					return;
				}

				// 业务更新必须满足已开启、可见、已初始化且根对象活跃
				if (!Opened || !Showing || !mUI.Inited || mUI.ui == null || !mUI.ui.activeInHierarchy) {
					return;
				}

				// 先调用 Logic.OnUpdate
				try {
					Logic.OnUpdate(elapseSeconds, realElapseSeconds);
				} catch (Exception ex) {
					Debug.LogException(ex, mUI.ui);
				}

				// 版本可能在 Logic 回调内失效
				if (mUpdateVersion != expectedVersion) { return; }
				if (!Opened || !Showing || !mUI.Inited || mUI.ui == null || !mUI.ui.activeInHierarchy) {
					return;
				}

				// 遍历 Window 组件
				IReadOnlyList<UIWindowBase> windows = mUI.Windows;
				if (windows == null) { return; }
				int count = windows.Count;
				for (int i = 0; i < count; i++) {
					if (mUpdateVersion != expectedVersion) { return; }
					if (!Opened || !Showing || !mUI.Inited || mUI.ui == null || !mUI.ui.activeInHierarchy) {
						return;
					}
					UIWindowBase window = windows[i];
					if (window != null) {
						try {
							window.InternalUpdate(elapseSeconds, realElapseSeconds);
						} catch (Exception ex) {
							Debug.LogException(ex, mUI.ui);
						}
					}
				}
			}

		}

		private partial class Processor {

			private readonly struct FrameEntry {
				public readonly UIInstanceBase Instance;
				public readonly uint Version;
				public FrameEntry(UIInstanceBase instance, uint version) {
					Instance = instance;
					Version = version;
				}
			}

			private readonly List<FrameEntry> mFrameSnapshot = new List<FrameEntry>();
			private bool mInUpdate = false;
			private bool mShutdown = false;

			/// <summary>
			/// 从 WFrameworkUIManager 接收逻辑帧并按固定阶段分发。
			/// </summary>
			public void Update(float elapseSeconds, float realElapseSeconds, bool escapePressed = false) {
				if (mShutdown) { return; }
				if (mInUpdate) {
					throw new InvalidOperationException("W-Framework UI 不支持重入帧更新。");
				}
				mInUpdate = true;
				try {
					// 捕获所有实例的当前版本
					mFrameSnapshot.Clear();
					for (int i = 0; i < mFixed.Count; i++) {
						UIInstanceFixed ins = mFixed[i];
						if (ins != null) {
							mFrameSnapshot.Add(new FrameEntry(ins, ins.UpdateVersion));
						}
					}
					for (int i = 0; i < mStack.Count; i++) {
						UIInstanceStack ins = mStack[i];
						if (ins != null) {
							mFrameSnapshot.Add(new FrameEntry(ins, ins.UpdateVersion));
						}
					}

					// 屏幕/相机变化
					if (!ReferenceEquals(s_processor, this) || mShutdown) { return; }
					CheckScreenOrCameraChanged();

					// Escape 输入
					if (escapePressed) {
						if (!ReferenceEquals(s_processor, this) || mShutdown) { return; }
						ProcessEscape();
					}

					// UI Timer
					if (!ReferenceEquals(s_processor, this) || mShutdown) { return; }
					Utils.Timer.Update(elapseSeconds, realElapseSeconds);

					// AnimExtension
					if (!ReferenceEquals(s_processor, this) || mShutdown) { return; }
					Utils.AnimExtension.Update(elapseSeconds, realElapseSeconds);

					// 实例帧更新
					if (!ReferenceEquals(s_processor, this) || mShutdown) { return; }
					for (int i = 0; i < mFrameSnapshot.Count; i++) {
						if (!ReferenceEquals(s_processor, this) || mShutdown) { return; }
						FrameEntry entry = mFrameSnapshot[i];
						entry.Instance.UpdateFrame(elapseSeconds, realElapseSeconds, entry.Version);
					}
				} finally {
					mFrameSnapshot.Clear();
					mInUpdate = false;
				}
			}

		}

	}

}
