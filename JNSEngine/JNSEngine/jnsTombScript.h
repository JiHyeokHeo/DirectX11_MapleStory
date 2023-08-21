#pragma once
#include "jnsScript.h"

namespace jns
{
	class TombScript : public Script
	{
	public:
		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

	private:

	};

}
