#pragma once
#include "jnsUIBase.h"

namespace jns
{
	class MpBar : public UIBase
	{
	public:
		MpBar();
		virtual ~MpBar();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:

	};
}

