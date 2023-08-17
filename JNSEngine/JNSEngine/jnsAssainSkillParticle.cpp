#include "jnsAssainSkillParticle.h"
#include "jnsParticleSystem.h"
#include "jnsResources.h"
#include "jnsInput.h"

namespace jns
{
	AssainSkillParticle::AssainSkillParticle()
	{
	}
	AssainSkillParticle::~AssainSkillParticle()
	{
	}
	void AssainSkillParticle::Initialize()
	{
		SetName(L"Particle");
		ps = AddComponent<ParticleSystem>();
		std::shared_ptr<Material> material = Resources::Find<Material>(L"SkillParticleMaterial");
		ps->SetMaterial(material);

		GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 1.0f));
		GetComponent<Transform>()->SetScale(Vector3(1500.0f, 1500.0f, 1.0f));

		GameObject::Initialize();
	}
	void AssainSkillParticle::Update()
	{
		if (Input::GetKeyDown(eKeyCode::K))
		{
			cnt++;
		}
		else if (Input::GetKeyDown(eKeyCode::L))
		{
			cnt--;
		}
		else if (Input::GetKeyDown(eKeyCode::X))
		{
			color.x += 0.01f;
		}
		else if (Input::GetKeyDown(eKeyCode::C))
		{
			color.y += 0.01f;
		}
		else if (Input::GetKeyDown(eKeyCode::V))
		{
			color.z += 0.01f;
		}
		else if (Input::GetKeyDown(eKeyCode::B))
		{
			size.x += 0.1f;
			size.y += 0.1f;
		}
		else if (Input::GetKeyDown(eKeyCode::N))
		{
			size.x -= 0.1f;
			size.y -= 0.1f;
		}
		GameObject::Update();
	}
	void AssainSkillParticle::LateUpdate()
	{
		ps->SetCount(cnt);
		GameObject::LateUpdate();
	}
	void AssainSkillParticle::Render()
	{
		GameObject::Render();
	}
}