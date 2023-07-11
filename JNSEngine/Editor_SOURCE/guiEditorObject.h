#pragma once
#include "jnsGameObject.h"

namespace gui
{
	class EditorObject : public jns::GameObject
	{
	public:
		EditorObject();
		~EditorObject();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;
		
	};
}
