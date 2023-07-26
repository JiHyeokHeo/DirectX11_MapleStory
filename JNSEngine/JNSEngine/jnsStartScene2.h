#pragma once
#include "..\Engine_Source\jnsScene.h"
#include "jnsPlayScene.h"

namespace jns
{
	class StartScene2 : public PlayScene
	{
	public:
		StartScene2();
		virtual ~StartScene2();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;
		virtual void OnEnter() override;
		virtual void OnExit() override;
	private:

	};
}

