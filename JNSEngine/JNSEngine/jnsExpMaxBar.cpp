#include "jnsExpMaxBar.h"
#include "CommonUIInclude.h"
#include "CommonSceneInclude.h"

namespace jns
{
	ExpMaxBar::ExpMaxBar()
	{
		SetIsOnlyOne(true);
		SetState(eState::DontDestroy);
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
		int mPlayerHp = SceneManager::GetPlayer()->GetComponent<PlayerScript>()->GetPlayerInfo().hp;
		int mPlayerMp = SceneManager::GetPlayer()->GetComponent<PlayerScript>()->GetPlayerInfo().mp;
		int mPlayerExp = SceneManager::GetPlayer()->GetComponent<PlayerScript>()->GetPlayerInfo().exp;
		int mHp = mPlayerHp;
		int mMp = mPlayerMp;
		int mExp = mPlayerExp;

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