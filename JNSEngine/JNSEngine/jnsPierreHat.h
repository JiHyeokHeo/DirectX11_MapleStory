#pragma once
#include "jnsMonsterBase.h"

namespace jns
{
	class PierreHat : public GameObject
	{
	public:
		PierreHat();
		~PierreHat();
		
		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:
		class Animator* at;
	};
}
