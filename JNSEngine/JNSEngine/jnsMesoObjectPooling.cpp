#include "jnsMesoObjectPooling.h"
#include "jnsBloodyMeso.h"
#include "jnsSceneManager.h"

namespace jns::MesoPooling
{
    void MesoObjectPooling::Release()
    {
        mesoPool.clear();
    }
    GameObject* MesoObjectPooling::CreateMesoObject()
    {
        if (!mesoPool.empty())
        {
            GameObject* gameObject = mesoPool.front();
            mesoPool.pop_front();
            Scene* activeScene = SceneManager::GetActiveScene();
            activeScene->AddGameObject(gameObject->GetLayerType(), gameObject);
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
        Scene* activeScene = SceneManager::GetActiveScene();
        activeScene->DeleteGameObject(gameObject->GetLayerType(), gameObject);
        mesoPool.push_back(gameObject);
    }

   
}