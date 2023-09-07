#pragma once
#include "jnsUIBase.h"
#include "jnsInput.h"

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

		void SetIndexNum(int y, int x, eKeyCode code) { indexNum[y][x] = code; }
		eKeyCode GetIndexKeyCode(int xidx, int yidx) { return indexNum[xidx][yidx]; }
	private:
		std::vector<std::vector<eKeyCode>> indexNum;
	};
}




