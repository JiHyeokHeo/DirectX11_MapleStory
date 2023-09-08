#pragma once
#include "jnsScript.h"
#include "DamageDisplay.h"

namespace jns
{

	class DemonAttackCol : public Script
	{
	public:
		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

	private:
		class Collider2D* cd;
		class DemonMonsterScript* mDMScript;
		DamageDisplay damageDisplay;
	};

}
