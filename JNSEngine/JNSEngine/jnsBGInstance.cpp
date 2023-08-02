#include "jnsBGInstance.h"
#include "jnsResources.h"
#include "jnsTransform.h"
#include "CommonSceneInclude.h"

namespace jns
{
	BGInstance::BGInstance()
	{
	}
	BGInstance::BGInstance(eBGType type)
		:mBGtype(type)
	{
	}
	BGInstance::~BGInstance()
	{
	}
	void BGInstance::Initialize()
	{
		mr = GetComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		tr = GetComponent<Transform>();
		switch(mBGtype)
		{
			case eBGType::Login:
				mr->SetMaterial(Resources::Find<Material>(L"LoginBGMaterial"));
				mSize = GetComponent<MeshRenderer>()->GetMaterial()->GetTexture()->GetTextureSize();
				tr->SetPosition(Vector3(0.0f, 0.0f, 5.0f));
				tr->SetScale(Vector3(mSize.x, mSize.y, 1.0f));
				break;
			case eBGType::WorldSelect:
				mr->SetMaterial(Resources::Find<Material>(L"WorldSelectBGMaterial"));
				mSize = GetComponent<MeshRenderer>()->GetMaterial()->GetTexture()->GetTextureSize();
				tr->SetPosition(Vector3(0.0f, 0.0f, 5.0f));
				tr->SetScale(Vector3(mSize.x, mSize.y, 1.0f));
				break;
			case eBGType::CharactorMake:
				mr->SetMaterial(Resources::Find<Material>(L"CharactorMakeBGMaterial"));
				mSize = GetComponent<MeshRenderer>()->GetMaterial()->GetTexture()->GetTextureSize();
				tr->SetPosition(Vector3(0.0f, 0.0f, 5.0f));
				tr->SetScale(Vector3(mSize.x, mSize.y, 1.0f));
				break;
			case eBGType::RutabysMain:
				mr->SetMaterial(Resources::Find<Material>(L"RutabysMainMaterial"));
				mSize = GetComponent<MeshRenderer>()->GetMaterial()->GetTexture()->GetTextureSize();
				tr->SetPosition(Vector3(0.0f, 100.0f, 5.0f));
				tr->SetScale(Vector3(mSize.x, mSize.y, 1.0f));
				break;
			case eBGType::RutabysQueenBoss:
				mr->SetMaterial(Resources::Find<Material>(L"RutabysBossBGMaterial"));
				mSize = GetComponent<MeshRenderer>()->GetMaterial()->GetTexture()->GetTextureSize();
				tr->SetPosition(Vector3(0.0f, 100.0f, 5.0f));
				tr->SetScale(Vector3(mSize.x * 1.3f, mSize.y * 1.3f, 1.0f));
				break;
			case eBGType::CharactorSelect:
				mr->SetMaterial(Resources::Find<Material>(L"SelectBGMaterial"));
				mSize = GetComponent<MeshRenderer>()->GetMaterial()->GetTexture()->GetTextureSize();
				tr->SetPosition(Vector3(0.0f, 0.0f, 5.0f));
				tr->SetScale(Vector3(mSize.x, mSize.y, 1.0f));
				break;
			case eBGType::Start1:
				mr->SetMaterial(Resources::Find<Material>(L"StartBGMaterial"));
				mSize = GetComponent<MeshRenderer>()->GetMaterial()->GetTexture()->GetTextureSize();
				tr->SetPosition(Vector3(0.0f, 200.0f, 5.0f));
				tr->SetScale(Vector3(mSize.x, mSize.y, 1.0f));
				break;
			case eBGType::Start2:
				mr->SetMaterial(Resources::Find<Material>(L"Start2BGMaterial"));
				mSize = GetComponent<MeshRenderer>()->GetMaterial()->GetTexture()->GetTextureSize();
				tr->SetPosition(Vector3(0.0f, 0.0f, 5.0f));
				tr->SetScale(Vector3(mSize.x, mSize.y, 1.0f));
				break;
			case eBGType::Start3:
				mr->SetMaterial(Resources::Find<Material>(L"Start3BGMaterial"));
				mSize = GetComponent<MeshRenderer>()->GetMaterial()->GetTexture()->GetTextureSize();
				tr->SetPosition(Vector3(0.0f, 100.0f, 5.0f));
				tr->SetScale(Vector3(mSize.x, mSize.y, 1.0f));
				break;
			case eBGType::Start4:
				mr->SetMaterial(Resources::Find<Material>(L"Start4BGMaterial"));
				mSize = GetComponent<MeshRenderer>()->GetMaterial()->GetTexture()->GetTextureSize();
				tr->SetPosition(Vector3(0.0f, 0.0f, 5.0f));
				tr->SetScale(Vector3(mSize.x, mSize.y, 1.0f));
				break;
			case eBGType::Start5:
				mr->SetMaterial(Resources::Find<Material>(L"Start5BGMaterial"));
				mSize = GetComponent<MeshRenderer>()->GetMaterial()->GetTexture()->GetTextureSize();
				tr->SetPosition(Vector3(0.0f, -400.0f, 5.0f));
				tr->SetScale(Vector3(mSize.x * 1.3f, mSize.y * 1.3f, 1.0f));
				break;
			case eBGType::RutabysQueenMob1:
				mr->SetMaterial(Resources::Find<Material>(L"Rutabysqueen1Material"));
				mSize = GetComponent<MeshRenderer>()->GetMaterial()->GetTexture()->GetTextureSize();
				tr->SetPosition(Vector3(0.0f, 0.0f, 5.0f));
				tr->SetScale(Vector3(mSize.x * 1.3f, mSize.y * 1.3f, 1.0f));
				break;
			case eBGType::RutabysQueenMob2:
				mr->SetMaterial(Resources::Find<Material>(L"Rutabysqueen2Material"));
				mSize = GetComponent<MeshRenderer>()->GetMaterial()->GetTexture()->GetTextureSize();
				tr->SetPosition(Vector3(0.0f, 0.0f, 4.9f));
				tr->SetScale(Vector3(mSize.x * 1.3f, mSize.y * 1.3f, 1.0f));
				break;
		}


		BGBase::Initialize();
	}
	void BGInstance::Update()
	{
		if (mBGtype == eBGType::RutabysQueenMob1)
		{
			Vector3 mPos = tr->GetPosition();
			Vector3 mPlayerPos = SceneManager::GetPlayer()->GetComponent<Transform>()->GetPosition();
			
			mPos.x = mPlayerPos.x * 0.1f;
			
			tr->SetPosition(mPos);
		}
		BGBase::Update();
	}
	void BGInstance::LateUpdate()
	{
		BGBase::LateUpdate();
	}
	void BGInstance::Render()
	{
		BGBase::Render();
	}
}