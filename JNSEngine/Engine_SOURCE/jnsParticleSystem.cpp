#include "jnsParticleSystem.h"
#include "jnsMesh.h"
#include "jnsMaterial.h"
#include "jnsResources.h"
#include "jnsTransform.h"
#include "jnsGameObject.h"
#include "jnsTime.h"
#include <random>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> dis(1, 1000);

namespace jns
{
	ParticleSystem::ParticleSystem()
		: mCount(2)
		, mStartSize(Vector4::One)
		, mEndSize(Vector4::One)
		, mStartColor(Vector4::Zero)
		, mEndColor(Vector4::Zero)
		, mLifeTime(1.0f)
		, mTime(0.0f)
		, mFrequency(0.5f)
	{
		std::shared_ptr<Mesh> mesh = Resources::Find<Mesh>(L"PointMesh");
		SetMesh(mesh);

		//std::shared_ptr<Material> material = Resources::Find<Material>(L"ParticleMaterial");
		//SetMaterial(material);
		mStartSize =  Vector4(5.0f, 5.0f, 1.0f, 1.0f);
		mStartColor = Vector4(1.0f, 0.0f, 0.0f, 1.0f);
		mEndColor = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
		mCS = Resources::Find<ParticleShader>(L"ParticleSystemShader");

		Particle particles[1000] = {};
		for (size_t i = 0; i < 1000; i++)
		{
			//pos.x += rand() % 1000;
			//pos.y += rand() % 600;

			//int sign = rand() % 2;
			//if (sign == 0)
			//	pos.x *= -1.0f;
			//sign = rand() % 2;
			//if (sign == 0)
			//	pos.y *= -1.0f;

	/*		particles[i].direction =
				Vector4(cosf((float)i * (XM_2PI / (float)1000))
					, sinf((float)i * (XM_2PI / 100.f))
					, 0.0f, 1.0f);*/
			int randomValue = dis(gen);
			float coneAngle = math::DegreeToRadian(20.0f);  
			float angle = ((float)randomValue / 1000.0f) * coneAngle;

			particles[i].direction =
				Vector4(cosf(angle), sinf(angle), 0.0f, 1.0f);
			Vector4 pos = Vector4::Zero;

			particles[i].direction.Normalize();

			particles[i].position = pos;
			particles[i].speed = 200.0f;
			particles[i].active = 0;
			particles[i].lifeTime = mLifeTime;
			particles[i].frequency = mFrequency;
			particles[i].startSize = mStartSize;
			particles[i].startColor= mStartColor;
			particles[i].endColor = mEndColor;
		}

		mBuffer = new graphics::StructedBuffer();
		mBuffer->Create(sizeof(Particle), 1000, eViewType::UAV, particles);

		mSharedBuffer = new graphics::StructedBuffer();
		mSharedBuffer->Create(sizeof(ParticleShared), 1, eViewType::UAV, nullptr, true);

		//ParticleShared shareData = {};
		//shareData.sharedActiveCount = 1000;
		//mSharedBuffer->SetData(&shareData, 1);
		//mBuffer->SetData(particles, 100);
	}
	ParticleSystem::~ParticleSystem()
	{
	}
	void ParticleSystem::Initialize()
	{
	}
	void ParticleSystem::Update()
	{
	}
	void ParticleSystem::LateUpdate()
	{
		float AliveTime = 0.1f / 1.0f;
		mTime += Time::DeltaTime();

		if (mTime > AliveTime)
		{
			float f = (mTime / AliveTime);
			UINT AliveCount = (UINT)f;
			mTime = f - floor(f);

			ParticleShared shareData = {};
			shareData.sharedActiveCount = mCount;
			mSharedBuffer->SetData(&shareData, 1);
		}
		else
		{
			ParticleShared shareData = {};
			shareData.sharedActiveCount = 0;
			mSharedBuffer->SetData(&shareData, 1);
		}


		mCS->SetParticleBuffer(mBuffer);
		mCS->SetSharedBuffer(mSharedBuffer);
		mCS->OnExcute();
	}
	void ParticleSystem::Render()
	{
		GetOwner()->GetComponent<Transform>()->BindConstantBuffer();
		mBuffer->BindSRV(eShaderStage::VS, 14);
		mBuffer->BindSRV(eShaderStage::GS, 14);
		mBuffer->BindSRV(eShaderStage::PS, 14);

		GetMaterial()->Binds();
		GetMesh()->RenderInstanced(1000);

		mBuffer->Clear();
	}
}