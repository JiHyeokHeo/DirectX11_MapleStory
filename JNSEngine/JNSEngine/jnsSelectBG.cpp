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
		tr = GetComponent<Transform>();
		tr->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
		tr->SetScale(Vector3(8.0f, 4.5f, 0.0f));

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