#include "jnsRutabysMobScene.h"
#include "CommonSceneInclude.h"

namespace jns
{
	RutabysMobScene::RutabysMobScene()
	{
	}
	RutabysMobScene::~RutabysMobScene()
	{
	}
	void RutabysMobScene::Initialize()
	{
		object::InstantiateBG<BGInstance>(eLayerType::BG, BGInstance::eBGType::RutabysQueenMob1);
		GameObject* rutaMovingBG = object::InstantiateBG<BGInstance>(eLayerType::BG, BGInstance::eBGType::RutabysQueenMob2);
		
		
		object::Instantiate<Ground>(eLayerType::Ground, Vector3(0.0f, -300.0f, 4.0f), Vector3(5000.0f, 110.0f, 1.0f));

		CreatePlayerUI();
		PlayScene::Initialize();
	}
	void RutabysMobScene::Update()
	{
		PlayScene::Update();
	}
	void RutabysMobScene::LateUpdate()
	{
		PlayScene::LateUpdate();
		if (Input::GetKeyDown(eKeyCode::P))
		{
			SceneManager::LoadScene(L"RutabysBoss");
		}
	}
	void RutabysMobScene::Render()
	{
		PlayScene::Render();
	}
	void RutabysMobScene::OnEnter()
	{
		PlayScene::OnEnter();
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Item, true);
		CollisionManager::SetLayer(eLayerType::Cursor, eLayerType::Item, true);
		CollisionManager::SetLayer(eLayerType::Cursor, eLayerType::UI, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Cursor, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, true);
	}
	void RutabysMobScene::OnExit()
	{
		PlayScene::OnExit();
	}
}