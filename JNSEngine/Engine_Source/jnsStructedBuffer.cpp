#include "jnsStructedBuffer.h"
#include "jnsGraphicDevice_Dx11.h"

namespace jns::graphics
{
	StructedBuffer::StructedBuffer()
		: GpuBuffer()
		, mType(eViewType::SRV)
		, mSRV(nullptr)
		, mSize(0)
		, mStride(0)
		, mSRVSlot(0)
		, mUAVslot(0)
	{
	}
	StructedBuffer::~StructedBuffer()
	{
	}
	bool StructedBuffer::Create(UINT size, UINT stride, eViewType type, void* data, bool cpuAccess)
	{
		mType = type;

		mSize = size;
		mStride = stride;

		desc.ByteWidth = mSize * mStride;
		desc.StructureByteStride = mSize;

		desc.Usage = D3D11_USAGE::D3D11_USAGE_DEFAULT;
		desc.CPUAccessFlags = 0;
		desc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_SHADER_RESOURCE;	// Texture Register Binding
		desc.MiscFlags = D3D11_RESOURCE_MISC_FLAG::D3D11_RESOURCE_MISC_BUFFER_STRUCTURED; // 구조화 버퍼 추가 플래그 설정

		if (mType == eViewType::UAV)
		{
			desc.Usage = D3D11_USAGE::D3D11_USAGE_DEFAULT;
			desc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_SHADER_RESOURCE
				| D3D11_BIND_FLAG::D3D11_BIND_UNORDERED_ACCESS;	// Texture Register Binding
			desc.CPUAccessFlags = 0;
		}

		if (data)
		{
			D3D11_SUBRESOURCE_DATA tSub = {};
			tSub.pSysMem = data;

			if (!(GetDevice()->CreateBuffer(buffer.GetAddressOf(), &desc, &tSub)))
				return false;
		}
		else
		{
			if (!(GetDevice()->CreateBuffer(buffer.GetAddressOf(), &desc, nullptr)))
				return false;
		}

		D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc = {};
		srvDesc.BufferEx.NumElements = mStride;
		srvDesc.ViewDimension = D3D_SRV_DIMENSION_BUFFEREX;

		if (!(GetDevice()->CreateShaderResourceView(buffer.Get(), &srvDesc, mSRV.GetAddressOf())))
			return false;

		if (mType == eViewType::UAV)
		{
			D3D11_UNORDERED_ACCESS_VIEW_DESC uavDesc = {};
			uavDesc.Buffer.NumElements = mStride;
			uavDesc.ViewDimension = D3D11_UAV_DIMENSION_BUFFER;

			if (!GetDevice()->CreateUnordedAccessView(buffer.Get(), &uavDesc, mUAV.GetAddressOf()))
				return false;
		}

		if (cpuAccess)
			CreateRWBuffer();


		return true;
	}
	bool StructedBuffer::CreateRWBuffer()
	{
		D3D11_BUFFER_DESC wDesc(desc);

		wDesc.MiscFlags = D3D11_RESOURCE_MISC_BUFFER_STRUCTURED; // 구조화 버퍼 추가 플래그 설정
		wDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE;	// Texture Register Binding	

		wDesc.Usage = D3D11_USAGE_DYNAMIC;
		wDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

		if (!GetDevice()->CreateBuffer(mWriteBuffer.GetAddressOf(), &wDesc, nullptr))
			return false;

		D3D11_BUFFER_DESC rDesc(desc);

		rDesc.MiscFlags = D3D11_RESOURCE_MISC_BUFFER_STRUCTURED; // 구조화 버퍼 추가 플래그 설정
		rDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE;	// Texture Register Binding	

		rDesc.Usage = D3D11_USAGE_DEFAULT;
		rDesc.CPUAccessFlags = D3D11_CPU_ACCESS_READ;

		if (!GetDevice()->CreateBuffer(mReadBuffer.GetAddressOf(), &rDesc, nullptr))
			return false;

		return true;
	}
	void StructedBuffer::SetData(void* data, UINT bufferCount)
	{
		if (mStride < bufferCount)
			Create(mSize, bufferCount, mType, data);
		else
			GetDevice()->BindBuffer(mWriteBuffer.Get(), data, mSize * bufferCount);

		GetDevice()->CopyResource(buffer.Get(), mWriteBuffer.Get());
	}
	void StructedBuffer::GetData(void* data, UINT size)
	{
		GetDevice()->CopyResource(mReadBuffer.Get(), buffer.Get());

		if (size == 0)
			GetDevice()->BindBuffer(mReadBuffer.Get(), data, mSize * mStride);
		else
			GetDevice()->BindBuffer(mReadBuffer.Get(), data, size);
	}
	void StructedBuffer::BindSRV(eShaderStage stage, UINT slot)
	{
		mSRVSlot = slot;
		GetDevice()->BindShaderResource(stage, slot, mSRV.GetAddressOf());
	}
	void StructedBuffer::BindUAV(UINT slot)
	{
		mUAVslot = slot;
		UINT i = -1;
		GetDevice()->BindUnorderedAccess(slot, mUAV.GetAddressOf(), &i);
	}
	void StructedBuffer::Clear()
	{
		// srv clear
		ID3D11ShaderResourceView* srv = nullptr;
		GetDevice()->BindShaderResource(eShaderStage::VS, mSRVSlot, &srv);
		GetDevice()->BindShaderResource(eShaderStage::HS, mSRVSlot, &srv);
		GetDevice()->BindShaderResource(eShaderStage::DS, mSRVSlot, &srv);
		GetDevice()->BindShaderResource(eShaderStage::GS, mSRVSlot, &srv);
		GetDevice()->BindShaderResource(eShaderStage::PS, mSRVSlot, &srv);
		GetDevice()->BindShaderResource(eShaderStage::CS, mSRVSlot, &srv);

		ID3D11UnorderedAccessView* uav = nullptr;
		UINT i = -1;
		GetDevice()->BindUnorderedAccess(mUAVslot, &uav, &i);

		// uav clear
	}
}
