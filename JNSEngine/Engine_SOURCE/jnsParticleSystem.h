#pragma once
#include "jnsMeshRenderer.h"
#include "jnsStructedBuffer.h"
#include "jnsParticleShader.h"

namespace jns
{
	class ParticleSystem : public MeshRenderer
	{
	public:
		ParticleSystem();
		~ParticleSystem();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void SetStartSize(Vector2 size) { mStartSize = Vector4(size.x, size.y, 1.0f, 1.0f); }
		
		// ¹º°¡ ¼±Çü º¸°£ ÇØ¾ß ÇÒ²¨ °°Àºµ¥?
		void SetEndSize(Vector2 size) { mEndSize = Vector4(size.x, size.y, 1.0f, 1.0f); }
		
		// ´À³¦ÀÌ ¿¹´Â PS ½¦ÀÌ´õ °Çµå·ÁÁà¾ßÇÒ²¨ °°°í
		void SetStartColor(Vector4 startcolor) { mStartColor = startcolor; }
		void SetEndColor(Vector4 endcolor) { mEndColor = endcolor; }
		void SetFrequency(float frequency) { mFrequency = frequency; }

		void SetCount(UINT cnt) { mCount = cnt; }
		void SetLifeTime(float settime) { mLifeTime = settime; }
		
		void SetSpeed(float speed) { mSpeed = speed; }

	private:
		graphics::StructedBuffer* mBuffer;
		graphics::StructedBuffer* mSharedBuffer;

		std::shared_ptr<ParticleShader> mCS;


		UINT    mCount;
		Vector4 mStartSize;
		Vector4 mEndSize;
		Vector4 mStartColor;
		Vector4 mEndColor;
		float   mLifeTime;
		float	mFrequency;

		float mSpeed;
		float mTime;
	};
}