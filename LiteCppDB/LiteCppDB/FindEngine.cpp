#include "stdafx.h"

#include "LiteEngine.h"

namespace LiteCppDB
{
	std::vector<BsonDocument> LiteEngine::Find(std::string collection, Query query, int32_t skip, int32_t limit) noexcept
	{
		return std::vector<BsonDocument>();
	}

	std::vector<BsonValue> LiteEngine::FindIndex(std::string collection, Query query, int32_t skip, int32_t limit)
	{
		return std::vector<BsonValue>();
	}

	BsonDocument LiteEngine::FindOne(std::string collection, Query query) noexcept
	{
		return BsonDocument();
	}

	BsonDocument LiteEngine::FindById(std::string collection, BsonValue id) noexcept
	{
		return BsonDocument();
	}

	std::vector<BsonDocument> LiteEngine::FindAll(std::string collection) noexcept
	{
		return std::vector<BsonDocument>();
	}
}