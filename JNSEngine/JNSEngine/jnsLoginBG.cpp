#include "jnsLoginBG.h"
#include "jnsResources.h"
#include "jnsTransform.h"

namespace jns
{
	LoginBG::LoginBG()
	{
	}
	LoginBG::~LoginBG()
	{
	}
	void LoginBG::Initialize()
	{
		mr = GetComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"LoginBGMaterial"));
		mSize = GetComponent<MeshRenderer>()->GetMaterial()->GetTexture()->GetTextureSize();
		tr = GetComponent<Transform>();
		tr->SetPosition(Vector3(0.0f, 0.0f, 5.0f));
		tr->SetScale(Vector3(mSize.x * 1.0f, mSize.y * 1.0f, 1.0f));

		BGBase::Initialize();
	}
	void LoginBG::Update()
	{
		BGBase::Update();
	}
	void LoginBG::LateUpdate()
	{
		BGBase::LateUpdate();
	}
	void LoginBG::Render()
	{
		BGBase::Render();
	}
}