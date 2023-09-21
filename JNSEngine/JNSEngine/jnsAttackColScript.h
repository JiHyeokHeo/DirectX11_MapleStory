#pragma once
#include "jnsScript.h"

namespace jns
{
	class AttackColScript : public Script
	{
	public:
		virtual void Update() override;

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

		std::vector<GameObject*> GetMonsterObjects() { return MonsterGameObjects; }
	private:
		std::vector<GameObject*> MonsterGameObjects;
	};
}

