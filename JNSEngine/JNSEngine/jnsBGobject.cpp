#include "jnsBGobject.h"
#include "CommonSceneInclude.h"

namespace jns
{
	BGobject::BGobject()
	{
	}
	BGobject::~BGobject()
	{

	}
	void BGobject::Initialize()
	{
		MeshRenderer* mr = AddComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"SpriteAnimaionMaterial"));
		Animator* at = AddComponent<Animator>();
		Transform* tr = GetComponent<Transform>();
		Vector2 mSize = {};
		at->CreateAnimations(L"..\\Resources\\Charactor\\CharAssain1Hit", 100, 0.1f);
		switch (bgObjectType)
		{
		case jns::BGobject::eBGObjectType::westGardenArtifect1:
			at->CreateAnimations(L"..\\Resources\\Map\\Rutabys\\AniObjects\\westArtficiality1", 500, 0.1f);
			at->PlayAnimation(L"AniObjectswestArtficiality1", true);
			tr->SetScale(Vector3(500.0f, 500.0f, 1.0f));
			break;
		case jns::BGobject::eBGObjectType::westGardenArtifect2:
			at->CreateAnimations(L"..\\Resources\\Map\\Rutabys\\AniObjects\\westArtficiality2", 500, 0.1f);
			at->PlayAnimation(L"AniObjectswestArtficiality2", true);
			tr->SetScale(Vector3(500.0f, 500.0f, 1.0f));
			break;
		case jns::BGobject::eBGObjectType::westGardenArtifect3:
			at->CreateAnimations(L"..\\Resources\\Map\\Rutabys\\AniObjects\\westArtficiality3", 500, 0.1f);
			at->PlayAnimation(L"AniObjectswestArtficiality3", true);
			tr->SetScale(Vector3(500.0f, 500.0f, 1.0f));
			break;
		default:
			break;
		}
		GameObject::Initialize();
	}
	void BGobject::Update()
	{
		GameObject::Update();
	}
	void BGobject::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void BGobject::Render()
	{
		GameObject::Render();
	}
}