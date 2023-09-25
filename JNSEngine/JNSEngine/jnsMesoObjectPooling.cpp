#include "jnsMesoObjectPooling.h"
#include "jnsBloodyMeso.h"
#include "jnsSceneManager.h"
#include "jnsSkillEffect.h"

namespace jns::MesoPooling
{
    void MesoObjectPooling::InitializePool()
    {
        if (isInitialized == false)
        {
            for (int i = 0; i < maxPoolSize; ++i)
            {
                BloodyMeso* meso = new BloodyMeso();
                meso->Initialize();
                mesoPool.push_back(meso);
            }

            for (int i = 0; i < maxPoolSize; ++i)
            {
                SkillEffect* mesoeffect = new SkillEffect(SkillBase::eSkillType::BloodyMeso);
                mesoeffect->Initialize();
                mesoEffects.push_back(mesoeffect);
            }

            isInitialized = true;
        }
    }

    void MesoObjectPooling::ActiveMesoObject()
    {
        Scene* activeScene = SceneManager::GetActiveScene();

        std::vector<GameObject*> objs = {};
        std::vector<GameObject*> activeMeso = {};
        objs = activeScene->FindObjects<GameObject>(eLayerType::Skill);

        std::vector<GameObject*>::iterator objiter
            = objs.begin();

        for (objiter; objiter != objs.end(); objiter++)
        {
            if ((*objiter)->GetName() == L"BloodyMeso")
            {
                activeMeso.push_back(*objiter);
            }
        }
        std::vector<GameObject*>::iterator iter
            = activeMeso.begin();

        for (iter; iter != activeMeso.end();)
        {
            (*iter)->Activate();
            
            
            iter = activeMeso.erase(iter);
            continue;
        }
    }
    void MesoObjectPooling::Release()
    {
        // 메소 이펙트는 shared_ptr 스마트 포인터 활용

        for (GameObject* obj : mesoPool)
        {
            if (obj == nullptr)
                continue;

            delete obj;
            obj = nullptr;
        }

        for (GameObject* obj : mesoEffects)
        {
            if (obj == nullptr)
                continue;

            delete obj;
            obj = nullptr;
        }
        
    }
    GameObject* MesoObjectPooling::CreateMesoObject()
    {
        if (!mesoPool.empty())
        {
            GameObject* gameObject = mesoPool.front();
            //gameObject->Initialize();
            Scene* activeScene = SceneManager::GetActiveScene();
            activeScene->AddGameObject(gameObject->GetLayerType(), gameObject);
            mesoPool.pop_front();
            return gameObject;
        }
        else
        {
            SkillEffect* mesoeffect = new SkillEffect(SkillBase::eSkillType::BloodyMeso);
            mesoeffect->Initialize();
            Scene* activeScene = SceneManager::GetActiveScene();
            activeScene->AddGameObject(mesoeffect->GetLayerType(), mesoeffect);

            return mesoeffect;
        }
    }

    GameObject* MesoObjectPooling::CreateMesoEffect()
    {
        if (!mesoEffects.empty())
        {
            GameObject* gameObject = mesoEffects.front();
            //gameObject->Initialize();
            Scene* activeScene = SceneManager::GetActiveScene();
            activeScene->AddGameObject(gameObject->GetLayerType(), gameObject);
            mesoEffects.pop_front();
            return gameObject;
        }
        else
        {
            BloodyMeso* meso = new BloodyMeso();
            meso->Initialize();
            Scene* activeScene = SceneManager::GetActiveScene();
            activeScene->AddGameObject(meso->GetLayerType(), meso);

            return meso;
        }

        return nullptr;
    }

    void MesoObjectPooling::RecycleMesoObject(GameObject* gameObject)
    {
        // 객체 초기화 및 상태 재설정
        /*gameObject->Reset();*/
        gameObject->DeActivate();

        // 그냥 일반적인 포인터로 
        Scene* activeScene = SceneManager::GetActiveScene();
        activeScene->DeleteGameObject(gameObject->GetLayerType(), gameObject);
        mesoPool.push_back(gameObject);
    }

    void MesoObjectPooling::RecycleMesoEffect(GameObject* gameObject)
    {
        gameObject->DeActivate();

        // 스마트 포인터 shared_ptr 활용
        Scene* activeScene = SceneManager::GetActiveScene();
        activeScene->DeleteGameObject(gameObject->GetLayerType(), gameObject);
        mesoEffects.push_back(gameObject);
    }
   
}