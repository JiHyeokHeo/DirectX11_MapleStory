#pragma once
#include "jnsGameObject.h"

namespace jns
{
	class FontObjects : public GameObject
	{
	public:
		FontObjects(int fontcnt);
		~FontObjects();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:
		int itemfontcnt = 0;
	};
}

