#pragma once
#include "jnsScript.h"


namespace jns
{

	class HeartScript : public Script
	{
	public:
		enum class eHeartState
		{
			Move,
			Summon,
			Bomb,
			End,
		};
		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

		void Fsm();
		void PlayAnimation();

		void GoUp();

		void CompleteSummon();
		void CompleteBomb();
	private:
		eHeartState heartState;
		eHeartState prevheartState = eHeartState::End;
		float destinationYcor = 50.0f;

		bool isSummon = false;
		class Transform* tr;
		class Animator* at;
		float heartMoveSpeed = 100.0f;

		float heartStartPos = -375.0f;
		int hp;
	};

}
