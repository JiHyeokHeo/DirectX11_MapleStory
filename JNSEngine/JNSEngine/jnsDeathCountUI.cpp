#include "jnsDeathCountUI.h"
#include "CommonSceneInclude.h"

namespace jns
{
    DeathCountUI::DeathCountUI()
    {
    }
    DeathCountUI::~DeathCountUI()
    {
    }
    void DeathCountUI::Initialize()
    {
        tr = GetComponent<Transform>();
        MeshRenderer* mr = AddComponent<MeshRenderer>();
        mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
        mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));
        ani = AddComponent<Animator>();
        tr->SetScale(Vector3(100.0f, 100.0f, 1.0f));

        digitAnimations = {
            {0, L"Zero"},
            {1, L"One"},
            {2, L"Two"},
            {3, L"Three"},
            {4, L"Four"},
            {5, L"Five"},
            {6, L"Six"},
            {7, L"Seven"},
            {8, L"Eight"},
            {9, L"Nine"}
        };

        std::wstring animationPath = L"..\\Resources\\UI\\DeathCountDown\\";

        for (const auto& i : digitAnimations)
        {
            ani->CreateAnimations(animationPath + i.second, 100, 0.1f, Vector2::Zero);
        }
        ani->PlayAnimation(L"DeathCountDownNine", false);
        tr->SetPosition(Vector3(-238.0f, 290.0f, 0.9f));
    }
	
	void DeathCountUI::Update()
	{
        PlayerScript::ePlayerState state = SceneManager::GetPlayer()->GetComponent<PlayerScript>()->GetPlayerState();
        
        Activate();
        CheckDeathCount();

        GameObject::Update();
	}
	void DeathCountUI::LateUpdate()
	{
        GameObject::LateUpdate();
	}
	void DeathCountUI::Render()
	{
        GameObject::Render();
	}
	void DeathCountUI::Activate()
	{
        int cnt = GameManager::GetInstance().GetDeathCount();
        std::wstring aniname = digitAnimations[cnt];
        std::wstring anifrontname = L"DeathCountDown";

        std::wstring fullname = anifrontname + aniname;
        ani->PlayAnimation(fullname, false);
	}
	void DeathCountUI::DeActivate()
	{
	}
	void DeathCountUI::SetPosition(Vector3 pos)
	{
	}

    void DeathCountUI::CheckDeathCount()
    {
        int cnt =GameManager::GetInstance().GetDeathCount();

        if (cnt == 0)
        {
            Scene* scene =SceneManager::GetActiveScene();
            jns::enums::eSceneType scenetype = scene->GetSceneType();
            jns::enums::eSceneType destinationscene = GameManager::GetInstance().GetMapData().diedestination[scenetype];
            SceneManager::GetPlayer()->SetPosition(Vector3(-00.0f, -200.0f, 1.0f));
            SceneManager::GetPlayer()->GetComponent<PlayerScript>()->SetPlayerState(jns::PlayerScript::ePlayerState::Idle);
            SceneManager::GetPlayer()->GetComponent<PlayerScript>()->SetPlayerHpFull();
            SceneManager::LoadScene(destinationscene);
        }

    }

    /////////////////////////////////////////////////// UI 데스카운트 분류


    DeathCount::DeathCount()
    {
    }

    DeathCount::~DeathCount()
    {
    }

    void DeathCount::Initialize()
    {
        tr = GetComponent<Transform>();
        MeshRenderer* mr = AddComponent<MeshRenderer>();
        mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
        mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));
        ani = AddComponent<Animator>();
        ani->CreateAnimations(L"..\\Resources\\UI\\DeathCountUI\\BG", 100, 0.1f, Vector2::Zero);
        tr->SetScale(Vector3(100.0f, 100.0f, 1.0f));
        ani->PlayAnimation(L"DeathCountUIBG", false);
        // -22 -10 차이
        tr->SetPosition(Vector3(-260.0f, 300.0f, 1.0f));

    }

    void DeathCount::Update()
    {
        GameObject::Update();
    }

    void DeathCount::LateUpdate()
    {
        GameObject::LateUpdate();
    }

    void DeathCount::Render()
    {
        GameObject::Render();
    }

    void DeathCount::Activate()
    {
    }

    void DeathCount::DeActivate()
    {
    }

    void DeathCount::SetPosition(Vector3 pos)
    {
    }

}