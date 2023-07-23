#pragma once
#include "jnsScript.h"

namespace jns
{
	class PlayerScript : public Script
	{
	public:
		enum class ePlayerState
		{
			Idle,
			Move,
			Attack,
			Attacked,
			Die,
			End,
		};


		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

		void Complete();

		void bindConstantBuffer();

	public:
		void Idle();
		void Move();
		void Attack();
		void Attacked();
		void Die();


		void AnimatorControl();
	private:
		ePlayerState mPlayerState;
		ePlayerState mPrevPlayerState;
		bool isPlayed;
		bool isRight;
	};
}
