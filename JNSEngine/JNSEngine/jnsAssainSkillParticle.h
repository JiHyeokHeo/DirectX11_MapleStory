#pragma once
#include "jnsGameObject.h"
#include "jnsParticleSystem.h"
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
		ParticleSystem* ps;
		int cnt = 0;
		Vector4 color;
		Vector2 size;
	};

}
