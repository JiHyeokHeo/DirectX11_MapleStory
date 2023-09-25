#include "jnsSpawner.h"
#include "ObjectTemplate.h"
#include "jnsDemonMonster.h"

namespace jns
{
	Spawner::Spawner()
	{
	}
	Spawner::~Spawner()
	{
		monsters.clear();
	}
	void Spawner::Initialize()
	{
		SceneManager::GetActiveScene()->AddGameObject(eLayerType::MapEffect, this);
		// 씬별에 맞게 스포너 해주면 될듯함
		for (int i = -8; i <= 9; i++)
		{
			monsters.push_back(object::Instantiate<DemonMonster>(eLayerType::Monster, Vector3(200 * i, -180.0f, 2.0f)));
		}

	}
	void Spawner::Update()
	{
		GameObject::Update();
	}
	void Spawner::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Spawner::Render()
	{
	}
	void Spawner::Activate()
	{
		for (int i = 0; i < monsters.size(); i++)
		{
			monsters[i]->Activate();
		}
	}
	void Spawner::DeActivate()
	{
	}
	void Spawner::SetPosition(Vector3 pos)
	{
	}
}