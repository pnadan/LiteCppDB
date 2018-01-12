#include "stdafx.h"
#include "QueryBetween.h"

namespace LiteCppDB
{
	QueryBetween::QueryBetween(const QueryBetween& src) noexcept
	{
	}

	QueryBetween& QueryBetween::operator=(const QueryBetween& rhs) noexcept
	{
		if (this == &rhs)
		{
			return *this;
		}

		return *this;
	}

	QueryBetween::QueryBetween(const QueryBetween&& src) noexcept
	{
	}

	QueryBetween& QueryBetween::operator=(QueryBetween&& rhs) noexcept
	{
		if (this == &rhs)
		{
			return *this;
		}

		return *this;
	}

	QueryBetween::QueryBetween(std::string field, BsonValue start, BsonValue end) noexcept
	{
	}

	std::vector<IndexNode> QueryBetween::ExecuteIndex(IndexService indexer, CollectionIndex index) noexcept
	{
		return std::vector<IndexNode>();
	}
}