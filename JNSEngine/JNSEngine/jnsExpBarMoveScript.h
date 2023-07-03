#pragma once
#include "jnsScript.h"

namespace jns
{
	class ExpBarMoveScript : public Script
	{
	public:
		ExpBarMoveScript();
		~ExpBarMoveScript();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void BindConstantBuffer();

	private:
		float mTime;
	};
}


