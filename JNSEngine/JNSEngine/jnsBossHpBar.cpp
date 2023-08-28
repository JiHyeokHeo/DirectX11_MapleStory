#include "jnsBossHpBar.h"
#include "CommonSceneInclude.h"

namespace jns
{
	BossHpBar::BossHpBar()
	{
	}
	BossHpBar::~BossHpBar()
	{
	}
	void BossHpBar::Initialize()
	{
		Transform* tr = GetComponent<Transform>();
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"BossHpBarRedMaterial"));
		//mr->GetMaterial()->SetRenderingMode(eRenderingMode::Transparent);
		tr->SetPosition(Vector3(0.0f, 350.0f, -1.0f));
		tr->SetScale(Vector3(1200.0f, 60.0f, 4.0f));
		GameObject::Initialize();
	}
	void BossHpBar::Update()
	{
		GameObject::Update();
	}
	void BossHpBar::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void BossHpBar::Render()
	{
		renderer::PlayerCB playerUICB = {};	
		MonsterBase* monsterBase = dynamic_cast<MonsterBase*>(bossTarget);
		int mBossHp = monsterBase->GetMonsterStatus().hp;

		playerUICB.hp = mBossHp;
		playerUICB.mp = 0;
		playerUICB.exp = 0;
		playerUICB.type = 0;
		ConstantBuffer* cb = renderer::constantBuffer[(UINT)eCBType::Player];

		cb->SetData(&playerUICB);
		cb->Bind(eShaderStage::PS);
		GameObject::Render();
	}
}