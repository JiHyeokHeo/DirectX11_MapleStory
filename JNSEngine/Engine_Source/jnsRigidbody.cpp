#include "jnsRigidbody.h"
#include "jnsTime.h"
#include "jnsGameObject.h"
#include "jnsTransform.h"


namespace jns
{
	RigidBody::RigidBody()
		:Component(eComponentType::RigidBody)
		, mMass(0.2f)
		, mForce(Vector3::Zero)
		, mAccelation(Vector3::Zero)
		, mVelocity(Vector3::Zero)
	{
		mLimitedVelocity.x = 200.0f;
		mLimitedVelocity.y = 1000.0f;
		mbGround = false;
		mGravity = Vector3(0.0f, 1400.0f ,0.0f);
		mFriction = 100.0f;
	}
	RigidBody::~RigidBody()
	{
	}
	void RigidBody::Initialize()
	{
	}
	void RigidBody::Update()
	{
		mAccelation = mForce / mMass;

		// 속도에 가속도를 더해준다.
		mVelocity += mAccelation * Time::DeltaTime();

		if (mbGround)
		{
			mVelocity = Vector3::Zero;
			// 땅위에 있을때
			Vector3 gravity = mGravity;
			gravity.Normalize();

			float dot = mVelocity.Dot(gravity);
			mVelocity -= gravity * dot;
		}
		else // 땅위에 없으면 그냥 계속해서 더해준다.
		{
			mVelocity += mGravity * Time::DeltaTime();
		}

		//mVelocity += mAccelation * Time::DeltaTime();
		// 중력가속도 최대 속도 제한
		Vector3 gravity = mGravity;
		gravity.Normalize();
		float dot = mVelocity.Dot(gravity); // 내적 스칼라값 반환 방향은 없고 오직 크기만
		gravity = gravity * dot;

		Vector3 sideVelocity = mVelocity - gravity;
		if (mLimitedVelocity.y < gravity.Length())
		{
			gravity.Normalize();
			gravity *= mLimitedVelocity.y;
		}

		if (mLimitedVelocity.x < sideVelocity.Length())
		{
			sideVelocity.Normalize();
			sideVelocity *= mLimitedVelocity.x;
		}
			
		//// 마찰력 조건 ( 적용된 힘이 없고, 속도가 0이 아님)
		//if (!(mVelocity == Vector3::Zero))
		//{
		//	//속도에 반대방향으로 마찰력이 적용된다.
		//	Vector3 friction = -mVelocity;
		//	friction.Normalize();
		//	friction = friction * mFriction * mMass * Time::DeltaTime();

		//	//마찰력으로 인한 속도 감소는 현재 속도보다 큰 경우

		//	if (mVelocity.Length() < friction.Length())
		//	{
		//		mVelocity = Vector3::Zero;
		//	}
		//	else
		//	{
		//		mVelocity += friction;
		//	}
		//}

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();
		pos = pos - mVelocity * Time::DeltaTime();
		tr->SetPosition(pos);
		
		mForce = Vector3::Zero;
	}
	void RigidBody::LateUpdate()
	{
	}
	void RigidBody::Render()
	{
	}

	void RigidBody::AddForce(Vector3 force)
	{
		mForce += force;
	}

}