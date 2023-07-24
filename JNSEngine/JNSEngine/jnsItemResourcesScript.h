#pragma once
#include "jnsScript.h"

namespace jns
{
	class ItemResourcesScript : public Script
	{
	public:
		ItemResourcesScript();
		~ItemResourcesScript();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;


		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;


	public:
		void ItemMove();
		void ItemSetPos();

	private:
		bool isPicked;
	};
}
