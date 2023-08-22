#pragma once
#include "jnsBGBase.h"
#include "jnsAudioClip.h"

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
		class AudioSource* as;
		static bool isBGPlayed;
		class Scene* mPrevScene;
	};

}
