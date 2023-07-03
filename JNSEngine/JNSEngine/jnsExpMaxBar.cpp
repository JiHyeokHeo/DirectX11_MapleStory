#include "jnsExpMaxBar.h"
#include "jnsResources.h"
#include "jnsTransform.h"

namespace jns
{
	ExpMaxBar::ExpMaxBar()
	{
	}
	ExpMaxBar::~ExpMaxBar()
	{
	}
	void ExpMaxBar::Initialize()
	{
		mr = GetComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"ExpMaxBarMaterial"));
		tr = GetComponent<Transform>();
		tr->SetPosition(Vector3(0.0f, -2.2f, 4.0f));
		tr->SetScale(Vector3(8.0f, 0.05f, 1.0f));

		UIBase::Initialize();
	}
	void ExpMaxBar::Update()
	{
		UIBase::Update();
	}
	void ExpMaxBar::LateUpdate()
	{
		UIBase::LateUpdate();
	}
	void ExpMaxBar::Render()
	{
		UIBase::Render();
	}
}