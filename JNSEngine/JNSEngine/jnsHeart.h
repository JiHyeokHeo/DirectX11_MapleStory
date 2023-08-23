#pragma once
#include "jnsGameObject.h"

namespace jns
{
	class Heart : public GameObject
	{
	public:
		Heart();
		~Heart();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		void CompleteSummon();
	private:
	};
}