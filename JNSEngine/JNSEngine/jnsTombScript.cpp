#include "jnsTombScript.h"
#include "jnsTomb.h"
#include "jnsGround.h"

namespace jns
{
	void TombScript::OnCollisionEnter(Collider2D* other)
	{
		//Ground* ground = dynamic_cast<Ground*>(other->GetOwner());

		//if (ground == nullptr)
		//	return;
		//if (ground->GetGroundName() != L"DownGround")
		//	return;

		//Collider2D* tombCol = GetOwner()->GetComponent<Collider2D>();
		//Vector3 tombPos = tombCol->GetPosition();

		//Collider2D* groundCol = ground->GetComponent<Collider2D>();
		//Vector3 groundPos = groundCol->GetPosition();

		//float fLen = fabs(tombPos.x - groundPos.x);
		//float fSize = (tombCol->GetScale().x / 2.0f) + (groundCol->GetScale().x / 2.0f);

		//if (fLen < fSize)
		//{
		//	Transform* playerTr = ground->GetComponent<Transform>();
		//	Transform* grTr = this->GetOwner()->GetComponent<Transform>();

		//	Vector3 playerPos = playerTr->GetPosition();
		//	Vector3 grPos = grTr->GetPosition();

		//	playerPos.y += (fSize - fLen) - 1.0f;
		//	playerTr->SetPosition(playerPos);
		//}
	}
	void TombScript::OnCollisionStay(Collider2D* other)
	{
		//Ground* ground = dynamic_cast<Ground*>(other->GetOwner());

		//if (ground == nullptr)
		//	return;
		//if (ground->GetGroundName() != L"DownGround")
		//	return;

		//Collider2D* tombCol = GetOwner()->GetComponent<Collider2D>();
		//Vector3 tombPos = tombCol->GetPosition();

		//Collider2D* groundCol = ground->GetComponent<Collider2D>();
		//Vector3 groundPos = groundCol->GetPosition();

		//float fLen = fabs(tombPos.x - groundPos.x);
		//float fSize = (tombCol->GetScale().x / 2.0f) + (groundCol->GetScale().x / 2.0f);

		//if (fLen < fSize)
		//{
		//	Transform* playerTr = ground->GetComponent<Transform>();
		//	Transform* grTr = this->GetOwner()->GetComponent<Transform>();

		//	Vector3 playerPos = playerTr->GetPosition();
		//	Vector3 grPos = grTr->GetPosition();

		//	playerPos.y += (fSize - fLen) - 1.0f;
		//	playerTr->SetPosition(playerPos);
		//}
	}
	void TombScript::OnCollisionExit(Collider2D* other)
	{
	}
}