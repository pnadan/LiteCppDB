#include "stdafx.h"
#include "QueryOr.h"

namespace LiteCppDB
{
	QueryOr::QueryOr(Query left, Query right) noexcept
	{
	}

	std::vector<IndexNode> QueryOr::ExecuteIndex(IndexService indexer, CollectionIndex index) noexcept
	{
		return std::vector<IndexNode>();
	}

	std::vector<IndexNode> QueryOr::Run(CollectionPage col, IndexService indexer) noexcept
	{
		return std::vector<IndexNode>();
	}
}