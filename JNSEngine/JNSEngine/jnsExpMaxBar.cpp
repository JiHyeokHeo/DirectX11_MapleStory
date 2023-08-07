#include "jnsExpMaxBar.h"
#include "CommonUIInclude.h"
#include "CommonSceneInclude.h"

namespace jns
{
	ExpMaxBar::ExpMaxBar()
	{
	}
	ExpMaxBar::~ExpMaxBar()
	{
	}
	void ExpMaxBar::Initialize()
	{
		SetMesh(L"RectMesh");
		SetMaterial(L"ExpMaxBarMaterial");
	
		SetPosition(Vector3(3.0f, -379.0f, 4.0f));
		SetScaleWithOriginalImageScale(Vector2(0.71f, 1.0f));

		UIBase::Initialize();
	}
	void ExpMaxBar::Update()
	{
		UIBase::Update();
	}
	void ExpMaxBar::LateUpdate()
	{
		UIBase::LateUpdate();
	}
	void ExpMaxBar::Render()
	{
		renderer::PlayerCB playerUICB = {};
		int mHp = 40;
		int mMp = 100;
		int mExp = 50;

		playerUICB.hp = mHp;
		playerUICB.mp = mMp;
		playerUICB.exp = mExp;
		playerUICB.type = 2;
		ConstantBuffer* cb = renderer::constantBuffer[(UINT)eCBType::Player];

		cb->SetData(&playerUICB);
		cb->Bind(eShaderStage::PS);
		UIBase::Render();
	}
}