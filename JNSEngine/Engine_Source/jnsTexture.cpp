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
            if (FAILED(LoadFromWICFile(path.c_str(), WIC_FLAGS::WIC_FLAGS_IGNORE_SRGB, nullptr, mImage)))
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

    HRESULT Texture::CreateTex(const std::wstring& path, UINT filecnt, size_t imageMaxWidth, size_t imageMaxHeight)
    {
        ScratchImage atlasImage;
        HRESULT hr = S_OK;

        wchar_t ext[_MAX_EXT] = {};
        _wsplitpath_s(path.c_str(), nullptr, 0, nullptr, 0, nullptr, 0, ext, _MAX_EXT);
        ScratchImage image;
        int idx = 0;
        std::filesystem::path fs(path);
        size_t targetWidth = imageMaxWidth;
        size_t targetHeight = imageMaxHeight;

        //if (imageMaxWidth >= 500)
        //{
        //   targetWidth = imageMaxWidth / 5;
        //   targetHeight = imageMaxHeight / 5;
        //}
        //else
        //{
        //    targetWidth = imageMaxWidth;
        //    targetHeight = imageMaxHeight;
        //}


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
                hr = LoadFromWICFile(fullName.c_str(), WIC_FLAGS_IGNORE_SRGB, nullptr, image);
            }

            if (SUCCEEDED(hr))
            {
                // 이미지 크기를 목표 크기로 조정
                ScratchImage resizedImage;

                size_t t_Width = {};
                size_t t_Height= {};
                t_Width = image.GetMetadata().width;
                t_Height = image.GetMetadata().height;
                //if (t_Width >= 600)
                //{
                //    int frontnum = 0;
                //    frontnum = t_Width / 600;
                //    t_Width /= frontnum;
                //    t_Height /= frontnum;
                //}
               
                hr = Resize(image.GetImages(), image.GetImageCount(), image.GetMetadata(), t_Width, t_Height, TEX_FILTER_DEFAULT, resizedImage);
                if (FAILED(hr))
                {
                    // 이미지 크기 조정 오류 처리 (필요한 경우)
                    return hr;
                }

                // 조정된 이미지를 원하는 형식으로 변환
                ScratchImage convertedImage;
                hr = Convert(resizedImage.GetImages(), resizedImage.GetImageCount(), resizedImage.GetMetadata(), DXGI_FORMAT_R8G8B8A8_UNORM, TEX_FILTER_DEFAULT, TEX_THRESHOLD_DEFAULT, convertedImage);
                if (FAILED(hr))
                {
                    // 변환 오류 처리 (필요한 경우)
                    return hr;
                }

                if (isMake == false)
                {
                    hr = atlasImage.Initialize2D(DXGI_FORMAT_R8G8B8A8_UNORM, targetWidth * filecnt, targetHeight * 2, 1, 1);
                    isMake = true;
                }
                if (FAILED(hr))
                {
                    // 아틀라스 이미지 초기화 오류 처리 (필요한 경우)
                    return hr;
                }

                // 조정된 이미지 데이터를 아틀라스 이미지로 복사
                hr = CopyRectangle(*convertedImage.GetImage(0, 0, 0), Rect(0, 0, convertedImage.GetMetadata().width, convertedImage.GetMetadata().height),
                    *atlasImage.GetImage(0, 0, 0), TEX_FILTER_DEFAULT, (targetWidth)*idx, 0);
                if (FAILED(hr))
                {
                    // 복사 오류 처리 (필요한 경우)
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
        mSRV->GetResource((ID3D11Resource**)mTexture.GetAddressOf());

        // Create an atlas texture object
        // Assign the DirectX 11 texture and SRV to the atlasTexture

        // Copy the image data from atlasImage to atlasTexture->mImage
        this->mImage.Initialize2D(
            atlasImage.GetMetadata().format,
            atlasImage.GetMetadata().width,
            atlasImage.GetMetadata().height,
            atlasImage.GetMetadata().arraySize,
            atlasImage.GetMetadata().mipLevels
        );

        return S_OK;
    }
    bool Texture::Create(UINT width, UINT height, DXGI_FORMAT format, UINT bindFlag)
    {
        if (mTexture == nullptr)
        {
            mDesc.BindFlags = bindFlag;
            mDesc.Usage = D3D11_USAGE_DEFAULT;
            mDesc.CPUAccessFlags = 0;
            mDesc.Format = format;
            mDesc.Width = width;
            mDesc.Height = height;
            mDesc.ArraySize = 1;

            mDesc.SampleDesc.Count = 1;
            mDesc.SampleDesc.Quality = 0;

            mDesc.MipLevels = 0;
            mDesc.MiscFlags = 0;

            if (!GetDevice()->CreateTexture2D(&mDesc, nullptr, mTexture.GetAddressOf()))
                return false;
        }

        if (bindFlag & (UINT)D3D11_BIND_FLAG::D3D11_BIND_DEPTH_STENCIL)
        {
            if (!GetDevice()->CraeteDepthStencilView(mTexture.Get(), nullptr, mDSV.GetAddressOf()))
                return false;
        }
        if (bindFlag & (UINT)D3D11_BIND_FLAG::D3D11_BIND_SHADER_RESOURCE)
        {
            D3D11_SHADER_RESOURCE_VIEW_DESC tSRVDesc = {};
            tSRVDesc.Format = mDesc.Format;
            tSRVDesc.Texture2D.MipLevels = 1;
            tSRVDesc.Texture2D.MostDetailedMip = 0;
            tSRVDesc.ViewDimension = D3D11_SRV_DIMENSION::D3D11_SRV_DIMENSION_TEXTURE2D;

            if (!GetDevice()->CreateShaderResourceView(mTexture.Get(), &tSRVDesc, mSRV.GetAddressOf()))
                return false;
        }

        if (bindFlag & (UINT)D3D11_BIND_FLAG::D3D11_BIND_RENDER_TARGET)
        {
            D3D11_RENDER_TARGET_VIEW_DESC tSRVDesc = {};
            tSRVDesc.Format = mDesc.Format;
            tSRVDesc.Texture2D.MipSlice = 0;
            tSRVDesc.ViewDimension = D3D11_RTV_DIMENSION::D3D11_RTV_DIMENSION_TEXTURE2D;

            if (!GetDevice()->CreateRenderTargetView(mTexture.Get(), nullptr, mRTV.GetAddressOf()))
                return false;
        }

        if (bindFlag & (UINT)D3D11_BIND_FLAG::D3D11_BIND_UNORDERED_ACCESS)
        {
            D3D11_UNORDERED_ACCESS_VIEW_DESC tUAVDesc = {};
            tUAVDesc.Format = mDesc.Format;
            tUAVDesc.Texture2D.MipSlice = 0;
            tUAVDesc.ViewDimension = D3D11_UAV_DIMENSION::D3D11_UAV_DIMENSION_TEXTURE2D;

            if (!GetDevice()->CreateUnordedAccessView(mTexture.Get(), &tUAVDesc, mUAV.GetAddressOf()))
                return false;
        }


        return true;
    }
}