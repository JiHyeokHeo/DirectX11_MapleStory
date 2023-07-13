#pragma once
#include "..\\Engine_Source\\jnsGameObject.h"


namespace gui
{
	class DebugObject : public jns::GameObject
	{
	public:
		DebugObject();
		~DebugObject();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:
	};
}