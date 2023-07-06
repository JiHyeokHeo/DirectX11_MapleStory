#include "jnsRutabysMain.h"
#include "jnsResources.h"
#include "jnsTransform.h"
#include "jnsTexture.h"

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
		mSize = GetComponent<MeshRenderer>()->GetMaterial()->GetTexture()->GetTextureSize();
		tr = GetComponent<Transform>();
		tr->SetPosition(Vector3(0.0f, 0.80f, 5.0f));
		tr->SetScale(Vector3(mSize.x / 160, mSize.y / 160, 1.0f));

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