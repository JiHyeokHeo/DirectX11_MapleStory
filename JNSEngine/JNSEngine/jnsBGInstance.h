#pragma once
#include "jnsBGBase.h"
#include "jnsAudioClip.h"
#include "jnsAudioSource.h"

namespace jns
{
	class BGInstance : public BGBase
	{
	public:
		enum class eBGType
		{
			Login,
			WorldSelect,
			CharactorSelect,
			CharactorMake,
			Start1,
			Start2,
			Start3,
			Start4,
			Start5,
			RutabysMain,
			RutabysQueenMob1,
			RutabysQueenMob2,
			RutabysQueenBoss,
			RutabysPierreMob1,
			RutabysPierreMob2,
			RutabysPierreBoss,
			None,
		};

		BGInstance();
		BGInstance(eBGType type);
		~BGInstance();


		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:
		eBGType mBGtype;
		AudioSource* as;
		bool isBGPlayed;
		class Scene* mPrevScene;
	};

}
