#include "jnsDamageControl.h"
#include "CommonSceneInclude.h"

namespace jns
{
    DamageControl::DamageControl()
    {
    }

    DamageControl::~DamageControl()
    {
    }

    void DamageControl::Initialize()
    {
        renderDelayTime = 0.0f;
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

        std::wstring animationPath = L"..\\Resources\\UI\\NormalDamageSkin\\";

        for (const auto& i : digitAnimations)
        {
            ani->CreateAnimations(animationPath + i.second, 100, 0.1f, Vector2::Zero);
        }

        std::map<int, std::wstring>::iterator iter
            = digitAnimations.find(digit);

        std::wstring animationName = L"NormalDamageSkin" + iter->second;
        digitname = iter->second;
        ani->PlayAnimation(animationName, false);
        GameObject::Initialize();
    }

    void DamageControl::Update()
    {
        renderDelayTime += Time::DeltaTime();
        if (renderDelayTime >= renderDelayMaxTime)
        {
            renderTime += Time::DeltaTime();
            Vector3 damagePos = tr->GetPosition();
            damagePos.y += 40.0f * Time::DeltaTime();
            tr->SetPosition(damagePos);
            transparecny += 0.3f * Time::DeltaTime();;
            ani->PlayAnimation(digitname, false);
            ani->GetActiveAnimation()->SetTransparency(transparecny);
        }


        if (renderTime >= 1.5f)
        {
            SetState(GameObject::eState::Dead);
        }
        
        GameObject::Update();
    }

    void DamageControl::LateUpdate()
    {
        GameObject::LateUpdate();
    }

    void DamageControl::Render()
    {
        if (renderDelayTime >= renderDelayMaxTime)
        {
            GameObject::Render();
        }
    }
}