#include "jnsAttackColScript.h"
#include "CommonSceneInclude.h"

namespace jns
{
	AttackColScript::AttackColScript()
	{
	}
	AttackColScript::~AttackColScript()
	{
		//MonsterGameObjects.clear();
	}
	void AttackColScript::Update()
	{
		

	}

	void AttackColScript::OnCollisionEnter(Collider2D* other)
	{
		
	}
	void AttackColScript::OnCollisionStay(Collider2D* other)
	{
		
	}
	void AttackColScript::OnCollisionExit(Collider2D* other)
	{
	}
	void AttackColScript::UpdateMonsters()
	{
		Scene* scene = SceneManager::GetActiveScene();
		MonsterGameObjects = (scene->FindObjects<GameObject>(eLayerType::Monster));
	}
	void AttackColScript::CheckMonster(Collider2D* other)
	{
		if (other->GetOwner()->GetLayerType() == eLayerType::Monster)
		{
			BloodyMeso* meso = dynamic_cast<BloodyMeso*>(GetOwner());

			Vector3 monsterPos = other->GetOwner()->GetComponent<Transform>()->GetPosition();
			Vector3 mesoPos = GetOwner()->GetComponent<Transform>()->GetPosition();
			if (mesoPos.x <= monsterPos.x + 10.0f && mesoPos.x >= monsterPos.x - 10.0f)
			{
				if (meso->GetIsActive() == true)
				{
					meso->SetIsActive(false);
					MesoPooling::MesoObjectPooling::GetInstance().RecycleMesoObject(this->GetOwner());
				}
			}
		}
	}
}