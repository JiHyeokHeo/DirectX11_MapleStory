#pragma once
#include "jnsEntity.h"

namespace jns
{
	class Resource
	{
	public:
		Resource(const enums::eResourceType type);
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0;

		const std::wstring& GetKey() { return mKey; }
		const std::wstring& GetPath() { return mPath; }
		void SetKey(const std::wstring& key) { mKey = key; }
		void SetPath(const std::wstring& path) { mPath = path; }

		enums::eResourceType GetType() { return mType; }

	private:
		const enums::eResourceType mType;
		std::wstring mKey;
		std::wstring mPath;
	};
}
