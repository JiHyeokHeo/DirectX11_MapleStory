#include "jnsStartScene4.h"
#include "CommonSceneInclude.h"

namespace jns
{
	StartScene4::StartScene4()
	{
	}
	StartScene4::~StartScene4()
	{
	}
	void StartScene4::Initialize()
	{
		object::InstantiateBG<BGInstance>(eLayerType::BG, BGInstance::eBGType::Start4);
		PlayScene::Initialize();
	}
	void StartScene4::Update()
	{
		PlayScene::Update();
	}
	void StartScene4::LateUpdate()
	{
		PlayScene::LateUpdate();
		//if (Input::GetKeyDown(eKeyCode::P))
		//{
		//	SceneManager::LoadScene(L"StartScene5");
		//}
	}
	void StartScene4::Render()
	{
		PlayScene::Render();
	}
	void StartScene4::OnEnter()
	{
		PlayScene::OnEnter();
	}
	void StartScene4::OnExit()
	{
		PlayScene::OnExit();
	}
}