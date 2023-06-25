#pragma once
#include "jnsBGBase.h"

namespace jns
{
	class WorldSelectBG : public BGBase
	{
	public:
		WorldSelectBG();
		virtual ~WorldSelectBG();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:

	};
}


