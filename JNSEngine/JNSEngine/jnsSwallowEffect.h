#pragma once
#include "jnsEffectBase.h"

namespace jns
{
	class SwallowEffect : public EffectBase
	{
	public:
		SwallowEffect();
		virtual ~SwallowEffect();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void SwallowComplete();

	private:
		bool isEffectOn;
		bool isSet;
	};

}
