#include "jnsRutabysMain.h"
#include "jnsResources.h"
#include "jnsTransform.h"

namespace jns
{
	RutabysMain::RutabysMain()
	{
	}
	RutabysMain::~RutabysMain()
	{
	}
	void RutabysMain::Initialize()
	{
		mr = GetComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"RutabysMainMaterial"));
		tr = GetComponent<Transform>();
		tr->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
		tr->SetScale(Vector3(8.0f, 4.5f, 0.0f));

		BGBase::Initialize();
	}
	void RutabysMain::Update()
	{
		BGBase::Update();
	}
	void RutabysMain::LateUpdate()
	{
		BGBase::LateUpdate();
	}
	void RutabysMain::Render()
	{
		BGBase::Render();
	}
}