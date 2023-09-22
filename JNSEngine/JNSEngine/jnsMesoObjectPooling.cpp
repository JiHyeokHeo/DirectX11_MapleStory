#include "jnsMesoObjectPooling.h"
#include "jnsBloodyMeso.h"
#include "jnsSceneManager.h"

namespace jns::MesoPooling
{
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
        for (GameObject* obj : mesoPool)
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
            gameObject->Initialize();
            Scene* activeScene = SceneManager::GetActiveScene();
            activeScene->AddGameObject(gameObject->GetLayerType(), gameObject);
            mesoPool.pop_front();
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
    }

    void MesoObjectPooling::RecycleMesoObject(GameObject* gameObject)
    {
        // 객체 초기화 및 상태 재설정
        /*gameObject->Reset();*/
        gameObject->DeActivate();

        Scene* activeScene = SceneManager::GetActiveScene();
        activeScene->DeleteGameObject(gameObject->GetLayerType(), gameObject);
        mesoPool.push_back(gameObject);
    }
   
}