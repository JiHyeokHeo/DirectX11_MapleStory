#include "jnsLayer.h"


namespace jns
{
	Layer::Layer()
	{
	}
	Layer::~Layer()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj == nullptr)
				continue;

			delete gameObj;
			gameObj = nullptr;
		}
	}
	void Layer::Initialize()
	{
	}
	void Layer::Update()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			//if (gameObj->GetState()
			//	!= GameObject::eState::Active)
			//	continue;
			gameObj->Update();
		}
	}
	void Layer::LateUpdate()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			//if (gameObj->GetState()
			//	!= GameObject::eState::Active)
			//	continue;
			gameObj->LateUpdate();
		}
	}
	void Layer::Render()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj->GetState()
				!= GameObject::eState::Active)
				continue;
			gameObj->Render();
		}
	}
	void Layer::Destroy()
	{
		// dead 오브젝트 모아두기
		std::set<GameObject*> deleteGameObj = {};
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj->GetState()
				== GameObject::eState::Dead)
				deleteGameObj.insert(gameObj);
		}

		// daed 오브젝트 제외시키기 layer에서
		typedef std::vector<GameObject*>::iterator GameObjectIter;
		for (GameObjectIter iter = mGameObjects.begin()
			; iter != mGameObjects.end(); )
		{
			std::set<GameObject*>::iterator deleteIter
				= deleteGameObj.find(*(iter));

			if (deleteIter != deleteGameObj.end())
			{
				iter = mGameObjects.erase(iter);
				continue;
			}

			iter++;
		}

		//메모리 해제
		for (GameObject* gameObj : deleteGameObj)
		{
			delete gameObj;
			gameObj = nullptr;
		}
	}
	void Layer::DontDestroySceneExit()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj->GetState()
				== GameObject::eState::DontDestroy)
				DeleteGameObject(gameObj);
		}
	}
	void Layer::DontDestroySceneEnter()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			if (gameObj->GetState()
				== GameObject::eState::DontDestroy)
				AddGameObject(gameObj);
		}
	}
	void Layer::AddGameObject(GameObject* gameObj)
	{
		mGameObjects.push_back(gameObj);
	}
	void Layer::DeleteGameObject(GameObject* gameObj)
	{
		std::vector<GameObject*>::iterator iter;
		for (iter = mGameObjects.begin(); iter != mGameObjects.end();)
		{
			if (*iter == gameObj)
			{
				iter = mGameObjects.erase(iter);
				continue;
			}

			iter++;
		}
	}
}