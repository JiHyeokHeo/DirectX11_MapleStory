#pragma once
#include "jnsResource.h"
#include "jnsGraphics.h"
//#include "jnsMath.h"

#include "../External/DirectXTex/Include/DirectXTex.h"
#include "../External/DirectXTex/Include/DirectXTex.inl"

#ifdef _DEBUG
#pragma comment(lib, "..\\External\\DirectXTex\\Lib\\Debug\\DirectXTex.lib")
#else
#pragma comment(lib, "..\\External\\DirectXTex\\Lib\\Release\\DirectXTex.lib")
#endif

using namespace jns::math;
namespace jns::graphics
{
	class Texture : public Resource
	{
	public:
		Texture();
		~Texture();


		HRESULT CreateTex(const std::wstring& path,  UINT filecnt , size_t imageMaxWidth, size_t imageMaxHeight);
		bool Create(UINT width, UINT height, DXGI_FORMAT format, UINT bindFlag);
	
		virtual HRESULT Load(const std::wstring& path) override;
		void BindShader(eShaderStage stage, UINT startSlot);
		void Clear();
		
		Vector2 GetTextureSize() 
		{ 
			/*if (mImage == nullptr)*/

			
			return Vector2(mImage.GetMetadata().width, mImage.GetMetadata().height); 
		}
		
		size_t GetWidth() { return mImage.GetMetadata().width; }
		size_t GetHeight() { return mImage.GetMetadata().height; }

		Microsoft::WRL::ComPtr<ID3D11RenderTargetView>    GetRTV() { return  mRTV; }
		void SetRTV(Microsoft::WRL::ComPtr<ID3D11RenderTargetView> rtv) { mRTV = rtv; }
		Microsoft::WRL::ComPtr<ID3D11DepthStencilView>    GetDSV() { return  mDSV; }
		void SetDSV(Microsoft::WRL::ComPtr<ID3D11DepthStencilView> dsv) { mDSV = dsv; }
		Microsoft::WRL::ComPtr<ID3D11ShaderResourceView>  GetSRV() { return  mSRV; }
		Microsoft::WRL::ComPtr<ID3D11UnorderedAccessView> GetUAV() { return  mUAV; }
		Microsoft::WRL::ComPtr<ID3D11Texture2D> GetTexture() { return mTexture; }
		void SetTexture(Microsoft::WRL::ComPtr<ID3D11Texture2D> texture) { mTexture = texture; }


		Vector2 GetTextureRatio() 
		{
			mWidth = mImage.GetMetadata().width;
			mHeight = mImage.GetMetadata().height;
			if (mWidth > mHeight)
			{
				mRatio.x = 1.0f;
				mRatio.y = mHeight / mWidth;
			}
			else
			{
				mRatio.x = mWidth / mHeight;
				mRatio.y = 1.0f;
			}	
			return mRatio;
		}
		const ScratchImage& GetAtlasImage() { return atlasImage; }
		
		
	private:
		ScratchImage mImage;
		Microsoft::WRL::ComPtr<ID3D11Texture2D> mTexture;
		Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> mSRV;
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> mRTV;
		Microsoft::WRL::ComPtr<ID3D11DepthStencilView> mDSV;
		Microsoft::WRL::ComPtr<ID3D11UnorderedAccessView> mUAV;

		D3D11_TEXTURE2D_DESC mDesc;

		ScratchImage atlasImage;

		float mWidth;
		float mHeight;
		Vector2 mRatio;
	};
}
