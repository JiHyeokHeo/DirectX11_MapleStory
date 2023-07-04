#include "jnsExpBar.h"
#include "CommonUIInclude.h"

namespace jns
{
	ExpBar::ExpBar()
	{
	}
	ExpBar::~ExpBar()
	{
	}
	void ExpBar::Initialize()
	{
		mr = GetComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"ExpBarUIMaterial"));
		
		//mSize = GetComponent<MeshRenderer>()->GetMaterial()->GetTexture()->GetTextureSize();
		tr = GetComponent<Transform>();
		tr->SetPosition(Vector3(0.0f, -2.2f, 4.5f));
		tr->SetScale(Vector3(7.95f, 0.05f, 1.0f));

		UIBase::Initialize();
	}
	void ExpBar::Update()
	{
		UIBase::Update();
	}
	void ExpBar::LateUpdate()
	{
		UIBase::LateUpdate();
	}
	void ExpBar::Render()
	{
		UIBase::Render();
	}
}