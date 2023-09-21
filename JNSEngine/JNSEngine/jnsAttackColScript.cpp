#include "jnsAttackColScript.h"
#include "CommonSceneInclude.h"

namespace jns
{
	void AttackColScript::Update()
	{
		// 상시로 몬스터 갱신
		Scene* scene = SceneManager::GetActiveScene();
		MonsterGameObjects = (scene->FindObjects<GameObject>(eLayerType::Monster));
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
}