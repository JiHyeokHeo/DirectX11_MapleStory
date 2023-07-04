#include "jnsExpMaxBar.h"
#include "CommonUIInclude.h"

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
		tr->SetPosition(Vector3(0.05f, -2.2f, 4.0f));
		tr->SetScale(Vector3(7.95f, 0.05f, 1.0f));

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