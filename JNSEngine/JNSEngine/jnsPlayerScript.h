#pragma once
#include "jnsScript.h"

namespace jns
{
	class PlayerScript : public Script
	{
	public:
		virtual void Update() override;
		virtual void Render() override;

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

		void bindConstantBuffer();
	private:
	};
}
