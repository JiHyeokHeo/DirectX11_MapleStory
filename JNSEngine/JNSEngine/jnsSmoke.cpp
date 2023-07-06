#include "jnsSmoke.h"
#include "CommonUIInclude.h"
#include "jnstestScript.h"

namespace jns
{
	Smoke::Smoke()
	{
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
		GetComponent<Transform>()->SetPosition(Vector3(2.0f, 0.0f, 4.95f));
		GetComponent<Transform>()->SetRotation(Vector3(0.0f, 0.0f, 0.0f));
		GetComponent<Transform>()->SetScale(Vector3(2.0f, 1.0f, 1.0f));
		AddComponent<testScript>();
		GameObject::Initialize();
	}
	void Smoke::Update()
	{
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