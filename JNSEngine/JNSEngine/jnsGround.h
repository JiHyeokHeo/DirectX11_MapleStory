#pragma once
#include "jnsGameObject.h"

namespace jns
{
	class Ground : public GameObject
	{
	public:
		Ground();
		Ground(const std::wstring name);
		virtual ~Ground();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	private:
		std::wstring mGroundName;
	};

}
