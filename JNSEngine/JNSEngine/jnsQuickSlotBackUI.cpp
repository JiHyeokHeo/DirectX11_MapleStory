#include "jnsQuickSlotBackUI.h"
#include "CommonUIInclude.h"
#include "jnsQuickSlotScript.h"

namespace jns
{
	QuickSlotUI::QuickSlotUI()
	{
		SetIsOnlyOne(true);
		SetState(eState::DontDestroy);
		int row = 2;
		int col = 16;
		indexNum.assign(row, std::vector<eKeyCode>(col, eKeyCode::END));
		indexOn.resize(2, std::vector<bool>(5));
	}
	QuickSlotUI::~QuickSlotUI()
	{
	}
	void QuickSlotUI::Initialize()
	{
		SetMesh(L"RectMesh");
		SetMaterial(L"SkillQuickSlotBackMaterial");
		SetPosition(Vector3(405.0f, -339.0f, 4.3f));
		SetScaleWithOriginalImageScale(Vector2(1.0f,1.0f));
		
		indexNum[0][0] = eKeyCode::LSHIFT;
		indexNum[0][1] = eKeyCode::Q;
		indexNum[0][2] = eKeyCode::W;
		indexNum[0][3] = eKeyCode::E;
		indexNum[0][4] = eKeyCode::R;
		indexNum[1][0] = eKeyCode::LCTRL;
		indexNum[1][1] = eKeyCode::A;
		indexNum[1][2] = eKeyCode::S;
		indexNum[1][3] = eKeyCode::D;
		indexNum[1][4] = eKeyCode::F;

		// 크기조절

		AddComponent<QuickSlotScript>();
		UIBase::Initialize();
	}
	void QuickSlotUI::Update()
	{

		UIBase::Update();
	}
	void QuickSlotUI::LateUpdate()
	{
		UIBase::LateUpdate();
	}
	void QuickSlotUI::Render()
	{
		UIBase::Render();
	}
}