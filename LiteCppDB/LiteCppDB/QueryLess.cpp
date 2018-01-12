#include "stdafx.h"
#include "QueryLess.h"

namespace LiteCppDB
{
	QueryLess::QueryLess(const QueryLess& src) noexcept
	{
		this->mEquals = src.mEquals;
		this->mValue = src.mValue;
	}

	QueryLess& QueryLess::operator=(const QueryLess& rhs) noexcept
	{
		if (this == &rhs)
		{
			return *this;
		}

		this->mEquals = rhs.mEquals;
		this->mValue = rhs.mValue;
		return *this;
	}

	QueryLess::QueryLess(const QueryLess&& src) noexcept
	{
		this->mEquals = src.mEquals;
		this->mValue = src.mValue;
	}

	QueryLess& QueryLess::operator=(QueryLess&& rhs) noexcept
	{
		if (this == &rhs)
		{
			return *this;
		}

		this->mEquals = rhs.mEquals;
		this->mValue = rhs.mValue;
		return *this;
	}

	QueryLess::QueryLess(std::string field, BsonValue value, bool equals) noexcept
	{
		this->mEquals = false;
	}

	std::vector<IndexNode> QueryLess::ExecuteIndex(IndexService indexer, CollectionIndex index) noexcept
	{
		return std::vector<IndexNode>();
	}
}