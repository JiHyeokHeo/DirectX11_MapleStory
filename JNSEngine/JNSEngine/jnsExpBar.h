#pragma once
#include "jnsUIBase.h"

namespace jns
{
	class ExpBar : public UIBase
	{
	public:
		ExpBar();
		virtual ~ExpBar();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;


	private:

	};
}
