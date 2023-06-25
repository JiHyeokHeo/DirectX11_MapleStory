#include "jnsRootAbyssMain.h"
#include "jnsResources.h"
#include "jnsTransform.h"

namespace jns
{
	RootAbyssMain::RootAbyssMain()
	{
	}
	RootAbyssMain::~RootAbyssMain()
	{
	}
	void RootAbyssMain::Initialize()
	{
		mr = GetComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"RutabysMainMaterial"));
		tr = GetComponent<Transform>();
		tr->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
		//tr->SetScale(Vector3(8.0f, 5.0f, 0.0f));

		BGBase::Initialize();
	}
	void RootAbyssMain::Update()
	{
		BGBase::Update();
	}
	void RootAbyssMain::LateUpdate()
	{
		BGBase::LateUpdate();
	}
	void RootAbyssMain::Render()
	{
		BGBase::Render();
	}
}