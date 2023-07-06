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
		mTime += Time::DeltaTime() * 0.5f;
	}
	void testScript::Render()
	{
		BindConstantBuffer();
	}
	void testScript::BindConstantBuffer()
	{
		renderer::ObjectTypeMoveCB objmoveCB= {};

		objmoveCB.mtype = 1.0f;
		objmoveCB.mTime = Vector3(mTime, 0.0f, 0.0f);
		ConstantBuffer* cb = renderer::constantBuffer[(UINT)eCBType::Move];
		cb->SetData(&objmoveCB);
		cb->Bind(eShaderStage::PS);
		//cb->Bind(eShaderStage::VS);
	}
}
