#include "jnstestScript.h"
#include "jnsTime.h"
#include "jnsConstantBuffer.h"
#include "jnsRenderer.h"
#include "jnsInput.h"

namespace jns
{
	using namespace jns::graphics;

	testScript::testScript()
		: mTime(1.0f)
		, mT(1)
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
		if(Input::GetKeyDown(eKeyCode::G))
		{
			mT = 1;
		}
		else if(Input::GetKeyDown(eKeyCode::H))
		{
			mT = 2;
		}
		mTime += Time::DeltaTime() * 0.5f;
	}
	void testScript::Render()
	{
		BindConstantBuffer();
	}
	void testScript::BindConstantBuffer()
	{
		renderer::ObjectTypeMoveCB objmoveCB= {};

		objmoveCB.mtype = mT;
		objmoveCB.mTime = Vector3(mTime, 0.0f, 0.0f);
		ConstantBuffer* cb = renderer::constantBuffer[(UINT)eCBType::Move];
		cb->SetData(&objmoveCB);
		cb->Bind(eShaderStage::PS);
		//cb->Bind(eShaderStage::VS);
	}
}
