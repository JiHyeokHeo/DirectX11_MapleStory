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
			Idle,
			Move,
			Ladder,
			Jump,
			Prone,
			Attack,
			Hitted,
			Die,
			End,
		};

		class eKeyType
		{
		public:
			uint32_t Attack = static_cast<uint32_t>(eKeyCode::LCTRL);
			uint32_t Jump = static_cast<uint32_t>(eKeyCode::C);
			uint32_t Prone = static_cast<uint32_t>(eKeyCode::DOWN);
			uint32_t MoveL = static_cast<uint32_t>(eKeyCode::LEFT);
			uint32_t MoveR = static_cast<uint32_t>(eKeyCode::RIGHT);
			uint32_t Skill = static_cast<uint32_t>(eKeyCode::F);
		};

		enum class PlayerDir
		{
			Left = -1,
			Right = 1,
		};

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;


		void BindConstantBuffer();
		eKeyCode GetPlayerClickButton() { return mClicked; }
		PlayerDir GetPlayerDirection() { return mPlayerInfo.mDir; }
		eKeyType GetPlayerKeyType() { return mPlayerKeyType; }

	public:
		void Idle();
		void Move();
		void Ladder();
		void Jump();
		void Prone();
		void Attack();
		void Hitted();
		void Die();


		// 애니메이션 이벤트를 통해 스킬 생성 타이밍 조절
		void CompleteAssasinHit1();
		void CompleteAssasinHit2();
		void CompleteAnimation();
		void CompletePronStab();
		void CompleteRope();
		void InstantiateAssainHit1Skill();
		void InstantiateAssainHit2Skill();
		void InstantiateJumpSkill();



		void PlayerControl();
		void AnimatorControl();
		void SetInventoryScript(InventoryScript* script) { mInventoryScript = script; }



		void Clear();
		void CheckPlayerIsGrounded();
		void CheckIsAssainHitUsed();
		
	private:
		struct PlayerInfo
		{
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

		struct PlayerStatus
		{
		};

		struct PlayerSkillInfo
		{
			bool isAssainHit1Used;
		};

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
	};
}
