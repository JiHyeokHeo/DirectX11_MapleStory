#include "jnsBGInstance.h"
#include "jnsResources.h"
#include "jnsTransform.h"
#include "CommonSceneInclude.h"
#include "jnsScene.h"

namespace jns
{
	bool BGInstance::isBGPlayed = false;
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
		as = AddComponent<AudioSource>();
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
				as->SetClip(Resources::Find<AudioClip>(L"RutaBysMain"));
				break;
			case eBGType::RutabysQueenBoss:
				mr->SetMaterial(Resources::Find<Material>(L"RutabysBossBGMaterial"));
				mSize = GetComponent<MeshRenderer>()->GetMaterial()->GetTexture()->GetTextureSize();
				tr->SetPosition(Vector3(0.0f, 100.0f, 5.0f));
				as->SetClip(Resources::Find<AudioClip>(L"QueenPalace"));
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
				as->SetClip(Resources::Find<AudioClip>(L"QueenPalace"));
				tr->SetScale(Vector3(mSize.x * 1.3f, mSize.y * 1.3f, 1.0f));
				break;
			case eBGType::RutabysQueenMob2:
				mr->SetMaterial(Resources::Find<Material>(L"Rutabysqueen2Material"));
				mSize = GetComponent<MeshRenderer>()->GetMaterial()->GetTexture()->GetTextureSize();
				tr->SetPosition(Vector3(0.0f, 0.0f, 5.0f));
				tr->SetScale(Vector3(mSize.x * 1.3f, mSize.y * 1.3f, 1.0f));
				break;
			case eBGType::RutabysPierreMob1:
				mr->SetMaterial(Resources::Find<Material>(L"Rutabypierre1Material"));
				mSize = GetComponent<MeshRenderer>()->GetMaterial()->GetTexture()->GetTextureSize();
				tr->SetPosition(Vector3(0.0f, 0.0f, 5.0f));
				tr->SetScale(Vector3(mSize.x * 1.3f, mSize.y * 1.3f, 1.0f));
				break;
			case eBGType::RutabysPierreMob2:
				mr->SetMaterial(Resources::Find<Material>(L"Rutabypierre2Material"));
				mSize = GetComponent<MeshRenderer>()->GetMaterial()->GetTexture()->GetTextureSize();
				tr->SetPosition(Vector3(0.0f, 0.0f, 5.0f));
				tr->SetScale(Vector3(mSize.x * 1.3f, mSize.y * 1.3f, 1.0f));
				break;
			case eBGType::RutabysPierreBoss:
				mr->SetMaterial(Resources::Find<Material>(L"Rutabypierre3Material"));
				mSize = GetComponent<MeshRenderer>()->GetMaterial()->GetTexture()->GetTextureSize();
				tr->SetPosition(Vector3(0.0f, 0.0f, 5.0f));
				tr->SetScale(Vector3(mSize.x * 1.3f, mSize.y * 1.3f, 1.0f));
				break;
		}
		
		mr->GetMaterial()->SetShader(Resources::Find<Shader>(L"DarkShader"));
		BGBase::Initialize();
	}
	void BGInstance::Update()
	{
		if (mBGtype == eBGType::RutabysQueenMob1 || mBGtype == eBGType::RutabysPierreMob1)
		{
			Vector3 mPos = tr->GetPosition();
			Vector3 mPlayerPos = SceneManager::GetPlayer()->GetComponent<Transform>()->GetPosition();
			mPos.x = mPlayerPos.x * 0.1f;
			
			tr->SetPosition(mPos);
		}

		if (mPrevScene != SceneManager::GetActiveScene())
		{
			isBGPlayed = false;
			as->Stop();
		}

		if (isBGPlayed == false)
		{
			switch (mBGtype)
			{
			case jns::BGInstance::eBGType::Login:
				as->Play();
				break;
			case jns::BGInstance::eBGType::WorldSelect:
				as->Play();
				break;
			case jns::BGInstance::eBGType::CharactorSelect:
				as->Play();
				break;
			case jns::BGInstance::eBGType::CharactorMake:
				as->Play();
				break;
			case jns::BGInstance::eBGType::Start1:
				as->Play();
				break;
			case jns::BGInstance::eBGType::Start2:
				as->Play();
				break;
			case jns::BGInstance::eBGType::Start3:
				as->Play();
				break;
			case jns::BGInstance::eBGType::Start4:
				as->Play();
				break;
			case jns::BGInstance::eBGType::Start5:
				as->Play();
				break;
			case jns::BGInstance::eBGType::RutabysMain:
				as->Play();
				break;
			case jns::BGInstance::eBGType::RutabysQueenMob1:
				as->Play();
				break;
			case jns::BGInstance::eBGType::RutabysQueenMob2:
				as->Play();
				break;
			case jns::BGInstance::eBGType::RutabysQueenBoss:
				as->Play();
				break;
			case jns::BGInstance::eBGType::None:
				break;
			default:
				break;
			}
			isBGPlayed = true;
			as->SetMute(true);
		}

		mPrevScene = SceneManager::GetActiveScene();
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