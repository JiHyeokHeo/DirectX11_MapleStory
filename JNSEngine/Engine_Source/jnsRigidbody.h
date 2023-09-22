#pragma once
#include "jnsComponent.h"

namespace jns
{
	using namespace jns::enums;
	using namespace jns::math;

	class RigidBody : public Component
	{
	public:
		RigidBody();
		~RigidBody();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void SetGround(bool mGround) { mbGround = mGround; }
		void SetMass(float mass) { mMass = mass; }
		bool GetGround() { return mbGround; }

		void SetIsRigidBodyOn(bool mRigidBody) { mRigidBodyOn = mRigidBody; }

		Vector3 GetVelocity() {	return mVelocity; }
		void SetVelocity(Vector3 vel) { mVelocity = vel; }
		void AddForce(Vector3 force);

	private:
		float mMass;
		Vector3 mForce;
		Vector3 mAccelation;
		Vector3 mVelocity;
		Vector3 mLimitedVelocity;

		Vector3 mGravity;
		float mFriction;
		bool mbGround;
		bool mRigidBodyOn;
		RigidBody* mRigidBody;
	};

}
