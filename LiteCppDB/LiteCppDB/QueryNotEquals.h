#pragma once

#include "Query.h"
#include "IndexNode.h"
#include "IndexService.h"
#include "CollectionIndex.h"

namespace LiteCppDB
{
	// Not is an Index Scan operation
	class QueryNotEquals : Query
	{
	private:
		BsonValue _value;

	public:
		QueryNotEquals(std::string field, BsonValue value) noexcept;// : base(field);

	private:
		std::vector<IndexNode> ExecuteIndex(IndexService indexer, CollectionIndex index) noexcept;
	};
}