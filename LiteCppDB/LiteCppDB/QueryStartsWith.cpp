#include "stdafx.h"
#include "QueryStartsWith.h"

namespace LiteCppDB
{
	QueryStartsWith::QueryStartsWith(std::string field, BsonValue value) noexcept
	{
	}

	std::vector<IndexNode> QueryStartsWith::ExecuteIndex(IndexService indexer, CollectionIndex index) noexcept
	{
		return std::vector<IndexNode>();
	}
}
