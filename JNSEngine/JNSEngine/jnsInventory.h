#pragma once
#include "jnsUIBase.h"

namespace jns
{
	class Inventory : public UIBase
	{
	public:
		Inventory();
		virtual ~Inventory();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:
	};
	
}
