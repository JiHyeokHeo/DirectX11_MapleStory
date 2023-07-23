#include "jnsPlayerScript.h"
#include "jnsTransform.h"
#include "jnsGameObject.h"
#include "jnsInput.h"
#include "jnsTime.h"
#include "jnsConstantBuffer.h"
#include "jnsRenderer.h"
#include "CommonSceneInclude.h"

namespace jns
{
	void PlayerScript::Initialize()
	{
		mPlayerState = ePlayerState::Idle;
		Animator* at = GetOwner()->GetComponent<Animator>();
		//at->CompleteEvent(L"CharactorCharWalk") = std::bind(&PlayerScript::Complete, this);
		at->CompleteEvent(L"CharactorCharAssain1Hit") = std::bind(&PlayerScript::Complete, this);
	}
	void PlayerScript::Update()
	{
		switch (mPlayerState)
		{
		case ePlayerState::Idle:
			Idle();
			break;
		case ePlayerState::Move:
			Move();
			break;
		case ePlayerState::Attack:
			Attack();
			break;
		case ePlayerState::Attacked:
			Attacked();
			break;
		case ePlayerState::Die:
			Die();
			break;
		default:
			break;

		}
		mPrevPlayerState = mPlayerState;
	}
	void PlayerScript::LateUpdate()
	{
		bindConstantBuffer();
	}
	
	void PlayerScript::OnCollisionEnter(Collider2D* other)
	{
	}
	void PlayerScript::OnCollisionStay(Collider2D* other)
	{
	}
	void PlayerScript::OnCollisionExit(Collider2D* other)
	{
	}
	void PlayerScript::bindConstantBuffer()
	{
		renderer::PlayerCB playerUICB = {};
		int mHp = 40;
		int mMp = 100;
		int mExp = 100;
		
		playerUICB.hp = mHp;
		playerUICB.mp = mMp;
		playerUICB.exp = mExp;
		playerUICB.type = 0.0f;
		ConstantBuffer* cb = renderer::constantBuffer[(UINT)eCBType::Player];
		
		cb->SetData(&playerUICB);
		cb->Bind(eShaderStage::PS);


		// 좌우 판정 + 애니메이터 작동 편하게 !

		renderer::ObjectTypeMoveCB MoveCB = {};
		MoveCB.mtype = isRight;
		MoveCB.mTime = Vector3::Zero;

		ConstantBuffer* cb2 = renderer::constantBuffer[(UINT)eCBType::Move];

		cb2->SetData(&MoveCB);
		cb2->Bind(eShaderStage::PS);
	}

	void PlayerScript::Idle()
	{	
		if (Input::GetKeyDown(eKeyCode::UP))
		{
			mPlayerState = ePlayerState::Move;
		}
		else if (Input::GetKeyDown(eKeyCode::DOWN))
		{
			mPlayerState = ePlayerState::Move; 
		}
		else if (Input::GetKeyDown(eKeyCode::LEFT))
		{
			mPlayerState = ePlayerState::Move;
		}
		else if (Input::GetKeyDown(eKeyCode::RIGHT))
		{
			mPlayerState = ePlayerState::Move;
		}
		else if (Input::GetKeyDown(eKeyCode::LCTRL))
		{
			mPlayerState = ePlayerState::Attack;
		}
		else if (Input::GetKeyDown(eKeyCode::Y))
		{
			mPlayerState = ePlayerState::Die;
		}
		else if (Input::GetKeyDown(eKeyCode::U))
		{
			mPlayerState = ePlayerState::Attacked;
		}
		AnimatorControl();
	}

	void PlayerScript::Move()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();
		if (Input::GetKey(eKeyCode::UP))
		{
			pos.y += 255.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::DOWN))
		{
			pos.y -= 255.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::LEFT))
		{
			pos.x -= 255.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::RIGHT))
		{
			pos.x += 255.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::Q))
		{
			pos.z -= 255.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::E))
		{
			pos.z += 255.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}

		AnimatorControl();
	}

	void PlayerScript::Attack()
	{
	}

	void PlayerScript::Attacked()
	{
	}

	void PlayerScript::Die()
	{
	}

	void PlayerScript::AnimatorControl()
	{
		//Animator* at = AddComponent<Animator>();
		//at->CreateAnimations(L"..\\Resources\\Charactor\\CharWalk", 0.1f);
		//at->CreateAnimations(L"..\\Resources\\Charactor\\CharAssain1Hit", 0.1f);
		//at->CreateAnimations(L"..\\Resources\\Charactor\\CharAssain2Hit", 0.1f);
		//at->CreateAnimations(L"..\\Resources\\Charactor\\CharBuff", 0.1f);
		//at->CreateAnimations(L"..\\Resources\\Charactor\\CharDead", 0.1f);
		//at->CreateAnimations(L"..\\Resources\\Charactor\\CharHit", 0.1f);
		//at->CreateAnimations(L"..\\Resources\\Charactor\\CharIdle", 0.3f);
		//at->CreateAnimations(L"..\\Resources\\Charactor\\CharJump", 0.1f);
		//at->CreateAnimations(L"..\\Resources\\Charactor\\CharLadder", 0.1f);
		//at->CreateAnimations(L"..\\Resources\\Charactor\\CharProne", 0.1f);
		//at->CreateAnimations(L"..\\Resources\\Charactor\\CharProneStab", 0.2f);
		//at->CreateAnimations(L"..\\Resources\\Charactor\\CharRope", 0.2f);
		//at->CreateAnimations(L"..\\Resources\\Charactor\\CharStab", 0.2f);
		//at->CreateAnimations(L"..\\Resources\\Charactor\\CharSummon", 0.1f);
		//at->PlayAnimation(L"CharactorCharIdle", true);
		Animator* at = GetOwner()->GetComponent<Animator>();
		switch (mPlayerState)
		{
		case ePlayerState::Idle:
			if (mPrevPlayerState != mPlayerState)
			at->PlayAnimation(L"CharactorCharIdle", true);
			break;
		case ePlayerState::Move:
			if (mPrevPlayerState != mPlayerState)
			at->PlayAnimation(L"CharactorCharWalk", true);
			break;
		case ePlayerState::Attack:
			if (mPrevPlayerState != mPlayerState)
			at->PlayAnimation(L"CharactorCharAssain1Hit", true);
			break;
		case ePlayerState::Attacked:
			if (mPrevPlayerState != mPlayerState)
			at->PlayAnimation(L"CharactorCharHit", true);
			break;
		case ePlayerState::Die:
			if (mPrevPlayerState != mPlayerState)
			at->PlayAnimation(L"CharactorCharDead", true);
			break;
		default:
			break;
		}
	}

	void PlayerScript::Complete()
	{
		Animator* at = GetOwner()->GetComponent<Animator>();
		//at->PlayAnimation(L"CharactorCharAssain2Hit", false);
	}
}