#include "stdafx.h"
#include "QueryAnd.h"

namespace LiteCppDB
{
	QueryAnd::QueryAnd(Query left, Query right) noexcept
	{
	}

	QueryAnd::QueryAnd(const QueryAnd & src) noexcept
	{
	}

	QueryAnd& QueryAnd::operator=(const QueryAnd & rhs) noexcept
	{
		if (this == &rhs)
		{
			return *this;
		}

		return *this;
	}

	QueryAnd::QueryAnd(const QueryAnd && src) noexcept
	{
	}

	QueryAnd& QueryAnd::operator=(QueryAnd && rhs) noexcept
	{
		if (this == &rhs)
		{
			return *this;
		}

		return *this;
	}

	std::vector<IndexNode> QueryAnd::ExecuteIndex(IndexService indexer, CollectionIndex index) noexcept
	{
		return std::vector<IndexNode>();
	}

	std::vector<IndexNode> QueryAnd::Run(CollectionPage col, IndexService indexer) noexcept
	{
		return std::vector<IndexNode>();
	}
}