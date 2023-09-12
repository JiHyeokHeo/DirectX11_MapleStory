#include "jnsMpBar.h"
#include "CommonUIInclude.h"
#include "CommonSceneInclude.h"

namespace jns
{
	MpBar::MpBar()
	{
		SetIsOnlyOne(true);
		SetState(eState::DontDestroy);
	}
	MpBar::~MpBar()
	{
	}
	void MpBar::Initialize()
	{
		SetMesh(L"RectMesh");
		SetMaterial(L"MpBarMaterial");
		mr->GetMaterial()->SetRenderingMode(eRenderingMode::Opaque);
		SetPosition(Vector3(0.05f, -0.2f, 0.1f));
		tr->SetScale(Vector3(0.85f, 0.2f, 1.0f));
	
		
		UIBase::Initialize();
	}
	void MpBar::Update()
	{
		UIBase::Update();
	}
	void MpBar::LateUpdate()
	{
		UIBase::LateUpdate();
	}
	void MpBar::Render()
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
		playerUICB.type = 1;
		ConstantBuffer* cb = renderer::constantBuffer[(UINT)eCBType::Player];

		cb->SetData(&playerUICB);
		cb->Bind(eShaderStage::PS);
		UIBase::Render();
	}
}