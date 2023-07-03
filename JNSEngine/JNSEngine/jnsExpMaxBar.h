#pragma once
#include "jnsUIBase.h"

namespace jns
{
	class ExpMaxBar : public UIBase
	{
	public:
		ExpMaxBar();
		virtual ~ExpMaxBar();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:

	};
}

