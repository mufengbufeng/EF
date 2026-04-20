using System;
using EF.Common;
using EF.Debugger;
using EF.Feature;
using UnityEngine;

namespace GameLogic
{
    /// <summary>
    /// 自动攻击特性，按固定间隔执行攻击逻辑。
    /// </summary>
    public class AttackFeature : FeatureBase<AttackData>
    {
        private float _attackInterval;
        private float _attackTimer;
        private float _bulletSpeed;
        private int _sourceEntityId;
        private Func<Vector3, bool> _customAttackExecutor;
        private bool _bulletWarningLogged;

        /// <summary>
        /// 配置攻击参数。
        /// </summary>
        protected override void OnSetup(AttackData data)
        {
            _attackInterval = data.AttackInterval;
            _bulletSpeed = data.BulletSpeed;
            _sourceEntityId = data.SourceEntityId;
            _attackTimer = 0f;
            _customAttackExecutor = null;
            _bulletWarningLogged = false;
        }

        /// <summary>
        /// 清理自定义攻击执行器。
        /// </summary>
        public override void OnDestroy()
        {
            base.OnDestroy();
            _customAttackExecutor = null;
        }

        /// <summary>
        /// 设置自定义攻击执行器。
        /// </summary>
        public void SetCustomAttackExecutor(Func<Vector3, bool> executor)
        {
            _customAttackExecutor = executor;
        }

        /// <summary>
        /// 每帧累积攻击计时器，达到间隔时执行攻击。
        /// </summary>
        public override void OnUpdate(float elapseSeconds, float realElapseSeconds)
        {
            if (!Enabled)
            {
                return;
            }

            if (_attackInterval <= 0f)
            {
                return;
            }

            _attackTimer += elapseSeconds;
            if (_attackTimer < _attackInterval)
            {
                return;
            }

            _attackTimer = 0f;
            ExecuteAttack();
        }

        /// <summary>
        /// 执行攻击，优先使用自定义执行器，否则发射默认子弹。
        /// </summary>
        private void ExecuteAttack()
        {
            if (Entity?.Handle == null)
            {
                return;
            }

            if (_customAttackExecutor != null)
            {
                try
                {
                    if (_customAttackExecutor.Invoke(Entity.Handle.transform.position))
                    {
                        return;
                    }
                }
                catch (Exception e)
                {
                    Log.Error($"[AttackFeature] 自定义攻击执行器异常: {e.Message}");
                }
            }

            FireDefaultBullet();
        }

        /// <summary>
        /// 通过 IBulletModule 发射默认子弹。
        /// </summary>
        private void FireDefaultBullet()
        {
            if (!ModuleSystem.TryGet<IBulletModule>(out var bulletModule))
            {
                if (!_bulletWarningLogged)
                {
                    _bulletWarningLogged = true;
                    Log.Warning($"[AttackFeature] 无法获取 IBulletModule，跳过默认攻击");
                }
                return;
            }

            _bulletWarningLogged = false;
            var bulletData = new BulletData
            {
                SpawnPosition = Entity.Handle.transform.position,
                Direction = Vector3.up,
                Speed = _bulletSpeed,
                OwnerType = BulletOwnerType.Player,
                Damage = 10f,
                SourceEntityId = _sourceEntityId
            };
            bulletModule.Fire(bulletData);
        }
    }
}
