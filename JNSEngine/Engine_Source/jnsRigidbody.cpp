#include "jnsRigidbody.h"
#include "jnsTime.h"
#include "jnsGameObject.h"
#include "jnsTransform.h"


namespace jns
{
	RigidBody::RigidBody()
		:Component(eComponentType::RigidBody)
		, mMass(0.0f)
		, mForce(Vector3::Zero)
		, mAccelation(Vector3::Zero)
		, mVelocity(Vector3::Zero)
	{
		mLimitedVelocity.x = 200.0f;
		mLimitedVelocity.y = 1000.0f;
		mbGround = false;
		mGravity = Vector3(0.0f, 700.0f ,0.0f);
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

		// �ӵ��� ���ӵ��� �����ش�.
		mVelocity += mAccelation * Time::DeltaTime();
		if (mbGround)
		{
			// ������ ������
			Vector3 gravity = mGravity;
			gravity.Normalize();

			float dot = mVelocity.Dot(gravity);
			mVelocity -= gravity * dot;
		}
		else // ������ ������ �׳� ����ؼ� �����ش�.
		{
			mVelocity += mGravity * Time::DeltaTime();
		}


		// �߷°��ӵ� �ִ� �ӵ� ����
		Vector3 gravity = mGravity;
		gravity.Normalize();
		float dot = mVelocity.Dot(gravity); // ���� ��Į�� ��ȯ ������ ���� ���� ũ�⸸
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