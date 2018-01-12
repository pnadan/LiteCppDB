#include "stdafx.h"
#include "QueryEmpty.h"

namespace LiteCppDB
{
	QueryEmpty::QueryEmpty() noexcept
	{
	}

	std::vector<IndexNode> QueryEmpty::ExecuteIndex(IndexService indexer, CollectionIndex index) noexcept
	{
		return std::vector<IndexNode>();
	}
}