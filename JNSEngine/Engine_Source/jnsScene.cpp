#include "jnsScene.h"
#include "jnsPlayer.h"
#include "jnsTime.h"
#include "jnsMonster.h"
#include "jnsGameObject.h"

namespace jns
{
	Scene::Scene()
		: mTime(0.0f)
		, mTarget(nullptr)
	{
	}
	Scene::~Scene()
	{
	}
	void Scene::Initialize()
	{
		// 여기서 초기 게임 맵데이터를 세팅해줘야 한다.
		Player* mPlayer = new Player();
		mGameObjects.push_back(mPlayer);

		for (int i = 0; i < 40; i++)
		{
			Monster* mMonster = new Monster();
			mGameObjects.push_back(mMonster);
		}
		
		FindTarget(mPlayer);
	}
	void Scene::Update()
	{

		CollisionCheck(mTarget);
		for (GameObject* gameObj : mGameObjects)
		{
			gameObj->Update();
		}

		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj->GetState() == GameObject::Paused && gameObj->GetTime() >=3.0f)
			{
				gameObj->SetState(GameObject::Active);
			}
		}
	}
	void Scene::LateUpdate()
	{

	}
	void Scene::Render()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if(gameObj->GetState() == GameObject::Active)
			gameObj->Render();
		}
	}

	void Scene::CollisionCheck(GameObject* Target)
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj->GetName() == L"Player")
				continue;
			
			if (gameObj->GetState() == GameObject::Active)
			InterSect(Target, gameObj);
		}
	}

	void Scene::InterSect(GameObject* Target, GameObject* CheckList)
	{
		Vector2 mTargetDistance = Target->GetPos();
		Vector2 mCheckList = CheckList->GetPos();
		
		// 거리 
		float mBetweenDistance = sqrt(powf(mTargetDistance.x - mCheckList.x, 2) + powf(mTargetDistance.y - mCheckList.y, 2));
		//float mBetweenDistance = Vector2::Distance(mTargetDistance, mCheckList);
		
		// 반지름
		float mTargetRadius = Target->GetScale();
		float mCheckListRadius = CheckList->GetScale();

		float mRadiusDifference = abs(mTargetRadius + mCheckListRadius);

		if (mBetweenDistance <= mRadiusDifference)
		{
			CheckList->SetState(GameObject::Paused);
			CollisionEnter(Target);
		}
		else
		{
			CollisionOut(Target);
		}
	}

	void Scene::CollisionEnter(GameObject* target)
	{
		target->SetCol(true);
	}

	void Scene::CollisionOut(GameObject* target)
	{
		//target->SetCol(false);
	}
	void Scene::SetRandomPos()
	{
	}
}