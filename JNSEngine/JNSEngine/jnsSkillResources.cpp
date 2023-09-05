#include "jnsSkillResources.h"
#include "CommonSceneInclude.h"
constexpr auto SKILLICON_SIZE = 30.0f;

namespace jns
{
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
		case eSkillType::MesoExplosionRed:
			SetExplosionRedSkill();
			break;
		}

		Vector3 skillUIPos = skillBGUI->GetComponent<Transform>()->GetPosition();

		switch (mSkillType)
		{
		case eSkillType::Assain:
			skillUIPos.x -= 130.0f;
			skillUIPos.y += 70.0f;
			tr->SetPosition(skillUIPos);
			at->PlayAnimation(L"Assain_able", true);
			break;
		case eSkillType::MesoExplosionRed:
			skillUIPos.x += 15.0f;
			skillUIPos.y += 70.0f;
			tr->SetPosition(skillUIPos);
			at->PlayAnimation(L"MesoExplosionRed_able", true);
			break;
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

		if (mousePos.x >= mLeftTop.x && mousePos.x <= mRightBottom.x 
			&& mousePos.y <= mLeftTop.y && mousePos.y >= mRightBottom.y)
		{
			Vector3 quickSlotPos = skillQuickSlot->GetComponent<Transform>()->GetPosition();
			Vector3 quickSlotSize = skillQuickSlot->GetComponent<Transform>()->GetScale();
			Vector2 quickslotleftTop = {};
			Vector2 quickslotrightBottom = {};
			quickslotleftTop.x = quickSlotPos.x - (quickSlotSize.x / 2);
			quickslotleftTop.y = quickSlotPos.y + (quickSlotSize.y / 2);
			quickslotrightBottom.x = quickSlotPos.x + (quickSlotSize.x / 2);
			quickslotrightBottom.y = quickSlotPos.y - (quickSlotSize.y / 2);

			if (mousePos.x >= quickslotleftTop.x && mousePos.x <= quickslotrightBottom.x && mousePos.y <= quickslotleftTop.y && mousePos.y >= quickslotrightBottom.y)
			{
				isOnTarget = true;
			}

			if (Input::GetKeyDown(eKeyCode::LBUTTON) && isPicked == false && isItIcon == false)
			{
				isMovePossible = true;
				isPicked = true;
			}
			else if(Input::GetKeyDown(eKeyCode::LBUTTON) && isItIcon == false && isPicked == true)
			{
				if (isOnTarget)
				{
					Vector2 checkPos = Vector2(mousePos.x - quickslotleftTop.x, quickslotleftTop.y - mousePos.y);
					int xidx = checkPos.x / (SKILLICON_SIZE + 5.0f);
					int yidx = checkPos.y / (SKILLICON_SIZE + 5.0f);
					Vector2 itemSetPos = Vector2((xidx * (SKILLICON_SIZE + 2.5f)) + (2.5f * xidx)
						+ (SKILLICON_SIZE / 2), (yidx * (SKILLICON_SIZE + 2.5f)) + (1.5f * yidx) + (SKILLICON_SIZE / 2));
					Vector3 itemFinalPos = Vector3(1.5f + itemSetPos.x + quickslotleftTop.x, -1.5f + quickslotleftTop.y - itemSetPos.y, 3.5f);
					tr->SetPosition(itemFinalPos);
					isMovePossible = false;
					isPicked = false;
					isOnTarget = false;
					AddSkillResource();
				}
			}
		}

		if (isPicked)
		{
			isRender = true;
			isMovePossible = true;
		}

		if (isMovePossible == true && isItIcon == false)
		{
			MouseBTNClick();
		}
	
		
		UIBase::Update();
	}
	void SkillResources::LateUpdate()
	{
		if (isRender == false)
		{
			Vector3 skillUIPos = skillBGUI->GetComponent<Transform>()->GetPosition();
			switch (mSkillType)
			{
			case eSkillType::Assain:
				skillUIPos.x -= 130.0f;
				skillUIPos.y += 70.0f;
				tr->SetPosition(skillUIPos);
				break;
			case eSkillType::MesoExplosionRed:
				skillUIPos.x += 15.0f;
				skillUIPos.y += 70.0f;
				tr->SetPosition(skillUIPos);
				break;
			}
		}
		UIBase::LateUpdate();
	}
	void SkillResources::Render()
	{
		if(isRender == true)
		UIBase::Render();
	}
	void SkillResources::MouseBTNClick()
	{
		tr->SetPosition(Input::GetUIMousePos());
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
	void SkillResources::SetExplosionRedSkill()
	{
		at->CreateAnimations(L"..\\Resources\\UI\\SkillUI\\MesoExplosionRed\\_able", 100, 0.1f);
		at->CreateAnimations(L"..\\Resources\\UI\\SkillUI\\MesoExplosionRed\\_disable", 100, 0.1f);

		GetComponent<Transform>()->SetScale(Vector3(100.0f, 100.0f, 1.0f));
	}
	void SkillResources::AddSkillResource()
	{
		switch (mSkillType)
		{
		case jns::SkillResources::eSkillType::Assain:
			//SkillManager::FindSkillData(L"Normal_Assain_First_Attack")->SetSkillKeyState()
			//SkillManager::FindSkillData(L"Normal_Assain_Second_Attack");
			break;
		case jns::SkillResources::eSkillType::MesoExplosionRed:
			break;
		case jns::SkillResources::eSkillType::End:
			break;
		default:
			break;
		}
	}
}