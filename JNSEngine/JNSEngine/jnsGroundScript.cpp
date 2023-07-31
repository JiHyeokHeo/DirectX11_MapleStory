#include "jnsGroundScript.h"
#include "CommonSceneInclude.h"

namespace jns
{
	GroundScript::GroundScript()
		: mGround(nullptr)
	{
	}
	GroundScript::~GroundScript()
	{
	}
	void GroundScript::Initialize()
	{
		mGround = dynamic_cast<Ground*>(this->GetOwner());
	}
	void GroundScript::Update()
	{
	}
	void GroundScript::LateUpdate()
	{
	}
	void GroundScript::OnCollisionEnter(Collider2D* other)
	{
		if (mGround->GetGroundName() == L"DownGround")
			CheckDownGround(other);

		if (mGround->GetGroundName() == L"LeftGround")
			CheckLeftGround(other);

		if (mGround->GetGroundName() == L"RightGround")
			CheckRightGround(other);

	}
	void GroundScript::OnCollisionStay(Collider2D* other)
	{
		if (mGround->GetGroundName() == L"LeftGround")
			CheckLeftGround(other);

		if (mGround->GetGroundName() == L"RightGround")
			CheckRightGround(other);
		
		if (mGround->GetGroundName() == L"Ladder" && Input::GetKey(eKeyCode::UP))
			CheckLadder(other);
	}
	void GroundScript::OnCollisionExit(Collider2D* other)
	{
		if (mGround->GetGroundName() == L"DownGround")
		{
			Player* player = dynamic_cast<Player*>(other->GetOwner());
			if (player == nullptr)
				return;

			RigidBody* rb = other->GetOwner()->GetComponent<RigidBody>();
			rb->SetGround(false);
		}

		if (mGround->GetGroundName() == L"Ladder")
		{
			RigidBody* rb = other->GetOwner()->GetComponent<RigidBody>();
			rb->SetGround(false);
		}
	}



	void GroundScript::CheckDownGround(Collider2D* other)
	{
		Player* player = dynamic_cast<Player*>(other->GetOwner());
		if (player == nullptr)
			return;

		RigidBody* rb = other->GetOwner()->GetComponent<RigidBody>();
		rb->SetGround(true);
		Collider2D* playerCol = player->GetComponent<Collider2D>();
		Vector3 playerPos = playerCol->GetPosition();

		Collider2D* groundCol = this->GetOwner()->GetComponent<Collider2D>();
		Vector3 groundPos = groundCol->GetPosition();

		float fLen = fabs(playerPos.y - groundPos.y);
		float fSize = (playerCol->GetScale().y / 2.0f) + (groundCol->GetScale().y / 2.0f);

		if (fLen < fSize)
		{
			Transform* playerTr = player->GetComponent<Transform>();
			Transform* grTr = this->GetOwner()->GetComponent<Transform>();

			Vector3 playerPos = playerTr->GetPosition();
			Vector3 grPos = grTr->GetPosition();

			playerPos.y += (fSize - fLen) - 1.0f;
			playerTr->SetPosition(playerPos);
		}
	}
	void GroundScript::CheckLeftGround(Collider2D* other)
	{
		Player* player = dynamic_cast<Player*>(other->GetOwner());
		if (player == nullptr)
			return;

		RigidBody* rb = other->GetOwner()->GetComponent<RigidBody>();
		Collider2D* playerCol = player->GetComponent<Collider2D>();
		Vector3 playerPos = playerCol->GetPosition();

		Collider2D* groundCol = this->GetOwner()->GetComponent<Collider2D>();
		Vector3 groundPos = groundCol->GetPosition();

		float fLen = fabs(playerPos.x - groundPos.x);
		float fSize = (playerCol->GetScale().x / 2.0f) + (groundCol->GetScale().x / 2.0f);

		if (fLen < fSize)
		{
			Transform* playerTr = player->GetComponent<Transform>();
			Transform* grTr = this->GetOwner()->GetComponent<Transform>();

			Vector3 playerPos = playerTr->GetPosition();
			Vector3 grPos = grTr->GetPosition();

			playerPos.x += (fSize - fLen) + 1.0f;
			playerTr->SetPosition(playerPos);
		}
	}
	void GroundScript::CheckRightGround(Collider2D* other)
	{
		Player* player = dynamic_cast<Player*>(other->GetOwner());
		if (player == nullptr)
			return;

		RigidBody* rb = other->GetOwner()->GetComponent<RigidBody>();
		Collider2D* playerCol = player->GetComponent<Collider2D>();
		Vector3 playerPos = playerCol->GetPosition();

		Collider2D* groundCol = this->GetOwner()->GetComponent<Collider2D>();
		Vector3 groundPos = groundCol->GetPosition();

		float fLen = fabs(playerPos.x - groundPos.x);
		float fSize = (playerCol->GetScale().x / 2.0f) + (groundCol->GetScale().x / 2.0f);

		if (fLen < fSize)
		{
			Transform* playerTr = player->GetComponent<Transform>();
			Transform* grTr = this->GetOwner()->GetComponent<Transform>();

			Vector3 playerPos = playerTr->GetPosition();
			Vector3 grPos = grTr->GetPosition();

			playerPos.x -= (fSize - fLen) + 1.0f;
			playerTr->SetPosition(playerPos);
		}
	}
	void GroundScript::CheckLadder(Collider2D* other)
	{
		Player* player = dynamic_cast<Player*>(other->GetOwner());
		if (player == nullptr)
			return;

		Transform* playerTr = player->GetComponent<Transform>();
		RigidBody* rb = other->GetOwner()->GetComponent<RigidBody>();
		rb->SetGround(true);
		Collider2D* playerCol = player->GetComponent<Collider2D>();
		Vector3 playerPos = playerCol->GetPosition();

		Collider2D* groundCol = this->GetOwner()->GetComponent<Collider2D>();
		Vector3 groundPos = groundCol->GetPosition();

		playerPos.x = groundPos.x;
		rb->SetVelocity(rb->GetVelocity() * -1);
		playerTr->SetPosition(playerPos);
	}
}