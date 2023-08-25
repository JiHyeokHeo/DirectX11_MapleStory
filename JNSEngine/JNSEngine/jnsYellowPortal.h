#pragma once
#include "jnsPortalBase.h"

namespace jns
{
	class YellowPortal : public PortalBase
	{
	public:
		YellowPortal(std::wstring name, Vector3 setpos, int dir);
		~YellowPortal();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

	private:
		int mDir;
		class Animator* at;
		bool isSetDir;
	};

}
