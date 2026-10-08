using System;
using UnityEngine;

namespace EF.UI.WFramework.Utils {

	public sealed class DefaultTimer : TimerCore<float, float> {
		public DefaultTimer(ITimerCalculator<float, float> calculator) : base(calculator) { }
	}

	public sealed class RealtimeTimer : TimerCore<DateTime, TimeSpan> {
		public RealtimeTimer(ITimerCalculator<DateTime, TimeSpan> calculator) : base(calculator) { }
	}

	public static class Timer {

		public static DefaultTimer Default {
			get {
				if (s_default == null) {
					s_defaultCalculator = new DefaultTimerCalculator();
					s_default = new DefaultTimer(s_defaultCalculator);
				}
				return s_default;
			}
		}

		public static RealtimeTimer DefaultRealTime {
			get {
				if (s_default_realtime == null) {
					s_default_realtime = new RealtimeTimer(new RealtimeTimerCalculator());
				}
				return s_default_realtime;
			}
		}

		private static DefaultTimer s_default;
		private static RealtimeTimer s_default_realtime;
		private static DefaultTimerCalculator s_defaultCalculator;

		/// <summary>
		/// UIManager 内部帧更新入口，只更新已创建的计时器实例。
		/// 默认计时器按 elapseSeconds 推进；实时计时器保留 DateTime.Now 绝对墙钟语义。
		/// </summary>
		internal static void Update(float elapseSeconds, float realElapseSeconds) {
			DefaultTimerCalculator calc = s_defaultCalculator;
			DefaultTimer defaultTimer = s_default;
			if (calc != null && defaultTimer != null) {
				calc.Tick(elapseSeconds);
				if (ReferenceEquals(s_default, defaultTimer)) {
					defaultTimer.Tick();
				}
			}
			RealtimeTimer realtimeTimer = s_default_realtime;
			if (realtimeTimer != null && ReferenceEquals(s_default_realtime, realtimeTimer)) {
				realtimeTimer.Tick();
			}
		}

		/// <summary>
		/// UIManager 关闭时清空计时器队列和静态引用。
		/// </summary>
		internal static void Shutdown() {
			if (s_default != null) {
				s_default.Clear();
				s_default = null;
			}
			if (s_default_realtime != null) {
				s_default_realtime.Clear();
				s_default_realtime = null;
			}
			s_defaultCalculator = null;
		}

		private class DefaultTimerCalculator : ITimerCalculator<float, float> {
			private float mTimer = 0f;
			float ITimerCalculator<float, float>.Add(float time, float delta) {
				return time + delta;
			}
			float ITimerCalculator<float, float>.Subtract(float time, float delta) {
				return time - delta;
			}
			int ITimerCalculator<float, float>.Compare(float a, float b) {
				if (a == b) { return 0; }
				return a < b ? -1 : 1;
			}
			float ITimerCalculator<float, float>.GetNow() {
				return mTimer;
			}
			public void Tick(float delta) {
				mTimer += delta;
			}
		}

		private class RealtimeTimerCalculator : ITimerCalculator<DateTime, TimeSpan> {
			DateTime ITimerCalculator<DateTime, TimeSpan>.Add(DateTime time, TimeSpan delta) {
				return time + delta;
			}
			TimeSpan ITimerCalculator<DateTime, TimeSpan>.Subtract(DateTime time, DateTime delta) {
				return time - delta;
			}
			int ITimerCalculator<DateTime, TimeSpan>.Compare(DateTime a, DateTime b) {
				return DateTime.Compare(a, b);
			}
			DateTime ITimerCalculator<DateTime, TimeSpan>.GetNow() {
				return DateTime.Now;
			}
		}

	}

}
