#include "jnsAssainHit01.h"
#include "CommonSceneInclude.h"

namespace jns
{
	AssainHit01::AssainHit01()
		: SkillBase(eSkillType::AssainHit01)
	{	
		
		SetState(GameObject::eState::DontDestroy);
		SetIsOnlyOne(true);
	}
	AssainHit01::~AssainHit01()
	{
	}
	void AssainHit01::Initialize()
	{
		as = AddComponent<AudioSource>();
		clip[0] = Resources::Find<AudioClip>(L"Assain01Use");
		clip[1] = Resources::Find<AudioClip>(L"Assain02Hit");
		
		isRenderOn = false;
		cd = AddComponent<Collider2D>();
		SetName(L"Normal_Assain_First_Attack");
		SetMesh(L"RectMesh");
		SetMaterial(L"SpriteAnimaionMaterial");
		at->CreateAnimations(L"..\\Resources\\Rogue_Skill\\Assaination\\Normal_Assasination_First_Attack",  500, 0.05f);
		at->CompleteEvent(L"AssainationNormal_Assasination_First_Attack") = std::bind(&AssainHit01::CompleteSkillAnimation, this);
		at->StartEvent(L"AssainationNormal_Assasination_First_Attack") = std::bind(&AssainHit01::StartSkillAnimation, this);
		at->PlayAnimation(L"AssainationNormal_Assasination_First_Attack" , true);
		tr->SetScale(Vector3(500.0f, 500.0f, 1.0f));
		
		cd->SetSize(Vector2(0.5f, 0.3f));
		SkillBase::Initialize();
	}
	void AssainHit01::Update()
	{
		// 플레이어 위치정보 가져오기
		Vector3 mPos = mPlayerScript->GetOwner()->GetComponent<Transform>()->GetPosition();
		
		int direction = (int)mPlayerScript->GetPlayerDirection();
		mPos.x += direction * 130.0f;
		mPos.z = 0.0f;
		SetPosition(mPos);

		if (isRenderOn == false)
		{
			cd->SetSize(Vector2::Zero);
			cd->SetColliderOn(false);
		}
		else
		{
			cd->SetSize(Vector2(0.5f, 0.3f));
			cd->SetColliderOn(true);
		}

		SkillBase::Update();
	}
	void AssainHit01::LateUpdate()
	{
		SkillBase::SetDirection();
		SkillBase::LateUpdate();

		if (isPlayPossible == true)
		{
			isPlayPossible = false;
			at->PlayAnimation(L"AssainationNormal_Assasination_First_Attack", true);
		}
	}
	void AssainHit01::Render()
	{
		SkillBase::Render();
	}
	void AssainHit01::CompleteSkillAnimation()
	{
		isRenderOn = false;
	}
	void AssainHit01::StartSkillAnimation()
	{
	}
	void AssainHit01::Activate()
	{
		as->SetClip(clip[0]);
		as->Play();
		as->SetLoop(false);
		as->SetVolume(0.1f);
	}
}