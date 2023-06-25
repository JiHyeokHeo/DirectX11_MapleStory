#pragma once
#include "jnsScene.h"


namespace jns
{
	class LoginScene : public Scene
	{
	public:
		LoginScene();
		virtual ~LoginScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:

	};
}
