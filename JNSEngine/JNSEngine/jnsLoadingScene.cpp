#include "jnsLoadingScene.h"
#include "ObjectTemplate.h"
#include "jnsBGInstance.h"

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
		mBGInstance = object::InstantiateBG<BGInstance>(eLayerType::BG, BGInstance::eBGType::CharactorSelect);
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
}