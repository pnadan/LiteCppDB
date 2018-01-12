#pragma once

#include "Query.h"
#include "IndexNode.h"
#include "CollectionIndex.h"
#include "CollectionService.h"

namespace LiteCppDB
{
	class QueryEquals : Query
	{
	private:
		BsonValue _value;

	public:
		QueryEquals(std::string field, BsonValue value) noexcept;// : base(field);

	private:
		std::vector<IndexNode> ExecuteIndex(IndexService indexer, CollectionIndex index) noexcept;
	};
}