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
}