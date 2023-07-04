#pragma once
#include "jnsUIBase.h"

namespace jns
{
	class CenterStatus : public UIBase
	{
	public:
		CenterStatus();
		virtual ~CenterStatus();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:

	};
}

