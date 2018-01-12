#include "stdafx.h"
#include "QueryNotEquals.h"

namespace LiteCppDB
{
	QueryNotEquals::QueryNotEquals(std::string field, BsonValue value) noexcept
	{
	}

	std::vector<IndexNode> QueryNotEquals::ExecuteIndex(IndexService indexer, CollectionIndex index) noexcept
	{
		return std::vector<IndexNode>();
	}
}
