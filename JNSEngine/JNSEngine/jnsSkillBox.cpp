#include "jnsSkillBox.h"
#include "jnsSkillUIBG.h"

namespace jns
{
	int SkillBox::GlobalIdx = 0;
	SkillBox::SkillBox()
	{
		GlobalIdx++;
		mIdx = GlobalIdx;
	}
	SkillBox::~SkillBox()
	{
	}
	void SkillBox::Initialize()
	{
		SetMesh(L"RectMesh");
		SetMaterial(L"SkillBoxMaterial");
		
		SetScaleWithOriginalImageScale(Vector2(1.0f, 1.0f));
	}
	void SkillBox::Update()
	{
		Vector3 parentPos = skillBGUI->GetComponent<Transform>()->GetPosition();
		float mYstartCor = parentPos.y - 90.0f;
		if (mIdx >= 1 && mIdx <= 4)
		{
			parentPos.x -= 78.0f;
			parentPos.y = mYstartCor;
			parentPos.y += 40.0f * mIdx;
			parentPos.z -= 0.1f;
			tr->SetPosition(parentPos);
		}
		else
		{
			parentPos.x += 68.0f;
			parentPos.y = mYstartCor;
			parentPos.y += 40.0f * (mIdx - 4);
			parentPos.z -= 0.1f;
			tr->SetPosition(parentPos);
		}
		GameObject::Update();
	}
	void SkillBox::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void SkillBox::Render()
	{
		GameObject::Render();
	}
}