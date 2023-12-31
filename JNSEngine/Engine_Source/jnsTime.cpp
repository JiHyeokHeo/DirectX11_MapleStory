#include "jnsTime.h"
#include "jnsApplication.h"
#include "jnsInput.h"
#include "../JNSEngine/jnsCursor.h"

extern jns::Application application;

namespace jns
{
	double Time::mDeltaTime = 0.0l;
	double Time::mSecond = 0.0f;
	LARGE_INTEGER Time::mCpuFrequency = {};
	LARGE_INTEGER Time::mPrevFrequency = {};
	LARGE_INTEGER Time::mCurFrequency = {};

	void Time::Initialize()
	{
		// CPU 고유 진동수 가져오기
		QueryPerformanceFrequency(&mCpuFrequency);

		// 프로그램이 처음 시작할때 진동수
		QueryPerformanceCounter(&mPrevFrequency);
	}

	void Time::Update()
	{
		QueryPerformanceCounter(&mCurFrequency);

		double differnceFrequency = mCurFrequency.QuadPart - mPrevFrequency.QuadPart;

		mDeltaTime = differnceFrequency / mCpuFrequency.QuadPart;
		
		mPrevFrequency.QuadPart = mCurFrequency.QuadPart;
	}

	void Time::Render()
	{
		mSecond += mDeltaTime;

		if (mSecond > 1.0f)
		{
			HWND hWnd = application.GetHwnd();
			Vector3 mPos = jns::Input::GetWorldMousePos();
			Vector3 mUIPos = jns::Input::GetUIMousePos();
			wchar_t szFloat[256] = {};
			float FPS = 1.0f / (float)mDeltaTime;
			swprintf_s(szFloat, 256, L"FPS : %d Mouse X COR : %d, Mouse Y COR : %d, MouseWorld X : %d, MouseWorld Y : %d", (UINT)FPS, (UINT)mUIPos.x, (UINT)mUIPos.y, (UINT)mPos.x, (UINT)mPos.y);
			//int iLen = wcsnlen_s(szFloat, 50);
			SetWindowText(hWnd, szFloat);
			
			//TextOut(hdc, 0, 0, szFloat, 20);
			mSecond = 0.0f;
		}
	}
}
