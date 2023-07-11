#pragma once
#include "..\Engine_Source\jnsScene.h"


namespace jns
{
	class Camera;
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		virtual ~PlayScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	

	protected:
		void CreateMainCamera();
		void CreateUICamera();
		void CreatePlayerUI();
		void CreateCursor();
		void CreateInventory();
		void SetTarget(GameObject* target) { followtarget = target; }
	
	private:
		GameObject* followtarget;
		Camera* maincameraComp;
	};
}
