#pragma once
#include "jnsUIBase.h"

namespace jns
{
	class QuickSlotUI : public UIBase
	{
	public:
		QuickSlotUI();
		virtual ~QuickSlotUI();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void SetIndexNum(int y, int x, bool set) { indexNum[y][x] = set; }
		
	private:
		std::vector<std::vector<bool>> indexNum;
	};
}




