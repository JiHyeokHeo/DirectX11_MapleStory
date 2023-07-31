#include "jnsPlayerScript.h"
#include "jnsTransform.h"
#include "jnsGameObject.h"
#include "jnsInput.h"
#include "jnsTime.h"
#include "jnsConstantBuffer.h"
#include "jnsRenderer.h"
#include "CommonSceneInclude.h"


#define KEY_SLOT(name) (eKeyCode)name

namespace jns
{
	void PlayerScript::Initialize()
	{
        
		isAnimationDone = true;
		mPreveScene = nullptr;
		mPlayerInfo = {};
		mPlayerInfo.mMoveSpeed = 255.0f;
		mPlayerInfo.mJumpCnt = 0;
		mPlayerInfo.mDir = PlayerDir::Left;
        mPlayerState = ePlayerState::Idle;
        
        at = GetOwner()->GetComponent<Animator>();
		mRb = GetOwner()->GetComponent<RigidBody>();
        cd = GetOwner()->GetComponent<Collider2D>();
        tr = GetOwner()->GetComponent<Transform>();
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
        PlayerControl();
		AnimatorControl();
        
        mPrevPlayerState = mPlayerState;
        mPlayerInfo.mPrevDir = mPlayerInfo.mDir;
	}
	void PlayerScript::LateUpdate()
	{
		//BindConstantBuffer();
        at->GetActiveAnimation()->SetAniDirection(mPlayerInfo.isRight);
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

	void PlayerScript::BindConstantBuffer()
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
	}

    void PlayerScript::Idle()
    {
        if (Input::GetKeyDown(KEY_SLOT(eKeyType::Jump)))
        {
            wasStand = true;
            Vector3 velocity = mRb->GetVelocity();
            velocity.y -= 450.0f;
            mRb->SetVelocity(velocity);
            mRb->SetGround(false);
            mPlayerState = ePlayerState::Jump;
            //mPlayerInfo.mJumpCnt++;
        }
        else if (Input::GetKey(KEY_SLOT(eKeyType::Prone)))
        {
            mPlayerState = ePlayerState::Prone;
        }
        else if (Input::GetKey(KEY_SLOT(eKeyType::MoveL)))
        {
            mPlayerInfo.mDir = PlayerDir::Left;
            mPlayerState = ePlayerState::Move;
        }
        else if (Input::GetKey(KEY_SLOT(eKeyType::MoveR)))
        {
            mPlayerInfo.mDir = PlayerDir::Right;
            mPlayerState = ePlayerState::Move;
        }
        else if (Input::GetKey(KEY_SLOT(eKeyType::Attack)))
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
        if (Input::GetKeyUp(KEY_SLOT(eKeyType::MoveL)) || Input::GetKeyUp(KEY_SLOT(eKeyType::MoveR))
            || Input::GetKeyUp(KEY_SLOT(eKeyType::Prone)) || Input::GetKeyUp(KEY_SLOT(eKeyType::Jump)))
        {
            mPlayerState = ePlayerState::Idle;
        }

        Vector3 pos = tr->GetPosition();
        if (Input::GetKeyDown(KEY_SLOT(eKeyType::Jump)))
        {
            Vector3 velocity = mRb->GetVelocity();
            velocity.x += 600.0f * -(int)mPlayerInfo.mDir;
            velocity.y -= 450.0f;

            mRb->SetVelocity(velocity);
            mRb->SetGround(false);
            mPlayerState = ePlayerState::Jump;
            mPlayerInfo.mJumpCnt++;
        }
        if (Input::GetKey(KEY_SLOT(eKeyType::Prone)))
        {
            //pos.y -= 255.0f * Time::DeltaTime();
            //tr->SetPosition(pos);
        }
        if (Input::GetKey(KEY_SLOT(eKeyType::MoveL)))
        {
            pos.x -= mPlayerInfo.mMoveSpeed * Time::DeltaTime();
            tr->SetPosition(pos);
        }
        if (Input::GetKey(KEY_SLOT(eKeyType::MoveR)))
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
        if (Input::GetKeyDown(KEY_SLOT(eKeyType::Attack)))
        {
            object::InstantiateSkill<AssainHit01>(pos, Vector3(100.0f, 100.0f, 1.0f));
            mPlayerState = ePlayerState::Attack;
        }
    }

    void PlayerScript::Jump()
    {
        Vector3 pos = tr->GetPosition();
        if (Input::GetKey(eKeyCode::LEFT))
        {
            mPlayerInfo.mDir = PlayerDir::Left;
        }

        if (Input::GetKey(eKeyCode::RIGHT))
        {
            mPlayerInfo.mDir = PlayerDir::Right;
        }

        if (mPlayerInfo.mPrevDir != mPlayerInfo.mDir && mPlayerInfo.isGrounded == false)
        {
            if (mPlayerInfo.mJumpCnt >= 3)
            {
                int a = 0;
            }
            else if(mPlayerInfo.mJumpCnt >= 1 && mPlayerInfo.mJumpCnt <= 2)
            {
				isChangedDir = true;
            }
        }

        if (Input::GetKeyDown(eKeyCode::C) && mPlayerInfo.mJumpCnt <= 1 && wasStand == true)
        {
            Vector3 velocity = mRb->GetVelocity();
            velocity.x += 700.0f * -(int)mPlayerInfo.mDir;
            velocity.y -= 60.0f;

            mRb->SetVelocity(velocity);
            mRb->SetGround(false);
            mPlayerInfo.mJumpCnt++;
            wasStand = false;
            object::InstantiateSkill<JumpSkill>(pos, Vector3(100.0f, 100.0f, 1.0f));
        }

        if (Input::GetKeyDown(eKeyCode::C) && mPlayerInfo.mJumpCnt <= 2 && mPlayerInfo.mJumpCnt >= 1 && isChangedDir == false)
        {
            Vector3 velocity = mRb->GetVelocity();
            velocity.x += 300.0f * -(int)mPlayerInfo.mDir;
            velocity.y -= 260.0f;

            mRb->SetVelocity(velocity);
            mRb->SetGround(false);
            mPlayerInfo.mJumpCnt++;
            object::InstantiateSkill<JumpSkill>(pos, Vector3(100.0f, 100.0f, 1.0f));
        }

        if (Input::GetKeyDown(eKeyCode::C) && mPlayerInfo.mJumpCnt <= 2 && mPlayerInfo.mJumpCnt >= 1 && isChangedDir == true)
        {
            Vector3 velocity = mRb->GetVelocity();
            velocity.x *= -1;
            velocity.x += 300.0f * -(int)mPlayerInfo.mDir;
            velocity.y -= 260.0f;

            mRb->SetVelocity(velocity);
            mRb->SetGround(false);
            mPlayerInfo.mJumpCnt++;
            object::InstantiateSkill<JumpSkill>(pos, Vector3(100.0f, 100.0f, 1.0f));
        }

   /*     if (Input::GetKeyDown(eKeyCode::C) && mPlayerInfo.mJumpCnt <= 2 && mPlayerInfo.mJumpCnt > 1 && isChangedDir == true)
        {
            Vector3 velocity = mRb->GetVelocity();
            velocity.x *= -1;
            velocity.x += 300.0f * -(int)mPlayerInfo.mDir;
            velocity.y -= 260.0f;

            mRb->SetVelocity(velocity);
            mRb->SetGround(false);
            mPlayerInfo.mJumpCnt++;
        }*/


        if (Input::GetKeyDown(eKeyCode::LCTRL))
        {
            mPlayerState = ePlayerState::Attack;
        }

        if (mPlayerInfo.isGrounded == true)
        {
            isChangedDir = false;
            mPlayerInfo.mJumpCnt = 0;
            mPlayerState = ePlayerState::Idle;
        }

    }

    void PlayerScript::Prone()
    {
        cd->SetSize(Vector2(0.65f, 0.4f));
        cd->SetCenter(Vector2(0.0f, -45.0f));
        if (Input::GetKeyUp(eKeyCode::DOWN))
        {
            cd->SetSize(Vector2(0.5f, 0.8f));
            cd->SetCenter(Vector2::Zero);
            mPlayerState = ePlayerState::Idle;
        }
    }

    void PlayerScript::Attack()
    {

    }

    void PlayerScript::Hitted()
    {
        mPlayerInfo.mHittedTime += Time::DeltaTime();
        Vector3 mPos = tr->GetPosition();
        mPos.x += (float)mPlayerInfo.mDir * -80.0f * Time::DeltaTime();
        mPos.y += 160.0f * Time::DeltaTime();
        tr->SetPosition(Vector3(mPos.x, mPos.y, mPos.z));
        

        if (mPlayerInfo.mHittedTime >= 0.5f)
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

    void PlayerScript::PlayerControl()
    {
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
            break;
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
    }

    void PlayerScript::AnimatorControl()
    {
        if (mPlayerInfo.mDir == PlayerDir::Right)
        {
            mPlayerInfo.isRight = true;
        }
        else if(mPlayerInfo.mDir == PlayerDir::Left)
        {
            mPlayerInfo.isRight = false;
        }

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
                at->PlayAnimation(L"CharactorCharAssain2Hit", true);
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
