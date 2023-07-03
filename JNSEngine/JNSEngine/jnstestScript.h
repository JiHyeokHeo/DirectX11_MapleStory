#pragma once
#include "jnsScript.h"

namespace jns
{
	class testScript : public Script
	{
	public:
		testScript();
		~testScript();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void BindConstantBuffer();

	private:
		float mTime;
	};
}
