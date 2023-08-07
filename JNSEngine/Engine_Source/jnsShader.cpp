#include "jnsShader.h"
#include "jnsRenderer.h"

namespace jns
{
	Shader::Shader()
		: Resource(enums::eResourceType::Shader)
		, mInputLayout(nullptr)
		, mTopology(D3D11_PRIMITIVE_TOPOLOGY::D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST)
		, mRSType(eRSType::SolidBack)
		, mDSType(eDSType::Less)
		, mBSType(eBSType::AlphaBlend)
	{
	}
	Shader::~Shader()
	{
		mInputLayout->Release();
	}
	HRESULT Shader::Load(const std::wstring& path)
	{
		return E_NOTIMPL;
	}
	bool Shader::Create(const eShaderStage stage
		, const std::wstring& fileName
		, const std::string& funcName)
	{
		std::filesystem::path shaderPath
			= std::filesystem::current_path().parent_path();
		shaderPath += L"\\Shader_SOURCE\\";

		std::filesystem::path fullPath(shaderPath.c_str());
		fullPath += fileName;

		ID3DBlob* errorBlob = nullptr;
		if (stage == eShaderStage::VS)
		{
			GetDevice()->CompileFromfile(fullPath, funcName, "vs_5_0", mVSBlob.GetAddressOf());
			GetDevice()->CreateVertexShader(mVSBlob->GetBufferPointer()
				, mVSBlob->GetBufferSize(), mVS.GetAddressOf());
		}
		else if (stage == eShaderStage::GS)
		{
			GetDevice()->CompileFromfile(fullPath, funcName, "gs_5_0", mGSBlob.GetAddressOf());
			GetDevice()->CreateGeometryShader(mGSBlob->GetBufferPointer()
				, mGSBlob->GetBufferSize(), mGS.GetAddressOf());
		}
		else if (stage == eShaderStage::PS)
		{
			GetDevice()->CompileFromfile(fullPath, funcName, "ps_5_0", mPSBlob.GetAddressOf());
			GetDevice()->CreatePixelShader(mPSBlob->GetBufferPointer()
				, mPSBlob->GetBufferSize(), mPS.GetAddressOf());
		}


		return true;;
	}
	void Shader::Binds()
	{
		GetDevice()->BindInputLayout(mInputLayout);
		GetDevice()->BindPrimitiveTopology(mTopology);
		
		GetDevice()->BindVertexShader(mVS.Get());
		GetDevice()->BindGeometryShader(mGS.Get());
		GetDevice()->BindPixelShader(mPS.Get());

		Microsoft::WRL::ComPtr<ID3D11RasterizerState> rsState = renderer::rasterizerStates[(UINT)mRSType];
		//Microsoft::WRL::ComPtr<ID3D11DepthStencilState> dsState = renderer::depthStencilStates[(UINT)mDSType];
		Microsoft::WRL::ComPtr<ID3D11BlendState> bsState = renderer::blendStates[(UINT)mBSType];

		GetDevice()->BindRasterizeState(rsState.Get());
		//GetDevice()->BindDepthStencilState(dsState.Get());
		GetDevice()->BindBlendState(bsState.Get());
	}
}