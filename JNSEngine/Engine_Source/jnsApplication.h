#pragma once
#include "JNSEngine.h"
#include "jnsGraphicDevice_Dx11.h"
#include "jnsScene.h"

namespace jns
{
	class Application
	{
	public:
		Application();
		~Application();
		
		void Run();

		void Initialize();
		void Update();
		void LateUpdate();
		void Render();

		void SetWindow(HWND hwnd, UINT width, UINT height);

		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mHeight; }
		HWND GetHwnd() { return mHwnd; }

	private:
		bool mbInitialize = false;
		std::unique_ptr<jns::graphics::GraphicDevice_Dx11> graphicDevice;

		HWND mHwnd;
		UINT mWidth;
		UINT mHeight;
		
		Scene* mScene;
	};
}
