#pragma once
#include "jnsScript.h"
#include "jnsPierreScript.h"

namespace jns
{
	class PierreAttackRangeScript : public Script
	{
	public:
		virtual void Initialize() override;
		virtual void Update() override;

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;
	private:
		class Collider2D* cd;
		PierreScript* mPrScript;

	};
}

