#include "jnsHpBar.h"
#include "CommonUIInclude.h"
#include "CommonSceneInclude.h"

namespace jns
{
	HpBar::HpBar()
	{
		SetIsOnlyOne(true);
		SetState(eState::DontDestroy);
	}
	HpBar::~HpBar()
	{
	}
	void HpBar::Initialize()
	{
		SetMesh(L"RectMesh");
		SetMaterial(L"HpBarMaterial");
		mr->GetMaterial()->SetRenderingMode(eRenderingMode::Opaque);
		SetPosition(Vector3(0.05f, 0.0, 0.1f));
		tr->SetScale(Vector3(0.85f, 0.1f, 1.0f));
		//SetScaleWhenParentOn(Vector3(100.0f, 100.0f, 1.0f));
		//SetScaleWithOriginalImageScale(Vector2(1.0f,1.0f));
		
		UIBase::Initialize();
	}
	void HpBar::Update()
	{
		UIBase::Update();
	}
	void HpBar::LateUpdate()
	{
		UIBase::LateUpdate();
	}
	void HpBar::Render()
	{
		renderer::PlayerCB playerUICB = {};
		int mPlayerHp = SceneManager::GetPlayer()->GetComponent<PlayerScript>()->GetPlayerInfo().hp;
		int mPlayerMaxHp = SceneManager::GetPlayer()->GetComponent<PlayerScript>()->GetPlayerInfo().maxhp;
		int mPlayerMp = SceneManager::GetPlayer()->GetComponent<PlayerScript>()->GetPlayerInfo().mp;
		int mPlayerExp = SceneManager::GetPlayer()->GetComponent<PlayerScript>()->GetPlayerInfo().exp;

		Vector3 playermaxHp = { (float)mPlayerMaxHp, 0.0, 0.0 };
		Vector3 playerHp = { (float)mPlayerHp, 0.0, 0.0 };


		interpolatedHp = Vector3::Lerp(playerPrevHp, playerHp, Time::DeltaTime() * 10.0f);

		int mHp = interpolatedHp.x;
		int mMp = mPlayerMp;
		int mExp = mPlayerExp;

		playerUICB.hp = mHp;
		playerUICB.mp = mMp;
		playerUICB.exp = mExp;
		playerUICB.type = 0;
		playerUICB.maxhp = mPlayerMaxHp;
		ConstantBuffer* cb = renderer::constantBuffer[(UINT)eCBType::Player];

		cb->SetData(&playerUICB);
		cb->Bind(eShaderStage::PS);

		playerPrevHp = interpolatedHp;

		UIBase::Render();
	}
}