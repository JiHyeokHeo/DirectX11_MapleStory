#pragma once
#include "jnsScript.h"


namespace jns
{
	class BloodyQueenScript : public Script
	{
	public:
		enum class eBloodyQueenType
		{
			Normal,
			Attract,
			Reflect,
			Smile,
		};

		enum class eBossStatus
		{

		};

		enum class BossDir
		{
			Left = -1,
			Right = 1,
		};

		enum class eBloodyQueenState
		{
			Idle,
			Move,

		};
		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;
	
	public:
		void Idle();
		void Move();


	private:
		eBossStatus mBloodyQueenStatus;
		eBloodyQueenState mBloodyQueenState;
		class Transform* tr;
		class RigidBody* mRb;
		class Animator* at;
		class Collider2D* cd;
	};


}