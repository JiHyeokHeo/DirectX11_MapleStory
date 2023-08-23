#pragma once
#include "JNSEngine.h"
#include "jnsMath.h"

namespace jns
{
#define LAYER_MAX (UINT)eLayerType::End
	using namespace enums;
	using namespace math;
	class Collider2D;
	class CollisionManager
	{
	public:
		union ColliderID
		{
			struct
			{
				UINT left;
				UINT right;
			};
			UINT64 id;
		};


		static void Initialize();
		static void Update();
		static void LayerCollision(eLayerType left, eLayerType right);
		static void ColliderCollision(Collider2D* left, Collider2D* right);
		static bool Intersect(Collider2D* left, Collider2D* right);
		static bool IntersectForMouse(Collider2D* left, Collider2D* right);

		static void SetLayer(eLayerType left, eLayerType right, bool enable);
		static void Clear();
		static bool IntersectLineSegment(Vector3 p1, Vector3 p2, Vector3 q1, Vector3 q2);
	private:
		static std::bitset<LAYER_MAX> mMatrix[LAYER_MAX];
		static std::map<UINT64, bool> mCollisionMap;
		static bool isStart;
	};

}

