#include "jnsFontWrapper.h"
#include "jnsGraphicDevice_Dx11.h"

namespace jns
{
	IFW1Factory* FontWrapper::mFW1Factory = nullptr;
	IFW1FontWrapper* FontWrapper::mFontWrapper = nullptr;


	bool FontWrapper::Initialize()
	{
		if (FAILED(FW1CreateFactory(FW1_VERSION, &mFW1Factory)))
			return false;

		ID3D11Device* pDevice = graphics::GetDevice()->GetID3D11Device();
		if (FAILED(mFW1Factory->CreateFontWrapper(pDevice, L"Arial", &mFontWrapper)))
			return false;

		return true;
	}

	void FontWrapper::DrawFont(const wchar_t* str, float x, float y, float size, UINT rgb)
	{	
		//RGB();
		ID3D11DeviceContext* pContext = graphics::GetDevice()->GetID3D11DeviceContext();
		mFontWrapper->DrawString(
			pContext,
			str, // String
			size,// Font size
			x,// X position
			y,// Y position
			rgb,// Text color, 0xAaBbGgRr
			FW1_RESTORESTATE      // Flags (for example FW1_RESTORESTATE to keep context states unchanged)
		);
	}

	void FontWrapper::Release()
	{
		mFW1Factory->Release();
		mFW1Factory = nullptr;

		mFontWrapper->Release();
		mFontWrapper = nullptr;
	}

}