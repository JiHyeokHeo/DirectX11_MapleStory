#include "jnsStartScene.h"
#include "CommonSceneInclude.h"

namespace jns
{
	StartScene::StartScene()
	{
	}
	StartScene::~StartScene()
	{
	}
	void StartScene::Initialize()
	{
		object::InstantiateBG<BGInstance>(eLayerType::BG, BGInstance::eBGType::Start1);
		PlayScene::Initialize();
	}
	void StartScene::Update()
	{
		PlayScene::Update();
	}
	void StartScene::LateUpdate()
	{
		PlayScene::LateUpdate();
	}
	void StartScene::Render()
	{
		PlayScene::Render();
	}
}