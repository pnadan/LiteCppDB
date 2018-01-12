#pragma once

#include "Query.h"
#include "IndexNode.h"
#include "CollectionIndex.h"
#include "CollectionService.h"
#include "BsonValue.h"

namespace LiteCppDB
{
	class QueryIn : Query
	{
	private:
		std::vector<BsonValue> _values;

	public:
		QueryIn(std::string field, std::vector<BsonValue> values) noexcept;// : base(field);

	private:
		std::vector<IndexNode> ExecuteIndex(IndexService indexer, CollectionIndex index) noexcept;
	};
}