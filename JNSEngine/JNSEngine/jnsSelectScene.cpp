#include "jnsSelectScene.h"
#include "jnsTransform.h"
#include "jnsCamera.h"
#include "jnsCameraScript.h"
#include "jnsInput.h"
#include "jnsSceneManager.h"
#include "jnsSelectBG.h"

namespace jns
{
	SelectScene::SelectScene()
	{
	}
	SelectScene::~SelectScene()
	{
	}
	void SelectScene::Initialize()
	{
		SelectBG* selectBG = new SelectBG();
		AddGameObject(eLayerType::BG, selectBG);
		selectBG->Initialize();

		PlayScene::Initialize();
	}
	void SelectScene::Update()
	{
		PlayScene::Update();
	}
	void SelectScene::LateUpdate()
	{
		PlayScene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::P))
		{
			SceneManager::LoadScene(L"CharactorMake");
		}
	}
	void SelectScene::Render()
	{
		PlayScene::Render();
	}
}