#include "jnsSkillUIBG.h"
#include "jnsInput.h"
#include "jnsGameManager.h"

namespace jns
{
	SkillUIBG::SkillUIBG()
	{
		SetState(GameObject::eState::DontDestroy);
		SetIsOnlyOne(true);
	}
	SkillUIBG::~SkillUIBG()
	{
	}
	void SkillUIBG::Initialize()
	{
		SetMesh(L"RectMesh");
		SetMaterial(L"SkillSlotBGMaterial");
		SetPosition(Vector3(250.0f, 100.0f, 4.5f));
		SetScaleWithOriginalImageScale(Vector2(1.0f, 1.0f));

		UIBase::Initialize();
	}
	void SkillUIBG::Update()
	{
		Transform* tr = GetComponent<Transform>();
		Vector3 mPos = tr->GetPosition();
		Vector3 mUIPos = Input::GetUIMousePos();

		Vector3 mLeftTop = Vector3(mPos.x - 155.0f, mPos.y + 190.0f, 0.0f);
		Vector3 mLeftBottom = Vector3(mPos.x - 155.0f, mPos.y + 160.0f, 0.0f);

		Vector3 mRightTop = Vector3(mPos.x + 155.0f, mPos.y + 190.0f, 0.0f);
		Vector3 mRightBottom = Vector3(mPos.x + 155.0f, mPos.y + 160.0f, 0.0f);

		if (Input::GetKeyDown(eKeyCode::LBUTTON)
			&& mUIPos.x >= mLeftTop.x && mUIPos.x <= mRightBottom.x
			&& mUIPos.y <= mLeftTop.y && mUIPos.y >= mRightBottom.y)
		{
			isDragging = true;
			initialMousePos = mUIPos;
			initialObjectPos = mPos;
		}

		if (isDragging && Input::GetKey(eKeyCode::LBUTTON))
		{
			int xOffset = mUIPos.x - initialMousePos.x;
			int yOffset = mUIPos.y - initialMousePos.y;

			mPos.x = initialObjectPos.x + xOffset;
			mPos.y = initialObjectPos.y + yOffset;
			tr->SetPosition(mPos);
		}
		else if (Input::GetKeyUp(eKeyCode::LBUTTON))
		{
			isDragging = false;
		}

		if (Input::GetKeyDown(eKeyCode::K))
		{
			if (isRender == false)
			{
				isRender = true;
			}
			else
			{
				isRender = false;
			}
		}
		UIBase::Update();
	}
	void SkillUIBG::LateUpdate()
	{
		UIBase::LateUpdate();
	}
	void SkillUIBG::Render()
	{
		if(isRender == true)
		UIBase::Render();
	}
}