#include "jnsExpBarMoveScript.h"
#include "jnsTime.h"
#include "jnsConstantBuffer.h"
#include "jnsRenderer.h"

namespace jns
{
	ExpBarMoveScript::ExpBarMoveScript()
	{
	}
	ExpBarMoveScript::~ExpBarMoveScript()
	{
	}
	void ExpBarMoveScript::Initialize()
	{
	}
	void ExpBarMoveScript::Update()
	{
		mTime += Time::DeltaTime();
	}
	void ExpBarMoveScript::LateUpdate()
	{
	}
	void ExpBarMoveScript::Render()
	{
		BindConstantBuffer();
	}
	void ExpBarMoveScript::BindConstantBuffer()
	{
		ConstantBuffer* cb = renderer::constantBuffer[(UINT)eCBType::Move];
		cb->SetData(&mTime);
		cb->Bind(eShaderStage::PS);
	}
}