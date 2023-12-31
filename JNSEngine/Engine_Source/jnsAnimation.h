#pragma once
#include "jnsResource.h"
#include "jnsTexture.h"


namespace jns
{	
	using namespace math;
	using namespace graphics;

	class Animator;
	class Animation : public Resource
	{
	public:
		struct Sprite
		{
			Vector2 leftTop;
			Vector2 size;
			Vector2 offset;
			Vector2 atlasSize;
			float duration;

			Sprite()
				: leftTop(Vector2::Zero)
				, size(Vector2::Zero)
				, offset(Vector2::Zero)
				, atlasSize(Vector2::Zero)
				, duration(0.0f)
			{

			}
		};	

		Animation();
		~Animation();

		virtual HRESULT Load(const std::wstring& path);

		void Update();
		void LateUpdate();
		void Render();

		void Create(std::wstring name
			, std::shared_ptr<graphics::Texture> atlas
			, Vector2 leftTop
			, Vector2 size
			, UINT columnLength
			, int divideSize
			, Vector2 offset = Vector2::Zero
			, float duration = 0.0f);

		void Binds();
		void Reset();

		bool IsComplete() { return mbComplete; }
		void SetAniDirection(bool direction) { mDirection = direction; }
		bool GetAniDirection() { return mDirection; }

		void SetTransparency(float transparecny) { mTransparency = transparecny; }

		void SetAnimationName(std::wstring name) { animationName = name; }
		std::wstring GetAnimationName() { return animationName; }

		int GetAnimationIndex() { return mIndex; }
		
	private:
		std::shared_ptr<graphics::Texture> mAtlas;
		Animator* ani;
		std::vector<Sprite> mSprites;
		int mIndex;
		float mTime;
		bool mbComplete;

		bool mDirection;
		float mTransparency;

		std::wstring animationName;
	};

}
