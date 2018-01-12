#include "stdafx.h"
#include "QueryContains.h"

namespace LiteCppDB
{
	QueryContains::QueryContains(const QueryContains& src) noexcept
	{
	}

	QueryContains& QueryContains::operator=(const QueryContains& rhs) noexcept
	{
		if (this == &rhs)
		{
			return *this;
		}

		return *this;
	}

	QueryContains::QueryContains(const QueryContains&& src) noexcept
	{
	}

	QueryContains& QueryContains::operator=(QueryContains&& rhs) noexcept
	{
		if (this == &rhs)
		{
			return *this;
		}

		return *this;
	}

	QueryContains::QueryContains(std::string field, BsonValue value) noexcept
	{
	}

	std::vector<IndexNode> QueryContains::ExecuteIndex(IndexService indexer, CollectionIndex index) noexcept
	{
		return std::vector<IndexNode>();
	}
}