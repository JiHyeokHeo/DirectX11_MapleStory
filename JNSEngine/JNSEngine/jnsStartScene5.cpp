#include "jnsStartScene5.h"
#include "CommonSceneInclude.h"


namespace jns
{
	StartScene5::StartScene5()
	{
	}
	StartScene5::~StartScene5()
	{
	}
	void StartScene5::Initialize()
	{
		object::InstantiateBG<BGInstance>(eLayerType::BG, BGInstance::eBGType::Start5);
		CreatePlayerUI();
		PlayScene::Initialize();
	}
	void StartScene5::Update()
	{
		PlayScene::Update();
	}
	void StartScene5::LateUpdate()
	{
		PlayScene::LateUpdate();
		//if (Input::GetKeyDown(eKeyCode::P))
		//{
		//	SceneManager::LoadScene(L"Rutabys");
		//}
	}
	void StartScene5::Render()
	{
		PlayScene::Render();
	}
	void StartScene5::OnEnter()
	{
		PlayScene::OnEnter();
	}
	void StartScene5::OnExit()
	{
		PlayScene::OnExit();
	}
}