#pragma once
#include "jnsGameObject.h"

namespace jns
{
	class DarkPaper : public GameObject
	{
	public:
		DarkPaper();
		~DarkPaper();
		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;


	private:
	};

}
