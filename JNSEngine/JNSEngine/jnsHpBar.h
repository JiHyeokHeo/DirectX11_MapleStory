#pragma once
#include "jnsUIBase.h"

namespace jns
{
	class HpBar : public UIBase
	{
	public:
		HpBar();
		virtual ~HpBar();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:

	};
}



