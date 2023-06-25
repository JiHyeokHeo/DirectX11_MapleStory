#include "jnsLoginBG.h"
#include "jnsResources.h"
#include "jnsTransform.h"

namespace jns
{
	LoginBG::LoginBG()
	{
	}
	LoginBG::~LoginBG()
	{
	}
	void LoginBG::Initialize()
	{
		mr = GetComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"LoginBGMaterial"));
		tr = GetComponent<Transform>();
		tr->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
		tr->SetScale(Vector3(8.0f, 4.5f, 1.0f));

		BGBase::Initialize();
	}
	void LoginBG::Update()
	{
		BGBase::Update();
	}
	void LoginBG::LateUpdate()
	{
		BGBase::LateUpdate();
	}
	void LoginBG::Render()
	{
		BGBase::Render();
	}
}