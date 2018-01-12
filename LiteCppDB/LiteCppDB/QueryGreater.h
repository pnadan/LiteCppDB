#pragma once

#include "Query.h"
#include "IndexNode.h"
#include "CollectionIndex.h"
#include "CollectionService.h"

namespace LiteCppDB
{
	class QueryGreater : Query
	{
	private:
		BsonValue _value;
		bool _equals;

	public:
		QueryGreater(std::string field, BsonValue value, bool equals) noexcept;// : base(field);

		std::vector<IndexNode> ExecuteIndex(IndexService indexer, CollectionIndex index) noexcept;
	};
}