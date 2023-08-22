#include "jnsDarkPaper.h"
#include "CommonSceneInclude.h"

namespace jns
{
	DarkPaper::DarkPaper()
	{
	}
	DarkPaper::~DarkPaper()
	{
	}
	void DarkPaper::Initialize()
	{
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		Transform* tr = GetComponent<Transform>();
		tr->SetScale(Vector3(600.0f, 600.0f, 1.0f));
		tr->SetPosition(Vector3(-150.0f, -320.0f, -0.5f));
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"DarkMaterial"));
	}
	void DarkPaper::Update()
	{
		GameObject::Update();
	}
	void DarkPaper::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void DarkPaper::Render()
	{
		GameObject::Render();
	}
}