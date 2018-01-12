#include "stdafx.h"
#include "Query.h"
#include "QueryAll.h"

namespace LiteCppDB
{
	Query::Query(const Query& src) noexcept
	{
	}

	Query& Query::operator=(const Query& rhs) noexcept
	{
		if (this == &rhs)
		{
			return *this;
		}

		return *this;
	}

	Query::Query(const Query&& src) noexcept
	{
	}

	Query& Query::operator=(Query&& rhs) noexcept
	{
		if (this == &rhs)
		{
			return *this;
		}

		return *this;
	}

	void Query::setField(std::string field) noexcept
	{
	}

	std::string Query::getField() noexcept
	{
		return std::string();
	}

	Query Query::All(int32_t order) noexcept
	{
		return QueryAll(std::string("_id"), order);
	}

	Query Query::All(std::string field, int32_t order) noexcept
	{
		return QueryAll::QueryAll(field, order);
	}

	Query Query::EQ(std::string field, BsonValue value) noexcept
	{
		return Query();
	}

	Query LiteCppDB::Query::LT(std::string field, BsonValue value) noexcept
	{
		return Query();
	}

	Query LiteCppDB::Query::LTE(std::string field, BsonValue value) noexcept
	{
		return Query();
	}

	Query Query::GT(std::string field, BsonValue value) noexcept
	{
		return Query();
	}

	Query Query::GTE(std::string field, BsonValue value) noexcept
	{
		return Query();
	}

	Query Query::Between(std::string field, BsonValue start, BsonValue end) noexcept
	{
		return Query();
	}

	Query Query::StartsWith(std::string field, std::string value) noexcept
	{
		return Query();
	}

	Query Query::Contains(std::string field, std::string value) noexcept
	{
		return Query();
	}

	Query Query::Not(std::string field, BsonValue value) noexcept
	{
		return Query();
	}

	Query Query::Not(Query query, int32_t order) noexcept
	{
		return Query();
	}

	Query Query::In(std::string field, BsonArray value) noexcept
	{
		return Query();
	}

	Query Query::And(Query left, Query right) noexcept
	{
		return Query();
	}

	Query Query::Or(Query left, Query right) noexcept
	{
		return Query();
	}

	std::vector<IndexNode> Query::ExecuteIndex(IndexService indexer, CollectionIndex index) noexcept
	{
		return std::vector<IndexNode>();
	}

	std::vector<IndexNode> Query::Run(CollectionPage col, IndexService indexer) noexcept
	{
		return std::vector<IndexNode>();
	}
}