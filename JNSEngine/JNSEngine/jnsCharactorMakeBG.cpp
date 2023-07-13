#include "jnsCharactorMakeBG.h"
#include "jnsResources.h"
#include "jnsTransform.h"

namespace jns
{
	CharactorMakeBG::CharactorMakeBG()
	{
	}
	CharactorMakeBG::~CharactorMakeBG()
	{
	}
	void CharactorMakeBG::Initialize()
	{
		mr = GetComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"CharactorMakeBGMaterial"));
		mSize = GetComponent<MeshRenderer>()->GetMaterial()->GetTexture()->GetTextureSize();
		tr = GetComponent<Transform>();
		tr->SetPosition(Vector3(0.0f, 0.0f, 5.0f));
		tr->SetScale(Vector3(mSize.x , mSize.y, 1.0f));

		BGBase::Initialize();
	}
	void CharactorMakeBG::Update()
	{
		BGBase::Update();
	}
	void CharactorMakeBG::LateUpdate()
	{
		BGBase::LateUpdate();
	}
	void CharactorMakeBG::Render()
	{
		BGBase::Render();
	}
}