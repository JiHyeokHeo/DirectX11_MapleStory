#pragma once
#include "..\Engine_Source\jnsScene.h"


namespace jns
{
	class WorldSelectScene : public Scene
	{
	public:
		WorldSelectScene();
		virtual ~WorldSelectScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:

	};
}
