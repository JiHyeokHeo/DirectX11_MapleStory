#include "jnsGround.h"
#include "CommonSceneInclude.h"

namespace jns
{
	Ground::Ground()
	{
	}
	Ground::Ground(const std::wstring name)
		: mGroundName(name)
	{
	}
	Ground::~Ground()
	{
	}
	void Ground::Initialize()
	{
		SetName(L"Ground");
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"DebugMaterial"));
		Collider2D* cd = AddComponent<Collider2D>();
		AddComponent<GroundScript>();
	}
	void Ground::Update()
	{
		GameObject::Update();
	}
	void Ground::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Ground::Render()
	{
		GameObject::Render();
	}
}