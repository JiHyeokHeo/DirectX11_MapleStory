#pragma once
#include "jnsGameObject.h"
#include "jnsAnimator.h"
#include "jnsMeshRenderer.h"

namespace jns
{
	class SkillResources : public GameObject
	{
	public:
		enum class eSkillType
		{
			Assain,
			End,
		};


		SkillResources();
		~SkillResources();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void SetAssainSkill();

	private:
		eSkillType mSkillType;
		bool isMovePossible;
		MeshRenderer* mr;
		Animator* at;
	};

}
