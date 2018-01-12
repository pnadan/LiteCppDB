#pragma once

#include "Query.h"
#include "IndexNode.h"
#include "IndexService.h"
#include "CollectionIndex.h"
#include "BsonValue.h"

namespace LiteCppDB
{
	class QueryLess : Query
	{
	private:
		BsonValue mValue;
		bool mEquals;

	public:
		QueryLess(std::string field, BsonValue value, bool equals) noexcept;// : base(field);

		virtual ~QueryLess() {};

		QueryLess(const QueryLess& src) noexcept;
		virtual QueryLess& operator=(const QueryLess& rhs) noexcept;

		QueryLess(const QueryLess&& src) noexcept;
		virtual QueryLess& operator=(QueryLess&& rhs) noexcept;

	private:
		std::vector<IndexNode> ExecuteIndex(IndexService indexer, CollectionIndex index) noexcept;
	};
}