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
		isAnimationDone = true;
		mPreveScene = nullptr;
		mPlayerInfo = {};
		mPlayerInfo.mMoveSpeed = 255.0f;
		mPlayerInfo.mJumpCnt = 0;
		mPlayerInfo.LeftRight = -1;
		mPlayerState = ePlayerState::Idle;
		at = GetOwner()->GetComponent<Animator>();
		mRb = GetOwner()->GetComponent<RigidBody>();
		//at->CompleteEvent(L"CharactorCharWalk") = std::bind(&PlayerScript::Complete, this);
		at->CompleteEvent(L"CharactorCharAssain1Hit") = std::bind(&PlayerScript::CompleteAssasinHit1, this);
		at->CompleteEvent(L"CharactorCharAssain2Hit") = std::bind(&PlayerScript::CompleteAnimation, this);
		at->CompleteEvent(L"CharactorCharProneStab") = std::bind(&PlayerScript::CompletePronStab, this);
	}
	void PlayerScript::Update()
	{
		mActveScene = SceneManager::GetActiveScene();
		if (mPreveScene != mActveScene)
		{
			mPreveScene = mActveScene;
			Clear();
		}

		CheckPlayerIsGrounded();
		
		switch (mPlayerState)
		{
		case ePlayerState::Idle:
			Idle();
			break;
		case ePlayerState::Move:
			Move();
			break;
		case ePlayerState::Jump:
			Jump();
;		case ePlayerState::Prone:
			Prone();
			break;
		case ePlayerState::Attack:
			Attack();
			break;
		case ePlayerState::Hitted:
			Hitted();
			break;
		case ePlayerState::Die:
			Die();
			break;
		default:
			break;
		}
		AnimatorControl();
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
		if (other->GetName() == L"Item" && Input::GetKeyDown(eKeyCode::Z))
		{
			ItemResources* item = dynamic_cast<ItemResources*>(other->GetOwner());
		}
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
		MoveCB.mtype = mPlayerInfo.isRight;
		MoveCB.mTime = Vector3::Zero;

		ConstantBuffer* cb2 = renderer::constantBuffer[(UINT)eCBType::Move];

		cb2->SetData(&MoveCB);
		cb2->Bind(eShaderStage::PS);
	}

    void PlayerScript::Idle()
    {
        if (Input::GetKeyDown(eKeyCode::C))
        {
            Vector3 velocity = mRb->GetVelocity();
            velocity.y -= 400.0f;

            mRb->SetVelocity(velocity);
            mRb->SetGround(false);
            mPlayerState = ePlayerState::Jump;
            mPlayerInfo.mJumpCnt++;
        }
        else if (Input::GetKey(eKeyCode::DOWN))
        {
            mPlayerState = ePlayerState::Prone;
        }
        else if (Input::GetKey(eKeyCode::LEFT))
        {
            mPlayerInfo.LeftRight = -1;
            mPlayerState = ePlayerState::Move;
        }
        else if (Input::GetKey(eKeyCode::RIGHT))
        {
            mPlayerInfo.LeftRight = 1;
            mPlayerState = ePlayerState::Move;
        }
        else if (Input::GetKey(eKeyCode::LCTRL))
        {
            mPlayerState = ePlayerState::Attack;
        }
        else if (Input::GetKey(eKeyCode::Y))
        {
            mPlayerState = ePlayerState::Die;
        }
        else if (Input::GetKey(eKeyCode::U))
        {
            mPlayerState = ePlayerState::Hitted;
        }
    }

    void PlayerScript::Move()
    {
        if (Input::GetKeyUp(eKeyCode::LEFT) || Input::GetKeyUp(eKeyCode::RIGHT) || Input::GetKeyUp(eKeyCode::UP)
            || Input::GetKeyUp(eKeyCode::DOWN) || Input::GetKeyUp(eKeyCode::C))
        {
            mPlayerState = ePlayerState::Idle;
        }

        Transform* tr = GetOwner()->GetComponent<Transform>();
        Vector3 pos = tr->GetPosition();
        if (Input::GetKeyDown(eKeyCode::C))
        {
            Vector3 velocity = mRb->GetVelocity();
            velocity.x += 600.0f * -mPlayerInfo.LeftRight;
            velocity.y -= 400.0f;

            mRb->SetVelocity(velocity);
            mRb->SetGround(false);
            mPlayerState = ePlayerState::Jump;
            mPlayerInfo.mJumpCnt++;
        }
        if (Input::GetKey(eKeyCode::DOWN))
        {
            //pos.y -= 255.0f * Time::DeltaTime();
            //tr->SetPosition(pos);
        }
        if (Input::GetKey(eKeyCode::LEFT))
        {
            pos.x -= mPlayerInfo.mMoveSpeed * Time::DeltaTime();
            tr->SetPosition(pos);
        }
        if (Input::GetKey(eKeyCode::RIGHT))
        {
            pos.x += mPlayerInfo.mMoveSpeed * Time::DeltaTime();
            tr->SetPosition(pos);
        }
        if (Input::GetKey(eKeyCode::Q))
        {
            pos.z -= mPlayerInfo.mMoveSpeed * Time::DeltaTime();
            tr->SetPosition(pos);
        }
        if (Input::GetKeyDown(eKeyCode::E))
        {
            pos.z += mPlayerInfo.mMoveSpeed * Time::DeltaTime();
            tr->SetPosition(pos);
        }
        if (Input::GetKeyDown(eKeyCode::LCTRL))
        {
            mPlayerState = ePlayerState::Attack;
        }
    }

    void PlayerScript::Jump()
    {
        Transform* tr = GetOwner()->GetComponent<Transform>();
        Vector3 pos = {};
        if (Input::GetKey(eKeyCode::LEFT))
        {
            mPlayerInfo.LeftRight = -1;
        }

        if (Input::GetKey(eKeyCode::RIGHT))
        {
            mPlayerInfo.LeftRight = 1;
        }

        if (Input::GetKeyDown(eKeyCode::C) && mPlayerInfo.mJumpCnt <= 2)
        {
            Vector3 velocity = mRb->GetVelocity();
            velocity.x += 600.0f * -mPlayerInfo.LeftRight;
            velocity.y -= 70.0f;

            mRb->SetVelocity(velocity);
            mRb->SetGround(false);
            mPlayerInfo.mJumpCnt++;
        }

        if (Input::GetKeyDown(eKeyCode::C) && mPlayerInfo.mJumpCnt <= 3 && mPlayerInfo.mJumpCnt > 2)
        {
            Vector3 velocity = mRb->GetVelocity();
            velocity.x += 600.0f * -mPlayerInfo.LeftRight;
            velocity.y -= 70.0f;

            mRb->SetVelocity(velocity);
            mRb->SetGround(false);
            mPlayerInfo.mJumpCnt++;
        }

        if (Input::GetKeyDown(eKeyCode::LCTRL))
        {
            mPlayerState = ePlayerState::Attack;
        }

        if (mPlayerInfo.isGrounded == true)
        {
            mPlayerInfo.mJumpCnt = 0;
            mPlayerState = ePlayerState::Idle;
        }

    }

    void PlayerScript::Prone()
    {
        if (Input::GetKeyUp(eKeyCode::DOWN))
        {
            mPlayerState = ePlayerState::Idle;
        }
    }

    void PlayerScript::Attack()
    {

    }

    void PlayerScript::Hitted()
    {
        mPlayerInfo.mHittedTime += Time::DeltaTime();


        if (mPlayerInfo.mHittedTime >= 1.0f)
        {
            mPlayerState = ePlayerState::Idle;
            mPlayerInfo.mHittedTime = 0.0f;
        }
    }

    void PlayerScript::Die()
    {
        mPlayerInfo.mDeathTime += Time::DeltaTime();



        if (mPlayerInfo.mDeathTime >= 3.0f)
        {
            mPlayerState = ePlayerState::Idle;
            mPlayerInfo.mDeathTime = 0.0f;
        }
    }

    void PlayerScript::AnimatorControl()
    {
        if (mPlayerInfo.LeftRight == 1)
        {
            mPlayerInfo.isRight = true;
        }
        else
        {
            mPlayerInfo.isRight = false;
        }
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

        if (mPlayerState != mPrevPlayerState)
        {
            isAnimationDone = true;
            switch (mPlayerState)
            {
            case ePlayerState::Idle:
                at->PlayAnimation(L"CharactorCharIdle", true);
                break;
            case ePlayerState::Move:
                at->PlayAnimation(L"CharactorCharWalk", true);
                break;
            case ePlayerState::Jump:
                at->PlayAnimation(L"CharactorCharJump", true);
                break;
            case ePlayerState::Prone:
                at->PlayAnimation(L"CharactorCharProne", true);
                break;
            case ePlayerState::Attack:
                at->PlayAnimation(L"CharactorCharAssain1Hit", true);
                break;
            case ePlayerState::Hitted:
                at->PlayAnimation(L"CharactorCharHit", true);
                break;
            case ePlayerState::Die:
                at->PlayAnimation(L"CharactorCharDead", true);
                break;
            default:
                break;
            }
        }

        if (mPlayerState == ePlayerState::Prone && Input::GetKeyDown(eKeyCode::LCTRL) && isAnimationDone == true)
        {
            at->PlayAnimation(L"CharactorCharProneStab", true);
            isAnimationDone = false;
        }

    }

    void PlayerScript::Clear()
    {
        mRb->SetGround(false);
        mPlayerInfo.isGrounded = false;
        mPlayerInfo.mJumpTime = 0.0f;
    }

    void PlayerScript::CheckPlayerIsGrounded()
    {
        mPlayerInfo.isGrounded = mRb->GetGround();

        if (mPlayerInfo.isGrounded == false)
        {
            mPlayerInfo.mJumpTime += Time::DeltaTime();
        }
        else if (mPlayerState == ePlayerState::Idle)
        {
            mPlayerInfo.mJumpTime = 0.0f;
        }
    }

    void PlayerScript::CompleteAssasinHit1()
    {
        mPlayerState = ePlayerState::Idle;
        //at->PlayAnimation(L"CharactorCharAssain2Hit", true);
    }
    void PlayerScript::CompleteAnimation()
    {
        mPlayerState = ePlayerState::Idle;
        at->PlayAnimation(L"CharactorCharIdle", true);
    }
    void PlayerScript::CompletePronStab()
    {
        isAnimationDone = true;
    }
}
