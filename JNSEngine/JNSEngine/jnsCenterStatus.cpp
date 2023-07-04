#include "jnsCenterStatus.h"
#include "CommonUIInclude.h"

namespace jns
{
	CenterStatus::CenterStatus()
	{
	}
	CenterStatus::~CenterStatus()
	{
	}
	void CenterStatus::Initialize()
	{
		mr = GetComponent<MeshRenderer>();
		mr->SetMaterial(Resources::Find<Material>(L"StatusMainBarMaterial"));
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		
		mTextureRatio = GetComponent<MeshRenderer>()->GetMaterial()->GetTexture()->GetTextureRatio();
		tr = GetComponent<Transform>();
		tr->SetPosition(Vector3(0.0f, -1.95f, 4.3f));
		tr->SetScale(Vector3(mTextureRatio * 1.0f, mTextureRatio * 1.0f, 1.0f));

		UIBase::Initialize();
	}
	void CenterStatus::Update()
	{
		UIBase::Update();
	}
	void CenterStatus::LateUpdate()
	{
		UIBase::LateUpdate();
	}
	void CenterStatus::Render()
	{
		UIBase::Render();
	}
}