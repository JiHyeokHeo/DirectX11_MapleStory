#include "jnsCursor.h"
#include "CommonUIInclude.h"
#include "jnsInput.h"
#include "jnsCamera.h"

namespace jns
{
	Vector3 Cursor::mCursorPos = {};
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
		tr->SetScale(Vector3(mTextureRatio.x * 0.15f, mTextureRatio.y * 0.15f, 1.0f));

		GameObject::Initialize();
	}
	void Cursor::Update()
	{
		mCursorPos = Vector3(Input::GetMousePos().x, Input::GetMousePos().y, 0.0f);
		//Vector3 pos2(600, 450, 1000.0f);
		Viewport viewport;
		viewport.width = 1600.0f;
		viewport.height = 900.0f;
		viewport.x = 0;
		viewport.y = 0;
		viewport.minDepth = 0.0f;
		viewport.maxDepth = 1.0f;

		mCursorPos = viewport.Unproject(mCursorPos, Camera::GetProjectionMatrix(), Camera::GetViewMatrix(), Matrix::Identity);
		mCursorPos.z = 1.0f;
		//pos2 = viewport.Unproject(pos2, Camera::GetProjectionMatrix(), Camera::GetViewMatrix(), Matrix::Identity);
		tr->SetPosition(mCursorPos);

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