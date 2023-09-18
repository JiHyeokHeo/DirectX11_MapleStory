#pragma once
#include "jnsScript.h"
#include "jnsPierreScript.h"

namespace jns
{
	class PierreAttackColScirpt : public Script
	{
	public:
		struct PierreSkillDamage
		{
			int normalAttack = 30;
			int swallowAttack = 1250;
			int bressAttack = 10000;
		};
		virtual void Initialize() override;
		virtual void LateUpdate() override;

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

	private:
		void AttackNormal(Vector2 collidersize, Vector2 collidercenter, int anistartIdx, int aniendIdx);

		class Collider2D* cd;
		PierreScript* mPrScript;
		PierreSkillDamage mPrSkillDamage;

		class Animator* at;
		DamageDisplay damageDisplay;
	};

}
