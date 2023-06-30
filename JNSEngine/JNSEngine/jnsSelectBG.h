#pragma once
#include "jnsBGBase.h"

namespace jns
{
	class SelectBG : public BGBase
	{
	public:
		SelectBG();
		virtual ~SelectBG();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:

	};
}


