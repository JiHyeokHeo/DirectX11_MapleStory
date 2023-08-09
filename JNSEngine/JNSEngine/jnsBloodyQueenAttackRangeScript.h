#pragma once
#include "jnsScript.h"
#include "jnsBloodyQueenScript.h"

namespace jns
{
	class BloodyQueenAttackRangeScript : public Script
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
		BloodyQueenScript* mBQScript;

	};
}
