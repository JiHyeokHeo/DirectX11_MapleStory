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
		void Destroy();
		void Present();

		void SetWindow(HWND hwnd, UINT width, UINT height);

		UINT GetMetaDataWidth() { return mWidth; }
		UINT GetMedtaDataHeight() { return mHeight; }
		HWND GetHwnd() { return mHwnd; }

		void ResourcesLoadThread();

	private:
		bool mbInitialize = false;
		std::unique_ptr<jns::graphics::GraphicDevice_Dx11> graphicDevice;

		HWND mHwnd;
		UINT mWidth;
		UINT mHeight;

		bool isCreate = false;
		// 로딩 프로세스
	};
}
