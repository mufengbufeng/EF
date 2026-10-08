using EF.UI.WFramework.Collections;
using System;
using System.Collections.Generic;
using UnityEngine;

namespace EF.UI.WFramework.Utils {

	public static partial class AnimExtension {

		public struct AnimParam {
			public int _layer;
			public float _speed;
			public float _crossfade;
			public AnimParam SetLayer(int layer) {
				_layer = layer;
				return this;
			}
			public AnimParam SetSpeed(float speed) {
				if (speed <= 0f) { throw new ArgumentException(nameof(speed)); }
				_speed = speed;
				return this;
			}
			public AnimParam SetCrossFade(float crossfade) {
				if (crossfade < 0f) { throw new ArgumentException(nameof(crossfade)); }
				_crossfade = crossfade;
				return this;
			}
			public static AnimParam Default {
				get {
					return new AnimParam() {
						_layer = 0,
						_speed = -1f,
						_crossfade = -1f
					};
				}
			}
		}

		public delegate void AnimEventDelegate(float time, float length);

		public struct AnimEvent {
			public bool _is_normalized;
			public float _t;
			public uint _times;
			public AnimEventDelegate _callback;
			public static AnimEvent Progress(float progress, uint times, AnimEventDelegate callback) {
				if (progress < 0f) { throw new ArgumentException(nameof(progress)); }
				AnimEvent ret = new AnimEvent();
				ret._is_normalized = true;
				ret._t = progress;
				ret._times = times;
				ret._callback = callback;
				return ret;
			}
			public static AnimEvent Time(float time, uint times, AnimEventDelegate callback) {
				AnimEvent ret = new AnimEvent();
				ret._is_normalized = false;
				ret._t = time;
				ret._times = times;
				ret._callback = callback;
				return ret;
			}
		}

		private static AnimEvent[] s_temp_events = new AnimEvent[1];

		private static Playing s_playing { get; } = new Playing();

		/// <summary>
		/// UIManager 内部帧更新入口，推进活动动画并派发完成事件。
		/// </summary>
		internal static void Update(float elapseSeconds, float realElapseSeconds) {
			s_playing.Update(elapseSeconds, realElapseSeconds);
		}

		/// <summary>
		/// UIManager 关闭时回收活动项并清空列表。
		/// </summary>
		internal static void Shutdown() {
			s_playing.Shutdown();
		}

		private class Playing {
			private static List<AnimEventInvoke> s_temp_invokes = new List<AnimEventInvoke>();
			private List<AnimItem> mPlayings = new List<AnimItem>(16);
			private uint mUpdateVersion = 0u;

			public Playing() { }

			public void AddPlaying(AnimItem item) {
				if (item == null) { return; }
				mPlayings.Add(item);
			}

			public bool Remove(Component comp, int layer) {
				for (int i = mPlayings.Count - 1; i >= 0; i--) {
					var playing = mPlayings[i];
					if (playing.Equals(comp, layer)) {
						mPlayings.RemoveAt(i);
						playing.Recycle();
						return true;
					}
				}
				return false;
			}

			internal void Update(float elapseSeconds, float realElapseSeconds) {
				s_temp_invokes.Clear();
				for (int i = mPlayings.Count - 1; i >= 0; i--) {
					AnimItem item = mPlayings[i];
					if (!item.Tick(s_temp_invokes, elapseSeconds, realElapseSeconds)) {
						mPlayings.RemoveAt(i);
						item.Recycle();
					}
				}
				uint currentVersion = mUpdateVersion;
				for (int i = s_temp_invokes.Count - 1; i >= 0; i--) {
					if (mUpdateVersion != currentVersion) { break; }
					AnimEventInvoke invoke = s_temp_invokes[i];
					try {
						invoke.callback.Invoke(invoke.time, invoke.length);
					} catch (Exception ex) {
						Debug.LogException(ex);
					}
				}
				s_temp_invokes.Clear();
			}

			internal void Shutdown() {
				unchecked { mUpdateVersion++; }
				for (int i = mPlayings.Count - 1; i >= 0; i--) {
					mPlayings[i].Recycle();
				}
				mPlayings.Clear();
				s_temp_invokes.Clear();
			}
		}


		private abstract class AnimItem {
			private float mLength;
			private bool mUnscaledTime;
			private List<AnimEvent> mEventsFrom = new List<AnimEvent>();
			private PriorityQueue<AnimEventInternal, float> mEvents = new PriorityQueue<AnimEventInternal, float>();
			private float mPrevNT;
			private int mRetryCount;
			public string AnimName { get; private set; }
			public abstract bool Equals(Component comp, int layer);
			public bool Tick(List<AnimEventInvoke> invokes, float elapseSeconds, float realElapseSeconds) {
				if (!CheckValid()) { return false; }
				if (mLength <= 0f) {
					TryGetClipLength(out float len, out bool unscaledTime);
					if (len < 0f) { return false; }
					if (len == 0f) { return mRetryCount-- > 0; }
					mLength = len;
					mUnscaledTime = unscaledTime;
					InitEvents(mEventsFrom, mEvents, len);
					mEventsFrom.Clear();
				}
				float nt = GetNormalizedTime(out float speed);
				float dt = mUnscaledTime ? realElapseSeconds : elapseSeconds;
				TickEvents(mEvents, invokes, mPrevNT, nt, dt * speed, mLength);
				if (nt < mPrevNT) {
					mEvents.Clear();
				}
				mPrevNT = nt;
				return mEvents.Count > 0;
			}
			public abstract void Recycle();
			protected abstract bool CheckValid();
			protected abstract void TryGetClipLength(out float length, out bool unscaledTime);
			protected abstract float GetNormalizedTime(out float speed);
			protected static void InitAnimNameAndEvents(AnimItem item, string animName, IEnumerable<AnimEvent> events) {
				item.mLength = 0f;
				item.mUnscaledTime = false;
				item.AnimName = animName;
				item.mPrevNT = 0f;
				item.mRetryCount = 2;
				item.mEventsFrom.Clear();
				item.mEvents.Clear();
				if (events != null) { item.mEventsFrom.AddRange(events); }
			}
			protected static void ClearEvents(AnimItem item) {
				item.mEventsFrom.Clear();
				item.mEvents.Clear();
			}
		}

		private abstract class AnimItem<T> : AnimItem where T : Component {
			protected T Component { get; private set; }
			protected int Layer { get; private set; }
			public abstract bool Play(float speed, float crossfade);
			public override bool Equals(Component comp, int layer) {
				if (comp == null) { return false; }
				if (Layer != layer) { return false; }
				return comp is T c && Component == c;
			}
			protected static void InitComponentAndLayer(AnimItem<T> item, T component, int layer) {
				item.Component = component;
				item.Layer = layer;
			}
			protected static void ClearComponent(AnimItem<T> item) {
				item.Component = null;
			}
		}

		private struct AnimEventInvoke {
			public AnimEventDelegate callback;
			public float time;
			public float length;
		}

		private struct AnimEventInternal {
			public float cycles;
			public float nt;
			public uint times;
			public AnimEventDelegate callback;
		}

		private static void TickEvents(PriorityQueue<AnimEventInternal, float> evts, List<AnimEventInvoke> invokes, float pt, float t, float dt, float length) {
			if (t < pt) { t = Mathf.Min(pt + dt * 2f / length, Mathf.Ceil(pt)); }
			while (evts.Count > 0) {
				AnimEventInternal e = evts.Peek();
				if (t < e.nt) { break; }
				evts.Dequeue();
				invokes.Add(new AnimEventInvoke() {
					callback = e.callback,
					time = t * length,
					length = length
				});
				if (e.times == 1) { continue; }
				if (e.times > 1) { e.times--; }
				e.nt += e.cycles;
				evts.Enqueue(e, e.nt);
			}
		}

		private static void InitEvents(List<AnimEvent> from, PriorityQueue<AnimEventInternal, float> to, float length) {
			float _len = 1f / length;
			int n = from.Count;
			for (int i = 0; i < n; i++) {
				AnimEvent e = from[i];
				float t = e._t;
				if (!e._is_normalized) {
					if (t < 0f) {
						t += length;
						if (t < 0f) { t = 0f; }
					}
					t *= _len;
				}
				to.Enqueue(new AnimEventInternal() {
					cycles = Mathf.Max(1f, Mathf.Ceil(t)),
					nt = t,
					times = e._times,
					callback = e._callback
				}, t);
			}
		}

	}

}
