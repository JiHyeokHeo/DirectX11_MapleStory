#pragma once
#include "..\Engine_Source\jnsScene.h"
#include "jnsPlayScene.h"

namespace jns
{
	class RutabysBossScene : public PlayScene
	{
	public:
		RutabysBossScene();
		virtual ~RutabysBossScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;
	private:
		class Player* player;
		class BloodyQueenScript* mBQscript;
		class AttackReflection* atObj;
	};
}


