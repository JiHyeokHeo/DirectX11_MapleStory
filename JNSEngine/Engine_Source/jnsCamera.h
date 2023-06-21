#pragma once
#include "jnsComponent.h"
#include "jnsGraphics.h"


namespace jns
{
	class Camera : public Component
	{
	public:
		Camera();
		~Camera();
	
	private:
		static Matrix mView;
		static Matrix mProjection;

	};
}
