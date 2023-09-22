#pragma once
#include "jnsSkillBase.h"


namespace jns
{
	class BloodyMeso : public SkillBase
	{
	public:
		BloodyMeso();
		~BloodyMeso();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		virtual void CompleteSkillAnimation() override;
		virtual void StartSkillAnimation() override;

		virtual void Activate() override;
		virtual void DeActivate() override;
		void SetPosition(Vector3 pos) override;
		bool GetIsActive() { return active; }
		void SetIsActive(bool isactive) { active = isactive; }

		void SetDamageDone(bool damaged) { isDamageDisplayed = damaged; }

		void SetInitData();


	private:
		// 이건 절대 변경되어선 안된다
		bool isInitialize = false;
		
		class Collider2D* cd;
		std::vector<GameObject*> settarget;
		float targetNum;
		float velocity;
		float angle;

		float mAirTime;
		float airMaxTime;

		bool isDamageDisplayed = false;

		bool active;
		float mTime;

	};

}
