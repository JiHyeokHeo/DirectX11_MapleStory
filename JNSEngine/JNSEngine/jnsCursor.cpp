#include "jnsCursor.h"
#include "CommonUIInclude.h"
#include "jnsInput.h"
#include "jnsCamera.h"

namespace jns
{
	Cursor::Cursor()
	{
		AddComponent<MeshRenderer>();
	}
	Cursor::~Cursor()
	{
	}
	void Cursor::Initialize()
	{
		mr = GetComponent<MeshRenderer>();
		mr->SetMaterial(Resources::Find<Material>(L"CursorSpirte0Material"));
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));

		mTextureRatio = GetComponent<MeshRenderer>()->GetMaterial()->GetTexture()->GetTextureRatio();
		tr = GetComponent<Transform>();
		tr->SetPosition(Vector3(1.0f, 0.0, 0.1f));
		tr->SetScale(Vector3(mTextureRatio.x * 1.0f, mTextureRatio.y * 1.0f, 1.0f));

		GameObject::Initialize();
	}
	void Cursor::Update()
	{
		Vector2 mMousePos = jns::Input::GetMousePos();
		tr->SetPosition(Vector3(mMousePos.x, mMousePos.y, 1.0f));

		Camera::GetProjectionMatrix();
		//Viewport::Unproject(mMousePos, Camera::GetProjectionMatrix(),Camera::GetViewMatrix(), )


		GameObject::Update();
	}
	void Cursor::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Cursor::Render()
	{
		GameObject::Render();
	}
}