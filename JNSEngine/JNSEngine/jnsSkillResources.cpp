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
		//Light* light = AddComponent<Light>();
		//light->SetType(eLightType::Spot);
		
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));
		at = AddComponent<Animator>();


		switch (mSkillType)
		{
		case eSkillType::Assain:
			SetAssainSkill();
			skillLearnNum = 4;
			break;
		case eSkillType::MesoExplosionRed:
			SetExplosionRedSkill();
			skillLearnNum = 4;
			break;
		case eSkillType::JumpSkill:
			SetJumpSkill();
			skillLearnNum = 1;
			break;
		}

		GetComponent<Transform>()->SetScale(Vector3(100.0f, 100.0f, 1.0f));

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
		case eSkillType::JumpSkill:
			skillUIPos.x -= 130.0f;
			skillUIPos.y += 70.0f;	
			tr->SetPosition(skillUIPos);
			at->PlayAnimation(L"TripleJump_able", true);
			break;
		}

		
		isRender = false;
		
	}
	void SkillResources::Update()
	{
		Vector3 mPos = tr->GetPosition();
		Vector3 mMousePos = Input::GetUIMousePos();
		if (skillBGUI->GetIsDrag() == true && isInitDrag == false)
		{
			isInitDrag = true;
			initialMousePos = Input::GetUIMousePos();
			initialObjectPos = tr->GetPosition();
		}

		if (skillBGUI->GetIsDrag() == true && isSet == false)
		{
			int xOffset = mMousePos.x - initialMousePos.x;
			int yOffset = mMousePos.y - initialMousePos.y;

			mPos.x = initialObjectPos.x + xOffset;
			mPos.y = initialObjectPos.y + yOffset;
			tr->SetPosition(mPos);
		}
		else
		{
			isInitDrag = false;
		}

		if (SceneManager::GetActiveScene() != SceneManager::GetPrevScene())
		{
			playeScene = SceneManager::GetActiveScene();
			
			float opacity = LightScript::GetOpacity();
			float one = 1.0f;
			one -= opacity;
			one *= 0.8f;
			
			at->GetActiveAnimation()->SetTransparency(-one);
			std::wstring aniname = at->GetActiveAnimation()->GetAnimationName();
			at->PlayAnimation(aniname, false);
		}

		if (Input::GetKeyDown(eKeyCode::K))
		{
			if (isItIcon == true)
			{
				if (isRender == false)
				{
					isRender = true;
					isIconRender = true;
				}
				else
				{
					isRender = false;
					isIconRender = false;
				}
			}
		}

		if (isRender == true)
		{
			if (SkillUIBTN::GetPushedSkillBTNNumber() != skillLearnNum && isItIcon == true)
			{
				isIconRender = false;
			}
			else if(SkillUIBTN::GetPushedSkillBTNNumber() == skillLearnNum && isItIcon == true)
			{
				isIconRender = true;
			}
		}

		Vector3 mSkillResourcesPos = tr->GetPosition();
		Vector2 mLeftTop = Vector2(mSkillResourcesPos.x - SKILLICON_SIZE, mSkillResourcesPos.y + SKILLICON_SIZE);
		Vector2 mRightBottom = Vector2(mSkillResourcesPos.x + SKILLICON_SIZE, mSkillResourcesPos.y - SKILLICON_SIZE);
		Vector3 mousePos = Input::GetUIMousePos();

		if (mousePos.x >= mLeftTop.x && mousePos.x <= mRightBottom.x 
			&& mousePos.y <= mLeftTop.y && mousePos.y >= mRightBottom.y
			)
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
			else
			{
				isOnTarget = false;
			}

			if (SkillUIBTN::GetPushedSkillBTNNumber() == skillLearnNum)
			{

				if (Input::GetKeyDown(eKeyCode::LBUTTON) && isPicked == false && isItIcon == false)
				{
					isMovePossible = true;
					isPicked = true;
				}
				else if (Input::GetKeyDown(eKeyCode::LBUTTON) && isItIcon == false && isPicked == true)
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
						isSet = true;
						AddSkillResource(xidx, yidx);
					}
					else
					{
						isSet = false;
						isRender = false;
						isPicked = false;
						DeleteSkillResource();
					}
				}
			}
			else
			{
				if (isOnTarget)
				{
					if (Input::GetKeyDown(eKeyCode::LBUTTON) && isPicked == false && isItIcon == false)
					{
						isMovePossible = true;
						isPicked = true;
					}
					else if (Input::GetKeyDown(eKeyCode::LBUTTON) && isItIcon == false && isPicked == true)
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
							isSet = true;
							AddSkillResource(xidx, yidx);
						}
					}
				}
				else
				{
					if (Input::GetKeyDown(eKeyCode::LBUTTON) && isItIcon == false && isPicked == true)
					{
						isRender = false;
						isPicked = false;
						isSet = false;
						DeleteSkillResource();
					}
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
		// 스킬 리소스 위치해놓기
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
			case eSkillType::JumpSkill:
				skillUIPos.x -= 130.0f;
				skillUIPos.y += 70.0f;
				tr->SetPosition(skillUIPos);
				break;
			}
		}
		UIBase::LateUpdate();
	}
	void SkillResources::Render()
	{
		if((isRender == true && isItIcon == false) || (isIconRender == true && isItIcon == true))
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
	}
	void SkillResources::SetExplosionRedSkill()
	{
		at->CreateAnimations(L"..\\Resources\\UI\\SkillUI\\MesoExplosionRed\\_able", 100, 0.1f);
		at->CreateAnimations(L"..\\Resources\\UI\\SkillUI\\MesoExplosionRed\\_disable", 100, 0.1f);
	}
	void SkillResources::SetJumpSkill()
	{
		at->CreateAnimations(L"..\\Resources\\UI\\SkillUI\\\TripleJump\\_able", 100, 0.1f);
		at->CreateAnimations(L"..\\Resources\\UI\\SkillUI\\\TripleJump\\_disable", 100, 0.1f);
	}
	void SkillResources::AddSkillResource(int xidx, int yidx)
	{
		eKeyCode setKeyCode = {};
		if (xidx < 0 || yidx < 0)
		{
			setKeyCode = eKeyCode::NONE;
		}
		else
		{
			setKeyCode = skillQuickSlot->GetIndexKeyCode(yidx, xidx);
			skillQuickSlot->SetIndexOn(yidx, xidx, true);
		}

		switch (mSkillType)
		{
		case jns::SkillResources::eSkillType::Assain:
			SkillManager::FindSkillData(L"Normal_Assain_First_Attack")->SetSkillKeyState(setKeyCode);
			SkillManager::FindSkillData(L"Normal_Assain_Second_Attack")->SetSkillKeyState(setKeyCode);
			break;
		case jns::SkillResources::eSkillType::MesoExplosionRed:
			SkillManager::FindSkillData(L"BloodyMeso")->SetSkillKeyState(setKeyCode);
			break;
		case jns::SkillResources::eSkillType::JumpSkill:
			SkillManager::FindSkillData(L"Rogue_SkillflashJump_01")->SetSkillKeyState(setKeyCode);
			SkillManager::FindSkillData(L"Rogue_SkillflashJump_02")->SetSkillKeyState(setKeyCode);
			SkillManager::FindSkillData(L"Rogue_SkillflashJump_01")->SetSkillLearn(true);
			break;
		case jns::SkillResources::eSkillType::End:
			break;
		default:
			break;
		}
	}
	void SkillResources::DeleteSkillResource()
	{
		eKeyCode setKeyCode = {};
		setKeyCode = eKeyCode::NONE;

		switch (mSkillType)
		{
		case jns::SkillResources::eSkillType::Assain:
			SkillManager::FindSkillData(L"Normal_Assain_First_Attack")->SetSkillKeyState(setKeyCode);
			SkillManager::FindSkillData(L"Normal_Assain_Second_Attack")->SetSkillKeyState(setKeyCode);
			break;
		case jns::SkillResources::eSkillType::MesoExplosionRed:
			SkillManager::FindSkillData(L"BloodyMeso")->SetSkillKeyState(setKeyCode);
			break;
		case jns::SkillResources::eSkillType::JumpSkill:
			SkillManager::FindSkillData(L"Rogue_SkillflashJump_01")->SetSkillKeyState(setKeyCode);
			SkillManager::FindSkillData(L"Rogue_SkillflashJump_02")->SetSkillKeyState(setKeyCode);
			SkillManager::FindSkillData(L"Rogue_SkillflashJump_01")->SetSkillLearn(false);
			break;
		case jns::SkillResources::eSkillType::End:
			break;
		default:
			break;
		}
	}
}