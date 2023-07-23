#include "jnsCursor.h"
#include "CommonUIInclude.h"
#include "jnsInput.h"
#include "jnsCamera.h"
#include "jnsRenderer.h"
#include "jnsApplication.h"

extern jns::Application application;
#define MOUSEZPOS -9.0f;

namespace jns
{
	Vector3 Cursor::mCursorPos = {};
	Vector3 Cursor::mCursorEndPos = {};
	Vector3 Cursor::mCursorWorldPos = {};
	Cursor::Cursor()
	{
		AddComponent<MeshRenderer>();
	}
	Cursor::~Cursor()
	{
	}
	void Cursor::Initialize()
	{
		SetName(L"Cursor");
		mr = GetComponent<MeshRenderer>();
		mr->SetMaterial(Resources::Find<Material>(L"CursorSpirte0Material"));
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));

		mTextureRatio = GetComponent<MeshRenderer>()->GetMaterial()->GetTexture()->GetTextureSize();
		tr = GetComponent<Transform>();
		tr->SetPosition(Vector3(1.0f, 0.0, -9.0f));
		tr->SetScale(Vector3(mTextureRatio.x, mTextureRatio.y, 1.0f));
		//tr->SetRotation(Vector3(0.0f, 0.0f, DegreeToRadian(80.0f)));

		GameObject::Initialize();
	}
	void Cursor::Update()
	{
		GameObject::Update();
	}
	void Cursor::LateUpdate()
	{	
		int a = 0;
		Vector3 testPos = renderer::mainCamera->GetOwner()->GetComponent<Transform>()->GetPosition();
		mCursorPos = Vector3(Input::GetMousePos().x - testPos.x, Input::GetMousePos().y + testPos.y, 0.0f); //ui용도로만 쓰라는건가?
		mCursorWorldPos = Vector3(Input::GetMousePos().x, Input::GetMousePos().y, 0.0f);
		mCursorEndPos = Vector3(800.0f, 450.0f, 0.0f);
			
		Viewport viewport;
		viewport.width = application.GetWidth();
		viewport.height = application.GetHeight();
		viewport.x = 0;
		viewport.y = 0;
		viewport.minDepth = 0.0f;
		viewport.maxDepth = 1.0f;

		mCursorPos = viewport.Unproject(mCursorPos, Camera::GetGpuProjectionMatrix(), Camera::GetGpuViewMatrix(), Matrix::Identity);
		mCursorPos.z = MOUSEZPOS;

		mCursorWorldPos = viewport.Unproject(mCursorWorldPos, Camera::GetGpuProjectionMatrix(), Camera::GetGpuViewMatrix(), Matrix::Identity);
		mCursorWorldPos.z = MOUSEZPOS;
		// 추후 UI좌표를 사용하기 위해!
		mCursorEndPos = viewport.Unproject(mCursorEndPos, Camera::GetGpuProjectionMatrix(), Camera::GetGpuViewMatrix(), Matrix::Identity);
		mCursorEndPos.z = MOUSEZPOS;

		Input::SetWorldMousePos(mCursorWorldPos);

		tr->SetPosition(mCursorPos);
		GameObject::LateUpdate();
	}
	void Cursor::Render()
	{
		GameObject::Render();
	}
}