#pragma once
#include "jnsScript.h"

namespace jns
{
	class testScript : public Script
	{
	public:
		enum class eSmokeType
		{
			Right,
			Left,
			None,
		};
		testScript();
		~testScript();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void BindConstantBuffer();

	private:
		float mTime;
		int mT;
		eSmokeType mSmokeType;
	};
}
