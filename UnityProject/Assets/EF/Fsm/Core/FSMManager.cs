using System.Collections.Generic;
using UnityEngine;

namespace EF
{
    /// <summary>
    /// FSM管理器，负责管理游戏中所有的FiniteStateMachine实例
    /// 实现为MonoBehaviour单例，允许在Unity的生命周期中更新FSM
    /// </summary>
    public class FSMManager : BehaviourSingleton<FSMManager>
    {
        /// <summary>
        /// 存储所有活跃的FSM实例
        /// </summary>
        private List<FiniteStateMachine> activeFSMs = new List<FiniteStateMachine>();

        /// <summary>
        /// 初始化FSM管理器
        /// </summary>
        protected override void Init()
        {
            base.Init();
            Log.Info("FSM管理器已初始化");
        }

        /// <summary>
        /// 每帧更新所有FSM实例
        /// </summary>
        private void Update()
        {
            UpdateAllFSMs();
        }

        /// <summary>
        /// 向管理器注册一个新的FSM实例
        /// </summary>
        /// <param name="fsm">FSM实例</param>
        public void RegisterFSM(FiniteStateMachine fsm)
        {
            if (fsm != null && !activeFSMs.Contains(fsm))
            {
                activeFSMs.Add(fsm);
                Log.Info($"FSM已注册到管理器，当前FSM总数：{activeFSMs.Count}");
            }
        }

        /// <summary>
        /// 从管理器注销一个FSM实例
        /// </summary>
        /// <param name="fsm">FSM实例</param>
        public void UnregisterFSM(FiniteStateMachine fsm)
        {
            if (fsm != null && activeFSMs.Contains(fsm))
            {
                activeFSMs.Remove(fsm);
                Log.Info($"FSM已从管理器注销，当前FSM总数：{activeFSMs.Count}");
            }
        }

        /// <summary>
        /// 更新所有注册的FSM实例
        /// </summary>
        public void UpdateAllFSMs()
        {
            // 创建一个临时列表以防在迭代过程中FSM列表被修改
            FiniteStateMachine[] tempFSMs = activeFSMs.ToArray();

            foreach (var fsm in tempFSMs)
            {
                if (fsm != null)
                {
                    fsm.Update();
                }
            }
        }

        /// <summary>
        /// 清除所有注册的FSM实例
        /// </summary>
        public void ClearAllFSMs()
        {
            activeFSMs.Clear();
            Log.Info("所有FSM已从管理器中清除");
        }

        /// <summary>
        /// 释放管理器时的清理工作
        /// </summary>
        protected override void OnRelease()
        {
            base.OnRelease();
            ClearAllFSMs();
        }

        /// <summary>
        /// 获取当前活跃的FSM数量
        /// </summary>
        /// <returns>活跃FSM数量</returns>
        public int GetActiveFSMCount()
        {
            return activeFSMs.Count;
        }
    }
}