#pragma once
#include "jnsScript.h"
#include "jnsInput.h"
#include "jnsRigidbody.h"
#include "jnsScene.h"
#include "jnsSkillManager.h"

namespace jns
{
	class Animator;
	class InventoryScript;
	class PlayerScript : public Script
	{
	public:
		enum class ePlayerState
		{
			Idle = 0,
			Move,
			Ladder,
			Jump,
			Prone,
			Attack,
			Hitted,
			Die,
			Attracted,
			DontMove,
			End,
		};

		struct PlayerSkillInfo
		{
			bool isAssainHit1Used;
		};

		class eKeyType
		{
		public:
			eKeyCode Attack = eKeyCode::LCTRL;
			eKeyCode NormalJump = eKeyCode::C;
			eKeyCode Jump = eKeyCode::C;
			eKeyCode Prone = eKeyCode::DOWN;
			eKeyCode MoveL = eKeyCode::LEFT;
			eKeyCode MoveR = eKeyCode::RIGHT;
			eKeyCode Skill = eKeyCode::F;
		};

		enum class PlayerDir
		{
			Left = -1,
			Right = 1,
		};

		struct PlayerInfo
		{
			float invisibilityTime;
			int maxhp;
			int hp;
			int mp;
			int exp;
			int mJumpCnt;
			float mJumpTime;
			float mJumpForce;
			bool isGrounded;
			bool isPlayPossible;
			bool isRight;
			float mDeathTime;
			float mHittedTime;
			float mMoveSpeed;
			PlayerDir mDir;     // 왼쪽일때 -1 오른쪽일때 1값이 들어가도록
			PlayerDir mPrevDir;
		};

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

		eKeyCode GetPlayerClickButton() { return mClicked; }
		PlayerDir GetPlayerDirection() { return mPlayerInfo.mDir; }
		void SetPlayerDirection(PlayerDir dir) { mPlayerInfo.mDir = dir; }
		eKeyType GetPlayerKeyType() { return mPlayerKeyType; }
		void SetPlayerState(ePlayerState state) { mPlayerState = state; }
		ePlayerState GetPlayerState() { return mPlayerState; }
		ePlayerState GetPlayerPrevState() { return mPrevPlayerState; }
		void SetInventoryScript(InventoryScript* script) { mInventoryScript = script; }
		PlayerInfo GetPlayerInfo() { return mPlayerInfo; }
		PlayerSkillInfo GetPlayerSkillInfo() { return mPlayerSkillInfo; }
		
		void PlayerDamaged(int dmg);

		void SetIsNormalHit(bool isHit) { isNormalHit = isHit; }
		bool GetIsNormalHit() { return isNormalHit; }

		void SetBossIsLeft(bool isLeft) { isBossIsLeft = isLeft; }

		void SetIsPushedHit(bool ispushhit) { isPushedHit = ispushhit; }

		void SetIsSkillLock(bool isskilllock) { isSkillLocked = isskilllock; }

		static int GetStaticPlayerDir() { return playerDir; }
	private:
		void CheckAttackSkills();
		void HpLerp();
		void OpenInventory();
		void BindConstantBuffer();
		void Idle();
		void Move();
		void Ladder();
		void Jump();
		void Prone();
		void Attack();
		void Hitted();
		void Die();
		void Attarct();
		void DontMove();


		void TurnOnLightWhenIHit();
		// 애니메이션 이벤트를 통해 스킬 생성 타이밍 조절
		void CompleteAssasinHit1();
		void CompleteAssasinHit2();
		void CompleteAnimation();
		void CompletePronStab();
		void CompleteRope();
		void InstantiateAssainHit1Skill();
		void InstantiateAssainHit2Skill();
		void InstantiateJumpSkill();

		void CheckJumpCount();

		void ActiveJumpSkill();
		void PlayerControl();
		void AnimatorControl();

		void Clear();
		void GetNewPosition();
		void CheckPlayerHp();
		void CheckPlayerIsGrounded();
		void CheckIsAssainHitUsed();
		void CheckInvisibleTime();
	private:
		static int playerDir;

		eKeyType mPlayerKeyType;

		Transform* tr;
		RigidBody* mRb;
		Animator* at;
		Collider2D* cd;
		
		PlayerInfo mPlayerInfo;
		PlayerSkillInfo mPlayerSkillInfo;
		ePlayerState mPlayerState;
		ePlayerState mPrevPlayerState = ePlayerState::End;
		eKeyCode mClicked;
		
		InventoryScript* mInventoryScript;
		
		Scene* mPreveScene;
		Scene* mActveScene;
		
		int checktime;
		bool isAnimationDone;
		
		bool isDone;
		bool isChangedDir;
		bool wasStand = false;

		bool isLadderMoving = false;
		bool isLadderOn = false;

		bool isTombInstantiate = false;

		float angle = 0.0;  
		bool checkInvisibleTime;
		bool isNotSetDeadPos = true;

		float centerX;
		float centerY;

		float mBlackTime = 0.0f;
		bool isNormalHit = false;
		
		
		bool isPushedHit = false;
		bool isBossIsLeft = true;

		bool isSkillLocked = false;


		int destinationHp;
		int mPrevHp;
		bool isHpLerp = false;

		bool isDownGround = true;
		bool isAttarcted = false;

		float pusehdPower = 300.0f;

		int clickcnt = 0;
	};
}
