#pragma once

#include "Query.h"
#include "IndexNode.h"
#include "IndexService.h"
#include "CollectionIndex.h"

#include <vector>

namespace LiteCppDB
{
	class QueryBetween : Query
	{
	private:
		BsonValue _start;
		BsonValue _end;

	public:
		QueryBetween(std::string field, BsonValue start, BsonValue end) noexcept;// : base(field);
		virtual ~QueryBetween() {};

		QueryBetween(const QueryBetween& src) noexcept;
		virtual QueryBetween& operator=(const QueryBetween& rhs) noexcept;

		QueryBetween(const QueryBetween&& src) noexcept;
		virtual QueryBetween& operator=(QueryBetween&& rhs) noexcept;

		std::vector<IndexNode> ExecuteIndex(IndexService indexer, CollectionIndex index) noexcept;
	};
}