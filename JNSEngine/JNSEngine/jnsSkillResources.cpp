#include "jnsSkillResources.h"
#include "CommonSceneInclude.h"
constexpr auto SKILLICON_SIZE = 30.0f;

namespace jns
{
	bool SkillResources::isPicked = false;
	SkillResources::SkillResources(eSkillType type)
		: at(nullptr)
		, mSkillType(type)
		, isMovePossible(false)
		, isRender (true)
	{
		SetIsOnlyOne(true);
		SetState(GameObject::eState::DontDestroy);
	}
	SkillResources::~SkillResources()
	{
	}
	void SkillResources::Initialize()
	{
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));
		at = AddComponent<Animator>();
		switch (mSkillType)
		{
		case eSkillType::Assain:
			SetAssainSkill();
			break;
		}

		if (mSkillType == eSkillType::Assain)
		{
			at->PlayAnimation(L"Assain_able", true);
		}

		Vector3 skillUIPos = skillBGUI->GetComponent<Transform>()->GetPosition();

		if (isItIcon)
		{
			skillUIPos.x -= 130.0f;
			skillUIPos.y += 70.0f;
			tr->SetPosition(skillUIPos);
		}

		if (isItIcon == false)
		{
			isRender = false;
		}
	}
	void SkillResources::Update()
	{
		Vector3 mSkillResourcesPos = tr->GetPosition();
		Vector2 mLeftTop = Vector2(mSkillResourcesPos.x - SKILLICON_SIZE, mSkillResourcesPos.y + SKILLICON_SIZE);
		Vector2 mRightBottom = Vector2(mSkillResourcesPos.x + SKILLICON_SIZE, mSkillResourcesPos.y - SKILLICON_SIZE);
		Vector3 mousePos = Input::GetUIMousePos();

		if (mousePos.x >= mLeftTop.x && mousePos.x <= mRightBottom.x && mousePos.y <= mLeftTop.y && mousePos.y >= mRightBottom.y)
		{
			if(Input::GetKeyDown(eKeyCode::LBUTTON)) 
			{
				isPicked = true;
			}
		}
		
		if (isPicked)
		{
			isRender = true;
			isMovePossible = true;
		}

		if (mousePos.x >= mLeftTop.x && mousePos.x <= mRightBottom.x && mousePos.y <= mLeftTop.y && mousePos.y >= mRightBottom.y)
		{
			if (isMovePossible == true && isItIcon == false)
			{
				if (Input::GetKeyDown(eKeyCode::LBUTTON))
				{
					Vector3 quickSlotPos = skillQuickSlot->GetComponent<Transform>()->GetPosition();
					Vector3 quickSlotSize = skillQuickSlot->GetComponent<Transform>()->GetScale();
					Vector2 leftTop = {};
					Vector2 rightBottom = {};
					leftTop.x = quickSlotPos.x - (quickSlotSize.x / 2);
					leftTop.y = quickSlotPos.y + (quickSlotSize.y / 2);
					rightBottom.x = quickSlotPos.x + (quickSlotSize.x / 2);
					rightBottom.y = quickSlotPos.y - (quickSlotSize.y / 2);

					if (mousePos.x >= leftTop.x && mousePos.x <= rightBottom.x && mousePos.y <= leftTop.y && mousePos.y >= rightBottom.y)
					{
						isOnTarget = true;
					}
					else
					{
						isRender = false;
						isPicked = false;
					}

					if (isOnTarget)
					{
						Vector2 checkPos = Vector2(mousePos.x - leftTop.x, leftTop.y - mousePos.y);
						int xidx = checkPos.x / (SKILLICON_SIZE + 5.0f);
						int yidx = checkPos.y / (SKILLICON_SIZE + 5.0f);
						Vector2 itemSetPos = Vector2((xidx * (SKILLICON_SIZE + 2.5f)) + (2.5f * xidx) + (SKILLICON_SIZE / 2), (yidx * (SKILLICON_SIZE + 2.5f)) + (1.5f * yidx) + (SKILLICON_SIZE / 2));
						Vector3 itemFinalPos = Vector3(1.5f + itemSetPos.x + leftTop.x, -1.5f + leftTop.y - itemSetPos.y, 3.5f);
						//skillQuickSlot->SetIndexNum(yidx, xidx, true);
						tr->SetPosition(itemFinalPos);
						//isMovePossible = false;
						isPicked = false;
						isOnTarget = false;
					}
				}
			}
		}

		if (isMovePossible && isItIcon == false)
		{
			MouseBTNClick();
		}
	
		
		UIBase::Update();
	}
	void SkillResources::LateUpdate()
	{
		UIBase::LateUpdate();
	}
	void SkillResources::Render()
	{
		if(isRender == true)
		UIBase::Render();
	}
	void SkillResources::MouseBTNClick()
	{
		if (isPicked == true)
		{
			tr->SetPosition(Input::GetUIMousePos());
		}
	}
	void SkillResources::MouseBTNClickOff()
	{
		
	}
	void SkillResources::ClickOnQuickSlot()
	{
	}
	void SkillResources::ClickOffQuickSlot()
	{
	}
	void SkillResources::SetAssainSkill()
	{
		at->CreateAnimations(L"..\\Resources\\UI\\SkillUI\\Assain\\_able", 100, 0.1f);
		at->CreateAnimations(L"..\\Resources\\UI\\SkillUI\\Assain\\_disable", 100, 0.1f);

		GetComponent<Transform>()->SetScale(Vector3(100.0f, 100.0f, 1.0f));
	}
}