#include "jnsLoadingScene.h"
#include "ObjectTemplate.h"


namespace jns
{
	LoadingScene::LoadingScene()
	{
	}
	LoadingScene::~LoadingScene()
	{
	}
	void LoadingScene::Initialize()
	{
		//GameObject* rutaMovingBG = object::InstantiateBG<BGInstance>(eLayerType::BG, BGInstance::eBGType::RutabysPierreMob2);
		PlayScene::Initialize();
	}
	void LoadingScene::Update()
	{
		PlayScene::Update();
	}
	void LoadingScene::LateUpdate()
	{
		PlayScene::LateUpdate();
	}
	void LoadingScene::Render()
	{
		PlayScene::Render();
	}
	void LoadingScene::OnEnter()
	{
	}
	void LoadingScene::OnExit()
	{
	}
}