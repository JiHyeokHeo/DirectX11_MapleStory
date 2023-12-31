#pragma once
#include "jnsScript.h"
#include "jnsBloodyQueenScript.h"
#include "DamageDisplay.h"
#include "DamageInterface.h"

namespace jns
{
	class BloodyQueenAttackCol : public Script
	{
	public:
		struct BloodyQueenSkillDamage
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
		void AttackNormal();

		class Collider2D* cd;
		BloodyQueenScript* mBQScript;
		BloodyQueenSkillDamage mBQSkillDamage;

		class Animator* at;
		DamageDisplay damageDisplay;
	};
}


