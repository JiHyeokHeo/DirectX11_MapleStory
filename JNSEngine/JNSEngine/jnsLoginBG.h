#pragma once
#include "jnsBGBase.h"

namespace jns
{
	class LoginBG : public BGBase
	{
	public:
		LoginBG();
		virtual ~LoginBG();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:

	};
}

