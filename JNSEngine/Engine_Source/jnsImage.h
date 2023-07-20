#pragma once
#include "jnsResource.h"
#include "jnsTexture.h"

namespace jns
{
	using namespace math;
	using namespace graphics;
	class Image : public Resource
	{
	public:
		static Image* Create(const std::wstring& name, UINT width, UINT height, COLORREF rgb = RGB(0, 0, 0));

		Image();
		~Image();

		virtual HRESULT Load(const std::wstring& path) override;

	private:
		std::shared_ptr<graphics::Texture> mImage;
		Vector2 leftTop;
		Vector2 size;
		Vector2 offset;
	};
}

