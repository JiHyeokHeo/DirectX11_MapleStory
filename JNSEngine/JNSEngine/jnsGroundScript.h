#pragma once
#include "jnsScript.h"

namespace jns
{
	class GroundScript : public Script
	{

	public:
		GroundScript();
		~GroundScript();
		
		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

	private:

	};

}
