#include "jnsWorldSelectBG.h"
#include "jnsResources.h"
#include "jnsTransform.h"

namespace jns
{
	WorldSelectBG::WorldSelectBG()
	{
	}
	WorldSelectBG::~WorldSelectBG()
	{
	}
	void WorldSelectBG::Initialize()
	{
		mr = GetComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"WorldSelectBGMaterial"));
		mSize = GetComponent<MeshRenderer>()->GetMaterial()->GetTexture()->GetTextureSize();
		tr = GetComponent<Transform>();
		tr->SetPosition(Vector3(0.0f, 0.0f, 5.0f));
		tr->SetScale(Vector3(mSize.x , mSize.y , 1.0f));

		BGBase::Initialize();
	}
	void WorldSelectBG::Update()
	{
		BGBase::Update();
	}
	void WorldSelectBG::LateUpdate()
	{
		BGBase::LateUpdate();
	}
	void WorldSelectBG::Render()
	{
		BGBase::Render();
	}
}