#include "jnsRutabysPierreBossScene.h"
#include "CommonSceneInclude.h"
#include "jnsBossHp.h"
#include "jnsBossHpBar.h"
namespace jns
{
	RutabysPierreBossScene::RutabysPierreBossScene()
	{
	}
	RutabysPierreBossScene::~RutabysPierreBossScene()
	{
	}
	void RutabysPierreBossScene::Initialize()
	{
		mBGInstance = object::InstantiateBG<BGInstance>(eLayerType::BG, BGInstance::eBGType::RutabysPierreBoss);
		object::InstantiateGroundCollider<Ground>(L"DownGround", Vector3(0.0f, -450.0f, 4.0f), Vector3(5000.0f, 110.0f, 1.0f));
		object::InstantiateGroundCollider<Ground>(L"LeftGround", Vector3(-1250.0f, -300.0f, 4.0f), Vector3(100.0f, 2500.0f, 1.0f));
		object::InstantiateGroundCollider<Ground>(L"RightGround", Vector3(1250.0f, -300.0f, 4.0f), Vector3(100.0f, 2500.0f, 1.0f));
		
		object::Instantiate<BossHp>(eLayerType::UI, Vector3::Zero);
		BossHpBar* bossHpBar = object::Instantiate<BossHpBar>(eLayerType::UI, Vector3::Zero);
		// 피에르랑 연결 시켜야함
		//bossHpBar->SetBossTarget(obj);
		PlayScene::Initialize();
	}
	void RutabysPierreBossScene::Update()
	{
		PlayScene::Update();
	}
	void RutabysPierreBossScene::LateUpdate()
	{
		PlayScene::LateUpdate();
	}
	void RutabysPierreBossScene::Render()
	{
		PlayScene::Render();
	}
	void RutabysPierreBossScene::OnEnter()
	{
		PlayScene::OnEnter();
	}
	void RutabysPierreBossScene::OnExit()
	{
		PlayScene::OnExit();
	}
}