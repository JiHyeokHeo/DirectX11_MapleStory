#include "jnsStartScene2.h"
#include "CommonSceneInclude.h"

namespace jns
{
	StartScene2::StartScene2()
	{
	}
	StartScene2::~StartScene2()
	{
	}
	void StartScene2::Initialize()
	{
		object::InstantiateBG<BGInstance>(eLayerType::BG, BGInstance::eBGType::Start2);
		PlayScene::Initialize();
	}
	void StartScene2::Update()
	{
		PlayScene::Update();
	}
	void StartScene2::LateUpdate()
	{
		PlayScene::LateUpdate();
		//if (Input::GetKeyDown(eKeyCode::P))
		//{
		//	SceneManager::LoadScene(L"StartScene3");
		//}
	}
	void StartScene2::Render()
	{
		PlayScene::Render();
	}
	void StartScene2::OnEnter()
	{
		PlayScene::OnEnter();
	}
	void StartScene2::OnExit()
	{
		PlayScene::OnExit();
	}
}