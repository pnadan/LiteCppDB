#include "stdafx.h"

#include "LiteEngine.h"

namespace LiteCppDB
{
	bool LiteEngine::Delete(std::string collection, BsonValue id)
	{
		return this->Delete(collection, Query());
	}

	int32_t LiteEngine::Delete(std::string collection, Query query) noexcept
	{
		return int32_t();
	}
}