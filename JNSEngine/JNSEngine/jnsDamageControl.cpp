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
        ani->PlayAnimation(animationName, false);

        GameObject::Initialize();
    }

    void DamageControl::Update()
    {
        renderTime += Time::DeltaTime();
        Vector3 damagePos = tr->GetPosition();
        damagePos.y += 40.0f * Time::DeltaTime();

        tr->SetPosition(damagePos);


        if (renderTime >= 1.0f)
            SetState(GameObject::eState::Dead);
        
        GameObject::Update();
    }

    void DamageControl::LateUpdate()
    {
        GameObject::LateUpdate();
    }

    void DamageControl::Render()
    {
        GameObject::Render();
    }
}