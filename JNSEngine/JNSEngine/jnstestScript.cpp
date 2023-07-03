#include "jnstestScript.h"
#include "jnsTime.h"
#include "jnsConstantBuffer.h"
#include "jnsRenderer.h"

namespace jns
{
	using namespace jns::graphics;

	testScript::testScript()
		: mTime(1.0f)
	{
	}
	testScript::~testScript()
	{
	}
	void testScript::Initialize()
	{
	}
	void testScript::Update()
	{
	}
	void testScript::LateUpdate()
	{
		mTime += Time::DeltaTime();
	}
	void testScript::Render()
	{
		BindConstantBuffer();
	}
	void testScript::BindConstantBuffer()
	{
		ConstantBuffer* cb = renderer::constantBuffer[(UINT)eCBType::Move];
		cb->SetData(&mTime);
		cb->Bind(eShaderStage::PS);
	}
}
