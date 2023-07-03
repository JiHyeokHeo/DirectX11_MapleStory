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
		tr = GetComponent<Transform>();
		tr->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
		tr->SetScale(Vector3(4.5f, 4.5f, 1.0f));

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