#include "stdafx.h"
#include "QueryIn.h"

namespace LiteCppDB
{
	QueryIn::QueryIn(std::string field, std::vector<BsonValue> values) noexcept
	{
	}

	std::vector<IndexNode> QueryIn::ExecuteIndex(IndexService indexer, CollectionIndex index) noexcept
	{
		return std::vector<IndexNode>();
	}
}