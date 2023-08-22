#pragma once
#include "jnsScript.h"
#include "jnsBloodyQueenScript.h"

namespace jns
{
	class BloodyQueenAttackCol : public Script
	{
	public:
		struct BloodyQueenSkillDamage
		{
			int normalAttack = 30;

		};
		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;
	private:
		class Collider2D* cd;
		bool isColPosSet;
		float mBlackOutReturnTime;
		float mColMakeTime;
		BloodyQueenScript* mBQScript;
		BloodyQueenSkillDamage mBQSkillDamage;
		bool isNomralAttackHit;
	};
}


