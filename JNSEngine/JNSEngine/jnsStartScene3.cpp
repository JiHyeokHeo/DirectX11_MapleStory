#include "jnsStartScene3.h"
#include "CommonSceneInclude.h"

namespace jns
{
	StartScene3::StartScene3()
	{
	}
	StartScene3::~StartScene3()
	{
	}
	void StartScene3::Initialize()
	{
		object::InstantiateBG<BGInstance>(eLayerType::BG, BGInstance::eBGType::Start3);
		CreatePlayerUI();
		PlayScene::Initialize();
	}
	void StartScene3::Update()
	{
		PlayScene::Update();
	}
	void StartScene3::LateUpdate()
	{
		PlayScene::LateUpdate();
		if (Input::GetKeyDown(eKeyCode::P))
		{
			SceneManager::LoadScene(L"StartScene4");
		}
	}
	void StartScene3::Render()
	{
		PlayScene::Render();
	}
}