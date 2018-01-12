#include "stdafx.h"
#include "QueryNot.h"

namespace LiteCppDB
{
	QueryNot::QueryNot(Query query, int order) noexcept
	{
		this->_order = 0;
	}

	std::vector<IndexNode> QueryNot::ExecuteIndex(IndexService indexer, CollectionIndex index) noexcept
	{
		return std::vector<IndexNode>();
	}

	std::vector<IndexNode> QueryNot::Run(CollectionPage col, IndexService indexer) noexcept
	{
		return std::vector<IndexNode>();
	}
}