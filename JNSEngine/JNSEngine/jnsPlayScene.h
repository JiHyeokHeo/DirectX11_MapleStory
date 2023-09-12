#pragma once
#include "..\Engine_Source\jnsScene.h"


namespace jns
{
	class CameraObject;
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		virtual ~PlayScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;
		virtual void OnEnter() override;
		virtual void OnExit() override;
	

	protected:
		void CreateMainCamera();
		void CreateUICamera();
		void CreatePlayerUI();
		void CreateCursor();
		void CreateInventory();
		void SetTarget(GameObject* target) { followtarget = target; }
		
		CameraObject* mainCameraObj;
		CameraObject* uiCameraObj;
		GameObject* mBGInstance;
		GameObject* mDirectionalLight;
		GameObject* followtarget;
		
		
	private:
	};
}
