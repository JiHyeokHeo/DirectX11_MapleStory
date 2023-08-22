#pragma once
#include "jnsScript.h"

namespace jns
{
	class MirrorScript : public Script
	{
	public:
		enum class eMirrorState
		{
			Summon,
			Idle,
			Bombed,
			Attract,
			Hit,
		};

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;


		void CheckSummonTime();
		void CheckMirrorHp();
		void Activate();
		void PlayAnimation();
		void CompleteAni();
		void CompleteSunmmon();

		void Summon();
		void Idle();
		void Bombed();
		void Hitted();
		void Attracted();
	private:
		eMirrorState mMirrorState;
		eMirrorState mMirrorPrevState;
		
		
		class Animator* at;

		float mSummonTime;
		float mSummonMaxTime;

		bool isNotPlayed;
		bool isDead;

		float mHp;

		float mPrevHp;

		bool isNotSetting = true;
	};
}
