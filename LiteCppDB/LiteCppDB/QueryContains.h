#pragma once

#include "Query.h"
#include "IndexNode.h"
#include "IndexService.h"

namespace LiteCppDB
{
	// Contains query do not work with index, only full scan
	class QueryContains : Query
	{
	private:
		BsonValue _value;

	public:
		QueryContains() noexcept {};
		virtual ~QueryContains() {};

		QueryContains(const QueryContains& src) noexcept;
		virtual QueryContains& operator=(const QueryContains& rhs) noexcept;

		QueryContains(const QueryContains&& src) noexcept;
		virtual QueryContains& operator=(QueryContains&& rhs) noexcept;
		
		QueryContains(std::string field, BsonValue value) noexcept;// : base(field);

	private:
		std::vector<IndexNode> ExecuteIndex(IndexService indexer, CollectionIndex index) noexcept;
	};
}