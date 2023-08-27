#include "jnsBossHp.h"
#include "CommonSceneInclude.h"

namespace jns
{
	BossHp::BossHp()
	{
	}
	BossHp::~BossHp()
	{
	}
	void BossHp::Initialize()
	{
		Transform* tr = GetComponent<Transform>();
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"BossHpBarMaterial"));
		mr->GetMaterial()->SetRenderingMode(eRenderingMode::Opaque);
		tr->SetPosition(Vector3(0.0f, 350.0f, -0.9f));
		tr->SetScale(Vector3(1200.0f, 60.0f, 4.0f));
		GameObject::Initialize();
	}
	void BossHp::Update()
	{

		GameObject::Update();
	}
	void BossHp::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void BossHp::Render()
	{
		////renderer::PlayerCB playerUICB = {};
		////int mHp = mPlayerHp;
		////int mMp = mPlayerMp;
		////int mExp = mPlayerExp;

		//playerUICB.hp = mHp;
		//playerUICB.mp = mMp;
		//playerUICB.exp = mExp;
		//playerUICB.type = 0;
		//ConstantBuffer* cb = renderer::constantBuffer[(UINT)eCBType::Player];

		//cb->SetData(&playerUICB);
		//cb->Bind(eShaderStage::PS);
		GameObject::Render();
	}
}