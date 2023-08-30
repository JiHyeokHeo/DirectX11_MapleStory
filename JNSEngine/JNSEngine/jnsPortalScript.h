#pragma once
#include "jnsScript.h"
#include "jnsSceneManager.h"

namespace jns
{
	class PortalScript : public Script
	{
	public:
		enum class ePortalEnter
		{
			RutabysMob,
			Rutabys,
			RutabysBoss,
		};
		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;


	private:
		class PortalBase* mPortal;

		jns::enums::eSceneType mEnter;
		bool isEnter;
	};

}
