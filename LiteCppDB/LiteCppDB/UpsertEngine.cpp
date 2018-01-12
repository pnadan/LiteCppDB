#include "stdafx.h"

#include "LiteEngine.h"

namespace LiteCppDB
{
	bool LiteEngine::Upsert(std::string collection, BsonDocument doc) noexcept
	{
		return false;
	}

	int32_t LiteEngine::Upsert(std::string collection, std::vector<BsonDocument> docs) noexcept
	{
		return int32_t();
	}
}