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

    HRESULT Texture::Create(const std::vector<std::wstring>& imagePaths, std::shared_ptr<graphics::Texture>& atlasTexture, std::vector<RECT>& uvCoordinates)
    {
        ScratchImage atlasImage;
        HRESULT hr = S_OK;

        for (const auto& path : imagePaths)
        {
            wchar_t ext[_MAX_EXT] = {};
            _wsplitpath_s(path.c_str(), nullptr, 0, nullptr, 0, nullptr, 0, ext, _MAX_EXT);

            ScratchImage image;

            if (_wcsicmp(ext, L".dds") == 0)
            {
                hr = LoadFromDDSFile(path.c_str(), DDS_FLAGS_NONE, nullptr, image);
            }
            else if (_wcsicmp(ext, L".tga") == 0)
            {
                hr = LoadFromTGAFile(path.c_str(), nullptr, image);
            }
            else if (_wcsicmp(ext, L".hdr") == 0)
            {
                hr = LoadFromHDRFile(path.c_str(), nullptr, image);
            }
            else
            {
                hr = LoadFromWICFile(path.c_str(), WIC_FLAGS_NONE, nullptr, image);
            }

            if (SUCCEEDED(hr))
            {
                // Convert the image to a different format if needed (e.g., to DXGI_FORMAT_R8G8B8A8_UNORM)
                ScratchImage convertedImage;
                hr = Convert(image.GetImages(), image.GetImageCount(), image.GetMetadata(), DXGI_FORMAT_R8G8B8A8_UNORM, TEX_FILTER_DEFAULT, TEX_THRESHOLD_DEFAULT, convertedImage);
                if (FAILED(hr))
                {
                    // Handle the conversion error if necessary
                    return hr;
                }

                // Append the converted image to the atlas image
                hr = atlasImage.Initialize2D(DXGI_FORMAT_R8G8B8A8_UNORM, convertedImage.GetMetadata().width, convertedImage.GetMetadata().height, 1, 1);
                if (SUCCEEDED(hr))
                {
                    hr = CopyRectangle(*convertedImage.GetImage(0, 0, 0), Rect(0, 0, image.GetMetadata().width, image.GetMetadata().height), *image.GetImage(0, 0, 0),
                        TEX_FILTER_DEFAULT, 100, 50);
                }
            }

            if (FAILED(hr))
            {
                // Error handling if image loading or conversion fails
                return hr;
            }
        }

        // Create a DirectX 11 texture from the combined image data
       
        hr = CreateTexture(GetDevice()->GetID3D11Device(),
            atlasImage.GetImages(), atlasImage.GetImageCount(),
            atlasImage.GetMetadata(), (ID3D11Resource**)mTexture.GetAddressOf());

        if (FAILED(hr))
        {
            // Error handling if the texture creation failed
            return hr;
        }
        // Create an atlas texture object
        atlasTexture = std::make_shared<graphics::Texture>();
        atlasTexture->mSRV->GetResource((ID3D11Resource**)mTexture.GetAddressOf());

        // Calculate UV coordinates for each individual image in the atlas
        // and store them in the uvCoordinates vector
        // You need to decide how to map each image in the atlas, such as evenly dividing the atlas or using a sprite sheet layout.

        return S_OK;
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