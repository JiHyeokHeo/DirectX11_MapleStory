#pragma once
#include "jnsGameObject.h"

namespace jns
{
	class AssainSkillParticle : public GameObject
	{
	public:
		AssainSkillParticle();
		~AssainSkillParticle();


		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;


	private:
	};

}
