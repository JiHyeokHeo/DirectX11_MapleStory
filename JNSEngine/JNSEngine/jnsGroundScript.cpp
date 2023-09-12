#include "jnsGroundScript.h"
#include "CommonSceneInclude.h"
#include "jnsTomb.h"

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

		if (mGround->GetGroundName() == L"DownJumpGround")
			CheckDownJumpGround(other);

		if (mGround->GetGroundName() == L"LeftGround")
			CheckLeftGround(other);

		if (mGround->GetGroundName() == L"RightGround")
			CheckRightGround(other);

	}
	void GroundScript::OnCollisionStay(Collider2D* other)
	{
		if (mGround->GetGroundName() == L"LeftGround")
			CheckLeftGround(other);

		//if (mGround->GetGroundName() == L"DownJumpGround")
		//	CheckDownJumpGround(other);

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

			if (player->GetComponent<PlayerScript>()->GetPlayerState() != PlayerScript::ePlayerState::Die)
			{
				RigidBody* rb = other->GetOwner()->GetComponent<RigidBody>();
				rb->SetGround(false);
			}
		}

		if (mGround->GetGroundName() == L"DownJumpGround")
		{
			Player* player = dynamic_cast<Player*>(other->GetOwner());
			if (player == nullptr)
				return;

			Collider2D* playerCol = player->GetComponent<Collider2D>();
			Vector3 playerPos = playerCol->GetPosition();

			Collider2D* groundCol = this->GetOwner()->GetComponent<Collider2D>();
			Vector3 groundPos = groundCol->GetPosition();

			
			if (player->GetComponent<PlayerScript>()->GetPlayerState() != PlayerScript::ePlayerState::Die)
			{
				RigidBody* rb = other->GetOwner()->GetComponent<RigidBody>();
				float size = groundCol->GetScale().x / 2;
				if (playerPos.x >= groundPos.x + size || playerPos.x <= groundPos.x - size )
				{
					if(playerPos.y >= groundPos.y)	
						rb->SetGround(false);
				}
			}
		}

		if (mGround->GetGroundName() == L"Ladder")
		{
			RigidBody* rb = other->GetOwner()->GetComponent<RigidBody>();
		}
	}



	void GroundScript::CheckDownGround(Collider2D* other)
	{
		if (other->GetOwner()->GetName() == L"Player")
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

		
		if (other->GetOwner()->GetName() == L"Tomb")
		{
			Tomb* tomb = dynamic_cast<Tomb*>(other->GetOwner());
			if (mGround->GetGroundName() == L"DownGround")
			{
				Collider2D* tombCol = tomb->GetComponent<Collider2D>();
				Vector3 tombPos = tombCol->GetPosition();

				Collider2D* groundCol = this->GetOwner()->GetComponent<Collider2D>();
				Vector3 groundPos = groundCol->GetPosition();

				float fLen = fabs(tombPos.y - groundPos.y);
				float fSize = (tombCol->GetScale().y / 2.0f) + (groundCol->GetScale().y / 2.0f);

				if (fLen < fSize)
				{
					Transform* tombTr = tomb->GetComponent<Transform>();
					Transform* grTr = this->GetOwner()->GetComponent<Transform>();

					Vector3 tombPos = tombTr->GetPosition();
					Vector3 grPos = grTr->GetPosition();

					tombPos.y += (fSize - fLen) - 1.0f;
					tombTr->SetPosition(tombPos);
					tomb->SetIsDone(true);
				}
			}
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
	void GroundScript::CheckDownJumpGround(Collider2D* other)
	{
		if (other->GetOwner()->GetName() == L"Player")
		{
			Player* player = dynamic_cast<Player*>(other->GetOwner());
			if (player == nullptr)
				return;
			PlayerScript* playerScript = player->GetComponent<PlayerScript>();
			RigidBody* rb = other->GetOwner()->GetComponent<RigidBody>();
			Collider2D* playerCol = player->GetComponent<Collider2D>();
			Vector3 playerPos = playerCol->GetPosition();

			Collider2D* groundCol = this->GetOwner()->GetComponent<Collider2D>();
			Vector3 groundPos = groundCol->GetPosition();

			float fLen = fabs(playerPos.y - groundPos.y);
			float fSize = (playerCol->GetScale().y / 2.0f) + (groundCol->GetScale().y / 2.0f);

			PlayerScript::ePlayerState playerState = playerScript->GetPlayerState();
			if (fLen < fSize)
			{
				Transform* playerTr = player->GetComponent<Transform>();
				Transform* grTr = this->GetOwner()->GetComponent<Transform>();

				Vector3 playerPos = playerTr->GetPosition();
				Vector3 grPos = grTr->GetPosition();
				float playeryhalftsize = playerCol->GetScale().y / 2.0f;
				float groundyhalftsize = groundCol->GetScale().y / 2.0f;
				float playerxhalftsize = playerCol->GetScale().y / 2.0f;
				float groundxhalftsize = groundCol->GetScale().y / 2.0f;
				if (playerPos.y - playeryhalftsize >= (groundPos.y + groundyhalftsize) - 1.0f)
				{
					rb->SetGround(true);
				}
				
			}
		}


		if (other->GetOwner()->GetName() == L"Tomb")
		{
			Tomb* tomb = dynamic_cast<Tomb*>(other->GetOwner());
			if (mGround->GetGroundName() == L"DownGround")
			{
				Collider2D* tombCol = tomb->GetComponent<Collider2D>();
				Vector3 tombPos = tombCol->GetPosition();

				Collider2D* groundCol = this->GetOwner()->GetComponent<Collider2D>();
				Vector3 groundPos = groundCol->GetPosition();

				float fLen = fabs(tombPos.y - groundPos.y);
				float fSize = (tombCol->GetScale().y / 2.0f) + (groundCol->GetScale().y / 2.0f);

				if (fLen < fSize)
				{
					Transform* tombTr = tomb->GetComponent<Transform>();
					Transform* grTr = this->GetOwner()->GetComponent<Transform>();

					Vector3 tombPos = tombTr->GetPosition();
					Vector3 grPos = grTr->GetPosition();

					tombPos.y += (fSize - fLen) - 1.0f;
					tombTr->SetPosition(tombPos);
					tomb->SetIsDone(true);
				}
			}
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