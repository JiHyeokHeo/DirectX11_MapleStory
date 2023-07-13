#pragma once
#include "..\\Engine_SOURCE\\CommonInclude.h"
#include "..\\Engine_Source\\JNSEngine.h"
#include "..\\Engine_Source\\jnsGraphics.h"

#include "guiEditorObject.h"
#include "guiDebugObject.h"
#include "guiWidget.h"

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
