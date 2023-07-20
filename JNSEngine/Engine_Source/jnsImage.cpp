#include "jnsImage.h"
#include "jnsTexture.h"

namespace jns
{
	Image* Image::Create(const std::wstring& name, UINT width, UINT height, COLORREF rgb)
	{



		return nullptr;
	}
	Image::Image()
		: Resource(enums::eResourceType::Image)
	{

	}
	Image::~Image()
	{
	}
	HRESULT Image::Load(const std::wstring& path)
	{
	

		return S_OK;
	}
}