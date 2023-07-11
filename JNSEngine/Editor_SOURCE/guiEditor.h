#pragma once
#include "CommonInclude.h"
#include "JNSEngine.h"
#include "guiWidget.h"
#include "guiEditorObject.h"
#include "guiDebugObject.h"
#include "jnsGraphics.h"

namespace gui
{
	class Editor
	{
	public:
		static void Initialize();
		static void Run();

		static void Update();
		static void LateUpdate();
		static void Render();
		static void Release();

		static void DebugRender(const jns::graphics::DebugMesh& mesh);

	private:
		static std::vector<Widget*> mWidgets;
		static std::vector<EditorObject*> mEditorObjects;
		static std::vector<DebugObject*> mDebugObjects;

	};
}
