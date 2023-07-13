#include "jnsSelectBG.h"
#include "jnsResources.h"
#include "jnsTransform.h"

namespace jns
{
	SelectBG::SelectBG()
	{
	}
	SelectBG::~SelectBG()
	{
	}
	void SelectBG::Initialize()
	{
		mr = GetComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SelectBGMaterial"));
		mSize = GetComponent<MeshRenderer>()->GetMaterial()->GetTexture()->GetTextureSize();
		tr = GetComponent<Transform>();
		tr->SetPosition(Vector3(0.0f, 0.0f, 5.0f));
		tr->SetScale(Vector3(mSize.x , mSize.y , 1.0f));

		BGBase::Initialize();
	}
	void SelectBG::Update()
	{
		BGBase::Update();
	}
	void SelectBG::LateUpdate()
	{
		BGBase::LateUpdate();
	}
	void SelectBG::Render()
	{
		BGBase::Render();
	}
}