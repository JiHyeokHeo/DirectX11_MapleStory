#include "jnsSmoke.h"
#include "CommonUIInclude.h"
#include "jnstestScript.h"
#include "jnsTime.h"

namespace jns
{
	Smoke::Smoke()
		:mTime(0.0f)
	{
		tr = GetComponent<Transform>();
		mr = AddComponent<MeshRenderer>();
	}
	Smoke::Smoke(Vector3 mPos)
	{

	}
	Smoke::~Smoke()
	{
	}
	void Smoke::Initialize()
	{
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"Mist01Material"));
		Vector2 mSize = GetComponent<MeshRenderer>()->GetMaterial()->GetTexture()->GetTextureSize();
		tr->SetScale(mSize.x, mSize.y, 1.0f);
		//AddComponent<testScript>();
		GameObject::Initialize();
	
	}
	void Smoke::Update()
	{
		mPos = tr->GetPosition();
		if (mPos.x <= -1600.0f)
		{
			mPos.x = 1600.0f;
		}

		mPos.x -= 155.5f * Time::DeltaTime();
		
		tr->SetPosition(mPos.x, mPos.y, mPos.z);
		GameObject::Update();
	}
	void Smoke::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Smoke::Render()
	{
		GameObject::Render();
	}
}