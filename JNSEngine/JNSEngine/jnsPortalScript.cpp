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
			Vector3 mSetPos = mPortal->GetDestinationPlayerPos();
			SceneManager::GetPlayer()->GetComponent<Transform>()->SetPosition(mSetPos);
			SceneManager::LoadScene(mEnter);
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
		/*	if (other->GetOwner()->GetName() == L"Player" && mPortal->GetDestinationSceneType() == jns::enums::eSceneType::RutabysMob)
			{
				mEnter = mPortal->GetDestinationSceneType();
			}
			else if(other->GetOwner()->GetName() == L"Player" && mPortal->GetDestinationSceneType() == jns::enums::eSceneType::RutabysMain)
			{
				mEnter = mPortal->GetDestinationSceneType();
			}
			else if (other->GetOwner()->GetName() == L"Player" && mPortal->GetDestinationSceneType() == jns::enums::eSceneType::RutabysBoss)
			{
				mEnter = mPortal->GetDestinationSceneType();
			}
			else if (other->GetOwner()->GetName() == L"Player" && mPortal->GetDestinationSceneType() == jns::enums::eSceneType::RutabysPierreMob)
			{
				mEnter = mPortal->GetDestinationSceneType();
			}
			else if (other->GetOwner()->GetName() == L"Player" && mPortal->GetDestinationSceneType() == jns::enums::eSceneType::RutabysPierreBoss)
			{
				mEnter = mPortal->GetDestinationSceneType();
			}*/
			mEnter = mPortal->GetDestinationSceneType();
			isEnter = true;
		}
	}
	void PortalScript::OnCollisionExit(Collider2D* other)
	{
	}
}