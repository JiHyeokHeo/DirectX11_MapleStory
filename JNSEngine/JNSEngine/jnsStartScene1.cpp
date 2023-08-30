#include "jnsStartScene1.h"
#include "CommonSceneInclude.h"

namespace jns
{
	StartScene1::StartScene1()
	{
	}
	StartScene1::~StartScene1()
	{
	}
	void StartScene1::Initialize()
	{
		mBGInstance = object::InstantiateBG<BGInstance>(eLayerType::BG, BGInstance::eBGType::Start1);
		CreatePlayerUI();
		PlayScene::Initialize();
	}
	void StartScene1::Update()
	{
		PlayScene::Update();
	}
	void StartScene1::LateUpdate()
	{
		PlayScene::LateUpdate();
		//if (Input::GetKeyDown(eKeyCode::P))
		//{
		//	SceneManager::LoadScene(L"StartScene2");
		//}
	}
	void StartScene1::Render()
	{
		PlayScene::Render();
	}
	void StartScene1::OnEnter()
	{
		PlayScene::OnEnter();
	}
	void StartScene1::OnExit()
	{
		PlayScene::OnExit();
	}
}