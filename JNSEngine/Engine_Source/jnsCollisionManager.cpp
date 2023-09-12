#include "jnsCollisionManager.h"
#include "jnsGameObject.h"
#include "jnsScene.h"
#include "jnsSceneManager.h"
#include "jnsLayer.h"
#include "jnsCollider2D.h"
#include "jnsInput.h"



namespace jns
{
	std::bitset<LAYER_MAX> CollisionManager::mMatrix[LAYER_MAX] = {};
	std::map<UINT64, bool>CollisionManager::mCollisionMap = {};
	bool CollisionManager::isStart = false;
	void CollisionManager::Initialize()
	{
	}
	void CollisionManager::Update()
	{
		if (SceneManager::isLoading == true)
			return;

		if (isStart == true)
		{
			for (UINT column = 0; column < (UINT)eLayerType::End; column++)
			{
				for (UINT row = 0; row < (UINT)eLayerType::End; row++)
				{
					if (mMatrix[column][row] == true)
					{
						LayerCollision((eLayerType)column, (eLayerType)row);
					}
				}
			}
		}
		else
		{
			isStart = true;
		}
	}
	void CollisionManager::LayerCollision(eLayerType left, eLayerType right)
	{
		Scene* activeScene = SceneManager::GetActiveScene();

		const std::vector<GameObject*>& lefts
			= activeScene->GetLayer(left).GetGameObjects();
		const std::vector<GameObject*>& rights
			= activeScene->GetLayer(right).GetGameObjects();

		if (lefts.size() == 0  || rights.size() == 0)
			return;

		for (GameObject* leftObj : lefts)
		{
			std::vector<Collider2D*> leftCols = {};
			leftCols = leftObj->GetComponents<Collider2D>();

			if (leftCols.capacity() == 0)
				continue;

			for (GameObject* rightObj : rights)
			{
				std::vector<Collider2D*> rightCols = {};
				rightCols = rightObj->GetComponents<Collider2D>();
				if (rightCols.capacity() == 0)
					continue;
				if (leftObj == rightObj)
					continue;
				
				for (int i = 0; i < leftCols.capacity(); i++)
				{
					for (int j = 0; j < rightCols.capacity(); j++)
					{
						ColliderCollision(leftCols[i], rightCols[j]);
					}
				}
			}
		}


	}
	void CollisionManager::ColliderCollision(Collider2D* left, Collider2D* right)
	{
		//bool isCursor = false;
		//if (left->GetOwner()->GetLayerType() == eLayerType::Cursor ||
		//	right->GetOwner()->GetLayerType() == eLayerType::Cursor)
		//	isCursor = true;

			
		// 두 충돌체의 ID bool값을 확인
		ColliderID id = {};
		id.left = left->GetColliderID();
		id.right= right->GetColliderID();

		// 충돌 정보를 가져온다
		std::map<UINT64, bool>::iterator iter
			= mCollisionMap.find(id.id);

		if (iter == mCollisionMap.end())
		{
			mCollisionMap.insert(std::make_pair(id.id, false));
			iter = mCollisionMap.find(id.id);
		}

		
		if (Intersect(left, right))
		{
			// 충돌
			if (iter->second == false)
			{
				// 최초충돌
				left->OnCollisionEnter(right);
				right->OnCollisionEnter(left);
			}
			else
			{
				// 충돌 중
				left->OnCollisionStay(right);
				right->OnCollisionStay(left);
			}
			iter->second = true;
		}
		else
		{
			// 충돌 X
			if (iter->second == true)
			{
				// 충돌하고 있다가 나갈떄
				left->OnCollisionExit(right);
				right->OnCollisionExit(left);
			}
			iter->second = false;
		}
		


	
	}
	bool CollisionManager::Intersect(Collider2D* left, Collider2D* right)
	{		
		if (left == nullptr || right == nullptr)
			return false;

		if (left->GetColliderOn() == false || right->GetColliderOn() == false)
			return false;

		if (left->GetType() == eColliderType::Rect && right->GetType() == eColliderType::Rect)
		{
			const Vector3& leftColCenterPos = left->GetPosition();
			const Vector3& righColCentertPos = right->GetPosition();

			Vector3 colPosDiff = leftColCenterPos - righColCentertPos;

			Vector3 leftColR = left->GetOwner()->GetComponent<Transform>()->Right();
			Vector3 leftColUp = left->GetOwner()->GetComponent<Transform>()->Up();
			Vector3 rightColR = right->GetOwner()->GetComponent<Transform>()->Right();
			Vector3 rightColUp = right->GetOwner()->GetComponent<Transform>()->Up();
		

			// 스케일 전환을 해줘도 문제없도록 Collider의 스케일을 가져오도록함
			Vector3 leftColLocalScale = left->GetScale();
			Vector3 rightColLocalScale = right->GetScale();
		
			// 단위 법선 벡터들을 넣어주고              
			std::vector<Vector3> checkPos = {};
			checkPos.push_back(leftColR);
			checkPos.push_back(leftColUp);
			checkPos.push_back(rightColR);
			checkPos.push_back(rightColUp);

			// 두 충돌체의 길이측정용 
			leftColR *= leftColLocalScale.x / 2;
			leftColUp *= leftColLocalScale.y / 2;
			rightColR *= rightColLocalScale.x / 2;
			rightColUp *= rightColLocalScale.y / 2;
		
			for (int i = 0; i < 4; i++)
			{
				float colDistance = abs((checkPos[i].Dot(colPosDiff)));

				if (colDistance > abs(checkPos[i].Dot(leftColR))
					+ abs(checkPos[i].Dot(leftColUp))
					+ abs(checkPos[i].Dot(rightColR))
					+ abs(checkPos[i].Dot(rightColUp)))
					return false;
			}
		}
		else if(left->GetType() == eColliderType::Line && right->GetType() == eColliderType::Rect)
		{
			Vector3 lineStart = left->GetStartPoint(); 
			Vector3 lineEnd = left->GetEndPoint();     
			Vector3 rectCenter = right->GetPosition();
			Vector2 rectSize = right->GetSize();
			Vector3 rectScale = right->GetScale();

			rectSize.x *= rectScale.x;
			rectSize.y *= rectScale.y;

			Vector3 rectCorners[4];
			rectCorners[0] = rectCenter + Vector3(-rectSize.x / 2, rectSize.y / 2, 0.0f);
			rectCorners[1] = rectCenter + Vector3(rectSize.x / 2, rectSize.y / 2, 0.0f);
			rectCorners[2] = rectCenter + Vector3(-rectSize.x / 2, -rectSize.y / 2, 0.0f);
			rectCorners[3] = rectCenter + Vector3(rectSize.x / 2, -rectSize.y / 2, 0.0f);

			for (int i = 0; i < 4; ++i)
			{
				Vector3 rectEdge1 = rectCorners[i];
				Vector3 rectEdge2 = rectCorners[(i + 1) % 4];

				if (IntersectLineSegment(lineStart, lineEnd, rectEdge1, rectEdge2))
				{
					return true; // Collision detected
				}
			}

		}
		else if(left->GetType() == eColliderType::Rect && right->GetType() == eColliderType::Line)
		{
			Vector3 lineStart = right->GetStartPoint(); 
			Vector3 lineEnd = right->GetEndPoint();     
			Vector3 rectCenter = left->GetPosition();
			Vector2 rectSize = left->GetSize();
			Vector3 rectScale = left->GetScale();

			rectSize.x *= rectScale.x;
			rectSize.y *= rectScale.y;

			Vector3 rectCorners[4];
			rectCorners[0] = rectCenter + Vector3(-rectSize.x / 2, rectSize.y / 2, 0.0f);
			rectCorners[1] = rectCenter + Vector3(rectSize.x / 2, rectSize.y / 2, 0.0f);
			rectCorners[2] = rectCenter + Vector3(-rectSize.x / 2, -rectSize.y / 2, 0.0f);
			rectCorners[3] = rectCenter + Vector3(rectSize.x / 2, -rectSize.y / 2, 0.0f);

			for (int i = 0; i < 4; ++i)
			{
				Vector3 rectEdge1 = rectCorners[i];
				Vector3 rectEdge2 = rectCorners[(i + 1) % 4];

				if (IntersectLineSegment(lineStart, lineEnd, rectEdge1, rectEdge2))
				{
					return true; 
				}
			}
		}



		return true;
	}
	bool CollisionManager::IntersectForMouse(Collider2D* left, Collider2D* right)
	{
		if (left == nullptr || right == nullptr)
			return false;

		Vector3 leftColCenterPos = {};
		Vector3 righColCentertPos = {};
		//if (left->GetOwner()->GetLayerType() == eLayerType::Cursor)
		//{
		//	leftColCenterPos = Input::GetUIMousePos();
		//	righColCentertPos = right->GetPosition();
		//}
		//else if (right->GetOwner()->GetLayerType() == eLayerType::Cursor)
		//{
		//	leftColCenterPos = left->GetPosition();
		//	righColCentertPos = Input::GetUIMousePos();
		//}
	
		Vector3 colPosDiff = leftColCenterPos - righColCentertPos;
		Vector3 leftColR = left->GetOwner()->GetComponent<Transform>()->Right();
		Vector3 leftColUp = left->GetOwner()->GetComponent<Transform>()->Up();
		Vector3 rightColR = right->GetOwner()->GetComponent<Transform>()->Right();
		Vector3 rightColUp = right->GetOwner()->GetComponent<Transform>()->Up();


		// 스케일 전환을 해줘도 문제없도록 Collider의 스케일을 가져오도록함
		Vector3 leftColLocalScale = left->GetScale();
		Vector3 rightColLocalScale = right->GetScale();

		// 단위 법선 벡터들을 넣어주고              
		std::vector<Vector3> checkPos = {};
		checkPos.push_back(leftColR);
		checkPos.push_back(leftColUp);
		checkPos.push_back(rightColR);
		checkPos.push_back(rightColUp);

		// 두 충돌체의 길이측정용 
		leftColR *= leftColLocalScale.x / 2;
		leftColUp *= leftColLocalScale.y / 2;
		rightColR *= rightColLocalScale.x / 2;
		rightColUp *= rightColLocalScale.y / 2;

		for (int i = 0; i < 4; i++)
		{
			float colDistance = abs((checkPos[i].Dot(colPosDiff)));

			if (colDistance > abs(checkPos[i].Dot(leftColR))
				+ abs(checkPos[i].Dot(leftColUp))
				+ abs(checkPos[i].Dot(rightColR))
				+ abs(checkPos[i].Dot(rightColUp)))
				return false;
		}


		return true;
	}
	void CollisionManager::SetLayer(eLayerType left, eLayerType right, bool enable)
	{
		UINT row = -1;
		UINT col = -1;

		UINT mLeft = (UINT)left;
		UINT mRight = (UINT)right;

		if (mLeft <= mRight)
		{
			row = mLeft;
			col = mRight;
		}
		else
		{
			row = mRight;
			col = mLeft;
		}

		mMatrix[col][row] = enable; 

	}
	void CollisionManager::Clear()
	{
		mMatrix->reset();
		mCollisionMap.clear();
	}

	bool CollisionManager::IntersectLineSegment(Vector3 p1, Vector3 p2, Vector3 q1, Vector3 q2)
	{
		Vector3 r = p2 - p1;
		Vector3 s = q2 - q1;

		float crossProduct = r.Cross(s).Length();

		Vector3 qMinusP = q1 - p1;
		float t = qMinusP.Cross(s).Length() / crossProduct;
		float u = qMinusP.Cross(r).Length() / crossProduct;

		if (crossProduct == 0 && qMinusP.Cross(r).Length() == 0) {
			// Collinear, check if they overlap
			if ((q1 - p1).Dot(r) >= 0 && (q1 - p2).Dot(r) <= 0)
				return true;
		}

		if (crossProduct != 0 && t >= 0 && t <= 1 && u >= 0 && u <= 1)
			return true;

		return false;
	}




}