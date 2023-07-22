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

    HRESULT Texture::CreateTex(const std::wstring& path, std::shared_ptr<graphics::Texture>& atlasTexture, UINT filecnt, UINT imageMaxWidth, UINT imageMaxHeight)
    {
        ScratchImage atlasImage;
        HRESULT hr = S_OK;

        wchar_t ext[_MAX_EXT] = {};
        _wsplitpath_s(path.c_str(), nullptr, 0, nullptr, 0, nullptr, 0, ext, _MAX_EXT);
        ScratchImage image;
        int idx = 0;
        std::filesystem::path fs(path);

        bool isMake = false;
        for (const auto& p : std::filesystem::recursive_directory_iterator(path))
        {
            std::wstring fileName = p.path().filename();
            std::wstring fullName = p.path().wstring(); // Use the full path from the iterator
            if (_wcsicmp(ext, L".dds") == 0)
            {
                hr = LoadFromDDSFile(fullName.c_str(), DDS_FLAGS_NONE, nullptr, image);
            }
            else if (_wcsicmp(ext, L".tga") == 0)
            {
                hr = LoadFromTGAFile(fullName.c_str(), nullptr, image);
            }
            else if (_wcsicmp(ext, L".hdr") == 0)
            {
                hr = LoadFromHDRFile(fullName.c_str(), nullptr, image);
            }
            else
            {
                hr = LoadFromWICFile(fullName.c_str(), WIC_FLAGS_NONE, nullptr, image);
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
                // imageMaxWidth * filecnt, imageMaxHeight
                // Initialize the atlas image
                if (isMake == false)
                {
                    hr = atlasImage.Initialize2D(DXGI_FORMAT_R8G8B8A8_UNORM, imageMaxWidth * filecnt, imageMaxHeight * 2, 1, 1);
                    isMake = true;
                }
                if (FAILED(hr))
                {
                    // Handle the atlas image initialization error if necessary
                    return hr;
                }

                // Copy the converted image data to the atlas image
                hr = CopyRectangle(*convertedImage.GetImage(0, 0, 0), Rect(0, 0, convertedImage.GetMetadata().width, convertedImage.GetMetadata().height),
                    *atlasImage.GetImage(0, 0, 0), TEX_FILTER_DEFAULT, (convertedImage.GetMetadata().width * idx), 0);
                if (FAILED(hr))
                {
                    // Handle the copy rectangle error if necessary
                    return hr;
                }
            }
            idx++;
        }
        if (FAILED(hr))
        {
            // Error handling if image loading, conversion, or copy rectangle fails
            return hr;
        }

        // Create a DirectX 11 texture from the combined image data
        //hr = CreateTexture(GetDevice()->GetID3D11Device(),
        //    atlasImage.GetImages(), atlasImage.GetImageCount(),
        //    atlasImage.GetMetadata(), (ID3D11Resource**)mTexture.GetAddressOf());
        if (FAILED(hr))
        {
            // Error handling if the texture creation failed
            return hr;
        }

        CreateShaderResourceView
        (
            GetDevice()->GetID3D11Device()
            , atlasImage.GetImages()
            , atlasImage.GetImageCount()
            , atlasImage.GetMetadata()
            , mSRV.GetAddressOf()
        );
        //mWidth = mImage.GetMetadata().width;
        //mHeight = mImage.GetMetadata().height;
        mSRV->GetResource((ID3D11Resource**)mTexture.GetAddressOf());

        // Create an atlas texture object



        // Assign the DirectX 11 texture and SRV to the atlasTexture
        atlasTexture = std::make_shared<graphics::Texture>();
        atlasTexture->mTexture = mTexture.Get();
        atlasTexture->mSRV = mSRV.Get();

        // Copy the image data from atlasImage to atlasTexture->mImage
        atlasTexture->mImage.Initialize2D(
            atlasImage.GetMetadata().format,
            atlasImage.GetMetadata().width,
            atlasImage.GetMetadata().height,
            atlasImage.GetMetadata().arraySize,
            atlasImage.GetMetadata().mipLevels
        );

        //for (size_t mip = 0; mip < atlasImage.GetMetadata().mipLevels; ++mip)
        //{
        //    const Image* srcImage = atlasImage.GetImage(mip, 0, 0);
        //    const Image* destImage = atlasTexture->mImage.GetImage(mip, 0, 0);

        //    if (srcImage && destImage)
        //    {
        //        memcpy(destImage->pixels, srcImage->pixels, srcImage->rowPitch * srcImage->height);
        //    }
        //}
        // Calculate UV coordinates for each individual image in the atlasz
        // and store them in the uvCoordinates vector
        // You need to decide how to map each image in the atlas, such as evenly dividing the atlas or using a sprite sheet layout.

        return S_OK;
    }
}