#include "jnsPierreHatScript.h"
#include "CommonSceneInclude.h"


namespace jns
{
	void PierreHatScript::Initialize()
	{
		
		//at = AddComponent<Animator>();
		//at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\Cap\\CapAffected", 500, 0.1f);
		//at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\Cap\\CapAffectedAfter", 500, 0.1f);
		//at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\Cap\\CapEffectStart", 500, 0.1f);
		//at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\Cap\\CapEffectWarning1", 500, 0.1f, Vector2(0.020f, 0.45f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\Cap\\CapEffectWarning2", 500, 0.1f, Vector2(0.020f, 0.45f));
		//at->CreateAnimations(L"..\\Resources\\Boss\\Pierre\\Cap\\CapEffectWarning3", 500, 0.1f, Vector2(0.020f, 0.45f));
		at = GetOwner()->GetComponent<Animator>();
		tr = GetOwner()->GetComponent<Transform>();
		cd = GetOwner()->GetComponent<Collider2D>();
		cd->SetSize(Vector2(0.3f, 0.3f));
		//at->CompleteEvent(L"CapCapEffectStart") = std::bind(&PierreHatScript::CompleteCapStartEnd, this);
		at->CompleteEvent(L"CapCapAffected") = std::bind(&PierreHatScript::CompleteCapAffected, this);
		at->CompleteEvent(L"CapCapAffectedAfter") = std::bind(&PierreHatScript::CompleteCapAffectedAfter, this);
		at->CompleteEvent(L"CapCapEffectWarning1") = std::bind(&PierreHatScript::CompleteWarning1, this);
		at->CompleteEvent(L"CapCapEffectWarning2") = std::bind(&PierreHatScript::CompleteWarning2, this);
		at->CompleteEvent(L"CapCapEffectWarning3") = std::bind(&PierreHatScript::CompleteWarning3, this);

	}
	void PierreHatScript::Update()
	{
		Vector3 pos = tr->GetPosition();
		if (at->GetActiveAnimation()->GetAnimationName() == L"CapCapEffectStart")
		{
			cd->SetSize(Vector2(0.3f, 0.3f));
			cd->SetColliderOn(true);
			
			pos.y -= 500.0f * Time::DeltaTime();
			
			
			if (pos.y <= -430.0f)
			{
				if (isHit)
				{
					hitTime += Time::DeltaTime();

					if (hitTime >= hitMaxTime)
					{
						ResetData();
					}
				}
				else
				{
					at->PlayAnimation(L"CapCapAffected", true);
				}
			}
			else
			{
				tr->SetPosition(pos);
			}

		}
		else
		{
			cd->SetSize(Vector2::Zero);
			cd->SetColliderOn(false);
		}
	}
	void PierreHatScript::OnCollisionEnter(Collider2D* other)
	{
		if (other->GetOwner()->GetLayerType() == eLayerType::Player && isHit == false)
		{
			if (SceneManager::GetPlayer()->GetComponent<PlayerScript>()->GetPlayerState() == jns::PlayerScript::ePlayerState::Die)
				return;

			SceneManager::GetPlayer()->GetComponent<PlayerScript>()->SetPlayerState(jns::PlayerScript::ePlayerState::DontMove);
			isHit = true;
		}
	}
	void PierreHatScript::OnCollisionStay(Collider2D* other)
	{
	}
	void PierreHatScript::OnCollisionExit(Collider2D* other)
	{
	}
	void PierreHatScript::CompleteCapStartEnd()
	{
		at->PlayAnimation(L"CapCapAffected", true);
	}
	void PierreHatScript::CompleteCapAffected()
	{
		at->PlayAnimation(L"CapCapAffectedAfter", true);
	}
	void PierreHatScript::CompleteCapAffectedAfter()
	{
		ResetData();
	}
	void PierreHatScript::CompleteWarning1()
	{
		at->PlayAnimation(L"CapCapEffectWarning2", true);
	}
	void PierreHatScript::CompleteWarning2()
	{
		Vector3 pos = tr->GetPosition();
		pos.y += 500.0f;
		tr->SetPosition(pos);
		at->PlayAnimation(L"CapCapEffectWarning3", true);
	}
	void PierreHatScript::CompleteWarning3()
	{
		at->PlayAnimation(L"CapCapEffectStart", false);
	}
	void PierreHatScript::ResetData()
	{
		isHit = false;
		hitTime = 0.0f;
		Vector3 pos = tr->GetPosition();
		pos.y = -430.0f;
		tr->SetPosition(pos);
		GetOwner()->SetState(GameObject::eState::Paused);
	}
	void PierreHatScript::Activate()
	{
		GetOwner()->SetState(GameObject::eState::Active);
		at->PlayAnimation(L"CapCapEffectWarning1", true);
	}
}