#include "jnsCharactorMakeScene.h"
#include "jnsTransform.h"
#include "jnsCamera.h"
#include "jnsCameraScript.h"
#include "jnsInput.h"
#include "jnsSceneManager.h"
#include "jnsCharactorMakeBG.h"

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
		CharactorMakeBG* charactorMakeBG = new CharactorMakeBG();
		AddGameObject(eLayerType::BG, charactorMakeBG);
		charactorMakeBG->Initialize();

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
}