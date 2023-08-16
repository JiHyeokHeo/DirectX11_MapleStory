#pragma once
#include "jnsGameObject.h"
namespace jns
{
	class Mirror : public GameObject
	{
	public:
		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:
	};
}


