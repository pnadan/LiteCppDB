#include "stdafx.h"

#include "LiteEngine.h"

namespace LiteCppDB
{
	bool LiteEngine::Update(std::string collection, BsonDocument doc) noexcept
	{
		return false;
	}

	int32_t LiteEngine::Update(std::string collection, std::vector<BsonDocument> docs) noexcept
	{
		return int32_t();
	}

	bool LiteEngine::UpdateDocument(CollectionPage col, BsonDocument doc) noexcept
	{
		return false;
	}
}