#pragma once
#include "jnsScript.h"
#include "jnsInput.h"

namespace jns
{
	class InventoryScript;
	class PlayerScript : public Script
	{
	public:
		enum class ePlayerState
		{
			Idle,
			Move,
			Prone,
			Attack,
			Hitted,
			Die,
			End,
		};


		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;


		void bindConstantBuffer();

	public:
		void Idle();
		void Move();
		void Prone();
		void Attack();
		void Hitted();
		void Die();

		void CompleteAssasinHit1();
		void CompleteAnimation();
		void AnimatorControl();
	
		void SetInventoryScript(InventoryScript* script) { mInventoryScript = script; }

	private:
		ePlayerState mPlayerState;
		ePlayerState mPrevPlayerState = ePlayerState::End;
		bool isPlayed;
		bool isRight;
		float mDeathTime;
		float mHittedTime;
		InventoryScript* mInventoryScript;
	};
}
