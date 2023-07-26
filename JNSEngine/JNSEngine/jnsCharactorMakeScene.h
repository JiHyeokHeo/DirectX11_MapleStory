#pragma once
#include "..\Engine_Source\jnsScene.h"
#include "jnsPlayScene.h"

namespace jns
{
	class CharactorMakeScene : public PlayScene
	{
	public:
		CharactorMakeScene();
		virtual ~CharactorMakeScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

	private:

	};
}

