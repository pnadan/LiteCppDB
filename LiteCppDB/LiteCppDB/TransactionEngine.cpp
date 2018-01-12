#include "stdafx.h"

#include "LiteEngine.h"

namespace LiteCppDB
{
	void LiteEngine::BeginTrans() noexcept
	{
	}

	bool LiteEngine::Commit() noexcept
	{
		return false;
	}

	void LiteEngine::Rollback() noexcept
	{
	}
}