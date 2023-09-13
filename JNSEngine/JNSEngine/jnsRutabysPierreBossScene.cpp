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
		object::InstantiateGroundCollider<Ground>(L"DownGround", Vector3(0.0f, -550.0f, 4.0f), Vector3(5000.0f, 110.0f, 1.0f));
		object::InstantiateGroundCollider<Ground>(L"LeftGround", Vector3(-1260.0f, -300.0f, 4.0f), Vector3(100.0f, 2500.0f, 1.0f));
		object::InstantiateGroundCollider<Ground>(L"RightGround", Vector3(1260.0f, -300.0f, 4.0f), Vector3(100.0f, 2500.0f, 1.0f));
		
		object::Instantiate<BossHp>(eLayerType::UI, Vector3::Zero);
		BossHpBar* bossHpBar = object::Instantiate<BossHpBar>(eLayerType::UI, Vector3::Zero);

		object::InstantiateAniObjects<BGobject>(jns::enums::eLayerType::BG, BGobject::eBGObjectType::pierreArtficiality1, Vector3(-950.0f, -20.0f, 3.0f));
		object::InstantiateAniObjects<BGobject>(jns::enums::eLayerType::BG, BGobject::eBGObjectType::pierreArtficiality2, Vector3(-380.0f, -220.0f, 3.0f));
		object::InstantiateAniObjects<BGobject>(jns::enums::eLayerType::BG, BGobject::eBGObjectType::pierreArtficiality3, Vector3(350.0f, -220.0f, 3.0f));
		object::InstantiateAniObjects<BGobject>(jns::enums::eLayerType::BG, BGobject::eBGObjectType::pierreArtficiality4, Vector3(970.0f, -20.0f, 3.0f));
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