#pragma once
#include "jnsScript.h"

namespace jns
{
	class PierreHatScript : public Script
	{
	public:
		virtual void Initialize() override;
		virtual void Update() override;

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

		void CompleteCapStartEnd();
		void CompleteCapAffected();
		void CompleteCapAffectedAfter();
		void CompleteWarning1();
		void CompleteWarning2();
		void CompleteWarning3();
		void ResetData();

		void Activate();
	private:
		class Animator* at;
		class Transform* tr;
		class Collider2D* cd;
		bool isHit;
		float hitTime;
		float hitMaxTime = 3.0f;
	};

}
