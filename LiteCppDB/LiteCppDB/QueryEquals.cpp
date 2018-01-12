#include "stdafx.h"
#include "QueryEquals.h"

namespace LiteCppDB
{
	QueryEquals::QueryEquals(std::string field, BsonValue value) noexcept
	{
	}

	std::vector<IndexNode> QueryEquals::ExecuteIndex(IndexService indexer, CollectionIndex index) noexcept
	{
		return std::vector<IndexNode>();
	}
}