#include "stdafx.h"

#include "LiteEngine.h"

namespace LiteCppDB
{
	BsonValue LiteEngine::Min(std::string collection, std::string field) noexcept
	{
		return BsonValue();
	}

	BsonValue LiteEngine::Max(std::string collection, std::string field) noexcept
	{
		return BsonValue();
	}

	int64_t LiteEngine::Count(std::string collection, Query query) noexcept
	{
		return int64_t();
	}

	bool LiteEngine::Exists(std::string collection, Query query) noexcept
	{
		return false;
	}
}