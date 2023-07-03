#include "jnsRutabysBossScene.h"
#include "jnsTransform.h"
#include "jnsCamera.h"
#include "jnsCameraScript.h"
#include "jnsInput.h"
#include "jnsSceneManager.h"
#include "jnsRutabysBossBG.h"
#include "jnsResources.h"

namespace jns
{
	RutabysBossScene::RutabysBossScene()
	{
	}
	RutabysBossScene::~RutabysBossScene()
	{
	}
	void RutabysBossScene::Initialize()
	{
		RutabysBossBG* rutabysBossBG = new RutabysBossBG();
		AddGameObject(eLayerType::BG, rutabysBossBG);
		rutabysBossBG->Initialize();

		PlayScene::Initialize();
	}
	void RutabysBossScene::Update()
	{
		PlayScene::Update();
	}
	void RutabysBossScene::LateUpdate()
	{
		PlayScene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::P))
		{
			SceneManager::LoadScene(L"Login");
		}
	}
	void RutabysBossScene::Render()
	{
		PlayScene::Render();
	}
}