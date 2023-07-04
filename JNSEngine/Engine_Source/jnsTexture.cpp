#include "jnsTexture.h"
#include "jnsGraphicDevice_Dx11.h"


namespace jns::graphics
{
	Texture::Texture()
		: Resource(enums::eResourceType::Texture)
		, mImage{}
		, mTexture(nullptr)
		, mSRV(nullptr)
		, mDesc{}
	{
	}

	Texture::~Texture()
	{
	}

	HRESULT Texture::Load(const std::wstring& path)
	{
		wchar_t szExtension[50] = {};
		_wsplitpath_s(path.c_str(), nullptr, 0, nullptr, 0, nullptr, 0, szExtension, 50);

		std::wstring extension = szExtension;
		if (extension == L".dds" || extension == L".DDS")
		{
			if (FAILED(LoadFromDDSFile(path.c_str(), DDS_FLAGS::DDS_FLAGS_NONE, nullptr, mImage)))
				return S_FALSE;
		}
		else if (extension == L".tga" || extension == L".TGA")
		{
			if (FAILED(LoadFromTGAFile(path.c_str(), nullptr, mImage)))
				return S_FALSE;
		}
		else // WIC (png, jpg, jpeg, bmp )
		{
			if (FAILED(LoadFromWICFile(path.c_str(), WIC_FLAGS::WIC_FLAGS_NONE, nullptr, mImage)))
				return S_FALSE;
		}

		CreateShaderResourceView
		(
			GetDevice()->GetID3D11Device()
			, mImage.GetImages()
			, mImage.GetImageCount()
			, mImage.GetMetadata()
			, mSRV.GetAddressOf()
		);
		//mWidth = mImage.GetMetadata().width;
		//mHeight = mImage.GetMetadata().height;
		mSRV->GetResource((ID3D11Resource**)mTexture.GetAddressOf());

		return S_OK;
	}

	void Texture::BindShader(eShaderStage stage, UINT startSlot)
	{
		GetDevice()->BindShaderResource(stage, startSlot, mSRV.GetAddressOf());
	}
	void Texture::Clear()
	{
		ID3D11ShaderResourceView* srv = nullptr;

		GetDevice()->BindShaderResource(eShaderStage::VS, 0, &srv);
		GetDevice()->BindShaderResource(eShaderStage::DS, 0, &srv);
		GetDevice()->BindShaderResource(eShaderStage::GS, 0, &srv);
		GetDevice()->BindShaderResource(eShaderStage::HS, 0, &srv);
		GetDevice()->BindShaderResource(eShaderStage::CS, 0, &srv);
		GetDevice()->BindShaderResource(eShaderStage::PS, 0, &srv);
	}
}