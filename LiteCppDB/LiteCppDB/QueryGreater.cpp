#include "stdafx.h"
#include "QueryGreater.h"

namespace LiteCppDB
{
	QueryGreater::QueryGreater(std::string field, BsonValue value, bool equals) noexcept
	{
		this->_equals = false;
	}

	std::vector<IndexNode> QueryGreater::ExecuteIndex(IndexService indexer, CollectionIndex index) noexcept
	{
		return std::vector<IndexNode>();
	}
}