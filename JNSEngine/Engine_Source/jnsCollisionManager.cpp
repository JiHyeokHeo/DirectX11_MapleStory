#include "jnsCollisionManager.h"
#include "jnsGameObject.h"
#include "jnsScene.h"
#include "jnsSceneManager.h"
#include "jnsLayer.h"
#include "jnsCollider2D.h"

namespace jns
{
	std::bitset<LAYER_MAX> CollisionManager::mMatrix[LAYER_MAX] = {};
	std::map<UINT64, bool>CollisionManager::mCollisionMap = {};

	void CollisionManager::Initialize()
	{
	}
	void CollisionManager::Update()
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
	void CollisionManager::LayerCollision(eLayerType left, eLayerType right)
	{
		Scene* activeScene = SceneManager::GetActiveScene();

		const std::vector<GameObject*>& lefts
			= activeScene->GetLayer(left).GetGameObjects();
		const std::vector<GameObject*>& rights
			= activeScene->GetLayer(right).GetGameObjects();

		for (GameObject* leftObj : lefts)
		{
			Collider2D* leftCol = leftObj->GetComponent<Collider2D>();

			if (leftCol == nullptr)
				continue;
			if (leftObj->GetState()
				!= GameObject::eState::Active)
				continue;

			for (GameObject* rightObj : rights)
			{
				Collider2D* rightCol = rightObj->GetComponent<Collider2D>();
				if (rightCol == nullptr)
					continue;
				if (leftObj == rightObj)
					continue;
				if (rightObj->GetState()
					!= GameObject::eState::Active)
					continue;

				ColliderCollision(leftCol, rightCol);
			}
		}


	}
	void CollisionManager::ColliderCollision(Collider2D* left, Collider2D* right)
	{	
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
		}
	
	}
	bool CollisionManager::Intersect(Collider2D* left, Collider2D* right)
	{		
		if (left == nullptr || right == nullptr)
			return false;


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
		
		// 단위 법선 벡터들을 넣어주고              // 제가 실수로 여기를 밑으로 내려서 작업쳤거든요? 그래도 작동이 됐었는데 이유 궁금..
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
		

		//// 단위 법선 벡터들을 넣어주고              // 제가 실수로 여기를 밑으로 내려서 작업쳤거든요?
		//std::vector<Vector3> checkPos = {};
		//checkPos.push_back(leftColR);
		//checkPos.push_back(leftColUp);
		//checkPos.push_back(rightColR);
		//checkPos.push_back(rightColUp);
		// 네모 네모 충돌
		// 분리축 이론

		for (int i = 0; i < 4; i++)
		{
			float colDistance = abs((checkPos[i].Dot(colPosDiff)));

			if (colDistance > abs(checkPos[i].Dot(leftColR))
				+ abs(checkPos[i].Dot(leftColUp))
				+ abs(checkPos[i].Dot(rightColR))
				+ abs(checkPos[i].Dot(rightColUp)))
				return false;
		}
		
		

		// To do... (숙제)
		// 분리축이 어렵다 하시는분들은
		// 원 - 원 충돌

		//math::

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




}