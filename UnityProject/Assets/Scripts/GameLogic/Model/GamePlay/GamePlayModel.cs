// ----------------------------
// 负责存储角色游戏中的数据
// ----------------------------
using EF;
using UnityEngine;

namespace GameLogic
{
    public class GamePlayModel : BaseModel<GamePlayModel>
    {
        // protected new bool _dontDestroyOnLoad = false;
        public int Chater { get; private set; }
        public Vector2[] AllBoxColliderCorners { get; private set; }

        public void StartGame(int chater)
        {
            Chater = chater;
        }

        public void SetAllBoxColliderCorners(Vector2[] allBoxColliderCorners)
        {
            AllBoxColliderCorners = allBoxColliderCorners;
        }

        // 传入一个点，判断是否在所有BoxColliderCorners中
        public bool IsPointInAllBoxColliderCorners(Vector2 point)
        {
            if (AllBoxColliderCorners == null || AllBoxColliderCorners.Length < 4)
            {
                return false;
            }
            Vector2[] currentBoxColliderCorners = new Vector2[4];
            // 判断点是否在所有BoxColliderCorners中
            for (int i = 0; i < AllBoxColliderCorners.Length / 4; i++)
            {
                // 获取当前BoxColliderCorners
                for (int j = 0; j < 4; j++)
                {
                    currentBoxColliderCorners[j] = AllBoxColliderCorners[i * 4 + j];
                }

                // 判断点是否在当前BoxColliderCorners中
                if (IsPointInPolygon(point, currentBoxColliderCorners))
                {
                    return true;
                }
            }

            return false;
        }

        /// <summary>
        /// 判断点是否在多边形中 (射线法)
        /// </summary>
        /// <param name="point"></param>
        /// <param name="polygon"></param>
        /// <returns></returns>
        private bool IsPointInPolygon(Vector2 point, Vector2[] polygon)
        {
            int j = polygon.Length - 1;
            bool isInside = false;

            for (int i = 0; i < polygon.Length; i++)
            {
                if (polygon[i].y > point.y != polygon[j].y > point.y &&
                    point.x < (polygon[j].x - polygon[i].x) * (point.y - polygon[i].y) / (polygon[j].y - polygon[i].y) + polygon[i].x)
                {
                    isInside = !isInside;
                }
                j = i;
            }

            return isInside;
        }


    }
}