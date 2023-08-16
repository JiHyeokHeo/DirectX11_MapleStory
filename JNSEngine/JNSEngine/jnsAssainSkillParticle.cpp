#include "jnsAssainSkillParticle.h"
#include "jnsParticleSystem.h"
#include "jnsResources.h"

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
		ParticleSystem* ps = AddComponent<ParticleSystem>();
		std::shared_ptr<Material> material = Resources::Find<Material>(L"SkillParticleMaterial");
		ps->SetMaterial(material);

		GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 1.0f));
		GetComponent<Transform>()->SetScale(Vector3(1500.0f, 1500.0f, 1.0f));

		GameObject::Initialize();
	}
	void AssainSkillParticle::Update()
	{
		GameObject::Update();
	}
	void AssainSkillParticle::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void AssainSkillParticle::Render()
	{
		GameObject::Render();
	}
}