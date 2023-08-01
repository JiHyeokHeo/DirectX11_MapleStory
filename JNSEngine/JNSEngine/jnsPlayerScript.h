#pragma once
#include "jnsScript.h"
#include "jnsInput.h"
#include "jnsRigidbody.h"
#include "jnsScene.h"

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

		enum class eKeyType
		{
			Attack = (UINT)eKeyCode::LCTRL,
			Jump = (UINT)eKeyCode::C,
			Prone = (UINT)eKeyCode::DOWN,
			MoveL = (UINT)eKeyCode::LEFT,
			MoveR = (UINT)eKeyCode::RIGHT,
			Skill = (UINT)eKeyCode::F,
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
		PlayerDir GetPlayerDirection() { return mPlayerInfo.mPrevDir; }

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
			bool isPlayed;
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
