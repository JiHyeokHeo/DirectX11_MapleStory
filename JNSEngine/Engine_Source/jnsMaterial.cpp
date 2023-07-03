#include "jnsMaterial.h"


namespace jns::graphics
{
	Material::Material()
		: Resource(jns::enums::eResourceType::Material)
		, mShader(nullptr)
		, mTexture(nullptr)
		, mMode(eRenderingMode::Opaque)
	{

	}

	Material::~Material()
	{
	}

	HRESULT Material::Load(const std::wstring& path)
	{
		return E_NOTIMPL;
	}

	void Material::Binds()
	{
		if (mTexture)
			mTexture->BindShader(eShaderStage::PS, 0);
		mTexture->BindShader(eShaderStage::PS, 1);

		if (mShader)
			mShader->Binds();
	}
	void Material::Clear()
	{
		mTexture->Clear();
	}
}