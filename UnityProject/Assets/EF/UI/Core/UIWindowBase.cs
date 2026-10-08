using UnityEngine;

namespace EF.UI.WFramework {

	/// <summary>
	/// W-Framework Window 组件统一基类，供生成绑定继承以间接获得 MonoBehaviour。
	/// 实例帧更新由 UIManager 通过内部列表直接调度，不使用 Unity Update 消息。
	/// </summary>
	public abstract class UIWindowBase : MonoBehaviour {

		/// <summary>
		/// 由 UIManager 在每个逻辑帧调用，传递逻辑与真实 delta。
		/// 只在窗口可见、组件 enabled 且根 GameObject active 时执行。
		/// </summary>
		protected virtual void OnUpdate(float elapseSeconds, float realElapseSeconds) { }

		/// <summary>
		/// UIManager 内部分发入口，验证组件状态后调用业务 OnUpdate。
		/// </summary>
		internal void InternalUpdate(float elapseSeconds, float realElapseSeconds) {
			if (this != null && enabled && gameObject.activeInHierarchy) {
				OnUpdate(elapseSeconds, realElapseSeconds);
			}
		}

	}

}
