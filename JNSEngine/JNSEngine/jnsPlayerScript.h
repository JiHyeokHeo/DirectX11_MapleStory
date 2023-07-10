#pragma once
#include "jnsScript.h"

namespace jns
{
	class PlayerScript : public Script
	{
	public:
		virtual void Update() override;
		virtual void Render() override;

		void bindConstantBuffer();
	private:
	};
}
