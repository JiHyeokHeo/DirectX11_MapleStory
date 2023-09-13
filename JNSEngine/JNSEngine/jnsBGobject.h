#pragma once
#include "jnsGameObject.h"

namespace jns
{
	class BGobject : public GameObject
	{
	public:
		BGobject();
		~BGobject();

		enum class eBGObjectType
		{
			westGardenArtifect1,
			westGardenArtifect2,
			westGardenArtifect3,
			pierreArtficiality1,
			pierreArtficiality2,
			pierreArtficiality3,
			pierreArtficiality4,
			None,
		};

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void SetBGObjectType(eBGObjectType type) { bgObjectType = type; }
	private:
		eBGObjectType bgObjectType;
	};

}
