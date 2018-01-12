#include "stdafx.h"
#include "QueryAll.h"

namespace LiteCppDB
{
	QueryAll::QueryAll(std::string field, int32_t order) noexcept
	{
		Query q(field);

		this->_order = order;
	}

	std::vector<IndexNode> QueryAll::ExecuteIndex(IndexService indexer, CollectionIndex index) noexcept
	{
		return indexer.FindAll(index, this->_order);
	}
}