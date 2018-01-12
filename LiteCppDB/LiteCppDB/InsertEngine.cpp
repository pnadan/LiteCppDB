#include "stdafx.h"

#include "LiteEngine.h"

namespace LiteCppDB
{
	BsonValue LiteEngine::Insert(std::string collection, BsonDocument doc) noexcept
	{
		return BsonValue();
	}

	int32_t LiteEngine::Insert(std::string collection, std::vector<BsonDocument> docs) noexcept
	{
		return int32_t();
	}

	int32_t LiteEngine::InsertBulk(std::string collection, std::vector<BsonDocument> docs, int32_t batchSize) noexcept
	{
		return int32_t();
	}

	void LiteEngine::InsertDocument(CollectionPage col, BsonDocument doc) noexcept
	{
	}
}