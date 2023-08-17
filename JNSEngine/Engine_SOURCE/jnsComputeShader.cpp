#include "jnsComputeShader.h"
#include "jnsGraphicDevice_Dx11.h"

namespace jns::graphics
{
	ComputeShader::ComputeShader(int x, int y, int z)
		: Resource(enums::eResourceType::ComputeShader)
	{
		mThreadGroupCountX = x;
		mThreadGroupCountY = y;
		mThreadGroupCountZ = z;
	}
	ComputeShader::ComputeShader()
		: Resource(enums::eResourceType::ComputeShader)
	{
		mThreadGroupCountX = 32;
		mThreadGroupCountY = 32;
		mThreadGroupCountZ = 1;
	}

	ComputeShader::~ComputeShader()
	{
	}

	bool ComputeShader::Create(const std::wstring& name, const std::string& methodName)
	{
		std::filesystem::path shaderPath
			= std::filesystem::current_path().parent_path();
		shaderPath += L"\\Shader_SOURCE\\";

		std::filesystem::path fullPath(shaderPath.c_str());
		fullPath += name;

		ID3DBlob* errorBlob = nullptr;
		graphics::GetDevice()->CompileFromfile(fullPath, methodName, "cs_5_0", mCSBlob.GetAddressOf());
		graphics::GetDevice()->CreateComputeShader(mCSBlob->GetBufferPointer()
			, mCSBlob->GetBufferSize(), mCS.GetAddressOf());

		return true;
	}
	void ComputeShader::OnExcute()
	{
		Binds();

		GetDevice()->BindComputeShader(mCS.Get());
		GetDevice()->Dispatch(mGroupX, mGroupY, mGroupZ);

		Clear();
	}
	void ComputeShader::Binds()
	{
	}
	void ComputeShader::Clear()
	{
	}
}