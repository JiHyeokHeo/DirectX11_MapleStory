#include "jnsPortalScript.h"
#include "CommonSceneInclude.h"
#include "jnsPortal.h"

namespace jns
{
	void PortalScript::Initialize()
	{
		isEnter = false;
	}
	void PortalScript::Update()
	{
	
	}
	void PortalScript::LateUpdate()
	{
		if (isEnter == true)
		{
			Vector3 mSetPos = mPortal->GetsetPlayerPos();
			SceneManager::GetPlayer()->GetComponent<Transform>()->SetPosition(mSetPos);
			switch (mEnter)
			{
			case ePortalEnter::Rutabys:
				SceneManager::LoadScene(L"Rutabys");
				break;
			case ePortalEnter::RutabysMob:
				SceneManager::LoadScene(L"RutabysMob");
				break;
			case ePortalEnter::RutabysBoss:
				SceneManager::LoadScene(L"RutabysBoss");
				break;
			default:
				break;
			}

			isEnter = false;
		}
	}
	void PortalScript::Render()
	{
		
	}
	void PortalScript::OnCollisionEnter(Collider2D* other)
	{
		if (other->GetOwner()->GetName() == L"Player")
		{
			mPortal = dynamic_cast<PortalBase*>(this->GetOwner());
		}
	}
	void PortalScript::OnCollisionStay(Collider2D* other)
	{
		if (Input::GetKeyDown(eKeyCode::UP))
		{
			if (other->GetOwner()->GetName() == L"Player" && mPortal->GetPortalName() == L"RutaMob")
			{
				mEnter = ePortalEnter::RutabysMob;
			}
			else if(other->GetOwner()->GetName() == L"Player" && mPortal->GetPortalName() == L"RutaScene")
			{
				mEnter = ePortalEnter::Rutabys;
			}
			else if (other->GetOwner()->GetName() == L"Player" && mPortal->GetPortalName() == L"RutaBoss")
			{
				mEnter = ePortalEnter::RutabysBoss;
			}

			isEnter = true;
		}
	}
	void PortalScript::OnCollisionExit(Collider2D* other)
	{
	}
}