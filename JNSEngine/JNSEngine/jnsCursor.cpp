#include "jnsCursor.h"
#include "CommonUIInclude.h"
#include "jnsInput.h"
#include "jnsCamera.h"
#include "jnsRenderer.h"

#define MOUSEZPOS -9.0f;
namespace jns
{
	Vector3 Cursor::mCursorPos = {};
	Vector3 Cursor::mUIPos = {};
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
		////Vector3 testPos = renderer::cameras[0]->GetOwner()->GetComponent<Transform>()->GetPosition();
		//mCursorPos = Vector3(Input::GetMousePos().x , Input::GetMousePos().y, 0.0f); //ui�뵵�θ� ����°ǰ�?

		//// UI 
		//mUIPos = Vector3(800.0f, 450.0f, 0.0f);

		//Viewport viewport;
		//viewport.width = 1600.0f;
		//viewport.height = 900.0f;
		//viewport.x = 0;
		//viewport.y = 0;
		//viewport.minDepth = 0.0f;
		//viewport.maxDepth = 1.0f;

		//mCursorPos = viewport.Unproject(mCursorPos, Camera::GetProjectionMatrix(), Camera::GetViewMatrix(), Matrix::Identity);
		//mCursorPos.z = MOUSEZPOS;
		//
		//// ���� UI��ǥ�� ����ϱ� ����!
		//mUIPos = viewport.Unproject(mUIPos, Camera::GetProjectionMatrix(), Camera::GetViewMatrix(), Matrix::Identity);
		//mUIPos.z = MOUSEZPOS;
		//
		//
		//
		//tr->SetPosition(mCursorPos);

		GameObject::Update();
	}
	void Cursor::LateUpdate()
	{	
		int a = 0;
		//Vector3 testPos = renderer::cameras[0]->GetOwner()->GetComponent<Transform>()->GetPosition();
		mCursorPos = Vector3(Input::GetMousePos().x, Input::GetMousePos().y, 0.0f); //ui�뵵�θ� ����°ǰ�?

		// UI 
		mUIPos = Vector3(800.0f, 450.0f, 0.0f);

		Viewport viewport;
		viewport.width = 1600.0f;
		viewport.height = 900.0f;
		viewport.x = 0;
		viewport.y = 0;
		viewport.minDepth = 0.0f;
		viewport.maxDepth = 1.0f;

		mCursorPos = viewport.Unproject(mCursorPos, Camera::GetProjectionMatrix(), Camera::GetViewMatrix(), Matrix::Identity);
		mCursorPos.z = MOUSEZPOS;

		// ���� UI��ǥ�� ����ϱ� ����!
		mUIPos = viewport.Unproject(mUIPos, Camera::GetProjectionMatrix(), Camera::GetViewMatrix(), Matrix::Identity);
		mUIPos.z = MOUSEZPOS;

		tr->SetPosition(mCursorPos);
		GameObject::LateUpdate();
	}
	void Cursor::Render()
	{
		GameObject::Render();
	}
}