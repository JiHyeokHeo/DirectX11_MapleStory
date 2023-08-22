#include "jnsCharactorMakeScene.h"
#include "CommonSceneInclude.h"

namespace jns
{
	CharactorMakeScene::CharactorMakeScene()
	{
	}
	CharactorMakeScene::~CharactorMakeScene()
	{
	}
	void CharactorMakeScene::Initialize()
	{
		//BG
		mBGInstance = object::InstantiateBG<BGInstance>(eLayerType::BG, BGInstance::eBGType::CharactorMake);

		PlayScene::Initialize();
	}
	void CharactorMakeScene::Update()
	{
		PlayScene::Update();
	}
	void CharactorMakeScene::LateUpdate()
	{
		PlayScene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::P))
		{
			SceneManager::LoadScene(L"Rutabys");
		}
	}
	void CharactorMakeScene::Render()
	{
		PlayScene::Render();
	}
	void CharactorMakeScene::OnEnter()
	{
	}
	void CharactorMakeScene::OnExit()
	{
	}
}