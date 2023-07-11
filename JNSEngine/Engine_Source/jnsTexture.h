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

		virtual HRESULT Load(const std::wstring& path) override;
		void BindShader(eShaderStage stage, UINT startSlot);
		void Clear();
		
		Vector2 GetTextureSize() { return Vector2(mImage.GetMetadata().width, mImage.GetMetadata().height); }
		
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
		
	private:
		ScratchImage mImage;
		Microsoft::WRL::ComPtr<ID3D11Texture2D> mTexture;
		Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> mSRV;
		D3D11_TEXTURE2D_DESC mDesc;


		float mWidth;
		float mHeight;
		Vector2 mRatio;
	};
}
