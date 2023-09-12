#include "jnsPlayerScript.h"
#include "jnsTransform.h"
#include "jnsGameObject.h"
#include "jnsInput.h"
#include "jnsTime.h"
#include "jnsConstantBuffer.h"
#include "jnsRenderer.h"
#include "CommonSceneInclude.h"
#include "jnsTomb.h"

namespace jns
{
    int PlayerScript::playerDir = 0;
	void PlayerScript::Initialize()
	{
        // 플레이어 정보
		isAnimationDone = true;
        mPlayerState = ePlayerState::Idle;
		mPreveScene = nullptr;
		mPlayerInfo = {};
		mPlayerInfo.mMoveSpeed = 200.0f;
		mPlayerInfo.mJumpCnt = 0;
		mPlayerInfo.mDir = PlayerDir::Left;
        mPlayerInfo.hp = 100;
        mPlayerInfo.mp = 100;
        mPlayerInfo.exp = 0;
        mPrevHp = mPlayerInfo.hp;

        // 애니메이터
        at = GetOwner()->GetComponent<Animator>();
		mRb = GetOwner()->GetComponent<RigidBody>();
        cd = GetOwner()->GetComponent<Collider2D>();
        cd->SetColNum(1);
        this->SetColNum(1);
        tr = GetOwner()->GetComponent<Transform>();
        at->StartEvent(L"CharactorCharAssain1Hit") = std::bind(&PlayerScript::InstantiateAssainHit1Skill, this);
        at->StartEvent(L"CharactorCharAssain2Hit") = std::bind(&PlayerScript::InstantiateAssainHit2Skill, this);
        at->StartEvent(L"CharactorCharJump") = std::bind(&PlayerScript::InstantiateJumpSkill, this);
        at->CompleteEvent(L"CharactorCharAssain1Hit") = std::bind(&PlayerScript::CompleteAssasinHit1, this);
		at->CompleteEvent(L"CharactorCharAssain2Hit") = std::bind(&PlayerScript::CompleteAssasinHit2, this);
		at->CompleteEvent(L"CharactorCharProneStab") = std::bind(&PlayerScript::CompletePronStab, this);
        at->CompleteEvent(L"CharactorCharRope") = std::bind(&PlayerScript::CompleteRope, this);
        at->PlayAnimation(L"CharactorCharIdle", true);
	}
	void PlayerScript::Update()
	{
		mActveScene = SceneManager::GetActiveScene();
        
        if (Input::GetKeyDown(eKeyCode::O))
        {
            tr->SetPosition(Vector3(100.0f, 300.0f, 1.0f));
            mPlayerState = ePlayerState::Idle;
        }


        if (Input::GetKeyDown(eKeyCode::U))
        {
            mPlayerState = ePlayerState::Die;
            mPlayerInfo.hp = 0;
        }

        if (Input::GetKeyDown(eKeyCode::H))
        {
            mPlayerInfo.hp = 100;
            mRb->SetGround(false);
        }

        if (mPreveScene != mActveScene)
		{
			mPreveScene = mActveScene;
			Clear();
		}

        if(SkillManager::FindSkillData(L"Rogue_SkillflashJump_01")->GetSkillLearn())
        {
            mPlayerKeyType.Jump = mPlayerKeyType.NormalJump;
        }

        //CheckJumpCount();
        OpenInventory();
        CheckPlayerHp();
        CheckPlayerIsGrounded();
        PlayerControl();
		AnimatorControl();
        TurnOnLightWhenIHit();
      
        mPrevPlayerState = mPlayerState;
        mPlayerInfo.mPrevDir = mPlayerInfo.mDir;
        playerDir = (int)mPlayerInfo.mDir;
	}
	void PlayerScript::LateUpdate()
	{
        if (mPlayerInfo.hp != mPrevHp)
        {
            checkInvisibleTime = true;
            isHpLerp = true;
        }

        if (checkInvisibleTime)
        {
            CheckInvisibleTime();
        }

		//BindConstantBuffer();
        at->GetActiveAnimation()->SetAniDirection((bool)mPlayerInfo.isRight);
        /*mPrevPlayerState = mPlayerState;
        mPlayerInfo.mPrevDir = mPlayerInfo.mDir;
        playerDir = (int)mPlayerInfo.mDir;*/
	}
	
	void PlayerScript::OnCollisionEnter(Collider2D* other)
	{

        // 땅바닥 관련 코드
        if (other->GetOwner()->GetLayerType() == eLayerType::Ground)
        {
            Ground* ground = dynamic_cast<Ground*>(other->GetOwner());
            if (ground->GetGroundName() == L"DownGround")
            {
                if (mPlayerState != ePlayerState::Die)
                {
                    isDownGround = true;
                    mPlayerState = ePlayerState::Idle;
                }
            }

            if (ground->GetGroundName() == L"DownJumpGround")
            {
                if (mPlayerState != ePlayerState::Die)
                {
                    Collider2D* playerCol = GetOwner()->GetComponent<Collider2D>();
                    Vector3 playerPos = playerCol->GetPosition();

                    Collider2D* groundCol = other->GetOwner()->GetComponent<Collider2D>();
                    Vector3 groundPos = groundCol->GetPosition();

                    if (mPlayerState == ePlayerState::Ladder)
                    {
                        float size = groundCol->GetSize().x / 2;
                        if (playerPos.x >= groundPos.x + size || playerPos.x <= groundPos.x - size)
                        {
                            if (playerPos.y >= groundPos.y)
                               mPlayerState = ePlayerState::Idle;
                        }
                    }
                }
            }
        }
	}
	void PlayerScript::OnCollisionStay(Collider2D* other)
	{
		if (other->GetName() == L"Item" && Input::GetKeyDown(eKeyCode::Z))
		{
			ItemResources* item = dynamic_cast<ItemResources*>(other->GetOwner());
		}


        // 땅바닥 관련 코드
        if (other->GetOwner()->GetLayerType() == eLayerType::Ground)
        {
            Ground* ground = dynamic_cast<Ground*>(other->GetOwner()); 
            if (ground->GetGroundName() == L"Ladder" )
            {
                if (Input::GetKey(eKeyCode::UP))
                {
                    isLadderOn = true;
                    mPlayerState = ePlayerState::Ladder;
                }
                else if (Input::GetKey(eKeyCode::DOWN) && isDownGround == false)
                {
                    isLadderOn = true;
                    mPlayerState = ePlayerState::Ladder;
                }
            }
        }

        if (other->GetOwner()->GetLayerType() == eLayerType::Ground)
        {
            Ground* ground = dynamic_cast<Ground*>(other->GetOwner());
            if (ground->GetGroundName() == L"DownJumpGround")
            {
                Collider2D* playerCol = GetOwner()->GetComponent<Collider2D>();
                Vector3 playerPos = playerCol->GetPosition();

                Collider2D* groundCol = other->GetOwner()->GetComponent<Collider2D>();
                Vector3 groundPos = groundCol->GetPosition();

                if (Input::GetKeyDown((eKeyCode)mPlayerKeyType.Jump) && mPlayerState == ePlayerState::Prone)
                {
                    float size = groundCol->GetSize().x / 2;
                    if (playerPos.x >= groundPos.x + size || playerPos.x <= groundPos.x - size)
                    {
                        if (playerPos.y >= groundPos.y)
                            mRb->SetGround(false);
                    }
                }

                if (mPlayerState == ePlayerState::Ladder)
                {
                    float size = groundCol->GetSize().x / 2;
                    if (playerPos.x >= groundPos.x + size || playerPos.x <= groundPos.x - size)
                    {
                        if (playerPos.y >= groundPos.y)
                            mPlayerState = ePlayerState::Idle;
                    }
                }
            }
        }
	}
	void PlayerScript::OnCollisionExit(Collider2D* other)
	{

        // 땅바닥 관련 코드
        if (other->GetOwner()->GetLayerType() == eLayerType::Ground)
        {
            Ground* ground = dynamic_cast<Ground*>(other->GetOwner());
            if (ground->GetGroundName() == L"Ladder" && mPlayerState != ePlayerState::Jump)
            {
                isLadderOn = false;
                mPlayerState = ePlayerState::Idle;
            }
        }

        if (other->GetOwner()->GetLayerType() == eLayerType::Ground)
        {
            Ground* ground = dynamic_cast<Ground*>(other->GetOwner());
            if (ground->GetGroundName() == L"DownGround")
            {
                if (mPlayerState != ePlayerState::Die)
                {
                    isDownGround = false;
                }
            }
        }
	}

    void PlayerScript::PlayerDamaged(int dmg)
    {
        // 여기서 데미지 연산 공식 들어가야한다
        mPlayerInfo.hp -= dmg;
    }

    void PlayerScript::CheckAttackSkills()
    {
        if (Input::GetKeyDown(SkillManager::FindSkillData(L"Normal_Assain_First_Attack")->GetSkillKeyState()))
        {
            mPlayerState = ePlayerState::Attack;
        }
    }

    void PlayerScript::HpLerp()
    {
    }

    void PlayerScript::OpenInventory()
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
		playerUICB.type = -1;
		ConstantBuffer* cb = renderer::constantBuffer[(UINT)eCBType::Player];
		
		cb->SetData(&playerUICB);
		cb->Bind(eShaderStage::PS);
	}

    void PlayerScript::Idle()
    {

		if (Input::GetKeyDown((eKeyCode)mPlayerKeyType.NormalJump))
		{
			wasStand = true;
			Vector3 velocity = mRb->GetVelocity();
			velocity.y -= 450.0f;
			mRb->SetVelocity(velocity);
			mRb->SetGround(false);
			mPlayerState = ePlayerState::Jump;
			//mPlayerInfo.mJumpCnt++;
		}
		else if (Input::GetKey((eKeyCode)mPlayerKeyType.Prone))
		{
			mPlayerState = ePlayerState::Prone;
		}
		else if (Input::GetKey((eKeyCode)mPlayerKeyType.MoveL))
		{
			mPlayerInfo.mDir = PlayerDir::Left;
			mPlayerState = ePlayerState::Move;
		}
		else if (Input::GetKey((eKeyCode)mPlayerKeyType.MoveR))
		{
			mPlayerInfo.mDir = PlayerDir::Right;
			mPlayerState = ePlayerState::Move;
		}

        CheckAttackSkills();
    }

    void PlayerScript::Move()
    {
        if (Input::GetKeyUp((eKeyCode)mPlayerKeyType.MoveL) || Input::GetKeyUp((eKeyCode)mPlayerKeyType.MoveR)
            || Input::GetKeyUp((eKeyCode)mPlayerKeyType.Prone) || Input::GetKeyUp((eKeyCode)mPlayerKeyType.Jump))
        {
            mPlayerState = ePlayerState::Idle;
        }

		Vector3 pos = tr->GetPosition();

		if (Input::GetKeyDown((eKeyCode)mPlayerKeyType.NormalJump))
		{
			Vector3 velocity = mRb->GetVelocity();
			velocity.x += 600.0f * -(int)mPlayerInfo.mDir;
			velocity.y -= 450.0f;

			mRb->SetVelocity(velocity);
			mRb->SetGround(false);
			mPlayerState = ePlayerState::Jump;
			mPlayerInfo.mJumpCnt++;
		}
		if (Input::GetKey((eKeyCode)mPlayerKeyType.Prone))
		{
			//pos.y -= 255.0f * Time::DeltaTime();
			//tr->SetPosition(pos);
		}
		if (Input::GetKey((eKeyCode)mPlayerKeyType.MoveL))
		{
			pos.x -= mPlayerInfo.mMoveSpeed * Time::DeltaTime();
		}
		if (Input::GetKey((eKeyCode)mPlayerKeyType.MoveR))
		{
			pos.x += mPlayerInfo.mMoveSpeed * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Q))
		{
			pos.z -= mPlayerInfo.mMoveSpeed * Time::DeltaTime();
		}
		if (Input::GetKeyDown(eKeyCode::E))
		{
			pos.z += mPlayerInfo.mMoveSpeed * Time::DeltaTime();
		}
        

        CheckAttackSkills();

		tr->SetPosition(pos);
    }

    void PlayerScript::Ladder()
    {
        Vector3 pos = tr->GetPosition();
        mPlayerInfo.mJumpCnt = 0;
        wasStand = false;

        if (Input::GetKey(eKeyCode::UP))
        {
            isLadderMoving = true;
            pos.y += 250.0f * Time::DeltaTime();
        }
        else if (Input::GetKey(eKeyCode::DOWN))
        {
            isLadderMoving = true;
            pos.y -= 250.0f * Time::DeltaTime();
        }
        else
        {
            isLadderMoving = false;
        }



        if (Input::GetKey((eKeyCode)mPlayerKeyType.MoveL))
        {
            mPlayerInfo.mDir = PlayerDir::Left;
        }
        if (Input::GetKey((eKeyCode)mPlayerKeyType.MoveR))
        {
            mPlayerInfo.mDir = PlayerDir::Right;
        }
        if (Input::GetKey((eKeyCode)mPlayerKeyType.Jump))
        {
            mPlayerInfo.mJumpCnt++;
            Vector3 velocity = mRb->GetVelocity();
            velocity.y -= 350.0f;
            velocity.x += 600.0f * -(int)mPlayerInfo.mDir;
            mRb->SetVelocity(velocity);
            mRb->SetGround(false);
            mPlayerState = ePlayerState::Jump;
            //mPlayerInfo.mJumpCnt++;
        }

        tr->SetPosition(pos);
    }

    void PlayerScript::Jump()
    {
        Vector3 pos = tr->GetPosition();
        Vector3 velocity = mRb->GetVelocity();

        if (mPlayerInfo.isGrounded == true)
        {
            isLadderOn = false;
            isChangedDir = false;
            mPlayerInfo.mJumpCnt = 0;
            mPlayerState = ePlayerState::Idle;
        }

        if (SkillManager::FindSkillData(L"Rogue_SkillflashJump_01")->GetSkillKeyState() == eKeyCode::NONE)
            return;


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
          
           if(mPlayerInfo.mJumpCnt >= 1 && mPlayerInfo.mJumpCnt <= 3)
            {
				isChangedDir = true;
            }
        }

        if (Input::GetKeyDown((eKeyCode)mPlayerKeyType.Jump) && mPlayerInfo.mJumpCnt <= 1 && wasStand == true)
        {
            velocity.x += 700.0f * -(int)mPlayerInfo.mDir;
            velocity.y -= 180.0f;

            mPlayerInfo.mJumpCnt++;
            wasStand = false;

            // 점프 생성
            //pos.x -= (int)mPlayerInfo.mDir * 100.0f;
        }

        if (Input::GetKeyDown((eKeyCode)mPlayerKeyType.Jump) && mPlayerInfo.mJumpCnt <= 2 && mPlayerInfo.mJumpCnt >= 1 && isChangedDir == false && isLadderOn == true)
        {
            //pos.x -= (int)mPlayerInfo.mDir * 100.0f;

            ActiveJumpSkill();
            mPlayerInfo.mJumpCnt++;
        }

        if (Input::GetKeyDown((eKeyCode)mPlayerKeyType.Jump) && mPlayerInfo.mJumpCnt <= 2 && mPlayerInfo.mJumpCnt >= 1 && isChangedDir == true && isLadderOn == true)
        {
            velocity.x = 0.0f;
            velocity.x += 700.0f * -(int)mPlayerInfo.mDir;
            velocity.y -= 180.0f;

            ActiveJumpSkill();

            mPlayerInfo.mJumpCnt++;
        }

        if (Input::GetKeyDown((eKeyCode)mPlayerKeyType.Jump) && mPlayerInfo.mJumpCnt <= 2 && mPlayerInfo.mJumpCnt >= 1 && isChangedDir == false && isLadderOn == false)
        {
            velocity.x += 200.0f * -(int)mPlayerInfo.mDir;
            velocity.y -= 180.0f;


            ActiveJumpSkill();

            mPlayerInfo.mJumpCnt++;
        }

        if (Input::GetKeyDown((eKeyCode)mPlayerKeyType.Jump) && mPlayerInfo.mJumpCnt <= 2 && mPlayerInfo.mJumpCnt >= 1 && isChangedDir == true && isLadderOn == false)
        {
            velocity.x = 0.0f;
            velocity.x += 700.0f * -(int)mPlayerInfo.mDir;
            velocity.y -= 180.0f;


            ActiveJumpSkill();

            mPlayerInfo.mJumpCnt++;
        }


 

        CheckAttackSkills();

        mRb->SetVelocity(velocity);
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
        if (Input::GetKeyDown(eKeyCode::D))
        {
            
        }
  
    }

    void PlayerScript::Hitted()
    {
        mPlayerInfo.mHittedTime += Time::DeltaTime();
        Vector3 mPos = tr->GetPosition();
        mPos.x += (float)mPlayerInfo.mDir * -80.0f * Time::DeltaTime();
        mPos.y += 160.0f * Time::DeltaTime();
        tr->SetPosition(Vector3(mPos.x, mPos.y, mPos.z));
        
    }

    void PlayerScript::Die()
    {
     /*   if (mPlayerInfo.isGrounded == true)
        {*/
			mPlayerInfo.mDeathTime += Time::DeltaTime();

			if (angle >= 360.0f)
			{
				angle = 0.0f;
			}
			float radius = 10.0f; 


			if (isNotSetDeadPos)
			{
				centerX = tr->GetPosition().x; 
				centerY = tr->GetPosition().y + 20.0f; 
				isNotSetDeadPos = false;
			}



			float x = centerX + (radius * cos(DegreeToRadian(angle)));
			float y = centerY + (radius * sin(DegreeToRadian(angle)));

			angle -= 250.0 * Time::DeltaTime();

			tr->SetPosition(Vector3(x, y, tr->GetPosition().z));
            
        //}
    }

    void PlayerScript::Attarct()
    {
        isAttarcted = true;
    }

    void PlayerScript::TurnOnLightWhenIHit()
    {
        if (mBlackTime >= 1.0f)
        {
            isNormalHit = false;
        }

        if (isNormalHit)
        {
            mBlackTime += Time::DeltaTime();
            Light* light = GetOwner()->GetComponent<Light>();
            light->SetColor(Vector4(0.8f, 0.8f, 0.8f, 1.0f));
        }
        else
        {
            mBlackTime = 0.0f;
            Light* light = GetOwner()->GetComponent<Light>();
            light->SetColor(Vector4::Zero);
        }
    }

    void PlayerScript::PlayerControl()
    {
        if (isAttarcted)
            mPlayerState = ePlayerState::Attracted;

        switch (mPlayerState)
        {
        case ePlayerState::Idle:
            Idle();
            break;
        case ePlayerState::Move:
            Move();
            break;
        case ePlayerState::Ladder:
            Ladder();
            break;
        case ePlayerState::Jump:
            Jump();
            break;
        case ePlayerState::Prone:
            Prone();
            break;
        case ePlayerState::Attack:
            Attack();
            break;
        case ePlayerState::Hitted:
            Hitted();
            break;
        case ePlayerState::Attracted:
            Attarct();
            break;
        case ePlayerState::Die:
            Die();
            break;
        default:
            break;
        }

        if (mPlayerInfo.hp <= 0)
        {
            mPlayerState = ePlayerState::Die;
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
            switch (mPlayerState)
            {
            case ePlayerState::Idle:
                at->PlayAnimation(L"CharactorCharIdle", true);
                break;
            case ePlayerState::Move:
                at->PlayAnimation(L"CharactorCharWalk", true);
                break;
            case ePlayerState::Ladder:
                at->PlayAnimation(L"CharactorCharRope", true);
                break;
            case ePlayerState::Jump:
                at->PlayAnimation(L"CharactorCharJump", true);
                break;
            case ePlayerState::Prone:
                at->PlayAnimation(L"CharactorCharProne", true);
                break;
            case ePlayerState::Attack:
                CheckIsAssainHitUsed();
                break;
            case ePlayerState::Attracted:
                at->PlayAnimation(L"CharactorCharAttract", true);
                break;
            case ePlayerState::Hitted:
                at->PlayAnimation(L"CharactorCharHit", true);
                break;
            case ePlayerState::Die:
                at->PlayAnimation(L"CharactorCharDead", true);
                at->GetActiveAnimation()->SetTransparency(0.7f);
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

        if (mPlayerState == ePlayerState::Ladder && isAnimationDone == true && isLadderMoving == true)
        {
            at->PlayAnimation(L"CharactorCharRope", true);
            isAnimationDone = false;
        }

    }

    void PlayerScript::Clear()
    {
        mRb->SetGround(false);
        mPlayerInfo.isGrounded = false;
        mPlayerInfo.mJumpTime = 0.0f;
    }

    void PlayerScript::GetNewPosition()
    {
    }

    void PlayerScript::CheckPlayerHp()
    {
        if (mPlayerInfo.hp <= 0)
        {
            isAttarcted = false;
            Vector3 playerPos = tr->GetPosition();
            mPlayerState = ePlayerState::Die;
        }
        else if(mPlayerInfo.hp > 0)
        {
            isNotSetDeadPos = true;
        }
    }

    void PlayerScript::CheckPlayerIsGrounded()
    {
        mPlayerInfo.isGrounded = mRb->GetGround();

        if (mPlayerInfo.isGrounded == false)
        {
            mPlayerInfo.mJumpTime += Time::DeltaTime();
        }
        else if (mPlayerInfo.isGrounded == true)
        {
            isLadderOn = false;
            isChangedDir = false;
            mPlayerInfo.mJumpCnt = 0;
            mPlayerInfo.mJumpTime = 0.0f;
        }
    }
    void PlayerScript::CheckIsAssainHitUsed()
    {
		if (mPlayerSkillInfo.isAssainHit1Used == false)
		{
			at->PlayAnimation(L"CharactorCharAssain1Hit", true);
		}
		else if (mPlayerSkillInfo.isAssainHit1Used == true)
		{
			at->PlayAnimation(L"CharactorCharAssain2Hit", true);
		}
    }

    void PlayerScript::CheckInvisibleTime()
    {
        mPlayerInfo.invisibilityTime += Time::DeltaTime();
        
        if (mPlayerInfo.invisibilityTime >= 1.0f)
        {
            mPlayerInfo.invisibilityTime = 0.0f;
            checkInvisibleTime = false;
            mPrevHp = mPlayerInfo.hp;
        }
    }
    
    void PlayerScript::CompleteAssasinHit1()
    {
        mPlayerState = ePlayerState::Idle;
    }
    void PlayerScript::CompleteAssasinHit2()
    {
        mPlayerState = ePlayerState::Idle;
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
    void PlayerScript::CompleteRope()
    {
        if (isLadderMoving == false)
        {
            at->PlayAnimation(L"CharactorCharRopeIdle", false);
            isAnimationDone = true;
        }
        else
        {
            at->PlayAnimation(L"CharactorCharRope", true);
        }
    }
    void PlayerScript::InstantiateAssainHit1Skill()
    {
        mPlayerSkillInfo.isAssainHit1Used = true;
        GameObject* obj = SkillManager::FindSkill(L"Normal_Assain_First_Attack");
        AssainHit01* obj2 = dynamic_cast<AssainHit01*>(obj);
        obj2->SetSkillMode(true);
        obj2->SetSkillPlay(true);
    }
    void PlayerScript::InstantiateAssainHit2Skill()
    {
        mPlayerSkillInfo.isAssainHit1Used = false;
        GameObject* obj = SkillManager::FindSkill(L"Normal_Assain_Second_Attack");
        AssainHit02* obj2 = dynamic_cast<AssainHit02*>(obj);
        obj2->SetSkillMode(true);
        obj2->SetSkillPlay(true);
    }
    void PlayerScript::InstantiateJumpSkill()
    {


    }
    void PlayerScript::CheckJumpCount()
    {
        if (mPlayerInfo.isGrounded == true)
        {
            isDone = false;
        }
    }
    void PlayerScript::ActiveJumpSkill()
    {
        if (mPlayerInfo.mJumpCnt == 1)
        {
            GameObject* obj = SkillManager::FindSkill(L"Rogue_SkillflashJump_01");
            JumpSkill* obj2 = dynamic_cast<JumpSkill*>(obj);
            obj2->SetSkillMode(true);
            obj2->SetSkillPlay(true);
            obj2->IsPosSet(true);
        }
        else
        {
            GameObject* obj = SkillManager::FindSkill(L"Rogue_SkillflashJump_02");
            JumpSkill* obj2 = dynamic_cast<JumpSkill*>(obj);
            obj2->SetSkillMode(true);
            obj2->SetSkillPlay(true);
            obj2->IsPosSet(true);
        }
    }
}
